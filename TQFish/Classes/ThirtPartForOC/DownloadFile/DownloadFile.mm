#import "DownloadFile.h"
#import "CCLuaObjcBridge.h"
#import "platform/ios/CCNativeIOS.h"

@implementation DownloadFile

- (void)dealloc {
    self.fileData = nil;
    self.filePath = nil;
    self.connection = nil;
    self.urlString = nil;
    self.luaCallBackFunction = -1;
    self.fileName = nil;
    [super dealloc];
}

//下载文件
+ (NSDictionary *) startDownloadFile:(NSDictionary *)dict {
    
    NSString * ScriptUpdateUrl = [dict valueForKey:@"fileUrl"];
    NSString *fileDir = [dict valueForKey:@"fileDir"];
    int CallBackFunction = [[dict objectForKey:@"callback"] intValue];
    NSString *name = [dict objectForKey:@"name"];
    
    [DownloadFile downloadFileData:ScriptUpdateUrl downloadPath:fileDir luaCallBackFunction:CallBackFunction fileName:name];
    return nil;
}

//下载需要更新的脚本
+ (void)downloadFileData:(NSString *)urlString downloadPath:(NSString *)path luaCallBackFunction:(int)callback fileName:(NSString *)name {
    DownloadFile *load = [[DownloadFile new] init];
    load.filePath = path;
    load.urlString = urlString;
    load.luaCallBackFunction = callback;
    load.fileName = name;
    
    //1.获取网络资源路径(URL)
    NSURL *url = [NSURL URLWithString:urlString];
    //2.根据URL创建请求
    NSMutableURLRequest *request = [[NSMutableURLRequest alloc] initWithURL:url cachePolicy:(NSURLRequestCachePolicy)1 timeoutInterval:60];
    //3.（与同步请求的区别点）发起请求，通过委托模式回调完成数据获取
    [request setValue:@"" forHTTPHeaderField:@"accept-encoding"];
    //网络连接，异步，通过代理实现
    [NSURLConnection connectionWithRequest:request delegate:load];
    //注意：在异步请求中使用了NSURLConnectionDataDelegate协议，委托对象为自己。其中有四个经常用到的方法，我们将获得的数据放在self.fileData中，其类型为 NSMutableData 。
    
}

//1.服务器响应回调的方法
- (void)connection:(NSURLConnection *)connection didReceiveResponse:(NSURLResponse *)response {
    NSLog(@"NSURLConnection didReceiveResponse 服务器响应 ========== ");
    
    self.connection = connection;
    self.fileData = [NSMutableData data];
    self.fileLength = [response expectedContentLength];
}

//2.服务返回数据,客户端开始接受(data为返回的数据)
- (void)connection:(NSURLConnection *)connection didReceiveData:(NSData *)data {
    //NSLog(@"NSURLConnection didReceiveData 服务器返回数据 =========");
    
    [self.fileData appendData:data];
    //self.fileData.length/(float)self.fileLength
    //NSLog(@"self.fileData.length ========== %lu",(unsigned long)self.fileData.length);
    //NSLog(@"self.fileLength ========== %lu",(unsigned long)self.fileLength);
    
    if (self.fileData.length != self.fileLength && self.luaCallBackFunction >= 0) {
        // 1. 将引用 ID 对应的 Lua function 放入 Lua stack
        CCLuaObjcBridge::pushLuaFunctionById(self.luaCallBackFunction);
        
        // 2. 将需要传递给 Lua function 的参数放入 Lua stack
        
        CCLuaValueDict item;
        NSString *downloadFileSize = [NSString stringWithFormat: @"%lu", (unsigned long)self.fileData.length];
        NSString *fileMaxSize = [NSString stringWithFormat: @"%lld", self.fileLength];
        item["downloadFileSize"] = CCLuaValue::stringValue(downloadFileSize.UTF8String);
        item["fileMaxSize"] = CCLuaValue::stringValue(fileMaxSize.UTF8String);
        item["fileName"] = CCLuaValue::stringValue(self.fileName.UTF8String);
        //useravatorInApp
        CCLuaObjcBridge::getStack()->pushCCLuaValueDict(item);
        
        // 3. 执行 Lua function
        CCLuaObjcBridge::getStack()->executeFunction(1);
        
        // 4. 释放引用 ID
        //CCLuaObjcBridge::releaseLuaFunctionById(self.luaCallBackFunction);
    }
    
}

