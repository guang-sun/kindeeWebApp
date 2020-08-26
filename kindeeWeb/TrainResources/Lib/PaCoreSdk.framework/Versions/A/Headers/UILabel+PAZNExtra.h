//
//  UILabel+BoundsCate.h
//  MLPlayer
//
//  Created by BearLi on 15/11/16.
//  Copyright © 2015年 w. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UILabel (PAZNExtra)

/**
 *  字体的大小
 *  [UIFont systemFontOfSize:systemFont]
 */
@property (nonatomic,assign) CGFloat systemFont;

/**
 *  计算Text的宽, (固定高的情况下)
 *
 *  @return 返回文本宽度
 */
- (CGFloat)widthForText;

/**
 *  计算Text的高, (固定宽的情况下)
 *
 *  @return 返回文本高度
 */
- (CGFloat)heightForText;

/**
 *  根据text获取每行文字的数组
 *
 *  @param text 文本字符串
 *
 *  @return 每行文字的数组
 */
- (NSArray *)getContentLinesArrayWithText:(NSString*)text;

/**
 * 根据text获取每行文字的数组
 *
 *  @param text  文本字符串
 *  @param font  字体
 *  @param width 约束的宽
 *
 *  @return 每行文字的数组
 */
+ (NSArray *)getContentLinesArrayWithText:(NSString*)text font:(UIFont*)font constraintWidth:(CGFloat)width;

@end
