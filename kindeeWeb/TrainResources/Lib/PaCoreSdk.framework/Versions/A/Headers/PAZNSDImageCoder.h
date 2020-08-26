/*
 * This file is part of the PAZNSDWebImage package.
 * (c) Olivier Poitrey <rs@dailymotion.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

#import <Foundation/Foundation.h>
#import "PAZNSDWebImageCompat.h"
#import "NSData+PAZNImageContentType.h"

typedef NSString * PAZNSDImageCoderOption NS_STRING_ENUM;
typedef NSDictionary<PAZNSDImageCoderOption, id> PAZNSDImageCoderOptions;
typedef NSMutableDictionary<PAZNSDImageCoderOption, id> PAZNSDImageCoderMutableOptions;

#pragma mark - Coder Options
// These options are for image decoding
/**
 A Boolean value indicating whether to decode the first frame only for animated image during decoding. (NSNumber). If not provide, decode animated image if need.
 @note works for `PAZNSDImageCoder`.
 */
FOUNDATION_EXPORT PAZNSDImageCoderOption _Nonnull const PAZNSDImageCoderDecodeFirstFrameOnly;
/**
 A CGFloat value which is greater than or equal to 1.0. This value specify the image scale factor for decoding. If not provide, use 1.0. (NSNumber)
 @note works for `PAZNSDImageCoder`, `PAZNSDProgressiveImageCoder`, `PAZNSDAnimatedImageCoder`.
 */
FOUNDATION_EXPORT PAZNSDImageCoderOption _Nonnull const PAZNSDImageCoderDecodeScaleFactor;

// These options are for image encoding
/**
 A Boolean value indicating whether to encode the first frame only for animated image during encoding. (NSNumber). If not provide, encode animated image if need.
 @note works for `PAZNSDImageCoder`.
 */
FOUNDATION_EXPORT PAZNSDImageCoderOption _Nonnull const PAZNSDImageCoderEncodeFirstFrameOnly;
/**
 A double value between 0.0-1.0 indicating the encode compression quality to produce the image data. 1.0 resulting in no compression and 0.0 resulting in the maximum compression possible. If not provide, use 1.0. (NSNumber)
 @note works for `PAZNSDImageCoder`
 */
FOUNDATION_EXPORT PAZNSDImageCoderOption _Nonnull const PAZNSDImageCoderEncodeCompressionQuality;

/**
 A PAZNSDWebImageContext object which hold the original context options from top-level API. (PAZNSDWebImageContext)
 This option is ignored for all built-in coders and take no effect.
 But this may be useful for some custom coders, because some business logic may dependent on things other than image or image data inforamtion only.
 See `PAZNSDWebImageContext` for more detailed information.
 */
FOUNDATION_EXPORT PAZNSDImageCoderOption _Nonnull const PAZNSDImageCoderWebImageContext;

#pragma mark - Coder
/**
 This is the image coder protocol to provide custom image decoding/encoding.
 These methods are all required to implement.
 @note Pay attention that these methods are not called from main queue.
 */
@protocol PAZNSDImageCoder <NSObject>

@required
#pragma mark - Decoding
/**
 Returns YES if this coder can decode some data. Otherwise, the data should be passed to another coder.
 
 @param data The image data so we can look at it
 @return YES if this coder can decode the data, NO otherwise
 */
- (BOOL)canDecodeFromData:(nullable NSData *)data;

/**
 Decode the image data to image.
 @note This protocol may supports decode animated image frames. You can use `+[PAZNSDImageCoderHelper animatedImageWithFrames:]` to produce an animated image with frames.

 @param data The image data to be decoded
 @param options A dictionary containing any decoding options. Pass @{PAZNSDImageCoderDecodeScaleFactor: @(1.0)} to specify scale factor for image. Pass @{PAZNSDImageCoderDecodeFirstFrameOnly: @(YES)} to decode the first frame only.
 @return The decoded image from data
 */
- (nullable UIImage *)decodedImageWithData:(nullable NSData *)data
                                   options:(nullable PAZNSDImageCoderOptions *)options;

#pragma mark - Encoding

/**
 Returns YES if this coder can encode some image. Otherwise, it should be passed to another coder.
 For custom coder which introduce new image format, you'd better define a new `PAZNSDImageFormat` using like this. If you're creating public coder plugin for new image format, also update `https://github.com/rs/PAZNSDWebImage/wiki/Coder-Plugin-List` to avoid same value been defined twice.
 * @code
 static const PAZNSDImageFormat PAZNSDImageFormatHEIF = 10;
 * @endcode
 
 @param format The image format
 @return YES if this coder can encode the image, NO otherwise
 */
- (BOOL)canEncodeToFormat:(PAZNSDImageFormat)format NS_SWIFT_NAME(canEncode(to:));

/**
 Encode the image to image data.
 @note This protocol may supports encode animated image frames. You can use `+[PAZNSDImageCoderHelper framesFromAnimatedImage:]` to assemble an animated image with frames.

 @param image The image to be encoded
 @param format The image format to encode, you should note `PAZNSDImageFormatUndefined` format is also  possible
 @param options A dictionary containing any encoding options. Pass @{PAZNSDImageCoderEncodeCompressionQuality: @(1)} to specify compression quality.
 @return The encoded image data
 */
