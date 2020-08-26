//
//  PAZNMASConstraint+Constants.h
//  PADrawAwardModule
//
//  Created by 王斌(平安科技智慧教育团队项目研发部知鸟研发团队移动开发组) on 2018/8/31.
//  Copyright © 2018年 wans. All rights reserved.
//

#import <PaCoreSdk/PAZNMASConstraint.h>

@interface PAZNMASConstraint (Constants)

@property (nonatomic, assign) CGFloat                               pa_constant;

@property (nonatomic, assign) CGFloat                               pa_offset;

@property (nonatomic, strong) PAZNMASConstraint*(^mas_equalConstant)(CGFloat constant);

@property (nonatomic, strong) PAZNMASConstraint*(^mas_equalOffset)(CGFloat offset);

@end

@interface UIButton (Hidden)

@property (nonatomic, strong) NSString                              *pa_text;

@property (nonatomic, strong) UIImage                               *pa_image;

@end

@interface CALayer (BorderColor)

@property (nonatomic, strong) UIColor                               *pa_borderColor;

@end
