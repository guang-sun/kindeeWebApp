//
//  PAZNUtilityButtonView.h
//  PAZNTableViewCell
//
//  Created by Matt Bowman on 11/27/13.
//  Copyright (c) 2013 Chris Wendel. All rights reserved.
//

#import <UIKit/UIKit.h>
@class PAZNTableViewCell;

#define PAZNkUtilityButtonWidthDefault 90

@interface PAZNUtilityButtonView : UIView

- (id)initWithUtilityButtons:(NSArray *)utilityButtons parentCell:(PAZNTableViewCell *)parentCell utilityButtonSelector:(SEL)utilityButtonSelector;
- (id)initWithFrame:(CGRect)frame utilityButtons:(NSArray *)utilityButtons parentCell:(PAZNTableViewCell *)parentCell utilityButtonSelector:(SEL)utilityButtonSelector;

@property (nonatomic, weak, readonly) PAZNTableViewCell *parentCell;
@property (nonatomic, copy) NSArray *utilityButtons;
@property (nonatomic, assign) SEL utilityButtonSelector;

- (void)setUtilityButtons:(NSArray *)utilityButtons WithButtonWidth:(CGFloat)width;
- (void)pushBackgroundColors;
- (void)popBackgroundColors;

@end
