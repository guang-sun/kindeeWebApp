/*
 * This file is part of the PAZNSDWebImage package.
 * (c) Olivier Poitrey <rs@dailymotion.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

#import <Foundation/Foundation.h>
#import "PAZNSDWebImageDownloader.h"
#import "PAZNSDWebImageOperation.h"

/**
 Describes a downloader operation. If one wants to use a custom downloader op, it needs to inherit from `NSOperation` and conform to this protocol
 For the description about these methods, see `PAZNSDWebImageDownloaderOperation`
 @note If your custom operation class does not use `NSURLSession` at all, do not implement the optional methods and session delegate methods.
 */
@protocol PAZNSDWebImageDownloaderOperation <NSURLSessionTaskDelegate, NSURLSessionDataDelegate>
@required
- (nonnull instancetype)initWithRequest:(nullable NSURLRequest *)request
                              inSession:(nullable NSURLSession *)session
                                options:(PAZNSDWebImageDownloaderOptions)options;

- (nonnull instancetype)initWithRequest:(nullable NSURLRequest *)request
                              inSession:(nullable NSURLSession *)session
                                options:(PAZNSDWebImageDownloaderOptions)options
                                context:(nullable PAZNSDWebImageContext *)context;

- (nullable id)addHandlersForProgress:(nullable PAZNSDWebImageDownloaderProgressBlock)progressBlock
                            completed:(nullable PAZNSDWebImageDownloaderCompletedBlock)completedBlock;

- (BOOL)cancel:(nullable id)token;

@property (strong, nonatomic, readonly, nullable) NSURLRequest *request;
@property (strong, nonatomic, readonly, nullable) NSURLResponse *response;

@optional
@property (strong, nonatomic, readonly, nullable) NSURLSessionTask *dataTask;
@property (strong, nonatomic, nullable) NSURLCredential *credential;
@property (assign, nonatomic) double minimumProgressInterval;

@end


/**
 The download operation class for PAZNSDWebImageDownloader.
 */
@interface PAZNSDWebImageDownloaderOperation : NSOperation <PAZNSDWebImageDownloaderOperation>

/**
 * The request used by the operation's task.
 */
@property (strong, nonatomic, readonly, nullable) NSURLRequest *request;

/**
 * The response returned by the operation's task.
 */
@property (strong, nonatomic, readonly, nullable) NSURLResponse *response;

/**
 * The operation's task
 */
@property (strong, nonatomic, readonly, nullable) NSURLSessionTask *dataTask;

/**
 * The credential used for authentication challenges in `-URLSession:task:didReceiveChallenge:completionHandler:`.
 *
 * This will be overridden by any shared credentials that exist for the username or password of the request URL, if present.
 */
@property (strong, nonatomic, nullable) NSURLCredential *credential;

/**
 * The minimum interval about progress percent during network downloading. Which means the next progress callback and current progress callback's progress percent difference should be larger or equal to this value. However, the final finish download progress callback does not get effected.
 * The value should be 0.0-1.0.
 * @note If you're using progressive decoding feature, this will also effect the image refresh rate.
 * @note This value may enhance the performance if you don't want progress callback too frequently.
 * Defaults to 0, which means each time we receive the new data from URLSession, we callback the progressBlock immediately.
 */
@property (assign, nonatomic) double minimumProgressInterval;

/**
 * The options for the receiver.
 */
@property (assign, nonatomic, readonly) PAZNSDWebImageDownloaderOptions options;

/**
 * The context for the receiver.
 */
@property (copy, nonatomic, readonly, nullable) PAZNSDWebImageContext *context;

/**
 *  Initializes a `PAZNSDWebImageDownloaderOperation` object
 *
 *  @see PAZNSDWebImageDownloaderOperation
 *
 *  @param request        the URL request
 *  @param session        the URL session in which this operation will run
 *  @param options        downloader options
 *
 *  @return the initialized instance
 */
- (nonnull instancetype)initWithRequest:(nullable NSURLRequest *)request
                              inSession:(nullable NSURLSession *)session
                                options:(PAZNSDWebImageDownloaderOptions)options;

/**
 *  Initializes a `PAZNSDWebImageDownloaderOperation` object
 *
 *  @see PAZNSDWebImageDownloaderOperation
 *
 *  @param request        the URL request
 *  @param session        the URL session in which this operation will run
 *  @param options        downloader options
 *  @param context        A context contains different options to perform specify changes or processes, see `PAZNSDWebImageContextOption`. This hold the extra objects which `options` enum can not hold.
 *
 *  @return the initialized instance
 */
- (nonnull instancetype)initWithRequest:(nullable NSURLRequest *)request
                              inSession:(nullable NSURLSession *)session
                                options:(PAZNSDWebImageDownloaderOptions)options
                                context:(nullable PAZNSDWebImageContext *)context NS_DESIGNATED_INITIALIZER;

/**
 *  Adds handlers for progress and completion. Returns a tokent that can be passed to -cancel: to cancel this set of
 *  callbacks.
 *
 *  @param progressBlock  the block executed when a new chunk of data arrives.
 *                        @note the progress block is executed on a background queue
 *  @param completedBlock the block executed when the download is done.
 *                        @note the completed block is executed on the main queue for success. If errors are found, there is a chance the block will be executed on a background queue
 *
 *  @return the token to use to cancel this set of handlers
 */
- (nullable id)addHandlersForProgress:(nullable PAZNSDWebImageDownloaderProgressBlock)progressBlock
                            completed:(nullable PAZNSDWebImageDownloaderCompletedBlock)completedBlock;

/**
 *  Cancels a set of callbacks. Once all callbacks are canceled, the operation is cancelled.
 *
 *  @param token the token representing a set of callbacks to cancel
 *
 *  @return YES if the operation was stopped because this was the last token to be canceled. NO otherwise.
 */
- (BOOL)cancel:(nullable id)token;

@end
