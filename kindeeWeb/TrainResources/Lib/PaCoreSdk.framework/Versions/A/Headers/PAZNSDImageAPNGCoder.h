/*
 * This file is part of the PAZNSDWebImage package.
 * (c) Olivier Poitrey <rs@dailymotion.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

#import <Foundation/Foundation.h>
#import "PAZNSDImageIOAnimatedCoder.h"

/**
 Built in coder using ImageIO that supports APNG encoding/decoding
 */
@interface PAZNSDImageAPNGCoder : PAZNSDImageIOAnimatedCoder <PAZNSDProgressiveImageCoder, PAZNSDAnimatedImageCoder>

@property (nonatomic, class, readonly, nonnull) PAZNSDImageAPNGCoder *sharedCoder;

@end
