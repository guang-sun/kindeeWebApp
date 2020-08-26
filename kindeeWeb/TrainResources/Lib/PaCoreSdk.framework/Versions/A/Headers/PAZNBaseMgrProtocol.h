//
//  PAZNBaseMgrProtocol.h
//  PaCoreSdk
//
//  Created by w-chen on 2017/8/22.
//  Copyright © 2017年 Cyril Zhou. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol PAZNBaseMgrProtocol <NSObject>

- (void)addDelegate:(id)delegate delegateQueue:(dispatch_queue_t)delegateQueue;
- (void)removeDelegate:(id)delegate delegateQueue:(dispatch_queue_t)delegateQueue;
- (void)removeDelegate:(id)delegate;
- (void)removeAllDelegates;

@end
