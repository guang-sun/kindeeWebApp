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
#import "PAZNSDWebImageOperation.h"
#import "PAZNSDWebImageDownloaderConfig.h"
#import "PAZNSDWebImageDownloaderRequestModifier.h"
#import "PAZNSDImageLoader.h"

/// Downloader options
typedef NS_OPTIONS(NSUInteger, PAZNSDWebImageDownloaderOptions) {
    /**
     * Put the download in the low queue priority and task priority.
     */
    PAZNSDWebImageDownloaderLowPriority = 1 << 0,
    
    /**
     * This flag enables progressive download, the image is displayed progressively during download as a browser would do.
     */
    PAZNSDWebImageDownloaderProgressiveLoad = 1 << 1,

    /**
     * By default, request prevent the use of NSURLCache. With this flag, NSURLCache
     * is used with default policies.
     */
    PAZNSDWebImageDownloaderUseNSURLCache = 1 << 2,

    /**
     * Call completion block with nil image/imageData if the image was read from NSURLCache
     * And the error code is `PAZNSDWebImageErrorCacheNotModified`
     * This flag should be combined with `PAZNSDWebImageDownloaderUseNSURLCache`.
     */
    PAZNSDWebImageDownloaderIgnoreCachedResponse = 1 << 3,
    
    /**
     * In iOS 4+, continue the download of the image if the app goes to background. This is achieved by asking the system for
     * extra time in background to let the request finish. If the background task expires the operation will be cancelled.
     */
    PAZNSDWebImageDownloaderContinueInBackground = 1 << 4,

    /**
     * Handles cookies stored in NSHTTPCookieStore by setting 
     * NSMutableURLRequest.HTTPShouldHandleCookies = YES;
     */
    PAZNSDWebImageDownloaderHandleCookies = 1 << 5,

    /**
     * Enable to allow untrusted SSL certificates.
     * Useful for testing purposes. Use with caution in production.
     */
    PAZNSDWebImageDownloaderAllowInvalidSSLCertificates = 1 << 6,

    /**
     * Put the download in the high queue priority and task priority.
     */
    PAZNSDWebImageDownloaderHighPriority = 1 << 7,
    
    /**
     * By default, images are decoded respecting their original size. On iOS, this flag will scale down the
     * images to a size compatible with the constrained memory of devices.
     * This flag take no effect if `PAZNSDWebImageDownloaderAvoidDecodeImage` is set. And it will be ignored if `PAZNSDWebImageDownloaderProgressiveLoad` is set.
     */
    PAZNSDWebImageDownloaderScaleDownLargeImages = 1 << 8,
    
    /**
     * By default, we will decode the image in the background during cache query and download from the network. This can help to improve performance because when rendering image on the screen, it need to be firstly decoded. But this happen on the main queue by Core Animation.
     * However, this process may increase the memory usage as well. If you are experiencing a issue due to excessive memory consumption, This flag can prevent decode the image.
     */
    PAZNSDWebImageDownloaderAvoidDecodeImage = 1 << 9,
    
    /**
     * By default, we decode the animated image. This flag can force decode the first frame only and produece the static image.
     */
    PAZNSDWebImageDownloaderDecodeFirstFrameOnly = 1 << 10,
    
    /**
     * By default, for `PAZNSDAnimatedImage`, we decode the animated image frame during rendering to reduce memory usage. This flag actually trigger `preloadAllAnimatedImageFrames = YES` after image load from network
     */
    PAZNSDWebImageDownloaderPreloadAllFrames = 1 << 11,
    
    /**
     * By default, when you use `PAZNSDWebImageContextAnimatedImageClass` context option (like using `PAZNSDAnimatedImageView` which designed to use `PAZNSDAnimatedImage`), we may still use `UIImage` when the memory cache hit, or image decoder is not available, to behave as a fallback solution.
     * Using this option, can ensure we always produce image with your provided class. If failed, a error with code `PAZNSDWebImageErrorBadImageData` will been used.
     * Note this options is not compatible with `PAZNSDWebImageDownloaderDecodeFirstFrameOnly`, which always produce a UIImage/NSImage.
     */
    PAZNSDWebImageDownloaderMatchAnimatedImageClass = 1 << 12,
};

