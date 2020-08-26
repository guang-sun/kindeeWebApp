//
//  PAZNFaceCheckManager.h
//  MLPlayer
//
//  Created by 胡铭 on 2018/1/5.
//  Copyright © 2018年 w. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "PAFaceCheckEnum.h"
#import <UIKit/UIKit.h>



typedef void(^PAZNFaceCheckCompletionBlock)(BOOL isSuccess);

@protocol PAZNFaceCheckManagerDelegate <NSObject>

@optional

- (void)checkIsSetFaceId;
- (void)checkIsSetRealName;
- (void)openExamFaceCheck:(BOOL)flag;
- (void)startFaceCheck:(NSString *)examId scoreId:(NSString *)scroreId success:(PAZNFaceCheckCompletionBlock)completion;
- (void)startFaceLoginWithScuess:(PAZNFaceCheckCompletionBlock)completion;

@end

@protocol PAZNFaceCheckManagerRequestDelegate <NSObject>
@required

- (NSString *)systemTimestampForFaceCheck;

@end

@interface PAZNFaceCheckManager : NSObject

@property (nonatomic, weak) id<PAZNFaceCheckManagerDelegate>delegate;
@property (nonatomic, weak) id<PAZNFaceCheckManagerRequestDelegate> requestDelegate;
// 实名认证状态
@property (nonatomic, assign) PARealNameVerifyStatus verifyStatus;
@property (nonatomic, copy) NSString *userName;
@property (nonatomic, copy) NSString *timeInterval;

/// 校验类型
@property (nonatomic, assign) PAZNFaceCheckVerifyType verifyType;

/// 证件号码
@property (nonatomic, copy) NSString * realNaionalId;

+ (PAZNFaceCheckManager *)shareInstance;
- (void)initWithAppId:(NSString *)appId
               appKey:(NSString *)appKey
             deviceId:(NSString *)deviceId
             phoneNum:(NSString *)phoneNum
      displayPhoneNum:(NSString *)displayPhoneNum
displayInvisiblePhoneNum:(NSString *)displayInvisiblePhoneNum
           serverHost:(NSString *)serverHost
              openSSL:(BOOL)openSSL
     appServerVersion:(NSString *)appServerVersion
               userId:(NSString *)userId
                  sid:(NSString *)sid
      faceDetectorURL:(NSString *)faceDetectorURL
     faceCheckHelpURL:(NSString *)faceCheckHelpURL
   privacyProtocolURL:(NSString *)privacyProtocolURL
             language:(NSString *)language;

/// 设置头像，证件号码，用户名
/// @param userImg 头像
/// @param nationalId 证件号码
/// @param username 用户名
- (void)setUserImage:(NSString *)userImg
          nationalId:(NSString *)nationalId
            username:(NSString *)username;

- (BOOL)getFaceCheckConfig;
- (void)configFaceCheck:(BOOL)flag;

- (BOOL)getFaceLoginConfig;
- (void)configFaceLogin:(BOOL)flag;

- (BOOL)getCardFaceVerificationPermission;
-(void)configPermission:(BOOL)permission;

//检查是否采集过人脸
- (void)isSetFaceId;

//检查是否实名认证
- (void)isSetRealName;

//开启考试的人脸识别视图
- (void)openExamFaceView:(BOOL)flag;

//考试前的人脸验证
- (void)startExamFaceLoginWithSuccess:(PAZNFaceCheckCompletionBlock)completion;

//发起考试的人脸识别
- (void)startExamFaceRecognize:(NSString *)examId scoreId:(NSString *)scroreId success:(PAZNFaceCheckCompletionBlock)completion;

/// 课程，考试，智能陪练，培训班监学验证
/// @param completion 完成回调
- (void)superviseValidationBeforeStartWithCompletion:(void(^)(PAZNFaceCheckVerifyType type, NSError *error, BOOL result,NSString * realNaionalId))completion;


/// 人社资源学前认证
/// @param isLearnBeforeAuth 是否开启-学习前身份验证（0：否 1：是） ,
/// @param isRealNameVerify 是否选择-人员基本信息实名认证（0：否 1：是） ,
/// @param superVC 父控制器
/// @param completion 完成回调
- (void)societyCheckBeforeLearn:(BOOL)isLearnBeforeAuth isRealNameVerify:(BOOL)isRealNameVerify superViewController:(UIViewController *)superVC completion:(void(^)(BOOL succ, NSString *desc))completion;

/**
 查询实名认证状态接口

 @param completion - 回调
 */
- (void)requestRealNameVerifyStatueWithCompletion:(void(^)(NSError *error, NSDictionary *dict))completion;

- (void)setFaceCheckEnvironment:(PAZNFaceCheckEnvironment)environment;

- (void)configureAuthorizationWithUrl:(NSString *)urlStr AppKey:(NSString *)appKey AppId:(NSString *)appId;

- (void)setUserId:(NSString *)userId
              sid:(NSString *)sid
         phoneNum:(NSString *)phoneNum;

- (UIViewController *)faceCheckFailedPageWithCloseAction:(void (^)(void))close retryAction:(void (^)(void))retry;

@end
