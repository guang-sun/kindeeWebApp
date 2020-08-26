//
//  PAZNGuideDisplayRule.h
//  MLPlayer
//
//  Created by 罗红(EX-LUOHONG003) on 2019/1/11.
//  Copyright © 2019 平安知鸟. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "PAZNPopupDataSource.h"

NS_ASSUME_NONNULL_BEGIN

@interface PAZNPopupDisplayRule : NSObject

+ (BOOL)needDisplay;
+ (void)displayClass: (NSString *)className onView: (UIView *)view dismiss:(void (^)(void))block;
+ (void)displayClass: (NSString *)className dataSource:(id<PAZNPopupDataSource>)dataSource onView: (UIView *)view dismiss:(void (^)(BOOL sure, NSString *result))block;

@end

NS_ASSUME_NONNULL_END
