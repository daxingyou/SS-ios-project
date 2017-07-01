//
//  Assistant.m
//  TqLord
//
//  Created by huang he on 12-11-12.
//  Copyright (c) 2012年 huang he. All rights reserved.
//


#import "Assistant.h"
//#import <Message/NetworkController.h>

//#import "network.h"
#include <sys/types.h>
#include <sys/sysctl.h>
#import <mach/mach_host.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <ifaddrs.h>
#include <sys/socket.h>
#include <net/if.h>
#include <net/if_dl.h>
#include <ifaddrs.h>
#include "Reachability.h"
#import <CoreTelephony/CTTelephonyNetworkInfo.h>
#import <CoreTelephony/CTCarrier.h>

@implementation Assistant

+(void)alertContent:(NSString*)content title:(NSString *)title{
    UIAlertView *alert = [[UIAlertView alloc] initWithTitle:title message:content delegate:nil cancelButtonTitle:@"确认" otherButtonTitles: nil];
    [alert show];
    //[alert release];
}
+ (NSDictionary *) macaddress:(NSDictionary *)dict
{
    int                    mib[6];
    size_t                len;
    char                *buf;
    unsigned char        *ptr;
    struct if_msghdr    *ifm;
    struct sockaddr_dl    *sdl;
    mib[0] = CTL_NET;
    mib[1] = AF_ROUTE;
    mib[2] = 0;
    mib[3] = AF_LINK;
    mib[4] = NET_RT_IFLIST;
    if ((mib[5] = if_nametoindex("en0")) == 0) {
        printf("Error: if_nametoindex error/n");
        return NULL;
    }
    if (sysctl(mib, 6, NULL, &len, NULL, 0) < 0) {
        printf("Error: sysctl, take 1/n");
        return NULL;
    }
    if ((buf = malloc(len)) == NULL) {
        printf("Could not allocate memory. error!/n");
        return NULL;
    }
    if (sysctl(mib, 6, buf, &len, NULL, 0) < 0) {
        printf("Error: sysctl, take 2");
        free(buf);
        return NULL;
    }
    ifm = (struct if_msghdr *)buf;
    sdl = (struct sockaddr_dl *)(ifm + 1);
    ptr = (unsigned char *)LLADDR(sdl);
    
    NSString *outstring = [NSString stringWithFormat:@"%02X:%02X:%02X:%02X:%02X:%02X", *ptr, *(ptr+1), *(ptr+2), *(ptr+3), *(ptr+4), *(ptr+5)];
    free(buf);
    
    //NSLog(@"%@ ===== outstring ====== ",outstring);
    
    return [NSDictionary dictionaryWithObjectsAndKeys:[outstring uppercaseString], @"macaddress",
            [NSNumber numberWithInt:1], @"error", nil];

}



//+ (NSString *) imei
//{
//  
//}


+(NSString *)getImagePath{
    NSArray *paths = NSSearchPathForDirectoriesInDomains(NSCachesDirectory, NSUserDomainMask, YES);
	NSString *path = [[paths objectAtIndex:0] stringByAppendingPathComponent:@"images"];
    
    NSFileManager* fileMgr = [NSFileManager defaultManager];
    if (![fileMgr fileExistsAtPath:path]){
		[fileMgr createDirectoryAtPath:path withIntermediateDirectories:YES attributes:nil error:nil];
    }
    return path;
}

+(UIImage *)getImageWithURL:(NSString *)thePath{
    
   
	NSString *path = [self getImagePath];
    NSString *str = [[thePath componentsSeparatedByString:@"/"] lastObject];
    NSString *picPath = [path stringByAppendingPathComponent:[NSString stringWithFormat:@"%@",str]];
    UIImage *image = [UIImage imageWithContentsOfFile:picPath];
    return image;

}

+(void)saveImageWithURL:(NSString *)thePath data:(NSData *)data{
    
    NSString *path = [self getImagePath];
    NSString *str = [[thePath componentsSeparatedByString:@"/"] lastObject];
    NSString *picPath = [path stringByAppendingPathComponent:[NSString stringWithFormat:@"%@",str]];
    [data writeToFile:picPath atomically:YES];
    
    
}

