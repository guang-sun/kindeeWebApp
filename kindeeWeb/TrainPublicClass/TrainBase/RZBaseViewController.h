//
//  RZBaseViewController.h
//  YGProject
//
//  Created by admin on 2017/10/30.
//  Copyright © 2017年 YG. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "RZBaseViewControllerProtocol.h"


@interface RZBaseViewController : UIViewController <RZBaseViewControllerProtocol>

/* 修改statusbar */
/**
 * 参数：（1）StatusBar样式：statusBarStyle
 *      （2）是否隐藏StatusBar：statusBarHidden
 *      （3）是否动画过渡：animated
 */
- (void)changeStatusBarStyle:(UIStatusBarStyle)statusBarStyle
             statusBarHidden:(BOOL)statusBarHidden
     changeStatusBarAnimated:(BOOL)animated;


- (void)evGotoLoginView ;

/**  获取未读消息数量  */
- (void)evGetUsernoReadMessageNum ;
/**  用于我的页面获取未读消息数据  */
- (void)evUpdateUserCenterVCpageWithDataArr:(NSArray *)arr ;

@end
