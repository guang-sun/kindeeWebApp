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
    [self.trainAPIEngine trainPostRequest:url parameters:params finished:finish];

    
}


-(void)trainGetAppUpdateWithsuccess:(defaultSuccessBlock)success
                         andFailure:(defaultFailureBlock)failure
{
    
    TrainNetWorkConfiguration   *netConf = [[TrainNetWorkConfiguration defaultConfiguration] init];
    
    NSString *urlPath = [self trainCreatBaseURL:[TrainNetWorkConfiguration trainGetAppUpdate]];
    
    NSDictionary  *dic = [self trainAddCommonParameters:nil andUserName:nil];
    
    
    [self trainBaseNetWorkWithURl:urlPath parameters:dic Success:success andFailure:failure];
    
}

@end
