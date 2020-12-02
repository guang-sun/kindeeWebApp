//
//  TrainNetWorkConfiguration.h
//  SOHUEhr
//
//  Created by apple on 16/8/29.
//  Copyright © 2016年  . All rights reserved.
//

#import <Foundation/Foundation.h>
#import "TrainNetWorkAPI.h"


@interface TrainNetWorkConfiguration : NSObject

@property (nonatomic, strong, readonly) NSString * hostString;

// 默认配置 url

+ (TrainNetWorkConfiguration *)defaultConfiguration;

// 生成自定义配置， hostString

- (TrainNetWorkConfiguration *)initWithHostString:(NSString *)hostString;


/**************************
 *
 * 获取各请求的 url query path
 *
 ****************************/


#pragma   mark - gengxin
/**
 *  gengxin
 */

+(NSString *)trainGetAppUpdateInfo;







@end
