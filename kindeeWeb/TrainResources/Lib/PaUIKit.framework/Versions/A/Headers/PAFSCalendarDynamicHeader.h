//
//  PAFSCalendarDynamicHeader.h
//  Pods
//
//  Created by DingWenchao on 6/29/15.
//
//  动感头文件，仅供框架内部使用。
//  Private header, don't use it.
//

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>

#import "PAFSCalendar.h"
#import "PAFSCalendarCell.h"
#import "PAFSCalendarHeaderView.h"
#import "PAFSCalendarStickyHeader.h"
#import "PAFSCalendarCollectionView.h"
#import "PAFSCalendarCollectionViewLayout.h"
#import "PAFSCalendarScopeHandle.h"
#import "PAFSCalendarCalculator.h"
#import "PAFSCalendarTransitionCoordinator.h"
#import "PAFSCalendarDelegationProxy.h"

@interface PAFSCalendar (Dynamic)

@property (readonly, nonatomic) PAFSCalendarCollectionView *collectionView;
@property (readonly, nonatomic) PAFSCalendarScopeHandle *scopeHandle;
@property (readonly, nonatomic) PAFSCalendarCollectionViewLayout *collectionViewLayout;
@property (readonly, nonatomic) PAFSCalendarTransitionCoordinator *transitionCoordinator;
@property (readonly, nonatomic) PAFSCalendarCalculator *calculator;
@property (readonly, nonatomic) BOOL floatingMode;
@property (readonly, nonatomic) NSArray *visibleStickyHeaders;
@property (readonly, nonatomic) CGFloat preferredHeaderHeight;
@property (readonly, nonatomic) CGFloat preferredWeekdayHeight;
@property (readonly, nonatomic) UIView *bottomBorder;

@property (readonly, nonatomic) NSCalendar *gregorian;
@property (readonly, nonatomic) NSDateComponents *components;
@property (readonly, nonatomic) NSDateFormatter *formatter;

@property (readonly, nonatomic) UIView *contentView;
@property (readonly, nonatomic) UIView *daysContainer;

@property (assign, nonatomic) BOOL needsAdjustingViewFrame;

- (void)invalidateHeaders;
- (void)adjustMonthPosition;
- (void)configureAppearance;

- (BOOL)isPageInRange:(NSDate *)page;
- (BOOL)isDateInRange:(NSDate *)date;

- (CGSize)sizeThatFits:(CGSize)size scope:(PAFSCalendarScope)scope;

@end

@interface PAFSCalendarAppearance (Dynamic)

@property (readwrite, nonatomic) PAFSCalendar *calendar;

@property (readonly, nonatomic) NSDictionary *backgroundColors;
@property (readonly, nonatomic) NSDictionary *titleColors;
@property (readonly, nonatomic) NSDictionary *subtitleColors;
@property (readonly, nonatomic) NSDictionary *borderColors;

@end

@interface PAFSCalendarWeekdayView (Dynamic)

@property (readwrite, nonatomic) PAFSCalendar *calendar;

@end

@interface PAFSCalendarCollectionViewLayout (Dynamic)

@property (readonly, nonatomic) CGSize estimatedItemSize;

@end

@interface PAFSCalendarDelegationProxy()<PAFSCalendarDataSource,PAFSCalendarDelegate,PAFSCalendarDelegateAppearance>
@end


