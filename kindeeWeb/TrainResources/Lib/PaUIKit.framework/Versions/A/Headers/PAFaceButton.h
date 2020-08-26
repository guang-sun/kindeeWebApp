//
//  FaceButton.h
//
//  Created by blue on 12-9-26.
//  Copyright (c) 2012年 blue. All rights reserved.
//  Email - 360511404@qq.com
//  http://github.com/bluemood
//

#import <UIKit/UIKit.h>
#import <QuartzCore/QuartzCore.h>

#define Emoji_Counts   115
//竖屏时一页的显示的表情数量
#define kFaceButtonVerticalPageSize 28
#define kFaceButtonVerticalLines 7
//横屏时一页的显示的表情数量
#define kFaceButtonHorizonalPageSize 48
#define kFaceButtonHorizonalLines 12

@protocol FaceEmojiViewDelegate;

@interface PAFaceButton : UIView{
    NSInteger _touchedIndex;   
}
@property (assign, nonatomic) id<FaceEmojiViewDelegate> delegate;
@property (retain, nonatomic) UIImage *image;
@property (assign, nonatomic) NSInteger touchedIndex;

+ (void)preparEmojiImages;

@end

@protocol FaceEmojiViewDelegate<NSObject>
@optional
/**
 *	点击开始点击到的emoji的 index位置
 *
 */
- (void)didTouchEmojiViewBeganIndex:(NSInteger)index;

/**
 *	点击移动时 更新气泡框最新位置的emoji表情
 *
 */
- (void)didTouchEmojiViewMovedIndex:(NSInteger)index;

/**
 *	点击手势结束，获取emoji表情在plist里的text文本
 *
 */
- (void)didTouchEmojiView:(PAFaceButton*)emojiView touchedEmoji:(NSString*)string;
@end
