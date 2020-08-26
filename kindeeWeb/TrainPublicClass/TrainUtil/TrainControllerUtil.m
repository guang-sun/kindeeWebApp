//
//  TrainControllerUtil.m
//  SOHUTrain
//
//  Created by apple on 16/8/26.
//  Copyright © 2016年  Kingno. All rights reserved.
//

#import "TrainControllerUtil.h"
#import <CommonCrypto/CommonDigest.h>


@implementation TrainControllerUtil

//获取rootviewcontroller
+ (UIViewController *)getTrainRootVC{
    TrainControllerUtil *controllerUtil = [[TrainControllerUtil alloc] init];
    return [controllerUtil getRootVC];
}

//获取当前屏幕显示的viewcontroller
+ (UIViewController *)getTrainCurrentVC{
    TrainControllerUtil *controllerUtil = [[TrainControllerUtil alloc] init];
    return [controllerUtil getCurrentVC];
}

//获取rootviewcontroller
- (UIViewController *)getRootVC
{
    return [UIApplication sharedApplication].keyWindow.rootViewController;
}
//获取当前屏幕显示的viewcontroller
- (UIViewController *)getCurrentVC
{
    UIViewController *result = nil;
    UIWindow * window = [[UIApplication sharedApplication] keyWindow];
    if (window.windowLevel != UIWindowLevelNormal)
    {
        NSArray *windows = [[UIApplication sharedApplication] windows];
        for(UIWindow * tmpWin in windows)
        {
            if (tmpWin.windowLevel == UIWindowLevelNormal)
            {
                window = tmpWin;
                break;
            }
        }
    }
    NSLog(@"%@",[window subviews]);
    
    UIView *frontView = [[window subviews] objectAtIndex:0];
    id nextResponder = [frontView nextResponder];
    if ([nextResponder isKindOfClass:[UIViewController class]])
        result = nextResponder;
    else
        result = window.rootViewController;
    return result;
}


//判断是否为iphone X

+ (BOOL)isiPhoneX {
    if(@available(iOS 11.0, *)) {
        
        UIWindow *keyWindow  = [[[UIApplication sharedApplication] delegate] window];
        CGFloat bottomSafeInset = keyWindow.safeAreaInsets.bottom;
        if (bottomSafeInset == 34.f || bottomSafeInset == 21.0f) {
            return YES;
        }
    }
    return NO;
}

//安全区域高度

+ (float)safeBottomHeight {
   
    if (@available(iOS 11.0, *)) {
        return [[[UIApplication sharedApplication] delegate]window].safeAreaInsets.bottom;
    }
    return 0.0f;
}


const char* jailbreak_tool_pathes[] = {
       "/Applications/Cydia.app",
       "/Library/MobileSubstrate/MobileSubstrate.dylib",
       "/bin/bash",
       "/usr/sbin/sshd",
       "/etc/apt"
       };
       #define ARRAY_SIZE(a) sizeof(a)/sizeof(a[0])
+ (BOOL)isJailBroken
{
    if ([self isSimulator] == YES)
    {
        return NO;
    }
    
    for (int i=0; i<ARRAY_SIZE(jailbreak_tool_pathes); i++) {
           if ([[NSFileManager defaultManager] fileExistsAtPath:[NSString stringWithUTF8String:jailbreak_tool_pathes[i]]]) {
               NSLog(@"The device is jail broken!");
               return YES;
            }
       }
      NSLog(@"The device is NOT jail broken!");
      return NO;
}


+ (BOOL)isSimulator {
#if TARGET_OS_SIMULATOR
    return YES;
#else
    return NO;
#endif
}


//生成资源文件名及对应的hash的字典
+(NSDictionary *)getBundleFileHash{
    NSMutableDictionary * dicHash = [NSMutableDictionary dictionary];
    NSArray * fileArr = [TrainControllerUtil allFilesAtPath:[[NSBundle mainBundle]resourcePath]];
    for (NSString * fileName in fileArr) {
        
        //对应的文件生成hashFileMD5Hash
        NSString * HashString = [self getFileMD5WithPath:[[[NSBundle mainBundle] resourcePath] stringByAppendingPathComponent:fileName]];
        if (HashString != nil) {
            [dicHash setObject:HashString forKey:fileName];
        }
    }
 //所有资源文件的hash就保存在这数组里
  return dicHash;
}

//获得所有资源文件名
+ (NSArray *)allFilesAtPath:(NSString *)dir{
    NSMutableArray * arr = [NSMutableArray array];
    NSFileManager * manager = [NSFileManager defaultManager];
    NSArray *temp = [manager contentsOfDirectoryAtPath:dir error:nil];
    
    for (NSString * fileName in temp) {
        BOOL flag = YES;
        NSString * fullpath = [dir stringByAppendingPathComponent:fileName];
        if ([manager fileExistsAtPath:fullpath isDirectory:&flag]) {
            if (!flag ) {
                [arr addObject:fileName];
//                NSLog(@"%@",fileName);
            }
        }
    }
    return arr;
}

