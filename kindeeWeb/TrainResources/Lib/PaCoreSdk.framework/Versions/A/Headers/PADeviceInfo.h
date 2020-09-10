//
//  PADeviceInfo.h
//  MLPlayer
//
//  Created by txt on 15/6/20.
//  Copyright (c) 2015年 w. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <PaCoreSdk/UIFont+PAZNExtra.h>

# if ! __has_feature(objc_arc)
#define CMRELEASE(x) if (x != nil) {[x release];}
# else
#define CMRELEASE(__x)
# endif

#define SAFE_STRING(str) (![str isKindOfClass: [NSString class]] ? @"" : str)
#define STR_IS_NULL(str)  (str)?(str):@""
#define StringOBJ(strobj) (strobj)?(strobj):@""   //字符为空判断

#define SCREEN_WIDTH            ([[UIScreen mainScreen] bounds].size.width)
#define SCREEN_HEIGHT           ([[UIScreen mainScreen] bounds].size.height)
#define SCREEN_MAX_LENGTH       (MAX(SCREEN_WIDTH, SCREEN_HEIGHT))

#define IS_IPHONE       (UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPhone)
#define IS_IPHONE_4     ((IS_IPHONE) && (SCREEN_MAX_LENGTH == 480.0))
#define IS_IPHONE_5     ((IS_IPHONE) && (SCREEN_MAX_LENGTH == 568.0))
#define IS_IPHONE_6     ((IS_IPHONE) && (SCREEN_MAX_LENGTH == 667.0))
#define IS_IPHONE_6P    ((IS_IPHONE) && (SCREEN_MAX_LENGTH == 736.0))
#define IS_IPHONE_X     ((IS_IPHONE) && (SCREEN_MAX_LENGTH >= 812.0))

/*========================================屏幕适配============================================*/
//状态栏高度
#define def_baseStatusBar_height    [UIApplication sharedApplication].statusBarFrame.size.height

//导航栏高度（不包含状态栏）
#define def_baseNavBar_height       44

//导航栏高度（包含状态栏）
#define def_NavBar_height           (def_baseNavBar_height + def_baseStatusBar_height)

//iPhoneX底部高度
#define kIphoneBottomHeight         (IS_IPHONE_X ? 34 : 0)

//自定义tabBar按钮高度
#define kTabBarItemHeight           49

//自定义tabBar高度
#define kTabBarHeight               (kTabBarItemHeight + kIphoneBottomHeight)

#define kSystemVesion [[[UIDevice currentDevice] systemVersion] floatValue]

#define CURR_IOS_DEVICE_VERSION [[[UIDevice currentDevice] systemVersion] floatValue] //获取当前系统版本号

#define iPhone5 ([UIScreen instancesRespondToSelector:@selector(currentMode)] ? CGSizeEqualToSize(CGSizeMake(640, 1136), [[UIScreen mainScreen] currentMode].size) : NO)

#define UI_iphone5_WIDTH 320.0
#define UI_iphone5_Height 568.0
#define  kNaviRightButtonX  (UI_IOS_WINDOW_WIDTH * (10.0 / 320))

#define UI_iphone_WIDTH_320 320.0
#define UI_iphone_WIDTH_375 375.0

#if __IPHONE_OS_VERSION_MAX_ALLOWED >= 30200

//设置1像素分割线
#define SINGLE_LINE_BOUNDS          (1 / [UIScreen mainScreen].scale)
#define SINGLE_LINE_ADJUST_OFFSET   ((1 / [UIScreen mainScreen].scale) / 2)

#define UI_IOS_WINDOW_WIDTH     [[UIScreen mainScreen] bounds].size.width
#define UI_IOS_WINDOW_HEIGHT    [[UIScreen mainScreen] bounds].size.height

//横屏判断
#define kIsLandscape ( ([[UIApplication sharedApplication] statusBarOrientation] == UIInterfaceOrientationLandscapeLeft) || \
([[UIApplication sharedApplication] statusBarOrientation] == UIInterfaceOrientationLandscapeRight) )
#define kIsPortrait  (!kIsLandscape)

