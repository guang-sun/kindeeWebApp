//
//  PAZNFaceDetectorManager.h
//  PaFaceCheckSdk
//
//  Created by huming on 2018/5/29.
//  Copyright © 2018年 huming. All rights reserved.
//

#import <AVFoundation/AVFoundation.h>
#import <UIKit/UIKit.h>
#import "PAZNFCLivenessDetectionFrame.h"

/**
 Environmental ErrorEnum
 */
typedef NS_ENUM(NSInteger, PAZNEnvironmentalErrorEnum) {
    PAZN_EnvironmentalTip_NORMAL = 2001,    //正常
    PAZN_EnvironmentalTip_NO_FACE  ,        //没有人脸
    PAZN_EnvironmentalTip_MULTI_FACE ,      //多人脸存在
    PAZN_EnvironmentalTip_NOCENTER,         //请正对采集框
    PAZN_EnvironmentalTip_YAW_LEFT,         //人脸过于偏左
    PAZN_EnvironmentalTip_YAW_RIGHT,        //人脸过于偏右
    PAZN_EnvironmentalTip_PITCH_UP,         //人脸过于仰头
    PAZN_EnvironmentalTip_PITCH_DOWN,       //人脸过于低头
    PAZN_EnvironmentalTip_ROLL_LEFT,        //人脸过于偏左歪头
    PAZN_EnvironmentalTip_ROLL_RIGHT,       //人脸过于偏右歪头
    PAZN_EnvironmentalTip_TOO_DARK ,        //人脸过于灰暗
    PAZN_EnvironmentalTip_TOO_BRIGHT ,      //人脸过于亮
    PAZN_EnvironmentalTip_TOO_FUZZY ,       //模糊值过高
    PAZN_EnvironmentalTip_TOO_CLOSE,        //人脸过近
    PAZN_EnvironmentalTip_TOO_FAR ,         //人脸过于远
    PAZN_EnvironmentalTip_ILLEGAL,          //非法人脸警告
    PAZN_EnvironmentalTip_MOVEMENT,         //请保持相对静止
    PAZN_EnvironmentalTip_MOUTHOPEN,        //请不要张着嘴
    PAZN_EnvironmentalTip_EYECLOSE,         //请不要闭着眼
    PAZN_EnvironmentalTip_COVERFACE,        //请不要遮挡脸部
    PAZN_EnvironmentalTip_COVEREYE,         //请不要遮挡眼部
    PAZN_EnvironmentalTip_COVERMOUTH,       //请不要遮挡嘴部
};

/*!
 *  \enum PACFLivenessDetectionType
 *  \brief 检测类型选项
 */
typedef NS_ENUM (NSInteger,PAZNFaceDetectType) {
    PAZNFaceDetectType_NORMAL      = 1001,    //正脸--必须--合格
    PAZNFaceDetectType_MouthOpen ,            //张嘴---选择
    PAZNFaceDetectType_EyeBlink ,             //眨眼---选择
    PAZNFaceDetectType_HeadShank,             //摇头---选择
    PAZNFaceDetectType_LeftShank,             //摇头左---选择
    PAZNFaceDetectType_RightShank             //摇头右---选择
};

/*!
 *  此接口通过 PALivenessDetector 的 setDelegate 函数进行注册，在活体检测的过程中会经由不同的事件触发不同的回调方法
 */
@protocol PAFCLivenessProtocolDelegate <NSObject>

@required

/**
 每一帧数据
 
 @param perFrame 每一帧相对于的帧数据
 */
-(void)PAZN_OnDetectFrame:(PAZNFCLivenessDetectionFrame *)perFrame;

/*!
 *  当前活体检测的环境与用户操作监控
 *  @param tipType 返回环境与用户操作 不妥当的地方
 */
-(void)PAZN_OnDetectTip:(PAZNEnvironmentalErrorEnum)tipType;

/*!
 *  当前活体检测的动作检测成功时，调用此方法
 *  @param validFrame 当前动作中采集的质量最好帧。
 */
- (void)PAZN_OnDetectionSuccess:(PAZNFCLivenessDetectionFrame *)validFrame currentFaceDetectionState:(PAZNFaceDetectType)currentState;

@optional

/*!
 *  相机授权处理（sdk中提供相机用到）
 */
- (void)PAPermissionOfCamer:(AVAuthorizationStatus)camerState;

/*!
 *  视频流处理的回调，相机获得的视屏流会传出来（使用sdk提供相机需要）
 */
