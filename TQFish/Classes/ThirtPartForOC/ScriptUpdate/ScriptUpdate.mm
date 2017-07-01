

#import "ScriptUpdate.h"
#import "CCLuaObjcBridge.h"
#import "platform/ios/CCNativeIOS.h"
#import "DownloadScript.h"
#import "sys/utsname.h"
#include "support/zip_support/unzip.h"
#import "PublicLuaBridge.h"

#define BUFFER_SIZE    8192
#define MAX_FILENAME   512

int LuaUpdateDoneCallBackFunction = -1;//解压回调方法

@implementation ScriptUpdate

//开始复制MD5文件
+ (void) startMD5FileListCopy {
    //判断是否有复制结束标识，没有则复制
    //如果脚本不存在则复制到目标路径
    if (PublicLuaBridge::getInstance()->productionModels) {
        bool isSuccess = false;
        NSLog(@"开始复制MD5文件==============");
        //
        NSString *NativeCommonFileMD5ListDirectory = Cachespath(@LoadScriptDir@"NativeCommonFileMD5List");
        NSString *NativeAllListMD5Path = Cachespath(@LoadScriptDir@"cached_res_AllListMD5.data");
        NSString *NativeFileMD5ListPath = Cachespath(@LoadScriptDir@"cached_res_FileMD5List.data");
        NSString *configFilePath = Cachespath(@LoadScriptDir@"scriptConfig.json");
        
        NSString *NativeCommonFileMD5ListPath = [[[NSBundle mainBundle] bundlePath] stringByAppendingPathComponent:@"cached_res/NativeCommonFileMD5List"];
        NSString *AllListMD5Path = [[[NSBundle mainBundle] bundlePath] stringByAppendingPathComponent:@"cached_res/cached_res_AllListMD5.data"];
        NSString *FileMD5ListPath = [[[NSBundle mainBundle] bundlePath] stringByAppendingPathComponent:@"cached_res/cached_res_FileMD5List.data"];
        NSString *luaConfigPath = [[[NSBundle mainBundle] bundlePath] stringByAppendingPathComponent:@"scriptConfig.json"];
        
        NSLog(@"luaFilePath ========== %@",NativeCommonFileMD5ListPath);
        NSLog(@"luaConfigPath ========== %@",luaConfigPath);
        isSuccess = [ScriptUpdate copyScriptFileToPath:NativeCommonFileMD5ListPath toPath:NativeCommonFileMD5ListDirectory];
        isSuccess = [ScriptUpdate copyScriptFileToPath:AllListMD5Path toPath:NativeAllListMD5Path];
        isSuccess = [ScriptUpdate copyScriptFileToPath:FileMD5ListPath toPath:NativeFileMD5ListPath];
        isSuccess = [ScriptUpdate copyScriptFileToPath:luaConfigPath toPath:configFilePath];
        
        if (isSuccess) {
            NSLog(@"复制MD5文件结束==============");
        } else {
            NSLog(@"复制MD5文件失败==============");
        }
        
    } else {
        //debug模式，不复制脚本
        NSLog(@"debug模式，不复制MD5文件=============");
    }
}

//开始复制脚本文件
+ (void) startScriptCopy {
    //判断是否有复制结束标识，没有则复制
    if (PublicLuaBridge::getInstance()->productionModels) {
        // 以下两行将任务排程到一个后台线程执行。dispatch_get_global_queue会取得一个系统分配的后台任务队列。
        dispatch_queue_t queue = dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0);
        dispatch_async(queue, ^{
            // 现在它在后台线程上执行了。
            bool isSuccess = false;
            NSLog(@"开始复制脚本==============");
            
            NSString *scriptDirectory = Cachespath(@LoadScriptDir);
            NSString *configDirectory = Cachespath(@LoadScriptDir@"scriptConfig.json");
            //如果脚本不存在则赋值到目标路径
            NSString *luaFilePath = [[[NSBundle mainBundle] bundlePath] stringByAppendingPathComponent:@"cached_res"];
            NSString *luaConfigPath = [[[NSBundle mainBundle] bundlePath] stringByAppendingPathComponent:@"scriptConfig.json"];
            
            NSLog(@"luaFilePath ========== %@",luaFilePath);
            NSLog(@"luaConfigPath ========== %@",luaConfigPath);
            isSuccess = [ScriptUpdate copyScriptFileToPath:luaFilePath toPath:scriptDirectory];
            isSuccess = [ScriptUpdate copyScriptFileToPath:luaConfigPath toPath:configDirectory];
            
            // 完成后，因为有UI操作，所以需要切换回主线程。一般原则：
            // 1. UI操作必须在主线程上完成。2. 耗时的同步网络、同步IO、运算等操作不要在主线程上跑，以避免阻塞
            // dispatch_get_main_queue()会返回关联到主线程的那个任务队列。
            dispatch_async(dispatch_get_main_queue(), ^{
                if (isSuccess) {
                    NSLog(@"复制脚本结束==============");
                } else {
                    NSLog(@"复制脚本失败==============");
                }
            });
        });
        
    } else {
        //debug模式，不复制脚本
        NSLog(@"debug模式，不复制脚本=============");
    }
}

