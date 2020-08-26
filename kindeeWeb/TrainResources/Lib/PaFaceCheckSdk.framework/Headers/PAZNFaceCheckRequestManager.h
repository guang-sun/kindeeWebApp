//
//  PAZNFaceCheckRequestManager.h
//  PaFaceCheckSdk
//
//  Created by 胡铭(平安金融管理学院产品开发中心) on 2019/6/5.
//  Copyright © 2019 huming. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSInteger, FaceCheckStatusCode)
{
    FaceCheckCodeSuccess                = 0,
    FaceCheckCodeFaild                  = 1,
    FaceCheckCodeTimeOut                = 2,
    FaceCheckCodeParamWrong             = 3,
    FaceCheckCodeDecodeWrong            = 4,
    FaceCheckCodeUnknowPhone            = 5,
    FaceCheckCodeUnknowEmail            = 6,
    FaceCheckCodeWeChatUnbindPhone      = 7,
    FaceCheckCodeSmsCodeWrong           = 8,
    FaceCheckCodeCheckDevice            = 9,
    FaceCheckCodeMobileExsit            = 10,
    FaceCheckCodeMobileExsitAndEn       = 11,
    FaceCheckCodeAresForbid             = 12,
    FaceCheckCodeImageCheckFailed       = 13,
    FaceCheckCodeOtherErr               = 14,
};

NS_ASSUME_NONNULL_BEGIN

@interface PAZNFaceCheckRequestManager : NSObject

@property (nonatomic, copy) NSString *userName;
@property (nonatomic, copy) NSString *appId;
@property (nonatomic, copy) NSString *appKey;

//用户初始化人脸识别SDK
@property (nonatomic, copy) NSString *faceDetectorURL;
@property (nonatomic, copy) NSString *SeverHost;
@property (nonatomic, assign) BOOL OpenSSL;
@property (nonatomic, copy) NSString *appServerVersion;
@property (nonatomic, copy) NSString *userId;
@property (nonatomic, copy) NSString *sid;
@property (nonatomic, copy) NSString *deviceId;
//人脸识别帮助页面URL
@property (nonatomic, copy) NSString *faceCheckHelpURL;
@property (nonatomic, copy) NSString *privacyProtocolURL;

// 用于注册人脸
@property (nonatomic, copy) NSString *phoneNum;
@property (nonatomic, copy) NSString *displayPhoneNum;
@property (nonatomic, copy) NSString *displayInvisiblephoneNum;
@property (nonatomic, copy) NSString *password;
@property (nonatomic, copy) NSString *verCode;

@property (nonatomic, copy) NSString *nationalId; //证件号码
@property (nonatomic, strong) NSString *userImg;        //头像


+ (instancetype)shareInstance;

- (NSString *)getAppVersion;

- (NSString *)getDevicePlatform;

- (NSData *)image:(UIImage *)image compressWithMaxLength:(NSUInteger)maxLength;

/**
 上传人脸照片
 
 @param faceImage 照片
 @param completion 回调
 */
- (void)uploadFaceImage:(UIImage *)faceImage password:(NSString *)password phoneNum:(NSString *)phoneNum verCode:(NSString *)verCode completion:(void (^)(NSInteger code, NSString *errStr))completion;

/*
 智能陪练监学人脸注册接口不能传密码，验证码
 userType= "ITRAIN_PORTAL"
 */
- (void)uploadFaceImage:(UIImage *)faceImage userType:(NSString *)userType completion:(void (^)(NSInteger code, NSString *errStr))completion;

/**
 上传身份证照片
 
 @param image 照片
 @param completion 回调
 */
- (void)uploadIdentifyImage:(UIImage *)image completion:(void (^)(NSError *error, NSDictionary *dict))completion;

/**
 人脸和证件比对接口
 
 @param nationId - 身份证号
 @param name - 姓名
 @param image - 人脸采集的图片
 @param completion - 回调
 */
- (void)idComparisonWithNationalId:(NSString *)nationalId name:(NSString *)name faceImage:(UIImage *)image identifyImgPath:(NSString *)identifyImgPath fromSource:(NSString *)fromSource completin:(void (^)(NSError *, NSDictionary *))completion;

/// 外籍实名认证
/// @param idNumber 证件号
/// @param idType 证件类型
/// @param image 人脸图片
/// @param fromSource 来源
/// @param completion 完成回调
- (void)foreignVerifyWithIdNumber:(NSString *)idNumber idType:(NSString *)idType faceImage:(UIImage *)image fromSource:(NSString *)fromSource completin:(void (^)(NSError *err, NSDictionary *dict))completion;

/**
 转人工认证
 
 @param image - 人脸采集的图片
 @param completion - 回调
 */
- (void)applyArtificalVerifyWithImage:(UIImage *)image realName:(NSString *)realName nationalId:(NSString *)nationalId identifyImgPath:(NSString *)identifyImgPath fromSource:(NSString *)fromSource completion:(void (^)(NSError *error, NSDictionary *dict))completion;

/**
 查询实名认证状态接口
 
 @param completion - 回调
 */
- (void)requestRealNameVerifyStatueWithCompletion:(void(^)(NSError *error, NSDictionary *dict))completion;

- (void)getPersonDetailByUserID:(NSString *)userID isDetail:(BOOL)isDetail completion:(void (^)(NSError *err, NSDictionary *personInfo))completion;

//人脸验证
- (void)faceLoginWithFaceImage:(UIImage *)faceImage completion:(void(^)(NSInteger code, NSString *errStr))completion;


//员工身份证和实名认证身份证对比
- (void)compareNaionalIdWith:(NSString *)inputNaionalId completion:(void(^)(NSError *err, NSString *status,NSString *realNaionalId))completion;

//是否进入实名认证流程接口
- (void)requestRealNameIdentify:(void(^)(NSError *err, BOOL realNameIdentify))completion;

/// 获取个人信息
/// @param completion 完成回调
- (void)requestNewPersonDetailWithCompletion:(void (^)(BOOL succ, NSString *msg, NSDictionary *dict))completion;
@end

NS_ASSUME_NONNULL_END
