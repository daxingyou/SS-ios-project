/****************************************************************************
 Copyright (c) 2010 cocos2d-x.org

 http://www.cocos2d-x.org

 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:

 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.

 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 ****************************************************************************/
#import <UIKit/UIKit.h>
#import "AppController.h"
#import "cocos2d.h"
#import "EAGLView.h"
#import "RootViewController.h"
#import "Helper.h"
#import "ScriptUpdate.h"
#import "DownloadScript.h"
#import "NSData+ToNSString.h"
#import "CCLuaObjcBridge.h"
#import "PublicLuaBridge.h"
#import "UMTongjiIOS.h"

//麻友局的微信APPID
static NSString * WeiXin_App_ID = @"wxfb3229d1e5635107";
static NSString * UMAppKey = @"58ff19d845297d6a0a0001e3";
//static NSString * UMAppKey = @"58b3de5c07fe652de8000449";//优洽
static NSString * UMChannelId = @"92AppStore";

@implementation AppController

#pragma mark -
#pragma mark Application lifecycle -

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {

    //屏幕常亮
    [[UIApplication sharedApplication ] setIdleTimerDisabled:YES];
    //[UIApplication sharedApplication].applicationIconBadgeNumber=33;
    
    // Override point for customization after application launch.
    
    [UMTongjiIOS umengTrack:UMAppKey ChannelId:UMChannelId];
    
    [WXApi registerApp:WeiXin_App_ID withDescription:@"demo 2.0"];
    
    //向微信注册支持的文件类型
    UInt64 typeFlag = MMAPP_SUPPORT_TEXT | MMAPP_SUPPORT_PICTURE | MMAPP_SUPPORT_LOCATION | MMAPP_SUPPORT_VIDEO |MMAPP_SUPPORT_AUDIO | MMAPP_SUPPORT_WEBPAGE | MMAPP_SUPPORT_DOC | MMAPP_SUPPORT_DOCX | MMAPP_SUPPORT_PPT | MMAPP_SUPPORT_PPTX | MMAPP_SUPPORT_XLS | MMAPP_SUPPORT_XLSX | MMAPP_SUPPORT_PDF;
    
    [WXApi registerAppSupportContentFlag:typeFlag];

    // Add the view controller's view to the window and display.
    window = [[UIWindow alloc] initWithFrame: [[UIScreen mainScreen] bounds]];
    EAGLView *__glView = [EAGLView viewWithFrame: [window bounds]
                                     pixelFormat: kEAGLColorFormatRGBA8
                          // 原值：GL_DEPTH_COMPONENT16
                          // 现值：GL_DEPTH24_STENCIL8_OES  lua listview 自动裁切
                                     depthFormat: GL_DEPTH24_STENCIL8_OES
                              preserveBackbuffer: NO
                                      sharegroup: nil
                                   multiSampling: NO
                                 numberOfSamples: 0 ];

    [__glView setMultipleTouchEnabled:YES];
    
    // Use RootViewController manage EAGLView
    viewController = [[RootViewController alloc] initWithNibName:nil bundle:nil];
    viewController.wantsFullScreenLayout = YES;
    viewController.view = __glView;

    // Set RootViewController to window
    if ( [[UIDevice currentDevice].systemVersion floatValue] < 6.0)
    {
        // warning: addSubView doesn't work on iOS6
        [window addSubview: viewController.view];
    }
    else
    {
        // use this method on ios6
        [window setRootViewController:viewController];
    }
    
    [window makeKeyAndVisible];
    
    NSDictionary *dict = [NSDictionary dictionaryWithObjectsAndKeys:@TQGameDir, @"fileName", nil];
    [Helper getDocumentDirectoryPath:dict];

    [[UIApplication sharedApplication] setStatusBarHidden: YES];

    cocos2d::CCApplication::sharedApplication()->run();
    
    self->window.rootViewController = self->viewController;
	[self->window makeKeyAndVisible];
    
    // 让手机知道我们想接收推送信息提示
    if([[UIDevice currentDevice].systemVersion floatValue] >= 10.0){
        [[UIApplication sharedApplication] registerForRemoteNotifications];
        UNUserNotificationCenter *center = [UNUserNotificationCenter currentNotificationCenter];
        center.delegate = self;
        [center requestAuthorizationWithOptions:(UNAuthorizationOptionBadge | UNAuthorizationOptionSound | UNAuthorizationOptionAlert) completionHandler:^(BOOL granted, NSError * _Nullable error) {
            if (!error) {
                NSLog(@"succeeded!");
            }
        }];
    }
    else if ([[UIDevice currentDevice].systemVersion floatValue] >= 8.0) {
        [[UIApplication sharedApplication] registerForRemoteNotifications];
        [[UIApplication sharedApplication] registerUserNotificationSettings:[UIUserNotificationSettings settingsForTypes:
                                                                             (UIRemoteNotificationTypeBadge | UIRemoteNotificationTypeSound | UIRemoteNotificationTypeAlert) categories:nil]];
    } else {
        [[UIApplication sharedApplication] registerForRemoteNotificationTypes:(UIRemoteNotificationTypeBadge | UIRemoteNotificationTypeSound | UIRemoteNotificationTypeAlert)];
    }    
    return YES;
}


