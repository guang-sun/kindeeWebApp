//
//  MessageView.h
//  PAFaceBoardDome
//
//  Created by kangle1208 on 13-12-12.
//  Copyright (c) 2013年 Blue. All rights reserved.
//


#import <UIKit/UIKit.h>

#import <CoreText/CoreText.h>
#define KCharacterWidth     7

#define VIEW_LINE_HEIGHT    [@":-D" sizeWithAttributes:@{NSFontAttributeName:[UIFont systemFontOfSize:18]}].height

#define VIEW_LEFT           0

#define VIEW_TOP            2

#define VIEW_WIDTH_MAX      (230/UI_iphone5_WIDTH)*UI_IOS_WINDOW_WIDTH

#define FACE_ICON_NAME      @"^[0][0-8][0-5]$"
#define EmotionItemPattern         @"\\[[a-zA-Z0-9\\u4e00-\\u9fa5]+\\]"
#define BEGIN_FLAG @"["
#define END_FLAG @"]"
#define PlaceHolder                 @" "
#define EmotionFileType             @"png"
#define AttributedImageNameKey      @"ImageName"

#define EmotionImageWidth           21
#define FontHeight                  14
#define ImageLeftPadding            0.0
#define ImageTopPadding             2.0


@interface PAMessageView : UIView {

    CGFloat upX;

    CGFloat upY;

    CGFloat lastPlusSize;

    CGFloat viewWidth;

    CGFloat viewHeight;

    BOOL isLineReturn;
    
    NSDictionary *_faceMap;
    
    CGSize msgSize;
    
    NSString *wideString;
    
}
//字体颜色
@property (nonatomic,strong) UIColor * fontColor;

//字体大小
@property (nonatomic) CGFloat fontSize;

//行间距
@property (nonatomic) CGFloat lineSpace;

/**文本要显示的宽度，动态计算高度，必须赋值
 */
@property (nonatomic) CGFloat maxWidth;

// 处理过后的用户绘图的富文本字符串
@property (nonatomic, retain) NSMutableAttributedString *attrEmotionString;

// 按顺序保存的 emotionString 中包含的表情名字
@property (nonatomic, retain) NSMutableArray *emotionNames;
@property (nonatomic, retain) NSDictionary *faceMap;

@property (nonatomic, retain) NSArray *emotionRanges;

@property (nonatomic, retain) NSMutableDictionary *emojiRanges;

@property (nonatomic, retain) NSMutableArray *messageRange;

@property (nonatomic, retain) NSString *text;
@property (nonatomic, assign) CGSize messageSize;

CTRunDelegateRef newEmotionRunDelegate(void);

- (void)setText:(NSString *)message;

- (CGSize)getContentSizeWithMessage:(NSString *)message;

- (id)initWithFrame:(CGRect)frame emotionString:(NSString *)emotionString;

- (void)getMessageRange:(NSString*)message :(NSMutableArray*)array;

- (NSUInteger)getstringContainsEmojiCount:(NSString *)string index:(NSInteger)_index;

/// 将 emotionString 中的特殊字符串替换为空格
// @discussion 不要直接调用此方法
- (void)cookEmotionString;

@end
