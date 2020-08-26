//
//  UIView+PAZNMASShorthandAdditions.h
//  Masonry
//
//  Created by Jonas Budelmann on 22/07/13.
//  Copyright (c) 2013 Jonas Budelmann. All rights reserved.
//

#import "View+PAZNMASAdditions.h"

#ifdef MAS_SHORTHAND

/**
 *	Shorthand view additions without the 'mas_' prefixes,
 *  only enabled if MAS_SHORTHAND is defined
 */
@interface MAS_VIEW (PAZNMASShorthandAdditions)

@property (nonatomic, strong, readonly) MASViewAttribute *pazn_left;
@property (nonatomic, strong, readonly) MASViewAttribute *pazn_top;
@property (nonatomic, strong, readonly) MASViewAttribute *pazn_right;
@property (nonatomic, strong, readonly) MASViewAttribute *pazn_bottom;
@property (nonatomic, strong, readonly) MASViewAttribute *pazn_leading;
@property (nonatomic, strong, readonly) MASViewAttribute *pazn_trailing;
@property (nonatomic, strong, readonly) MASViewAttribute *pazn_width;
@property (nonatomic, strong, readonly) MASViewAttribute *pazn_height;
@property (nonatomic, strong, readonly) MASViewAttribute *pazn_centerX;
@property (nonatomic, strong, readonly) MASViewAttribute *pazn_centerY;
@property (nonatomic, strong, readonly) MASViewAttribute *pazn_baseline;
@property (nonatomic, strong, readonly) MASViewAttribute *(^pazn_attribute)(NSLayoutAttribute attr);

#if TARGET_OS_IPHONE

@property (nonatomic, strong, readonly) MASViewAttribute *pazn_leftMargin;
@property (nonatomic, strong, readonly) MASViewAttribute *pazn_rightMargin;
@property (nonatomic, strong, readonly) MASViewAttribute *pazn_topMargin;
@property (nonatomic, strong, readonly) MASViewAttribute *pazn_bottomMargin;
@property (nonatomic, strong, readonly) MASViewAttribute *pazn_leadingMargin;
@property (nonatomic, strong, readonly) MASViewAttribute *pazn_trailingMargin;
@property (nonatomic, strong, readonly) MASViewAttribute *pazn_centerXWithinMargins;
@property (nonatomic, strong, readonly) MASViewAttribute *pazn_centerYWithinMargins;

#endif

- (NSArray *)pazn_makeConstraints:(void(^)(PAZNMASConstraintMaker *make))block;
- (NSArray *)pazn_updateConstraints:(void(^)(PAZNMASConstraintMaker *make))block;
- (NSArray *)pazn_remakeConstraints:(void(^)(PAZNMASConstraintMaker *make))block;

@end

#define MAS_ATTR_FORWARD(attr)  \
- (MASViewAttribute *)attr {    \
    return [self pazn_mas_##attr];   \
}

@implementation MAS_VIEW (PAZNMASShorthandAdditions)

MAS_ATTR_FORWARD(top);
MAS_ATTR_FORWARD(left);
MAS_ATTR_FORWARD(bottom);
MAS_ATTR_FORWARD(right);
MAS_ATTR_FORWARD(leading);
MAS_ATTR_FORWARD(trailing);
MAS_ATTR_FORWARD(width);
MAS_ATTR_FORWARD(height);
MAS_ATTR_FORWARD(centerX);
MAS_ATTR_FORWARD(centerY);
MAS_ATTR_FORWARD(baseline);

#if TARGET_OS_IPHONE

MAS_ATTR_FORWARD(leftMargin);
MAS_ATTR_FORWARD(rightMargin);
MAS_ATTR_FORWARD(topMargin);
MAS_ATTR_FORWARD(bottomMargin);
MAS_ATTR_FORWARD(leadingMargin);
MAS_ATTR_FORWARD(trailingMargin);
MAS_ATTR_FORWARD(centerXWithinMargins);
MAS_ATTR_FORWARD(centerYWithinMargins);

#endif

- (MASViewAttribute *(^)(NSLayoutAttribute))pazn_attribute {
    return [self mas_attribute];
}

- (NSArray *)pazn_makeConstraints:(void(^)(PAZNMASConstraintMaker *))block {
    return [self mas_makeConstraints:block];
}

- (NSArray *)pazn_updateConstraints:(void(^)(PAZNMASConstraintMaker *))block {
    return [self mas_updateConstraints:block];
}

- (NSArray *)pazn_remakeConstraints:(void(^)(PAZNMASConstraintMaker *))block {
    return [self mas_remakeConstraints:block];
}

@end

#endif
