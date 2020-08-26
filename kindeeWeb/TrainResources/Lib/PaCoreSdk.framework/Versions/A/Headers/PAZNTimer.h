//
//  PAZNTimer.h
//  PaCoreSdk
//
//  Created by 胡铭(智慧教育) on 2020/5/13.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface PAZNTimer : NSObject

/**
 启动计时器

 @param interval 间隔
 @param queue 队列
 @param repeats 是否重复
 @param immediate 是否立即开启
 @param block 事件回调
 return PAQATimer
 */
+ (PAZNTimer *)scheduleTimerWithTimeInterval:(NSTimeInterval)interval queue:(dispatch_queue_t _Nullable)queue repeats:(BOOL)repeats startImmediate:(BOOL)immediate action:(dispatch_block_t)block;

/**
 启动计时器
 */
- (void)resume;

/**
 暂停计时器
 */
- (void)suspend;

/**
 取消计时器
 */
- (void)invalidate;
@end

NS_ASSUME_NONNULL_END
