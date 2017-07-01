#import <Foundation/Foundation.h>
#import "SimplePing.h"

@interface SimplePingHelper : NSObject <SimplePingDelegate>

+ (void)ping:(NSString*)address luaCallback:(int)luaCallback target:(id)target sel:(SEL)sel;

@end
