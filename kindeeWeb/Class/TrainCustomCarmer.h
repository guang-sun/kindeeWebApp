//
//  TrainCustomCarmer.h
//  kindeeWeb
//
//  Created by Guang on 2020/7/4.
//  Copyright © 2020 WDG. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AVFoundation/AVFoundation.h>
#import <UIKit/UIKit.h>


typedef void (^trainTakePhotoBlock) (UIImage *originImage);
typedef void (^CallBackBlock)(NSInteger btnIndex);

@interface TrainCustomCarmer : NSObject

/// 代理对象
//@property (nonatomic,weak) id <GGCamerManagerDelegate> delegate;
/*
 * 相机初始化
 */
- (instancetype)initWithParentView:(UIView *)view;

- (void)startCapRuning ;
- (void)stopCapRuning ;

- (void)takePhotoWithImageBlock:(trainTakePhotoBlock )block;

/**
 *  拍照
 *
 *  @param block 原图 比例图 裁剪图 （原图是你照相机摄像头能拍出来的大小，比例图是按照原图的比例去缩小一倍，裁剪图是你设置好的摄像范围的图片）
 */
//- (void)takePhotoWithImageBlock:(trainTakePhotoBlock )block;
/**
 *  切换前后镜
 *
 *  isFrontCamera (void(^)(NSString *))callback;
 */
- (void)switchCamera:(BOOL)isFrontCamera didFinishChanceBlock:(void(^)(id))block;
/**
 *  切换闪光灯模式
 * （切换顺序：最开始是auto，然后是off，最后是on，一直循环）
 */
- (void)switchFlashMode:(UIButton*)sender;

@end
