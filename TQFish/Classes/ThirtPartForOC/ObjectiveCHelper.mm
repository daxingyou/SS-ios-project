
#import "ObjectiveCHelper.h"
#import "ELCImagePickerController.h"
#import "ELCAlbumPickerController.h"
#import "ELCAssetTablePicker.h"
#import "Assistant.h"
#import "ASIHTTPRequest.h"
#import "CCLuaObjcBridge.h"
#import "platform/ios/CCNativeIOS.h"
#import "VPImageCropperViewController.h"
#import "Helper.h"

#import <MobileCoreServices/UTCoreTypes.h>
#import <AVFoundation/AVFoundation.h>


static UIViewController *currentController = nil;

static UIViewController *pickImgController = nil;

@interface ObjectiveCHelper() <UINavigationControllerDelegate, UIImagePickerControllerDelegate, ELCImagePickerControllerDelegate, UIImagePickerControllerDelegate, UIActionSheetDelegate, VPImageCropperDelegate>

@end

@implementation ObjectiveCHelper

static ObjectiveCHelper *sharedHelper = nil;

+ (ObjectiveCHelper *) sharedObjectiveCHelper
{
    if (!sharedHelper) {
        sharedHelper = [[ObjectiveCHelper alloc] init];
    }
    return sharedHelper;
}

//更换头像
-(void) changeHeader
{
    if (!pickImgController) {
        pickImgController = [[UIViewController alloc] init];
    }
    UIWindow *window = [[UIApplication sharedApplication] keyWindow];
    [window addSubview:pickImgController.view];
    
    UIActionSheet *actionSheet = [[UIActionSheet alloc] initWithTitle:@"更换头像" delegate:self cancelButtonTitle:@"取消" destructiveButtonTitle:nil otherButtonTitles:@"相机", @"从手机相册选择", nil];
    [actionSheet showInView:pickImgController.view];
}

//废除老版的修改头像
- (void)showAlbum
{
//    [self changeHeader]; //使用新版的修改头像
    
    if (!currentController) {
        UIWindow *window = [[UIApplication sharedApplication] keyWindow];

        currentController = [[UIViewController alloc] init];
        [window addSubview:currentController.view];
    }
    
    ELCAlbumPickerController *elcAlbum = [[ELCAlbumPickerController alloc] init];
    ELCImagePickerController *elcPicker = [[ELCImagePickerController alloc] initWithRootViewController:elcAlbum];
    elcPicker.maximumImagesCount = 1;
    [elcAlbum setParent:elcPicker];
    elcPicker.imagePickerDelegate = self;
    
    [currentController presentViewController:elcPicker animated: YES completion:nil];
}

- (NSLock *)getLock {
    if (!lock) {
        lock = [[NSLock alloc] init];
    }
    return lock;
}

#pragma mark - UIActionSheetDelegate -

