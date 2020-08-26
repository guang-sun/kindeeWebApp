//
//  PAZNEmojiUtility.h
//  MLPlayer
//
//  Created by Cyril Zhou on 2017/4/12.
//  Copyright © 2017年 w. All rights reserved.
//

#import <Foundation/Foundation.h>

static NSString *PAZNCustomEmojiPattern = @"\\[[^ \\[\\]]+?\\]";

@interface PAZNEmojiUtility : NSDictionary

@property (nonatomic, strong) NSDictionary *emoticonsdictionary;
@property (nonatomic, strong) NSDictionary *originsDictionary;

// 这个数组表示了表情的顺序和资源名(smiley_0),plist中key是占位符(/微笑),value是内部标记([smiley_0.png])
// originString = [NSString stringWithFormat:@"[%@.png]", emojiName]
@property (nonatomic, strong) NSArray *emojiNameArray;

+ (instancetype)sharedInstance;

+ (NSMutableAttributedString *)matchEmoticonInString:(NSString *)string
                                            fontSize:(CGFloat)fontSize
                                               color:(UIColor *)color;

@end
