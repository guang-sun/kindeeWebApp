//
//  PACircleProgressBar.h
//  MLPlayer
//
//  Created by 周大俊(智慧教育) on 2019/3/20.
//  Copyright © 2019年 平安知鸟. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface PACircleProgressBar : UIControl

/**
 进度，默认 0
 */
@property(nonatomic, assign) CGFloat progress;

/**
 是否顺时针，默认 NO
 */
@property(nonatomic, assign) BOOL clockwise;

/**
 进度环宽度，默认 10
 */
@property(nonatomic, assign) CGFloat lineWidth;

/**
 进度环底色，默认 lightGrayColor
 */
@property(nonatomic, strong) UIColor *trackColor;

/**
 进度色，数组，>1, 则渐变；默认 @[orangeColor]
 */
@property(nonatomic, strong) NSArray<UIColor *> *progressColors; 

/**
 进度数值文本色，默认 orangeColor
 */
@property(nonatomic, strong) UIColor *progressTextColor;

/**
 进度数值文本大小，默认 12
 */
@property(nonatomic, strong) UIFont *progressTextFont;

@end

NS_ASSUME_NONNULL_END
