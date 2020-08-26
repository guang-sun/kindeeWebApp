//
//  PAFaceCheckEnum.h
//  PaFaceCheckSdk
//
//  Created by 黄漫(智慧城市总部成人教育事业部研发部移动端开发团队) on 2020/8/12.
//  Copyright © 2020 huming. All rights reserved.
//

#ifndef PAFaceCheckEnum_h
#define PAFaceCheckEnum_h

//不晓得后面会加啥人社
typedef NS_ENUM(NSInteger, PAFCSocietyType) {
    //通用人社
    PAFCSocietyTypeCommon,
};

typedef NS_ENUM(NSInteger, PAFaceBusinessType){
    PAFaceBusinessType_FaceCheck = 0,       ///< 人脸识别
    PAFaceBusinessType_RealName,            ///< 实名认证
    PAFaceBusinessType_FaceLogin,           ///< 人脸登录
    PAFaceBusinessType_Home,                ///< 人脸主页
};

typedef NS_ENUM(NSInteger, PAFaceFromType){
    PAFaceFromType_SecurityCenter = 1<<1, ///< 安全中心
    PAFaceFromType_Society = 1<<2,
    PAFaceFromType_Other = 1<<3,          ///< 非安全中心
};

typedef NS_ENUM(NSUInteger, FCErrorCode) {
    FCErrorCode_success = 0,            ///< 成功
    FCErrorCode_detectorTimeOut = 1     ///< 检测超时
};

//PAZNFaceCheckSource 使用人脸功能模块
typedef NS_ENUM(NSInteger, PAZNFaceCheckSourceType) {
    //直播间监学，
    //能进入普通直播间的父控制器较多，
    //根据superViewController判断较为复杂,
    PAZNFaceCheckSourceTypeLive,
    //安全中心人脸登录
    PAZNFaceCheckSourceTypeSecurity,
    //学堂直播
    PAZNFaceCheckSourceTypeSchoolLive,
    //考试
    PAZNFaceCheckSourceTypeExam,
    //陪练
    PAZNFaceCheckSourceTypePracticeRobot,
    //培训班签到
    PAZNFaceCheckSourceTypeTCSignIn,
    //课程学习
    PAZNFaceCheckSourceTypeStudyCourse,
    //安全中心实名认证
    PAZNFaceCheckSourceTypeSecurityRealName,
    //课程抽查
    PAZNFaceCheckSourceTypeCourseCheck
};

typedef NS_ENUM(NSInteger, PAZNFaceCheckVerifyType) {
    PAZNFaceCheckVerifyType_continue = 1<<1,
    PAZNFaceCheckVerifyType_RealName = 1<<2,
    PAZNFaceCheckVerifyType_FaceCheck = 1<<3,
    PAZNFaceCheckVerifyType_ManualVerify = 1<<4,
    PAZNFaceCheckVerifyType_netWrong = 1<<5,
    PAZNFaceCheckVerifyType_noMatch = 1<<6,
    PAZNFaceCheckVerifyType_error = 1<<7,
};

typedef NS_ENUM(NSInteger, PAZNFaceCheckEnvironment)
{
    PAZNFaceCheckEnvironmentPrd = 0,       //生产环境
    PAZNFaceCheckEnvironmentStg1 = 1,      //测试环境1
    PAZNFaceCheckEnvironmentStg5 = 5,      //测试环境5
};

typedef NS_ENUM(NSInteger, PARealNameVerifyStatus) {
    PARealNameVerifyStatus_none = -2,       ///< 默认
    PARealNameVerifyStatus_failed = -1,     ///< 失败
    PARealNameVerifyStatus_notVerify,       ///< 未认证
    PARealNameVerifyStatus_alreadyVerify,   ///< 已经认证
    PARealNameVerifyStatus_manualVerify,    ///< 人工认证中
};

//身份与员工信息比对错误码
typedef NS_ENUM(NSInteger, PAValidationIdentityErrorCode) {
    PAValidationIdentityStatus_noPermission = -1,///< 未开通权限
    PAValidationIdentityStatus_notVerifyRealName,///< 尚未实名认证
    PAValidationIdentityStatus_verifymanualVerify, //人工认证中
    PAValidationIdentityStatus_netWrong,         ///< 网络错误
};

typedef NS_ENUM(NSInteger, PAIdComparisonStatus) {
    PAIdComparisonStatus_success                    = 2300000,      ///< 成功
    PAIdComparisonStatus_recFailed                  = 2340010,      ///< 卡证内容识别失败
    PAIdComparisonStatus_verifyNoPass               = 2340101,      ///< 认证未通过
    PAIdComparisonStatus_wrongName                  = 2340102,      ///< 姓名格式不正确，不能为空
    PAIdComparisonStatus_wrongId                    = 2340103,      ///< 身份证号码有误
    PAIdComparisonStatus_idNoExist                  = 2340105,      ///< 身份证号不存在
    PAIdComparisonStatus_noFace                     = 2340201,      ///< 没有识别到人脸
    PAIdComparisonStatus_sizeLimit                  = 2340301,      ///< 图片太大
    PAIdComparisonStatus_imageFuzzy                 = 2340302,      ///< 图片模糊
    PAIdComparisonStatus_belowStandard              = 2340303,      ///< 质量不通过
    PAIdComparisonStatus_analyseImageFailed         = 2340304,      ///< 图片解析错误
    PAIdComparisonStatus_unliving                   = 2340401,      ///< 非活体
    PAIdComparisonStatus_noBottomImage              = 2340501,      ///< 底图不存在
    PAIdComparisonStatus_analyseBottomImageFailed   = 2340502,      ///< 底图解析错误
};

typedef NS_ENUM(NSInteger, PAZNRegulatorySdkEnvironment)
{
    PAZNRegulatorySdkEnvironmentPrd = 0,       //生产环境
    PAZNRegulatorySdkEnvironmentTest = 1,      //测试环境
};

//证件类型
typedef NS_ENUM(NSInteger, IDCardType) {
    IDCardTypeMainland = 1<<1,            //大陆身份证
    IDCardTypeRegionsPass = 1<<2,         //港澳台居民来往大陆通行证
    IDCardTypeForeignPassport = 1<<3,     //护照
    IDCardTypeRegionsPermit = 1<<4,       //港澳台居民居住证
    IDCardTypeForeignPermit = 1<<5,       //外国人永久居留身份证
    IDCardTypeOther = 1<<6,               //其他证件
};

//监管平台后台-接口错误码
typedef NS_ENUM(NSInteger, PAZNRegulatoryRequestCode) {
    PAZNRegulatoryCode_success = 200,             //成功
    PAZNRegulatoryCode_withoutPermission = 10001, //未在培训班内
    PAZNRegulatoryCode_excessive = 10009,         //验证或实名超过次数
    PAZNRegulatoryCode_cardIdIsNull = 10015,      //证件号码为空
    PAZNRegulatoryCode_maintenance = 10016,       //系统维护
    PAZNRegulatoryCode_trainingEnd = 10017,       //已结训
};

//人社认证状态
typedef NS_ENUM(NSInteger, PAFCSocietyStatus) {
    PAFCSocietyStatus_none = -2,       ///< 默认
    PAFCSocietyStatus_failed = -1,     ///< 失败
    PAFCSocietyStatus_manualVerify,    ///< 人工认证中
    PAFCSocietyStatus_cancel,          ///< 取消
    PAFCSocietyStatus_succ,            ///< 认证流程成功
};

#endif /* PAFaceCheckEnum_h */
