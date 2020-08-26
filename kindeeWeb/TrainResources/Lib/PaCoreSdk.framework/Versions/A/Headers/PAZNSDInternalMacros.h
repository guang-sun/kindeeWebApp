/*
 * This file is part of the PAZNSDWebImage package.
 * (c) Olivier Poitrey <rs@dailymotion.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

#import <Foundation/Foundation.h>
#import "PAZNSDmetamacros.h"

#ifndef PAZNSD_LOCK
#define PAZNSD_LOCK(lock) dispatch_semaphore_wait(lock, DISPATCH_TIME_FOREVER);
#endif

#ifndef PAZNSD_UNLOCK
#define PAZNSD_UNLOCK(lock) dispatch_semaphore_signal(lock);
#endif

#ifndef PAZNSD_OPTIONS_CONTAINS
#define PAZNSD_OPTIONS_CONTAINS(options, value) (((options) & (value)) == (value))
#endif

#ifndef weakify
#define weakify(...) \
PAZNSD_keywordify \
metamacro_foreach_cxt(PAZNSD_weakify_,, __weak, __VA_ARGS__)
#endif

#ifndef strongify
#define strongify(...) \
PAZNSD_keywordify \
_Pragma("clang diagnostic push") \
_Pragma("clang diagnostic ignored \"-Wshadow\"") \
metamacro_foreach(PAZNSD_strongify_,, __VA_ARGS__) \
_Pragma("clang diagnostic pop")
#endif

#define PAZNSD_weakify_(INDEX, CONTEXT, VAR) \
CONTEXT __typeof__(VAR) metamacro_concat(VAR, _weak_) = (VAR);

#define PAZNSD_strongify_(INDEX, VAR) \
__strong __typeof__(VAR) VAR = metamacro_concat(VAR, _weak_);

#if DEBUG
#define PAZNSD_keywordify autoreleasepool {}
#else
#define PAZNSD_keywordify try {} @catch (...) {}
#endif

#ifndef onExit
#define onExit \
PAZNSD_keywordify \
__strong PAZNSD_cleanupBlock_t metamacro_concat(PAZNSD_exitBlock_, __LINE__) __attribute__((cleanup(PAZNSD_executeCleanupBlock), unused)) = ^
#endif

typedef void (^PAZNSD_cleanupBlock_t)(void);

#if defined(__cplusplus)
extern "C" {
#endif
    void PAZNSD_executeCleanupBlock (__strong PAZNSD_cleanupBlock_t *block);
#if defined(__cplusplus)
}
#endif
