#import <Foundation/Foundation.h>

@interface PAZNRSAEncrypt : NSObject

+ (NSString *)rsaEncryptString:(NSString *)string;

//-----BEGIN RSA PUBLIC KEY-----
+ (NSString *)rsaEncryptString:(NSString *)string publicPem:(NSString *)publicPem;
//-----END RSA PUBLIC KEY-----

//-----BEGIN CERTIFICATE-----
+ (NSString *)rsaEncryptString:(NSString *)string certificatePem:(NSString *)certificatePem;
//-----END CERTIFICATE-----

@end
