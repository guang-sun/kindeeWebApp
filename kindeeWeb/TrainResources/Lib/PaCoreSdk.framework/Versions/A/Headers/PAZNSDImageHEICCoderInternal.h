/*
* This file is part of the PAZNSDWebImage package.
* (c) Olivier Poitrey <rs@dailymotion.com>
*
* For the full copyright and license information, please view the LICENSE
* file that was distributed with this source code.
*/

#import <Foundation/Foundation.h>
#import "PAZNSDImageHEICCoder.h"

// AVFileTypeHEIC/AVFileTypeHEIF is defined in AVFoundation via iOS 11, we use this without import AVFoundation
#define kPAZNSDUTTypeHEIC ((__bridge CFStringRef)@"public.heic")
#define kPAZNSDUTTypeHEIF ((__bridge CFStringRef)@"public.heif")
// HEIC Sequence (Animated Image)
#define kPAZNSDUTTypeHEICS ((__bridge CFStringRef)@"public.heics")

@interface PAZNSDImageHEICCoder ()

+ (BOOL)canDecodeFromHEICFormat;
+ (BOOL)canDecodeFromHEIFFormat;
+ (BOOL)canEncodeToHEICFormat;
+ (BOOL)canEncodeToHEIFFormat;

@end
