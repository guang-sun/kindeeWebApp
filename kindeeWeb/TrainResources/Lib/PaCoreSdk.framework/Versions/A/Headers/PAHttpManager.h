//
//  PAHttpManager.h
//  Pods
//
//  基于PAHttpRequest扩展的请求库
//
//  Created by wans on 2017/9/11.
//
//

#import <Foundation/Foundation.h>
#import "PAHttpManagerOrder.h"
#import "PAHMErrorModel.h"
#import "PAHMMetaModel.h"
#import "PAHttpManagerConfig.h"

#import <PaCoreSdk/PAZNCache.h>

typedef void(^PAHttpManagerRequest)(PAHttpManagerOrder *order);

typedef void(^PAHttpManagerSuccess)(PAHMMetaModel *meta);
typedef void(^PAHttpManagerFailure)(PAHMErrorModel *error);


@interface PAHttpManager : NSObject

+ (PAZNCache *)httpCache;

/**
 发起get请求(查:查询数据)
 
 @param request 请求参数
 @param success 成功回调
 @param failure 失败回调
 */
+ (void)GET:(PAHttpManagerRequest)request success:(PAHttpManagerSuccess)success failure:(PAHttpManagerFailure)failure;

/**
 发起post请求(增:生成新的数据)
 
 @param request 请求参数
 @param success 成功回调
 @param failure 失败回调
 */
+ (void)POST:(PAHttpManagerRequest)request success:(PAHttpManagerSuccess)success failure:(PAHttpManagerFailure)failure;


@end
