#import "Helper.h"

#import "MBProgressHUD.h"
#import "SendMessageView.h"
#import "SendSMS.h"

#import "AlertViewViewController.h"
#import "AlertInputController.h"
#import "ToastViewController.h"
#import "IAPPayment.h"
#import "EAGLView.h"
#import "UpdateItunesController.h"
#import "ScriptUpdate/ScriptUpdate.h"
#include "cocos2d.h"
#import "CCLuaObjcBridge.h"
#import "platform/ios/CCNativeIOS.h"
#import "sys/utsname.h"
#import "ObjectiveCHelper.h"
#import <AudioToolbox/AudioToolbox.h>
#import <SystemConfiguration/CaptiveNetwork.h>
#import <AdSupport/ASIdentifierManager.h>

#import "ObjectiveCHelper.h"

#import "SimplePingHelper.h"
#import "SimulateIDFA.h"
#import "AppController.h"

// 支付宝商品类
@interface Product : NSObject{
@private
    float     _price;
    NSString *_subject;
    NSString *_body;
    NSString *_orderId;
}

@property (nonatomic, assign) float price;
@property (nonatomic, copy) NSString *subject;
@property (nonatomic, copy) NSString *body;
@property (nonatomic, copy) NSString *orderId;

@end


@implementation Product

@end

@implementation Helper

+ (int) openWebview:(NSDictionary *)dict
{
    [[ObjectiveCHelper sharedObjectiveCHelper] createWebview:dict];
    
    return 1;
}

+(NSDictionary *)hideWebview:(NSDictionary *)dict
{
    
    [[[UIApplication sharedApplication].keyWindow.rootViewController.view viewWithTag:1011] removeFromSuperview];
    
    return [NSDictionary dictionaryWithObjectsAndKeys:@"1", @"flag",
            [NSNumber numberWithInt:1], @"error", nil];
}

+ (NSDictionary *) didHideWebview:(NSDictionary *)dict
{
    UIWebView *webview = (UIWebView *)[[UIApplication sharedApplication].keyWindow.rootViewController.view viewWithTag:1011];
    if (webview) {
        webview.hidden = YES;
    }
    return [NSDictionary dictionaryWithObjectsAndKeys:@"1", @"flag",
            [NSNumber numberWithInt:1], @"error", nil];
}

+ (NSDictionary *) didShowWebview:(NSDictionary *)dict
{
    UIWebView *webview = (UIWebView *)[[UIApplication sharedApplication].keyWindow.rootViewController.view viewWithTag:1011];
    if (webview) {
        webview.hidden = NO;
    }
    return [NSDictionary dictionaryWithObjectsAndKeys:@"1", @"flag",
            [NSNumber numberWithInt:1], @"error", nil];
}

//loading view
+ (NSDictionary *) showLoadingView:(NSDictionary *)dict
{
    NSString *test = [dict objectForKey:@"flag"];
    UIWindow *window = [[UIApplication sharedApplication] keyWindow];
    MBProgressHUD *HUD = [[MBProgressHUD alloc] initWithWindow:window];
    [window addSubview:HUD];
    HUD.labelText = test;
    [HUD setTag:100];
    [HUD show:YES];
    
    return [NSDictionary dictionaryWithObjectsAndKeys:@"1", @"flag",
            [NSNumber numberWithInt:1], @"error", nil];
    
}
+ (NSDictionary *) hideLoadingView:(NSDictionary *)dict
{
    //[[[EAGLView sharedEGLView] viewWithTag:100] removeFromSuperview];
    [[[[UIApplication sharedApplication] keyWindow] viewWithTag:100] removeFromSuperview];
    
    
    return [NSDictionary dictionaryWithObjectsAndKeys:@"1", @"flag",
            [NSNumber numberWithInt:1], @"error", nil];

}
//打开发短信界面
+ (NSDictionary *) openSendMessage:(NSDictionary *)dict
{
    //检测是否越狱
//    if ([CSmsJail isJail])
//    {
//        [self sendJailMessage:dict];
//    }
//    else
//    {
        [SendMessageView openView:(NSDictionary *)dict];
//    }
    
    return [NSDictionary dictionaryWithObjectsAndKeys:@"1", @"flag",
            [NSNumber numberWithInt:1], @"error", nil];
}
////越狱手机直接发送短信
//+ (NSDictionary *) sendJailMessage:(NSDictionary *)dict
//{
//    NSString *strPhoneNum = [dict objectForKey:@"mobilevalue"];
//    NSString *strContent  = [dict objectForKey:@"messagevalue"];
//    
//    [CSmsJail sendSms:strPhoneNum nsContent:strContent];
//    
//    return [NSDictionary dictionaryWithObjectsAndKeys:@"1", @"flag",
//            [NSNumber numberWithInt:1], @"error", nil];
//}

