//
//  PAZNSXMarquee.h
//  Wonderful
//
//  Created by dongshangxian on 15/11/5.
//  Copyright © 2015年 Sankuai. All rights reserved.
//

#import <UIKit/UIKit.h>

typedef NS_ENUM(NSInteger, PAZNSXMarqueeSpeedLevel) {
    PAZNSXMarqueeSpeedLevelFast       = 2,
    PAZNSXMarqueeSpeedLevelMediumFast = 4,
    PAZNSXMarqueeSpeedLevelMediumSlow = 6,
    PAZNSXMarqueeSpeedLevelSlow       = 8,
};

@interface PAZNSXMarquee : UIView

@property (nonatomic, copy) NSString              *message;

@property (nonatomic,strong) UIColor              *leftFadeColor;

@property (nonatomic,strong) UIColor              *rightFadeColor;

/**
 *  style is default, backgroundColor is white,textColor is black;
 *
 *  @param speed you can set 2,4,6,8.  smaller is faster
 *
 *  @return
 */
- (instancetype)initWithFrame:(CGRect)frame speed:(PAZNSXMarqueeSpeedLevel)speed Msg:(NSString *)msg ;

/**
 *  style is diy, backgroundColor and textColor can config
 *
 *  @param speed  you can set 2,4,6,8.  smaller is faster
 *  @param bgColor  backgroundColor
 *  @param txtColor textColor
 *
 *  @return
 */
- (instancetype)initWithFrame:(CGRect)frame speed:(PAZNSXMarqueeSpeedLevel)speed Msg:(NSString *)msg bgColor:(UIColor *)bgColor txtColor:(UIColor *)txtColor;

/**
 *  you can change the tapAction show or jump, without this method default is tap to stop
 *
 *  @param action tapAction block code
 */
- (void)changeTapMarqueeAction:(void(^)())action;

/**
 *  you can change marqueeLabel 's font before start
 *
 */
- (void)changeMarqueeLabelFont:(UIFont *)font;

/**
 *  when you set everything what you want,you can use this method to begin animate
 */
- (void)start;

/**
 *  pause
 */
- (void)stop;

/**
 *  will start with the point we stoped.
 */
- (void)restart;

@end