//添加游戏包外的搜索路径
+ (NSString*) addIOSSearchPath {
    NSLog(@"添加游戏包外的搜索路径=============%s",[Cachespath(@LoadScriptDir) UTF8String]);
    std::vector<std::string> searchPaths = CCFileUtils::sharedFileUtils()->getSearchPaths();
    std::vector<std::string>::iterator iter = searchPaths.begin();
    searchPaths.insert(iter, [Cachespath(@TQGameDir) UTF8String]);
    CCFileUtils::sharedFileUtils()->setSearchPaths(searchPaths);
    return @"YES";
}

//删除指定目录的所有文件（可添加排除目录）
+(NSString*) deleteExcludeScriptFile:(NSDictionary *)dict {
    
    NSString *isCopySuccess = @"YES";
    
    NSLog(@"deleteExcludeScriptFile ========= 删除指定目录的所有文件开始=====");
    
    long startTime = [[NSDate date] timeIntervalSince1970]*1000;
    
    //指定要删除的目录
    NSString *deletePath = [dict objectForKey:@"deletePath"];
    NSLog(@"deletePath ========= %@",deletePath);
    //需要排除的目录
    NSString *ExcludeFile = [dict objectForKey:@"ExcludeFile"];
    //NSLog(@"ExcludeFile ========= %@",ExcludeFile);
    
    NSFileManager *fileManager = [NSFileManager defaultManager];
    
    if ([ExcludeFile isEqualToString:@""]) {
        //没有需要排除的文件
        if ([fileManager fileExistsAtPath:deletePath]) {
            //NSLog(@"存在文件 ====开始删除==== %@",deletePath);
            BOOL isRemoveDir = [fileManager removeItemAtPath:deletePath error:nil];
            if(!isRemoveDir){
                //NSLog(@"存在文件删除失败====");
                isCopySuccess = @"NO";
            }
            //NSLog(@"存在文件 ====结束删除==== %@",deletePath);
        }
        
        long endTime = [[NSDate date] timeIntervalSince1970]*1000;
        NSLog(@"deleteExcludeScriptFile ========= 删除指定目录的所有文件结束=====");
        
        NSLog(@"删除指定目录的所有文件消耗的时间 ===== %ld 毫秒",(endTime - startTime));
        return isCopySuccess;
    }
    
    NSArray *array = [fileManager subpathsOfDirectoryAtPath:deletePath  error:nil];
    
    for (NSString *subPath in array) {
        if ([fileManager fileExistsAtPath:[deletePath stringByAppendingPathComponent:subPath]]) {
            //文件存在
            NSString *nativeStr = [deletePath stringByAppendingPathComponent:subPath];
            
            BOOL isDir = FALSE;
            //判断本地文件是否是目录
            [fileManager fileExistsAtPath:nativeStr isDirectory:&isDir];
            if(isDir) {
                //是目录
                if (![ExcludeFile isEqualToString:@""] && [ScriptUpdate getContainsString:nativeStr searchString:ExcludeFile]) {
                    //NSLog(@"排除文件夹==== %@",nativeStr);
                    continue;
                }
                
                //NSLog(@"nativeStr ========= %@",nativeStr);
                BOOL isRemoveDir = [fileManager removeItemAtPath:nativeStr error:nil];
                if(!isRemoveDir){
                    //NSLog(@"存在文件删除失败====");
                    isCopySuccess = @"NO";
                    break;
                }
            } else {
                //是文件
                if (![ExcludeFile isEqualToString:@""] && [ScriptUpdate getContainsString:nativeStr searchString:ExcludeFile]) {
                    //NSLog(@"排除文件==== %@",nativeStr);
                    continue;
                }
                if (![[NSFileManager defaultManager] removeItemAtPath:nativeStr error:nil]){
                    //NSLog(@"Could not remove old files");
                    isCopySuccess = @"NO";
                    break;
                } else {
                    //NSLog(@"remove old files success");
                }
            }
        }
    }
    
    long endTime = [[NSDate date] timeIntervalSince1970]*1000;
    NSLog(@"deleteExcludeScriptFile ========= 删除指定目录的所有文件结束=====");
    
    NSLog(@"删除指定目录的所有文件消耗的时间 ===== %ld 毫秒",(endTime - startTime));
    
    return isCopySuccess;
}

