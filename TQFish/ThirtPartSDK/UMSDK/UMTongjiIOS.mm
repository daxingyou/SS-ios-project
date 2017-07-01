
#import "UMTongjiIOS.h"
#import "UMMobClick/MobClick.h"

@implementation UMTongjiIOS

+ (void)umengTrack:(NSString*)UMAppKey ChannelId:(NSString*)UMChannelId {
    // [MobClick setAppVersion:XcodeAppVersion]; //参数为NSString * 类型,自定义app版本信息，如果不设置，默认从CFBundleVersion里取
    [MobClick setLogEnabled:YES];//设置是否对日志信息进行加密, 默认NO(不加密).
    UMConfigInstance.appKey = UMAppKey;
    UMConfigInstance.channelId = UMChannelId;
    // UMConfigInstance.secret = @"secretstringaldfkals";
    // UMConfigInstance.eSType = E_UM_GAME;
    [MobClick startWithConfigure:UMConfigInstance];
}

+(void)Tongji:(const char *)key value:(const char *)value {
    //NSLog(@"%@",[@"3333" substringFromIndex:10000]);
    NSString *keyS = [NSString stringWithUTF8String:key];
    NSString *valueS = [NSString stringWithUTF8String:value];
    
    [MobClick event:keyS label:valueS];
    //NSLog(@"友盟事件统计%@====%@",keyS,valueS);
}

//友盟统计事件
+ (NSDictionary *) YMTongjiList:(NSDictionary *)dict {
    NSString *keys = [dict objectForKey:@"keyV"];
    NSString *values = [dict objectForKey:@"valueV"];
    
    const char* keyc =  [keys UTF8String];
    const char* valuec = [values UTF8String];
    
    [UMTongjiIOS Tongji:keyc value:valuec];
    
    return [NSDictionary dictionaryWithObjectsAndKeys:@"1", @"flag", [NSNumber numberWithInt:1], @"error", nil];
}
@end
