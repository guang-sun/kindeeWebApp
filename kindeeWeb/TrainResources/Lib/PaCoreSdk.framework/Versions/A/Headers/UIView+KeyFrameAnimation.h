//
//  UIView+KeyFrameAnimation.h
//  ademo
//
//  Created by 汪子为 on 2018/6/14.
//  Copyright © 2018年 PAZN. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UIView (KeyFrameAnimation)

- (void)addAnimationWithImages:(NSArray *)animationImages
                         times:(NSArray *)times
                   repeatCount:(float)count
                animationFrame:(CGRect)frame
               animateComplete:(void (^) (BOOL flag))complete
           removeAfterComplete:(BOOL)removeAfterComplete;

/*
 周边加阴影，并且同时圆角
 */
- (void)addShadowWithOpacity:(float)shadowOpacity
                shadowRadius:(CGFloat)shadowRadius
             andCornerRadius:(CGFloat)cornerRadius;

- (void)removeShadowLayer;

@end
