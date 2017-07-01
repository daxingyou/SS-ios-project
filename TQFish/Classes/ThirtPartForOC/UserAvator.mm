
#import "UserAvator.h"
#import "platform/ios/CCNativeIOS.h"
#include "takePhoto.h"
#include "Camera.h"
#include "Helper.h"

#import "CCLuaObjcBridge.h"
#import "ObjectiveCHelper.h"

@interface UserAvator() 

@end

@implementation UserAvator

+(NSString *)getImagePath{
    NSArray *paths = NSSearchPathForDirectoriesInDomains(NSCachesDirectory, NSUserDomainMask, YES);
	NSString *path = [[paths objectAtIndex:0] stringByAppendingPathComponent:@"images"];
    
    NSFileManager* fileMgr = [NSFileManager defaultManager];
    if (![fileMgr fileExistsAtPath:path]){
		[fileMgr createDirectoryAtPath:path withIntermediateDirectories:YES attributes:nil error:nil];
    }
    return path;
}

+ (BOOL)picExists:(NSDictionary *)dict
{
    NSString *thePath = [dict objectForKey:@"imgurl"];
    NSString *picPath  = @"";
    NSString *path = [self getImagePath];
    NSString *str = [[thePath componentsSeparatedByString:@"/"] lastObject];
    picPath = [path stringByAppendingPathComponent:[NSString stringWithFormat:@"%@",str]];
    if ([picPath hasSuffix:@".jpg"]) {
        
        if(strstr([thePath UTF8String], "http://photo.99sai.com/upload/"))
        {
            picPath = [picPath stringByAppendingString:@"!convert2png"];//本地缓存图片
            
        } else {
            picPath = [picPath stringByReplacingOccurrencesOfString:@".jpg" withString:@".png"];
            
        }
    }
    //创建路径
    NSFileManager *fileManager = [NSFileManager defaultManager];
    if (![fileManager fileExistsAtPath:picPath]) {
        return false;
    }else {
        return true;
    }
}


+(void)downAvator:(NSDictionary *)dict
{
    //使用GCD通知主线程执行
    dispatch_queue_t  Queue = dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0);
    dispatch_async(Queue, ^{
        NSString *thePath = [dict objectForKey:@"imgurl"];
        int callBackFunction = [[dict objectForKey:@"callBackFunctionVar"] intValue];
        int nResIDVal = [[dict objectForKey:@"nResIDVal"] intValue];
        BOOL isRoundPhoto = [[dict objectForKey:@"isRoundPhoto"] boolValue];
        NSString *nResIDValString = [NSString stringWithFormat:@"%d",nResIDVal];
        int nGameId = -1; // 默认值
        nGameId = [[dict objectForKey:@"gameId"] intValue];
        int nGlobalApp = [[dict objectForKey:@"globalApp"] intValue];
        
        int imageSizeWidth = 0;
        imageSizeWidth = [[dict objectForKey:@"imageSizeWidth"] intValue];
        int imageSizeHeight = 0;
        imageSizeHeight = [[dict objectForKey:@"imageSizeHeight"] intValue];
        BOOL isNeedCustomSize = false;
        if ([dict objectForKey:@"isNeedCustomSize"] != nil ){
            isNeedCustomSize = [[dict objectForKey:@"isNeedCustomSize"] boolValue];
        }

        NSString *picPath  = @"";
        NSData * DATA = nil;
        NSString *path = [self getImagePath];
        NSString *str = [[thePath componentsSeparatedByString:@"/"] lastObject];

        if (isRoundPhoto) {
            // 圆形头像路径
            NSString *roundDir = [path stringByAppendingPathComponent:[NSString stringWithFormat:@"%@", @"RoundPhoto"]];
            if (![[NSFileManager defaultManager] fileExistsAtPath:roundDir]){
                [[NSFileManager defaultManager] createDirectoryAtPath:roundDir withIntermediateDirectories:YES attributes:nil error:nil];
            }
            
            picPath = [roundDir stringByAppendingPathComponent:[NSString stringWithFormat:@"%@", str]];
        }else {
            // 非圆形头像路径
            picPath = [path stringByAppendingPathComponent:[NSString stringWithFormat:@"%@",str]];
        }

        if ([picPath hasSuffix:@".jpg"]) {//判断字符串结尾是不是“.jpg”
            
            if (nGlobalApp == 1) {
                //德州国际版处理
                thePath = [thePath stringByAppendingString:@"!convert2png"];
                picPath = [picPath stringByAppendingString:@"!convert2png"];//本地缓存图片
            }else{
                if(strstr([thePath UTF8String], "http://photo.99sai.com/upload/"))
                {
                    thePath = [thePath stringByAppendingString:@"!convert2png"];
                    picPath = [picPath stringByAppendingString:@"!convert2png"];//本地缓存图片
                    
                }else
                {
                    thePath = [thePath stringByReplacingOccurrencesOfString:@".jpg" withString:@".png"];
                    picPath = [picPath stringByReplacingOccurrencesOfString:@".jpg" withString:@".png"];
                    
                }
            }

        }
        //创建路径
        NSFileManager *fileManager = [NSFileManager defaultManager];
    
        
        //如果缓存照片不存在则请求
        if (![fileManager fileExistsAtPath:picPath]) {
            if(![@"" isEqualToString:thePath] && thePath != nil){
                NSURL * URL=[NSURL URLWithString:thePath];
                DATA = [[NSData alloc]initWithContentsOfURL:URL];
                
                if (isRoundPhoto) {
                    // 德州扑克
                    // 针对头像图片
                    // 则将图片裁切成圆形
                    UIImage *image = [UIImage imageWithData:DATA];
                    UIImage *circleImage = [Helper ellipseImage:image withInset:1.f withBorderWidth:0 withBorderColor:[UIColor clearColor]];
                    if (imageSizeWidth != 0 && imageSizeHeight != 0){
                        circleImage = [Helper imageWithImageSimple:circleImage scaledToSize:CGSizeMake(imageSizeWidth, imageSizeHeight)];  // 压缩图片
                    }
                    
                    [DATA release];
                    DATA = UIImagePNGRepresentation(circleImage);
                }
                
                //非圆形头像，需要处理自定义尺寸的头像
                if (isNeedCustomSize) {
                    UIImage *image = [UIImage imageWithData:DATA];
                    if (imageSizeWidth != 0 && imageSizeHeight != 0){
                        image = [Helper imageWithImageSimple:image scaledToSize:CGSizeMake(imageSizeWidth, imageSizeHeight)];
                    }
                    
                    [DATA release];
                    DATA = UIImagePNGRepresentation(image);
                }
            }
            [DATA writeToFile:picPath atomically:YES];
            
            if(DATA == nil){
                return ;
            }
        }
        //通知主线程更新界面
        dispatch_async(dispatch_get_main_queue(),
                       ^{
                           NSLock *lock = [[ObjectiveCHelper sharedObjectiveCHelper] getLock];
                           [lock lock];
                           
                           // 1. 将引用 ID 对应的 Lua function 放入 Lua stack
                           CCLuaObjcBridge::pushLuaFunctionById(callBackFunction);
                           
                           // 2. 将需要传递给 Lua function 的参数放入 Lua stack
                           
                           CCLuaValueDict item;
                           //useravatorInApp
                           item["useravatorInApp"] = CCLuaValue::stringValue(picPath.UTF8String);
                           item["id"] = CCLuaValue::stringValue(nResIDValString.UTF8String);
                           
                           CCLuaObjcBridge::getStack()->pushCCLuaValueDict(item);
                           
                           // 3. 执行 Lua function
                           CCLuaObjcBridge::getStack()->executeFunction(1);
                           
                           // 4. 释放引用 ID
                           CCLuaObjcBridge::releaseLuaFunctionById(callBackFunction);
                           
                           [lock unlock];
                       });
    });
}


