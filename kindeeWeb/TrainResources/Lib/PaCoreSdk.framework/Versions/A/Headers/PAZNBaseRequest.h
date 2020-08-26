//
//  PAZNBaseRequest.h
//  MLPlayer
//
//  Created by liurj on 16/3/14.
//  Copyright © 2016年 w. All rights reserved.
//

typedef NS_ENUM(NSInteger , PAZNRequestCode)
{
    PAZNRequestCodeSuccess = 0,           //操作成功
    PAZNRequestCodeFail = -1,             //系统内部错误
    PAZNRequestCodeDataUnzip = -2,        //返回数据解压失败
    PAZNRequestCodeDataWrong = -3,         //数据格式错误
    PAZNRequestCodeDemotion = 41766,      //后台处于降级模式
    PAZNRequestCodeLimitTraffic = 41767,  //后台处于限流模式
};

typedef NS_ENUM(NSInteger , PAZNRequestMethod)
{
    PAZNRequestMethodGet = 0,
    PAZNRequestMethodPost,
    PAZNRequestMethodHead,
    PAZNRequestMethodPut,
    PAZNRequestMethodDelete,
    PAZNRequestMethodPatch,
    PAZNRequestMethodMultiFilePost,
    PAZNRequestMethodSpecialPost //共用参数拼到Url 后台需要的数据bodyJson
};

typedef NS_ENUM(NSInteger, PARequestSerializerType) {
    PARequestSerializerTypeHTTP = 0,
    PARequestSerializerTypeJSON,
};

@class PAZNBaseRequest;

typedef void(^PAZNBaseRequestCompletionBlock)(PAZNBaseRequest *request);

#define PAZNRequestServerSpecialMode @"kPAZNRequestServerSpecialMode"

@interface PAZNBaseRequest : NSObject

/*!
 @brief     需要添加到 http header 里的参数
 */
@property (nonatomic, strong) NSDictionary <NSString *, NSString *> *httpHeaders;

/*!
 @brief     参数
 */
@property (nonatomic, strong) NSDictionary *paramsDictionary;

/*!
 @brief     请求api
 */
@property (nonatomic, strong) NSString *relateiveUrl;
@property (nonatomic, strong) NSString *absoluteUrl;
@property (nonatomic, strong) NSString *buildRequestUrl;

/*!
 @brief     请求方法类型
 */
@property (nonatomic, assign) PAZNRequestMethod requtestMethordType;

/**
@brief 默认: PARequestSerializerTypeHTTP
 */
@property (nonatomic, assign) PARequestSerializerType requestSerializerType;

/**
 @brief 默认10.0
 */
@property (nonatomic, assign) NSTimeInterval timeout;

/*!
 @brief     tag
 */
@property (nonatomic, assign) NSInteger tag;

/*!
 @brief     用户自己扩展requtestUserInfo
 */
@property (nonatomic, strong) id requtestUserInfo;

/*!
 @brief     解码后的应答数据
 */
@property (nonatomic, strong) id responseObj;

/*!
@brief     解码后的应答header
*/
@property (nonatomic, strong) id responseHeader;

/*!
 @brief     是否为超时失败
 */
@property (nonatomic, assign) BOOL bIsFailedForTimeOut;

/**
 @brief     网络错误
 */
@property (nonatomic, strong) NSError *responseError;

/**
 @brief     回调队列, 默认为主线程
 */
@property (nonatomic, strong) dispatch_queue_t responseQueue;


/*!
 @brief     失败原因
 */
@property (nonatomic, assign) NSInteger responseStatusCode;
@property (nonatomic, strong) NSString *responseStatusDescription;

- (instancetype)initWithAbsoluteUrl:(NSString *)absoluteUrl
                         paramsDict:(NSDictionary *)paramsDict;

- (instancetype)initWithRelativeUrl:(NSString *)relativeUrl
                          SeverHost:(NSString *)SeverHost
                            OpenSSL:(BOOL)OpenSSL
                             params:(NSDictionary *)paramsDict;

- (instancetype)initWithRelativeUrl:(NSString *)relativeUrl
                          SeverHost:(NSString *)SeverHost
                            OpenSSL:(BOOL)OpenSSL
                       paramsString:(NSString *)paramsStr;

/*!
 @fileParams     格式如下,任一字段确保有，且有值，且值类型正确，否则终止：
 [@{
 @"name": @"name", // fieldName
 @"fileName": @"fileName", //文件名
 @"data": NSData || [NSArray<NSData *>, //文件数据，值为数据或数据数组
 @"mimeType": @"minetype", //文件类型
 },
 ...
 ]
 */
- (instancetype)initMultiFileWithRelativeUrl:(NSString *)relativeUrl
                                   SeverHost:(NSString *)SeverHost
                                     OpenSSL:(BOOL)OpenSSL
                                  fileParams:(NSArray<NSDictionary *> *)filesArray
                                      paramsString:(NSString *)paramsStr;

- (instancetype)initSpecialPostWithUrl:(NSString *)relativeUrl
                             SeverHost:(NSString *)SeverHost
                               OpenSSL:(BOOL)OpenSSL
                       urlParamsString:(NSString *)urlParamsString
                           jsonBodyDic:(NSDictionary *)jsonBodyDic;

- (instancetype)initSpecialDeleteWithUrl:(NSString *)relativeUrl
                             SeverHost:(NSString *)SeverHost
                               OpenSSL:(BOOL)OpenSSL
                       urlParamsString:(NSString *)urlParamsString
                           jsonBodyDic:(NSDictionary *)jsonBodyDic;

- (void)startWithCompletionBlockWithSuccess:(PAZNBaseRequestCompletionBlock)success
                                    failure:(PAZNBaseRequestCompletionBlock)failure;

- (void)cancelRequest;

@end
