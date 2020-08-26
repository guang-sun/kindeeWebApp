//
//  PAZNEmojiCollectionViewCell.h
//  MLPlayer
//
//  Created by Cyril Zhou on 2017/4/12.
//  Copyright © 2017年 w. All rights reserved.
//

#import <UIKit/UIKit.h>

@class PAZNEmojiCell;

@interface PAZNEmojiCell : UICollectionViewCell

@property (nonatomic, strong) NSString *emojiName;

- (void)setEmojiNameWithIndex:(NSUInteger)index;

@end