//横屏状态下最小，最大宽
#define kMINScreenWidth     MIN(UI_IOS_WINDOW_WIDTH, UI_IOS_WINDOW_HEIGHT)
#define kMAXScreenWidth     MAX(UI_IOS_WINDOW_WIDTH, UI_IOS_WINDOW_HEIGHT)

//屏幕适配ui尺寸
#define BoundsOfScale(x) (UI_IOS_WINDOW_HEIGHT > UI_IOS_WINDOW_WIDTH ? round((x)*(UI_IOS_WINDOW_WIDTH/320.0)) : round((x)*(UI_IOS_WINDOW_WIDTH/568.0)))

#define BoundsOfScale6(x) (UI_IOS_WINDOW_HEIGHT > UI_IOS_WINDOW_WIDTH ? round((x)*(UI_IOS_WINDOW_WIDTH/375.0)) : round((x)*(UI_IOS_WINDOW_WIDTH/667.0)))

#define BoundsOfScale6AndX(x) (UI_IOS_WINDOW_HEIGHT > UI_IOS_WINDOW_WIDTH ? round((x)*(UI_IOS_WINDOW_WIDTH/375.0)) : round((x)*(IS_IPHONE_X ? 1 : (UI_IOS_WINDOW_WIDTH/667.0))))

#define BoundsOfScale6AdjustAll(x) (UI_IOS_WINDOW_HEIGHT > UI_IOS_WINDOW_WIDTH ? round((x)*(UI_IOS_WINDOW_WIDTH/375.0)) : round((x)*(UI_IOS_WINDOW_HEIGHT/375.0)))

//6p字体尺寸+1
#define FontOfScale(font) (IS_IPHONE_6P ? (font+1) :(font))

#endif

#define kUnderStatusBarStartY (kSystemVesion>=7.0 ? 20 : 0) //7.0以上stautsbar不占位置，内容视图的起始位置要往下20
#define kContentHeight        (kScreenHeight - kNavigationBarHeight -kStatusBarHeight)

/*========================================屏幕适配============================================*/
#define kIOSVersions [[[UIDevice currentDevice] systemVersion] floatValue] //获得iOS版本
#define kIS_IOS8     (kIOSVersions >= 8.0)  //获得iOS版本
//#define kUIWindow    [[[UIApplication sharedApplication] delegate] window] //获得window

#define kUIWindow    [[UIApplication sharedApplication] keyWindow] //获得window
#define kAppWindow   [[UIApplication sharedApplication].delegate window] //获得window

#define kScreenSize           [[UIScreen mainScreen] bounds].size                 //(e.g. 320,480)
#define kScreenWidth          [[UIScreen mainScreen] bounds].size.width           //(e.g. 320)
#define kScreenHeight  (kIOSVersions>=7.0 ? [[UIScreen mainScreen] bounds].size.height : [[UIScreen mainScreen] bounds].size.height)
#define kIOS7OffHeight def_NavBar_height
#define kHeightFromSatus (kIOSVersions>=7.0 ? 24 : 0)

#define kApplicationSize      [[UIScreen mainScreen] applicationFrame].size       //(e.g. 320,460)
#define kApplicationWidth     [[UIScreen mainScreen] applicationFrame].size.width //(e.g. 320)
#define kApplicationHeight    [[UIScreen mainScreen] applicationFrame].size.height//不包含状态bar的高度(e.g. 460)

#define kStatusBarHeight         def_baseStatusBar_height
#define kNavigationBarHeight     def_baseNavBar_height
#define kNavigationheightForIOS7 def_NavBar_height

//#define kContentHeight           (kApplicationHeight - kNavigationBarHeight)
#define kTableRowTitleSize       14
#define maxPopLength             215
#define kSeekTabBarHeight (kIOSVersions>=7.0 ? 0 : 49)  //活动主页适配用

//颜色定义=================================================