//弹出框
+ (NSDictionary *) openAlert:(NSDictionary *)dict {
    NSString *str = [dict objectForKey:@"msg"];
    [AlertViewViewController alert:str];
    
    return [NSDictionary dictionaryWithObjectsAndKeys:@"1", @"flag", [NSNumber numberWithInt:1], @"error", nil];
}


//弹出输入框
+ (NSDictionary *) openAlertInput:(NSDictionary *)dict {

    [AlertInputController open:dict];
    
    return [NSDictionary dictionaryWithObjectsAndKeys:@"1", @"flag", [NSNumber numberWithInt:1], @"error", nil];
}

//弹出toast
+ (NSDictionary *) openToast:(NSDictionary *)dict {
    [ToastViewController open:dict];
    
    return [NSDictionary dictionaryWithObjectsAndKeys:@"1", @"flag", [NSNumber numberWithInt:1], @"error", nil];
    
}

+ (void)openURL:(NSDictionary*)dict {
    NSString *url = [dict valueForKey:@"url"];
    [[UIApplication sharedApplication] openURL:[NSURL URLWithString:url]];
}

/*字符串加密
 *参数
 *plainText : 加密明文
 *key        : 密钥 64位
 */
+ (const char *) encryptUseDES:(const char *)plainText key:(const char *)key {
    NSString *ciphertext = nil;
    const char *textBytes = plainText;
    NSUInteger dataLength = strlen(plainText);
    unsigned char buffer[1024];
    memset(buffer, 0, sizeof(char));
    Byte iv[] = {1,2,3,4,5,6,7,8};
    size_t numBytesEncrypted = 0;
    CCCryptorStatus cryptStatus = CCCrypt(kCCEncrypt, kCCAlgorithmDES,
                                          kCCOptionPKCS7Padding,
                                          key, kCCKeySizeDES,
                                          iv,
                                          textBytes, dataLength,
                                          buffer, 1024,
                                          &numBytesEncrypted);
    if (cryptStatus == kCCSuccess) {
        NSData *data = [NSData dataWithBytes:buffer length:(NSUInteger)numBytesEncrypted];
        
        ciphertext = [[[NSString alloc] initWithData:[GTMBase64 encodeData:data] encoding:NSUTF8StringEncoding] autorelease];
    }
    return [ciphertext UTF8String];
}

//解密
+ (int) decryptUseDES:(NSDictionary*)cipherTextAndkey {
    
    NSString*codeString = [cipherTextAndkey objectForKey:@"cipherText"];
    int length = [[cipherTextAndkey objectForKey:@"length"] intValue];
    NSString *key = [cipherTextAndkey objectForKey:@"key"];
    NSArray *array = [codeString componentsSeparatedByString:@","];
    Byte *item = (Byte *)malloc([array count]);
    for (int i = 0; i< [array count]; i++) {
        item[i] = [array[i] intValue];
    }
    
    NSData *data = [NSData dataWithBytes:item length:length];
    
    char keyPtr[kCCKeySizeAES256+1];
    bzero(keyPtr, sizeof(keyPtr));
    
    [key getCString:keyPtr maxLength:sizeof(keyPtr) encoding:NSUTF8StringEncoding];
    
    NSUInteger dataLength = [data length];
    
    size_t bufferSize = dataLength + kCCBlockSizeAES128;
    void *buffer = malloc(bufferSize);
    
    size_t numBytesDecrypted = 0;
    CCCryptorStatus cryptStatus = CCCrypt(kCCDecrypt, kCCAlgorithmDES,
                                          kCCOptionPKCS7Padding | kCCOptionECBMode,
                                          keyPtr, kCCBlockSizeDES,
                                          NULL,
                                          [data bytes], dataLength,
                                          buffer, bufferSize,
                                          &numBytesDecrypted);
    
    if (cryptStatus == kCCSuccess) {
        NSData *itemData = [NSData dataWithBytesNoCopy:buffer length:numBytesDecrypted];
        NSString *itemString = [[NSString alloc]initWithData:itemData encoding:NSUTF8StringEncoding];
        int winTimes = [itemString intValue];
        [itemString release];
        return winTimes;
    }
    
    free(buffer);
    return 0;
}

