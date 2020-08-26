/*
 * This file is part of the PAZNSDWebImage package.
 * (c) Olivier Poitrey <rs@dailymotion.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

#import <Foundation/Foundation.h>
#import "PAZNSDWebImageCompat.h"
#import "PAZNSDWebImageDefine.h"

@class PAZNSDWebImageOptionsResult;

typedef PAZNSDWebImageOptionsResult * _Nullable(^PAZNSDWebImageOptionsProcessorBlock)(NSURL * _Nullable url, PAZNSDWebImageOptions options, PAZNSDWebImageContext * _Nullable context);

/**
 The options result contains both options and context.
 */
@interface PAZNSDWebImageOptionsResult : NSObject

/**
 WebCache options.
 */
@property (nonatomic, assign, readonly) PAZNSDWebImageOptions options;

/**
 Context options.
 */
@property (nonatomic, copy, readonly, nullable) PAZNSDWebImageContext *context;

/**
 Create a new options result.

 @param options options
 @param context context
 @return The options result contains both options and context.
 */
- (nonnull instancetype)initWithOptions:(PAZNSDWebImageOptions)options context:(nullable PAZNSDWebImageContext *)context;

@end

/**
 This is the protocol for options processor.
 Options processor can be used, to control the final result for individual image request's `PAZNSDWebImageOptions` and `PAZNSDWebImageContext`
 Implements the protocol to have a global control for each indivadual image request's option.
 */
@protocol PAZNSDWebImageOptionsProcessor <NSObject>

/**
 Return the processed options result for specify image URL, with its options and context

 @param url The URL to the image
 @param options A mask to specify options to use for this request
 @param context A context contains different options to perform specify changes or processes, see `PAZNSDWebImageContextOption`. This hold the extra objects which `options` enum can not hold.
 @return The processed result, contains both options and context
 */
- (nullable PAZNSDWebImageOptionsResult *)processedResultForURL:(nullable NSURL *)url
                                                    options:(PAZNSDWebImageOptions)options
                                                    context:(nullable PAZNSDWebImageContext *)context;

@end

/**
 A options processor class with block.
 */
@interface PAZNSDWebImageOptionsProcessor : NSObject<PAZNSDWebImageOptionsProcessor>

- (nonnull instancetype)initWithBlock:(nonnull PAZNSDWebImageOptionsProcessorBlock)block;
+ (nonnull instancetype)optionsProcessorWithBlock:(nonnull PAZNSDWebImageOptionsProcessorBlock)block;

@end
