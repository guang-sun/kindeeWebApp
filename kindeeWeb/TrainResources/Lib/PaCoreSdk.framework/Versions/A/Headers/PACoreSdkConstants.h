//
//  PACoreSdkConstants.h
//  PaCoreSdk
//
//  Created by 王斌(平安科技智慧教育团队项目研发部知鸟研发团队移动开发组) on 2019/1/14.
//

#ifndef PACoreSdkConstants_h
#define PACoreSdkConstants_h

//屏蔽Release下的NSLog
#ifndef __OPTIMIZE__

#define NSLog(...) NSLog(__VA_ARGS__)

#else

#define NSLog(...) {}

#endif


//获取当前系统版本号
#define CURR_IOS_DEVICE_VERSION [[[UIDevice currentDevice] systemVersion] floatValue]

//设置颜色
#define UIColorRGBA(color,nAlpha) UIColorMakeRGBA(color>>16, (color&0x00ff00)>>8,color&0x0000ff,nAlpha)
#define UIColorMakeRGBA(r, g, b, a) [UIColor colorWithRed:(r)/255.0f green:(g)/255.0f blue:(b)/255.0f alpha:a]

#define UIColorFromRGB(rgbValue) [UIColor colorWithRed:((float)((rgbValue & 0xFF0000) >> 16))/255.0 green:((float)((rgbValue & 0xFF00) >> 8))/255.0 blue:((float)(rgbValue & 0xFF))/255.0 alpha:1.0]

#define ColorWithRGB(r,g,b) [UIColor colorWithRed:r/255.0 green:g/255.0 blue:b/255.0 alpha:1.0]

#define UIColorMakeRGB(nRed, nGreen, nBlue) UIColorMakeRGBA(nRed, nGreen, nBlue, 1.0f)
#define UIColorRGB(color) UIColorMakeRGB(color>>16, (color&0x00ff00)>>8,color&0x0000ff)

#define skinColor_blue        UIColorRGB(0x3790e0)
#define skinColor_yellow      UIColorRGB(0xfebe40)
#define skinColor_green       UIColorRGB(0x46cda4)
#define skinColor_red         UIColorRGB(0xf55848)
#define Skin_default_navColor UIColorRGB(0xf55848)

//设置尺寸
#define kNavigationheightForIOS7    64

#define IS_IPHONE (UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPhone)
#define SCREEN_WIDTH ([[UIScreen mainScreen] bounds].size.width)
#define SCREEN_HEIGHT ([[UIScreen mainScreen] bounds].size.height)
#define SCREEN_MAX_LENGTH (MAX(SCREEN_WIDTH, SCREEN_HEIGHT))
#define IS_IPHONE_6 ((IS_IPHONE) && (SCREEN_MAX_LENGTH == 667.0))
#define IS_IPHONE_6P ((IS_IPHONE) && (SCREEN_MAX_LENGTH == 736.0))
#define UI_iphone5_WIDTH 320.0
#define UI_iphone5_Height 568.0
#define kNaviRightButtonX  (UI_IOS_WINDOW_WIDTH * (10.0 / 320))

//设置1像素分割线
#define SINGLE_LINE_BOUNDS          (1 / [UIScreen mainScreen].scale)
#define SINGLE_LINE_ADJUST_OFFSET   ((1 / [UIScreen mainScreen].scale) / 2)

#define UI_IOS_WINDOW_WIDTH     [[UIScreen mainScreen] bounds].size.width
#define UI_IOS_WINDOW_HEIGHT    [[UIScreen mainScreen] bounds].size.height

//横屏状态下最小，最大宽
#define kMINScreenWidth     MIN(UI_IOS_WINDOW_WIDTH, UI_IOS_WINDOW_HEIGHT)
#define kMAXScreenWidth     MAX(UI_IOS_WINDOW_WIDTH, UI_IOS_WINDOW_HEIGHT)

//屏幕适配ui尺寸
#define BoundsOfScale(x) (UI_IOS_WINDOW_HEIGHT > UI_IOS_WINDOW_WIDTH ? round((x)*(UI_IOS_WINDOW_WIDTH/320.0)) : round((x)*(UI_IOS_WINDOW_WIDTH/568.0)))

//6p字体尺寸+1
#define FontOfScale(font) (IS_IPHONE_6P ? (font+1) :(font))

// 子组件加载图片
#define PAZNLoadImage( imageName ) \
({ \
NSBundle *bundle = [NSBundle bundleForClass:[self class]]; \
NSString *bundleName = bundle.infoDictionary[@"CFBundleName"]; \
NSURL *url = [bundle URLForResource:bundleName withExtension:@"bundle"]; \
\
NSBundle *imagebundle = [NSBundle bundleWithURL:url]; \
UIImage *image = [UIImage imageNamed:imageName inBundle:imagebundle compatibleWithTraitCollection:nil]; \
image; \
})

#endif /* PACoreSdkConstants_h */
