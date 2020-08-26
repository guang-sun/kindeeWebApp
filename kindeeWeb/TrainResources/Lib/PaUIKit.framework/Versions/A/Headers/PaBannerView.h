//
//  PaBannerView.h
//  PaCoreSdk
//
//  Created by Mac on 15/7/7.
//  Copyright (c) 2015年 w. All rights reserved.
//

#import <UIKit/UIKit.h>

@protocol PaBannerDelegate <NSObject>

- (void)bannerAction:(NSInteger)index;

@optional
- (void)bannerScrollAction:(BOOL)isScrolling;

@end

@interface PaBannerView : UIView<UIScrollViewDelegate>

@property (nonatomic, assign) BOOL isTimer;  //是否开启计时器

@property (nonatomic, assign) UIControlContentHorizontalAlignment pageControlHorizontalAlignment;

@property (nonatomic,weak) id<PaBannerDelegate> delegate;

@property (nonatomic,strong) UIImage *placeHolderImage;

@property (nonatomic,assign) UIEdgeInsets pageControlInsets;

@property (nonatomic,strong, readonly) UIScrollView *scrollView;

/**
 *  初始化方法,是否开启计时器
 *
 *  @param frame   frame
 *  @param isTimer 是否开启计时器
 *
 *  @return 返回 bannerScrollView
 */
- (instancetype)initWithFrame:(CGRect)frame withTimer:(BOOL)isTimer;

/**
 *  更新数据
 *
 *  @param datasource 数据
 */
- (void)resetData:(NSArray*)datasource;

//启动
- (void)startTimer;

//滑动停止
- (void)stopTimer;

@end


