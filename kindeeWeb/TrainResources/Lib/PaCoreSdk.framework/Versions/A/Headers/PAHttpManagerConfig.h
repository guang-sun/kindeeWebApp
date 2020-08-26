//
//  PAHttpManagerConfig.h
//  PaCoreSdk
//
//  Created by 王斌(平安科技智慧教育团队项目研发部知鸟研发团队移动开发组) on 2019/1/11.
//  Copyright © 2019年 Cyril Zhou. All rights reserved.
//

#import <Foundation/Foundation.h>

@class PAHMErrorModel;

typedef void(^HMSpecialErrorTask)(PAHMErrorModel *error);

@interface PAHttpConfigOrder : NSObject

/**
 根域名或ip地址
 */
@property (nonatomic,strong) NSString            *SeverHost;

@property (nonatomic,strong) NSString            *liveSensitiveHost;

@property (nonatomic,strong) NSString            *kCurrentAppId;

/**
 OpenSSL
 */
@property (nonatomic,assign) BOOL                OpenSSL;

/**
 默认的httpheader
 */
@property (nonatomic,strong) NSDictionary *(^defaultHeaderFields)(NSDictionary *parameters);

/**
 默认的参数
 */
@property (nonatomic,strong) NSDictionary        *defaultParameters;



@end


typedef void (^PAHttpConfig)(PAHttpConfigOrder *config);

@interface PAHttpManagerConfig : NSObject

/**
 配置网络库，根域名

 @param identifier 其他网络环境标识
 @param config 配置
 */
+ (void)setupOtherEnvWithIdentifier:(NSString *)identifier config:(PAHttpConfig)config;
+ (void)setupConfig:(PAHttpConfig)config;

/**
 获取网络库配置

 @param identifier 其他网络环境标识
 @return 配置
 */
+ (PAHttpConfigOrder *)configOtherEnvWithIdentifier:(NSString *)identifier;
+ (PAHttpConfigOrder *)config;

/**
更新网络配置，只更新设置项

@param identifier 其他网络环境标识
@return 配置
*/
+ (void)updateOtherEnvWithIdentifier:(NSString *)identifier config:(PAHttpConfig)config;
+ (void)updateConfig:(PAHttpConfig)config;

/**
 设置特殊错误统一处理

 @param identifier 其他网络环境标识
 @param errorTask 错误任务
 */
+ (void)onSpecialErrorOtherEnvWithIdentifier:(NSString *)identifier errorTask:(HMSpecialErrorTask)errorTask;
+ (void)onSpecialError:(HMSpecialErrorTask)specialError;

/**
获取特殊错误统一处理任务

@param identifier 其他网络环境标识
*/
+ (HMSpecialErrorTask)specialErrorTaskOtherEnvWithIdentifier:(NSString *)identifier;
+ (HMSpecialErrorTask)specialErrorTask;

@end