+ (NSDictionary *) changeAvator:(NSDictionary *)dict
{
    [[ObjectiveCHelper sharedObjectiveCHelper] showAlbum];
    
    NSString *picSize = [NSString stringWithFormat:@"%ld", [[dict objectForKey:@"picSize"] integerValue]];
    NSString *mUrl = [dict objectForKey:@"mUrl"];
    NSString *userID = [NSString stringWithFormat:@"%ld", [[dict objectForKey:@"userID"] integerValue]];
    NSString *password = [dict objectForKey:@"password"];
    NSString *call = [dict objectForKey:@"call"];
   
    
    [[NSUserDefaults standardUserDefaults] setObject:picSize forKey:@"picSize"];
    [[NSUserDefaults standardUserDefaults] setObject:mUrl forKey:@"mUrl"];
    [[NSUserDefaults standardUserDefaults] setObject:userID forKey:@"userID"];
    [[NSUserDefaults standardUserDefaults] setObject:password forKey:@"password"];
    [[NSUserDefaults standardUserDefaults] setObject:call forKey:@"call"];
    [[NSUserDefaults standardUserDefaults] synchronize];
    
    return [NSDictionary dictionaryWithObjectsAndKeys:@"1", @"flag", [NSNumber numberWithInt:1], @"error", nil];
}

+ (void)uploadImage:(NSDictionary *)dict
{
    NSString *postUrl = [dict objectForKey:@"mUrl"];
    NSString *imageFullPath = [dict objectForKey:@"imageFullPath"];
    NSString *callback = [dict objectForKey:@"call"];
    unsigned int userID = [[dict objectForKey:@"userID"] unsignedIntValue];
    NSString *password = [dict objectForKey:@"password"];

    NSLog(@"postUrl = %@", postUrl);
    NSLog(@"imageFullPath = %@", imageFullPath);
    NSLog(@"callback = %@", callback);
    NSLog(@"userID = %d", userID);
    NSLog(@"password = %@", password);

    [[NSUserDefaults standardUserDefaults] setObject:postUrl forKey:@"mUrl"];
    [[NSUserDefaults standardUserDefaults] setObject:callback forKey:@"call"];
    [[NSUserDefaults standardUserDefaults] setInteger:userID forKey:@"userID"];
    [[NSUserDefaults standardUserDefaults] setObject:password forKey:@"password"];

    [[NSUserDefaults standardUserDefaults] synchronize];
    
    UIImage *image = [UIImage imageWithContentsOfFile:imageFullPath];
    [[ObjectiveCHelper sharedObjectiveCHelper] uploadPortraitWithASIHTTPRequest:image];
}

@end