#define FileHashDefaultChunkSizeForReadingData 1024*8

+(NSString*)getFileMD5WithPath:(NSString*)path

{
    
    return (__bridge_transfer NSString *)FileMD5HashCreateWithPath((__bridge CFStringRef)path, FileHashDefaultChunkSizeForReadingData);
    
}



CFStringRef FileMD5HashCreateWithPath(CFStringRef filePath,size_t chunkSizeForReadingData) {
    
    // Declare needed variables
    
    CFStringRef result = NULL;
    
    CFReadStreamRef readStream = NULL;
    
    // Get the file URL
    
    CFURLRef fileURL =
    
    CFURLCreateWithFileSystemPath(kCFAllocatorDefault,
                                  
                                  (CFStringRef)filePath,
                                  
                                  kCFURLPOSIXPathStyle,
                                  
                                  (Boolean)false);
    
    if (!fileURL) goto done;
    
    // Create and open the read stream
    
    readStream = CFReadStreamCreateWithFile(kCFAllocatorDefault,
                                            
                                            (CFURLRef)fileURL);
    
    if (!readStream) goto done;
    
    bool didSucceed = (bool)CFReadStreamOpen(readStream);
    
    if (!didSucceed) goto done;
    
    // Initialize the hash object
    
    CC_MD5_CTX hashObject;
    
    CC_MD5_Init(&hashObject);
    
    // Make sure chunkSizeForReadingData is valid
    
    if (!chunkSizeForReadingData) {
        
        chunkSizeForReadingData = FileHashDefaultChunkSizeForReadingData;
        
    }
    
    // Feed the data to the hash object
    
    bool hasMoreData = true;
    
    while (hasMoreData) {
        
        uint8_t buffer[chunkSizeForReadingData];
        
        CFIndex readBytesCount = CFReadStreamRead(readStream,(UInt8 *)buffer,(CFIndex)sizeof(buffer));
        
        if (readBytesCount == -1) break;
        
        if (readBytesCount == 0) {
            
            hasMoreData = false;
            
            continue;
            
        }
        
        CC_MD5_Update(&hashObject,(const void *)buffer,(CC_LONG)readBytesCount);
        
    }
    
    // Check if the read operation succeeded
    
    didSucceed = !hasMoreData;
    
    // Compute the hash digest
    
    unsigned char digest[CC_MD5_DIGEST_LENGTH];
    
    CC_MD5_Final(digest, &hashObject);
    
    // Abort if the read operation failed
    
    if (!didSucceed) goto done;
    
    // Compute the string result
    
    char hash[2 * sizeof(digest) + 1];
    
    for (size_t i = 0; i < sizeof(digest); ++i) {
        
        snprintf(hash + (2 * i), 3, "%02x", (int)(digest[i]));
        
    }
    
    result = CFStringCreateWithCString(kCFAllocatorDefault,(const char *)hash,kCFStringEncodingUTF8);
    
    
    
done:
    
    if (readStream) {
        
        CFReadStreamClose(readStream);
        
        CFRelease(readStream);
        
    }
    
    if (fileURL) {
        
        CFRelease(fileURL);
        
    }
    
    return result;
    
}


+ (BOOL)trainCompareFileHash {
    
    
    NSDictionary  *appDic = [self getBundleFileHash];
    
//    NSString *docPath = [NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES) objectAtIndex:0];
//       //要创建的plist文件名 -> 路径
//       NSString *filePath = [docPath stringByAppendingPathComponent:@"appHash.plist"];
//       //将数组写入文件
//       [appDic writeToFile:filePath atomically:YES];
//     
    
    NSString *path = [[NSBundle mainBundle] pathForResource:@"appHash" ofType:@"plist"];
    NSDictionary  *localDic  ;
    if (!TrainStringIsEmpty(path)) {
        localDic = [NSDictionary dictionaryWithContentsOfURL:[NSURL fileURLWithPath:path]];
    }
    BOOL  isEqual = YES ;
    
    for (NSString  *key in appDic.allKeys) {
        
        if ([key isEqualToString:@"Assets.car"]){
            continue;
        }
        
        
        NSString *appval  = appDic[key];
        NSString *localVal = localDic[key];
        if (!TrainStringIsEmpty(appval) && !TrainStringIsEmpty(localVal) ) {
            
            isEqual = [appval isEqualToString:localVal] ;
            
        }else {
            isEqual = NO ;
        }
    }
    return  isEqual;
}








@end
