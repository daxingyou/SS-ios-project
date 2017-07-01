#import <Foundation/Foundation.h>


@interface WechatConfig : NSObject {
    
}

+ (void) weixinPayResult:(NSDictionary*)dict; // 微信支付回调
+ (void) weixinShare:(NSDictionary*)dict; // 微信分享
+ (void) weixinSharePic:(NSDictionary*)dict; // 微信分享图片
+ (void) weixinLogin:(NSDictionary *)dict;// 微信登录
+ (NSString*)gethasWechatAPP:(NSDictionary *)dict; //获取是否安装微信APP

@end
