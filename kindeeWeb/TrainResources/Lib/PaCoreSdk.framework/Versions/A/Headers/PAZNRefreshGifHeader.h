//
//  MJRefreshGifHeader.h
//  MJRefreshExample
//
//  Created by MJ Lee on 15/4/24.
//  Copyright (c) 2015年 小码哥. All rights reserved.
//

#import "PAZNRefreshStateHeader.h"

@interface PAZNRefreshGifHeader : PAZNRefreshStateHeader
@property (weak, nonatomic, readonly) UIImageView *gifView;

/** 设置state状态下的动画图片images 动画持续时间duration*/
- (void)setImages:(NSArray *)images duration:(NSTimeInterval)duration forState:(PAZNRefreshState)state;
- (void)setImages:(NSArray *)images forState:(PAZNRefreshState)state;
@end