- (void)actionSheet:(UIActionSheet *)actionSheet clickedButtonAtIndex:(NSInteger)buttonIndex
{
    [actionSheet dismissWithClickedButtonIndex:buttonIndex animated:YES];
    
    switch (buttonIndex)
    {
        case 0:
        {
            //检查相机模式是否可用
            if (![UIImagePickerController isSourceTypeAvailable:UIImagePickerControllerSourceTypeCamera])
            {
                NSLog(@"sorry, no camera or camera is unavailable.");
                return;
            }
            
            //获得相机模式下支持的媒体类型
            NSArray* availableMediaTypes = [UIImagePickerController availableMediaTypesForSourceType:UIImagePickerControllerSourceTypeCamera];
            
            BOOL canTakePicture = NO;
            
            for (NSString* mediaType in availableMediaTypes)
            {
                if ([mediaType isEqualToString:(__bridge NSString*)kUTTypeImage]) {
                    //支持拍照
                    canTakePicture = YES;
                    break;
                }
            }
            
            //检查是否支持拍照
            if (!canTakePicture)
            {
                NSLog(@"sorry, taking picture is not supported.");
                return;
            }
            
            NSString *mediaType = AVMediaTypeVideo;
            AVAuthorizationStatus authStatus = [AVCaptureDevice authorizationStatusForMediaType:mediaType];
            if(authStatus == AVAuthorizationStatusRestricted || authStatus == AVAuthorizationStatusDenied)
            {
                NSLog(@"相机权限受限");
                UIAlertView *alview = [[UIAlertView alloc] initWithTitle:nil message:@"请在iPhone的“设置-隐私-相机”选项中，允许访问你的相机" delegate:self cancelButtonTitle:@"确定" otherButtonTitles:nil, nil];
                [alview show];
                [self removePickImgController];
                return;
                
            }
            UIImagePickerController *picker = [[UIImagePickerController alloc] init];
            
            picker.sourceType = UIImagePickerControllerSourceTypeCamera;
            picker.delegate = self;
            picker.allowsEditing = YES;
            picker.mediaTypes = @[(NSString *)kUTTypeImage];
            [pickImgController presentViewController:picker animated:YES completion:nil];

            break;
        }
        case 1:
        {
            UIImagePickerController *picker = [[UIImagePickerController alloc] init];
            picker.sourceType = UIImagePickerControllerSourceTypePhotoLibrary;
            picker.delegate = self;
            picker.allowsEditing = YES;
            picker.mediaTypes = @[(NSString *)kUTTypeImage];
            [pickImgController presentViewController:picker animated:YES completion:nil];
            
            break;
        }
        case 2:
            //[self.navigationController dismissViewControllerAnimated:YES completion:nil];
            [self removePickImgController];
            
            break;
        default:
            break;
    }
}

#pragma mark - UIImagePickerControllerDelegate -

- (void)imagePickerControllerDidCancel:(UIImagePickerController *)picker
{
    [picker dismissViewControllerAnimated:YES completion:^{
        [pickImgController.view removeFromSuperview];
        [pickImgController release];
        pickImgController = nil;
    }];
}

- (void)imagePickerController: (UIImagePickerController *)picker didFinishPickingMediaWithInfo: (NSDictionary *)info
{
    UIImage *image = [info objectForKey:UIImagePickerControllerEditedImage];
    image = [Assistant getSmallPicture:image picSize:200];
    
    NSString *end = @"\r\n";
    NSString *twoHyphens = @"--";
    NSString *boundary = @"---------------------------41184676334";
    
    NSString *userID = [[NSUserDefaults standardUserDefaults] objectForKey:@"userID"];
    NSString *password = [[NSUserDefaults standardUserDefaults] objectForKey:@"password"];
    NSString * sFileName = [NSString stringWithFormat:@"%@_%@",userID,password];
    
    
    ASIHTTPRequest *request = [[ASIHTTPRequest alloc] initWithURL:[NSURL URLWithString:@"http://db.tongqutongqu.cn/tqAdmin/fileUploadManager!upload.do"]];
    
    [request setRequestMethod: @"POST"];
    [request setDelegate:self];
    [request setDidFinishSelector:@selector(requestDidFinish:)];
    
    [request addRequestHeader: @"Connection" value: @"Keep-Alive"];
    [request addRequestHeader: @"Charset" value: @"UTF-8"];
    [request addRequestHeader: @"Content-Type" value: [NSString stringWithFormat:@"multipart/form-data;boundary=%@",boundary]];
    
    [request appendPostData:[[NSString stringWithFormat:@"%@%@%@",twoHyphens,boundary,end] dataUsingEncoding: NSUTF8StringEncoding]];
    [request appendPostData:[[NSString stringWithFormat:@"%@%@%@%@%@",@"Content-Disposition: form-data;",@"name=\"photo\";filename=\"",sFileName,@".jpg\"\r\nContent-Type: image/jpeg",end] dataUsingEncoding: NSUTF8StringEncoding]];
    [request appendPostData:[end dataUsingEncoding: NSUTF8StringEncoding]];
    [request appendPostData:UIImagePNGRepresentation(image)];
    [request appendPostData:[end dataUsingEncoding: NSUTF8StringEncoding]];
    [request appendPostData:[[NSString stringWithFormat:@"%@%@%@%@",twoHyphens,boundary,twoHyphens,end] dataUsingEncoding: NSUTF8StringEncoding]];
    
    [request startAsynchronous];
    [request release];
    
    [picker dismissViewControllerAnimated:YES completion:^{
        [pickImgController.view removeFromSuperview];
        [pickImgController release];
        pickImgController = nil;
    }];
}