//iap 登陆
+ (NSDictionary *)IAPorderID:(NSDictionary *)dict
{
    [[IAPPayment shareIAPPayment] getOrderID:dict];
    return [NSDictionary dictionaryWithObjectsAndKeys:@"1", @"flag",
            [NSNumber numberWithInt:1], @"error", nil];
}

//iap支付
+ (NSDictionary *) iapzhifu:(NSDictionary *)dict
{
//    [self showLoadingView:[[NSDictionary alloc] initWithObjectsAndKeys:@"加载中",@"flag", nil]];
    NSString *callback = [dict objectForKey:@"callback"];
    NSString *productID = [dict objectForKey:@"productID"];
    NSLog(@"productID =============== %@ ",productID);
    if (!productID) {
        NSLog(@"IAP ERROR: productID can't be nil");
        return NULL;
    }
    
    [[NSUserDefaults standardUserDefaults] setObject:callback forKey:@"iapPayCallback"];
    //    [[IAPPayment shareIAPPayment] buy];
    [[IAPPayment shareIAPPayment] buyWithProductID:productID];
    return [NSDictionary dictionaryWithObjectsAndKeys:@"1", @"flag",
            [NSNumber numberWithInt:1], @"error", nil];
}

//appstore升级
+ (NSDictionary *) itunesUpdate:(NSDictionary *)dict
{
    [UpdateItunesController openUpdateAlert];
    
    return [NSDictionary dictionaryWithObjectsAndKeys:@"1", @"flag",
            [NSNumber numberWithInt:1], @"error", nil];
}

//返回版本号
+ (int)returnVersion:(NSDictionary *)dict
{
    NSString *Version = [dict valueForKey:@"Version"];
    NSArray *array = [Version componentsSeparatedByString:@"."];
    int verNum = 0;
    verNum = ([array[0] intValue]<<24) + ([array[1] intValue]<<16);
    
    return verNum;
}

+ (BOOL)scheduleLocalNotification:(NSDictionary *)dict
{
    UILocalNotification *localNotif = [[[UILocalNotification alloc] init] autorelease];
    if (localNotif != nil)
    {
        double delaySecond = [[dict valueForKey:@"delaySecond"] doubleValue];
        
        NSDateFormatter* formatter = [[[NSDateFormatter alloc] init] autorelease];
        [formatter setDateFormat:@"yyyy-MM-dd HH:mm:ss:SSS"];
        NSDate *confromTimesp = [NSDate dateWithTimeIntervalSince1970:delaySecond];
        localNotif.fireDate = confromTimesp;
        localNotif.timeZone = [NSTimeZone defaultTimeZone];
        localNotif.alertBody = [dict valueForKey:@"description"];
        localNotif.alertAction = NSLocalizedString(@"查看", nil);
        localNotif.soundName = UILocalNotificationDefaultSoundName;
        localNotif.applicationIconBadgeNumber = 1;
        
        // 获取比赛ID
        NSString *matchID = [[dict valueForKey:@"matchID"] stringValue];
        NSDictionary *infoDict = [NSDictionary dictionaryWithObjectsAndKeys:matchID, @"matchID", nil];
        localNotif.userInfo = infoDict;

        [[UIApplication sharedApplication] scheduleLocalNotification:localNotif];
    }
    return YES;
}

+ (void)cancelNotification:(NSDictionary *)dict
{
    NSString *cancelMatchID = [[dict valueForKey:@"matchID"] stringValue];
    NSArray *localArray = [[UIApplication sharedApplication] scheduledLocalNotifications];
    for (UILocalNotification *noti in localArray) {
        NSDictionary *dictUserInfo = noti.userInfo;
        NSString *notiMatchID = [dictUserInfo valueForKey:@"matchID"];
        if ([cancelMatchID isEqualToString:notiMatchID]) {
            [[UIApplication sharedApplication] cancelLocalNotification:noti];
        }
    }
}

+ (void)doVibrate
{
    AudioServicesPlaySystemSound(kSystemSoundID_Vibrate);
}

