#import <Foundation/Foundation.h>


@interface UMTongjiIOS : NSObject {
    
}

+(void)umengTrack:(NSString*)UMAppKey ChannelId:(NSString*)UMChannelId;
+(void)Tongji:(const char*)key value:(const char*)value;

+ (NSDictionary *) YMTongjiList:(NSDictionary *)dict;//友盟统计事件

@end