- (void)removePickImgController
{
    if(pickImgController)
    {
        [pickImgController.view removeFromSuperview];
        [pickImgController release];
        pickImgController = nil;
    }
}

#pragma mark - Private  -

- (void)removeCurrentController {
    if (currentController != nil) {
        [currentController.view removeFromSuperview];
        [currentController release];
        currentController = nil;
    }
}

#pragma mark - Private  -

- (void)dismissViewControllerAnimated:(BOOL)flag pickerController:(ELCImagePickerController *)picker
{
    if(currentController !=nil){
        [picker dismissViewControllerAnimated:flag completion:^{
            [currentController.view removeFromSuperview];
            [currentController release];
            currentController = nil;
        }];
    }
}

#pragma mark - VPImageCropperDelegate -

- (void)imageCropper:(VPImageCropperViewController *)cropperViewController didFinished:(UIImage *)editedImage {
    [cropperViewController dismissViewControllerAnimated:NO completion:^(){
        [self removeCurrentController];
        
        [self uploadPortraitWithASIHTTPRequest:[Helper imageWithImageSimple:editedImage scaledToSize:CGSizeMake(400, 400)]];
        
        // 保存到系统相册
//        UIImageWriteToSavedPhotosAlbum(editedImage, nil, nil, nil);
    }];
}

- (void)imageCropperDidCancel:(VPImageCropperViewController *)cropperViewController {
    [cropperViewController dismissViewControllerAnimated:NO completion:^(){
        [self removeCurrentController];
    }];
}

#pragma mark - ELCImagePickerControllerDelegate -

- (void)elcImagePickerController:(ELCImagePickerController *)picker didFinishPickingMediaWithInfo:(NSArray *)info
{
    NSLog(@"didFinishPickingMediaWithInfo");
    for (NSMutableDictionary *dict1 in info) {
        [picker dismissViewControllerAnimated:YES completion:^(){
            for (NSMutableDictionary *dict in info) {
                UIImage *image = [dict objectForKey:UIImagePickerControllerOriginalImage];
                
                // 裁剪
                VPImageCropperViewController *imgEditorVC = [[VPImageCropperViewController alloc] initWithImage:image cropFrame:
                                                             CGRectMake(currentController.view.frame.size.width/2-200/2, currentController.view.frame.size.height/2-200/2, 200, 200) limitScaleRatio:3.0];
                imgEditorVC.delegate = self;
                [currentController presentViewController:imgEditorVC animated:NO completion:^{
                    // TO DO
                }];
            }
        }];
    }
    [self dismissViewControllerAnimated:YES pickerController:picker];
}

- (void)elcImagePickerControllerDidCancel:(ELCImagePickerController *)picker
{
    [picker dismissViewControllerAnimated:YES completion:^(){
        [self removeCurrentController];
    }];
}