//复制脚本文件到指定路径
+(BOOL) copyScriptFileToPath:(NSString *)srcPath toPath:(NSString *)dstPath {
    
    BOOL isCopySuccess = true;
    
    NSFileManager *fileManager = [NSFileManager defaultManager];
    //新版本要实现小游戏的动态加载，所以不再删除整个目录
//    if ([fileManager fileExistsAtPath:dstPath]) {
//        NSLog(@"存在文件 ====开始删除====");
//        BOOL isRemoveDir = [fileManager removeItemAtPath:dstPath error:error];
//        if(!isRemoveDir){
//            NSLog(@"存在文件删除失败====");
//            return false;
//        }
//        NSLog(@"存在文件 ====结束删除====");
//    }
    BOOL isSrcDir = FALSE;
    [fileManager fileExistsAtPath:srcPath isDirectory:&isSrcDir];
    if (!isSrcDir) {
        //要复制是单个文件
        BOOL isDirExist = [fileManager fileExistsAtPath:dstPath];//查看文件是否已经存在
        if (isDirExist) {
            //包外已经存在此文件，则需要删除
            //NSLog(@"文件已经存在====%@",dstPath);
            //removing file
            if (![[NSFileManager defaultManager] removeItemAtPath:dstPath error:nil]){
                //NSLog(@"Could not remove old files");
                isCopySuccess = false;
                return isCopySuccess;
            } else {
                //NSLog(@"remove old files success");
            }
        }
        //复制文件
        BOOL success = [fileManager copyItemAtPath:srcPath toPath:dstPath error:nil];
        if (success == YES){
            //NSLog(@"Copied === %@", dstPath);
        } else {
            isCopySuccess = false;
            //NSLog(@"Not Copied srcPath == %@", srcPath);
            //NSLog(@"Not Copied dstPath == %@", dstPath);
        }
        return isCopySuccess;
    }
    
    //要复制的是文件夹
    [fileManager createDirectoryAtPath:dstPath withIntermediateDirectories:YES attributes:nil error:nil];
    
    NSArray *array = [fileManager subpathsOfDirectoryAtPath:srcPath  error:nil];
    
    for (NSString *subPath in array) {
        if (![fileManager fileExistsAtPath:[srcPath stringByAppendingPathComponent:subPath]]) {
            //没有找到文件
            NSLog(@"Could not find files %@.", subPath);
            isCopySuccess = false;
            break;
        } else {
            
            NSString *nativeStr = [srcPath stringByAppendingPathComponent:subPath];
            NSString *tostr = [dstPath stringByAppendingPathComponent:subPath];
            
            BOOL isDir = FALSE;
            //判断本地文件是否是目录
            [fileManager fileExistsAtPath:nativeStr isDirectory:&isDir];
            if(isDir) {
                //是目录
                BOOL isDirExist = [fileManager fileExistsAtPath:tostr];//查看目录是否已经存在
                if (isDirExist) {
                    //包外已经存在此目录
                    //NSLog(@"已经存在的目录====%@",tostr);
                } else {
                    //包外没有此目录
                    BOOL bCreateDir = [fileManager createDirectoryAtPath:tostr withIntermediateDirectories:YES attributes:nil error:nil];
                    if (bCreateDir) {
                        //NSLog(@"成功创建目录====%@",tostr);
                    } else {
                        //NSLog(@"Create Directory Failed.====%@",tostr);
                        isCopySuccess = false;
                        break;
                    }
                }
            } else {
                //是文件
                BOOL isDirExist = [fileManager fileExistsAtPath:tostr];//查看文件是否已经存在
                if (isDirExist) {
                    //包外已经存在此文件，则需要删除
                    //NSLog(@"文件已经存在====%@",tostr);
                    //removing file
                    if (![[NSFileManager defaultManager] removeItemAtPath:tostr error:nil]){
                        //NSLog(@"Could not remove old files");
                        isCopySuccess = false;
                        break;
                    } else {
                        //NSLog(@"remove old files success");
                    }
                }else{
                    //包外不存在此文件，则不作处理
                    //NSLog(@"文件不不不存在====%@",tostr);
                }
                //复制文件
                BOOL success = [fileManager copyItemAtPath:nativeStr toPath:tostr error:nil];
                if (success == YES){
                    //NSLog(@"Copied === %@", tostr);
                } else {
                    isCopySuccess = false;
                    //NSLog(@"Not Copied %@", nativeStr);
                    break;
                }
            }
        }
    }
    
    return isCopySuccess;
}

