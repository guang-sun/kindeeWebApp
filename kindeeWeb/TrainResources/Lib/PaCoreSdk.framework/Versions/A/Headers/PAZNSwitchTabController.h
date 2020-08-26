//
//  PAZNSwitchTabController.h
//  esl
//
//  Created by suruochang on 5/20/14.
//  Copyright (c) 2014 suruochang. All rights reserved.
//

#import <Foundation/Foundation.h>

@class PAZNSwitchTabController;

@protocol PAZNSwitchTabControllerDelegate <NSObject>

@optional
- (void)switchTabController:(PAZNSwitchTabController *)switchTabController willSwitchToIndex:(NSInteger)index;
- (void)switchTabController:(PAZNSwitchTabController *)switchTabController didSwitchToIndex:(NSInteger)index;

@end

@interface PAZNSwitchTabController : UIViewController

@property (nonatomic, weak) id<PAZNSwitchTabControllerDelegate> delegate;
@property (nonatomic, weak, readonly) UIScrollView *scrollView;
@property (nonatomic, strong) NSArray *viewControllers;
@property (nonatomic, assign) NSInteger selectedIndex;
@property (nonatomic, assign) BOOL scrollable;

- (UIViewController *)selectedViewController;

- (void)setSelectedIndex:(NSInteger)selectedIndex animated:(BOOL)animated;
- (void)setSelectedIndex:(NSInteger)selectedIndex animated:(BOOL)animated completion:(void(^)(void))completion;

@end
