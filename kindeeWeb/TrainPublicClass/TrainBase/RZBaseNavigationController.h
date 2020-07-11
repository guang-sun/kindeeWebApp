//
//  RZBaseNavigationController.h
//  PandaCar
//
//  Created by Year on 2017/11/20.
//  Copyright © 2017年 RoZSoft. All rights reserved.
//

#import <UIKit/UIKit.h>

@protocol BaseNavigationControllerDelegate <NSObject>

/**
 导航返回按钮点击事件，重写此方法需要设置BaseNavgationContrlloer 的Delegate
 */
- (void)backClick;

@end

@interface RZBaseNavigationController : UINavigationController

/**
 有些页面的返回按钮不在左上角，或者不需要返回按钮的。
 获取到当前的导航，传入不需要返回按钮的页面，即可隐藏掉返回按钮*/
@property (nonatomic, weak, nullable) UIViewController *noBackButtonVC;

/**
 导航代理，一些特殊的页面需要重写返回按钮的方法，用此代理*/
@property (nonatomic, weak, nullable) id <BaseNavigationControllerDelegate> baseDelegate;

@end
