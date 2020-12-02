//
//  TrainNetWorkAPIClient.h
//  SOHUTrain
//
//  Created by apple on 16/8/29.
//  Copyright © 2016年  Kingno. All rights reserved.
//

#import "TrainNetWorkClientBase.h"



@interface TrainNetWorkAPIClient : TrainNetWorkClientBase


#pragma mark - webView


/**
 嵌页面weburl拼接
 @param mod       mod
 @param object_id object_id
 
 @return  嵌页面weburl
 */
- (NSString *)trainWebViewMode:(NSString *)mod
                     object_id:(NSString *)object_id
                  andtarget_id:(NSString *)target_id;


/**
 给URL添加个人信息session
 @param baseURL 基础URL
 
 @return 添加个人信息session的URL
 */
- (NSString *)trainWebViewAddEmpidWithBaseURL:(NSString  *)baseURL;


#pragma   mark - gengxin


/**
 gengxin

 @param url 站点

 */
- (void)trainGetAppUpdateWithsuccess:(defaultSuccessBlock)success
                          andFailure:(defaultFailureBlock)failure;


@end