//判断lua升级文件
+ (void) logicLuaUpdateFile:(NSDictionary *)dict {
    
    if (LuaUpdateDoneCallBackFunction > 0) {
        //解压进行中
        NSLog(@"logicLuaUpdateFile ====== 解压进行中");
        return;
    }
    
    LuaUpdateDoneCallBackFunction = [[dict objectForKey:@"updateDoneCallback"] intValue];
    NSString *zipFileName = [dict objectForKey:@"zipFileName"];
    NSLog(@"zipFileName ====== %@", zipFileName);
    
    NSFileManager *fileManager = [NSFileManager defaultManager];
    //检测脚本更新
    NSLog(@"检测脚本更新=============");
    NSString *zipFilePath = Cachespath([[@DownloadScriptDir stringByAppendingString:zipFileName]stringByAppendingString:@".zip"]);
    
    NSLog(@"zipFilePath ====== %@", zipFilePath);
    if ([fileManager fileExistsAtPath:zipFilePath]) {
        [ScriptUpdate unZipScript:zipFilePath];
    }
}


//更新Lua成功(解压完成后回调lua)
+ (void) updateLuaSuccess {
    
    //删除冗余文件
    //[Helper deleteNousefulFile];
    
    if (LuaUpdateDoneCallBackFunction >= 0) {
        // 1. 将引用 ID 对应的 Lua function 放入 Lua stack
        CCLuaObjcBridge::pushLuaFunctionById(LuaUpdateDoneCallBackFunction);
        
        // 2. 将需要传递给 Lua function 的参数放入 Lua stack
        
        CCLuaValueDict item;
        item["type"] = CCLuaValue::stringValue(@"Success".UTF8String);
        //item["zipFileName"] = CCLuaValue::stringValue(zipFileName.UTF8String);
        //useravatorInApp
        CCLuaObjcBridge::getStack()->pushCCLuaValueDict(item);
        
        // 3. 执行 Lua function
        CCLuaObjcBridge::getStack()->executeFunction(1);
        
        // 4. 释放引用 ID
        CCLuaObjcBridge::releaseLuaFunctionById(LuaUpdateDoneCallBackFunction);
        LuaUpdateDoneCallBackFunction = -1;
    }
}

//更新Lua失败
+ (void) updateLuaError {
    
    if (LuaUpdateDoneCallBackFunction >= 0) {
        // 1. 将引用 ID 对应的 Lua function 放入 Lua stack
        CCLuaObjcBridge::pushLuaFunctionById(LuaUpdateDoneCallBackFunction);
        
        // 2. 将需要传递给 Lua function 的参数放入 Lua stack
        
        CCLuaValueDict item;
        item["type"] = CCLuaValue::stringValue(@"Error".UTF8String);
        //item["zipFileName"] = CCLuaValue::stringValue(zipFileName.UTF8String);
        //useravatorInApp
        CCLuaObjcBridge::getStack()->pushCCLuaValueDict(item);
        
        // 3. 执行 Lua function
        CCLuaObjcBridge::getStack()->executeFunction(1);
        
        // 4. 释放引用 ID
        CCLuaObjcBridge::releaseLuaFunctionById(LuaUpdateDoneCallBackFunction);
        LuaUpdateDoneCallBackFunction = -1;
    }
}

