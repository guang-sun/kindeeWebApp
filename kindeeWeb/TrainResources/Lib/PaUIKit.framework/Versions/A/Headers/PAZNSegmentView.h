//
//  PAZNSegmentView.h
//  PaCourseSdk
//
//  Created by 李锦华(平安科技集团系统开发部大学项目组) on 2019/5/27.
//  Copyright © 2019年 平安知鸟. All rights reserved.
//

#import <UIKit/UIKit.h>

@class PAZNSegmentView;

@protocol PAZNSegmentViewDelegate <NSObject>

- (void)segmentView:(PAZNSegmentView *)segmentView didScrollToIndex:(NSUInteger)index;

@end


@interface PAZNSegmentView : UIView

@property (nonatomic, assign) CGFloat itemWidth;
@property (nonatomic, strong) UIFont *itemFont;
@property (nonatomic, strong) UIFont *itemSelectFont;
@property (nonatomic, strong) UIColor *itemNormalColor;
@property (nonatomic, strong) UIColor *itemSelectColor;
@property (nonatomic, strong) UIColor *bottomLineColor;
@property (nonatomic, assign) CGFloat bottomLineWidth;
@property (nonatomic, assign) CGFloat bottomLineHeight;

@property (nonatomic, strong) NSArray <NSString *> *itemList;

@property (nonatomic, weak) id<PAZNSegmentViewDelegate> delegate;

- (void)scrollToIndex:(NSUInteger)index;

@end
