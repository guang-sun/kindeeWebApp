//
//  PAZNCountDown.h
//  MLPlayer
//
//  Created by 罗红(EX-LUOHONG003) on 2020/9/1.
//  Copyright © 2020 平安知鸟. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface PAZNCountDown : NSObject

@property (nonatomic, assign) BOOL userInteractionEnabled;
@property (nonatomic, copy) void (^endOfCountDown)(void);

+ (PAZNCountDown *)shareInstance;

- (void)start;
- (void)stop;
- (void)pause;
- (void)resume;

@end

NS_ASSUME_NONNULL_END
