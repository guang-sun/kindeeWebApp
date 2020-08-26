//
//  PACoreResourcesMacro.h
//  PaCoreSdk
//
//  Created by 王斌(平安科技智慧教育团队项目研发部知鸟研发团队移动开发组) on 2019/1/19.
//

#ifndef PACoreResourcesMacro_h
#define PACoreResourcesMacro_h

#import "objc/runtime.h"

/**
 获取子组件bundle
 
 @param bundleName 子组建名称中bundle名称
 @return NSBundle
 */
#undef  PAZNFetchBundle
#define PAZNFetchBundle( bundleName ) \
({ \
NSBundle *bundle = nil; \
NSBundle *existBundle = objc_getAssociatedObject([NSBundle mainBundle], [bundleName UTF8String]); \
if( !existBundle ) { \
NSString *bundlePath =  [[NSBundle mainBundle] pathForResource:bundleName ofType:@"bundle"]; \
/** NSLog(@"bundlePath :%@", bundlePath); **/ \
existBundle = [NSBundle bundleWithPath:bundlePath]; \
objc_setAssociatedObject([NSBundle mainBundle], [bundleName UTF8String], bundle, OBJC_ASSOCIATION_RETAIN); \
}else { \
/** NSLog(@"bundle exist"); **/ \
} \
bundle = existBundle; \
}) \

/**
 快速获取图片
 
 @param bundleName 子组建名称中bundle名称
 @param imageName 图片名称
 @return UIImage
 */
#undef  PAZNImage
#define PAZNImage( bundleName, imageName ) \
({ \
UIImage *image = nil; \
NSBundle *bundle = PAZNFetchBundle(bundleName); \
image = [UIImage imageNamed:imageName inBundle:bundle compatibleWithTraitCollection:nil]; \
}) \



/**
 获取子组件中的plist
 
 @param bundleName 子组建名称中bundle名称
 @param plistName plist名称
 @return plist转换成的字典
 */
#undef  PAZNFetchPlist
#define PAZNFetchPlist( bundleName, plistName ) \
({ \
NSDictionary *plist = nil; \
NSBundle *bundle = PAZNFetchBundle(bundleName); \
\
NSDictionary *existPlist = objc_getAssociatedObject(bundle, [plistName UTF8String]); \
if ( !existPlist ) { \
NSString *themePath = [bundle pathForResource:plistName ofType:@"plist"]; \
NSFileManager *fileNamager = [[NSFileManager alloc]init]; \
if ([fileNamager fileExistsAtPath:themePath]) { \
existPlist = [NSDictionary dictionaryWithContentsOfFile:themePath]; \
/** NSLog(@"plist value >> %@", existPlist); **/ \
}\
objc_setAssociatedObject(bundle, [plistName UTF8String], existPlist, OBJC_ASSOCIATION_RETAIN); \
}else { \
/** NSLog(@"plist exist");  **/ \
} \
\
plist = existPlist; \
}) \

/**
 快速获取16进制色值字符串
 
 @param bundleName 子组建名称中bundle名称
 @param plistName plist名称
 @param keyPath 色值路径
 @return 16进制色值字符串
 */
#undef  PAZNColorFetchHexString
#define PAZNColorFetchHexString( bundleName, plistName, keyPath ) \
({ \
NSString *colorHex = nil; \
__block id value = PAZNFetchPlist(bundleName, plistName); \
\
NSArray *keyArr = [keyPath componentsSeparatedByString:@"."]; \
[keyArr enumerateObjectsUsingBlock:^(id  _Nonnull akey, NSUInteger idx, BOOL * _Nonnull stop) { \
if ([value isKindOfClass:[NSDictionary class]]) { \
value = value[akey]; \
/** NSLog(@"keypath value:%@", value);  **/ \
}else{ \
/** NSLog(@"%@:not exist",akey);  **/ \
*stop = YES; \
} \
}]; \
colorHex = value; \
}) \


/**
 将(0x)十六进制色值转换成颜色
 
 @param hexValue 16(0x)进制色值
 @return UIColor
 */
#undef  PAZNColorHex
#define PAZNColorHex( hexValue )        [UIColor colorWithRed:((float)((hexValue & 0xFF0000) >> 16)) / 255.0 green:((float)((hexValue & 0xFF00) >> 8)) / 255.0 blue:((float)(hexValue & 0xFF)) / 255.0 alpha:1.0f]

/**
 将十六进制色值字符串转换成颜色
 
 @param hexString 十六进制色值（0x/#）
 @return UIColor
 */
#undef  PAZNColorHexString
#define PAZNColorHexString( hexString ) \
({ \
NSLog(@"%@:hexString exist",hexString); \
UIColor *tempColor = nil; \
UIColor *hexColor = nil; \
NSString *cString = [[hexString stringByTrimmingCharactersInSet:[NSCharacterSet whitespaceAndNewlineCharacterSet]] uppercaseString]; \
if ([cString length] < 6) { \
tempColor = [UIColor clearColor]; \
}else { \
if ([cString hasPrefix:@"0X"]) \
cString = [cString substringFromIndex:2]; \
if ([cString hasPrefix:@"#"]) \
cString = [cString substringFromIndex:1]; \
NSRange range; \
range.location = 0; \
range.length = 2; \
NSString *rString = [cString substringWithRange:range]; \
range.location = 2; \
NSString *gString = [cString substringWithRange:range]; \
range.location = 4; \
NSString *bString = [cString substringWithRange:range]; \
unsigned int r, g, b; \
[[NSScanner scannerWithString:rString] scanHexInt:&r]; \
[[NSScanner scannerWithString:gString] scanHexInt:&g]; \
[[NSScanner scannerWithString:bString] scanHexInt:&b]; \
tempColor = [UIColor colorWithRed:((float) r / 255.0f) green:((float) g / 255.0f) blue:((float) b / 255.0f) alpha:1.0f]; \
} \
hexColor = tempColor; \
}) \

/**
 快速获取颜色
 
 @param bundleName bundle名称
 @param plistName plist名称
 @param keyPath 色值路径字符串
 @return UIColor颜色
 */
#undef  PAZNColor
#define PAZNColor( bundleName, plistName, keyPath ) PAZNColorHexString(PAZNColorFetchHexString(bundleName, plistName, keyPath))



#endif /* PACoreResourcesMacro_h */
