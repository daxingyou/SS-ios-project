
#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#define Cachespath(name) [NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES)[0] stringByAppendingPathComponent:name]

//NSDocumentDirectory 关键数据
//NSCachesDirectory 缓存数据

//游戏文件存放目录
#define TQGameDir "LoadScript/"
//脚本下载存放目录
#define DownloadScriptDir TQGameDir@"downLoad/"
//游戏脚本存放目录
#define LoadScriptDir TQGameDir@"LuaScript/"
//游戏公共模块脚本存放目录
#define LoadMiniGameScriptDir LoadScriptDir@"script/loadModule/"
//主游戏包名
#define MainScriptPackage "cached_res"

@interface ScriptUpdate : NSObject

//检测脚本更新
//开始复制MD5文件
+ (void) startMD5FileListCopy;
//开始复制脚本文件
+ (void) startScriptCopy;
//判断lua升级文件
+ (void) logicLuaUpdateFile:(NSDictionary *)dict;
//更新脚本成功(解压完成后回调lua)
+ (void) updateLuaSuccess;
//更新Lua失败
+ (void) updateLuaError;
//添加游戏包外的搜索路径
+ (NSString*) addIOSSearchPath;
//删除指定目录的所有文件（可添加排除目录）
+ (NSString*) deleteExcludeScriptFile:(NSDictionary *)dict;
//复制脚本文件到指定路径
+ (BOOL) copyScriptFileToPath:(NSString *)srcPath toPath:(NSString *)dstPath;
//下载新脚本
+ (NSDictionary *) startDownloadScript:(NSDictionary *)dict;
//解压zip文件
+ (BOOL) uncompressZipFile:(const char *) zipPath toPath:(NSString *) path;
//解压脚本
+ (BOOL) unZipScript:(NSString *) zipFilePath;
//获取存放文件的路径
+ (NSDictionary *) getScriptDirectory:(NSDictionary *)dict;
//判断字符串包含
+(BOOL) getContainsString:(NSString *)currentString searchString:(NSString *)str;

@end
