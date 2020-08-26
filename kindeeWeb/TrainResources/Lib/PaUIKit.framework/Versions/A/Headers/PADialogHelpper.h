//
//  PADialogHelpper.h
//  PADrawAwardModule
//
//  Created by 王斌(平安科技智慧教育团队项目研发部知鸟研发团队移动开发组) on 2018/8/28.
//  Copyright © 2018年 wans. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "PADialogAlertView.h"
#import "PAMVAlertView.h"

@class PAAwardDialog;

#define pa_showToast( text )  [PADialogHelpper showToastWithContent:text];

@interface PADialogHelpper : NSObject

/**
 显示alert对话框（默认）
 
 @param title 标题
 @param message 内容
 @param btnTitles 按钮titles
 @param btnAction 按钮事件
 */
+ (void)showAlertWithTitle:(NSString *)title message:(NSString *)message btnTitles:(NSArray *)btnTitles btnAction:(void(^)(PAAwardDialog *dialog, NSInteger index))btnAction;
+ (void)showAlertWithTitle:(NSString *)title message:(NSString *)message btnTitles:(NSArray *)btnTitles btnAction:(void(^)(PAAwardDialog *dialog, NSInteger index))btnAction option:(PADialogAlertOrder)option;

/**
显示alert对话框（扩展）

@param title 标题
@param message 内容过长时，可以滑动展示
@param btnTitles 按钮titles
@param btnAction 按钮事件
@param option 扩展
 
*/
+ (void)showMVAlertWithTitle:(NSString *)title message:(NSString *)message btnTitles:(NSArray *)btnTitles btnAction:(void(^)(PAAwardDialog *dialog, NSInteger index))btnAction;
+ (void)showMVAlertWithTitle:(NSString *)title message:(NSString *)message btnTitles:(NSArray *)btnTitles btnAction:(void(^)(PAAwardDialog *dialog, NSInteger index))btnAction option:(PAMVAlertOrder)optionBlock;

/**
 显示toast提示
 
 @param content 内容
 */
+ (void)showToastWithContent:(NSString *)content;
+ (void)showToastWithAttributedText:(NSAttributedString *)attributedText cornerRadius:(CGFloat)cornerRadius;
+ (void)showToastWithAttributedText:(NSAttributedString *)attributedText cornerRadius:(CGFloat)cornerRadius edgeInsets:(UIEdgeInsets)edgeInsets;
+ (void)showToastWithText:(NSString *)text cornerRadius:(CGFloat)cornerRadius;




@end


