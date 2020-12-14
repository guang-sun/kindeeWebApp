//
//  UIImage+RZExtension.h
//  YGProject
//
//  Created by admin on 2017/10/23.
//  Copyright © 2017年 YG. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UIImage (RZExtension)

/**
 压缩image的大小
 
 @param maxFileSize 压缩到最大  单位K
 @return uiimage
 */
- (NSData *)compressImageMaxFileSize:(NSInteger)maxFileSize ;



- (UIImage*)imageByScalingForMaxSize:(CGSize )targetSize ;

/**
 将图片按比例缩小
 @param targetSize 设置缩小的目标大小
 @return 缩小后的image
 */
- (UIImage*)imageByScalingAndCroppingForSize:(CGSize)targetSize ;

/**
 *  @brief  根据bundle中的文件名读取图片
 *
 *  @param name 图片名
 *
 *  @return 无缓存的图片
 */
+ (UIImage *)imageWithFileName:(NSString *)name;

/**
 *  @brief  截图指定view成图片
 *
 *  @param view 一个view
 *
 *  @return 图片
 */
+ (UIImage *)captureWithView:(UIView *)view;

///截图（未测试是否可行）
+ (UIImage *)getImageWithSize:(CGRect)myImageRect FromImage:(UIImage *)bigImage;

/**
 *
 *  @brief  截图一个view中所有视图 包括旋转缩放效果
 *
 *  @param aView    指定的view
 *  @param maxWidth 宽的大小 0为view默认大小
 *
 *  @return 截图
 */
+ (UIImage *)screenshotWithView:(UIView *)aView limitWidth:(CGFloat)maxWidth;

@end
