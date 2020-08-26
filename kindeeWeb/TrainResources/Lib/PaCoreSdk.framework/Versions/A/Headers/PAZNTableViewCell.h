//
//  PAZNTableViewCell.h
//  PAZNTableViewCell
//
//  Created by Chris Wendel on 9/10/13.
//  Copyright (c) 2013 Chris Wendel. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <UIKit/UIGestureRecognizerSubclass.h>
#import "PAZNCellScrollView.h"
#import "PAZNLongPressGestureRecognizer.h"
#import "PAZNUtilityButtonTapGestureRecognizer.h"
#import "NSMutableArray+PAZNUtilityButtons.h"

@class PAZNTableViewCell;

typedef NS_ENUM(NSInteger, PAZNCellState)
{
    PAZNkCellStateCenter,
    PAZNkCellStateLeft,
    PAZNkCellStateRight,
};

@protocol PAZNTableViewCellDelegate <NSObject>

@optional
- (void)swipeableTableViewCell:(PAZNTableViewCell *)cell didTriggerLeftUtilityButtonWithIndex:(NSInteger)index;
- (void)swipeableTableViewCell:(PAZNTableViewCell *)cell didTriggerRightUtilityButtonWithIndex:(NSInteger)index;
- (void)swipeableTableViewCell:(PAZNTableViewCell *)cell scrollingToState:(PAZNCellState)state;
- (BOOL)swipeableTableViewCellShouldHideUtilityButtonsOnSwipe:(PAZNTableViewCell *)cell;
- (BOOL)swipeableTableViewCell:(PAZNTableViewCell *)cell canSwipeToState:(PAZNCellState)state;
- (void)swipeableTableViewCellDidEndScrolling:(PAZNTableViewCell *)cell;
- (void)swipeableTableViewCell:(PAZNTableViewCell *)cell didScroll:(UIScrollView *)scrollView;

@end

@interface PAZNTableViewCell : UITableViewCell

@property (nonatomic, copy) NSArray *leftUtilityButtons;
@property (nonatomic, copy) NSArray *rightUtilityButtons;

@property (nonatomic, weak) id <PAZNTableViewCellDelegate> delegate;

- (void)setRightUtilityButtons:(NSArray *)rightUtilityButtons WithButtonWidth:(CGFloat) width;
- (void)setLeftUtilityButtons:(NSArray *)leftUtilityButtons WithButtonWidth:(CGFloat) width;
- (void)hideUtilityButtonsAnimated:(BOOL)animated;
- (void)showLeftUtilityButtonsAnimated:(BOOL)animated;
- (void)showRightUtilityButtonsAnimated:(BOOL)animated;

- (BOOL)isUtilityButtonsHidden;

@end
