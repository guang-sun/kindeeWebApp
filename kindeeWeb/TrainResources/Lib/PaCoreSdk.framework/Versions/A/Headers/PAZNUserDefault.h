//
//  PAZNUserDefault.h
//
//  Created by Cyril Zhou on 16/1/28.
//  Copyright © 2016 year Mac. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface PAZNUserDefault : NSObject

+ (PAZNUserDefault *)standardUserDefaults;
+ (void)resetStandardUserDefaults;
- (instancetype)initWithFileURLAndSecretKey:(NSURL *)fileURL secretKey:(NSString *)secretKey;
- (NSArray *)arrayForKey:(NSString *)defaultName;
- (void)removeObjectForKey:(NSString *)defaultName;
- (void)removeAllKeys;
- (BOOL)synchronize;

- (void)setObject:(id)value forKey:(NSString *)defaultName;
- (void)setSecretObject:(id)value forKey:(NSString *)defaultName;

- (void)setInteger:(NSInteger)value forKey:(NSString *)defaultName;
- (void)setSecretInteger:(NSInteger)value forKey:(NSString *)defaultName;

- (void)setFloat:(float)value forKey:(NSString *)defaultName;
- (void)setSecretFloat:(float)value forKey:(NSString *)defaultName;

- (void)setDouble:(double)value forKey:(NSString *)defaultName;
- (void)setSecretDouble:(double)value forKey:(NSString *)defaultName;

- (void)setBool:(BOOL)value forKey:(NSString *)defaultName;
- (void)setSecretBool:(BOOL)value forKey:(NSString *)defaultName;

- (void)setURL:(NSURL *)url forKey:(NSString *)defaultName;
- (void)setSecretURL:(NSURL *)url forKey:(NSString *)defaultName;

- (id)objectForKey:(NSString *)defaultName;
- (id)secretObjectForKey:(NSString *)defaultName;

- (NSString *)stringForKey:(NSString *)defaultName;
- (NSString *)secretStringForKey:(NSString *)defaultName;

- (NSDictionary<NSString *, id> *)dictionaryForKey:(NSString *)defaultName;
- (NSDictionary<NSString *, id> *)secretDictionaryForKey:(NSString *)defaultName;

- (NSData *)dataForKey:(NSString *)defaultName;
- (NSData *)secretDataForKey:(NSString *)defaultName;

- (NSArray<NSString *> *)stringArrayForKey:(NSString *)defaultName;
- (NSArray<NSString *> *)secretStringArrayForKey:(NSString *)defaultName;

- (NSInteger)integerForKey:(NSString *)defaultName;
- (NSInteger)secretIntegerForKey:(NSString *)defaultName;

- (float)floatForKey:(NSString *)defaultName;
- (float)secretFloatForKey:(NSString *)defaultName;

- (double)doubleForKey:(NSString *)defaultName;
- (double)secretDoubleForKey:(NSString *)defaultName;

- (BOOL)boolForKey:(NSString *)defaultName;
- (BOOL)secretBoolForKey:(NSString *)defaultName;

- (NSURL *)URLForKey:(NSString *)defaultName;
- (NSURL *)secretURLForKey:(NSString *)defaultName;

@end



