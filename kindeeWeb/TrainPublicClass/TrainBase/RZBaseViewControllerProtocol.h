//
//  RZBaseViewControllerProtocol.h
//  YGProject
//
//  Created by admin on 2017/10/30.
//  Copyright © 2017年 YG. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol RZBaseViewControllerProtocol <NSObject>

@required

- (void)evAddSubviews;

- (void)evAddLayout;

@optional

- (void)evInitNavgation;

- (void)evBindViewModel;

- (void)evGetNewData;


@end
