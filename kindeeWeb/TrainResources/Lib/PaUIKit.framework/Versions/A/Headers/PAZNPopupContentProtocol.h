//
//  PAZNPopupContentProtocol.h
//  MLPlayer
//
//  Created by 罗红(EX-LUOHONG003) on 2019/1/11.
//  Copyright © 2019 平安知鸟. All rights reserved.
//

#import "PAZNPopupDataSource.h"

#ifndef PAZNPopupContentProtocol_h
#define PAZNPopupContentProtocol_h

@protocol PAZNPopupContentProtocol <NSObject>

@optional
+(void)presentPopupOnView:(UIView *)view dismiss:(void (^)(void))block;
+(void)presentPopupOnView:(UIView *)view dataSource:(id<PAZNPopupDataSource>)dataSource dismiss:(void (^)(BOOL sure, NSString *result))block;

@end

#endif /* PAZNPopupContentProtocol_h */