- (BOOL)application:(UIApplication *)application handleOpenURL:(NSURL *)url {
    //[[IPAYiAppPay sharediAppPay] handleOpenurl: url];
    
    [WXApi handleOpenURL:url delegate:self];
    
	return YES;
}

- (BOOL)application:(UIApplication *)application openURL:(NSURL *)url sourceApplication:(NSString *)sourceApplication annotation:(id)annotation {
    
    //[[IPAYiAppPay sharediAppPay] handleOpenurl: url];
    
    [WXApi handleOpenURL:url delegate:self];

	return YES;
}

- (void)applicationWillResignActive:(UIApplication *)application {
    /*
     Sent when the application is about to move from active to inactive state. This can occur for certain types of temporary interruptions (such as an incoming phone call or SMS message) or when the user quits the application and it begins the transition to the background state.
     Use this method to pause ongoing tasks, disable timers, and throttle down OpenGL ES frame rates. Games should use this method to pause the game.
     */
    cocos2d::CCDirector::sharedDirector()->pause();
    cocos2d::CCApplication::sharedApplication()->applicationDidEnterBackground();
}

- (void)applicationDidBecomeActive:(UIApplication *)application {
    /*
     Restart any tasks that were paused (or not yet started) while the application was inactive. If the application was previously in the background, optionally refresh the user interface.
     */
    cocos2d::CCDirector::sharedDirector()->resume();
    //取消之前所有的本地通知
    [self clearNotificationPromptMessage];
    cocos2d::CCApplication::sharedApplication()->applicationWillEnterForeground();
}

- (void)applicationDidEnterBackground:(UIApplication *)application {
    /*
     Use this method to release shared resources, save user data, invalidate timers, and store enough application state information to restore your application to its current state in case it is terminated later.
     If your application supports background execution, called instead of applicationWillTerminate: when the user quits.
     */
    //cocos2d::CCApplication::sharedApplication()->applicationDidEnterBackground();
}

- (void)applicationWillEnterForeground:(UIApplication *)application {
    /*
     Called as part of  transition from the background to the inactive state: here you can undo many of the changes made on entering the background.
     */
    //cocos2d::CCApplication::sharedApplication()->applicationWillEnterForeground();
    
    //取消之前所有的本地通知
//    [self clearNotificationPromptMessage];
}

- (void)applicationWillTerminate:(UIApplication *)application {
    /*
     Called when the application is about to terminate.
     See also applicationDidEnterBackground:.
     */
}

#pragma mark - APNs -

- (void)application:(UIApplication *)app didRegisterForRemoteNotificationsWithDeviceToken:(NSData *)deviceToken {
    NSArray *t1Token = [deviceToken.description componentsSeparatedByString:@" "];
    NSString *t1TokenString = [[NSString alloc] init];
    for (NSString *s in t1Token) {
        t1TokenString = [t1TokenString stringByAppendingString:s];
    }
    NSArray *t2Token = [t1TokenString componentsSeparatedByString:@"<"];
    NSString *t2TokenString = [t2Token lastObject];
    
    NSArray *t3Token = [t2TokenString componentsSeparatedByString:@">"];
    NSString *tokenString = [t3Token objectAtIndex:0];

    NSLog(@"My token is: %@", tokenString);
    [[NSUserDefaults standardUserDefaults] setObject:tokenString forKey:@"token"];
    [[NSUserDefaults standardUserDefaults] synchronize];
}

- (void)application:(UIApplication *)app didFailToRegisterForRemoteNotificationsWithError:(NSError *)error {
    NSString *error_str = [NSString stringWithFormat: @"%@", error];
    NSLog(@"Failed to get token, error:%@", error_str);
}

- (void)application:(UIApplication*)application didReceiveRemoteNotification:(NSDictionary *)userInfo {
    for (id key in userInfo) {
        NSLog(@"key: %@, value: %@", key, [userInfo objectForKey:key]);
    }
    
    [self clearNotificationPromptMessage];
}

- (void)clearNotificationPromptMessage
{
    [[UIApplication sharedApplication] setApplicationIconBadgeNumber:1];
    [[UIApplication sharedApplication] setApplicationIconBadgeNumber:0];
}

- (void)application:(UIApplication *)application didReceiveLocalNotification:(UILocalNotification*)notification{
    //在此时设置解析notification，并展示提示视图
    application.applicationIconBadgeNumber = 0;
    [[UIApplication sharedApplication] cancelLocalNotification:notification];
}
//ios10 点击推送 后台进入前台的会掉
- (void)userNotificationCenter:(UNUserNotificationCenter *)center didReceiveNotificationResponse:(UNNotificationResponse *)response withCompletionHandler:(void (^)())completionHandler {
    NSDictionary *userInfo = response.notification.request.content.userInfo;
    //消息处理
    
    for (id key in userInfo) {
        NSLog(@"key: %@, value: %@", key, [userInfo objectForKey:key]);
    }
    
    [self clearNotificationPromptMessage];
    
}
//ios10 点击推送 前台的会掉
- (void)userNotificationCenter:(UNUserNotificationCenter *)center willPresentNotification:(UNNotification *)notification withCompletionHandler:(void (^)(UNNotificationPresentationOptions))completionHandler{
    NSDictionary *userInfo = notification.request.content.userInfo;
    //消息处理
    
    for (id key in userInfo) {
        NSLog(@"key: %@, value: %@", key, [userInfo objectForKey:key]);
    }
    
    [self clearNotificationPromptMessage];
    
}

