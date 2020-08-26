//
//  PAHttpManagerOrder.h
//  Pods
//
//  Created by wans on 2017/9/11.
//
//

#import <Foundation/Foundation.h>
#import "PAZNBaseRequest.h"

typedef enum{
    PAHttpCodeSuccess = 0,
    PAHttpCodeFaild = -1,
    PAHttpCodeTimeOut = -2,
    PAHttpCodeFrequentlySubmitComment = -20, //频繁提交评论错误码
    PAHttpCodeSubmitSameComment = -21,       //提交相同评论错误码
    PAHttpCodeForbidComment = -23,           //用户被禁止评论
    PAHttpCodeCourseNotExist = -24,          //课程不存在
    PAHttpCodeAresForbid = -100,             //ares风控禁止
    PAHttpCodeBigDataSuccess = 200,          //大数据接口返回成功
    PAHttpCodeWltLoseEfficaacy = -1000,      //万里通失效
    PAHttpCodeTooManyInOneMinute = 100010,   //1分钟超2次
}PAHttpStatusCode;

@interface PAHttpManagerOrder : NSObject

/**
 msgID
 */
@property (nonatomic,assign) NSInteger         msgID;

/**
 请求路径
 */
@property (nonatomic,copy) NSString            *url;

/**
 请求参数 (字典或者json字符串)
 */
@property (nonatomic,copy)  id                 parameters;

/**
 需要上传参数
 */
@property (nonatomic,copy)  id                 uploadData;


/**
 提交到服务的约定格式模式
 */
@property (nonatomic,strong) NSString          *contentType;

/*!
 @brief     请求方法类型
 */
@property (nonatomic, assign) PAZNRequestMethod requtestMethordType;

/**
 是否使用缓存
 */
@property (nonatomic, assign) BOOL             useCache;

/**
 是否需要对参数进行编码, 默认为YES
 */
@property (nonatomic, assign) BOOL             isNeedEncode;

/**
 通过model传参
 */
@property (nonatomic, strong) id               requestModel;

/**
 返回data属性的模型
 */
@property (nonatomic, strong) Class            responseModel;

/**
 回调队列
 */
@property (nonatomic, strong) dispatch_queue_t responseQueue;

/**
 body的路径
 */
@property (nonatomic, strong) NSString         *bodyPath;

/**
 viewObject Model
 */
@property (nonatomic, strong) Class            viewObjectModel;

/**
 超时时间 默认10.0
 */
@property (nonatomic, assign) NSTimeInterval  timeout;

/**
 其他网络环境标识
 */
@property (nonatomic, strong) NSString         *otherEnvIdentifier;

// 方便扩展其他网络环境
/**
 默认的httpheader
 */
@property (nonatomic,strong) NSDictionary      *(^defaultHeaderFields)(NSDictionary *parameters);

/**
 默认的参数
 */
@property (nonatomic,strong) NSDictionary      *defaultParameters;

@end

