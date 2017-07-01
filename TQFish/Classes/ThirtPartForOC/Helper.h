
#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "ZYWebView.h"
#import <CommonCrypto/CommonCryptor.h>
#import "GTMBase64.h"

@interface Helper : NSObject

+ (int) openWebview:(NSDictionary *)dict;
+ (NSDictionary *) hideWebview:(NSDictionary *)dict;
+ (NSDictionary *) didHideWebview:(NSDictionary *)dict;
+ (NSDictionary *) didShowWebview:(NSDictionary *)dict;
+ (NSDictionary *) showLoadingView:(NSDictionary *)dict;
+ (NSDictionary *) hideLoadingView:(NSDictionary *)dict;


+ (NSDictionary *) openSendMessage:(NSDictionary *)dict;//打开发短信界面
//+ (NSDictionary *) sendJailMessage:(NSDictionary *)dict;//越狱手机直接发送短信

+ (NSDictionary *) openAlert:(NSDictionary *) dict;//弹出框
+ (NSDictionary *) openAlertInput:(NSDictionary *)dict;//弹出输入框
+ (NSDictionary *) openToast:(NSDictionary *)dict; // 弹出toast
    
+(const char *) encryptUseDES:(const char *)plainText key:(const char *)key;//加密
+(int) decryptUseDES:(NSDictionary*)cipherTextAndkey;//解密

+ (NSDictionary *) IAPorderID:(NSDictionary *)dict;//iap登陆
+ (NSDictionary *) iapzhifu:(NSDictionary *)dict;//iap支付

+ (void)openURL:(NSDictionary*)dict; //打开一个url

+ (int) returnVersion:(NSDictionary *)dict;//返回版本号
+ (NSDictionary *) itunesUpdate:(NSDictionary *)dict;//appstiore升级

// 本地推送
+ (BOOL) scheduleLocalNotification:(NSDictionary *)dict;
+ (void) cancelNotification:(NSDictionary *)dict;

// 设置执行震动
+ (void) doVibrate;

// Device
+ (void) getDeviceBatteryLevel:(NSDictionary *)dict;

//按形状切割图像
+ (UIImage *) ellipseImage:(UIImage *)image withInset:(CGFloat)inset withBorderWidth:(CGFloat)width withBorderColor:(UIColor*)color;
+ (UIImage *) imageWithImageSimple:(UIImage*)image scaledToSize:(CGSize)newSize;

//跳转到推广的网页
+(void) openSafariURL:(NSDictionary *)dict;
//跳转到appstore评价
+ (void) appPingjia:(NSDictionary*)dict;
//获取时间戳
+ (NSString*) getTimeStamp;
//获取设备型号
+ (NSString*) getCurrentDeviceModel:(NSDictionary *)dict;

//获取系统的广告标示符
+ (NSString*) getIDFA:(NSDictionary *)dict;

//判断系统的广告标示符是否可用
+ (NSString*)isCanUseIDFA:(NSDictionary *)dict;

//获取模拟的广告标示符
+ (NSString*)getSimulateIDFA:(NSDictionary *)dict;

//是否包含表情
+ (NSString*)stringContainsEmoji:(NSDictionary *)dict;

//获取应用包名
+ (NSString*)getBundleID:(NSDictionary *)dict;

//获取系统版本号
+ (NSString*) getSystemVersion:(NSDictionary *)dict;

//获取本机名字
+ (NSString*) getDeviceName:(NSDictionary *)dict;

//打开用户评价
+ (NSString*) openUserReview:(NSDictionary *)dict;

// 保存lua回调函数id
+ (void)saveLuaFunctionId:(NSDictionary *)dict;

// 移除lua回调函数id
+ (void)removeLuaFunctionIdByKey:(NSString *)key;

+ (void)archiveAPNSData:(NSDictionary *)userInfo withFilePath:(NSString *)path;
+ (id)unarchiveAPNSDatawithFilePath:(NSString *)path;
+ (void)handleAPNSData:(NSDictionary *)dict;
+ (void)clearAPNSData:(NSDictionary *)dict;
//获取当前是否是模拟器
+ (NSString*)isEmulator:(NSDictionary *)dict;

//开始ping地址
+ (void)startPing:(NSDictionary *)dict;

//ping结果 ipAddr:ip地址 luaCallBack:lua回调
+ (void)pingResult:(NSDictionary *)dict;

//获取联网IP
+ (void)getNetWorkIP:(NSDictionary *)dict;

//获取应用缓存文件夹路径
+(NSString *)getCachesDirectoryPath:(NSDictionary *)dict;

//获取应用关键(本地)文件夹路径
+(NSString *)getDocumentDirectoryPath:(NSDictionary *)dict;

//设置剪切板内容
+ (void)setClipboard:(NSDictionary *)dict;
//获取剪切板内容
+ (NSString*) getClipboard;

@end
