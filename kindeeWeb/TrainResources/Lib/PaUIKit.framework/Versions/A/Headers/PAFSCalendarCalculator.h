//
//  FSCalendarCalculator.h
//  FSCalendar
//
//  Created by dingwenchao on 30/10/2016.
//  Copyright © 2016 Wenchao Ding. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>

struct PAFSCalendarCoordinate {
    NSInteger row;
    NSInteger column;
};
typedef struct PAFSCalendarCoordinate PAFSCalendarCoordinate;

@interface PAFSCalendarCalculator : NSObject

@property (weak  , nonatomic) PAFSCalendar *calendar;

@property (readonly, nonatomic) NSInteger numberOfSections;

- (instancetype)initWithCalendar:(PAFSCalendar *)calendar;

- (NSDate *)safeDateForDate:(NSDate *)date;

- (NSDate *)dateForIndexPath:(NSIndexPath *)indexPath;
- (NSDate *)dateForIndexPath:(NSIndexPath *)indexPath scope:(PAFSCalendarScope)scope;
- (NSIndexPath *)indexPathForDate:(NSDate *)date;
- (NSIndexPath *)indexPathForDate:(NSDate *)date scope:(PAFSCalendarScope)scope;
- (NSIndexPath *)indexPathForDate:(NSDate *)date atMonthPosition:(PAFSCalendarMonthPosition)position;
- (NSIndexPath *)indexPathForDate:(NSDate *)date atMonthPosition:(PAFSCalendarMonthPosition)position scope:(PAFSCalendarScope)scope;

- (NSDate *)pageForSection:(NSInteger)section;
- (NSDate *)weekForSection:(NSInteger)section;
- (NSDate *)monthForSection:(NSInteger)section;
- (NSDate *)monthHeadForSection:(NSInteger)section;

- (NSInteger)numberOfHeadPlaceholdersForMonth:(NSDate *)month;
- (NSInteger)numberOfRowsInMonth:(NSDate *)month;
- (NSInteger)numberOfRowsInSection:(NSInteger)section;

- (PAFSCalendarMonthPosition)monthPositionForIndexPath:(NSIndexPath *)indexPath;
- (PAFSCalendarCoordinate)coordinateForIndexPath:(NSIndexPath *)indexPath;

- (void)reloadSections;

@end
