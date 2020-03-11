//
//  TrainMacroDefine.h
//  SOHUTrain
//
//  Created by apple on 16/8/26.
//  Copyright © 2016年  Kingno. All rights reserved.
//

#ifndef TrainMacroDefine_h
#define TrainMacroDefine_h

#import "AppDelegate.h"
#import "TrainControllerUtil.h"
#import "TrainStringUtil.h"
#import <Masonry.h>


// 工具


// 设置
#import "TrainPromptStr.h"
#import "TrainCommonMacro.h"
#import "TrainNetWorkAPI.h"
#import "TrainNetWorkAPIClient.h"



#define MaxTitleFontSize 18
#define NormalTitleFontSize 16
#define LittleTitleFontSize 14

#define MaxSubTitleFontSize 16
#define NormalSubTitleFontSize 14
#define LittleSubTitleFontSize 12

#define MiniTextFontSize 10
/************************自定义weak-strong-dance****START*************************/
/**
 
 * 强弱援用转换，用于处理代码块（block）与强援用self之间的循环援用题目
 * 挪用方法: `@weakify_self`完成弱援用转换，`@strongify_self`完成强援用转换
 * 示例：
 * @weakify_self
 * [obj block:^{
 *      @strongify_self
 *      self.property = something;
 * }];
 
 */

#ifndef    weakify_self

#if __has_feature(objc_arc)

#define weakify_self autoreleasepool{} __weak __typeof__(self) weakSelf = self;

#else

#define weakify_self autoreleasepool{} __block __typeof__(self) blockSelf = self;

#endif

#endif

#ifndef    strongify_self

#if __has_feature(objc_arc)

#define strongify_self try{} @finally{} __typeof__(weakSelf) self = weakSelf;

#else

#define strongify_self try{} @finally{} __typeof__(blockSelf) self = blockSelf;

#endif

#endif

#define if_self_is_nil_return try{} @finally{} if(!self){return ;} ;
/************************自定义weak-strong-dance****END*************************/


#ifndef weakify
#if DEBUG
#if __has_feature(objc_arc)
#define weakify(object) autoreleasepool{} __weak __typeof__(object) weak##_##object = object;
#else
#define weakify(object) autoreleasepool{} __block __typeof__(object) block##_##object = object;
#endif
#else
#if __has_feature(objc_arc)
#define weakify(object) try{} @finally{} {} __weak __typeof__(object) weak##_##object = object;
#else
#define weakify(object) try{} @finally{} {} __block __typeof__(object) block##_##object = object;
#endif
#endif
#endif
#ifndef strongify
#if DEBUG
#if __has_feature(objc_arc)
#define strongify(object) autoreleasepool{} __typeof__(object) object = weak##_##object;
#else
#define strongify(object) autoreleasepool{} __typeof__(object) object = block##_##object;
#endif
#else
#if __has_feature(objc_arc)
#define strongify(object) try{} @finally{} __typeof__(object) object = weak##_##object;
#else
#define strongify(object) try{} @finally{} __typeof__(object) object = block##_##object;
#endif
#endif
#endif

#pragma mark - debug  NSLog  打印信息


#ifdef DEBUG
#define TrainNSLog(format, ...) printf("\n[%s] %s [第%d行] %s\n", __TIME__, __FUNCTION__, __LINE__, [[NSString stringWithFormat:format, ## __VA_ARGS__] UTF8String]);
#else
#define TrainNSLog(format, ...)
#endif

#pragma mark - IOS8及以上系统
#define TrainIOS8 ([[[UIDevice currentDevice] systemVersion] floatValue] >= 8.0000 ? YES : NO)

#pragma mark - IOS7判断
#define TrainIOS7 ([[[UIDevice currentDevice] systemVersion] floatValue] >= 7.0000 ? YES : NO)
#pragma mark - 判断机型  4 5 6 6p


#define TrainiPhone4 ([UIScreen instancesRespondToSelector:@selector(currentMode)] ? CGSizeEqualToSize(CGSizeMake(640, 960), [[UIScreen mainScreen] currentMode].size) : NO)
#define TrainiPhone5 ([UIScreen instancesRespondToSelector:@selector(currentMode)] ? CGSizeEqualToSize(CGSizeMake(640, 1136), [[UIScreen mainScreen] currentMode].size) : NO)
#define TrainiPhone6 ([UIScreen instancesRespondToSelector:@selector(currentMode)] ? CGSizeEqualToSize(CGSizeMake(750, 1334), [[UIScreen mainScreen] currentMode].size) : NO)
#define TrainiPhone6Plus ([UIScreen instancesRespondToSelector:@selector(currentMode)] ? CGSizeEqualToSize(CGSizeMake(1242, 2208), [[UIScreen mainScreen] currentMode].size) : NO)
#define TrainiPhoneX ([TrainControllerUtil isiPhoneX])


#pragma mark - 获取屏幕的  高  宽

#define TrainSCREENHEIGHT  ([UIScreen mainScreen].bounds.size.height)

#define TrainSCREENWIDTH  ([UIScreen mainScreen].bounds.size.width)

#pragma mark - 视图距边界 px
#define TrainMarginWidth          15.0f
#define TrainCLASSHEIGHT          40.0f
#define TrainAlertOff_y           100.0f
//#define TrainNavHeight         64.0f
#define TrainNavorigin_y          0.0f
//#define TrainTabbarHeight         49.0f

#define  TrainSafeArea                  (TrainiPhoneX ? 34.0f : 0.0f)
#define  TrainNavHeight                 (TrainiPhoneX ? 88.0f : 64.0f)
#define  TrainTabbarHeight              (TrainiPhoneX ? 83.0f : 49.0f) //  49.0f
#define trainIconWidth               50.0f



