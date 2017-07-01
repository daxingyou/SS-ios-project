//
//  Assistant.h
//  TqLord
//
//  Created by huang he on 12-11-12.
//  Copyright (c) 2012年 huang he. All rights reserved.
//11

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>


@interface Assistant : NSObject{

}

+(void)alertContent:(NSString*)content title:(NSString *)title; //警告
+ (NSDictionary *) macaddress:(NSDictionary *)dict;                                     //得到mac地址
//+(NSString *) imei;                                       //得到IMEI


+(UIImage *)getImageWithURL:(NSString *)thePath;                    //得到图片
+(void)saveImageWithURL:(NSString *)thePath data:(NSData *)data;    //储存图片

+(UIView *)getNumImageWith:(long long)num width:(float)width height:(float)height;//通过数字，得到数字图片 结算

+(UIView *)getJinNumImageWith:(long long)num width:(float)width height:(float)height;//通过数字，得到数字图片 金色
+(UIView *)redNumImageWith:(long long)num width:(float)width height:(float)height;//通过数字，得到数字图片 红色



+(UIView *)getTimesImageWith:(long long)num;//得到总倍数

+(UIView *)getStarImageWithCurrentStar:(int)currentStar taskStar:(int)taskStar;//得到星级图

+ (NSString *)currentNetType;
+ (BOOL)isNetConnectValid;

+ (NSDictionary *)yunying:(NSDictionary *)dict;//电话运营商

+ (NSString *)uuid;

+ (NSString *)orderid;


+ (NSArray *)orderList;
+ (void)addOrder:(NSDictionary *) orderInfo;
+ (void)removeOrder:(NSDictionary *) orderInfo;



+(UIImage *)getSmallPicture:(UIImage *)theImage picSize:(int)picSize;            //得到小图

+ (NSDictionary *)getVersion:(NSDictionary *)dict;//获取版本号
+ (NSDictionary *)getNetType:(NSDictionary *)dict; //获取网络连接方式
+ (BOOL)connectedToNetWork;
@end
