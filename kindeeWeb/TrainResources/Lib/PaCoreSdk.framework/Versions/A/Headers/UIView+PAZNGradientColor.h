//
//  UIView+PAGradientColor.h
//  PADrawAwardModule
//
//  Created by 王斌(平安科技智慧教育团队项目研发部知鸟研发团队移动开发组) on 2018/9/29.
//  Copyright © 2018年 wans. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UIView (PAZNGradientColor)

@property (nonatomic, strong) CAGradientLayer *pa_gradientLayer;

@property (nonatomic, strong) NSArray<UIColor *> *pa_gradientTintColors;

- (void)pazn_gradientTintColors:(NSArray<UIColor *> *)gradientTintColors frame:(CGRect)frame;

@end
