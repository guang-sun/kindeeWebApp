//
//  TrainNetWorkAPIClient.m
//  SOHUTrain
//
//  Created by apple on 16/8/29.
//  Copyright © 2016年  Kingno. All rights reserved.
//

#import "TrainNetWorkAPIClient.h"

@implementation TrainNetWorkAPIClient



-(void)trainBaseNetWorkWithURl:(NSString *)url
                    parameters:(id )parameters
                       Success:(defaultSuccessBlock)success
                    andFailure:(defaultFailureBlock)failure{
    
    TrainAPIFinishedBlock finish = [self customFinishedBlock:^(id resultObject) {
        
        success(resultObject);
        return YES;
        
    } withFailure:failure];
    
    NSString  *params = [self trainCreatURLStringWithbaseURL:nil userinfo:nil parameters:parameters];
    NSString *getURL  = [NSString stringWithFormat:@"%@?%@",url,params];
    [self.trainAPIEngine trainPostRequest:getURL parameters:params finished:finish];
    
}

- (void)trainGetAppUpdateWithsuccess:(defaultSuccessBlock)success andFailure:(defaultFailureBlock)failure {
    
    TrainNetWorkConfiguration   *netConf = [[TrainNetWorkConfiguration defaultConfiguration] init];
    
    if (!TrainStringIsEmpty(@"")) {
        netConf = [[TrainNetWorkConfiguration defaultConfiguration] initWithHostString:@""];
    }
    NSString *urlPath = [self trainCreatBaseURL:[TrainNetWorkConfiguration trainGetAppUpdateInfo]];
    NSString *string =  [TrainUserDefault objectForKey:@"TrainWebHomeParam"];
    __block NSString *userName = @"";
    __block NSString *uuid = @"";
    if (!TrainStringIsEmpty(string)) {
        NSArray *arr = [ string componentsSeparatedByString:@"?"];
        if (arr.count > 1) {
            NSArray *params = [ arr[1] componentsSeparatedByString:@"&"];
            [params enumerateObjectsUsingBlock:^(id  _Nonnull obj, NSUInteger idx, BOOL * _Nonnull stop) {
                if ([obj hasPrefix:@"username"]) {
                    NSArray *userArr  = [obj componentsSeparatedByString:@"="];
                    if (userArr.count > 1) {
                        userName = userArr[1];
                    }
                }
                if ([obj hasPrefix:@"uuid"]) {
                    NSArray *userArr  = [obj componentsSeparatedByString:@"="];
                    if (userArr.count > 1) {
                        uuid = userArr[1];
                    }
                }

            }];
        }
    }
    NSMutableDictionary *mudic = [NSMutableDictionary dictionary];
    [mudic setObject:uuid forKey:@"uuid"];
    NSDictionary  *dic = [self trainAddCommonParameters:mudic andUserName:userName];
    
    [self trainBaseNetWorkWithURl:urlPath parameters:dic Success:success andFailure:failure];
    
}


/**
 欢迎页
 @param url 站点
 
 */
- (void)trainGetWelcomeWithBaseUrl:(NSString *)url
                           Success:(defaultSuccessBlock)success
                        andFailure:(defaultFailureBlock)failure{
    
    TrainNetWorkConfiguration   *netConf = [[TrainNetWorkConfiguration defaultConfiguration] initWithHostString:url];
    TrainNSLog(@"-======%@",netConf.hostString);
    
    NSString *urlPath = [self trainCreatBaseURL:[TrainNetWorkConfiguration trainGetWelcomeAd]];
    NSDictionary  *dic = [self trainAddCommonParameters:nil andUserName:nil];
    
    [self trainBaseNetWorkWithURl:urlPath parameters:dic Success:success andFailure:failure];
    
}





@end