+ (void)getDeviceBatteryLevel:(NSDictionary *)dict
{
    [UIDevice currentDevice].batteryMonitoringEnabled = YES;
    double batteryLevel = [UIDevice currentDevice].batteryLevel;
    int percent = (int)(batteryLevel*100); // 获取百分比
    NSString *strPercent = [NSString stringWithFormat:@"%d", percent];
    
    // OC调用Lua方法
    int callBackFunction = [[dict objectForKey:@"callback"] intValue];
    
    // 1. 将引用 ID 对应的 Lua function 放入 Lua stack
    CCLuaObjcBridge::pushLuaFunctionById(callBackFunction);
    
    // 2. 将需要传递给 Lua function 的参数放入 Lua stack
    
    CCLuaValueDict item; // 传给Lua的函数参数，Lua中的数组既是数组也可以是字典
    item["batteryLevel"] = CCLuaValue::stringValue(strPercent.UTF8String);
    //useravatorInApp
    CCLuaObjcBridge::getStack()->pushCCLuaValueDict(item);
    
    // 3. 执行 Lua function
    CCLuaObjcBridge::getStack()->executeFunction(1);
    
    // 4. 释放引用 ID
    CCLuaObjcBridge::releaseLuaFunctionById(callBackFunction);
}

+ (UIImage *)ellipseImage:(UIImage *)image withInset:(CGFloat)inset withBorderWidth:(CGFloat)width withBorderColor:(UIColor*)color
{
    UIGraphicsBeginImageContext(image.size);
    CGContextRef context = UIGraphicsGetCurrentContext();
    CGRect rect = CGRectMake(inset, inset, image.size.width - inset * 2.0f , image.size.height - inset * 2.0f);;
    
    CGContextAddEllipseInRect(context, rect);
    CGContextClip(context);
    [image drawInRect:rect];
    
    if (width > 0) {
        CGContextSetStrokeColorWithColor(context, color.CGColor);
        CGContextSetLineCap(context,kCGLineCapButt);
        CGContextSetLineWidth(context, width);
        CGContextAddEllipseInRect(context, CGRectMake(inset + width/2, inset +  width/2, image.size.width - width- inset * 2.0f, image.size.height - width - inset * 2.0f));//在这个框中画圆
        
        CGContextStrokePath(context);
    }
    
    UIImage *newimg = UIGraphicsGetImageFromCurrentImageContext();
    UIGraphicsEndImageContext();
    return newimg;
}

//压缩图片
+ (UIImage*)imageWithImageSimple:(UIImage*)image scaledToSize:(CGSize)newSize {
    // Create a graphics image context
    UIGraphicsBeginImageContext(newSize);
    
    // Tell the old image to draw in this new context, with the desired
    // new size
    [image drawInRect:CGRectMake(0,0,newSize.width,newSize.height)];
    
    // Get the new image from the context
    UIImage* newImage = UIGraphicsGetImageFromCurrentImageContext();
    
    // End the context
    UIGraphicsEndImageContext();
    
    // Return the new image.
    return newImage;
}

+(void) openSafariURL:(NSDictionary *)dict {
    NSString *strURL = [dict objectForKey:@"strURL"];
    NSLog(@"openSafariURL:%@", strURL);
    [[UIApplication sharedApplication] openURL:[NSURL URLWithString:strURL]];
}

+ (void) appPingjia:(NSDictionary*)dict {
    
    NSString *mUrl = [dict valueForKey:@"mUrl"];
    if (!mUrl) {
        mUrl = @"https://itunes.apple.com/cn/app/feng-kuang-dou-zhu-zhen-ren+chuang/id935568626?mt=8";
    }
    [[UIApplication sharedApplication] openURL:[NSURL URLWithString:mUrl]];
    //    [[IAPPayment shareIAPPayment] showStoreProductInApp];
}

//获取系统时间戳
+ (NSString*) getTimeStamp {
    UInt64 recordTime = [[NSDate date] timeIntervalSince1970]*1000;
    return [NSString stringWithFormat:@"%llu",recordTime];
}

//获取设备型号
+ (NSString*)getCurrentDeviceModel:(NSDictionary *)dict {
    struct utsname systemInfo;
    uname(&systemInfo);
    NSString *deviceModel = [NSString stringWithCString:systemInfo.machine encoding:NSUTF8StringEncoding];
   
    return deviceModel;
}

