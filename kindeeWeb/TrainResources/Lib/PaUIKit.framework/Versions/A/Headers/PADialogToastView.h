//
//  PADialogToastView.h
//  PADrawAwardModule
//
//  Created by 王斌(平安科技智慧教育团队项目研发部知鸟研发团队移动开发组) on 2018/9/7.
//  Copyright © 2018年 wans. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface PADialogToastView : UIView<BFDisplayProtocol>

@property (nonatomic, strong) NSAttributedString                 *attributedText;

@property (nonatomic, assign) CGFloat                            cornerRadius;

@property (nonatomic, assign) UIEdgeInsets                       edgeInsets;

@end
