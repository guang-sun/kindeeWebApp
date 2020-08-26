//
//  PAZNFCBaseViewController.h
//  PaFaceCheckSdk
//
//  Created by huming on 2018/5/30.
//  Copyright © 2018年 huming. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "PAZNFCLivenessDetectionFrame.h"
#import "PAFaceCheckEnum.h"

@class PAZNFCBaseViewController;

@protocol PAFaceCheckVCDelegate <NSObject>

@optional
/**
 返回处理

 @param currentController - 当前控制器
 */
- (void)faceCheckVCCancel:(UIViewController *)currentController;
/**
 人脸采集和人脸登录回调

 @param fcVC - 当前控制器
 @param code - 错误码
 @param errStr - 错误信息
 @param detectionFrame - 人脸信息
 */
- (void)faceCheckVC:(PAZNFCBaseViewController *)fcVC DetectorCompletion:(NSInteger)code errStr:(NSString *)errStr detectionFrame:(PAZNFCLivenessDetectionFrame *)detectionFrame;

/**
 实名认证成功回调

 @param vc - 当前控制器
 */
- (void)realNameVerifySuccessWithVC:(PAZNFCBaseViewController *)vc;

/// 实名认证后返回人脸检测数据
/// @param vc 当前控制器
/// @param frame 人脸检测数据
- (void)realNameVerifySuccessWithVC:(PAZNFCBaseViewController *)vc detectionFrame:(PAZNFCLivenessDetectionFrame *)frame;

- (void)verifyPassword:(NSString *)password completion:(void(^)(BOOL isPass))completion;
- (void)getSafeImgCaptchaFrom:(NSString *)phoneNum completion:(void(^)(NSInteger code, NSString *errStr, NSData *imageData))completion;
-(void)startCaptchaWithcompletion:(void (^)(BOOL checkSuccess,NSString *challenge,NSString *secCode,NSString *validate))completion;
- (void)getSmsCodeFrom:(NSString *)phoneNum verCode:(NSString *)code slideValidateDic:(NSDictionary *)dic isSlideValidate:(BOOL)isSlideValidate completion:(void (^)(NSInteger code, NSString *errorMsg))completion;
- (void)checkSmsCode:(NSString *)smsCode for:(NSString *)phoneNum completion:(void(^)(NSInteger code, NSString *errStr))completion;
@end

@interface PAZNFCBaseViewController : UIViewController<PAFaceCheckVCDelegate>

@property (nonatomic, strong) UIView *navigationView;
@property (nonatomic, strong) UILabel *titleLab;
@property (nonatomic, strong) UIButton *backBtn;
@property (nonatomic, strong) UIImageView *backGroundImageView;
@property (nonatomic, strong) UIColor *skinNavColor;
@property (nonatomic, weak) id<PAFaceCheckVCDelegate> delegate;
@property (nonatomic, assign) PAFaceBusinessType businessType;
@property (nonatomic, assign) PAFaceFromType fromType;

/// 证件类型
@property (nonatomic, copy) NSString *cardTitle;
/// 证件类型
@property (nonatomic, assign) NSInteger cardType;
/// 证件号
@property (nonatomic, copy) NSString *cardNum;

- (void)clickBackBtn;
- (void)setBackBtnHidden:(BOOL)hidden;
- (void)showAlert:(NSString *)alertString;

@end