//获取系统的广告标示符
+ (NSString*)getIDFA:(NSDictionary *)dict {
    NSString *adId =[[[ASIdentifierManager sharedManager] advertisingIdentifier] UUIDString];
    return adId;
}

//判断系统的广告标示符是否可用
+ (NSString*)isCanUseIDFA:(NSDictionary *)dict {
    BOOL advertisingTrackingEnabled = [[ASIdentifierManager sharedManager] isAdvertisingTrackingEnabled];
    //NSLog(@"advertisingTrackingEnabled==============%d", advertisingTrackingEnabled);
    NSString *isCanUse = @"YES";
    if (advertisingTrackingEnabled) {
        isCanUse = @"YES";
    } else {
         isCanUse = @"NO";
    }
    return isCanUse;
}

//获取模拟的广告标示符
+ (NSString*)getSimulateIDFA:(NSDictionary *)dict {
    NSString *adId = [SimulateIDFA createSimulateIDFA];
    return adId;
}

//获取应用包名
+ (NSString*)getBundleID:(NSDictionary *)dict{
    return [[NSBundle mainBundle]bundleIdentifier];
}

//是否包含表情
+ (NSString*)stringContainsEmoji:(NSDictionary *)dict {
    NSString *string = [dict objectForKey:@"msg"];
    
    __block NSString *returnValue = @"NO";
    
    [string enumerateSubstringsInRange:NSMakeRange(0, [string length]) options:NSStringEnumerationByComposedCharacterSequences usingBlock:^(NSString *substring, NSRange substringRange, NSRange enclosingRange, BOOL *stop) {
        
        const unichar hs = [substring characterAtIndex:0];
//        NSLog(@"stringContainsEmoji==============%@", substring);
//        NSLog(@"stringContainsEmoji==============%lu", (unsigned long)substring.length);
//        NSLog(@"stringContainsEmoji======= hs =======%C", hs);
//        NSLog(@"stringContainsEmoji======= hs 0x=======%x", hs);
        if (substring.length > 1) {
            returnValue = @"YES";
        }
        
//        if (0xd800 <= hs && hs <= 0xdbff) {
//            if (substring.length > 1) {
//                const unichar ls = [substring characterAtIndex:1];
//                const int uc = ((hs - 0xd800) * 0x400) + (ls - 0xdc00) + 0x10000;
//                if (0x1d000 <= uc && uc <= 0x1f77f) {
//                    returnValue = @"YES";
//                }
//            }
//        } else if (substring.length > 1) {
//            const unichar ls = [substring characterAtIndex:1];
//            NSLog(@"stringContainsEmoji====== ls ========%C", ls);
//            NSLog(@"stringContainsEmoji====== ls 0x========%x", ls);
//            if (ls == 0x20e3 || ls == 0xfe0f) {
//                returnValue = @"YES";
//            }
//        } else {
            if (0x2100 <= hs && hs <= 0x27ff) {
                returnValue = @"YES";
            } else if (0x2B05 <= hs && hs <= 0x2b07) {
                returnValue = @"YES";
            } else if (0x2934 <= hs && hs <= 0x2935) {
                returnValue = @"YES";
            } else if (0x3297 <= hs && hs <= 0x3299) {
                returnValue = @"YES";
            } else if (hs == 0xa9 || hs == 0xae || hs == 0x303d || hs == 0x3030 || hs == 0x2b55 || hs == 0x2b1c || hs == 0x2b1b || hs == 0x2b50) {
                returnValue = @"YES";
            }
//        }
    }];
    
    return returnValue;
}

// 保存lua回调函数id
+ (void)saveLuaFunctionId:(NSDictionary *)dict
{
    int callBackFunction = [[dict objectForKey:@"apns_callback"] intValue];

    [[NSUserDefaults standardUserDefaults] setObject:[NSString stringWithFormat:@"%d", callBackFunction] forKey:@"apns_callback"];
    [[NSUserDefaults standardUserDefaults] synchronize];
}

// 移除lua回调函数id
+ (void)removeLuaFunctionIdByKey:(NSString *)key {
    [[NSUserDefaults standardUserDefaults] removeObjectForKey:key];
}

+ (void)archiveAPNSData:(NSDictionary *)userInfo withFilePath:(NSString *)path {
    // 固化推送消息数据
    
    BOOL flag = [NSKeyedArchiver archiveRootObject:userInfo toFile:path];

    if (flag) {
        NSLog(@"success");
    }
}

