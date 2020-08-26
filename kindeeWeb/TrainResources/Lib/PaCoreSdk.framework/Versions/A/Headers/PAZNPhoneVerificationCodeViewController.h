//
//  PAZNWalletCheckPhoneViewController.h
//  PaPaySdk
//
//  Created by heng on 2017/11/16.
//  Copyright © 2017年 PAZN. All rights reserved.
//

#import <Foundation/Foundation.h>

//申请验证码类型
typedef NS_ENUM(NSInteger, PAZNRequestSmsType)
{
    PAZNSmsRegister                = 1,    //注册
    PAZNSmsForgetPassword          = 2,    //忘记密码
    PAZNSmsChangePhoneNum          = 3,    //修改手机号
    PAZNSmsFace                    = 9,    //人脸采集
};

@protocol PAZNPhoneVerificationCodeDelegate <NSObject>

- (void)dismissVC:(UIViewController *)vc;

- (void)getSafeImgCapthcha:(NSString *)phoneNum completion:(void (^)(NSInteger code, NSString *errStr, NSData *imageData))completion;

- (void)getSmsCodeWithImgCaptcha:(NSString *)phoneNum verCode:(NSString *)code completion:(void(^)(NSInteger code, NSString *errStr))completion;

- (void)checkSmsCode:(NSString *)phoneNum verCode:(NSString *)msgCode;
@end

@interface PAZNPhoneVerificationCodeViewController : UIViewController

@property (nonatomic, weak) id<PAZNPhoneVerificationCodeDelegate> delegate;

- (instancetype)initWithTitle:(NSString *)title
                     phoneNum:(NSString *)phoneNum
              displayPhoneNum:(NSString *)displayPhoneNum
     displayInvisiblePhoneNum:(NSString *)displayInvisiblePhoneNum
                   tipsString:(NSString *)tipsString
                    phoneIcon:(UIImage *)phoneIcon
                finishBtnIcon:(UIImage *)finishBtnIcon
              unfinishBtnIcon:(UIImage *)unfinishBtnIcon
                    closeIcon:(UIImage *)closeIcon
                  refreshIcon:(UIImage *)refreshIcon
                  backBtnIcon:(UIImage *)backBtnIcon;

@end
