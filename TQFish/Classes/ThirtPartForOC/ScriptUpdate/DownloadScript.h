
#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@interface DownloadScript : NSObject

@property(nonatomic,retain) NSMutableData *fileData;//文件数据
@property(nonatomic,assign) long long fileLength;//文件总大小
@property(nonatomic,retain) NSString *filePath;//文件存储目录
@property(nonatomic,retain) NSString *urlString;//文件下载地址
@property(nonatomic,retain) NSURLConnection * connection;//网络连接对象
@property(nonatomic,assign) int luaCallBackFunction;//下载进度回调lua
@property(nonatomic,retain) NSString *scriptPackage;//下载脚本的包名(小游戏包名、主游戏包名是mainScript)

//下载脚本数据
+ (void) downloadScriptData:(NSString *)urlString downloadPath:(NSString *)path luaCallBackFunction:(int)callback scriptPackage:(NSString *)package;

@end
