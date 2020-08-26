//
//  PAZNInputVerificationCodeView.h
//  PaPaySdk
//
//  Created by heng on 2017/11/18.
//  Copyright © 2017年 PAZN. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "UIColor+PAZNHex.h"
#import "UIFont+PAZNExtra.h"
#import "PAZNMasonry.h"
#import "UIView+PAZNAdditions.h"

#define BoundsOfScale6(x) (UI_IOS_WINDOW_HEIGHT > UI_IOS_WINDOW_WIDTH ? round((x)*(UI_IOS_WINDOW_WIDTH/375.0)) : round((x)*(UI_IOS_WINDOW_WIDTH/667.0)))
//状态栏高度
#define def_baseStatusBar_height    [UIApplication sharedApplication].statusBarFrame.size.height

//导航栏高度（不包含状态栏）
#define def_baseNavBar_height       44

//导航栏高度（包含状态栏）
#define def_NavBar_height           (def_baseNavBar_height + def_baseStatusBar_height)

#define kNaviLeftButtonAdjustDistance   (UI_IOS_WINDOW_WIDTH * (5.0 / 320))
#define kNaviButtonSize                 CGSizeMake(44, 44)
#define kNaviLeftButtonX                (UI_IOS_WINDOW_WIDTH * (2.0 / 320))


@protocol PAZNInputVerificationCodeViewDelegate <NSObject>

- (void)passwordViewDidFinished:(NSString *)inputString;

@optional
- (void)passwordViewDidChanging:(NSString *)inputString;

@end

@interface PAZNInputVerificationCodeView : UIView<UITextFieldDelegate>

@property (nonatomic , weak)id<PAZNInputVerificationCodeViewDelegate> delegate;

- (id)initWithFrame:(CGRect)frame showInput:(BOOL)isShow;

- (void)clearPassword;

- (void)becomeFirstResp;

- (void)resignFirstResp;

@end
