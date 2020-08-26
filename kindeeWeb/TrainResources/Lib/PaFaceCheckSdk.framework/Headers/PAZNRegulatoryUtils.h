//
//  PAZNRegulatoryUtils.h
//  PaFaceCheckSdk
//
//  Created by 李锦华(平安科技集团系统开发部大学项目组) on 2020/7/30.
//  Copyright © 2020 huming. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface PAZNRegulatoryUtils : NSObject

//获取SDK版本号
+(NSString *)getSDKVerion;

//获取时间戳
+(NSString *)getTimestamp;

//生成nonce
+(NSString *)generateNonce;

/**
生成sign
@return 返回依据规则生成的签名
@param appId -   appId(必填)
@param appkey - appkey(必填)
@param version  - getSDKVerion获取传入(必填)
@param nonce - generateNonce 生成传入(必填)
@param timestamp - getTimestamp获取传入(必填)
@discussion
1.生成签名
*/
+(NSString *)generateSignWith:(NSString *)appId
                       appKey:(NSString *)appkey
                      version:(NSString *)version
                        nonce:(NSString *)nonce
                    timestamp:(NSString *)timestamp;
@end

NS_ASSUME_NONNULL_END
