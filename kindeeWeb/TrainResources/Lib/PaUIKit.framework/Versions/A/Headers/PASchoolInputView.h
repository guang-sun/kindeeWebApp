//
//  PASchoolInputView.h
//  MLPlayer
//
//  Created by temp on 2017/11/2.
//  Copyright © 2017年 w. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "HPGrowingTextView.h"
#import "PAFaceBoard.h"


UIKIT_EXTERN CGFloat const kPASchoolInputViewHeight;  //初始高度
UIKIT_EXTERN CGFloat const kSchoolAnimationDuration;

typedef NS_ENUM(NSInteger, PASLInputViewType) {
    PASLInputViewTypeComment,//评论输入
    PASLInputViewTypeEmoji,//表情输入
    PASLInputViewTypeImpression,//直播印象输入
};


@protocol PASchoolInputViewDelegate;


/**
 评论输入框View
 */
@interface PASchoolInputView : UIView<HPGrowingTextViewDelegate,PAFaceBoardDelegate>

/// 是否显示直播印象按钮
@property (nonatomic, assign) BOOL showImpression;

/// 输入框类型
@property (nonatomic, assign) PASLInputViewType inputType;

/*!
 @brief     键盘高度
 */
@property (nonatomic, assign) CGFloat keyBoardHeight;

/// 输入框
@property (nonatomic, strong) HPGrowingTextView * inputField;

/**最小必须提交的个数，默认：5
 */
@property (nonatomic, assign) NSInteger minInputLength;

/// 代理
@property (nonatomic, weak) id<PASchoolInputViewDelegate> delegate;

/// 输入内容
@property (nonatomic, strong) NSString * inputText;

@property (nonatomic, strong) NSString * inputId;

/// 是否第一响应者
@property (nonatomic, assign) BOOL bFirstResponder;

/// y坐标偏移量
@property (nonatomic, assign) CGFloat offsetY;


/// 初始化
/// @param ignoreHeightTop 忽略顶部高度
- (instancetype)initWithIgnoreHeightTop:(CGFloat)ignoreHeightTop;

/// 占位文案
/// @param text 文案
- (void)setPlaceholderText:(NSString*)text;

/// 开始编辑
- (void)beginEditingInputField;

/// 取消编辑
- (void)resignInputField;

/// 设置文本样式
- (void)setTextStyle;

/// 重置输入
- (void)resetInput;

/// 刷新直播印象数据
/// @param source 数据源
/// e.g. @[@{
/// @"id":@"labelId",//标签id
/// @"labelLevel":@"labelLevel",//标签细分等级[0-6]很差；[7-8]一般；[9-10]很好；
/// @"mainLevel":@"mainLevel",//标签等级大分类， 1：[0-6]很差；2：[7-8]一般；3：[9-10]很好；
/// @"label":@"label"//标签名
///}];
- (void)refreshImpressions:(NSArray *)source;

- (void)addNotification;
- (void)removeNotification;
@end



@protocol PASchoolInputViewDelegate <NSObject>

/** 发送按钮点击
 */
- (void)inputView:(PASchoolInputView*)inputView commit:(NSString*)commitText;

@optional
- (BOOL)inputViewShouldBeginEditing:(HPGrowingTextView*)textField;

-(BOOL)inputViewView:(HPGrowingTextView *)growingTextView shouldChangeTextInRange:(NSRange)range replacementText:(NSString *)text;

- (void)changgeTextWithInputView:(PASchoolInputView *)inputView;

/// 选择印象标签
/// @param impression 直播印象数据
- (void)selectImpression:(NSDictionary *)impression;

/// 取消第一响应者
- (void)resignInputView;
@end