//下载升级包
+ (NSDictionary *) startDownloadScript:(NSDictionary *)dict {

    NSString * ScriptUpdateUrl = [dict valueForKey:@"ScriptUpdateUrl"];
    NSString *downLoadDirectory = Cachespath(@DownloadScriptDir);
    int CallBackFunction = [[dict objectForKey:@"callback"] intValue];
    NSString *package = [dict objectForKey:@"package"];
    
    NSFileManager *fileManager = [NSFileManager defaultManager];
    [fileManager createDirectoryAtPath:downLoadDirectory withIntermediateDirectories:YES attributes:nil error:nil];
    [DownloadScript downloadScriptData:ScriptUpdateUrl downloadPath:downLoadDirectory luaCallBackFunction:CallBackFunction scriptPackage:package];
    return nil;
}

//解压zip
+ (BOOL) uncompressZipFile:(const char *) zipPath toPath:(NSString *) path {
    NSFileManager *fileManager = [NSFileManager defaultManager];
    // Open the zip file
    const char *outFileName = zipPath;
    unzFile zipfile = unzOpen(outFileName);
    if (! zipfile)
    {
        CCLOG("can not open downloaded zip file %s", outFileName);
        return false;
    }
    
    // Get info about the zip file
    unz_global_info global_info;
    if (unzGetGlobalInfo(zipfile, &global_info) != UNZ_OK)
    {
        CCLOG("can not read file global info of %s", outFileName);
        unzClose(zipfile);
        return false;
    }
    
    // Buffer to hold data read from the zip file
    char readBuffer[BUFFER_SIZE];
    
    CCLOG("start uncompressing");
    // Loop to extract all files.
    
    int i = 0;
    long len = global_info.number_entry;
//    int maxCallBackNum = 20;
//    int interval = 5;
//    
//    if (len > maxCallBackNum) {
//        interval = len / maxCallBackNum;
//    }
//    
//    if (interval < 5) {
//        interval = 5;
//    }
//    CCLOG("start uncompressing len == %ld", len);
//    CCLOG("start uncompressing interval == %d", interval);
    
    for (i = 0; i < len; ++i)
    {
        unz_file_info fileInfo;
        char fileName[MAX_FILENAME];
        if (unzGetCurrentFileInfo(zipfile,
                                  &fileInfo,
                                  fileName,
                                  MAX_FILENAME,
                                  NULL,
                                  0,
                                  NULL,
                                  0) != UNZ_OK)
        {
            CCLOG("can not read file info");
            unzClose(zipfile);
            return false;
        }
        
        NSString * fullPath = [path stringByAppendingPathComponent:[NSString stringWithUTF8String:fileName]];
        
        
        // Check if this entry is a directory or a file.
        const size_t filenameLength = strlen(fileName);
        if (fileName[filenameLength-1] == '/')
        {
            // Entry is a direcotry, so create it.
            // If the directory exists, it will failed scilently.
            
            
            if (![fileManager createDirectoryAtPath:fullPath withIntermediateDirectories:YES attributes:nil error:nil])
            {
                CCLOG("can not create directory %s", outFileName);
                unzClose(zipfile);
                //[progroessView removeFromSuperview];
                return false;
            }
        }
        else
        {
            // Entry is a file, so extract it.
            
            // Open current file.
            if (unzOpenCurrentFile(zipfile) != UNZ_OK)
            {
                CCLOG("can not open file %s", fileName);
                unzClose(zipfile);
                //[progroessView removeFromSuperview];
                return false;
            }
            
            // Create a file to store current file.
            
            [fileManager createDirectoryAtPath:[fullPath stringByDeletingLastPathComponent] withIntermediateDirectories:YES attributes:nil error:nil];
            FILE *out = fopen([fullPath UTF8String], "wb");
            if (! out)
            {
                CCLOG("can not open destination file %s", [fullPath UTF8String]);
                unzCloseCurrentFile(zipfile);
                unzClose(zipfile);
                //[progroessView removeFromSuperview];
                return false;
            }
            
            // Write current file content to destinate file.
            int error = UNZ_OK;
            do
            {
                error = unzReadCurrentFile(zipfile, readBuffer, BUFFER_SIZE);
                if (error < 0)
                {
                    CCLOG("can not read zip file %s, error code is %d", fileName, error);
                    unzCloseCurrentFile(zipfile);
                    unzClose(zipfile);
                    //[progroessView removeFromSuperview];
                    return false;
                }
                
                if (error > 0)
                {
                    fwrite(readBuffer, error, 1, out);
                }
            } while(error > 0);
            
            fclose(out);
        }
        
        unzCloseCurrentFile(zipfile);
        
        // Goto next entry listed in the zip file.
        if ((i+1) < global_info.number_entry)
        {
            if (unzGoToNextFile(zipfile) != UNZ_OK)
            {
                CCLOG("can not read next file");
                //[progroessView removeFromSuperview];
                unzClose(zipfile);
                return false;
            }
        }
    }
    CCLOG("end uncompressing");
    return YES;
}

