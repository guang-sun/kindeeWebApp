//
//  NSArray+PAZNMASShorthandAdditions.h
//  Masonry
//
//  Created by Jonas Budelmann on 22/07/13.
//  Copyright (c) 2013 Jonas Budelmann. All rights reserved.
//

#import "NSArray+PAZNMASAdditions.h"

#ifdef MAS_SHORTHAND

/**
 *	Shorthand array additions without the 'mas_' prefixes,
 *  only enabled if MAS_SHORTHAND is defined
 */
@interface NSArray (PAZNMASShorthandAdditions)

- (NSArray *)pazn_makeConstraints:(void(^)(PAZNMASConstraintMaker *make))block;
- (NSArray *)pazn_updateConstraints:(void(^)(PAZNMASConstraintMaker *make))block;
- (NSArray *)pazn_remakeConstraints:(void(^)(PAZNMASConstraintMaker *make))block;

@end

@implementation NSArray (PAZNMASShorthandAdditions)

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
