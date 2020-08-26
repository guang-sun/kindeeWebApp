/**
 * PAZNRange is the functional equivalent of a 64 bit NSRange.
 * The HTTP Server is designed to support very large files.
 * On 32 bit architectures (ppc, i386) NSRange uses unsigned 32 bit integers.
 * This only supports a range of up to 4 gigabytes.
 * By defining our own variant, we can support a range up to 16 exabytes.
 * 
 * All effort is given such that PAZNRange functions EXACTLY the same as NSRange.
**/

#import <Foundation/NSValue.h>
#import <Foundation/NSObjCRuntime.h>

@class NSString;

typedef struct _PAZNRange {
    UInt64 location;
    UInt64 length;
} PAZNRange;

typedef PAZNRange *PAZNRangePointer;

NS_INLINE PAZNRange PAZNMakeRange(UInt64 loc, UInt64 len) {
    PAZNRange r;
    r.location = loc;
    r.length = len;
    return r;
}

NS_INLINE UInt64 PAZNMaxRange(PAZNRange range) {
    return (range.location + range.length);
}

NS_INLINE BOOL PAZNLocationInRange(UInt64 loc, PAZNRange range) {
    return (loc - range.location < range.length);
}

NS_INLINE BOOL PAZNEqualRanges(PAZNRange range1, PAZNRange range2) {
    return ((range1.location == range2.location) && (range1.length == range2.length));
}

FOUNDATION_EXPORT PAZNRange PAZNUnionRange(PAZNRange range1, PAZNRange range2);
FOUNDATION_EXPORT PAZNRange PAZNIntersectionRange(PAZNRange range1, PAZNRange range2);
FOUNDATION_EXPORT NSString *PAZNStringFromRange(PAZNRange range);
FOUNDATION_EXPORT PAZNRange PAZNRangeFromString(NSString *aString);

NSInteger PAZNRangeCompare(PAZNRangePointer pDDRange1, PAZNRangePointer pDDRange2);

@interface NSValue (PAZNNSValueDDRangeExtensions)

+ (NSValue *)valueWithDDRange:(PAZNRange)range;
- (PAZNRange)ddrangeValue;

- (NSInteger)ddrangeCompare:(NSValue *)ddrangeValue;

@end
