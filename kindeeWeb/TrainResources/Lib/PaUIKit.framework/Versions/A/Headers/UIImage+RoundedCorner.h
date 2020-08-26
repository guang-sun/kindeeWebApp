//
//  UIImage+RoundedCorner.h
//  MLPlayer
//
//  Created by 刘宏扬 on 2018/8/31.
//  Copyright © 2018年 w. All rights reserved.
//

#import <UIKit/UIKit.h>

struct PARadius {
    CGFloat topLeftRadius;
    CGFloat topRightRadius;
    CGFloat bottomLeftRadius;
    CGFloat bottomRightRadius;
};
typedef struct PARadius PARadius;


static inline PARadius PARadiusMake(CGFloat topLeftRadius, CGFloat topRightRadius, CGFloat bottomLeftRadius, CGFloat bottomRightRadius) {
    PARadius radius;
    radius.topLeftRadius = topLeftRadius;
    radius.topRightRadius = topRightRadius;
    radius.bottomLeftRadius = bottomLeftRadius;
    radius.bottomRightRadius = bottomRightRadius;
    return radius;
}


static inline NSString * NSStringFromPARadius(PARadius radius) {
    return [NSString stringWithFormat:@"{%.2f, %.2f, %.2f, %.2f}", radius.topLeftRadius, radius.topRightRadius, radius.bottomLeftRadius, radius.bottomRightRadius];
}

@interface UIImage (PASLRoundedCorner)

- (UIImage *)pa_imageByRoundCornerRadius:(CGFloat)radius;

- (UIImage *)pa_imageWithSize:(CGSize)size
                 cornerRadius:(CGFloat)radius
                  borderWidth:(CGFloat)borderWidth
                  borderColor:(UIColor *)borderColor;

- (UIImage *)pa_imageByRoundCornerRadius:(CGFloat)radius
                          borderWidth:(CGFloat)borderWidth
                          borderColor:(UIColor *)borderColor;

- (UIImage *)pa_imageWithSize:(CGSize)size
                 cornerRadius:(CGFloat)radius
                      corners:(UIRectCorner)corners
                  borderWidth:(CGFloat)borderWidth
                  borderColor:(UIColor *)borderColor
               borderLineJoin:(CGLineJoin)borderLineJoin;


- (UIImage *)pa_setRadius:(CGFloat)radius
                     size:(CGSize)size;


- (UIImage *)pa_setRadius:(CGFloat)radius
                     size:(CGSize)size
              contentMode:(UIViewContentMode)contentMode;


+ (UIImage *)pa_setRadius:(CGFloat)radius
                     size:(CGSize)size
              borderColor:(UIColor *)borderColor
              borderWidth:(CGFloat)borderWidth
          backgroundColor:(UIColor *)backgroundColor;


+ (UIImage *)pa_setPARadius:(PARadius)radius
                      image:(UIImage *)image
                       size:(CGSize)size
                borderColor:(UIColor *)borderColor
                borderWidth:(CGFloat)borderWidth
            backgroundColor:(UIColor *)backgroundColor
            withContentMode:(UIViewContentMode)contentMode;


@end
