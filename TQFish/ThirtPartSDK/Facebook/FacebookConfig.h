#import <Foundation/Foundation.h>


@interface FacebookConfig : NSObject {
    
}

+ (void)facebookLogout:(NSDictionary *)dict;
+ (void)facebookLogin:(NSDictionary *)dict;
+ (int)facebookShare:(NSDictionary *)dict;

@end
