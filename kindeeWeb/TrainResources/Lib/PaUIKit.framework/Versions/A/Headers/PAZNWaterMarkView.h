//
//  PAZNWaterMarkView.h
//  MLPlayer
//
//  Created by zv on 2018/2/6.
//  Copyright © 2018年 w. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface PAZNWaterMarkView : UIView

- (instancetype)initWithFrame:(CGRect)frame Radian:(double)randian;

@property (nonatomic, copy  )NSString  *watermark;
@property (nonatomic, strong)UIFont    *watermarkFont;
@property (nonatomic, strong)UIColor   *watermarkColor;
@property (nonatomic, assign)double     watermarkRandian;

@end
