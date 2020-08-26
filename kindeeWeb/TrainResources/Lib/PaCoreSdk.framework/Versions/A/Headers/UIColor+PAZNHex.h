//
//  UIColor+UIColor_extra_h.h
//  PAChat
//
//  Created by xiao on 8/12/14.
//  Copyright (c) 2014 FreeDo. All rights reserved.
//

#import <UIKit/UIKit.h>

#define UIColorHex(_hex_)   [UIColor pazn_colorWithHexString:((__bridge NSString *)CFSTR(#_hex_))]

@interface UIColor (PAZNHex)

+ (UIColor *)pazn_colorWithHex:(long)hexColor;
+ (UIColor *)pazn_colorWithHex:(long)hexColor alpha:(float)opacity;

+ (UIColor *)pazn_colorWithHexString:(NSString *)color;
+ (UIColor *)pazn_colorWithHexString:(NSString *)color alpha:(float)opacity;

+ (NSString *)pazn_hexStringWithColor:(UIColor *)color;

//前2位为16进制表示透明度的，后面的6位表示颜色
+(UIColor *)pazn_getColor:(NSString *)hexColor;

@end
