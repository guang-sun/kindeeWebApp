//
//  PAZNNetworkHelper.h
//  GZBSDKKit
//
//  Created by Mac on 16/4/18.
//  Copyright © 2016年 w-chen. All rights reserved.
//

#import <Foundation/Foundation.h>

/*!
 @enum
 @brief     查看当前网络状态
 @constant  NETWORK_TYPE_NONE   无网络
 @constant  NETWORK_TYPE_2G     2G网
 @constant  NETWORK_TYPE_3G     3G网
 @constant  NETWORK_TYPE_4G     4G网
 @constant  NETWORK_TYPE_5G     5G网
 @constant  NETWORK_TYPE_WIFI   WIFI
 */
typedef NS_ENUM(NSInteger, PAZNNetworkType)
{
    PAZN_NETWORK_TYPE_NONE = 0,
    PAZN_NETWORK_TYPE_2G = 1,
    PAZN_NETWORK_TYPE_3G = 2,
    PAZN_NETWORK_TYPE_4G = 3,
    PAZN_NETWORK_TYPE_5G = 4,
    PAZN_NETWORK_TYPE_WIFI = 5,
};

@interface PAZNNetworkHelper : NSObject

+ (PAZNNetworkType)getNetworkType;

@end
