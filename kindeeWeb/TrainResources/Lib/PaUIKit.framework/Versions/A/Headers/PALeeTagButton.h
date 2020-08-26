//
//  LeeTagButton.h
//  TagViewDemo
//
//  Created by YWKJ on 2018/9/4.
//  Copyright © 2018年 YWKJ. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "PALeeTagViewModel.h"

@interface PALeeTagButton : UIButton
@property (nonatomic, strong) PALeeTagViewModel * tagViewModel;
+(PALeeTagButton *)tagButtonWithTagViewModel:(PALeeTagViewModel *)tagViewModel;
@end
