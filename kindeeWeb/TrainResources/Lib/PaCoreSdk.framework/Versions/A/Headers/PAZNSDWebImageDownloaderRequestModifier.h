/*
 * This file is part of the PAZNSDWebImage package.
 * (c) Olivier Poitrey <rs@dailymotion.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

#import <Foundation/Foundation.h>
#import "PAZNSDWebImageCompat.h"

typedef NSURLRequest * _Nullable (^PAZNSDWebImageDownloaderRequestModifierBlock)(NSURLRequest * _Nonnull request);

/**
 This is the protocol for downloader request modifier.
 We can use a block to specify the downloader request modifier. But Using protocol can make this extensible, and allow Swift user to use it easily instead of using `@convention(block)` to store a block into context options.
 */
@protocol PAZNSDWebImageDownloaderRequestModifier <NSObject>

- (nullable NSURLRequest *)modifiedRequestWithRequest:(nonnull NSURLRequest *)request;

@end

/**
 A downloader request modifier class with block.
 */
@interface PAZNSDWebImageDownloaderRequestModifier : NSObject <PAZNSDWebImageDownloaderRequestModifier>

- (nonnull instancetype)initWithBlock:(nonnull PAZNSDWebImageDownloaderRequestModifierBlock)block;
+ (nonnull instancetype)requestModifierWithBlock:(nonnull PAZNSDWebImageDownloaderRequestModifierBlock)block;

@end
