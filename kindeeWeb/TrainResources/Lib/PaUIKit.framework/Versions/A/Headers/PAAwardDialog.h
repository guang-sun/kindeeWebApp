//
//  PAAwardDialog.h
//  PADrawAwardModule
//
//  Created by 王斌(平安科技智慧教育团队项目研发部知鸟研发团队移动开发组) on 2018/8/28.
//  Copyright © 2018年 wans. All rights reserved.
//

#import <UIKit/UIKit.h>

@protocol PAAwardDialogProtocol <NSObject>

@optional
/**
 返回键盘弹出时，contentView对应键盘顶部的距离,避免键盘遮挡输入框
 
 @return 距离
 */
- (CGFloat)aboveKeyboardY;

@end

@interface PAAwardDialog : UIView

@property (nonatomic, assign) BOOL                                hideWhenTouchOutSide;

@property (nonatomic, strong) UIColor                             *shadowColor;

@property (nonatomic, assign) BOOL                                hideShadow;

@property (nonatomic, strong) UIView<PAAwardDialogProtocol>       *contentView;

@property (nonatomic, strong) id                                  extra;

- (void)show;

- (void)hide;

@end
