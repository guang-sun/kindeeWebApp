//
//  UIView+PAZNHUD.h
//  MLPlayer
//
//  Created by suruochang on 12/8/15.
//  Copyright © 2015 w. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface NSObject (PAZNHUD)

/*
 *显示提示文字text，有不同的输入参数
 *除非明确给出HUD展示的容器view,否则将根据调用者自身所属的类来展示该视图
 *1、如果是view调用，则显示在该view中间
 *2、如果是UIViewController调用，则默认显示在UIViewController的view上
 *3、上述情况除外则显示在[[UIApplication sharedApplication] keyWindow] 上
 */

- (void)showHUD;

- (void)showHUDWithText:(NSString *)text;

- (void)showHUDWithText:(NSString *)text animated:(BOOL)animated;

- (void)showHUDWithText:(NSString *)text animated:(BOOL)animated toView:(UIView *)view;

/*
 *显示提示的text并且在 duration 之后消失
 */
- (void)showHUDWithText:(NSString *)text duration:(NSTimeInterval)duration;

- (void)showHUDWithText:(NSString *)text duration:(NSTimeInterval)duration yOffset:(CGFloat)yOffset;

- (void)showHUDWithText:(NSString *)text autoDismiss:(BOOL)dismiss;

/*
 *  多行文本显示
 */
- (void)showHudwithMoreLinesText:(NSString *)text duration:(NSTimeInterval)duration;

- (void)showHudwithMoreLinesText:(NSString *)text autoDismiss:(BOOL)dismiss;

/*
 *隐藏上述相关控件，不同的输入参数
 *根据调用者自身所属的类来隐藏对应视图上所有的HUD视图
 */
- (void)hideHUD;

- (void)hideHUDUseAnimated:(BOOL)animated;

- (void)hideHUDUseAnimated:(BOOL)animated duration:(NSTimeInterval)duration;

- (void)hideHUDAfterDuration:(NSTimeInterval)duration;

/*
 *显示带知鸟标示的loading动画
 */
- (void)showActivityIndicator;

/*
 *隐藏上述loading控件
 */
- (void)disimissActivityIndicator;

- (void)disimissActivityIndicatorUseAniamtion:(BOOL)aniamtion;

@end