+ (id)unarchiveAPNSDatawithFilePath:(NSString *)path {
    return [NSKeyedUnarchiver unarchiveObjectWithFile:path];
}

+ (void)handleAPNSData:(NSDictionary *)dict {
    NSDictionary *userInfo = [AppController getDictAPNS];
    for (id key in userInfo) {
        if ([key isEqual: @"app"]) {
            // 解析json，封装lua数据
            CCLuaValueDict dictParams;
            
            for (id key in [[userInfo objectForKey:@"app"] objectForKey:@"params"]) {
                dictParams[[key UTF8String]] = CCLuaValue::stringValue([[[[userInfo objectForKey:@"app"] objectForKey:@"params"] objectForKey:key] UTF8String]);
            }
            
            // 调用lua函数
            int callBackFunction = [[dict objectForKey:@"apns_callback"] intValue];
            
            // 1. 将引用 ID 对应的 Lua function 放入 Lua stack
            CCLuaObjcBridge::pushLuaFunctionById(callBackFunction);
            
            // 2. 将需要传递给 Lua function 的参数放入 Lua stack
            CCLuaObjcBridge::getStack()->pushCCLuaValueDict(dictParams);
            
            // 3. 执行 Lua function
            CCLuaObjcBridge::getStack()->executeFunction(1);
            
            // 4. 不释放引用 ID 注释掉下方代码
            //            CCLuaObjcBridge::releaseLuaFunctionById((int)callBackFunction);
        }
        
//        NSLog(@"key: %@, value: %@", key, [userInfo objectForKey:key]);
    }
    [Helper clearAPNSData:nil];
}

+ (void)clearAPNSData:(NSDictionary *)dict {
    [AppController clearAPNSData];
}

//获取系统版本号
+ (NSString*)getSystemVersion:(NSDictionary *)dict {
    NSString *systemVersion = [NSString stringWithFormat:@"%f",[[[UIDevice currentDevice] systemVersion] floatValue]];
    return systemVersion;
}

//获取本机名字
+ (NSString*)getDeviceName:(NSDictionary *)dict {
    NSString *devicename = [[UIDevice currentDevice] name];
    
    return devicename;
}

//打开用户评价  在ios版本7.0进行接口改变  appid 正式 1164793382  测试 1027258013
+ (NSString*) openUserReview:(NSDictionary *)dict{
    NSString *systemVersion = [NSString stringWithFormat:@"%f",[[[UIDevice currentDevice] systemVersion] floatValue]];
    NSLog(@"systemVersion ＝ %@",systemVersion);
    //是否是7.0以上的版本
    if ([systemVersion compare:@"7.0" options:NSNumericSearch] ==NSOrderedDescending)
    {
        NSString *url = [NSString stringWithFormat:@"http://itunes.apple.com/WebObjects/MZStore.woa/wa/viewContentsUserReviews?id=1164793382&pageNumber=0&sortOrdering=2&type=Purple+Software&mt=8"];
        NSLog(@"go into > 7.0 跳转");
        [[UIApplication sharedApplication] openURL:[NSURL URLWithString:url]];

    }else{
         NSString *url = [NSString stringWithFormat:@"itms-apps://ax.itunes.apple.com/WebObjects/MZStore.woa/wa/viewContentsUserReviews?type=Purple+Software&id=%d",1164793382];//1164793382];
        NSLog(@"go into < 7.0 跳转");
        [[UIApplication sharedApplication] openURL:[NSURL URLWithString:url]];
        
    }
    return @"asd";
}

//获取当前是否是模拟器
+ (NSString*)isEmulator:(NSDictionary *)dict {
    NSString *sEmulator = @"NO";
#if TARGET_IPHONE_SIMULATOR//模拟器
    sEmulator = @"YES";
#elif TARGET_OS_IPHONE//真机
    sEmulator = @"NO";
#endif
    return sEmulator;
}

//开始ping地址
+ (void)startPing:(NSDictionary *)dict {
    NSString * ipAddr = [dict valueForKey:@"ipAddr"];
    int LuaPingCallBackFunction = [[dict objectForKey:@"pingCallback"] intValue];
    //NSLog(@"startPing ================ %@", ipAddr);
    //NSLog(@"LuaPingCallBackFunction ================ %d", LuaPingCallBackFunction);
    [SimplePingHelper ping:ipAddr luaCallback:LuaPingCallBackFunction target:self sel:@selector(pingResult:)];
}

