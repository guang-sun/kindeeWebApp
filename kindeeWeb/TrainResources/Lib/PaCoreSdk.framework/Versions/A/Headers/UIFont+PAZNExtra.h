//
//  UIFont+PAZNExtra.h
//  MLPlayer
//
//  Created by wyd on 14-11-25.
//  Copyright (c) 2014年 w. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UIFont (PAZNExtra)

/**
 *  如果当前系统没有改字体，就返回系统缺省字体
 */
+ (UIFont *)fontWithNameSafe:(NSString *)fontName size:(CGFloat)fontSize;

@end
