//
//  PAZNAlertView.h
//  PaPracticeSdk
//
//  Created by 周大俊(智慧教育) on 2019/4/23.
//  Copyright © 2019 w-chen. All rights reserved.
//

#import "PAPopupView.h"

NS_ASSUME_NONNULL_BEGIN

@interface PAZNAlertView : PAPopupView

@property (nonatomic, readonly, strong) UIButton *confirmButton;
@property (nonatomic, readonly, strong) UIButton *cancelButton;
@property (nonatomic, strong) UIColor *liveBtnThemeColor;

/// 大标题，调show方法之后初始化，设置有效
@property (nonatomic, readonly) UILabel *titleLabel;

/// 内容，调show方法之后初始化，设置有效
@property (nonatomic, readonly) UITextView *contentView;

- (instancetype)initWithTitle:(nullable NSString *)title
                  withContent:(nullable NSString *)content
                  withConfirm:(nullable NSString *)confirm
                   withCancel:(nullable NSString *)cancel
             withConfirmBlock:(nullable void (^)(void))confirmBlock
              withCancelBlock:(nullable void (^)(void))cancelBlock;

- (instancetype)initWithTitle:(nullable NSString *)title
     withRichContent:(nullable NSAttributedString *)content
     withVerticalPadding:(CGFloat)padding
     withConfirm:(nullable NSString *)confirm
      withCancel:(nullable NSString *)cancel
withConfirmBlock:(nullable void (^)(void))confirmBlock
 withCancelBlock:(nullable void (^)(void))cancelBlock;

- (instancetype)initWithLiveTitle:(nullable NSString *)title
                  withContent:(nullable NSString *)content
                  withConfirm:(nullable NSString *)confirm
                   withCancel:(nullable NSString *)cancel
             withConfirmBlock:(nullable void (^)(void))confirmBlock
              withCancelBlock:(nullable void (^)(void))cancelBlock;

- (instancetype)initWithTitle:(nullable NSString *)title
                  withContent:(nullable NSString *)content
                 withItemList:(NSArray *)itemList
                  withConfirm:(nullable NSString *)confirm
                   withCancel:(nullable NSString *)cancel
             withConfirmBlock:(nullable void (^)(void))confirmBlock
              withCancelBlock:(nullable void (^)(void))cancelBlock;

@end

NS_ASSUME_NONNULL_END
