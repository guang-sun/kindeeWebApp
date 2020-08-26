//
//  NSData+Common.h
//  CommonLibrary
//
//  Created by Alexi on 13-11-6.
//  Copyright (c) 2013年 ywchen. All rights reserved.
//
#import <Foundation/Foundation.h>


void *PAZNNewBase64Decode(const char *inputBuffer, size_t length, size_t *outputLength);

char *PAZNNewBase64Encode(const void *inputBuffer, size_t length, bool separateLines, size_t *outputLength);

@interface NSData (PAZNCommon)

@property (nonatomic, readonly) NSString* md5Hash;

+ (NSData *)dataFromBase64String:(NSString *)aString;
- (NSString *)base64EncodedString;
- (NSString *)md5Hash;

@end

