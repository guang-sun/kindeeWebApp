/*
 * This file is part of the PAZNSDWebImage package.
 * (c) Olivier Poitrey <rs@dailymotion.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

#import "PAZNSDWebImageCompat.h"

#if PAZNSD_UIKIT || PAZNSD_MAC
#import "PAZNImageCache.h"

#if PAZNSD_UIKIT
typedef UIViewAnimationOptions PAZNSDWebImageAnimationOptions;
#else
typedef NS_OPTIONS(NSUInteger, PAZNSDWebImageAnimationOptions) {
    PAZNSDWebImageAnimationOptionAllowsImplicitAnimation = 1 << 0, // specify `allowsImplicitAnimation` for the `NSAnimationContext`
};
#endif

typedef void (^PAZNSDWebImageTransitionPreparesBlock)(__kindof UIView * _Nonnull view, UIImage * _Nullable image, NSData * _Nullable imageData, PAZNImageCacheType cacheType, NSURL * _Nullable imageURL);
typedef void (^PAZNSDWebImageTransitionAnimationsBlock)(__kindof UIView * _Nonnull view, UIImage * _Nullable image);
typedef void (^PAZNSDWebImageTransitionCompletionBlock)(BOOL finished);

/**
 This class is used to provide a transition animation after the view category load image finished. Use this on `PAZNSD_imageTransition` in UIView+WebCache.h
 for UIKit(iOS & tvOS), we use `+[UIView transitionWithView:duration:options:animations:completion]` for transition animation.
 for AppKit(macOS), we use `+[NSAnimationContext runAnimationGroup:completionHandler:]` for transition animation. You can call `+[NSAnimationContext currentContext]` to grab the context during animations block.
 @note These transition are provided for basic usage. If you need complicated animation, consider to directly use Core Animation or use `PAZNSDWebImageAvoidAutoSetImage` and implement your own after image load finished.
 */
@interface PAZNSDWebImageTransition : NSObject

/**
 By default, we set the image to the view at the beginning of the animtions. You can disable this and provide custom set image process
 */
@property (nonatomic, assign) BOOL avoidAutoSetImage;
/**
 The duration of the transition animation, measured in seconds. Defaults to 0.5.
 */
@property (nonatomic, assign) NSTimeInterval duration;
/**
 The timing function used for all animations within this transition animation (macOS).
 */
@property (nonatomic, strong, nullable) CAMediaTimingFunction *timingFunction API_UNAVAILABLE(ios, tvos, watchos);
/**
 A mask of options indicating how you want to perform the animations.
 */
@property (nonatomic, assign) PAZNSDWebImageAnimationOptions animationOptions;
/**
 A block object to be executed before the animation sequence starts.
 */
@property (nonatomic, copy, nullable) PAZNSDWebImageTransitionPreparesBlock prepares;
/**
 A block object that contains the changes you want to make to the specified view.
 */
@property (nonatomic, copy, nullable) PAZNSDWebImageTransitionAnimationsBlock animations;
/**
 A block object to be executed when the animation sequence ends.
 */
@property (nonatomic, copy, nullable) PAZNSDWebImageTransitionCompletionBlock completion;

@end

/**
 Convenience way to create transition. Remember to specify the duration if needed.
 for UIKit, these transition just use the correspond `animationOptions`. By default we enable `UIViewAnimationOptionAllowUserInteraction` to allow user interaction during transition.
 for AppKit, these transition use Core Animation in `animations`. So your view must be layer-backed. Set `wantsLayer = YES` before you apply it.
 */
@interface PAZNSDWebImageTransition (Conveniences)

/// Fade transition.
@property (nonatomic, class, nonnull, readonly) PAZNSDWebImageTransition *fadeTransition;
/// Flip from left transition.
@property (nonatomic, class, nonnull, readonly) PAZNSDWebImageTransition *flipFromLeftTransition;
/// Flip from right transition.
@property (nonatomic, class, nonnull, readonly) PAZNSDWebImageTransition *flipFromRightTransition;
/// Flip from top transition.
@property (nonatomic, class, nonnull, readonly) PAZNSDWebImageTransition *flipFromTopTransition;
/// Flip from bottom transition.
@property (nonatomic, class, nonnull, readonly) PAZNSDWebImageTransition *flipFromBottomTransition;
/// Curl up transition.
@property (nonatomic, class, nonnull, readonly) PAZNSDWebImageTransition *curlUpTransition;
/// Curl down transition.
@property (nonatomic, class, nonnull, readonly) PAZNSDWebImageTransition *curlDownTransition;

@end

#endif
