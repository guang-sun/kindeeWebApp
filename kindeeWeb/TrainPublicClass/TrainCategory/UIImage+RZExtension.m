//
//  UIImage+RZExtension.m
//  YGProject
//
//  Created by admin on 2017/10/23.
//  Copyright © 2017年 YG. All rights reserved.
//

#import "UIImage+RZExtension.h"
#import <QuartzCore/QuartzCore.h>

@implementation UIImage (RZExtension)


- (NSData *)compressImageMaxFileSize:(NSInteger)maxFileSize {
    
    NSData *orightData = UIImageJPEGRepresentation(self, 1);
    if (orightData.length / 1024.0 < maxFileSize) {
        return orightData;
    }
    UIImage  *newSizeImage = [self imageByScalingAndCroppingForSize:[UIScreen mainScreen].bounds.size];
    
    CGFloat compression = 0.9f;
    CGFloat minCompression = 0.2f;
    NSData *imageData = UIImageJPEGRepresentation(newSizeImage, compression);
    while ([imageData length] / 1024.0 > maxFileSize && compression > minCompression) {
        compression -= 0.1;
        imageData = UIImageJPEGRepresentation(newSizeImage, compression);
    }

    return imageData;
}
- (UIImage*)imageByScalingForMaxSize:(CGSize )targetSize {
    
    UIImage *sourceImage = self;
    UIImage *newImage = nil;
    CGSize imageSize = sourceImage.size;
    CGFloat width = imageSize.width;
    CGFloat height = imageSize.height;
    CGFloat targetWidth = targetSize.width;
    CGFloat targetHeight = targetSize.height;
    CGFloat scaleFactor = 0.0;
    CGFloat scaledWidth = targetWidth;
    CGFloat scaledHeight = targetHeight;
    //    CGPoint thumbnailPoint = CGPointMake(0.0,0.0);
    
    if(width < targetSize.width || height < targetSize.height){
        
        return self;
    }
    if (CGSizeEqualToSize(imageSize, targetSize) == NO)
    {
        CGFloat widthFactor = targetWidth / width * 1.0;
        CGFloat heightFactor = targetHeight / height * 1.0;
        if (widthFactor < heightFactor)
            scaleFactor = heightFactor; // scale to fit height
        else
            scaleFactor = widthFactor; // scale to fit width
        scaledWidth= width * scaleFactor;
        scaledHeight = height * scaleFactor;
    }
    
    //    UIGraphicsBeginImageContext(targetSize); // this will crop
    UIGraphicsBeginImageContextWithOptions(CGSizeMake(scaledWidth, scaledHeight), NO, [UIScreen mainScreen].scale);
    
    CGRect thumbnailRect = CGRectZero;
    //    thumbnailRect.origin = thumbnailPoint;
    thumbnailRect.size.width= scaledWidth;
    thumbnailRect.size.height = scaledHeight;
    
    [sourceImage drawInRect:thumbnailRect];
    
    newImage = UIGraphicsGetImageFromCurrentImageContext();
    if(newImage == nil)
        NSLog(@"could not scale image");
    
    //pop the context to get back to the default
    UIGraphicsEndImageContext();
    return newImage;
}

- (UIImage*)imageByScalingAndCroppingForSize:(CGSize)targetSize
{
    UIImage *sourceImage = self;
    UIImage *newImage = nil;
    CGSize imageSize = sourceImage.size;
    CGFloat width = imageSize.width;
    CGFloat height = imageSize.height;
    CGFloat targetWidth = targetSize.width;
    CGFloat targetHeight = targetSize.height;
    CGFloat scaleFactor = 0.0;
    CGFloat scaledWidth = targetWidth;
    CGFloat scaledHeight = targetHeight;
    //    CGPoint thumbnailPoint = CGPointMake(0.0,0.0);
    
    if(width < targetSize.width || height < targetSize.height){
        
        return self;
    }
    if (CGSizeEqualToSize(imageSize, targetSize) == NO)
    {
        CGFloat widthFactor = targetWidth / width * 1.0;
        CGFloat heightFactor = targetHeight / height * 1.0;
        
        if (widthFactor > heightFactor)
            scaleFactor = heightFactor; // scale to fit height
        else
            scaleFactor = widthFactor; // scale to fit width
        scaledWidth= width * scaleFactor;
        scaledHeight = height * scaleFactor;
    }
    
    //    UIGraphicsBeginImageContext(targetSize); // this will crop
    UIGraphicsBeginImageContextWithOptions(CGSizeMake(scaledWidth, scaledHeight), NO, [UIScreen mainScreen].scale);
    
    CGRect thumbnailRect = CGRectZero;
    //    thumbnailRect.origin = thumbnailPoint;
    thumbnailRect.size.width= scaledWidth;
    thumbnailRect.size.height = scaledHeight;
    
    [sourceImage drawInRect:thumbnailRect];
    
    newImage = UIGraphicsGetImageFromCurrentImageContext();
    if(newImage == nil)
        NSLog(@"could not scale image");
    
    //pop the context to get back to the default
    UIGraphicsEndImageContext();
    return newImage;
}

/**
 *  @brief  根据bundle中的文件名读取图片
 *
 *  @param name 图片名
 *
 *  @return 无缓存的图片
 */