+(UIView *)getNumImageWith:(long long)num width:(float)width height:(float)height{
    
    UIView *view = [[[UIView alloc] init] autorelease];
    view.backgroundColor = [UIColor clearColor];
    view.contentMode = UIViewContentModeScaleToFill;
    
    long long theNum = num;
    NSMutableArray *arr = [[NSMutableArray new] autorelease];
    if(num >0){
        while(theNum){
            UIImage *image = [UIImage imageNamed:[NSString stringWithFormat:@"jin_%lld.png",theNum%10]];
            UIImageView *imageView = [[[UIImageView alloc] initWithImage:image] autorelease];
            imageView.contentMode = UIViewContentModeScaleToFill;
            [arr insertObject:imageView atIndex:0];
            theNum = theNum/10;
            
        }
        
        UIImage *image = [UIImage imageNamed:[NSString stringWithFormat:@"jin_%d.png",10]];
        UIImageView *imageView = [[[UIImageView alloc] initWithImage:image] autorelease];
        imageView.contentMode = UIViewContentModeScaleToFill;
        [arr insertObject:imageView atIndex:0];
        
        
        for (int i = 0; i<[arr count]; i++) {
            UIImageView *imageView = [arr objectAtIndex:i];
            imageView.frame = CGRectMake(width*i,0,width,height);
            [view addSubview:imageView];
        }
        view.frame = CGRectMake(0,0,[arr count] * width,height);
    
    }
    else{
        if(theNum == 0){
            UIImage *image = [UIImage imageNamed:[NSString stringWithFormat:@"hui_0.png"]];
            UIImageView *imageView = [[[UIImageView alloc] initWithImage:image] autorelease];
            imageView.contentMode = UIViewContentModeScaleToFill;
            [arr insertObject:imageView atIndex:0];
        
        }
        else{
            while(theNum){
                
                UIImage *image = [UIImage imageNamed:[NSString stringWithFormat:@"hui_%lld.png",theNum%10*-1]];
                UIImageView *imageView = [[[UIImageView alloc] initWithImage:image] autorelease];
                imageView.contentMode = UIViewContentModeScaleToFill;
                [arr insertObject:imageView atIndex:0];
                theNum = theNum/10;
                
            }
        }
        
        
        UIImage *image = [UIImage imageNamed:[NSString stringWithFormat:@"hui_%d.png",11]];
        UIImageView *imageView = [[[UIImageView alloc] initWithImage:image] autorelease];
        imageView.contentMode = UIViewContentModeScaleToFill;
        [arr insertObject:imageView atIndex:0];
        
        
        
        for (int i = 0; i<[arr count]; i++) {
            UIImageView *imageView = [arr objectAtIndex:i];
            imageView.frame = CGRectMake(width*i,0,width,height);
            [view addSubview:imageView];
        }
        
        view.frame = CGRectMake(0,0,[arr count] * width,height);
    
    }
    
    for (UIView *cur in view.subviews) {
        cur.autoresizingMask = UIViewAutoresizingFlexibleLeftMargin|UIViewAutoresizingFlexibleWidth|UIViewAutoresizingFlexibleRightMargin|UIViewAutoresizingFlexibleTopMargin|UIViewAutoresizingFlexibleHeight |UIViewAutoresizingFlexibleBottomMargin;
    }
    
    return view;

}

+(UIView *)getJinNumImageWith:(long long)num width:(float)width height:(float)height{
    UIView *view = [[[UIView alloc] init] autorelease];
    view.backgroundColor = [UIColor clearColor];
    view.contentMode = UIViewContentModeScaleToFill;
    
    long long theNum = num;
    NSMutableArray *arr = [[NSMutableArray new] autorelease];
    if(num >=0){
        while(theNum){
            UIImage *image = [UIImage imageNamed:[NSString stringWithFormat:@"jin_%lld.png",theNum%10]];
            UIImageView *imageView = [[[UIImageView alloc] initWithImage:image] autorelease];
            imageView.contentMode = UIViewContentModeScaleToFill;
            [arr insertObject:imageView atIndex:0];
            theNum = theNum/10;
            
        }
        
        for (int i = 0; i<[arr count]; i++) {
            UIImageView *imageView = [arr objectAtIndex:i];
            imageView.frame = CGRectMake(width*i,0,width,height);
            [view addSubview:imageView];
        }
        view.frame = CGRectMake(0,0,[arr count] * width,height);
        
    }
    
    
    for (UIView *cur in view.subviews) {
        cur.autoresizingMask = UIViewAutoresizingFlexibleLeftMargin|UIViewAutoresizingFlexibleWidth|UIViewAutoresizingFlexibleRightMargin|UIViewAutoresizingFlexibleTopMargin|UIViewAutoresizingFlexibleHeight |UIViewAutoresizingFlexibleBottomMargin;
    }
    
    return view;

}

