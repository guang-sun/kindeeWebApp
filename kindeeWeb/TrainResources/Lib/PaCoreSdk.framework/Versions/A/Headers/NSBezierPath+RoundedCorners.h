/*
 * This file is part of the PAZNSDWebImage package.
 * (c) Olivier Poitrey <rs@dailymotion.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

#import "PAZNSDWebImageCompat.h"

#if PAZNSD_MAC

#import "UIImage+Transform.h"

@interface NSBezierPath (RoundedCorners)

/**
 Convenience way to create a bezier path with the specify rounding corners on macOS. Same as the one on `UIBezierPath`.
 */
+ (nonnull instancetype)PAZNSD_bezierPathWithRoundedRect:(NSRect)rect byRoundingCorners:(PAZNSDRectCorner)corners cornerRadius:(CGFloat)cornerRadius;

@end

#endif
