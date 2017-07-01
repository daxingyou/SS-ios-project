//
//  takePhoto.m
//  cocos2d-ImageTest
//
//  Created by spring on 14-1-14.
//
//

#import "takePhoto.h"
#import "Assistant.h"
#import "ASIHTTPRequest.h"
#import "URLConnect.h"


#import "platform/ios/CCNativeIOS.h"

#import "CCLuaObjcBridge.h"


@interface takePhoto ()

@end

@implementation takePhoto

- (id)initWithNibName:(NSString *)nibNameOrNil bundle:(NSBundle *)nibBundleOrNil
{
    self = [super initWithNibName:nibNameOrNil bundle:nibBundleOrNil];
    if (self) {
        // Custom initialization
    }
    return self;
}

- (void)viewDidLoad
{
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    
}

+(takePhoto *)snapImage
{
    UIWindow *window = [[UIApplication sharedApplication] keyWindow];
    takePhoto *viewController = [[takePhoto alloc] init];
    [window addSubview:viewController.view];
    [viewController openPhoto];
    return viewController;
    
}
-(void)openPhoto
{
    UIImagePickerController * picker = [[[UIImagePickerController alloc] init] autorelease];
    picker.delegate = self;
    
    picker.sourceType = UIImagePickerControllerSourceTypePhotoLibrary;
    picker.allowsEditing = YES;
    [self presentViewController:picker animated:YES completion:nil];
}
- (void)imagePickerController:(UIImagePickerController *)picker didFinishPickingImage:(UIImage *)image editingInfo:(NSDictionary *)editingInfo{
    
    [picker dismissViewControllerAnimated:YES completion:nil];
}
- (void)imagePickerController:(UIImagePickerController *)picker didFinishPickingMediaWithInfo:(NSDictionary *)info{
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
    
    
    self.view.userInteractionEnabled = NO;
    
    


   [picker dismissViewControllerAnimated:false completion:nil];
   [self.view removeFromSuperview];
}
-(void)requestDidFinish:(ASIHTTPRequest *) request{
    
    self.view.userInteractionEnabled = YES;
    
    if(request.error){
        NSLog(@"%@",[request.error description]);
        
    }
    else{
        NSLog(@"%@",[request.responseData description]);
        
    }
    
    //回调
    int callBackFunction = [[[NSUserDefaults standardUserDefaults] objectForKey:@"call"] intValue];
    
    
    
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
- (void)imagePickerControllerDidCancel:(UIImagePickerController *)picker{
    [picker dismissViewControllerAnimated:false completion:nil];
    [self.view removeFromSuperview];
}


- (void)connectionDidFinishLoading:(URLConnect *)connection data:(NSData *)data userInfo:(NSDictionary *)userInfo{
    
    
    
    //    RoomNewModel *model = [messageReceive.roomList objectAtIndex:path.row];
    
    NSString *url = [userInfo objectForKey:@"url"];
    UIImage *image = [UIImage imageWithData:data];
    
    if(image){
        [Assistant saveImageWithURL:url data:data];
    }
    else{
        
    }
    
    NSString *type = [userInfo objectForKey:@"type"];
    
    if ([type compare:@"avatar"] == 0){
        
    }
    else if([type compare:@"prize"] == 0){
        
        NSNumber *num = [userInfo objectForKey:@"num"];
        
        int numInt = [num intValue];
        
        
        
    }
    
    
    
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

@end
