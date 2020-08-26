//
//  PAZNCourseSignatureView.h
//  PaCourseSdk
//
//  Created by 李锦华(平安科技集团系统开发部大学项目组) on 2019/5/21.
//  Copyright © 2019年 平安知鸟. All rights reserved.
//

#import <UIKit/UIKit.h>

#define kSignatureNotRemindKey @"signatureNotRemind" //电子签名-不再提醒


@interface PAZNCourseSignatureView : UIView

//已签名的照片,跳转传入 -- 课程签名已经完成，查看签名。
@property(nonatomic, strong) UIImage *signImage;

// 签名笔划宽度，默认3.3
@property(nonatomic, assign) CGFloat lineWidth;

//签名完成的回调Block,签名图片
@property(nonatomic, copy) void(^signComplete)(UIImage *signImage);

//清除Blcok,可调用- (void)clearSignature;进行清除已有签名
@property(nonatomic, copy) void(^signClear)(void);

//取消签名回调
@property(nonatomic, copy) void(^signCancel)(void);

//不再提醒回调
@property(nonatomic, copy) void(^signNotRemindBlock)(BOOL isSelected);

//清除签名
-(void)clearSignature;

@end
