//
//  PAUIAnimationTool.h
//  MLPlayer
//
//  Created by txt on 15/6/20.
//  Copyright (c) 2015年 w. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSInteger, UIErrAnimationType){
    ENotSupportOffline = 1,//不支持离线模式
    
    EProtocolFormatError = 7,//协议格式错误
    
    EUnknownFormat = 6,//未知格式
    
    ENotSupportFormat = 5,//不支持格式
    
    ENothing = 4,//对获取数据的请求处理正确，但没有符合条件的结果返回
    
    EPartialContent = 3,//只返回了请求数据中的一部分
    
    ENetTimeout = 2,//请求超时
    
    ENetDisconnect = 1,//网络连接异常
    
    ESuccess = 0,//成功
    
    EUnknownError = -1,//服务器发生未定义的错误
    
    EUserOrPassError = -10,//用户名或密码错误
    
    EVersionError = -3,//版本不被服务器支持
    
    EKicked = -4, //被T了
    
    ESmscode = -5,//短信授权码不正确
    
    ECer = -6, //登录签证不正确
    
    EAlreadyDone = -7, //已完成，已提交
    
    EParams = -8, //参数错误
    
    EUserusing = -12,//用户已经登录，不允许重复登录
    
    EUserdisabled = -13,//用户已被禁用
    
    EDuplicaterating = -14,//不允许重复评价课程
    
    EIsGone = -15, //状态已改变
    
    EBound = -16,//帐号已绑定其它设备
};


@interface PAUIAnimationTool : NSObject

+(void)ShowActivityIndicator:(UIView*)view at:(CGPoint)pos;
+(void)ShowActivityIndicator:(UIView*)view;
+(void)DisimissActivityIndicator;

+(void)ShowAlert:(NSString*) text;
+(void)ShowError:(int)Result;
+(void)ShowTextLoading:(NSString*)text;
+(void)dimissAlertView;
+(void)ShowAlertWithStr:(NSString*)text stayTime:(int)stayTime;

@end
