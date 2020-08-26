//
//  PAZNAddressDisplayRule.h
//  MLPlayer
//
//  Created by 罗红(EX-LUOHONG003) on 2019/2/19.
//  Copyright © 2019 平安知鸟. All rights reserved.
//

/*
 
 Use Tips：
 1、import headers
 #import "PAZNAddressDisplayRule.h"

 2、display address popup like below
 
 if ([PAZNAddressDisplayRule needDisplay]) {
 PAZNAddressPopupModel *model = [[PAZNAddressPopupModel alloc] init];
 model.title = @"开户地区";
 model.maxColumn = 3;
 model.address = self.testAddress;
 [PAZNAddressDisplayRule displayClass:@"PAZNAddressView" dataSource:model onView:self.view.window dismiss:^(BOOL sure, NSString * _Nonnull result) {
 NSLog(@"address result:%@",result);
 if (sure) {
 self.testAddress = result;
 }
 }];
 }
 
 */

#import "PAZNPopupDisplayRule.h"
#import "PAZNAddressPopupModel.h"

NS_ASSUME_NONNULL_BEGIN

@interface PAZNAddressDisplayRule : PAZNPopupDisplayRule

@end

NS_ASSUME_NONNULL_END
