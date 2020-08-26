//
//  UIWindow+PAZNExtra.h
//  PaCoreSdk
//
//  Created by 周大俊(智慧教育) on 2020/2/17.
// 

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface UIWindow (PAZNExtra)

- (UIViewController *)visibleViewController;

- (UIImage *)getScreenshot;

- (UIView *)getStatusBar;

@end

NS_ASSUME_NONNULL_END
