//
//  UIView+UIView_BlockGesture.h
//  iOS-Categories (https://github.com/shaojiankui/iOS-Categories)
//
//  Created by Jakey on 14/12/30.
//  Copyright (c) 2014年 www.skyfox.org. All rights reserved.
//

#import <UIKit/UIKit.h>
typedef void (^GestureActionBlock)(UIGestureRecognizer *gestureRecoginzer);

@interface UIView (BlockGesture)
- (void)pa_addTapActionWithBlock:(GestureActionBlock)block;
- (void)pa_addLongPressActionWithBlock:(GestureActionBlock)block;
@end
