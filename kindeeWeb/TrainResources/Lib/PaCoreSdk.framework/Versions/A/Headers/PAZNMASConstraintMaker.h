//
//  PAZNMASConstraintMaker.h
//  Masonry
//
//  Created by Jonas Budelmann on 20/07/13.
//  Copyright (c) 2013 cloudling. All rights reserved.
//

#import "PAZNMASConstraint.h"
#import "PAZNMASUtilities.h"

typedef NS_OPTIONS(NSInteger, PAZNMASAttribute) {
    PAZNMASAttributeLeft = 1 << NSLayoutAttributeLeft,
    PAZNMASAttributeRight = 1 << NSLayoutAttributeRight,
    PAZNMASAttributeTop = 1 << NSLayoutAttributeTop,
    PAZNMASAttributeBottom = 1 << NSLayoutAttributeBottom,
    PAZNMASAttributeLeading = 1 << NSLayoutAttributeLeading,
    PAZNMASAttributeTrailing = 1 << NSLayoutAttributeTrailing,
    PAZNMASAttributeWidth = 1 << NSLayoutAttributeWidth,
    PAZNMASAttributeHeight = 1 << NSLayoutAttributeHeight,
    PAZNMASAttributeCenterX = 1 << NSLayoutAttributeCenterX,
    PAZNMASAttributeCenterY = 1 << NSLayoutAttributeCenterY,
    PAZNMASAttributeBaseline = 1 << NSLayoutAttributeBaseline,
    
#if TARGET_OS_IPHONE
    
    PAZNMASAttributeLeftMargin = 1 << NSLayoutAttributeLeftMargin,
    PAZNMASAttributeRightMargin = 1 << NSLayoutAttributeRightMargin,
    PAZNMASAttributeTopMargin = 1 << NSLayoutAttributeTopMargin,
    PAZNMASAttributeBottomMargin = 1 << NSLayoutAttributeBottomMargin,
    PAZNMASAttributeLeadingMargin = 1 << NSLayoutAttributeLeadingMargin,
    PAZNMASAttributeTrailingMargin = 1 << NSLayoutAttributeTrailingMargin,
    PAZNMASAttributeCenterXWithinMargins = 1 << NSLayoutAttributeCenterXWithinMargins,
    PAZNMASAttributeCenterYWithinMargins = 1 << NSLayoutAttributeCenterYWithinMargins,

#endif
    
};

/**
 *  Provides factory methods for creating MASConstraints.
 *  Constraints are collected until they are ready to be installed
 *
 */
@interface PAZNMASConstraintMaker : NSObject

/**
 *	The following properties return a new MASViewConstraint
 *  with the first item set to the makers associated view and the appropriate MASViewAttribute
 */
@property (nonatomic, strong, readonly) PAZNMASConstraint *left;
@property (nonatomic, strong, readonly) PAZNMASConstraint *top;
@property (nonatomic, strong, readonly) PAZNMASConstraint *right;
@property (nonatomic, strong, readonly) PAZNMASConstraint *bottom;
@property (nonatomic, strong, readonly) PAZNMASConstraint *leading;
@property (nonatomic, strong, readonly) PAZNMASConstraint *trailing;
@property (nonatomic, strong, readonly) PAZNMASConstraint *width;
@property (nonatomic, strong, readonly) PAZNMASConstraint *height;
@property (nonatomic, strong, readonly) PAZNMASConstraint *centerX;
@property (nonatomic, strong, readonly) PAZNMASConstraint *centerY;
@property (nonatomic, strong, readonly) PAZNMASConstraint *baseline;

#if TARGET_OS_IPHONE

@property (nonatomic, strong, readonly) PAZNMASConstraint *leftMargin;
@property (nonatomic, strong, readonly) PAZNMASConstraint *rightMargin;
@property (nonatomic, strong, readonly) PAZNMASConstraint *topMargin;
@property (nonatomic, strong, readonly) PAZNMASConstraint *bottomMargin;
@property (nonatomic, strong, readonly) PAZNMASConstraint *leadingMargin;
@property (nonatomic, strong, readonly) PAZNMASConstraint *trailingMargin;
@property (nonatomic, strong, readonly) PAZNMASConstraint *centerXWithinMargins;
@property (nonatomic, strong, readonly) PAZNMASConstraint *centerYWithinMargins;

#endif

/**
 *  Returns a block which creates a new MASCompositeConstraint with the first item set
 *  to the makers associated view and children corresponding to the set bits in the
 *  PAZNMASAttribute parameter. Combine multiple attributes via binary-or.
 */
@property (nonatomic, strong, readonly) PAZNMASConstraint *(^attributes)(PAZNMASAttribute attrs);

/**
 *	Creates a MASCompositeConstraint with type MASCompositeConstraintTypeEdges
 *  which generates the appropriate MASViewConstraint children (top, left, bottom, right)
 *  with the first item set to the makers associated view
 */
@property (nonatomic, strong, readonly) PAZNMASConstraint *edges;

/**
 *	Creates a MASCompositeConstraint with type MASCompositeConstraintTypeSize
 *  which generates the appropriate MASViewConstraint children (width, height)
 *  with the first item set to the makers associated view
 */
@property (nonatomic, strong, readonly) PAZNMASConstraint *size;

/**
 *	Creates a MASCompositeConstraint with type MASCompositeConstraintTypeCenter
 *  which generates the appropriate MASViewConstraint children (centerX, centerY)
 *  with the first item set to the makers associated view
 */
@property (nonatomic, strong, readonly) PAZNMASConstraint *center;

/**
 *  Whether or not to check for an existing constraint instead of adding constraint
 */
@property (nonatomic, assign) BOOL updateExisting;

/**
 *  Whether or not to remove existing constraints prior to installing
 */
@property (nonatomic, assign) BOOL removeExisting;

/**
 *	initialises the maker with a default view
 *
 *	@param	view	any MASConstrait are created with this view as the first item
 *
 *	@return	a new PAZNMASConstraintMaker
 */
- (id)initWithView:(MAS_VIEW *)view;

/**
 *	Calls install method on any MASConstraints which have been created by this maker
 *
 *	@return	an array of all the installed MASConstraints
 */
- (NSArray *)install;

- (PAZNMASConstraint * (^)(dispatch_block_t))group;

@end
