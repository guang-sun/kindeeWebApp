//
//  PAHMErrorModel.h
//  Pods
//
//  Created by wans on 2017/9/15.
//
//

#import <Foundation/Foundation.h>
#import <PaCoreSdk/PAZNBaseRequest.h>

typedef NSString *(^PAHMErrorMsg)(NSString * _Nullable responseError);

NS_ASSUME_NONNULL_BEGIN
@interface PAHMErrorModel : NSObject

/**
 错误码
 */
@property (nonatomic,assign) NSInteger           code;

/**
 网络错误
 */
@property (nonatomic,strong) NSError             *error;

/**
 错误信息,包含服务器错误和网络错误
 */
@property (nonatomic, strong) NSString           *errorMsg;

/**
 自定义系统错误信息
 */
@property (nonatomic, strong) PAHMErrorMsg       msg;

/**
 是否是系统网络错误
 */
@property (nonatomic, assign) BOOL               isSystemError;

// 元数据
@property (nonatomic, strong) NSDictionary       *meta;

+ (PAHMErrorModel *_Nullable)errorWithRequest:(PAZNBaseRequest *)request;

@end

NS_ASSUME_NONNULL_END
