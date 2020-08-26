//
//  PAZNAddressView.h
//  MLPlayer
//
//  Created by 罗红(EX-LUOHONG003) on 2019/2/19.
//  Copyright © 2019 平安知鸟. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "PAZNAddressDataSource.h"
#import "PAZNPopupContentProtocol.h"


@interface PAZNAddressView : UIView<PAZNPopupContentProtocol>

@property (nonatomic, strong) id<PAZNAddressDataSource> model;

- (instancetype)initWithFrame:(CGRect)frame title:(NSString *)title maxColumn:(NSInteger)maxColumn;

@end
