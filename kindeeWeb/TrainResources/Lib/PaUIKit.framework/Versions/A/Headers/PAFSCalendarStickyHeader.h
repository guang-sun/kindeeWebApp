//
//  PAFSCalendarStaticHeader.h
//  PAFSCalendar
//
//  Created by dingwenchao on 9/17/15.
//  Copyright (c) 2015 Wenchao Ding. All rights reserved.
//

#import <UIKit/UIKit.h>

@class PAFSCalendar,PAFSCalendarAppearance;

@interface PAFSCalendarStickyHeader : UICollectionReusableView

@property (weak, nonatomic) PAFSCalendar *calendar;

@property (weak, nonatomic) UILabel *titleLabel;

@property (strong, nonatomic) NSDate *month;

- (void)configureAppearance;

@end
