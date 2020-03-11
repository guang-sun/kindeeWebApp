//
//  TrainScanViewController.h
//  SOHUEhr
//
//  Created by apple on 16/9/9.
//  Copyright © 2016年  . All rights reserved.
//

#import <AVFoundation/AVFoundation.h>
#import <UIKit/UIKit.h>


@interface TrainScanViewController : UIViewController

@property (nonatomic, copy)  void  (^trainScanBlock)(NSString *result);


@end
