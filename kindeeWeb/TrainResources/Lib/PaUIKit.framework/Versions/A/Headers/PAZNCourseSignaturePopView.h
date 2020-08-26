//
//  PAZNCourseSignaturePopView.h
//  PaCourseSdk
//
//  Created by 李锦华(平安科技集团系统开发部大学项目组) on 2019/5/20.
//  Copyright © 2019年 平安知鸟. All rights reserved.
//

#import <UIKit/UIKit.h>

typedef NS_ENUM(NSInteger, SignatureType)
{
    SignatureType_Course = 0,  //课程签名
    SignatureType_Exam = 1,    //考试签名
};

@interface PAZNCourseSignaturePopView : UIView

- (instancetype)initWithFrame:(CGRect)frame
                     signType:(SignatureType)type
                       fromVc:(UIViewController *)fromVc
                       cancel:(void(^)(void))cancelBlock
                     makeSure:(void(^)(void))sureBlock;

- (void)show;

- (void)disMiss;
@end
