//
//  PADialogAlertView.h
//  PADrawAwardModule
//
//  Created by 王斌(平安科技智慧教育团队项目研发部知鸟研发团队移动开发组) on 2018/9/10.
//  Copyright © 2018年 wans. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "PAAwardDialog.h"

@class PADialogAlertViewOption;

typedef void(^PADialogAlertOrder)(PADialogAlertViewOption *option);

@interface PADialogAlertViewOption : NSObject

@property (nonatomic, strong) UIColor         *titleColor;

@property (nonatomic, strong) UIColor         *messageColor;

@property (nonatomic, strong) UIColor         *firstBtnTitleColor;

@property (nonatomic, strong) UIColor         *secondBtnTitleColor;

@property (nonatomic, strong) UIColor         *contentBgColor;

@property (nonatomic, assign) CGFloat         width;

@property (nonatomic, assign) NSTextAlignment messageAlignment; //!< 内容是的对齐方式

@property (nonatomic, assign) NSTextAlignment titleAlignment; //!< title是的对齐方式

@property (nonatomic, strong) UIFont          *btnsFont; //!< 按钮文字的大小

@property (nonatomic, strong) UIFont          *titleFont; //!< title文字的大小

@property (nonatomic, strong) UIFont          *messageFont; //!< message文字的大小

@end

@interface PADialogAlertView : UIView<PAAwardDialogProtocol>

@property (nonatomic, strong) void (^btnAction)(NSInteger tag);

@end
