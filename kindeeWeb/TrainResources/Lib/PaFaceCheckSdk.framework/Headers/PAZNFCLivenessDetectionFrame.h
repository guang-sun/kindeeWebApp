//
//  PAZNFCLivenessDetectionFrame.h
//  PaFaceCheckSdk
//
//  Created by huming on 2018/5/29.
//  Copyright © 2018年 huming. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 *  人脸识别参数
 */
struct PAZNFaceAttr{
    
    /** 人脸位置 */
    CGRect face_rect;
    /** 左右旋转弧度 */
    CGFloat yaw ;
    /** 上下俯仰弧度 */
    CGFloat pitch ;
    /** 左右偏航弧度 */
    CGFloat roll ;
    /** 运动模糊程度 */
    CGFloat blurness_motion ;
    /** 亮度 */
    CGFloat brightness ;
    /** 人脸占比 */
    CGFloat faceRatio ;
    /**活体结果**/
    CGFloat liveType ;
    /**连续帧置信度**/
    CGFloat compareScore ;
    /**单帧置信度度**/
    CGFloat confidence ;
};


/*!
 *  单帧检测结果的类，包含单帧检测出人脸的所有属性，此类无需构造，仅用于回调
 */
@interface PAZNFCLivenessDetectionFrame : NSObject

/** 检测帧对应图片*/
@property (nonatomic, strong) UIImage* image;

/** 图片中的人脸属性 */
@property (nonatomic) struct PAZNFaceAttr attr;


@end
