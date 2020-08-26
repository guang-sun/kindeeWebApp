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
 Built in coder using ImageIO that supports animated GIF encoding/decoding
 @note `PAZNSDImageIOCoder` supports GIF but only as static (will use the 1st frame).
 @note Use `PAZNSDImageGIFCoder` for fully animated GIFs. For `UIImageView`, it will produce animated `UIImage`(`NSImage` on macOS) for rendering. For `PAZNSDAnimatedImageView`, it will use `PAZNSDAnimatedImage` for rendering.
 @note The recommended approach for animated GIFs is using `PAZNSDAnimatedImage` with `PAZNSDAnimatedImageView`. It's more performant than `UIImageView` for GIF displaying(especially on memory usage)
 */
@interface PAZNSDImageGIFCoder : PAZNSDImageIOAnimatedCoder <PAZNSDProgressiveImageCoder, PAZNSDAnimatedImageCoder>

@property (nonatomic, class, readonly, nonnull) PAZNSDImageGIFCoder *sharedCoder;

@end
