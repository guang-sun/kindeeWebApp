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


-(void)trainGetAppUpdateWithsuccess:(defaultSuccessBlock)success
                         andFailure:(defaultFailureBlock)failure;

/**
 欢迎页
 @param url 站点
 
 */
- (void)trainGetWelcomeWithBaseUrl:(NSString *)url
                         Success:(defaultSuccessBlock)success
                      andFailure:(defaultFailureBlock)failure;



@end
