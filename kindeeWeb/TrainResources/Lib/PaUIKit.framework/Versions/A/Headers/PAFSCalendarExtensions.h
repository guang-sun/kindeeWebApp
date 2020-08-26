//
//  FSCalendarExtensions.h
//  FSCalendar
//
//  Created by dingwenchao on 10/8/16.
//  Copyright © 2016 Wenchao Ding. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface UIView (PAFSCalendarExtensions)

@property (nonatomic) CGFloat pa_fs_width;
@property (nonatomic) CGFloat pa_fs_height;

@property (nonatomic) CGFloat pa_fs_top;
@property (nonatomic) CGFloat pa_fs_left;
@property (nonatomic) CGFloat pa_fs_bottom;
@property (nonatomic) CGFloat pa_fs_right;

@end


@interface CALayer (PAFSCalendarExtensions)

@property (nonatomic) CGFloat pa_fs_width;
@property (nonatomic) CGFloat pa_fs_height;

@property (nonatomic) CGFloat pa_fs_top;
@property (nonatomic) CGFloat pa_fs_left;
@property (nonatomic) CGFloat pa_fs_bottom;
@property (nonatomic) CGFloat pa_fs_right;

@end


@interface NSCalendar (PAFSCalendarExtensions)

- (nullable NSDate *)pa_fs_firstDayOfMonth:(NSDate *)month;
- (nullable NSDate *)pa_fs_lastDayOfMonth:(NSDate *)month;
- (nullable NSDate *)pa_fs_firstDayOfWeek:(NSDate *)week;
- (nullable NSDate *)pa_fs_lastDayOfWeek:(NSDate *)week;
- (nullable NSDate *)pa_fs_middleDayOfWeek:(NSDate *)week;
- (NSInteger)pa_fs_numberOfDaysInMonth:(NSDate *)month;

@end

@interface NSMapTable (PAFSCalendarExtensions)

- (void)setObject:(nullable id)obj forKeyedSubscript:(id<NSCopying>)key;
- (id)objectForKeyedSubscript:(id<NSCopying>)key;

@end

@interface NSCache (PAFSCalendarExtensions)

- (void)setObject:(nullable id)obj forKeyedSubscript:(id<NSCopying>)key;
- (id)objectForKeyedSubscript:(id<NSCopying>)key;

@end


@interface NSObject (PAFSCalendarExtensions)

#define IVAR_DEF(SET,GET,TYPE) \
- (void)pa_fs_set##SET##Variable:(TYPE)value forKey:(NSString *)key; \
- (TYPE)pa_fs_##GET##VariableForKey:(NSString *)key;
IVAR_DEF(Bool, bool, BOOL)
IVAR_DEF(Float, float, CGFloat)
IVAR_DEF(Integer, integer, NSInteger)
IVAR_DEF(UnsignedInteger, unsignedInteger, NSUInteger)
#undef IVAR_DEF

- (void)pa_fs_setVariable:(id)variable forKey:(NSString *)key;
- (id)pa_fs_variableForKey:(NSString *)key;

- (nullable id)pa_fs_performSelector:(SEL)selector withObjects:(nullable id)firstObject, ... NS_REQUIRES_NIL_TERMINATION;

@end

NS_ASSUME_NONNULL_END