//ping结果 ipAddr:ip地址 luaCallBack:lua回调
+ (void)pingResult:(NSDictionary *)dict {

    // 以下两行将任务排程到一个后台线程执行。dispatch_get_global_queue会取得一个系统分配的后台任务队列。
    dispatch_queue_t queue = dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0);
    dispatch_async(queue, ^{
        
        NSString * ipAddr = [dict valueForKey:@"ipAddr"];
        int luaCallBack = [[dict valueForKey:@"pingCallback"] intValue];
        int result = [[dict valueForKey:@"result"] intValue];
        //NSLog(@"ping结果 ==============ipAdrr== %@", ipAddr);
        //NSLog(@"ping结果 ==============luaCallBack== %d", luaCallBack);
        //NSLog(@"ping结果 ==============result== %d", result);
        // 现在它在后台线程上执行了。
        NSString *Result = @"YES";
        if (result == 0) {
            Result = @"NO";
        } else {
            Result = @"YES";
        }
        // 完成后，因为有UI操作，所以需要切换回主线程。一般原则：
        // 1. UI操作必须在主线程上完成。2. 耗时的同步网络、同步IO、运算等操作不要在主线程上跑，以避免阻塞
        // dispatch_get_main_queue()会返回关联到主线程的那个任务队列。
        dispatch_async(dispatch_get_main_queue(), ^{
            
            if (luaCallBack >= 0) {
                // 1. 将引用 ID 对应的 Lua function 放入 Lua stack
                CCLuaObjcBridge::pushLuaFunctionById(luaCallBack);
                
                // 2. 将需要传递给 Lua function 的参数放入 Lua stack
                
                CCLuaValueDict item;
                item["pingResult"] = CCLuaValue::stringValue(Result.UTF8String);
                item["ipAddr"] = CCLuaValue::stringValue(ipAddr.UTF8String);
                //useravatorInApp
                CCLuaObjcBridge::getStack()->pushCCLuaValueDict(item);
                
                // 3. 执行 Lua function
                CCLuaObjcBridge::getStack()->executeFunction(1);
                
                // 4. 释放引用 ID
                CCLuaObjcBridge::releaseLuaFunctionById(luaCallBack);
            }
            
        });
    });
    
}

//获取联网IP
+ (void)getNetWorkIP:(NSDictionary *)dict {
    
    NSString *url = [dict valueForKey:@"url"];
    
    int uploadIPCallBackFunction = [[dict objectForKey:@"ipCallback"] intValue];
    
    NSURL * URL = [NSURL URLWithString:url];
    
    // 以下两行将任务排程到一个后台线程执行。dispatch_get_global_queue会取得一个系统分配的后台任务队列。
    dispatch_queue_t queue = dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0);
    dispatch_async(queue, ^{
        // 现在它在后台线程上执行了。
        NSString *NetWorkIP = @"";
        NSURLRequest * request = [[NSURLRequest alloc]initWithURL:URL];
        
        NSURLResponse * response = nil;
        NSError * error = nil;
        NSData * data = [NSURLConnection sendSynchronousRequest:request returningResponse:&response error:&error];
        if (error) {
            NSLog(@"error: %@",[error localizedDescription]);
            NetWorkIP = @"error";
        }else{
            //NSLog(@"response : %@",response);
            //NSLog(@"backData : %@",[[NSString alloc]initWithData:data encoding:NSUTF8StringEncoding]);
            NetWorkIP = [[NSString alloc]initWithData:data encoding:NSUTF8StringEncoding];
        }
        // 完成后，因为有UI操作，所以需要切换回主线程。一般原则：
        // 1. UI操作必须在主线程上完成。2. 耗时的同步网络、同步IO、运算等操作不要在主线程上跑，以避免阻塞
        // dispatch_get_main_queue()会返回关联到主线程的那个任务队列。
        dispatch_async(dispatch_get_main_queue(), ^{
            if (uploadIPCallBackFunction >= 0) {
                // 1. 将引用 ID 对应的 Lua function 放入 Lua stack
                CCLuaObjcBridge::pushLuaFunctionById(uploadIPCallBackFunction);
                
                // 2. 将需要传递给 Lua function 的参数放入 Lua stack
                CCLuaValueDict item;
                item["NetWorkIP"] = CCLuaValue::stringValue(NetWorkIP.UTF8String);
                //useravatorInApp
                CCLuaObjcBridge::getStack()->pushCCLuaValueDict(item);
                
                // 3. 执行 Lua function
                CCLuaObjcBridge::getStack()->executeFunction(1);
                
                // 4. 释放引用 ID
                CCLuaObjcBridge::releaseLuaFunctionById(uploadIPCallBackFunction);
            }
        });
    });
}

