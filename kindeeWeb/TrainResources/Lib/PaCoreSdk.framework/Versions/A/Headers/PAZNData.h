#import <Foundation/Foundation.h>

@interface NSData (PAZNData)

- (NSData *)md5Digest;

- (NSData *)sha256Digest;

- (NSString *)hexStringValue;

- (NSString *)base64Encoded;
- (NSData *)base64Decoded;

@end
