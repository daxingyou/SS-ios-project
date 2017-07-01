
#import <Foundation/Foundation.h>

@interface UserAvator : UIViewController 


+ (BOOL)picExists:(NSDictionary *)dict;
+ (void)downAvator:(NSDictionary *)dict;
//修改头像调用相册
+ (NSDictionary *) changeAvator:(NSDictionary *)dict;

+ (void)uploadImage:(NSDictionary *)dict;

@end
