//
//  PAZNReachability.h
//  YYKit <https://github.com/ibireme/YYKit>
//
//  Created by ibireme on 15/2/6.
//  Copyright (c) 2015 ibireme.
//
//  This source code is licensed under the MIT-style license found in the
//  LICENSE file in the root directory of this source tree.
//

#import <Foundation/Foundation.h>
#import <SystemConfiguration/SystemConfiguration.h>
#import <netinet/in.h>

typedef NS_ENUM(NSUInteger, PAZNReachabilityStatus) {
    PAZNReachabilityStatusNone  = 0, ///< Not Reachable
    PAZNReachabilityStatusWWAN  = 1, ///< Reachable via WWAN (2G/3G/4G)
    PAZNReachabilityStatusWiFi  = 2, ///< Reachable via WiFi
};

typedef NS_ENUM(NSUInteger, PAZNReachabilityWWANStatus) {
    PAZNReachabilityWWANStatusNone  = 0, ///< Not Reachable vis WWAN
    PAZNReachabilityWWANStatus2G = 2, ///< Reachable via 2G (GPRS/EDGE)       10~100Kbps
    PAZNReachabilityWWANStatus3G = 3, ///< Reachable via 3G (WCDMA/HSDPA/...) 1~10Mbps
    PAZNReachabilityWWANStatus4G = 4, ///< Reachable via 4G (eHRPD/LTE)       100Mbps
};


/**
 `QXReachability` can used to monitor the network status of an iOS device.
 */
@interface PAZNReachability : NSObject

@property (nonatomic, assign, readonly) SCNetworkReachabilityFlags flags;                           ///< Current flags.
@property (nonatomic, assign, readonly) PAZNReachabilityStatus status;                                ///< Current status.
@property (nonatomic, assign, readonly) PAZNReachabilityWWANStatus wwanStatus NS_AVAILABLE_IOS(7_0);  ///< Current WWAN status.
@property (nonatomic, assign, readonly, getter=isReachable) BOOL reachable;

/// Notify block which will be called on main thread when network changed.
@property (nonatomic, copy) void (^notifyBlock)(PAZNReachability *reachability);

+ (instancetype)reachability;
+ (instancetype)reachabilityForLocalWifi;
+ (instancetype)reachabilityWithHostname:(NSString *)hostname;
+ (instancetype)reachabilityWithAddress:(const struct sockaddr_in *)hostAddress;

@end
