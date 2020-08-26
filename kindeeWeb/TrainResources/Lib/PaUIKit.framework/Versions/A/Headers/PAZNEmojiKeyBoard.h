//
//  PAZNEmojiKeyBoard.h
//  MLPlayer
//
//  Created by Cyril Zhou on 2017/4/12.
//  Copyright © 2017年 w. All rights reserved.
//

#import <UIKit/UIKit.h>

#define  kEmojiKeyboardHeight (225 + kIphoneBottomHeight)

@class PAZNEmojiKeyBoard;

@protocol PAZNEmojiKeyBoardDelegate <NSObject>

- (void)onTapSendBtn;
- (void)onTapDeleteBackward;
- (void)onTapInsertText:(NSString *)text;

@end

@interface PAZNEmojiKeyBoard : UIView

- (id)initWithFrame:(CGRect)frame withSendMode:(BOOL)sendMode;

@property (nonatomic, weak) id<PAZNEmojiKeyBoardDelegate> delegate;

@property (nonatomic, assign) BOOL buttonActionIsSend;// 按钮显示为发送或 删除， 默认删除

@end
