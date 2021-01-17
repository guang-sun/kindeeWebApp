//
//  TrainNetWorkConfiguration.m
//  SOHUEhr
//
//  Created by apple on 16/8/29.
//  Copyright © 2016年  . All rights reserved.
//

#import "TrainNetWorkConfiguration.h"

@implementation TrainNetWorkConfiguration

static TrainNetWorkConfiguration *defaultConfiguration = nil;


+ (TrainNetWorkConfiguration *)defaultConfiguration
{
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
    
        defaultConfiguration = [[TrainNetWorkConfiguration alloc] initWithHostString:TrainUpdateText];
        
    });
    return defaultConfiguration;
}

- (TrainNetWorkConfiguration *)initWithHostString:(NSString *)hostString{
    self = [super init];
    if (self)
    {
        _hostString = hostString;
    }
    
    return self;
 
}

+(NSString *)trainGetAppUpdateInfo{
    return @"/center/update";

}


/**
 *  欢迎页
 */

+(NSString *)trainGetWelcomeAd{
    
    return @"/app/user/getStartPage.action";
    
}



@end