//更新脚本
+ (BOOL) unZipScript:(NSString *)zipFilePath {
    
    NSLog(@"zipFilePath ====== %@", zipFilePath);
    const char *outFileName = [zipFilePath UTF8String];
    
    dispatch_queue_t queue = dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0);
    dispatch_async(queue, ^{
        
        bool isError = false;
        
        if ([ScriptUpdate getContainsString:zipFilePath searchString:@MainScriptPackage]) {
            //主游戏解压更新
            NSLog(@"unZipScript ============== 主游戏版本更新");
            if(![ScriptUpdate uncompressZipFile:outFileName toPath:Cachespath(@LoadScriptDir)]) {
                NSLog(@"解压失败 ===== %@", zipFilePath);
                isError = true;
            }
        } else {
            //小游戏解压更新
            NSLog(@"unZipScript ============== 小游戏版本更新");
            if(![ScriptUpdate uncompressZipFile:outFileName toPath:Cachespath(@LoadMiniGameScriptDir)]) {
                NSLog(@"解压失败 ===== %@", zipFilePath);
                isError = true;
            }
        }
        
        NSFileManager *fileManager = [NSFileManager defaultManager];
        if ([fileManager fileExistsAtPath:zipFilePath]) {
            BOOL isRemoveDir = [fileManager removeItemAtPath:zipFilePath error:nil];
            if(!isRemoveDir){
                isError = true;
            }
        }
        
        // 完成后，因为有UI操作，所以需要切换回主线程。一般原则：
        // 1. UI操作必须在主线程上完成。2. 耗时的同步网络、同步IO、运算等操作不要在主线程上跑，以避免阻塞
        // dispatch_get_main_queue()会返回关联到主线程的那个任务队列。
        dispatch_async(dispatch_get_main_queue(), ^{
            
            if (isError) {
                NSLog(@"解压脚本失败==============");
                //解压失败回调
                [ScriptUpdate updateLuaError];
            } else {
                NSLog(@"解压脚本结束==============");
                //解压完成回调
                [ScriptUpdate updateLuaSuccess];
            }
            
        });
    });
    
    return YES;
}

//获取存放文件的路径
+ (NSDictionary *) getScriptDirectory:(NSDictionary *)dict {
    //NSFileManager *fileManager = [NSFileManager defaultManager];
    NSString *scriptDirectory = Cachespath(@LoadScriptDir);
    //如果脚本不存在则赋值到目标路径
    //NSLog(@"scriptDirectory====%@", scriptDirectory);
    
    return [NSDictionary dictionaryWithObjectsAndKeys:scriptDirectory, @"scriptDirectory",
            [NSNumber numberWithInt:1], @"error", nil];
}

//判断字符串包含
+(BOOL) getContainsString:(NSString *)currentString searchString:(NSString *)str {
    if (![[NSString class] respondsToSelector:@selector(containsString)]) {
        // ios 7
        NSRange range = [currentString rangeOfString:str];
        if(range.location != NSNotFound) {
            return true;
        } else {
            return false;
        }
    } else {
        // >=iOS 8
        if ([currentString containsString: str]){
            return true;
        } else {
            return false;
        }
    }
}

@end
