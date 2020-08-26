//
//  PAZNRecordFaceViewController.h
//  MLPlayer
//
//  Created by huming on 2018/1/10.
//  Copyright © 2018年 w. All rights reserved.
//

#import "PAZNFCBaseViewController.h"

@interface PAZNFCRecordFaceViewController : PAZNFCBaseViewController


//typedef NS_ENUM (NSInteger,PAZNFaceDetectType) {
//    PAZNFaceDetectType_NORMAL      = 1001,    //正脸--必须--合格
//    PAZNFaceDetectType_MouthOpen ,            //张嘴---选择
//    PAZNFaceDetectType_EyeBlink ,             //眨眼---选择
//    PAZNFaceDetectType_HeadShank,             //摇头---选择
//    PAZNFaceDetectType_LeftShank,             //摇头左---选择
//    PAZNFaceDetectType_RightShank             //摇头右---选择
//};

/**
    需要的检测动作数组，内容为PAZNFaceDetectType
 */
@property (nonatomic, strong) NSMutableArray *detectTypeArray;
@property (nonatomic, assign) NSUInteger timeLimit;    //设置超时时间，单位秒

@property (nonatomic, copy) NSString *topTips;  ///<顶部提示语
@property (nonatomic, copy) void (^takePhotoCompletion)(BOOL success,UIImage *image);

- (instancetype)initWithPreView:(UIView *)preview;

- (void)restartRecognized;

@end
