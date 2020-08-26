//
//  MASConstraint+Private.h
//  Masonry
//
//  Created by Nick Tymchenko on 29/04/14.
//  Copyright (c) 2014 cloudling. All rights reserved.
//

#import "PAZNMASConstraint.h"

@protocol PAZNMASConstraintDelegate;


@interface PAZNMASConstraint ()

/**
 *  Whether or not to check for an existing constraint instead of adding constraint
 */
@property (nonatomic, assign) BOOL updateExisting;

/**
 *	Usually PAZNMASConstraintMaker but could be a parent MASConstraint
 */
@property (nonatomic, weak) id<PAZNMASConstraintDelegate> delegate;

/**
 *  Based on a provided value type, is equal to calling:
 *  NSNumber - setOffset:
 *  NSValue with CGPoint - setPointOffset:
 *  NSValue with CGSize - setSizeOffset:
 *  NSValue with MASEdgeInsets - setInsets:
 */
- (void)setLayoutConstantWithValue:(NSValue *)value;

@end


@interface PAZNMASConstraint (Abstract)

/**
 *	Sets the constraint relation to given NSLayoutRelation
 *  returns a block which accepts one of the following:
 *    MASViewAttribute, UIView, NSValue, NSArray
 *  see readme for more details.
 */
- (PAZNMASConstraint * (^)(id, NSLayoutRelation))equalToWithRelation;

/**
 *	Override to set a custom chaining behaviour
 */
- (PAZNMASConstraint *)addConstraintWithLayoutAttribute:(NSLayoutAttribute)layoutAttribute;

@end


@protocol PAZNMASConstraintDelegate <NSObject>

/**
 *	Notifies the delegate when the constraint needs to be replaced with another constraint. For example
 *  A MASViewConstraint may turn into a MASCompositeConstraint when an array is passed to one of the equality blocks
 */
- (void)constraint:(PAZNMASConstraint *)constraint shouldBeReplacedWithConstraint:(PAZNMASConstraint *)replacementConstraint;

- (PAZNMASConstraint *)constraint:(PAZNMASConstraint *)constraint addConstraintWithLayoutAttribute:(NSLayoutAttribute)layoutAttribute;

@end
