//
//  PAIssueFeedbackBar.h
//  PaLiveSdk
//
//  Created by 周大俊(智慧教育) on 2020/2/13.
//  Copyright © 2020 Cyril Zhou. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface PAIssueFeedbackBar : UIView

@property (nonatomic, copy) void (^showFeedBackBlock)(void);

@property (nonatomic, assign) CGFloat marginToBottom;

@end

NS_ASSUME_NONNULL_END
