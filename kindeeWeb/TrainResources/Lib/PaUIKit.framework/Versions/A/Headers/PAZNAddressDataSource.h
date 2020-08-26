//
//  PAZNAddressDataSource.h
//  MLPlayer
//
//  Created by 罗红(EX-LUOHONG003) on 2019/2/19.
//  Copyright © 2019 平安知鸟. All rights reserved.
//

#import "PAZNPopupDataSource.h"

#ifndef PAZNAddressDataSource_h
#define PAZNAddressDataSource_h

@protocol  PAZNAddressDataSource <NSObject, PAZNPopupDataSource>

- (NSArray *)areas; //选择的地区数据
- (NSString *)title; //标题
- (NSInteger)maxColumn; //支持选择的级别,最大支持省，市，县3级选择
- (NSString *)address; //省，市，县以逗号隔开

@end

#endif /* PAZNAddressDataSource_h */