#define UIColorRGBA(color,nAlpha) UIColorMakeRGBA(color>>16, (color&0x00ff00)>>8,color&0x0000ff,nAlpha)
#define UIColorMakeRGBA(r, g, b, a) [UIColor colorWithRed:(r)/255.0f green:(g)/255.0f blue:(b)/255.0f alpha:a]

#define UIColorFromRGB(rgbValue) [UIColor colorWithRed:((float)((rgbValue & 0xFF0000) >> 16))/255.0 green:((float)((rgbValue & 0xFF00) >> 8))/255.0 blue:((float)(rgbValue & 0xFF))/255.0 alpha:1.0]

#define ColorWithRGB(r,g,b) [UIColor colorWithRed:r/255.0 green:g/255.0 blue:b/255.0 alpha:1.0]

#define UIColorMakeRGB(nRed, nGreen, nBlue) UIColorMakeRGBA(nRed, nGreen, nBlue, 1.0f)
#define UIColorRGB(color) UIColorMakeRGB(color>>16, (color&0x00ff00)>>8,color&0x0000ff)
#define RGB(r,g,b) ColorWithRGB(r,g,b)

#define RGBOF(rgbValue)     [UIColor colorWithRed:((float)((rgbValue & 0xFF0000) >> 16))/255.0 \
green:((float)((rgbValue & 0xFF00) >> 8))/255.0 \
blue:((float)(rgbValue & 0xFF))/255.0 \
alpha:1.0]

#define PAPingFangSCFont(fontSize) [UIFont fontWithNameSafe:@"PingFangSC-Regular" size:fontSize]
#define PAPingFangTCFont(fontSize) [UIFont fontWithNameSafe:@"PingFangTC-Regular" size:fontSize]
#define PAPingFangSC_MediumFont(fontSize) [UIFont fontWithNameSafe:@"PingFangSC-Medium" size:fontSize]
#define PAPingFangTC_MediumFont(fontSize) [UIFont fontWithNameSafe:@"PingFangTC-Medium" size:fontSize]
#define PAPingFangSC_SemiboldFont(fontSize) [UIFont fontWithNameSafe:@"PingFangSC-Semibold" size:fontSize]
#define PAPingFangTC_SemiboldFont(fontSize) [UIFont fontWithNameSafe:@"PingFangTC-Semibold" size:fontSize]

// 默认头像
#define kPADefaultHeaderImage(imageUrl) \
({ \
UIImage *placeHolderImage; \
if([imageUrl hasSuffix:@"default1"]){ \
    placeHolderImage = [UIImage imageNamed:@"default1"]; \
}else if([imageUrl hasSuffix:@"default2"]){ \
    placeHolderImage = [UIImage imageNamed:@"default2"]; \
}else{ \
    placeHolderImage = [UIImage imageNamed:@"com_default"]; \
} \
placeHolderImage; \
})

#define pa_isDictionary( value )  if ( ![value isKindOfClass:NSDictionary.class] ) return ;
#define pa_isArray( value )  if ( ![value isKindOfClass:NSArray.class] ) return ;

#define LEARN_DESC_COLOR		[UIColor colorWithRed:136.0f/255.0f green:136.0f/255.0f blue:136.0f/255.0f alpha:1.0f];

#define LEARN_TITLE_FONT18	17.0 //学习中心课程标题标题字号
#define LEARN_TITLE_FONT16	16.0 //学习中心课程标题标题字号
#define LEARN_TITLE_FONT15	11.0 //学习中心课程标题标题字号
#define SETTING_TITLE_FONT14	14.0 //设置
#define LEARN_TITLE_FONT10  13.0
#define LEARN_TITLE_FONT9	9.0
#define LEARN_ATTRIBUTE_FONT  12.0

#define ZNUserDefaults [NSUserDefaults standardUserDefaults]
#define ZNFileManager [NSFileManager defaultManager]
#define ZNNotification [NSNotificationCenter defaultCenter]
//颜色定义=================================================









