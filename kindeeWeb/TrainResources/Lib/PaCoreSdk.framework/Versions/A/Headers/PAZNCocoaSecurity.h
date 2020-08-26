/*
 CocoaSecurity  1.1

 Created by Kelp on 12/5/12.
 Copyright (c) 2012 Kelp http://kelp.phate.org/
 MIT License
 
 CocoaSecurity is core. It provides AES encrypt, AES decrypt, Hash(MD5, HmacMD5, SHA1~SHA512, HmacSHA1~HmacSHA512) messages.
*/

#import <Foundation/Foundation.h>
#import <Foundation/NSException.h>

#pragma mark - PAZNCocoaSecurityResult
@interface PAZNCocoaSecurityResult : NSObject

@property (strong, nonatomic, readonly) NSData *data;
@property (strong, nonatomic, readonly) NSString *utf8String;
@property (strong, nonatomic, readonly) NSString *hex;
@property (strong, nonatomic, readonly) NSString *hexLower;
@property (strong, nonatomic, readonly) NSString *base64;

- (id)initWithBytes:(unsigned char[])initData length:(NSUInteger)length;

@end


#pragma mark - CocoaSecurity
@interface PAZNCocoaSecurity : NSObject
#pragma mark - AES Encrypt
+ (PAZNCocoaSecurityResult *)aesEncrypt:(NSString *)data key:(NSString *)key;
+ (PAZNCocoaSecurityResult *)aesEncrypt:(NSString *)data hexKey:(NSString *)key hexIv:(NSString *)iv;
+ (PAZNCocoaSecurityResult *)aesEncrypt:(NSString *)data key:(NSData *)key iv:(NSData *)iv;
+ (PAZNCocoaSecurityResult *)aesEncryptWithData:(NSData *)data key:(NSData *)key iv:(NSData *)iv;
#pragma mark AES Decrypt
+ (PAZNCocoaSecurityResult *)aesDecryptWithBase64:(NSString *)data key:(NSString *)key;
+ (PAZNCocoaSecurityResult *)aesDecryptWithBase64:(NSString *)data hexKey:(NSString *)key hexIv:(NSString *)iv;
+ (PAZNCocoaSecurityResult *)aesDecryptWithBase64:(NSString *)data key:(NSData *)key iv:(NSData *)iv;
+ (PAZNCocoaSecurityResult *)aesDecryptWithData:(NSData *)data key:(NSData *)key iv:(NSData *)iv;

#pragma mark - MD5
+ (PAZNCocoaSecurityResult *)md5:(NSString *)hashString;
+ (PAZNCocoaSecurityResult *)md5WithData:(NSData *)hashData;
#pragma mark HMAC-MD5
+ (PAZNCocoaSecurityResult *)hmacMd5:(NSString *)hashString hmacKey:(NSString *)key;
+ (PAZNCocoaSecurityResult *)hmacMd5WithData:(NSData *)hashData hmacKey:(NSString *)key;

#pragma mark - SHA
+ (PAZNCocoaSecurityResult *)sha224:(NSString *)hashString;
+ (PAZNCocoaSecurityResult *)sha224WithData:(NSData *)hashData;
+ (PAZNCocoaSecurityResult *)sha256:(NSString *)hashString;
+ (PAZNCocoaSecurityResult *)sha256WithData:(NSData *)hashData;
+ (PAZNCocoaSecurityResult *)sha384:(NSString *)hashString;
+ (PAZNCocoaSecurityResult *)sha384WithData:(NSData *)hashData;
+ (PAZNCocoaSecurityResult *)sha512:(NSString *)hashString;
+ (PAZNCocoaSecurityResult *)sha512WithData:(NSData *)hashData;
#pragma mark HMAC-SHA
+ (PAZNCocoaSecurityResult *)hmacSha224:(NSString *)hashString hmacKey:(NSString *)key;
+ (PAZNCocoaSecurityResult *)hmacSha224WithData:(NSData *)hashData hmacKey:(NSString *)key;
+ (PAZNCocoaSecurityResult *)hmacSha256:(NSString *)hashString hmacKey:(NSString *)key;
+ (PAZNCocoaSecurityResult *)hmacSha256WithData:(NSData *)hashData hmacKey:(NSString *)key;
+ (PAZNCocoaSecurityResult *)hmacSha384:(NSString *)hashString hmacKey:(NSString *)key;
+ (PAZNCocoaSecurityResult *)hmacSha384WithData:(NSData *)hashData hmacKey:(NSString *)key;
+ (PAZNCocoaSecurityResult *)hmacSha512:(NSString *)hashString hmacKey:(NSString *)key;
+ (PAZNCocoaSecurityResult *)hmacSha512WithData:(NSData *)hashData hmacKey:(NSString *)key;
@end


#pragma mark - CocoaSecurityEncoder
@interface PAZNCocoaSecurityEncoder : NSObject
- (NSString *)base64:(NSData *)data;
- (NSString *)hex:(NSData *)data useLower:(BOOL)isOutputLower;
@end


#pragma mark - CocoaSecurityDecoder
@interface PAZNCocoaSecurityDecoder : NSObject
- (NSData *)base64:(NSString *)data;
- (NSData *)hex:(NSString *)data;
@end
