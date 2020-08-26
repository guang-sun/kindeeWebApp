//
//  PAZNPageView.h
//  PaCourseSdk
//
//  Created by 李锦华(平安科技集团系统开发部大学项目组) on 2019/5/27.
//  Copyright © 2019年 平安知鸟. All rights reserved.
//

#import <UIKit/UIKit.h>

@class PAZNPageView;

@protocol PAZNPageViewDataSource <NSObject>

- (NSUInteger)numberOfPagesInPageView:(PAZNPageView *)pageView;
- (UIView *)pageView:(PAZNPageView *)pageView pageAtIndex:(NSUInteger)index;

@end

@protocol PAZNPageViewDelegate <NSObject>

- (void)pageView:(PAZNPageView *)pageView didScrollToIndex:(NSUInteger)index;

@end

@interface PAZNPageView : UIView

@property (nonatomic, weak) id<PAZNPageViewDataSource> dataSource;
@property (nonatomic, weak) id<PAZNPageViewDelegate> delegate;

-(void)reloadData;
- (void)scrollToIndex:(NSUInteger)index;

@end
