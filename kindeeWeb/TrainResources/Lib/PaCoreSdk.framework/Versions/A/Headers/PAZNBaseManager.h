//
//  PAZNBaseManager.h
//
//  Created by Cyril Zhou on 2017/3/2.
//  Copyright © 2017年 Cyril Zhou. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "PAZNBaseMgrProtocol.h"

@interface PAZNBaseManager : NSObject <PAZNBaseMgrProtocol>
{
    dispatch_queue_t managerQueue;
    void *managerQueueTag;

    id multicastDelegate;
}

- (id)init;
- (id)initWithDispatchQueue:(dispatch_queue_t)queue;

- (dispatch_queue_t)managerQueue;
- (void *)managerQueueTag;
- (NSString *)managerName;

- (void)addDelegate:(id)delegate delegateQueue:(dispatch_queue_t)delegateQueue;
- (void)removeDelegate:(id)delegate delegateQueue:(dispatch_queue_t)delegateQueue;
- (void)removeDelegate:(id)delegate;
- (void)removeAllDelegates;

@end
