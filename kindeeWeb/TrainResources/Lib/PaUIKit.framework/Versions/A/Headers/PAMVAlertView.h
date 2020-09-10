//
//  PAMVAlertView.h
//  PADrawAwardModule
//
//  Created by 王斌(平安科技智慧教育团队项目研发部知鸟研发团队移动开发组) on 2018/9/10.
//  Copyright © 2018年 wans. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "PAAwardDialog.h"

@class PAMVAlertViewOption;

typedef void(^PAMVAlertOrder)(PAMVAlertViewOption *option);

@interface PAMVAlertViewOption : NSObject

@property (nonatomic, strong) UIColor         *titleColor;

@property (nonatomic, strong) UIColor         *messageColor;

@property (nonatomic, strong) UIColor         *firstBtnTitleColor;

@property (nonatomic, strong) UIColor         *secondBtnTitleColor;

@property (nonatomic, strong) UIColor         *firstBtnBackgroundColor;

@property (nonatomic, strong) UIColor         *secondBtnBackgroundColor;

@property (nonatomic, strong) UIColor         *firstBtnBorderColor;

@property (nonatomic, strong) UIColor         *secondBtnBorderColor;

@property (nonatomic, strong) UIColor         *contentBgColor;

@property (nonatomic, assign) CGFloat         width;

@property (nonatomic, assign) NSTextAlignment messageAlignment; //!< 内容是的对齐方式

@property (nonatomic, assign) NSTextAlignment titleAlignment; //!< title是的对齐方式

@property (nonatomic, strong) UIFont          *btnsFont; //!< 按钮文字的大小

@property (nonatomic, strong) UIFont          *titleFont; //!< title文字的大小

@property (nonatomic, strong) UIFont          *messageFont; //!< message文字的大小

@property (nonatomic, assign) BOOL            hideWhenTouchOutSide;

@property (nonatomic, assign) CGFloat         titleTop;

@property (nonatomic, assign) CGFloat         messageToTop;

@property (nonatomic, assign) CGFloat         btnsToTop;

@property (nonatomic, assign) CGFloat         btnsToBottom;

@property (nonatomic, assign) CGFloat         btnsHeight;

@end

@interface PAMVAlertView : UIView

@property (nonatomic, strong) void (^btnAction)(NSInteger tag);

@end
