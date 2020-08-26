//
//  PAZNFCRecordConfirmViewController.h
//  PaFaceCheckSdk
//
//  Created by 胡铭(平安金融管理学院产品开发中心) on 2019/12/11.
//  Copyright © 2019 huming. All rights reserved.
//

#import <PaFaceCheckSdk/PaFaceCheckSdk.h>

NS_ASSUME_NONNULL_BEGIN

@interface PAZNFCRecordConfirmViewController : PAZNFCBaseViewController
@property (nonatomic, strong) PAZNFCLivenessDetectionFrame *imageInfo;

- (void)restartRecognized;
@end

NS_ASSUME_NONNULL_END
