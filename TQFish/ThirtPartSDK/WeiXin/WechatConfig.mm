
#import "WechatConfig.h"

#import "platform/ios/CCNativeIOS.h"
#import "WXApi.h"
#include "cocos2d.h"
#import "CCLuaObjcBridge.h"
#import "ToastViewController.h"

@implementation WechatConfig

// 微信支付回调
+(void) weixinPayResult:(NSDictionary*)dict {
    
    int callBackFunction = [[dict objectForKey:@"installedCallBack"] intValue];
    //NSString *appid = [dict objectForKey:@"appid"];
    NSString *partnerid = [dict objectForKey:@"partnerid"];
    NSString *prepayid = [dict objectForKey:@"prepayid"];
    NSString *noncestr = [dict objectForKey:@"noncestr"];
    NSString *timestamp = [dict objectForKey:@"timestamp"];
    NSString *package = [dict objectForKey:@"package"];
    NSString *sign = [dict objectForKey:@"sign"];
    
    [[NSUserDefaults standardUserDefaults] setInteger:callBackFunction forKey:@"Wechat_Installed_Callback"];
    
    if (![WXApi isWXAppInstalled]) {
        NSLog(@"未安装微信");        // OC调用Lua方法
        NSString *parameters = @"HAVE_NO_WX";
        
        // 1. 将引用 ID 对应的 Lua function 放入 Lua stack
        CCLuaObjcBridge::pushLuaFunctionById(callBackFunction);
        
        // 2. 将需要传递给 Lua function 的参数放入 Lua stack
        CCLuaObjcBridge::getStack()->pushCCLuaValue(CCLuaValue::stringValue(parameters.UTF8String));
        
        // 3. 执行 Lua function
        CCLuaObjcBridge::getStack()->executeFunction(1);
        
        // 4. 释放引用 ID
        CCLuaObjcBridge::releaseLuaFunctionById(callBackFunction);
        
        return;
    }
    
    PayReq *request = [[[PayReq alloc] init] autorelease];
    request.partnerId = partnerid;
    request.prepayId = prepayid;
    request.package = package;
    request.nonceStr = noncestr;
    request.timeStamp = [timestamp longLongValue];
    request.sign= sign;
    
    NSLog(@"partnerId:%@", request.partnerId);
    NSLog(@"prepayId:%@", request.prepayId);
    NSLog(@"package:%@", request.package);
    NSLog(@"nonceStr:%@", request.nonceStr);
    NSLog(@"timeStamp:%@", timestamp);
    NSLog(@"sign:%@", request.sign);
    
    [WXApi sendReq:request];
}

// 微信分享
+ (void) weixinShare:(NSDictionary*)dict {
    int callBackFunction = [[dict objectForKey:@"shareCallBack"] intValue];
    int _scene = [[dict objectForKey:@"params"] integerValue];
    NSString *appDownLoadURL = [dict valueForKey:@"AppDownLoadURL"];
    NSString *showTitle = [dict valueForKey:@"showTitle"];
    NSString *showMessage = [dict valueForKey:@"showMessage"];
    
    [[NSUserDefaults standardUserDefaults] setInteger:callBackFunction forKey:@"Wechat_Share_Callback"];
    
    if (![WXApi isWXAppInstalled]) {
        NSLog(@"未安装微信");        // OC调用Lua方法
        NSString *parameters = @"HAVE_NO_WX";
        
        // 1. 将引用 ID 对应的 Lua function 放入 Lua stack
        CCLuaObjcBridge::pushLuaFunctionById(callBackFunction);
        
        // 2. 将需要传递给 Lua function 的参数放入 Lua stack
        CCLuaObjcBridge::getStack()->pushCCLuaValue(CCLuaValue::stringValue(parameters.UTF8String));
        
        // 3. 执行 Lua function
        CCLuaObjcBridge::getStack()->executeFunction(1);
        
        // 4. 释放引用 ID
        CCLuaObjcBridge::releaseLuaFunctionById(callBackFunction);
        
        return;
    }
    
    
    WXWebpageObject *ext = [WXWebpageObject object];
    ext.webpageUrl = appDownLoadURL;
    
    WXMediaMessage * msg = [WXMediaMessage message];
    msg.title = showTitle;
    msg.description = showMessage;
    [msg setThumbImage:[UIImage imageNamed:@"Icon-72.png"]];
    msg.mediaObject = ext;
    
    SendMessageToWXReq* req = [[[SendMessageToWXReq alloc] init] autorelease];
    req.bText = NO;
    req.scene = _scene;
    req.message = msg;
    
    [WXApi sendReq:req];
}

