//
//  FSCalendarScopeHandle.h
//  FSCalendar
//
//  Created by dingwenchao on 4/29/16.
//  Copyright © 2016 Wenchao Ding. All rights reserved.
//

#import <UIKit/UIKit.h>

@class PAFSCalendar;

@interface PAFSCalendarScopeHandle : UIView <UIGestureRecognizerDelegate>

@property (weak, nonatomic) UIPanGestureRecognizer *panGesture;
@property (weak, nonatomic) PAFSCalendar *calendar;

- (void)handlePan:(id)sender;

@end
