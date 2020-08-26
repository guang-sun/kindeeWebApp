//
//  PAZNLoginVerCodeInputView.h
//  MLPlayer
//
//  Created by Cyril Zhou on 2017/3/15.
//  Copyright © 2017年 w. All rights reserved.
//

#import <UIKit/UIKit.h>

@protocol PAZNCaptchaPasswordViewDelegate <NSObject>

@optional
- (void)passwordViewDidFinished:(NSString *)inputString;
- (void)passwordViewDidChanging:(NSString *)inputString;

@end

@interface PAZNCaptchaPasswordView : UIView <UITextFieldDelegate>

@property (nonatomic , weak) id<PAZNCaptchaPasswordViewDelegate> delegate;

- (instancetype)initWithFrame:(CGRect)frame;
- (void)clearPassword;
- (void)becomeFirstResp;
- (void)resignFirstResp;

@end

@protocol PAZNCaptchaInputViewDelegate <NSObject>
- (UIImage *)imageForRefresh;

@optional
- (UIImage *)imageForClose;
- (void)verCodeViewTapClose;
- (void)verCodeViewTapRefreshWithCompHandler:(void (^)(NSInteger code, NSData *imageData))completionHandler;
- (void)verCodeViewInputFinish:(NSString *)code completionHandler:(void (^)(NSInteger code, NSString *errorMsg))completionHandler;

@end

typedef void(^PAZNCaptchaTextViewBlock)(NSString *text);

@interface PAZNCaptchaInputView : UIView

@property (nonatomic, weak) id<PAZNCaptchaInputViewDelegate> delegate;

- (instancetype)initWithFrame:(CGRect)frame imageData:(NSData *)imageData tips:(NSString *)tips delegate:(id<PAZNCaptchaInputViewDelegate>)delegate;

+ (instancetype)showCaptchaInputViewAlertViewInView:(UIView *)view imageData:(NSData *)imageData tips:(NSString *)tips delegate:(id<PAZNCaptchaInputViewDelegate>)delegate;

@end
