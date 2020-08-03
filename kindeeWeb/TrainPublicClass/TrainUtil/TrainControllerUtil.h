//
//  TrainControllerUtil.h
//  SOHUTrain
//
//  Created by apple on 16/8/26.
//  Copyright © 2016年  Kingno. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@interface TrainControllerUtil : NSObject
//获取rootviewcontroller
+ (UIViewController *)getTrainRootVC;

//获取当前屏幕显示的viewcontroller
+ (UIViewController *)getTrainCurrentVC;

//判断是否为iphone X

+ (BOOL)isiPhoneX ;

//安全区域高度

+ (float)safeBottomHeight ;

//生成资源文件名及对应的hash的字典
+(NSDictionary *)getBundleFileHash ;

// 是否越狱
+ (BOOL)isJailBroken ;

//判断是否修改过
+ (BOOL)trainCompareFileHash ;

@end
