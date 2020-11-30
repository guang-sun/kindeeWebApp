//
//  UIImage+imageFace.h
//  kindeeWeb
//
//  Created by Guang on 2020/11/28.
//  Copyright © 2020 WDG. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface UIImage (imageFace)


/**
 CVPixelBufferRef 转换为UIimage

 @param pixelBufffer 图片的CVPixelBufferRef
 @return UIimage
 */
+(UIImage*)pixelBufferToImage:(CVPixelBufferRef) pixelBufffer;

#pragma mark -
#pragma mark - 缩放处理
//缩放倍数
+ (UIImage *)scaleImage:(UIImage *)image withScale:(float)scale;

//指定缩放大小
+ (UIImage *)scaleImage:(UIImage *)image toSize:(CGSize)size;

#pragma mark -
#pragma mark - 马赛克处理

static CGContextRef CreateRGBABitmapContext (CGImageRef inImage);

static unsigned char *RequestImagePixelData(UIImage *inImage);

+ (UIImage *)mosaicImage:(UIImage *)image withLevel:(int)level;

/*
 *转换成马赛克,level代表一个点转为多少level*level的正方形
 */
+ (UIImage *)transToMosaicImage:(UIImage*)orginImage blockLevel:(NSUInteger)level;
@end

NS_ASSUME_NONNULL_END
