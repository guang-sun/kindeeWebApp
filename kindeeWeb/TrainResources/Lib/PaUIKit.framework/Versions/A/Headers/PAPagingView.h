//
//  PAPagingView.h
//  PaUIKit
//
//  Created by 周大俊(智慧教育) on 2019/3/12.
//  Copyright © 2019年 周长川(智慧教育). All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, PAPagingViewSegmentLayoutStyle){
    PAPagingViewSegmentLayoutStyleAverageScreen,//屏幕等分
    PAPagingViewSegmentLayoutStyleAutolayout,//自适应宽度
};

@interface PAPagingView : UIView


#pragma mark -- Segment
 
@property (nonatomic, strong) UIColor *segmentItemSelectedColor;

@property (nonatomic, strong) UIFont *segmentItemSelectedFont;

@property (nonatomic, strong) UIColor *segmentItemColor;

@property (nonatomic, strong) UIFont *segmentItemFont;

@property (nonatomic, assign) CGFloat segmentItemPadding;

@property (nonatomic, assign) CGFloat segmentViewMargin;

/**
 *  segmentbutton布局样式
 */
@property (nonatomic, assign) PAPagingViewSegmentLayoutStyle segmentStyle;

/**
 *  segment据顶部的距离
 */
@property (nonatomic, assign) CGFloat segmentTopSpace;

/**
 *  自定义segmentButton的size
 */
@property (nonatomic, assign) CGSize segmentButtonSize; 

/**
 *  切换视图
 */
@property (nonatomic, strong, readonly) UIScrollView *segmentView;

@property (nonatomic, assign) UIEdgeInsets pageViewEdge;

@property (nonatomic, assign) CGFloat pageViewCornerRadius;

/**
 *  视图切换的回调block
 */
@property (nonatomic, copy) void (^pagingViewSwitchBlock)(NSInteger switchIndex);

/**
 *  视图点击的回调block
 */
@property (nonatomic, copy) void (^clickEventViewsBlock)(UIView *eventView);

/**
 *  视图滚动的回调block
 */
@property (nonatomic, copy) void (^scrollViewDidScrollBlock)(CGFloat offset);

/**
 *  实例化横向分页控件
 *
 *  @param headerView     tableHeaderView
 *  @param headerHeight   tableHeaderView高度
 *  @param segmentButtons 切换按钮的数组
 *  @param segmentHeight  切换视图高度
 *  @param contentViews   内容视图的数组
 *
 *  @return  控件对象
 */
- (instancetype)initWithFrame:(CGRect)frame
                   headerView:(UIView *)headerView
                 headerHeight:(CGFloat)headerHeight
                segmentTitles:(NSArray *)segmentTitles
                segmentHeight:(CGFloat)segmentHeight
                 contentViews:(NSArray *)contentViews;

/**
 *  手动控制滚动到某个视图
 *
 *  @param pageIndex 页号
 */
- (void)scrollToIndex:(NSInteger)pageIndex;

/**
 *  是否允许切换视图
 *  为NO时不能左右滑动视图，且segmentBar点击无效
 *
 *  @param enable 是否允许切换
 */
- (void)switchEnable:(BOOL)enable;

/**
 *  是否允许左右滑动
 *  为NO时不能左右滑动视图，但segmentBar点击有效
 *
 *  @param enable 是否允许滑动（为NO时segmentBar点击有效）
 */
- (void)scrollEnable:(BOOL)enable;

@end

NS_ASSUME_NONNULL_END
