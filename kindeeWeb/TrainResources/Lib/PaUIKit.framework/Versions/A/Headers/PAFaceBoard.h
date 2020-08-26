//
//  PAFaceBoard.h
//
//  Created by blue on 12-9-26.
//  Copyright (c) 2012年 blue. All rights reserved.
//  Email - 360511404@qq.com
//  http://github.com/bluemood

#import <UIKit/UIKit.h>
#import "PAFaceButton.h"

@protocol PAFaceBoardDelegate <NSObject>

@optional

- (void)textViewDidChange:(UITextView *)textView;

- (void)chooseAFace;

- (void)deleteAFace;

- (void)sendMsg;

@end

@interface PAFaceBoard : UIView<UIScrollViewDelegate,FaceEmojiViewDelegate>{
    UIScrollView *faceView;
    UIPageControl *facePageControl;
    NSDictionary *_faceMap;
}
@property (nonatomic, assign) id<PAFaceBoardDelegate> delegate;

@property (nonatomic, retain) UITextField *inputTextField;
@property (nonatomic, retain) UITextView *inputTextView;

/*!
 @brief     发送按钮
 */
@property (nonatomic, retain) UIButton *sendButton;

+ (PAFaceBoard*)sharedPAFaceBoard;

//表情键盘删除键
- (void)backFace;

- (void)setButtonSelectedState:(BOOL)isSelected;

@end
