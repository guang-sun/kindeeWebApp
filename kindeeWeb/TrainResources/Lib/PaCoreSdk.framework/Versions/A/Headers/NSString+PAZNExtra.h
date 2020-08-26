//
//  NSString+extra.h
//  MLPlayer
//
//  Created by 徐仁杰 on 9/5/14.
//  Copyright (c) 2014 w. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface NSString (PAZNExtra)
+ (NSString *)MD5StringFrom:(NSString *)source;
+ (NSString *)defaultVaule:(NSString *)defaultValue
                 forString:(NSString *)origin;
- (NSString *)PAZNURLEncodedString;
- (NSString *)stringEncoded;
//判断是否为系统表情
- (BOOL)stringContainsEmoji;
- (NSString *)URLDecodedString;
+ (NSString *)normaPhoneNumber:(NSString *)number; //电话号码去掉多余的字符

//分秒：00:00
+ (NSString *)stringWithTimeInterval:(NSTimeInterval)duration;

/**
 *  格式金额字符串 格式化为 xxx,xx.xx
 *
 *  @param moneyStr 金额字符串
 *
 *  @return 格式后的字符串
 */
+ (NSString *)formatMoneyString:(NSString *)moneyStr;

- (NSRange)composedRangeWithRange:(NSRange)range; //处理Emoji表情取长度问题
- (NSString *)composedSubstringWithRange:(NSRange)range;
//以RSA加密算法用后台提供的字符串公钥进行加密，content传加密内容，pkey传公钥
+ (NSString *)encryptWithString:(NSString *)content AndPublicKey:(NSString *)pKey;
- (NSString *)composedStringFromIndex:(int)index;
- (NSString *)composedStringToIndex:(int)index;
+ (BOOL)isContainsEmoji:(NSString *)string;
- (NSString *)milliSecondString2Second;
- (NSData *)dataFromHex;
- (NSString *)stringByReversed;
+ (NSString *)base64StringFromString:(NSString *)string;
- (NSString *)base64Decoding;

+ (NSString *)jsonStringWithDictionary:(NSDictionary *)dictionary;

+ (NSString *)jsonStringWithArray:(NSArray *)array;

+ (NSString *)jsonStringWithString:(NSString *)string;

+ (NSString *)jsonStringWithObject:(id)object;

- (BOOL)examinePassWordString;

- (int)examineUserNameString;

- (NSString *)mk_urlEncodedString;

- (NSString *)urlDecodedString;

- (NSString *)md5;

/**

 *  是否包含指定字符串 (iOS8.0可以使用系统的 - (BOOL)containsString:(NSString
 *)str;)
 *  不区分大小写
 *  @param string 包含的字符串
 *
 *  @return 结果
 */
- (BOOL)hasRangeOfString:(NSString *)string;

/*
 将整数转成xx万，xx亿的格式
 */
- (NSString *)formatLongNumber;

/** 是否包含特定字符串，区分大小写*/
- (BOOL)hasRangeOfStringCaseSensitive:(NSString *)string;

/**
 *  富文本大小
 *
 *  @param width 空间宽度
 *  @param attrt 富文本
 *
 *  @return CGRect
 */
+ (CGRect)getRectWithSize:(CGFloat)width
     withAttributedString:(NSMutableAttributedString *)attrt;
/**
 *  计算富文本高度
 *
 *  @param width       控件的宽度
 *  @param font        字体大小
 *  @param lineSpacing 行间距
 *
 *  @return 高度
 */
- (CGFloat)boundingRectWithSize:(CGFloat)width
                   withTextFont:(UIFont *)font
                withLineSpacing:(CGFloat)lineSpacing;
+ (CGFloat)boundingRectWithSize:(CGFloat)width
           withAttributedString:(NSMutableAttributedString *)attrt;
- (CGFloat)boundingRectWithSize:(CGFloat)width
           withAttributedString:(NSMutableAttributedString *)attrt;

/**
 *  获取字符串的宽度
 *
 *  @param size 指定高度的size
 *  @param font 字符串字体
 *
 *  @return 字符串宽度
 */
- (CGFloat)stringWidthWithSize:(CGSize)size font:(UIFont *)font;

/**
 *  获取字符串的高度
 *
 *  @param size 指定宽度的size
 *  @param font 字符串字体
 *
 *  @return 字符串宽度
 */
- (CGFloat)stringHeightWithSize:(CGSize)size font:(UIFont *)font;

- (CGSize)stringSizeWithSize:(CGSize)size font:(UIFont *)font;
/**
 *  富文本设置
 *
 *  @param font        字体大小
 *  @param color       字体颜色
 *  @param lineSpacing 行间距
 *
 *  @return 富文本
 */
- (NSMutableAttributedString *)attributedStringWithFont:(UIFont *)font
                                              withColor:(UIColor *)color
                                        withLineSpacing:(CGFloat)lineSpacing;
- (NSMutableAttributedString *)attributedStringWithFont:(UIFont *)font
                                        withLineSpacing:(CGFloat)lineSpacing;

/**
 *  判断字符串是否全为数字
 *
 *  @param string 需要验证的字符串
 *
 *  @return 比对结果
 */
+ (BOOL)isAllNumberCharacters:(NSString *)string;

- (UIColor *)rgbColor;


/**
 *  判断邮箱合法性
 *
 *  @param email 需要判断的邮箱
 *
 *  @return YES 合法 NO非法
 */
+ (BOOL)validateEmail:(NSString *)email;

/**
 *  判断手机号码的合法性
 *
 *  @param mobile 需要判断的手机号
 *
 *  @return YES 合法 NO非法
 */
+ (BOOL)validateMobile:(NSString *)mobile;

+ (CGSize)getStringSize:(NSString *)string fontSize:(float)font;

+ (CGSize)getStringSize:(NSString *)string font:(UIFont *)font;

/**
 对姓名字符串进行截断，应对测试经常出现的超长名字账号，
 截断原则：对超过maxLength的字符截断并在其后拼上...（汉字算1个字符，英文及数字算半个字符）

 @param maxLength 上限长度
 @return 截断后
 */
- (NSString *)nameStringWithMaxLength:(NSUInteger)maxLength;

@end

@interface NSMutableAttributedString (PAZNExtra)

- (CGSize)sizeConstrainedToSize:(CGSize)maxSize
                       fitRange:(NSRange *)fitRange
                        withStr:(NSAttributedString *)str;

@end
