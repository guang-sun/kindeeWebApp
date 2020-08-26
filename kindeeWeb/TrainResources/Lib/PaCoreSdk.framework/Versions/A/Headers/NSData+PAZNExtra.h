//
//  NSData_extra.h
//  PAZNChat
//
//  Created by xiao on 4/4/14.
//  Copyright (c) 2014 FreeDo. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSData (PAZNUnzip)

+ (NSString *)hexadecimalString:(NSData *)data;
//压缩
+ (NSData *)zipData:(NSData *)data;
//解压
+ (NSData *)gunzip:(NSData *)data;
+ (id)dataWithHexString:(NSString *)hex;
- (NSData *)gzipUnpack;

@end
