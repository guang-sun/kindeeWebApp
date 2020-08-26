//
//  PAZNCourseSignatureViewController.h
//  PaCourseSdk
//
//  Created by 李锦华(平安科技集团系统开发部大学项目组) on 2019/5/21.
//  Copyright © 2019年 平安知鸟. All rights reserved.
//  电子签名

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface PAZNCourseSignatureViewController : UIViewController
@property(nonatomic,copy) NSString *courseId;

//签名完成的回调Block,签名图片
@property(nonatomic, copy) void(^signComplete)(UIImage *signImage);

@end

NS_ASSUME_NONNULL_END