+ (UIImage *)imageWithFileName:(NSString *)name {
    
    NSString *extension = @"png";
    NSArray *components = [name componentsSeparatedByString:@"."];
    if ([components count] >= 2) {
        NSUInteger lastIndex = components.count - 1;
        extension = [components objectAtIndex:lastIndex];
        
        name = [name substringToIndex:(name.length-(extension.length+1))];
    }
    
    // 如果为Retina屏幕且存在对应图片，则返回Retina图片，否则查找普通图片
    if ([UIScreen mainScreen].scale == 2.0) {
        name = [name stringByAppendingString:@"@2x"];
        
        NSString *path = [[NSBundle mainBundle] pathForResource:name ofType:extension];
        if (path != nil) {
            return [UIImage imageWithContentsOfFile:path];
        }
    }
    
    if ([UIScreen mainScreen].scale == 3.0) {
        name = [name stringByAppendingString:@"@3x"];
        
        NSString *path = [[NSBundle mainBundle] pathForResource:name ofType:extension];
        if (path != nil) {
            return [UIImage imageWithContentsOfFile:path];
        }
    }
    
    NSString *path = [[NSBundle mainBundle] pathForResource:name ofType:extension];
    if (path) {
        return [UIImage imageWithContentsOfFile:path];
    }
    
    return nil;
}


/**
 *  @brief  截图指定view成图片
 *
 *  @param view 一个view
 *
 *  @return 图片
 */
+ (UIImage *)captureWithView:(UIView *)view
{
    UIGraphicsBeginImageContextWithOptions(view.bounds.size, view.opaque, [UIScreen mainScreen].scale);
    // IOS7及其后续版本
    if ([view respondsToSelector:@selector(drawViewHierarchyInRect:afterScreenUpdates:)]) {
        [view drawViewHierarchyInRect:view.bounds afterScreenUpdates:NO];
    } else { // IOS7之前的版本
        [view.layer renderInContext:UIGraphicsGetCurrentContext()];
    }
    
    UIImage *screenshot = UIGraphicsGetImageFromCurrentImageContext();
    UIGraphicsEndImageContext();
    return screenshot;
}

+ (UIImage *)getImageWithSize:(CGRect)myImageRect FromImage:(UIImage *)bigImage
{
    //大图bigImage
    //定义myImageRect，截图的区域
    CGImageRef imageRef = bigImage.CGImage;
    CGImageRef subImageRef = CGImageCreateWithImageInRect(imageRef, myImageRect);
    CGSize size;
    size.width = CGRectGetWidth(myImageRect);
    size.height = CGRectGetHeight(myImageRect);
    UIGraphicsBeginImageContext(size);
    CGContextRef context = UIGraphicsGetCurrentContext();
    CGContextDrawImage(context, myImageRect, subImageRef);
    UIImage* smallImage = [UIImage imageWithCGImage:subImageRef];
    CGImageRelease(subImageRef);
    UIGraphicsEndImageContext();
    return smallImage;
}

/**
 *
 *  @brief  截图一个view中所有视图 包括旋转缩放效果
 *
 *  @param aView    指定的view
 *  @param maxWidth 宽的大小 0为view默认大小
 *
 *  @return 截图
 */
+ (UIImage *)screenshotWithView:(UIView *)aView limitWidth:(CGFloat)maxWidth{
    CGAffineTransform oldTransform = aView.transform;
    
    CGAffineTransform scaleTransform = CGAffineTransformIdentity;
    if (!isnan(maxWidth) && maxWidth>0) {
        CGFloat maxScale = maxWidth/CGRectGetWidth(aView.frame);
        CGAffineTransform transformScale = CGAffineTransformMakeScale(maxScale, maxScale);
        scaleTransform = CGAffineTransformConcat(oldTransform, transformScale);
        
    }
    if(!CGAffineTransformEqualToTransform(scaleTransform, CGAffineTransformIdentity)){
        aView.transform = scaleTransform;
    }
    
    CGRect actureFrame = aView.frame; //已经变换过后的frame
    CGRect actureBounds= aView.bounds;//CGRectApplyAffineTransform();
    
    //begin
    UIGraphicsBeginImageContextWithOptions(actureFrame.size, NO, 0.0);
    CGContextRef context = UIGraphicsGetCurrentContext();
    CGContextSaveGState(context);
    //    CGContextScaleCTM(UIGraphicsGetCurrentContext(), 1, -1);
    CGContextTranslateCTM(context,actureFrame.size.width/2, actureFrame.size.height/2);
    CGContextConcatCTM(context, aView.transform);
    CGPoint anchorPoint = aView.layer.anchorPoint;
    CGContextTranslateCTM(context,
                          -actureBounds.size.width * anchorPoint.x,
                          -actureBounds.size.height * anchorPoint.y);
    if([aView respondsToSelector:@selector(drawViewHierarchyInRect:afterScreenUpdates:)])
    {
        [aView drawViewHierarchyInRect:aView.bounds afterScreenUpdates:NO];
    }
    else
    {
        [aView.layer renderInContext:UIGraphicsGetCurrentContext()];
    }
    UIImage *screenshot = UIGraphicsGetImageFromCurrentImageContext();
    UIGraphicsEndImageContext();
    //end
    aView.transform = oldTransform;
    
    return screenshot;
}

@end
