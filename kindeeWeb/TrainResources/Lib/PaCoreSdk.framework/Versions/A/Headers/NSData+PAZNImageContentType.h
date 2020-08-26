/*
 * This file is part of the PAZNSDWebImage package.
 * (c) Olivier Poitrey <rs@dailymotion.com>
 * (c) Fabrice Aneche
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

#import <Foundation/Foundation.h>
#import "PAZNSDWebImageCompat.h"

/**
 You can use switch case like normal enum. It's also recommended to add a default case. You should not assume anything about the raw value.
 For custom coder plugin, it can also extern the enum for supported format. See `PAZNSDImageCoder` for more detailed information.
 */
typedef NSInteger PAZNSDImageFormat NS_TYPED_EXTENSIBLE_ENUM;
static const PAZNSDImageFormat PAZNSDImageFormatUndefined = -1;
static const PAZNSDImageFormat PAZNSDImageFormatJPEG      = 0;
static const PAZNSDImageFormat PAZNSDImageFormatPNG       = 1;
static const PAZNSDImageFormat PAZNSDImageFormatGIF       = 2;
static const PAZNSDImageFormat PAZNSDImageFormatTIFF      = 3;
static const PAZNSDImageFormat PAZNSDImageFormatWebP      = 4;
static const PAZNSDImageFormat PAZNSDImageFormatHEIC      = 5;
static const PAZNSDImageFormat PAZNSDImageFormatHEIF      = 6;

/**
 NSData category about the image content type and UTI.
 */
@interface NSData (PAZNImageContentType)

/**
 *  Return image format
 *
 *  @param data the input image data
 *
 *  @return the image format as `PAZNSDImageFormat` (enum)
 */
+ (PAZNSDImageFormat)PAZNSD_imageFormatForImageData:(nullable NSData *)data;

/**
 *  Convert PAZNSDImageFormat to UTType
 *
 *  @param format Format as PAZNSDImageFormat
 *  @return The UTType as CFStringRef
 */
+ (nonnull CFStringRef)PAZNSD_UTTypeFromImageFormat:(PAZNSDImageFormat)format CF_RETURNS_NOT_RETAINED NS_SWIFT_NAME(PAZNSD_UTType(from:));

/**
 *  Convert UTTyppe to PAZNSDImageFormat
 *
 *  @param uttype The UTType as CFStringRef
 *  @return The Format as PAZNSDImageFormat
 */
+ (PAZNSDImageFormat)PAZNSD_imageFormatFromUTType:(nonnull CFStringRef)uttype;

@end
