//
//  NSMutableArray+PAZNExtra.h
//  PaCoreSdk
//
//  Created by 文泽亮 on 2018/9/5.
//  Copyright © 2018年 Cyril Zhou. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSMutableArray (PAZNExtra)
- (void)safeInsertObject:(id)anObject atIndex:(NSUInteger)index;
- (void)safeRemoveObjectAtIndex:(NSUInteger)index;
- (void)safeReplaceObjectAtIndex:(NSUInteger)index withObject:(id)anObject;
- (void)safeMoveObject:(id)anObject toIndex:(NSUInteger)index;
@end
