
#import "FacebookConfig.h"

#import "platform/ios/CCNativeIOS.h"
#include "cocos2d.h"
#import <FacebookSDK/FacebookSDK.h>
#import "CCLuaObjcBridge.h"
#import "ToastViewController.h"

@implementation FacebookConfig

+ (void) facebookLogout:(NSDictionary *)dict {
    if (FBSession.activeSession.state == FBSessionStateOpen
        || FBSession.activeSession.state == FBSessionStateOpenTokenExtended) {
        
        [FBSession.activeSession closeAndClearTokenInformation];
    }
}

+ (void)facebookLogin:(NSDictionary *)dict {
    //    if (FBSession.activeSession.state == FBSessionStateOpen
    //        || FBSession.activeSession.state == FBSessionStateOpenTokenExtended) {
    //        //action();
    //         NSLog(@"FBPerformPublishAction return ========== ");
    //        return;
    //    }
    
    [FBSession openActiveSessionWithReadPermissions:@[@"public_profile", @"user_friends"]
                                       allowLoginUI:YES
                                  completionHandler:
     ^(FBSession *session, FBSessionState state, NSError *error) {
         if (!error) {
             NSLog(@"Logged in");
             // 调用lua函数
             int callBackFunction = [[dict objectForKey:@"callback"] intValue];
             
             // 1. 将引用 ID 对应的 Lua function 放入 Lua stack
             CCLuaObjcBridge::pushLuaFunctionById(callBackFunction);
             
             // 2. 将需要传递给 Lua function 的参数放入 Lua stack
             CCLuaValueDict dictParameter;
             dictParameter["token"] = CCLuaValue::stringValue(session.accessTokenData.accessToken.UTF8String);
             CCLuaObjcBridge::getStack()->pushCCLuaValueDict(dictParameter);
             
             // 3. 执行 Lua function
             CCLuaObjcBridge::getStack()->executeFunction(1);
             
             // 4. 不释放引用 ID 注释掉下方代码
             CCLuaObjcBridge::releaseLuaFunctionById(callBackFunction);
             NSLog(@"session.accessTokenData.accessToken == %@",session.accessTokenData.accessToken);
         } else if (error.fberrorCategory != FBErrorCategoryUserCancelled) {
             UIAlertView *alertView = [[UIAlertView alloc] initWithTitle:@"Permission denied"
                                                                 message:@"Unable to get permission to post"
                                                                delegate:nil
                                                       cancelButtonTitle:@"OK"
                                                       otherButtonTitles:nil];
             [alertView show];
         } else{
             NSLog(@"FBPerformPublishAction error ========== ");
         }
     }];
}

+ (int)facebookShare:(NSDictionary *)dict {
    NSString *picPath = [dict objectForKey:@"imageURL"];
    NSLog(@"canPresent: %@", picPath);
    UIImage *img = [UIImage imageWithContentsOfFile: picPath];
    BOOL canPresent = [FBDialogs canPresentShareDialogWithPhotos];
    NSLog(@"canPresent: %d", canPresent);
    
    FBPhotoParams *params = [[FBPhotoParams alloc] init];
    params.photos = @[img];
    
    BOOL isSuccessful = NO;
    if (canPresent) {
        FBAppCall *appCall = [FBDialogs presentShareDialogWithPhotoParams:params
                                                              clientState:nil
                                                                  handler:^(FBAppCall *call, NSDictionary *results, NSError *error) {
                                                                      if (error) {
                                                                          NSLog(@"Error: %@", error.description);
                                                                      } else {
                                                                          NSLog(@"Success!");
                                                                      }
                                                                  }];
        isSuccessful = (appCall  != nil);
    }
    
    FBRequestConnectionErrorBehavior errorBehavior;
    errorBehavior = (FBRequestConnectionErrorBehavior)(FBRequestConnectionErrorBehaviorReconnectSession
                                                       | FBRequestConnectionErrorBehaviorAlertUser
                                                       | FBRequestConnectionErrorBehaviorRetry);
    return canPresent;
}

@end