- (void)uploadPortraitWithASIHTTPRequest:(UIImage *)image {
    NSString *end = @"\r\n";
    NSString *twoHyphens = @"--";
    NSString *boundary = @"---------------------------41184676334";
    
    NSString *mUrl = [[NSUserDefaults standardUserDefaults] objectForKey:@"mUrl"];
    unsigned int userID = (unsigned int)[[NSUserDefaults standardUserDefaults] integerForKey:@"userID"];
    NSString *password = [[NSUserDefaults standardUserDefaults] objectForKey:@"password"];
    NSString * sFileName = [NSString stringWithFormat:@"%u_%@", userID,password];
    NSLog(@"mUrl =========== %@",mUrl);
    NSLog(@"userID =========== %u", userID);
    NSLog(@"password =========== %@",password);
    
    ASIHTTPRequest *request = [[ASIHTTPRequest alloc] initWithURL:[NSURL URLWithString:mUrl]];
    
    [request setRequestMethod: @"POST"];
    [request setDelegate:self];
    [request setDidFinishSelector:@selector(requestDidFinish:)];
    
    [request addRequestHeader: @"Connection" value: @"Keep-Alive"];
    [request addRequestHeader: @"Charset" value: @"UTF-8"];
    [request addRequestHeader: @"Content-Type" value: [NSString stringWithFormat:@"multipart/form-data;boundary=%@",boundary]];
    
    [request appendPostData:[[NSString stringWithFormat:@"%@%@%@",twoHyphens,boundary,end] dataUsingEncoding: NSUTF8StringEncoding]];
    [request appendPostData:[[NSString stringWithFormat:@"%@%@%@%@%@",@"Content-Disposition: form-data;",@"name=\"photo\";filename=\"",sFileName,@".jpg\"\r\nContent-Type: image/jpeg",end] dataUsingEncoding: NSUTF8StringEncoding]];
    [request appendPostData:[end dataUsingEncoding: NSUTF8StringEncoding]];
    [request appendPostData:UIImagePNGRepresentation(image)];
    [request appendPostData:[end dataUsingEncoding: NSUTF8StringEncoding]];
    [request appendPostData:[[NSString stringWithFormat:@"%@%@%@%@",twoHyphens,boundary,twoHyphens,end] dataUsingEncoding: NSUTF8StringEncoding]];
    
    [request startAsynchronous];
    [request release];
}

-(void)requestDidFinish:(ASIHTTPRequest *)request {
    NSString *imageURL = NULL;
    
    if(request.error) {
        NSLog(@"error: %@",[request.error  localizedDescription]);
    } else {
        NSString *aString = [[[NSString alloc] initWithData:request.responseData encoding:NSUTF8StringEncoding] autorelease];
        NSLog(@"aString = %@", aString);
        
        NSError *error;
        NSDictionary *json = [NSJSONSerialization JSONObjectWithData:request.responseData options:NSJSONReadingMutableLeaves error:&error];
        NSDictionary *re = [json objectForKey:@"respones"];
        imageURL = [re objectForKey:@"imageURL"];
    }
    
    //回调
    int callBackFunction = [[[NSUserDefaults standardUserDefaults] objectForKey:@"call"] intValue];
    
    
    
    // 1. 将引用 ID 对应的 Lua function 放入 Lua stack
    CCLuaObjcBridge::pushLuaFunctionById(callBackFunction);
    
    // 2. 将需要传递给 Lua function 的参数放入 Lua stack
    
    CCLuaValueDict item;
    
    if (imageURL) {
        item["imageURL"] = CCLuaValue::stringValue(imageURL.UTF8String);
    }
    
    CCLuaObjcBridge::getStack()->pushCCLuaValueDict(item);
    
    // 3. 执行 Lua function
    CCLuaObjcBridge::getStack()->executeFunction(1);
    
    // 4. 释放引用 ID
    CCLuaObjcBridge::releaseLuaFunctionById(callBackFunction);
}

