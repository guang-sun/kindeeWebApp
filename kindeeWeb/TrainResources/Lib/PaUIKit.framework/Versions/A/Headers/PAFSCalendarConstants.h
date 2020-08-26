//
//  PAFSCalendarConstane.h
//  PAFSCalendar
//
//  Created by dingwenchao on 8/28/15.
//  Copyright © 2016 Wenchao Ding. All rights reserved.
//
//  https://github.com/WenchaoD
//

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>

#pragma mark - Constants

CG_EXTERN CGFloat const PAFSCalendarStandardHeaderHeight;
CG_EXTERN CGFloat const PAFSCalendarStandardWeekdayHeight;
CG_EXTERN CGFloat const PAFSCalendarStandardMonthlyPageHeight;
CG_EXTERN CGFloat const PAFSCalendarStandardWeeklyPageHeight;
CG_EXTERN CGFloat const PAFSCalendarStandardCellDiameter;
CG_EXTERN CGFloat const PAFSCalendarStandardSeparatorThickness;
CG_EXTERN CGFloat const PAFSCalendarAutomaticDimension;
CG_EXTERN CGFloat const PAFSCalendarDefaultBounceAnimationDuration;
CG_EXTERN CGFloat const PAFSCalendarStandardRowHeight;
CG_EXTERN CGFloat const PAFSCalendarStandardTitleTextSize;
CG_EXTERN CGFloat const PAFSCalendarStandardSubtitleTextSize;
CG_EXTERN CGFloat const PAFSCalendarStandardWeekdayTextSize;
CG_EXTERN CGFloat const PAFSCalendarStandardHeaderTextSize;
CG_EXTERN CGFloat const PAFSCalendarMaximumEventDotDiameter;
CG_EXTERN CGFloat const PAFSCalendarStandardScopeHandleHeight;

UIKIT_EXTERN NSInteger const PAFSCalendarDefaultHourComponent;

UIKIT_EXTERN NSString * const PAFSCalendarDefaultCellReuseIdentifier;
UIKIT_EXTERN NSString * const PAFSCalendarBlankCellReuseIdentifier;
UIKIT_EXTERN NSString * const PAFSCalendarInvalidArgumentsExceptionName;

CG_EXTERN CGPoint const CGPointInfinity;
CG_EXTERN CGSize const CGSizeAutomatic;

#if TARGET_INTERFACE_BUILDER
#define PAFSCalendarDeviceIsIPad NO
#else
#define PAFSCalendarDeviceIsIPad [[UIDevice currentDevice].model hasPrefix:@"iPad"]
#endif

#define PAFSCalendarStandardSelectionColor   PAFSColorRGBA(31,119,219,1.0)
#define PAFSCalendarStandardTodayColor       PAFSColorRGBA(198,51,42 ,1.0)
#define PAFSCalendarStandardTitleTextColor   PAFSColorRGBA(14,69,221 ,1.0)
#define PAFSCalendarStandardEventDotColor    PAFSColorRGBA(31,119,219,0.75)

#define PAFSCalendarStandardLineColor        [[UIColor lightGrayColor] colorWithAlphaComponent:0.30]
#define PAFSCalendarStandardSeparatorColor   [[UIColor lightGrayColor] colorWithAlphaComponent:0.60]
#define PAFSCalendarStandardScopeHandleColor [[UIColor lightGrayColor] colorWithAlphaComponent:0.50]

#define PAFSColorRGBA(r,g,b,a) [UIColor colorWithRed:r/255.0 green:g/255.0 blue:b/255.0 alpha:a]
#define PAFSCalendarInAppExtension [[[NSBundle mainBundle] bundlePath] hasSuffix:@".appex"]

#define PAFSCalendarFloor(c) floorf(c)
#define PAFSCalendarRound(c) roundf(c)
#define PAFSCalendarCeil(c) ceilf(c)
#define PAFSCalendarMod(c1,c2) fmodf(c1,c2)

#define PAFSCalendarHalfRound(c) (PAFSCalendarRound(c*2)*0.5)
#define PAFSCalendarHalfFloor(c) (PAFSCalendarFloor(c*2)*0.5)
#define PAFSCalendarHalfCeil(c) (PAFSCalendarCeil(c*2)*0.5)

#define PAFSCalendarUseWeakSelf __weak __typeof__(self) PAFSCalendarWeakSelf = self;
#define PAFSCalendarUseStrongSelf __strong __typeof__(self) self = PAFSCalendarWeakSelf;


#pragma mark - Deprecated

#define PAFSCalendarDeprecated(instead) DEPRECATED_MSG_ATTRIBUTE(" Use " # instead " instead")

PAFSCalendarDeprecated('borderRadius')
typedef NS_ENUM(NSUInteger, PAFSCalendarCellShape) {
    PAFSCalendarCellShapeCircle    = 0,
    PAFSCalendarCellShapeRectangle = 1
};

typedef NS_ENUM(NSUInteger, PAFSCalendarUnit) {
    PAFSCalendarUnitMonth = NSCalendarUnitMonth,
    PAFSCalendarUnitWeekOfYear = NSCalendarUnitWeekOfYear,
    PAFSCalendarUnitDay = NSCalendarUnitDay
};

static inline void PAFSCalendarSliceCake(CGFloat cake, NSInteger count, CGFloat *pieces) {
    CGFloat total = cake;
    for (int i = 0; i < count; i++) {
        NSInteger remains = count - i;
        CGFloat piece = PAFSCalendarRound(total/remains*2)*0.5;
        total -= piece;
        pieces[i] = piece;
    }
}



