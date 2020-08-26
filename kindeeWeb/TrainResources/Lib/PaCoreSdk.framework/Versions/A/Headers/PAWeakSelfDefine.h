//
//  PAWeakSelfDefine.h
//  MLPlayer
//
//  Created by BearLi on 16/4/27.
//  Copyright © 2016年 w. All rights reserved.

/**
 *  以下2个宏在Block中成对使用,先weak再strong,可以很好的管理Block内部对self的引用.
 *  进入Block前: @weakify(self);
 *  进入Block后: @strongify(self);
 *  前面加@，其实就是一个啥都没干的@autoreleasepool {}前面的那个@,显眼!
 
 *  @weakify(self);
    dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0), ^{
        @strongify(self);
        [self doSomeThing];
        [self doOtherThing];
    });
 *
 */


#ifndef PAWeakSelfDefine_h
#define PAWeakSelfDefine_h

#ifndef    weakify
#if __has_feature(objc_arc)

#define weakify( x ) \
_Pragma("clang diagnostic push") \
_Pragma("clang diagnostic ignored \"-Wshadow\"") \
autoreleasepool{} __weak __typeof__(x) __weak_##x##__ = x; \
_Pragma("clang diagnostic pop")

#else

#define weakify( x ) \
_Pragma("clang diagnostic push") \
_Pragma("clang diagnostic ignored \"-Wshadow\"") \
autoreleasepool{} __block __typeof__(x) __block_##x##__ = x; \
_Pragma("clang diagnostic pop")

#endif
#endif

#ifndef    strongify
#if __has_feature(objc_arc)

#define strongify( x ) \
_Pragma("clang diagnostic push") \
_Pragma("clang diagnostic ignored \"-Wshadow\"") \
try{} @finally{} __typeof__(x) x = __weak_##x##__; \
_Pragma("clang diagnostic pop")

#else

#define strongify( x ) \
_Pragma("clang diagnostic push") \
_Pragma("clang diagnostic ignored \"-Wshadow\"") \
try{} @finally{} __typeof__(x) x = __block_##x##__; \
_Pragma("clang diagnostic pop")

#endif
#endif


#endif /* PAWeakSelfDefine_h */