// 微信分享图片
+ (void) weixinSharePic:(NSDictionary*)dict {
    int callBackFunction = [[dict objectForKey:@"shareCallBack"] intValue];
    int _scene = [[dict objectForKey:@"params"] integerValue];
    NSString *iconPath = [dict valueForKey:@"iconPath"];
    NSString *picPath = [dict valueForKey:@"picPath"];
    
    [[NSUserDefaults standardUserDefaults] setInteger:callBackFunction forKey:@"Wechat_Share_Callback"];
    
    if (![WXApi isWXAppInstalled]) {
        NSLog(@"未安装微信");        // OC调用Lua方法
        NSString *parameters = @"HAVE_NO_WX";
        
        // 1. 将引用 ID 对应的 Lua function 放入 Lua stack
        CCLuaObjcBridge::pushLuaFunctionById(callBackFunction);
        
        // 2. 将需要传递给 Lua function 的参数放入 Lua stack
        CCLuaObjcBridge::getStack()->pushCCLuaValue(CCLuaValue::stringValue(parameters.UTF8String));
        
        // 3. 执行 Lua function
        CCLuaObjcBridge::getStack()->executeFunction(1);
        
        // 4. 释放引用 ID
        CCLuaObjcBridge::releaseLuaFunctionById(callBackFunction);
        
        return;
    }
    
    
    WXMediaMessage * message = [WXMediaMessage message];
    //缩略图
    [message setThumbImage:[UIImage imageNamed:iconPath]];
    //要用的图片内容
    WXImageObject *imageObject = [WXImageObject object];
    imageObject.imageData = [NSData dataWithContentsOfFile:picPath];
    message.mediaObject = imageObject;
    
    SendMessageToWXReq* req = [[[SendMessageToWXReq alloc] init] autorelease];
    req.bText = NO;
    req.scene = _scene;
    req.message = message;
    
    [WXApi sendReq:req];
}

//微信登录
+(void)weixinLogin:(NSDictionary *)dict {
    if (![WXApi isWXAppInstalled]) {
        NSMutableDictionary *dict = [NSMutableDictionary dictionary];
        NSString *strMsg = @"安装微信才可以登录哟 O(∩_∩)O";
        float time = 2.0;
        [dict setObject:strMsg forKey:@"msg"];
        [dict setObject:[NSString stringWithFormat:@"%f", time] forKey:@"time"];
        [ToastViewController open:dict];
        return;
    }
    NSString *callbackLogined = [dict objectForKey:@"callbackLogined"];
    NSLog(@"weixinLogin==============%@", callbackLogined);
    NSString *loginState = [dict objectForKey:@"wechatLoginState"];
    NSLog(@"weixinLogin==============%@", loginState);
    [[NSUserDefaults standardUserDefaults] setObject:callbackLogined forKey:@"WECHAT_LOGIN_CALLBACK"];
    
    //构造SendAuthReq结构体
    SendAuthReq* req =[[[SendAuthReq alloc ] init ] autorelease ];
    req.scope = @"snsapi_userinfo" ;
    req.state = loginState ;
    //第三方向微信终端发送一个SendAuthReq消息结构
    [WXApi sendReq:req];
}

//获取是否安装微信APP
+ (NSString*)gethasWechatAPP:(NSDictionary *)dict {
    NSString *hasWechatAPP = @"NO";
    if ([WXApi isWXAppInstalled]) {
        hasWechatAPP = @"YES";
    }
    return hasWechatAPP;
}

@end
