//
//  UpdateItunesController.m
//  demo
//
//  Created by spring on 14-4-18.
//
//

#import "UpdateItunesController.h"
#import "CCLuaObjcBridge.h"
#import "EAGLView.h"


@interface UpdateItunesController ()

@end

@implementation UpdateItunesController

@synthesize url;

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
    
    url = @"https://itunes.apple.com/us/app/feng-kuang-bao-ziaaa/id796771743?ls=1&mt=8";
    
}
+(UpdateItunesController *)openUpdateAlert
{
    UpdateItunesController *viewController = [[UpdateItunesController alloc] init];
    [[EAGLView sharedEGLView] addSubview:viewController.view];
    [viewController update];
    return viewController;
    
}
-(void)update
{
    NSString *newVersion = @"2.0.0.91";
    //获取本地软件的版本号
    NSString *localVersion = [[[NSBundle mainBundle]infoDictionary] objectForKey:@"CFBundleVersion"];
    
    NSString *msg = [NSString stringWithFormat:@"你当前的版本是V%@，发现新版本，是否下载新版本？",localVersion];
    
    //对比发现的新版本和本地的版本
    if ([newVersion floatValue] > [localVersion floatValue])
    {
        UIAlertView *createUserResponseAlert = [[UIAlertView alloc] initWithTitle:@"升级提示!" message:msg delegate:self cancelButtonTitle:@"下次再说" otherButtonTitles: @"现在升级", nil];
        [createUserResponseAlert show];
        [createUserResponseAlert release];
    }
}
//响应升级提示按钮
- (void)alertView:(UIAlertView *)actionSheet clickedButtonAtIndex:(NSInteger)buttonIndex {
    //如果选择“现在升级”
    if (buttonIndex == 1)
    {
        //打开iTunes  方法一
        [[UIApplication sharedApplication] openURL:[NSURL URLWithString:url]];
        
    }
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}



@end