#define  TrainScale                 (((TrainSCREENWIDTH < TrainSCREENHEIGHT) ? TrainSCREENWIDTH : TrainSCREENHEIGHT) / 375.0f)
#define  TrainScaleWith6(float)      (float *TrainScale)
//#define scale(iphone6)  (iphone6)
#define Train_BoldSizeFont(num)       [UIFont boldSystemFontOfSize: num * TrainScale]

#define TrainAPPVersions              [[[NSBundle mainBundle] infoDictionary] objectForKey:@"CFBundleShortVersionString"]

#define  TrainMovieHeight            (TrainSCREENWIDTH/16*9)

#define TrainTopicDetailMaxImageCount   9 // 详情最多
#define TrainTopicListMaxImageCount     3 // 话题列表上
#pragma mark - 颜色

#pragma mark - 16进制颜色
// #FFFFFF 颜色
#define TrainColorFromRGB16(rgbValue) [UIColor colorWithRed:((float)((rgbValue & 0xFF0000) >> 16))/255.0 green:((float)((rgbValue & 0xFF00) >> 8))/255.0 blue:((float)(rgbValue & 0xFF))/255.0 alpha:1.0]

#pragma mark - RGB颜色
#define TrainColorFromRGB(r, g, b)  ([UIColor colorWithRed:r/255.0 green:g/255.0 blue:b/255.0 alpha:1.0])

//#define TrainMenuSelectColor            [UIColor colorWithRed:1.0 green:192.0/255 blue:0 alpha:1.0]  //菜单 选中 (黄)

#define TrainBlueColor              [UIColor colorWithRed:36.0/255 green:204.0/255 blue:1.0 alpha:1.0];  //导航栏颜色
//#define TrainHourOrgColor           TrainColorFromRGB16(0xFF9628)  //导航栏颜色
//#define TrainNavColor           TrainColorFromRGB16(0x6FAD47)  //导航栏颜色


#define TrainMenuSelectColor    TrainNavColor                   //菜单 选中
#define TrainOrangeColor        TrainColorFromRGB16(0xFF8A10)

//#define TrainNavColor           TrainColorFromRGB16(0xE60012)  //导航栏颜色
#define TrainNavColor           TrainColorFromRGB16(0x6FAD47)  //导航栏颜色
#define TrainThemeTitleColor    TrainColorFromRGB16(0x6FAD47)
#define TrainTitleColor         TrainColorFromRGB16(0x565656)  // title (浅黑)
#define TrainContentColor       TrainColorFromRGB16(0xB7B7BA)  // 内容 (浅灰)
#define TrainLineColor          TrainColorFromRGB16(0xececec)  // 分割线 (浅浅灰)
#define TrainLineColor1         TrainColorFromRGB16(0xD9D9D9)  // 分割线1
#define TrainTitleFont          14.0f
#define TrainContentFont        12.0f

#define TrainIpText             @"101.201.48.193"
#define TrainHostText           @"e.learnking.net"


//@"elearnplus.com"


#define TrainDownLoadPath [NSHomeDirectory() stringByAppendingPathComponent:@"Documents/training"]

//AppDelegate对象
#define AppDelegateInstance     [[UIApplication sharedApplication] delegate]
//一些缩写 原生
#define TrainApplication        [UIApplication sharedApplication]
#define TrainNotiCenter         [NSNotificationCenter defaultCenter]
#define TrainUserDefault        [NSUserDefaults standardUserDefaults]
#define TrainFileManager        [NSFileManager defaultManager]

#define PGYAppKey      @"768af4f3b985146ea33f817eb735c44f"

//自定义
//#define TrainUser               [TrainUserInfo sharedTrainUserInfo]

#define DOC_CATCH_DATA [NSString stringWithFormat:@"%@_docArr",TrainUser.user_id]


//弱引用/强引用  可配对引用在外面用TrainWeakSelf(self)，block用TrainStrongSelf(self)  也可以单独引用在外面用TrainWeakSelf(self) block里面用weakself
#define TrainWeakSelf(type)  __weak typeof(type) weak##type = type
#define TrainStrongSelf(type)  __strong typeof(type) type = weak##type


//字符串是否为空
#define TrainStringIsEmpty(str) ([str isKindOfClass:[NSNull class]] || str == nil || [[str stringByTrimmingCharactersInSet:[NSCharacterSet whitespaceCharacterSet]] length]==0 ? YES : NO )
//数组是否为空
#define TrainArrayIsEmpty(array) (array == nil || [array isKindOfClass:[NSNull class]] || array.count == 0)
//字典是否为空
#define TrainDictIsEmpty(dic) (dic == nil || [dic isKindOfClass:[NSNull class]] || dic.allKeys == 0)
//是否是空对象
#define TrainObjectIsEmpty(_object) (_object == nil \
|| [_object isKindOfClass:[NSNull class]] \
|| ([_object respondsToSelector:@selector(length)] && [(NSData *)_object length] == 0) \
|| ([_object respondsToSelector:@selector(count)] && [(NSArray *)_object count] == 0))



//  单利

#define TrainSimpleH(className)\
+ (className *)shared##className;


#define TrainSimpleM(className) \
static className *_instance; \
+ (className *)shared##className \
{ \
static dispatch_once_t onceToken; \
dispatch_once(&onceToken, ^{ \
_instance = [[self alloc] init]; \
}); \
return _instance; \
}\
+ (id)allocWithZone:(NSZone *)zone \
{ \
static dispatch_once_t onceToken; \
dispatch_once(&onceToken, ^{ \
_instance = [super allocWithZone:zone]; \
}); \
return _instance; \
} \
- (id)copyWithZone:(NSZone *)zone{\
    return _instance;\
}

#endif /* TrainMacroDefine_h */
