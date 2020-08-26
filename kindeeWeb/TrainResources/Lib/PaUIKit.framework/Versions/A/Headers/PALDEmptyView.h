//
//  PALDEmptyView.h
//  MLPlayer
//
//  Created by 王斌(平安科技智慧教育团队项目研发部知鸟研发团队移动开发组) on 2018/10/17.
//  Copyright © 2018年 w. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface PALDEmptyView : UIView

@property (nonatomic, assign) CGFloat                             emptyOffsetY;

@property (nonatomic, strong) NSString                            *emptyText;

@property (nonatomic, strong) UIFont                              *emptyTextFont;

@property (nonatomic, strong) NSAttributedString                  *emptyAttributedText;

@property (nonatomic, strong) UIImage                             *emptyImage;

- (instancetype)initWithNib;

@end
