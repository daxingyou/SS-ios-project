//
//  Camera.m
//  demo
//
//  Created by spring on 14-1-14.
//
//

#import "Camera.h"

@interface Camera ()

@end

@implementation Camera

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
+(Camera*)TakePhoto
{
    UIWindow *window = [[UIApplication sharedApplication] keyWindow];
    Camera *viewController = [[Camera alloc] init];
    [window addSubview:viewController.view];
    [viewController OpenCamera];
    
    return viewController;
}
-(void)OpenCamera
{
    
    NSLog(@"启动相机");
    UIImagePickerController *picker= [[UIImagePickerController alloc] init];
    picker.delegate = self;
    
    if ([UIImagePickerController isSourceTypeAvailable:UIImagePickerControllerSourceTypeCamera])
    {
        picker.sourceType = UIImagePickerControllerSourceTypeCamera;
        
    }
    else
    {
        NSLog(@"模拟器无法打开相机");
    }
    [self presentViewController:picker animated:YES completion:nil];
    
}

//拍照
- (void)imagePickerController:(UIImagePickerController *)picker
didFinishPickingMediaWithInfo:(NSDictionary *)info
{
    NSLog(@"拍照");
    UIImage *originImage = [info objectForKey:UIImagePickerControllerOriginalImage];
    //保存原图到相册
    UIImageWriteToSavedPhotosAlbum(originImage, nil, nil, nil);
    
    [picker dismissViewControllerAnimated:false completion:nil];
    [self.view removeFromSuperview];
    
    
}
//取消
- (void)imagePickerControllerDidCancel:(UIImagePickerController *)picker {
    NSLog(@"取消");
    
    [picker dismissViewControllerAnimated:false completion:nil];
    [self.view removeFromSuperview];
    
    
}
- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

-(void) dealloc
{
    [self release];
    [super dealloc];
}
@end