+(UIView *)redNumImageWith:(long long)num width:(float)width height:(float)height{
    UIView *view = [[[UIView alloc] init] autorelease];
    view.backgroundColor = [UIColor clearColor];
    view.contentMode = UIViewContentModeScaleToFill;
    
    long long theNum = num;
    NSMutableArray *arr = [[NSMutableArray new] autorelease];
    if(num >=0){
        while(theNum){
            UIImage *image = [UIImage imageNamed:[NSString stringWithFormat:@"%lld@2x.png",theNum%10]];
            UIImageView *imageView = [[[UIImageView alloc] initWithImage:image] autorelease];
            imageView.contentMode = UIViewContentModeScaleToFill;
            [arr insertObject:imageView atIndex:0];
            theNum = theNum/10;
            
        }
        
        for (int i = 0; i<[arr count]; i++) {
            UIImageView *imageView = [arr objectAtIndex:i];
            imageView.frame = CGRectMake(width*i,0,width,height);
            [view addSubview:imageView];
        }
        view.frame = CGRectMake(0,0,[arr count] * width,height);
        
    }
    
    
    for (UIView *cur in view.subviews) {
        cur.autoresizingMask = UIViewAutoresizingFlexibleLeftMargin|UIViewAutoresizingFlexibleWidth|UIViewAutoresizingFlexibleRightMargin|UIViewAutoresizingFlexibleTopMargin|UIViewAutoresizingFlexibleHeight |UIViewAutoresizingFlexibleBottomMargin;
    }
    
    return view;
}



+(UIView *)getTimesImageWith:(long long)num{
    UIView *view = [[[UIView alloc] init] autorelease];
    view.backgroundColor = [UIColor clearColor];
    view.contentMode = UIViewContentModeScaleToFill;
//    view.autoresizingMask = UIViewAutoresizingFlexibleWidth | UIViewAutoresizingFlexibleHeight;
    
    long long theNum = num;
    
    UIImageView *imageView = [[[UIImageView alloc] initWithImage:[UIImage imageNamed:@"wenzi_jiesuan_9.png"]] autorelease];
    
    view.frame = imageView.frame;
    [view addSubview:imageView];
    
    UILabel *lable = [[[UILabel alloc] init] autorelease];
    lable.backgroundColor = [UIColor clearColor];
    lable.textColor = [UIColor whiteColor];
    lable.font = [UIFont fontWithName:@"Thonburi" size:12];
    lable.contentMode = UIViewContentModeScaleToFill;
    lable.frame = CGRectMake(24, 0, 30, 15);
    
//    lable.font = [UIFont boldSystemFontOfSize:12];
    lable.textColor = [UIColor colorWithRed:153/255.0 green:254/255.0 blue:28/255.0 alpha:1.0];
    lable.textAlignment = NSTextAlignmentCenter;
    lable.text = [NSString stringWithFormat:@"%lld",theNum];
    [view addSubview:lable];
    

    for (UIView *cur in view.subviews) {
        cur.autoresizingMask = UIViewAutoresizingFlexibleLeftMargin|UIViewAutoresizingFlexibleWidth|UIViewAutoresizingFlexibleRightMargin|UIViewAutoresizingFlexibleTopMargin|UIViewAutoresizingFlexibleHeight |UIViewAutoresizingFlexibleBottomMargin;
    }
    return view;

}

+(UIView *)getStarImageWithCurrentStar:(int)currentStar taskStar:(int)taskStar{
    
    UIView *view = [[[UIView alloc] init] autorelease];
    view.backgroundColor = [UIColor clearColor];
    for (int i = 0; i< taskStar; i++) {
        UIImageView *imageView = [[[UIImageView alloc] initWithImage:[UIImage imageNamed:@"dateTask_2.png"]] autorelease];
        imageView.contentMode = UIViewContentModeScaleToFill;
        imageView.frame = CGRectMake(i*22, 0, 20, 18);
        [view addSubview:imageView];
    }
    
    if(currentStar > taskStar){
        int count = currentStar -taskStar;
        for (int i = 0; i< count; i++) {
            UIImageView *imageView = [[[UIImageView alloc] initWithImage:[UIImage imageNamed:@"dateTask_3.png"]] autorelease];
            //imageView.backgroundColor = [UIColor redColor];
            imageView.contentMode = UIViewContentModeScaleToFill;
            imageView.frame = CGRectMake((i+[view.subviews count])*22, 0, 20, 18);
            [view addSubview:imageView];
        }
    }
    
    view.frame = CGRectMake(0, 2, [view.subviews count] * 22, 20);
    return view;
}

//移动1 联通2 电信3
+ (NSDictionary *)yunying:(NSDictionary *)dict{

    NSString *ret = [[NSString alloc]init];
    CTTelephonyNetworkInfo *info = [[CTTelephonyNetworkInfo alloc] init];
    CTCarrier *carrier = [info subscriberCellularProvider];
    if (carrier == nil) {
        ret = @"0";
    }
    NSString *code = [carrier mobileNetworkCode];
    if ([code isEqualToString:@""]) {
        ret = @"0";
    }
    if ([code isEqualToString:@"00"] || [code isEqualToString:@"02"] || [code isEqualToString:@"07"] || [code isEqualToString:@"08"]) {
        ret = @"1";
    }
    
    if ([code isEqualToString:@"01"]|| [code isEqualToString:@"06"] || [code isEqualToString:@"09"]) {
        ret = @"2";
    }
    
    if ([code isEqualToString:@"03"]|| [code isEqualToString:@"05"] || [code isEqualToString:@"11"]) {
        ret = @"3";;
    }
    
    return [NSDictionary dictionaryWithObjectsAndKeys:ret, @"yunying",
            [NSNumber numberWithInt:1], @"error", nil];
}

