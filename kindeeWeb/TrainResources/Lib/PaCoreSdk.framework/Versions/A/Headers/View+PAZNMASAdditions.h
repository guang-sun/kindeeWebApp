//
//  UIView+MASAdditions.h
//  Masonry
//
//  Created by Jonas Budelmann on 20/07/13.
//  Copyright (c) 2013 cloudling. All rights reserved.
//

#import "PAZNMASUtilities.h"
#import "PAZNMASConstraintMaker.h"
#import "PAZNMASViewAttribute.h"

/**
 *	Provides constraint maker block
 *  and convience methods for creating MASViewAttribute which are view + NSLayoutAttribute pairs
 */
@interface MAS_VIEW (PAZNMASAdditions)

/**
 *	following properties return a new MASViewAttribute with current view and appropriate NSLayoutAttribute
 */
@property (nonatomic, strong, readonly) PAZNMASViewAttribute *pazn_mas_left;
@property (nonatomic, strong, readonly) PAZNMASViewAttribute *pazn_mas_top;
@property (nonatomic, strong, readonly) PAZNMASViewAttribute *pazn_mas_right;
@property (nonatomic, strong, readonly) PAZNMASViewAttribute *pazn_mas_bottom;
@property (nonatomic, strong, readonly) PAZNMASViewAttribute *pazn_mas_leading;
@property (nonatomic, strong, readonly) PAZNMASViewAttribute *pazn_mas_trailing;
@property (nonatomic, strong, readonly) PAZNMASViewAttribute *pazn_mas_width;
@property (nonatomic, strong, readonly) PAZNMASViewAttribute *pazn_mas_height;
@property (nonatomic, strong, readonly) PAZNMASViewAttribute *pazn_mas_centerX;
@property (nonatomic, strong, readonly) PAZNMASViewAttribute *pazn_mas_centerY;
@property (nonatomic, strong, readonly) PAZNMASViewAttribute *pazn_mas_baseline;
@property (nonatomic, strong, readonly) PAZNMASViewAttribute *(^pazn_mas_attribute)(NSLayoutAttribute attr);

#if TARGET_OS_IPHONE

@property (nonatomic, strong, readonly) PAZNMASViewAttribute *pazn_mas_leftMargin;
@property (nonatomic, strong, readonly) PAZNMASViewAttribute *pazn_mas_rightMargin;
@property (nonatomic, strong, readonly) PAZNMASViewAttribute *pazn_mas_topMargin;
@property (nonatomic, strong, readonly) PAZNMASViewAttribute *pazn_mas_bottomMargin;
@property (nonatomic, strong, readonly) PAZNMASViewAttribute *pazn_mas_leadingMargin;
@property (nonatomic, strong, readonly) PAZNMASViewAttribute *pazn_mas_trailingMargin;
@property (nonatomic, strong, readonly) PAZNMASViewAttribute *pazn_mas_centerXWithinMargins;
@property (nonatomic, strong, readonly) PAZNMASViewAttribute *pazn_mas_centerYWithinMargins;

#endif

/**
 *	a key to associate with this view
 */
@property (nonatomic, strong) id pazn_mas_key;

/**
 *	Finds the closest common superview between this view and another view
 *
 *	@param	view	other view
 *
 *	@return	returns nil if common superview could not be found
 */
- (instancetype)pazn_mas_closestCommonSuperview:(MAS_VIEW *)view;

/**
 *  Creates a PAZNMASConstraintMaker with the callee view.
 *  Any constraints defined are added to the view or the appropriate superview once the block has finished executing
 *
 *  @param block scope within which you can build up the constraints which you wish to apply to the view.
 *
 *  @return Array of created MASConstraints
 */
- (NSArray *)pazn_mas_makeConstraints:(void(^)(PAZNMASConstraintMaker *make))block;

/**
 *  Creates a PAZNMASConstraintMaker with the callee view.
 *  Any constraints defined are added to the view or the appropriate superview once the block has finished executing.
 *  If an existing constraint exists then it will be updated instead.
 *
 *  @param block scope within which you can build up the constraints which you wish to apply to the view.
 *
 *  @return Array of created/updated MASConstraints
 */
- (NSArray *)pazn_mas_updateConstraints:(void(^)(PAZNMASConstraintMaker *make))block;

/**
 *  Creates a PAZNMASConstraintMaker with the callee view.
 *  Any constraints defined are added to the view or the appropriate superview once the block has finished executing.
 *  All constraints previously installed for the view will be removed.
 *
 *  @param block scope within which you can build up the constraints which you wish to apply to the view.
 *
 *  @return Array of created/updated MASConstraints
 */
- (NSArray *)pazn_mas_remakeConstraints:(void(^)(PAZNMASConstraintMaker *make))block;

@end
