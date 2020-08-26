//
//  PACourseTagGuideView.h
//  MLPlayer
//
//  Created by 李锦华(平安科技集团系统开发部大学项目组) on 2017/8/26.
//  Copyright © 2017年 w. All rights reserved.
//  初次使用课程标签提示

#import <Foundation/Foundation.h>

typedef void(^ClickCloseBlock)(BOOL click);

@interface PACourseTagGuideView : UIView

-(instancetype)initWithFrame:(CGRect)frame CloseCallBack:(ClickCloseBlock)completion;

@end
