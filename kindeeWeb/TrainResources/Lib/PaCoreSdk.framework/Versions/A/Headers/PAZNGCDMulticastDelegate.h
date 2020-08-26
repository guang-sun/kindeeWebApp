//
//  PAZNGCDMulticastDelegate.h
//
//  Created by Cyril Zhou on 2017/3/2.
//  Copyright © 2017年 Cyril Zhou. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface PAZNGCDMulticastDelegate : NSObject

/**
 是否同步转发(默认NO，避免死锁为YES时delegateQueue不能为mainquen)
 */
@property (nonatomic, assign)  BOOL isSyncForward;

- (void)addDelegate:(id)delegate delegateQueue:(dispatch_queue_t)delegateQueue;
- (void)removeDelegate:(id)delegate delegateQueue:(dispatch_queue_t)delegateQueue;
- (void)removeDelegate:(id)delegate;
- (void)removeAllDelegates;

- (NSUInteger)count;
- (NSUInteger)countOfClass:(Class)aClass;
- (NSUInteger)countForSelector:(SEL)aSelector;

- (BOOL)hasDelegateThatRespondsToSelector:(SEL)aSelector;

@end