FOUNDATION_EXPORT NSNotificationName _Nonnull const PAZNSDWebImageDownloadStartNotification;
FOUNDATION_EXPORT NSNotificationName _Nonnull const PAZNSDWebImageDownloadReceiveResponseNotification;
FOUNDATION_EXPORT NSNotificationName _Nonnull const PAZNSDWebImageDownloadStopNotification;
FOUNDATION_EXPORT NSNotificationName _Nonnull const PAZNSDWebImageDownloadFinishNotification;

typedef PAZNSDImageLoaderProgressBlock PAZNSDWebImageDownloaderProgressBlock;
typedef PAZNSDImageLoaderCompletedBlock PAZNSDWebImageDownloaderCompletedBlock;

/**
 *  A token associated with each download. Can be used to cancel a download
 */
@interface PAZNSDWebImageDownloadToken : NSObject <PAZNSDWebImageOperation>

/**
 Cancel the current download.
 */
- (void)cancel;

/**
 The download's URL.
 */
@property (nonatomic, strong, nullable, readonly) NSURL *url;

/**
 The download's request.
 */
@property (nonatomic, strong, nullable, readonly) NSURLRequest *request;

/**
 The download's response.
 */
@property (nonatomic, strong, nullable, readonly) NSURLResponse *response;

@end


/**
 * Asynchronous downloader dedicated and optimized for image loading.
 */
@interface PAZNSDWebImageDownloader : NSObject

/**
 * Downloader Config object - storing all kind of settings.
 * Most config properties support dynamic changes during download, except something like `sessionConfiguration`, see `PAZNSDWebImageDownloaderConfig` for more detail.
 */
@property (nonatomic, copy, readonly, nonnull) PAZNSDWebImageDownloaderConfig *config;

/**
 * Set the request modifier to modify the original download request before image load.
 * This request modifier method will be called for each downloading image request. Return the original request means no modication. Return nil will cancel the download request.
 * Defaults to nil, means does not modify the original download request.
 * @note If you want to modify single request, consider using `PAZNSDWebImageContextDownloadRequestModifier` context option.
 */
@property (nonatomic, strong, nullable) id<PAZNSDWebImageDownloaderRequestModifier> requestModifier;

/**
 * The configuration in use by the internal NSURLSession. If you want to provide a custom sessionConfiguration, use `PAZNSDWebImageDownloaderConfig.sessionConfiguration` and create a new downloader instance.
 @note This is immutable according to NSURLSession's documentation. Mutating this object directly has no effect.
 */
@property (nonatomic, readonly, nonnull) NSURLSessionConfiguration *sessionConfiguration;

/**
 * Gets/Sets the download queue suspension state.
 */
@property (nonatomic, assign, getter=isSuspended) BOOL suspended;

/**
 * Shows the current amount of downloads that still need to be downloaded
 */
@property (nonatomic, assign, readonly) NSUInteger currentDownloadCount;

/**
 *  Returns the global shared downloader instance. Which use the `PAZNSDWebImageDownloaderConfig.defaultDownloaderConfig` config.
 */
@property (nonatomic, class, readonly, nonnull) PAZNSDWebImageDownloader *sharedDownloader;

/**
 Creates an instance of a downloader with specified downloader config.
 You can specify session configuration, timeout or operation class through downloader config.

 @param config The downloader config. If you specify nil, the `defaultDownloaderConfig` will be used.
 @return new instance of downloader class
 */
- (nonnull instancetype)initWithConfig:(nullable PAZNSDWebImageDownloaderConfig *)config NS_DESIGNATED_INITIALIZER;

/**
 * Set a value for a HTTP header to be appended to each download HTTP request.
 *
 * @param value The value for the header field. Use `nil` value to remove the header field.
 * @param field The name of the header field to set.
 */
- (void)setValue:(nullable NSString *)value forHTTPHeaderField:(nullable NSString *)field;

/**
 * Returns the value of the specified HTTP header field.
 *
 * @return The value associated with the header field field, or `nil` if there is no corresponding header field.
 */
- (nullable NSString *)valueForHTTPHeaderField:(nullable NSString *)field;

/**
 * Creates a PAZNSDWebImageDownloader async downloader instance with a given URL
 *
 * The delegate will be informed when the image is finish downloaded or an error has happen.
 *
 * @see PAZNSDWebImageDownloaderDelegate
 *
 * @param url            The URL to the image to download
 * @param completedBlock A block called once the download is completed.
 *                       If the download succeeded, the image parameter is set, in case of error,
 *                       error parameter is set with the error. The last parameter is always YES
 *                       if PAZNSDWebImageDownloaderProgressiveDownload isn't use. With the
 *                       PAZNSDWebImageDownloaderProgressiveDownload option, this block is called
 *                       repeatedly with the partial image object and the finished argument set to NO
 *                       before to be called a last time with the full image and finished argument
 *                       set to YES. In case of error, the finished argument is always YES.
 *
 * @return A token (PAZNSDWebImageDownloadToken) that can be used to cancel this operation
 */
