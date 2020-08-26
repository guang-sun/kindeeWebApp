//
//  UIImage+extra.h
//  MLPlayer
//
//  Created by 徐仁杰 on 9/21/14.
//  Copyright (c) 2014 w. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <AVFoundation/AVFoundation.h>

@interface UIImage (PAZNExtra)

+ (UIImage *)imageScaleNamed:(NSString *)name;
+ (UIImage *)createImageWithColor:(UIColor *)color;
- (UIImage *)scaleImageToScale:(float)scaleSize;

/**
 *  生成loadingImage
 *
 *  @param color     背景色
 *  @param size  背景大小
 *  @param image2  中心图
 *
 *  @return loadingImage
 */
+ (UIImage *)createLoadingImage:(UIColor *)color size:(CGSize)size centerImage:(UIImage *)image2;

/**
 *  毛玻璃效果
 *
 *  @param blur      模糊度  0~1
 *  @param tintColor  背景填充色 ,可nil
 *
 *  @return 毛玻璃图
 */
- (UIImage *)boxblurImageWithBlur:(CGFloat)blur tintColor:(UIColor *)tintColor;
/**
 *  传入图片的名称,返回一张可拉伸不变形的图片
 *
 *  @param imageName 图片名称
 *
 *  @return 可拉伸图片
 */
+ (UIImage *)resizableImageWithName:(NSString *)imageName;

//截取图片的部分区域.
+ (UIImage *)cutSubImage:(UIImage *)image mCGRect:(CGRect)mCGRect centerBool:(BOOL)centerBool;

//2.自定长宽
- (UIImage *)reSizeImageToSize:(CGSize)reSize;

//3.处理某个特定View 只要是继承UIView的object 都可以处理
- (UIImage *)captureView:(UIView *)theView;

//4.处理选择图片后旋转的问题
- (UIImage *)fixOrientation;

/**
 * 用指定颜色生成一个1x1像素的图片
 */
+ (UIImage *)imageWithColor:(UIColor *)color;

+ (UIImage *)imageWithColor:(UIColor *)color size:(CGSize)size;

+ (UIImage *)imageWithBezierPath:(UIBezierPath *)path fillColor:(UIColor *)fillColor lineColor:(UIColor *)lineColor;

- (UIImage *)renderAtSize:(const CGSize)size;
- (UIImage *)maskWithImage:(const UIImage *)maskImage;

- (UIImage *)maskWithText:(NSString *)text atRect:(CGRect)rect withStyle:(NSDictionary *)style;

- (UIImage *)maskWithImage:(UIImage *)image atRect:(CGRect)rect;

+ (UIImage *)imageWithColor:(UIColor *)color size:(CGSize)size withCornerRadius:(CGFloat)radius;

- (UIImage *)maskWithText:(NSAttributedString *)text atRect:(CGRect)rect;

/**
 根据视频url获取指定时间的缩略图
 
 @param videoURL 视频的url地址
 @param time     指定时间
 
 @return 缩略图
 */
+ (UIImage *)thumbnailImageForVideo:(NSURL *)videoURL atTime:(CMTime)time;

/**
 * 改变当前图片里填充的颜色
 */
- (UIImage *)imageModifyWithColor:(UIColor *)color;

/**
 给图片添加圆角，减少离屏渲染

 @param radius 圆角尺寸
 @return 切完圆角之后的图片
 */
-(UIImage *)imageWithCornerRadius:(CGFloat)radius;

+ (CGSize)pazn_getImageSizeWithURL:(id)URL;
// 传进来图片大小，返回适配之后的图片大小
+ (CGSize)pazn_changeImageSizeToSizeWithImageSize:(CGSize )imageSize maxSize:(CGSize )maxSize;
/**
 *  根据图片url获取网络图片尺寸(url带有width和height)
 */
+ (CGSize)pazn_getImageSizeWithURLHaveWithAndHeight:(id)URL;

+(UIImage *)placeHoldImage:(UIImage *)placeHoldImage backgroundColor:(UIColor *)bgColor size:(CGSize)bgSize;

/**
 给图片增加透明度
 
 @param theAlpha 透明度（0~1）
 @return 增加透明度后的图片
 */
- (UIImage *)imageWithAlpha:(float)theAlpha;

/**
  渐变图片
 @param size 图片大小
 @param colors 渐变颜色数组 CGColorRef对象
 @param locations locations
 @param startPoint startPoint
 @param endPoint endPoint
 @param cornerRadius 圆角
 */
+ (UIImage *)gradientImage:(CGSize)size
                    colors:(NSArray *)colors
                 locations:(NSArray<NSNumber *> *)locations
                startPoint:(CGPoint)startPoint
                  endPoint:(CGPoint)endPoint
              cornerRadius:(CGFloat)cornerRadius;

/**
 周围线条、内部填充的圆角图片
 
 @param size 图片大小
 @param fillColor 填充颜色
 @param lineColor 线条颜色
 @param lineWidth 线条宽度
 */

+ (UIImage *)imageWithSize:(CGSize)size fillColor:(UIColor *)fillColor lineColor:(UIColor *)lineColor lineWidth:(CGFloat)lineWidth;

/**
 合并图片各取不同比例，做进度条的
 
@param size 图片大小
@param leftImage 左图
@param rightImage 右图
@param progress 左图进度
*/
+ (UIImage *)combineImageSize:(CGSize)size
                    leftImage:(UIImage *)leftImage
                   rightImage:(UIImage *)rightImage
                     progress:(CGFloat)progress;

@end