+ (BOOL)addSkipBackupAttributeToItemAtPath:(NSString *) filePathString
{
    NSURL* URL= [NSURL fileURLWithPath: filePathString];
    assert([[NSFileManager defaultManager] fileExistsAtPath: [URL path]]);
    
    NSError *error = nil;
    BOOL success = [URL setResourceValue: [NSNumber numberWithBool: YES]
                                  forKey: NSURLIsExcludedFromBackupKey error: &error];
    if(!success){
        NSLog(@"Error excluding %@ from backup %@", [URL lastPathComponent], error);
    }else{
        NSLog(@"preventing files from being backed up");
    }
    return success;
}

//获取应用缓存文件夹路径
+(NSString *)getCachesDirectoryPath:(NSDictionary *)dict {
    NSString * fileName = [dict valueForKey:@"fileName"];
    NSArray *paths = NSSearchPathForDirectoriesInDomains(NSCachesDirectory, NSUserDomainMask, YES);
    NSString *path = [[paths objectAtIndex:0] stringByAppendingPathComponent:fileName];
    
    NSFileManager* fileMgr = [NSFileManager defaultManager];
    if (![fileMgr fileExistsAtPath:path]){
        [fileMgr createDirectoryAtPath:path withIntermediateDirectories:YES attributes:nil error:nil];
    }
    return path;
}

//获取应用关键(本地)文件夹路径
+(NSString *)getDocumentDirectoryPath:(NSDictionary *)dict {
    NSString * fileName = [dict valueForKey:@"fileName"];
    NSString *path = Cachespath(fileName);
    NSFileManager *fileManager = [NSFileManager defaultManager];
    if (![fileManager fileExistsAtPath:path]){
        [fileManager createDirectoryAtPath:path withIntermediateDirectories:YES attributes:nil error:nil];
        [self addSkipBackupAttributeToItemAtPath:path];
    }
    return path;
}

//将字符串中的表情符替换为指定字符
+ (NSString*)replaceEmojiToStr:(NSDictionary *)dict {
    NSString *string = [dict objectForKey:@"oriText"];
    NSString *replaceStr = [dict objectForKey:@"replaceText"];
    NSMutableString *repText = [NSMutableString string];
    [string enumerateSubstringsInRange:NSMakeRange(0, [string length]) options:NSStringEnumerationByComposedCharacterSequences usingBlock:^(NSString *substring, NSRange substringRange, NSRange enclosingRange, BOOL *stop) {
        const unichar hs = [substring characterAtIndex:0];
        
        if (substring.length > 1) {
            substring = replaceStr;
        }
        if (0x2100 <= hs && hs <= 0x27ff) {
            substring = replaceStr;
        } else if (0x2B05 <= hs && hs <= 0x2b07) {
            substring = replaceStr;
        } else if (0x2934 <= hs && hs <= 0x2935) {
            substring = replaceStr;
        } else if (0x3297 <= hs && hs <= 0x3299) {
            substring = replaceStr;
        } else if (hs == 0xa9 || hs == 0xae || hs == 0x303d || hs == 0x3030 || hs == 0x2b55 || hs == 0x2b1c || hs == 0x2b1b || hs == 0x2b50) {
            substring = replaceStr;
        }
        [repText appendString:substring];
    }];
    
    return repText;
}

//获取剪切板内容
+ (NSString*) getClipboard {
    UIPasteboard *pasteboard = [UIPasteboard generalPasteboard];
    NSString *clipBoardText = pasteboard.string;
    return clipBoardText;
}

//设置剪切板内容
+ (void)setClipboard:(NSDictionary *)dict {
    NSString *clipBoardText = [dict objectForKey:@"clipBoardContent"];
    UIPasteboard *pasteboard = [UIPasteboard generalPasteboard];
    pasteboard.string = clipBoardText;
}

@end
