//
//  PAZNFileTransManager.h
//
//  Created by Cyril Zhou on 2017/3/2.
//  Copyright © 2017年 Cyril Zhou. All rights reserved.
//

#import "PAZNBaseManager.h"
#import "PAZNFileTransTask.h"

@interface PAZNFileTransManager : PAZNBaseManager

+ (PAZNFileTransManager *)shareInstance;

/**
 默认的httpheader
 */
@property (nonatomic,strong) NSDictionary *(^defaultHeaderFields)(NSDictionary *parameters);

- (void)download:(PAZNFileTransTask *)task;
- (void)upload:(PAZNFileTransTask *)task;

- (PAZNFileTransTask *)getTaskByTaskID:(NSString *)taskID;
- (void)setFileTransmissionToken:(NSString *)token;

- (void)cancelTaskByTaskID:(NSString *)taskID;
- (void)cancelAllTask;

- (void)enableRedirect;
@end