-(void) createWebview:(NSDictionary *)dict {
    CCSize winSize = CCEGLView::sharedOpenGLView()->getDesignResolutionSize();
    int m_width = [[dict objectForKey:@"width"] intValue];
    int m_height = [[dict objectForKey:@"height"] intValue];
    if(m_width <= 0){
        m_width = 1136;
    };
    if(m_height <= 0){
        m_height = 640;
    };
    winSize.width = m_width;
    winSize.height = m_height;
    NSString *url = [dict objectForKey:@"url"];
    NSString *content = [dict objectForKey:@"content"];
    float x = [[dict objectForKey:@"xvalue"] floatValue];
    float y = winSize.height - [[dict objectForKey:@"yvalue"] floatValue];
    float w = [[dict objectForKey:@"wvalue"] floatValue];
    float h = [[dict objectForKey:@"hvalue"] floatValue];
    
    NSString *call = [dict objectForKey:@"callback"];
    [[NSUserDefaults standardUserDefaults] setObject:call forKey:@"callWebviewFinishLoad"];
    [[NSUserDefaults standardUserDefaults] synchronize];
    
    [[NSUserDefaults standardUserDefaults] setObject:url forKey:@"loadWebviewUrl"];
    [[NSUserDefaults standardUserDefaults] synchronize];
    
    CGRect rect=[[UIScreen mainScreen] bounds];  //全屏的
    int cwidth = rect.size.height;
    int cheight = rect.size.width;
    int temp = 0;
    if (cwidth < cheight) {
        // 游戏是横屏，所以颠倒一下
        temp = cwidth;
        cwidth = cheight;
        cheight = temp;
    }
    
    float newx = x*cwidth/winSize.width;
    float newy = y*cheight/winSize.height;
    float neww = w*cwidth/winSize.width;
    float newh = h*cheight/winSize.height;
    
    UIWebView *webView = [[UIWebView alloc]initWithFrame:CGRectMake(newx, newy - newh, neww, newh)];
    [webView setBackgroundColor:[UIColor clearColor]];
    [webView setOpaque:NO];
    
    if (strlen([url UTF8String]) > 0)
    {
        [webView loadRequest:[NSURLRequest requestWithURL:[NSURL URLWithString:url]]];
        
    }
    else
    {
        [webView loadHTMLString:content baseURL:nil];
    }
    //[webView setBackgroundColor:[UIColor redColor]];
    
    [webView setDelegate:self];
    [webView setTag:1011];
 
    [[UIApplication sharedApplication].keyWindow.rootViewController.view addSubview:webView];
    
    
}

#pragma mark - WebView
//开始加载数据
- (void) webViewDidStartLoad:(UIWebView *)webView {
    NSLog(@"开始加载webView数据");
}

//数据加载完
- (void) webViewDidFinishLoad:(UIWebView *)webView {
    NSLog(@"webView数据加载完");
    
    //回调
    int callBackFunction = [[[NSUserDefaults standardUserDefaults] objectForKey:@"callWebviewFinishLoad"] intValue];
    
    // 1. 将引用 ID 对应的 Lua function 放入 Lua stack
    CCLuaObjcBridge::pushLuaFunctionById(callBackFunction);
    
    // 2. 将需要传递给 Lua function 的参数放入 Lua stack
    
    CCLuaValueDict item;
    
    CCLuaObjcBridge::getStack()->pushCCLuaValueDict(item);
    
    // 3. 执行 Lua function
    CCLuaObjcBridge::getStack()->executeFunction(1);
    
    // 4. 释放引用 ID
    CCLuaObjcBridge::releaseLuaFunctionById(callBackFunction);
    
}

- (BOOL)webView:(UIWebView *)webView shouldStartLoadWithRequest:(NSURLRequest *)request navigationType:(UIWebViewNavigationType)navigationType {
    // NOTE: ------  对alipays:相关的scheme处理 -------
    // NOTE: 若遇到支付宝相关scheme，则跳转到本地支付宝App
    NSString* reqUrl = request.URL.absoluteString;
    //NSLog(@"webView shouldStartLoadWithRequest == %@",reqUrl);
    if ([reqUrl hasPrefix:@"alipays://"] || [reqUrl hasPrefix:@"alipay://"]) {
        // NOTE: 跳转支付宝App
        NSLog(@"跳转支付宝App========");
        //移除跳转支付宝app的webview
        [[[UIApplication sharedApplication].keyWindow.rootViewController.view viewWithTag:1011] removeFromSuperview];
        
        BOOL bSucc = [[UIApplication sharedApplication]openURL:request.URL];
        
        // NOTE: 如果跳转失败，则跳转itune下载支付宝App
        if (!bSucc) {
            NSLog(@"跳转到本地支付宝App失败========");
            NSString* loadWebviewUrl = [[NSUserDefaults standardUserDefaults] objectForKey:@"loadWebviewUrl"];
            NSLog(@"loadWebviewUrl == %@",loadWebviewUrl);
            [[UIApplication sharedApplication] openURL:[NSURL URLWithString:loadWebviewUrl]];
        }
        return NO;
    }
    return YES;
}


@end
