/*
 * This file is part of the PAZNSDWebImage package.
 * (c) Olivier Poitrey <rs@dailymotion.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

#import "PAZNSDWebImageCompat.h"
#import "PAZNSDWebImageDefine.h"
#import "PAZNSDWebImageManager.h"
#import "PAZNSDWebImageTransition.h"
#import "PAZNSDWebImageIndicator.h"

/**
 The value specify that the image progress unit count cannot be determined because the progressBlock is not been called.
 */
FOUNDATION_EXPORT const int64_t PAZNSDWebImageProgressUnitCountUnknown; /* 1LL */

typedef void(^PAZNSDSetImageBlock)(UIImage * _Nullable image, NSData * _Nullable imageData, PAZNImageCacheType cacheType, NSURL * _Nullable imageURL);

/**
 Integrates PAZNSDWebImage async downloading and caching of remote images with UIView subclass.
 */
@interface UIView (PAZNWebCache)

/**
 * Get the current image URL.
 *
 * @note Note that because of the limitations of categories this property can get out of sync if you use setImage: directly.
 */
@property (nonatomic, strong, readonly, nullable) NSURL *PAZNSD_imageURL;

/**
 * The current image loading progress associated to the view. The unit count is the received size and excepted size of download.
 * The `totalUnitCount` and `completedUnitCount` will be reset to 0 after a new image loading start (change from current queue). And they will be set to `PAZNSDWebImageProgressUnitCountUnknown` if the progressBlock not been called but the image loading success to mark the progress finished (change from main queue).
 * @note You can use Key-Value Observing on the progress, but you should take care that the change to progress is from a background queue during download(the same as progressBlock). If you want to using KVO and update the UI, make sure to dispatch on the main queue. And it's recommand to use some KVO libs like KVOController because it's more safe and easy to use.
 * @note The getter will create a progress instance if the value is nil. But by default, we don't create one. If you need to use Key-Value Observing, you must trigger the getter or set a custom progresss instance before the loading start. The default value is nil.
 * @note Note that because of the limitations of categories this property can get out of sync if you update the progress directly.
 */
@property (nonatomic, strong, null_resettable) NSProgress *PAZNSD_imageProgress;

/**
 * Set the imageView `image` with an `url` and optionally a placeholder image.
 *
 * The download is asynchronous and cached.
 *
 * @param url            The url for the image.
 * @param placeholder    The image to be set initially, until the image request finishes.
 * @param options        The options to use when downloading the image. @see PAZNSDWebImageOptions for the possible values.
 * @param context        A context contains different options to perform specify changes or processes, see `PAZNSDWebImageContextOption`. This hold the extra objects which `options` enum can not hold.
 * @param setImageBlock  Block used for custom set image code. If not provide, use the built-in set image code (supports `UIImageView/NSImageView` and `UIButton/NSButton` currently)
 * @param progressBlock  A block called while image is downloading
 *                       @note the progress block is executed on a background queue
 * @param completedBlock A block called when operation has been completed.
 *   This block has no return value and takes the requested UIImage as first parameter and the NSData representation as second parameter.
 *   In case of error the image parameter is nil and the third parameter may contain an NSError.
 *
 *   The forth parameter is an `PAZNImageCacheType` enum indicating if the image was retrieved from the local cache
 *   or from the memory cache or from the network.
 *
 *   The fith parameter normally is always YES. However, if you provide PAZNSDWebImageAvoidAutoSetImage with PAZNSDWebImageProgressiveLoad options to enable progressive downloading and set the image yourself. This block is thus called repeatedly with a partial image. When image is fully downloaded, the
 *   block is called a last time with the full image and the last parameter set to YES.
 *
 *   The last parameter is the original image URL
 */
- (void)PAZNSD_internalSetImageWithURL:(nullable NSURL *)url
                  placeholderImage:(nullable UIImage *)placeholder
                           options:(PAZNSDWebImageOptions)options
                           context:(nullable PAZNSDWebImageContext *)context
                     setImageBlock:(nullable PAZNSDSetImageBlock)setImageBlock
                          progress:(nullable PAZNSDImageLoaderProgressBlock)progressBlock
                         completed:(nullable PAZNSDInternalCompletionBlock)completedBlock;

/**
 * Cancel the current image load
 */
- (void)PAZNSD_cancelCurrentImageLoad;

#if PAZNSD_UIKIT || PAZNSD_MAC

#pragma mark - Image Transition

/**
 The image transition when image load finished. See `PAZNSDWebImageTransition`.
 If you specify nil, do not do transition. Defautls to nil.
 */
@property (nonatomic, strong, nullable) PAZNSDWebImageTransition *PAZNSD_imageTransition;

#pragma mark - Image Indicator

/**
 The image indicator during the image loading. If you do not need indicator, specify nil. Defaults to nil
 The setter will remove the old indicator view and add new indicator view to current view's subview.
 @note Because this is UI related, you should access only from the main queue.
 */
@property (nonatomic, strong, nullable) id<PAZNSDWebImageIndicator> PAZNSD_imageIndicator;

#endif

@end