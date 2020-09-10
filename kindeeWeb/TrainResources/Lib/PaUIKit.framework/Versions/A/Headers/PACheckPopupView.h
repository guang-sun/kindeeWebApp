//
//  PACheckPopupView.h
//  MLPlayer
//
//  Created by 罗红(EX-LUOHONG003) on 2020/8/4.
//  Copyright © 2020 平安知鸟. All rights reserved.
//

#import "PAPopupView.h"

NS_ASSUME_NONNULL_BEGIN

@interface PACheckPopupView : PAPopupView

- (instancetype)initWithReceiveCheckBlock:(void(^)(void))block;

@end

NS_ASSUME_NONNULL_END
