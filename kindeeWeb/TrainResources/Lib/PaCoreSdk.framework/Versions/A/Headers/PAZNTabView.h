//
//  PATabView.h
//  MLPlayer
//
//  Created by liurj on 15/12/1.
//  Copyright © 2015年 w. All rights reserved.
//

#import <UIKit/UIKit.h>

@class PAZNTabView;

typedef NS_ENUM(NSInteger, PAZNTabViewType)
{
    PAZNTabViewTypeAverage = 0,   //宽度平均
    PAZNTabViewTypeTag = 1,       //标签选择类型
    PAZNTabViewTypeCustom = 2,    //自定义间距
};

@protocol PAZNTabViewDelegate <NSObject>

- (void)tabView:(PAZNTabView *)tabView selectedInex:(NSUInteger)index;

@end


@interface PAZNTabView : UIView
/*!
 @brief     代理
 */
@property (nonatomic, weak) id<PAZNTabViewDelegate> delegate;

/*!
 @brief     tab类型
 */
@property (nonatomic, assign) PAZNTabViewType tabType;

/*!
 @brief     当前选中的索引
 */
@property (nonatomic, assign) NSUInteger selectedIndex;
/*!
 @brief     选中的颜色
 */
@property (nonatomic, strong) UIColor *selectedColor;

/*!
 @brief     选中的颜色
 */
@property (nonatomic, strong) UIFont *selectedFont;

/*!
 @brief     指示view
 */
@property (nonatomic, strong) UIView *tabHudView;
/*!
 @brief     按钮数组
 */
@property (nonatomic, strong, readonly) NSMutableArray *buttonsArray;
/*!
 @brief     底线
 */
@property (nonatomic, strong, readonly) UIView *bottomLineView;
/*!
 @brief     能否滑动
 */
@property (nonatomic, assign) BOOL enableScroll;

/*!
 @brief     能否滑动
 */
@property (nonatomic, assign) BOOL showBottomLine;
/*!
 @brief     左边距离
 */
@property (nonatomic, assign) CGFloat   leftMargin;
/*!
 @brief     间隔
 */
@property (nonatomic, assign) CGFloat   interval;
/*!
 @brief     item ContentInset
 */
@property (nonatomic, assign) UIEdgeInsets  itemContentInset;
/*!
 @brief     item 背景色
 */
@property (nonatomic, strong) UIColor       *itemBgColor;
/*!
 @brief     item 边框颜色
 */
@property (nonatomic, strong) UIColor       *itemBorderColor;

/*!
 @brief      颜色
 */
@property (nonatomic, strong) UIColor *color;

/*!
 @brief     title字体
 */
@property (nonatomic, strong) UIFont *font;

/**
 *  创建一个tabview
 *
 *  @param frame       frame大小
 *  @param titlesArray tab标题数组
 *
 *  @return tabview对象
 */
- (instancetype)initWithFrame:(CGRect)frame titlesArray:(NSArray *)titlesArray;

/**
 创建一个tabview
 
 @param frame frame
 @param tabType tab类型
 @param titlesArray 标题数组
 @return tabview对象
 */
- (instancetype)initWithFrame:(CGRect)frame tabType:(PAZNTabViewType)tabType titlesArray:(NSArray *)titlesArray;


/**
 *  选中一个tab页
 *
 *  @param index tab的索引
 */
- (void)selectedTabIndex:(NSUInteger)index;

/**
 *  title字体大小
 *
 *  @return 字体大小
 */
- (UIFont *)titleFont;

/**
 *根据位置索引该出标题
 */
- (NSString *)titleForTabIndex:(NSUInteger)index;
- (void)changeTitle:(NSString *)title tabIndex:(NSUInteger)index;

/**
 *新样式
 */
- (void)changeStyle2;

- (void)addBottomLine;
@end
