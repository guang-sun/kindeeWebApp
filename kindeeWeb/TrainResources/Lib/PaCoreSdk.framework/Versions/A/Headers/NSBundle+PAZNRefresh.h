//
//  NSBundle+MJRefresh.h
//  MJRefreshExample
//
//  Created by MJ Lee on 16/6/13.
//  Copyright © 2016年 小码哥. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface NSBundle (PAZNRefresh)
+ (instancetype)pazn_refreshBundle:(NSString *)path;
+ (UIImage *)pazn_arrowImage;
+ (NSString *)pazn_localizedStringForKey:(NSString *)key value:(NSString *)value;
+ (NSString *)pazn_localizedStringForKey:(NSString *)key;
@end