- (void)PAZNCaptureOutput:(AVCaptureOutput *)captureOutput
    didOutputSampleBuffer:(CMSampleBufferRef)sampleBuffer
           fromConnection:(AVCaptureConnection *)connection;

@end


@interface PAZNFaceDetectorManager : NSObject

@property (nonatomic, assign) BOOL authorSuccess;
@property (nonatomic, assign, readonly) BOOL liveSwitch;
@property (nonatomic, weak) id<PAFCLivenessProtocolDelegate> delegate;


+ (instancetype)sharedInstance;
/**
 设置语言

 @param language - 语言
 */
+ (void)configLanguage:(NSString *)language;

/**
 授权,需要先查询授权，再调用下面的初始化接口
 
 @param urlStr 授权url
 @param appKey 业务key
 @param appId 业务id
 @param completion 回调
 */
+ (void)applicationAuthorizationWithUrl:(NSString *)urlStr AppKey:(NSString *)appKey AppId:(NSString *)appId completion:(void(^)(NSString *code, NSString *msg))completion;

/**
 初始化方法所需的options参数，方案一:随机两种动作+静默活体+后端活体

 @return options
 */
+ (NSDictionary *)planADefaultParameters;

/**
 初始化方法所需的options参数，方案二:随机两种动作+后端活体
 
 @return options
 */
+ (NSDictionary *)planBDefaultParameters;

/**
 自定义检测方案

 @param detectTypeArray PAZNFaceDetectType数组,空为只检测静默活体
 @return options
 */
+ (NSDictionary *)customParametersWithDetectTypeArray:(NSArray *)detectTypeArray;

/**
 初始化
 
 @param facedelegate 代理
 @return obj
 */
+ (PAZNFaceDetectorManager *)initDetectorWithBundleName:(NSString *)bundleName detectorOfOptions:(NSDictionary*) options andSetDelegate:(id<PAFCLivenessProtocolDelegate>)facedelegate completion:(void(^)(BOOL success))completion;


/*!
 *  获取版本信息
 *
 *  @return 版本描述
 */
+ (NSString *)getVersion;

/**如果不需要日记回传 则不需要
 设置业务配置
 
 @param app_id appid
 @param app_key appkey
 */
+(void)setApp_id:(NSString *)app_id setApp_key:(NSString *)app_key url:(NSString*)baseUrl success:(void(^)(id responseObject))success  failure:(void(^)(NSError *error))failure;

/**
 *  初始化相机方法
 *  相机可自定义，则无需调用此方法
 */
- (void)createCamerManager;

/**
    检查相机权限
 */
- (void)checkCameraPermission;

/**
 *  视频流的预览layer 默认全屏大小
 *
 *  @return 实例化对象
 */
- (AVCaptureVideoPreviewLayer *)videoPreview;

/**
 设置方向

 @param currentOrientation - 当前方向
 */
- (void)setupOrientation:(UIDeviceOrientation)currentOrientation;

/**
 开启视频流同时开启人脸采集
 */
- (void)startRunning;

/**
 关闭视频流同时关闭人脸采集
 */
- (void)stopRunning;

/**
 关闭人脸采集，不关闭视频流
 */
- (void)stopDetect;
/**
 将视频流传入检测器进行异步活体检测，检测结果将以异步的形式通知delegate
 
 @param sampleBuffer 视频流
 */
-(void)detectWithBuffer:(CMSampleBufferRef)sampleBuffer orientation:(UIDeviceOrientation)orientation;

/**
 重置Detector类的状态，当用户需要重新开始活体检测流程时，调用此函数。 *
 
 @param detectionType 强制更改当前的活体检测类型 具体选项请参照 PAFaceDetectType
 @param compareSwitch 是否与前一帧做校对 防止非连续攻击
 @param liveSwitch 是否开启非连续
 */
-(void)resetWithFaceDetectType:(PAZNFaceDetectType)detectionType compareVerifySwitch:(BOOL)compareSwitch liveVerifySwitch:(BOOL)liveSwitch;

/**如果不需要日记回传 则不需要
添加日记监控
*/
-(void)addLogNotification;

/**如果不需要日记回传 则不需要
 删除日记监控
 */
-(void)removeLogNotification;

/**如果不需要日记回传 则不需要
 写入日记
 @param text log信息
 */
-(void)fileHandleForWriting:(NSString *)text;

/**如果不需要日记回传 则不需要
 是否保存日记
 
 @param isSave yes保存 no废弃
 */
-(void)whetherOrNotSave:(BOOL)isSave;
@end
