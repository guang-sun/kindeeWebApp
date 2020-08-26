//
//  NSArray+CBExtension.h
//  CBEmotionView
//
//  Created by ly on 8/21/13.
//  Copyright (c) 2013 ly. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSArray (PAZNExtra)

- (NSArray *)offsetRangesInArrayBy:(NSUInteger)offset;

/**
 @brief 根据给定索引值，安全获取数组里的元素，index越界时返回nil，不会造成crash
 
 @param index 元素索引值
 
 @return 指定索引的元素
 */
- (id)safeGetObjectAtIndex:(NSUInteger)index;


/**
 @brief 打乱数组中的随机顺序
 
 @return 返回一个新的随机顺序数组
 */

- (NSArray *)paRandArray;

@end
