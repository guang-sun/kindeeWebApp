//
//  NSTimer+PAZNExtra.h
//

#import <Foundation/Foundation.h>

@interface NSTimer (PAZNExtra)

+ (instancetype)pazn_scheduleTimerWithTimeInterval:(NSTimeInterval)seconds repeats:(BOOL)repeats usingBlock:(void (^)(NSTimer *timer))block;

+ (instancetype)pazn_timerWithTimeInterval:(NSTimeInterval)seconds repeats:(BOOL)repeats usingBlock:(void (^)(NSTimer *timer))block;

@end
