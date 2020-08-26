//
//  UIButton+Block.h
//  iOS-Categories (https://github.com/shaojiankui/iOS-Categories)
//
//  Created by Jakey on 14/12/30.
//  Copyright (c) 2014年 www.skyfox.org. All rights reserved.
//

#import <UIKit/UIKit.h>

typedef void (^TouchedBlock)(NSInteger tag);

@interface UIButton (Block)
-(void)pa_addActionHandler:(TouchedBlock)touchHandler;
@property (nonatomic, strong)TouchedBlock pazn_touchHandler; //!< 事件
@end