//3.数据接受完毕回调的方法
- (void)connectionDidFinishLoading:(NSURLConnection *)connection {
    NSLog(@"NSURLConnection connectionDidFinishLoading 数据接受完毕 =========");
    
    //NSLog(@"self.fileData.length ========== %lu",(unsigned long)self.fileData.length);
    //NSLog(@"self.fileLength ========== %lu",(unsigned long)self.fileLength);
    NSLog(@"self.fileName ========= %@",self.fileName);
    NSString *zipfilePath = [_filePath stringByAppendingPathComponent:self.fileName];
    
    [self.fileData writeToFile:zipfilePath atomically:YES];
    
    if (self.luaCallBackFunction >= 0) {
        // 1. 将引用 ID 对应的 Lua function 放入 Lua stack
        CCLuaObjcBridge::pushLuaFunctionById(self.luaCallBackFunction);
        
        // 2. 将需要传递给 Lua function 的参数放入 Lua stack
        
        CCLuaValueDict item;
        NSString *downloadFileSize = [NSString stringWithFormat: @"%lu", (unsigned long)self.fileData.length];
        NSString *fileMaxSize = [NSString stringWithFormat: @"%lld", self.fileLength];
        item["downloadFileSize"] = CCLuaValue::stringValue(downloadFileSize.UTF8String);
        item["fileMaxSize"] = CCLuaValue::stringValue(fileMaxSize.UTF8String);
        item["fileName"] = CCLuaValue::stringValue(self.fileName.UTF8String);
        //useravatorInApp
        CCLuaObjcBridge::getStack()->pushCCLuaValueDict(item);
        
        // 3. 执行 Lua function
        CCLuaObjcBridge::getStack()->executeFunction(1);
        
        // 4. 释放引用 ID
        CCLuaObjcBridge::releaseLuaFunctionById(self.luaCallBackFunction);
    }
    
    self.fileData = nil;
    self.filePath = nil;
    self.connection = nil;
    self.urlString = nil;
    self.luaCallBackFunction = -1;
    self.fileName = nil;
}

//4.接受数据失败时候调用的方法
- (void)connection:(NSURLConnection *)connection didFailWithError:(NSError *)error {
    NSLog(@"NSURLConnection didFailWithError 数据接受失败 =========");
    NSLog(@"数据接受失败,失败原因:%@",[error localizedDescription]);
    
    if (self.luaCallBackFunction >= 0) {
        // 1. 将引用 ID 对应的 Lua function 放入 Lua stack
        CCLuaObjcBridge::pushLuaFunctionById(self.luaCallBackFunction);
        
        // 2. 将需要传递给 Lua function 的参数放入 Lua stack
        
        CCLuaValueDict item;
        item["downloadFileSize"] = CCLuaValue::stringValue(@"Error".UTF8String);
        item["fileMaxSize"] = CCLuaValue::stringValue(@"Error".UTF8String);
        item["fileName"] = CCLuaValue::stringValue(self.fileName.UTF8String);
        //useravatorInApp
        CCLuaObjcBridge::getStack()->pushCCLuaValueDict(item);
        
        // 3. 执行 Lua function
        CCLuaObjcBridge::getStack()->executeFunction(1);
        
        // 4. 释放引用 ID
        CCLuaObjcBridge::releaseLuaFunctionById(self.luaCallBackFunction);
    }
    
    self.fileData = nil;
    self.filePath = nil;
    self.connection = nil;
    self.urlString = nil;
    self.luaCallBackFunction = -1;
    self.fileName = nil;
}

@end