#pragma mark - WeApi Delegate -

- (void)onReq:(BaseReq *)req
{
    
}

- (void)onResp:(BaseResp *)resp
{
    NSString *strMsg = [NSString stringWithFormat:@"errcode:%d", resp.errCode];
    NSString *strTitle;
    if([resp isKindOfClass:[SendMessageToWXResp class]])
    {
        int errCode = resp.errCode;
        
        NSString *parameters = @"";
        if (errCode == 0) {
            parameters = @"OK";
        }else if (errCode == -1 or errCode == -3 or errCode == -5) {
            parameters = @"OTHER";
        }else if (errCode == -2) {
            parameters = @"CANCEL";
        }else if (errCode == -4) {
            parameters = @"DENIDE";
        }
        // OC调用Lua方法
        int callBackFunction = [[NSUserDefaults standardUserDefaults] integerForKey:@"Wechat_Share_Callback"];
        
        // 1. 将引用 ID 对应的 Lua function 放入 Lua stack
        CCLuaObjcBridge::pushLuaFunctionById(callBackFunction);
        
        // 2. 将需要传递给 Lua function 的参数放入 Lua stack
        CCLuaObjcBridge::getStack()->pushCCLuaValue(CCLuaValue::stringValue(parameters.UTF8String));
        
        // 3. 执行 Lua function
        CCLuaObjcBridge::getStack()->executeFunction(1);
        
        // 4. 释放引用 ID
        CCLuaObjcBridge::releaseLuaFunctionById(callBackFunction);
    }else if([resp isKindOfClass:[PayResp class]]) {
        //支付返回结果，实际支付结果需要去微信服务器端查询
        strTitle = [NSString stringWithFormat:@"支付结果"];
        
        switch (resp.errCode) {
            case WXSuccess:
                strMsg = @"支付结果：成功！";
                NSLog(@"支付成功－PaySuccess，retcode = %d", resp.errCode);
                break;
                
            default:
                strMsg = [NSString stringWithFormat:@"支付结果：失败！retcode = %d, retstr = %@", resp.errCode,resp.errStr];
                NSLog(@"错误，retcode = %d, retstr = %@", resp.errCode,resp.errStr);
                break;
        }
        
    }else if ([resp isKindOfClass:[SendAuthResp class]]) {
        SendAuthResp *authResp = (SendAuthResp *)resp;
        NSString* code = authResp.code;
        NSString* state = authResp.state;
        NSString* lang = authResp.lang;
        NSString* country = authResp.country;
        NSLog(@"微信登陆－code = %@", code);
        NSLog(@"微信登陆－state = %@", state);
        NSLog(@"微信登陆－lang = %@", lang);
        NSLog(@"微信登陆－country = %@", country);
        int callBackFunction = [[[NSUserDefaults standardUserDefaults] objectForKey:@"WECHAT_LOGIN_CALLBACK"] intValue];
        
        // 1. 通过ID把function压栈
        CCLuaObjcBridge::pushLuaFunctionById(callBackFunction);
        
        // 2. 将需要传递给 Lua function 的参数放入 Lua stack
        CCLuaValueDict item;
        
        if (code) {
            item["wxcode"] = CCLuaValue::stringValue([code UTF8String]);
        }else{
            item["wxcode"] = CCLuaValue::stringValue([@"-1" UTF8String]);
        }
        
        if (state) {
            item["wxstate"] = CCLuaValue::stringValue([state UTF8String]);
        }else{
            item["wxstate"] = CCLuaValue::stringValue([@"-1" UTF8String]);
        }
        
        CCLuaObjcBridge::getStack()->pushCCLuaValueDict(item);
        
        // 3. 执行 Lua function
        CCLuaObjcBridge::getStack()->executeFunction(1);
        
        // 4. 释放引用 ID
        CCLuaObjcBridge::releaseLuaFunctionById(callBackFunction);
    }
}

#pragma mark -
#pragma mark Memory management

- (void)applicationDidReceiveMemoryWarning:(UIApplication *)application {
    /*
     Free up as much memory as possible by purging cached data objects that can be recreated (or reloaded from disk) later.
     */
     cocos2d::CCDirector::sharedDirector()->purgeCachedData();
}


- (void)dealloc {
    [super dealloc];
}

// 获取手机DeviceToken
+ (NSDictionary *)getDeviceToken:(NSDictionary *)dict{
    NSString *dToken = [[NSUserDefaults standardUserDefaults] objectForKey:@"token"];
    return [NSDictionary dictionaryWithObjectsAndKeys:dToken, @"token", [NSNumber numberWithInt:1], @"error", nil];
}

@end

