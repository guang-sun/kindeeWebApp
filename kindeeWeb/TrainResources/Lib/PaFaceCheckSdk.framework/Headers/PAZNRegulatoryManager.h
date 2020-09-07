//
//  PAZNRegulatoryManager.h
//  PaFaceCheckSdk
//
//  Created by 李锦华(平安科技集团系统开发部大学项目组) on 2020/7/20.
//  Copyright © 2020 huming. All rights reserved.
//  监管平台

#import <Foundation/Foundation.h>
#import "PAFaceCheckEnum.h"

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, PAZNFCRegulatoryErrorCode) {
    PAZNFCRegulatoryErrorCode_Exit = -100,   //手动关闭验证页面退出
    PAZNFCRegulatoryErrorCode_Nonentity = 10000,  //学员信息不存在
    PAZNFCRegulatoryErrorCode_NoPermission = 10001, //非本课程参训学员
};


@interface PAZNRegulatoryManager : NSObject

/// 扩展信息
@property (nonatomic, strong,nullable) NSDictionary *extraInfo;

+ (instancetype)shareInstance;

+ (void)destory;

/**
初始化SDK环境
@param Env SDK环境(必填)
@param appId - 申请接入监管平台所用的bundleId(必填)
@return 是否成功，
@discussion
1.一般在app delegate的didFinishLaunching设置
*/
-(BOOL)initSdkWithEnvironment:(PAZNRegulatorySdkEnvironment)Env
                        appId:(NSString *)appId;

/**
设置用户信息
@param idCardType - 证件类型，类型入参请参照枚举值(必填)
@param userName  - 姓名(必填)
@param cardId - 证件号码(必填)
@discussion
1.在监管项目学习之前设置
*/
-(void)configUserInfo:(IDCardType)idCardType
             userName:(NSString *)userName
               cardId:(NSString *)cardId;


/**
监管项目学习之前的检查
@param trainingId - 监管项目id(必填)
@param timestamp  - 时间戳
@param nonce - 依据文档传入
@param sign - 依据文档生成传入
@param currentViewController - 接入方调用该api所处的当前页面
@param completion - 监管SDK回调给接入方检查是否通过，通过时回调该监管项目的抽查id、监管类型。
@discussion
1.在监管项目学习之前设置
*/
-(void)checkBeforeTraining:(NSString *)trainingId
                 timestamp:(NSString *)timestamp
                     nonce:(NSString *)nonce
                      sign:(NSString *)sign
                 currentVC:(UIViewController *)currentViewController
                completion:(void (^__nullable)(NSError *__nullable error,BOOL checkPass,NSString * __nullable comesBackToken))completion;


/**
 监管SDK回调完成后调用，即上面的方法的completion回调后执行。
 @discussion
 1.在监管项目回调之后调用
*/
-(void)resetRegulatoryData;

@end

NS_ASSUME_NONNULL_END
