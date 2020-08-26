//
//  PAZNFCSocietyManager.h
//  PaFaceCheckSdk
//
//  Created by 黄漫(智慧城市总部成人教育事业部研发部移动端开发团队) on 2020/8/13.
//  Copyright © 2020 huming. All rights reserved.
//

#import <PaFaceCheckSdk/PaFaceCheckSdk.h>
#import "PAFaceCheckEnum.h"


NS_ASSUME_NONNULL_BEGIN
@class PAZNFCSocietyManager;
@protocol PAZNSocietyManagerDelegate <NSObject>

- (void)manager:(PAZNFCSocietyManager *)manager verifyPassword:(NSString *)password completion:(void(^)(BOOL isPass))completion;
- (void)manager:(PAZNFCSocietyManager *)manager  getSafeImgCaptchaFrom:(NSString *)phoneNum completion:(void(^)(NSInteger code, NSString *errStr, NSData *imageData))completion;
-(void)manager:(PAZNFCSocietyManager *)manager  startCaptchaWithcompletion:(void (^)(BOOL checkSuccess,NSString *challenge,NSString *secCode,NSString *validate))completion;
- (void)manager:(PAZNFCSocietyManager *)manager  getSmsCodeFrom:(NSString *)phoneNum verCode:(NSString *)code slideValidateDic:(NSDictionary *)dic isSlideValidate:(BOOL)isSlideValidate completion:(void (^)(NSInteger code, NSString *errorMsg))completion;
- (void)manager:(PAZNFCSocietyManager *)manager  checkSmsCode:(NSString *)smsCode for:(NSString *)phoneNum completion:(void(^)(NSInteger code, NSString *errStr))completion;

@end

@interface PAZNFCSocietyManager : NSObject

/// 单例
+ (PAZNFCSocietyManager *)shared;

/// 人社资源学前认证
/// @param isLearnBeforeAuth 是否开启-学习前身份验证（0：否 1：是） ,
/// @param isRealNameVerify 是否选择-人员基本信息实名认证（0：否 1：是） ,
/// @param superVC 父控制器
/// @param societyType 人社类型
/// @param delegate 代理
/// @param completion 完成回调
- (void)societyCheckBeforeLearn:(BOOL)isLearnBeforeAuth
               isRealNameVerify:(BOOL)isRealNameVerify
            superViewController:(UIViewController *)superVC
                    societyType:(PAFCSocietyType)societyType
                       delegate:(id<PAZNSocietyManagerDelegate>)delegate
                     completion:(void(^)(PAFCSocietyStatus status, NSString *desc, UIImage *faceImage))completion;

/// 清除代理，回调
- (void)clear;

@end

NS_ASSUME_NONNULL_END
