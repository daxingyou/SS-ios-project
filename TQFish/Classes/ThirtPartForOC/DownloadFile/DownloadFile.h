
#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@interface DownloadFile : NSObject

@property(nonatomic,retain) NSMutableData *fileData;//文件数据
@property(nonatomic,assign) long long fileLength;//文件总大小
@property(nonatomic,retain) NSString *filePath;//文件存储目录
@property(nonatomic,retain) NSString *urlString;//文件下载地址
@property(nonatomic,retain) NSURLConnection * connection;//网络连接对象
@property(nonatomic,assign) int luaCallBackFunction;//下载进度回调lua
@property(nonatomic,retain) NSString *fileName;//下载文件名

//下载文件
+ (NSDictionary *) startDownloadFile:(NSDictionary *)dict;
//下载脚本数据
+ (void) downloadFileData:(NSString *)urlString downloadPath:(NSString *)path luaCallBackFunction:(int)callback fileName:(NSString *)name;

@end
