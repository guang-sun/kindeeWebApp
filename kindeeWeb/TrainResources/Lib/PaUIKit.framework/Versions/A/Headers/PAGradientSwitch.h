//
//  PAGradientSwitch.h
//  MLPlayer
//
//  Created by Davon Zhou on 2018/10/2.
//  Copyright © 2018 w. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface PAGradientSwitch : UIControl

@property (strong, nonatomic) UIColor *backgroundColor; // defaults to gray
@property (strong, nonatomic) UIColor *sliderColor; // defaults to white
@property (nonatomic, strong) NSArray<UIColor *> *sliderGradientTintColors;
@property (nonatomic, strong) CAGradientLayer *sliderGradientLayer;
@property (strong, nonatomic) UIColor *labelTextColorInsideSlider; // defaults to black
@property (strong, nonatomic) UIColor *labelTextColorOutsideSlider; // defaults to white
@property (strong, nonatomic) UIFont *labelFontInsideSlider; // defaults to black
@property (strong, nonatomic) UIFont *labelFontOutsideSlider; // defaults to white
@property (nonatomic) CGFloat cornerRadius; // defaults to 12
@property (nonatomic) CGFloat sliderOffset; // slider offset from background, top, bottom, left, right
@property (nonatomic) NSInteger selectedIndex;

+ (instancetype)switchWithStringsArray:(NSArray *)strings;
- (instancetype)initWithStringsArray:(NSArray *)strings;
- (instancetype)initWithAttributedStringsArray:(NSArray *)strings;

- (void)forceSelectedIndex:(NSInteger)index animated:(BOOL)animated; // sets the index, also calls handler block

// This method sets handler block that is getting called after the switcher is done animating the transition

- (void)setPressedHandler:(void (^)(NSUInteger index))handler;

// This method sets handler block that is getting called right before the switcher starts animating the transition

- (void)setWillBePressedHandler:(void (^)(NSUInteger index))handler;

- (void)selectIndex:(NSInteger)index animated:(BOOL)animated; // sets the index without calling the handler block

@end
NS_ASSUME_NONNULL_END
