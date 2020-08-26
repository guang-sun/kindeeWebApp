//
//  PAZNAddressPopupModel.h
//  MLPlayer
//
//  Created by 罗红(EX-LUOHONG003) on 2019/2/19.
//  Copyright © 2019 平安知鸟. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "PAZNAddressDataSource.h"

NS_ASSUME_NONNULL_BEGIN

@interface PAZNAddressPopupModel : NSObject<PAZNAddressDataSource>

@property (nonatomic, strong) NSArray *areas;
@property (nonatomic, copy) NSString *title; //标题
@property (nonatomic, assign) NSInteger maxColumn; //支持选择的级别,最大支持省，市，县3级选择
@property (nonatomic, copy) NSString *address; //省，市，县以逗号隔开

@end

NS_ASSUME_NONNULL_END
