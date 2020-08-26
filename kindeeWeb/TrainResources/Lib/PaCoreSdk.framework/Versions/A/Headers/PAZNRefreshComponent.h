//  代码地址: https://github.com/CoderMJLee/MJRefresh
//  代码地址: http://code4app.com/ios/%E5%BF%AB%E9%80%9F%E9%9B%86%E6%88%90%E4%B8%8B%E6%8B%89%E4%B8%8A%E6%8B%89%E5%88%B7%E6%96%B0/52326ce26803fabc46000000
//  MJRefreshComponent.h
//  MJRefreshExample
//
//  Created by MJ Lee on 15/3/4.
//  Copyright (c) 2015年 小码哥. All rights reserved.
//  刷新控件的基类

#import <UIKit/UIKit.h>
#import "PAZNRefreshConst.h"
#import "UIView+PAZNExtension.h"
#import "UIScrollView+PAZNExtension.h"
#import "UIScrollView+PAZNRefresh.h"
#import "NSBundle+PAZNRefresh.h"

/** 刷新控件的状态 */
typedef NS_ENUM(NSInteger, PAZNRefreshState) {
    /** 普通闲置状态 */
    PAZNRefreshStateIdle = 1,
    /** 松开就可以进行刷新的状态 */
    PAZNRefreshStatePulling,
    /** 正在刷新中的状态 */
    PAZNRefreshStateRefreshing,
    /** 即将刷新的状态 */
    PAZNRefreshStateWillRefresh,
    /** 所有数据加载完毕，没有更多的数据了 */
    PAZNRefreshStateNoMoreData
};

/** 进入刷新状态的回调 */
typedef void (^PAZNRefreshComponentRefreshingBlock)(void);
/** 开始刷新后的回调(进入刷新状态后的回调) */
typedef void (^PAZNRefreshComponentbeginRefreshingCompletionBlock)(void);
/** 结束刷新后的回调 */
typedef void (^PAZNRefreshComponentEndRefreshingCompletionBlock)(void);

/** 刷新控件的基类 */
@interface PAZNRefreshComponent : UIView
{
    /** 记录scrollView刚开始的inset */
    UIEdgeInsets _scrollViewOriginalInset;
    /** 父控件 */
    __weak UIScrollView *_scrollView;
}
#pragma mark - 刷新回调
/** 正在刷新的回调 */
@property (copy, nonatomic) PAZNRefreshComponentRefreshingBlock refreshingBlock;
/** 设置回调对象和回调方法 */
- (void)setRefreshingTarget:(id)target refreshingAction:(SEL)action;

/** 回调对象 */
@property (weak, nonatomic) id refreshingTarget;
/** 回调方法 */
@property (assign, nonatomic) SEL refreshingAction;
/** 触发回调（交给子类去调用） */
- (void)executeRefreshingCallback;

#pragma mark - 刷新状态控制
/** 进入刷新状态 */
- (void)beginRefreshing;
- (void)beginRefreshingWithCompletionBlock:(void (^)(void))completionBlock;
/** 开始刷新后的回调(进入刷新状态后的回调) */
@property (copy, nonatomic) PAZNRefreshComponentbeginRefreshingCompletionBlock beginRefreshingCompletionBlock;
/** 结束刷新的回调 */
@property (copy, nonatomic) PAZNRefreshComponentEndRefreshingCompletionBlock endRefreshingCompletionBlock;
/** 结束刷新状态 */
- (void)endRefreshing;
- (void)endRefreshingWithCompletionBlock:(void (^)(void))completionBlock;
/** 是否正在刷新 */
- (BOOL)isRefreshing;
/** 刷新状态 一般交给子类内部实现 */
@property (assign, nonatomic) PAZNRefreshState state;

#pragma mark - 交给子类去访问
/** 记录scrollView刚开始的inset */
@property (assign, nonatomic, readonly) UIEdgeInsets scrollViewOriginalInset;
/** 父控件 */
@property (weak, nonatomic, readonly) UIScrollView *scrollView;

#pragma mark - 交给子类们去实现
/** 初始化 */
- (void)prepare NS_REQUIRES_SUPER;
/** 摆放子控件frame */
- (void)placeSubviews NS_REQUIRES_SUPER;
/** 当scrollView的contentOffset发生改变的时候调用 */
- (void)scrollViewContentOffsetDidChange:(NSDictionary *)change NS_REQUIRES_SUPER;
/** 当scrollView的contentSize发生改变的时候调用 */
- (void)scrollViewContentSizeDidChange:(NSDictionary *)change NS_REQUIRES_SUPER;
/** 当scrollView的拖拽状态发生改变的时候调用 */
- (void)scrollViewPanStateDidChange:(NSDictionary *)change NS_REQUIRES_SUPER;


#pragma mark - 其他
/** 拉拽的百分比(交给子类重写) */
@property (assign, nonatomic) CGFloat pullingPercent;
/** 根据拖拽比例自动切换透明度 */
@property (assign, nonatomic, getter=isAutoChangeAlpha) BOOL autoChangeAlpha PAZNRefreshDeprecated("请使用automaticallyChangeAlpha属性");
/** 根据拖拽比例自动切换透明度 */
@property (assign, nonatomic, getter=isAutomaticallyChangeAlpha) BOOL automaticallyChangeAlpha;
@end

@interface UILabel(PAZNRefresh)
+ (instancetype)pazn_label;
- (CGFloat)pazn_textWith;
@end
