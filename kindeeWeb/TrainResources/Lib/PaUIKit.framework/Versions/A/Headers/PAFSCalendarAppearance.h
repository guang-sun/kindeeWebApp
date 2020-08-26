//
//  PAFSCalendarAppearance.h
//  Pods
//
//  Created by DingWenchao on 6/29/15.
//  Copyright © 2016 Wenchao Ding. All rights reserved.
//
//  https://github.com/WenchaoD
//

#import "PAFSCalendarConstants.h"

@class PAFSCalendar;

typedef NS_ENUM(NSInteger, PAFSCalendarCellState) {
    PAFSCalendarCellStateNormal      = 0,
    PAFSCalendarCellStateSelected    = 1,
    PAFSCalendarCellStatePlaceholder = 1 << 1,
    PAFSCalendarCellStateDisabled    = 1 << 2,
    PAFSCalendarCellStateToday       = 1 << 3,
    PAFSCalendarCellStateWeekend     = 1 << 4,
    PAFSCalendarCellStateTodaySelected = PAFSCalendarCellStateToday|PAFSCalendarCellStateSelected
};

typedef NS_ENUM(NSUInteger, PAFSCalendarSeparators) {
    PAFSCalendarSeparatorNone          = 0,
    PAFSCalendarSeparatorInterRows     = 1
};

typedef NS_OPTIONS(NSUInteger, PAFSCalendarCaseOptions) {
    PAFSCalendarCaseOptionsHeaderUsesDefaultCase      = 0,
    PAFSCalendarCaseOptionsHeaderUsesUpperCase        = 1,
    
    PAFSCalendarCaseOptionsWeekdayUsesDefaultCase     = 0 << 4,
    PAFSCalendarCaseOptionsWeekdayUsesUpperCase       = 1 << 4,
    PAFSCalendarCaseOptionsWeekdayUsesSingleUpperCase = 2 << 4,
};

/**
 * PAFSCalendarAppearance determines the fonts and colors of components in the calendar.
 *
 * @see PAFSCalendarDelegateAppearance
 */
@interface PAFSCalendarAppearance : NSObject

/**
 * The font of the day text.
 */
@property (strong, nonatomic) UIFont   *titleFont;

/**
 * The font of the subtitle text.
 */
@property (strong, nonatomic) UIFont   *subtitleFont;

/**
 * The font of the weekday text.
 */
@property (strong, nonatomic) UIFont   *weekdayFont;

/**
 * The font of the month text.
 */
@property (strong, nonatomic) UIFont   *headerTitleFont;

/**
 * The offset of the day text from default position.
 */
@property (assign, nonatomic) CGPoint  titleOffset;

/**
 * The Offset of the day text from default position.
 */
@property (assign, nonatomic) CGPoint  subtitleOffset;

/**
 * The Offset of the event dots from default position.
 */
@property (assign, nonatomic) CGPoint eventOffset;

/**
 * The Offset of the image from default position.
 */
@property (assign, nonatomic) CGPoint imageOffset;

/**
 * The color of event dots.
 */
@property (strong, nonatomic) UIColor  *eventDefaultColor;

/**
 * The color of event dots.
 */
@property (strong, nonatomic) UIColor  *eventSelectionColor;

/**
 * The color of weekday text.
 */
@property (strong, nonatomic) UIColor  *weekdayTextColor;

/**
 * The color of month header text.
 */
@property (strong, nonatomic) UIColor  *headerTitleColor;

/**
 * The date format of the month header.
 */
@property (strong, nonatomic) NSString *headerDateFormat;

/**
 * The alpha value of month label staying on the fringes.
 */
@property (assign, nonatomic) CGFloat  headerMinimumDissolvedAlpha;

/**
 * The day text color for unselected state.
 */
@property (strong, nonatomic) UIColor  *titleDefaultColor;

/**
 * The day text color for selected state.
 */
@property (strong, nonatomic) UIColor  *titleSelectionColor;

/**
 * The day text color for today in the calendar.
 */
@property (strong, nonatomic) UIColor  *titleTodayColor;

/**
 * The day text color for days out of current month.
 */
@property (strong, nonatomic) UIColor  *titlePlaceholderColor;

/**
 * The day text color for weekend.
 */
@property (strong, nonatomic) UIColor  *titleWeekendColor;

/**
 * The subtitle text color for unselected state.
 */
@property (strong, nonatomic) UIColor  *subtitleDefaultColor;

/**
 * The subtitle text color for selected state.
 */
@property (strong, nonatomic) UIColor  *subtitleSelectionColor;

/**
 * The subtitle text color for today in the calendar.
 */
@property (strong, nonatomic) UIColor  *subtitleTodayColor;

/**
 * The subtitle text color for days out of current month.
 */
@property (strong, nonatomic) UIColor  *subtitlePlaceholderColor;

/**
 * The subtitle text color for weekend.
 */
@property (strong, nonatomic) UIColor  *subtitleWeekendColor;

/**
 * The fill color of the shape for selected state.
 */
@property (strong, nonatomic) UIColor  *selectionColor;

/**
 * The fill color of the shape for today.
 */
@property (strong, nonatomic) UIColor  *todayColor;

/**
 * The fill color of the shape for today and selected state.
 */
@property (strong, nonatomic) UIColor  *todaySelectionColor;

/**
 * The border color of the shape for unselected state.
 */
@property (strong, nonatomic) UIColor  *borderDefaultColor;

/**
 * The border color of the shape for selected state.
 */
@property (strong, nonatomic) UIColor  *borderSelectionColor;

/**
 * The border radius, while 1 means a circle, 0 means a rectangle, and the middle value will give it a corner radius.
 */
@property (assign, nonatomic) CGFloat borderRadius;

/**
 * The case options manage the case of month label and weekday symbols.
 *
 * @see PAFSCalendarCaseOptions
 */
@property (assign, nonatomic) PAFSCalendarCaseOptions caseOptions;

/**
 * The line integrations for calendar.
 *
 */
@property (assign, nonatomic) PAFSCalendarSeparators separators;

#if TARGET_INTERFACE_BUILDER

// For preview only
@property (assign, nonatomic) BOOL      fakeSubtitles;
@property (assign, nonatomic) BOOL      fakeEventDots;
@property (assign, nonatomic) NSInteger fakedSelectedDay;

#endif

@end

/**
 * These functions and attributes are deprecated.
 */
@interface PAFSCalendarAppearance (Deprecated)

@property (assign, nonatomic) BOOL useVeryShortWeekdaySymbols PAFSCalendarDeprecated('caseOptions');
@property (assign, nonatomic) CGFloat titleVerticalOffset PAFSCalendarDeprecated('titleOffset');
@property (assign, nonatomic) CGFloat subtitleVerticalOffset PAFSCalendarDeprecated('subtitleOffset');
@property (strong, nonatomic) UIColor *eventColor PAFSCalendarDeprecated('eventDefaultColor');
@property (assign, nonatomic) PAFSCalendarCellShape cellShape PAFSCalendarDeprecated('borderRadius');
@property (assign, nonatomic) BOOL adjustsFontSizeToFitContentSize DEPRECATED_MSG_ATTRIBUTE("The attribute \'adjustsFontSizeToFitContentSize\' is not neccesary anymore.");
- (void)invalidateAppearance PAFSCalendarDeprecated('PAFSCalendar setNeedsConfigureAppearance');

@end



