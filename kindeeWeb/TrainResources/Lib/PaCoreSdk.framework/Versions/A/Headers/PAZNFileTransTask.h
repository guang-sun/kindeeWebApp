//
//  PAZNFileTransTask.h
//
//  Created by Cyril Zhou on 2017/3/2.
//  Copyright © 2017年 Cyril Zhou. All rights reserved.
//

#import <Foundation/Foundation.h>

@class PAZNFileTransTask;

typedef NS_ENUM(NSUInteger, PAZNFileTransTaskType)
{
    PAZNFileTransTaskUpload   = 0,
    PAZNFileTransTaskDownload = 1,
    PAZNFileTransTaskTypeButt
};

typedef void (^PAZNTaskBeginBlock)(PAZNFileTransTask *task);
typedef void (^PAZNTaskProgressBlock)(PAZNFileTransTask *task);
typedef void (^PAZNTaskEndBlock)(PAZNFileTransTask *task, NSError *error);

@interface PAZNFileTransTask : NSObject

@property (nonatomic, strong) NSString *taskID;
@property (nonatomic, strong) NSURLSessionDataTask *dataTask;
@property (nonatomic, assign) PAZNFileTransTaskType taskType;
@property (nonatomic, strong) dispatch_queue_t taskCompleteQueue;
@property (nonatomic, strong) NSString *fileTransmissionToken;
@property (nonatomic, strong) NSProgress *taskProgress;
@property (nonatomic, assign) BOOL highPriority;
@property (nonatomic, strong) id userInfo;
@property (nonatomic, strong) id responseObject;
@property (nonatomic, assign) NSUInteger fileOffset;
@property (nonatomic, assign) NSUInteger fileSize;
@property (nonatomic, assign) NSUInteger expectFileSize;
@property (nonatomic, assign) NSUInteger progressGranularity;
@property (nonatomic, copy) PAZNTaskBeginBlock taskBeginBlock;
@property (nonatomic, copy) PAZNTaskProgressBlock taskProgressBlock;
@property (nonatomic, copy) PAZNTaskEndBlock taskEndBlock;

// 下载相关参数
@property (nonatomic, strong) NSString *downloadFileRemoteUrl;
@property (nonatomic, strong) NSString *downloadFileCachePath;
@property (nonatomic, strong) NSString *redirectionFileRemoteUrl; //重定向地址

// 上传相关参
@property (nonatomic, strong) NSString *uploadFileName;
@property (nonatomic, strong) NSString *uploadFileKeyName;
@property (nonatomic, strong) NSString *uploadFileType;
@property (nonatomic, strong) NSData *uploadFileData;
@property (nonatomic, strong) NSDictionary *uploadParameters;
@property (nonatomic, strong) NSString *uploadFileRemoteUrl;
@property (nonatomic, strong) NSString *uploadFileLocalPath;

//协议相关
@property (nonatomic, strong) NSDictionary <NSString *, NSString *> *httpHeaders;

@end

