//
//  PAZNSXColorGradientView.h
//  Wonderful
//
//  Created by dongshangxian on 15/11/1.
//  Copyright © 2015年 Sankuai. All rights reserved.
//

#import <UIKit/UIKit.h>

typedef NS_ENUM(NSInteger, SXGradientDirection) {
    PAZNSXGradientToTop    = 1,
    PAZNSXGradientToLeft   = 2,
    PAZNSXGradientToBottom = 3,
    PAZNSXGradientToRight  = 4,
};

@interface PAZNSXColorGradientView : UIView

/**
 *  use one color to init the gradientView,default is this color to clear.
 *
 *  @param visible   can you see other view what below the gradientView
 *  @param direction  the direction we want gradient to clear
 *
 *  @return
 */
+ (instancetype)createWithColor:(UIColor *)color frame:(CGRect)frame direction:(SXGradientDirection)direction;

/**
 *  use two color to init the gradientView, from fromColor gradient to toColor
 *
 *  @param direction the direction we want gradient to toColor
 *
 *  @return 
 */
+ (instancetype)createWithFromColor:(UIColor *)fromColor toColor:(UIColor *)toColor frame:(CGRect)frame direction:(SXGradientDirection)direction;

/**
 *  use a colorArray to generate a wonderful gradientView.
 *
 *  @param colorArray array with UIColor
 *
 *  @return
 */
+ (instancetype)createWithColorArray:(NSArray *)colorArray frame:(CGRect)frame direction:(SXGradientDirection)direction cornerRadius:(CGFloat)cornerRadius;

@end
