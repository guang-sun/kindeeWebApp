//
//  PAPunchPopupView.h
//  PaCourseSdk
//
//  Created by 罗红(EX-LUOHONG003) on 2020/6/12.
//  Copyright © 2020 平安知鸟. All rights reserved.
//

#import "PAPopupView.h"

typedef NS_ENUM(NSInteger,PAPunchPopupViewType){
    PAPunchPopupViewTypeUnfinish = 0,
    PAPunchPopupViewTypeFinished = 1
};

NS_ASSUME_NONNULL_BEGIN

@interface PAPunchPopupView : PAPopupView

- (instancetype)initWithType:(PAPunchPopupViewType)type punchAction:(void(^)(void))block;

@end

NS_ASSUME_NONNULL_END
