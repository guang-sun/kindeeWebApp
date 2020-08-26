//
//  PAFSCalendarTransitionCoordinator.h
//  PAFSCalendar
//
//  Created by dingwenchao on 3/13/16.
//  Copyright © 2016 Wenchao Ding. All rights reserved.
//

#import "PAFSCalendar.h"
#import "PAFSCalendarCollectionView.h"
#import "PAFSCalendarCollectionViewLayout.h"
#import "PAFSCalendarScopeHandle.h"

typedef NS_ENUM(NSUInteger, PAFSCalendarTransition) {
    PAFSCalendarTransitionNone,
    PAFSCalendarTransitionMonthToWeek,
    PAFSCalendarTransitionWeekToMonth
};
typedef NS_ENUM(NSUInteger, PAFSCalendarTransitionState) {
    PAFSCalendarTransitionStateIdle,
    PAFSCalendarTransitionStateChanging,
    PAFSCalendarTransitionStateFinishing,
};

@interface PAFSCalendarTransitionCoordinator : NSObject <UIGestureRecognizerDelegate>

@property (weak, nonatomic) PAFSCalendar *calendar;
@property (weak, nonatomic) PAFSCalendarCollectionView *collectionView;
@property (weak, nonatomic) PAFSCalendarCollectionViewLayout *collectionViewLayout;

@property (assign, nonatomic) PAFSCalendarTransition transition;
@property (assign, nonatomic) PAFSCalendarTransitionState state;

@property (assign, nonatomic) CGSize cachedMonthSize;

@property (readonly, nonatomic) PAFSCalendarScope representingScope;

- (instancetype)initWithCalendar:(PAFSCalendar *)calendar;

- (void)performScopeTransitionFromScope:(PAFSCalendarScope)fromScope toScope:(PAFSCalendarScope)toScope animated:(BOOL)animated;
- (void)performBoundingRectTransitionFromMonth:(NSDate *)fromMonth toMonth:(NSDate *)toMonth duration:(CGFloat)duration;

- (void)handleScopeGesture:(id)sender;

@end


@interface PAFSCalendarTransitionAttributes : NSObject

@property (assign, nonatomic) CGRect sourceBounds;
@property (assign, nonatomic) CGRect targetBounds;
@property (strong, nonatomic) NSDate *sourcePage;
@property (strong, nonatomic) NSDate *targetPage;
@property (assign, nonatomic) NSInteger focusedRowNumber;
@property (assign, nonatomic) NSDate *focusedDate;
@property (strong, nonatomic) NSDate *firstDayOfMonth;

@end