+(NSString *)uuid;
{
    CFUUIDRef uuid_ref = CFUUIDCreate(NULL);
    CFStringRef uuid_string_ref= CFUUIDCreateString(NULL, uuid_ref);
    
    CFRelease(uuid_ref);
    NSString *uuid = [NSString stringWithString:(NSString*)uuid_string_ref];
    
    CFRelease(uuid_string_ref);
    
    
    return uuid;
}

+ (NSString *)orderid{
    NSDate *date = [NSDate date];
    NSDateFormatter *dateFormatter1 = [[[NSDateFormatter alloc] init] autorelease];
    [dateFormatter1 setDateFormat:@"yyyyMMddHHmmss"];
    NSString *dateString = [dateFormatter1 stringFromDate:date];
    
    return dateString;
}

+ (NSArray *)orderList{
    NSArray *list =  [[NSUserDefaults standardUserDefaults] objectForKey:@"orderList"];
    if(list == nil){
        list = [NSArray array];
        [[NSUserDefaults standardUserDefaults] setObject:list forKey:@"orderList"];
    }
    
    return list;
}
+ (void)addOrder:(NSDictionary *) orderInfo{
    NSArray *list =  [[NSUserDefaults standardUserDefaults] objectForKey:@"orderList"];
    if(list == nil){
        list = [NSArray array];
       
    }
    NSMutableArray *arr = [[NSMutableArray new] autorelease];
    [arr addObjectsFromArray:list];
    [arr addObject:orderInfo];

     [[NSUserDefaults standardUserDefaults] setObject:arr forKey:@"orderList"];
}

+(void)removeOrder:(NSDictionary *) orderInfo{
    NSArray *list =  [[NSUserDefaults standardUserDefaults] objectForKey:@"orderList"];
    if(list == nil){
        list = [NSArray array];
        
    }
    NSMutableArray *arr = [[NSMutableArray new] autorelease];
    [arr addObjectsFromArray:list];
    [arr removeObject:orderInfo];
    [[NSUserDefaults standardUserDefaults] setObject:arr forKey:@"orderList"];

}




+(UIImage *)getSmallPicture:(UIImage *)theImage picSize:(int)picSize {
    if (picSize < 200) {
        picSize = 200;
    }
    
    CGSize targetSize = CGSizeMake(picSize, picSize);
    UIGraphicsBeginImageContext(targetSize); // this will crop
    CGRect thumbnailRect = CGRectZero;
    thumbnailRect.origin = CGPointZero;
    thumbnailRect.size.width= targetSize.width;
    thumbnailRect.size.height = targetSize.height;
    [theImage drawInRect:thumbnailRect];
    UIImage *newImage = UIGraphicsGetImageFromCurrentImageContext();
    if(newImage == nil)
        NSLog(@"could not scale image");
    //pop the context to get back to the default
    UIGraphicsEndImageContext();
    return newImage;
}

//获取版本号
+(NSDictionary *)getVersion:(NSDictionary *)dict
{
    NSDictionary *infoDictionary = [[NSBundle mainBundle] infoDictionary];
    CFShow(infoDictionary);
    // app版本
    NSString *app_Version = [infoDictionary objectForKey:@"CFBundleShortVersionString"];
    
    return [NSDictionary dictionaryWithObjectsAndKeys:app_Version, @"appversion",
            [NSNumber numberWithInt:1], @"error", nil];
}

//获取网络连接方式

+(NSDictionary *)getNetType:(NSDictionary *)dict
{
    UIApplication *app = [UIApplication sharedApplication];
    NSArray *subviews = [[[app valueForKey:@"statusBar"] valueForKey:@"foregroundView"] subviews];
    NSNumber *dataNetworkItemView = nil;
    
    for (id subview in subviews) {
        if([subview isKindOfClass:[NSClassFromString(@"UIStatusBarDataNetworkItemView") class]]) {
            dataNetworkItemView = subview;
            break;
        }
    }
    
    NSString *netType = @"0";
    NSNumber * num = [dataNetworkItemView valueForKey:@"dataNetworkType"];
    if (num == nil) {
        
        netType = @"0";
        
    }else{
        
        int n = [num intValue];
        if (n == 0) {
            netType = @"0";
        }else if (n == 1){
            netType = @"2";
        }else if (n == 2){
            netType = @"3";
        }else{
            netType = @"1";
        }
        
    }
    
    return [NSDictionary dictionaryWithObjectsAndKeys:netType, @"nettype",
            [NSNumber numberWithInt:1], @"error", nil];
}
@end
