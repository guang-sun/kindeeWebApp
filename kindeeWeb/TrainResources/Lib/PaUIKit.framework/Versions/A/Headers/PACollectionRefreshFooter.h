//
//  PACollectionRefreshFooter.h
//  MLPlayer
//
//  Created by 刘宏扬 on 2018/11/3.
//  Copyright © 2018年 w. All rights reserved.
//

#import <Foundation/Foundation.h>

//刷新条宽度
static const CGFloat FooterRefreshWidth = 40.0;

//刷新状态
typedef NS_ENUM(NSUInteger, FooterRefreshStatus) {
    FooterRefreshStatusNormal,
    FooterRefreshStatusPulling,
    FooterRefreshStatusLoading,
};

// 刷新回调
typedef void(^loadAction)(void);

@interface PACollectionRefreshFooter : UIView

//依附的collectionView
@property (nonatomic, weak) UICollectionView *collectionView;
// 刷新状态
@property (nonatomic, assign) FooterRefreshStatus refreshStatus;
// 旧的刷新状态
@property (nonatomic, assign) FooterRefreshStatus oldRefreshStatus;
@property (nonatomic, assign) BOOL isFoeceHidden;
// 拉动提示
@property (nonatomic, copy) NSString *normalMessage;
//即将刷新的提示
@property (nonatomic, copy) NSString *pullingMessage;
// 加载中提示
@property (nonatomic, copy) NSString *loadingMessage;
//自定义的加载动画图片组
@property (nonatomic, strong) NSArray<UIImage *> *loadingImages;
// 提示文本
@property (nonatomic, strong) UILabel *messageLabel;
// 自定义的加载图片显示视图
@property (nonatomic, strong) UIImageView *loadingImageView;
// 默认箭头
@property (nonatomic, strong) UIImageView *defaultArrowView;
// 是否支持page
@property (nonatomic, assign) BOOL collectionViewPageEnabel;
// 隐藏文本
@property (nonatomic, assign) BOOL hideMessage;
// 隐藏加载图片
@property (nonatomic, assign) BOOL hideIndicator;

@property (nonatomic, assign) BOOL alwayShowFooter;
// 显示
@property (nonatomic, assign) BOOL limitCountExsit;
// 刷新执行回调
@property (nonatomic, copy) loadAction loadActionBlock;

// 初始化
+ (instancetype)refreshWithLoadAction:(loadAction)loadActionBlock;
// 开始刷新
- (void)beginLoading;
// 结束刷新
- (void)endLoading;
// 执行刷新回调
- (void)startLoadingAction;
// 设置常规状态ContentOffset
- (void)updateContentOffsetToNormal;
// 设置刷新状态ContentOffset
- (void)updateContentOffsetToLoading;
// 是否到达可刷新状态
- (BOOL)pullToReadyRefresh;
// 重置刷新视图位置
- (void)resetRefreshFrame;
// 保持刷新状态的offset
- (void)keepRefreshingOffset;

@end