- (nullable PAZNSDWebImageDownloadToken *)downloadImageWithURL:(nullable NSURL *)url
                                                 completed:(nullable PAZNSDWebImageDownloaderCompletedBlock)completedBlock;

/**
 * Creates a PAZNSDWebImageDownloader async downloader instance with a given URL
 *
 * The delegate will be informed when the image is finish downloaded or an error has happen.
 *
 * @see PAZNSDWebImageDownloaderDelegate
 *
 * @param url            The URL to the image to download
 * @param options        The options to be used for this download
 * @param progressBlock  A block called repeatedly while the image is downloading
 *                       @note the progress block is executed on a background queue
 * @param completedBlock A block called once the download is completed.
 *                       If the download succeeded, the image parameter is set, in case of error,
 *                       error parameter is set with the error. The last parameter is always YES
 *                       if PAZNSDWebImageDownloaderProgressiveLoad isn't use. With the
 *                       PAZNSDWebImageDownloaderProgressiveLoad option, this block is called
 *                       repeatedly with the partial image object and the finished argument set to NO
 *                       before to be called a last time with the full image and finished argument
 *                       set to YES. In case of error, the finished argument is always YES.
 *
 * @return A token (PAZNSDWebImageDownloadToken) that can be used to cancel this operation
 */
- (nullable PAZNSDWebImageDownloadToken *)downloadImageWithURL:(nullable NSURL *)url
                                                   options:(PAZNSDWebImageDownloaderOptions)options
                                                  progress:(nullable PAZNSDWebImageDownloaderProgressBlock)progressBlock
                                                 completed:(nullable PAZNSDWebImageDownloaderCompletedBlock)completedBlock;

/**
 * Creates a PAZNSDWebImageDownloader async downloader instance with a given URL
 *
 * The delegate will be informed when the image is finish downloaded or an error has happen.
 *
 * @see PAZNSDWebImageDownloaderDelegate
 *
 * @param url            The URL to the image to download
 * @param options        The options to be used for this download
 * @param context        A context contains different options to perform specify changes or processes, see `PAZNSDWebImageContextOption`. This hold the extra objects which `options` enum can not hold.
 * @param progressBlock  A block called repeatedly while the image is downloading
 *                       @note the progress block is executed on a background queue
 * @param completedBlock A block called once the download is completed.
 *
 * @return A token (PAZNSDWebImageDownloadToken) that can be used to cancel this operation
 */
- (nullable PAZNSDWebImageDownloadToken *)downloadImageWithURL:(nullable NSURL *)url
                                                   options:(PAZNSDWebImageDownloaderOptions)options
                                                   context:(nullable PAZNSDWebImageContext *)context
                                                  progress:(nullable PAZNSDWebImageDownloaderProgressBlock)progressBlock
                                                 completed:(nullable PAZNSDWebImageDownloaderCompletedBlock)completedBlock;

/**
 * Cancels all download operations in the queue
 */
- (void)cancelAllDownloads;

/**
 * Invalidates the managed session, optionally canceling pending operations.
 * @note If you use custom downloader instead of the shared downloader, you need call this method when you do not use it to avoid memory leak
 * @param cancelPendingOperations Whether or not to cancel pending operations.
 * @note Calling this method on the shared downloader has no effect.
 */
- (void)invalidateSessionAndCancel:(BOOL)cancelPendingOperations;

@end


/**
 PAZNSDWebImageDownloader is the built-in image loader conform to `PAZNSDImageLoader`. Which provide the HTTP/HTTPS/FTP download, or local file URL using NSURLSession.
 However, this downloader class itself also support customization for advanced users. You can specify `operationClass` in download config to custom download operation, See `PAZNSDWebImageDownloaderOperation`.
 If you want to provide some image loader which beyond network or local file, consider to create your own custom class conform to `PAZNSDImageLoader`.
 */
@interface PAZNSDWebImageDownloader (PAZNSDImageLoader) <PAZNSDImageLoader>

@end
