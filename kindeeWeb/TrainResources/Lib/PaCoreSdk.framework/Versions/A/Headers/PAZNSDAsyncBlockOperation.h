/*
 * This file is part of the PAZNSDWebImage package.
 * (c) Olivier Poitrey <rs@dailymotion.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

#import "PAZNSDWebImageCompat.h"

@class PAZNSDAsyncBlockOperation;
typedef void (^PAZNSDAsyncBlock)(PAZNSDAsyncBlockOperation * __nonnull asyncOperation);

@interface PAZNSDAsyncBlockOperation : NSOperation

- (nonnull instancetype)initWithBlock:(nonnull PAZNSDAsyncBlock)block;
+ (nonnull instancetype)blockOperationWithBlock:(nonnull PAZNSDAsyncBlock)block;
- (void)complete;

@end