- (nullable NSData *)encodedDataWithImage:(nullable UIImage *)image
                                   format:(PAZNSDImageFormat)format
                                  options:(nullable PAZNSDImageCoderOptions *)options;

@end

#pragma mark - Progressive Coder
/**
 This is the image coder protocol to provide custom progressive image decoding.
 These methods are all required to implement.
 @note Pay attention that these methods are not called from main queue.
 */
@protocol PAZNSDProgressiveImageCoder <PAZNSDImageCoder>

@required
/**
 Returns YES if this coder can incremental decode some data. Otherwise, it should be passed to another coder.
 
 @param data The image data so we can look at it
 @return YES if this coder can decode the data, NO otherwise
 */
- (BOOL)canIncrementalDecodeFromData:(nullable NSData *)data;

/**
 Because incremental decoding need to keep the decoded context, we will alloc a new instance with the same class for each download operation to avoid conflicts
 This init method should not return nil

 @param options A dictionary containing any progressive decoding options (instance-level). Pass @{PAZNSDImageCoderDecodeScaleFactor: @(1.0)} to specify scale factor for progressive animated image (each frames should use the same scale).
 @return A new instance to do incremental decoding for the specify image format
 */
- (nonnull instancetype)initIncrementalWithOptions:(nullable PAZNSDImageCoderOptions *)options;

/**
 Update the incremental decoding when new image data available

 @param data The image data has been downloaded so far
 @param finished Whether the download has finished
 */
- (void)updateIncrementalData:(nullable NSData *)data finished:(BOOL)finished;

/**
 Incremental decode the current image data to image.
 @note Due to the performance issue for progressive decoding and the integration for image view. This method may only return the first frame image even if the image data is animated image. If you want progressive animated image decoding, conform to `PAZNSDAnimatedImageCoder` protocol as well and use `animatedImageFrameAtIndex:` instead.

 @param options A dictionary containing any progressive decoding options. Pass @{PAZNSDImageCoderDecodeScaleFactor: @(1.0)} to specify scale factor for progressive image
 @return The decoded image from current data
 */
- (nullable UIImage *)incrementalDecodedImageWithOptions:(nullable PAZNSDImageCoderOptions *)options;

@end

#pragma mark - Animated Image Provider
/**
 This is the animated image protocol to provide the basic function for animated image rendering. It's adopted by `PAZNSDAnimatedImage` and `PAZNSDAnimatedImageCoder`
 */
@protocol PAZNSDAnimatedImageProvider <NSObject>

@required
/**
 The original animated image data for current image. If current image is not an animated format, return nil.
 We may use this method to grab back the original image data if need, such as NSCoding or compare.
 
 @return The animated image data
 */
@property (nonatomic, copy, readonly, nullable) NSData *animatedImageData;

/**
 Total animated frame count.
 If the frame count is less than 1, then the methods below will be ignored.
 
 @return Total animated frame count.
 */
@property (nonatomic, assign, readonly) NSUInteger animatedImageFrameCount;
/**
 Animation loop count, 0 means infinite looping.
 
 @return Animation loop count
 */
@property (nonatomic, assign, readonly) NSUInteger animatedImageLoopCount;
/**
 Returns the frame image from a specified index.
 @note The index maybe randomly if one image was set to different imageViews, keep it re-entrant. (It's not recommend to store the images into array because it's memory consuming)
 
 @param index Frame index (zero based).
 @return Frame's image
 */
- (nullable UIImage *)animatedImageFrameAtIndex:(NSUInteger)index;
/**
 Returns the frames's duration from a specified index.
 @note The index maybe randomly if one image was set to different imageViews, keep it re-entrant. (It's recommend to store the durations into array because it's not memory-consuming)
 
 @param index Frame index (zero based).
 @return Frame's duration
 */
- (NSTimeInterval)animatedImageDurationAtIndex:(NSUInteger)index;

@end

#pragma mark - Animated Coder
/**
 This is the animated image coder protocol for custom animated image class like  `PAZNSDAnimatedImage`. Through it inherit from `PAZNSDImageCoder`. We currentlly only use the method `canDecodeFromData:` to detect the proper coder for specify animated image format.
 */
@protocol PAZNSDAnimatedImageCoder <PAZNSDImageCoder, PAZNSDAnimatedImageProvider>

@required
/**
 Because animated image coder should keep the original data, we will alloc a new instance with the same class for the specify animated image data
 The init method should return nil if it can't decode the specify animated image data to produce any frame.
 After the instance created, we may call methods in `PAZNSDAnimatedImageProvider` to produce animated image frame.

 @param data The animated image data to be decode
 @param options A dictionary containing any animated decoding options (instance-level). Pass @{PAZNSDImageCoderDecodeScaleFactor: @(1.0)} to specify scale factor for animated image (each frames should use the same scale).
 @return A new instance to do animated decoding for specify image data
 */
- (nullable instancetype)initWithAnimatedImageData:(nullable NSData *)data options:(nullable PAZNSDImageCoderOptions *)options;

@end
