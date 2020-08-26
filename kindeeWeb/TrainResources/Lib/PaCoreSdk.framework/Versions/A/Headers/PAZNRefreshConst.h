//  代码地址: https://github.com/CoderMJLee/MJRefresh
//  代码地址: http://code4app.com/ios/%E5%BF%AB%E9%80%9F%E9%9B%86%E6%88%90%E4%B8%8B%E6%8B%89%E4%B8%8A%E6%8B%89%E5%88%B7%E6%96%B0/52326ce26803fabc46000000
#import <UIKit/UIKit.h>
#import <objc/message.h>

// 弱引用
#define PAZNWeakSelf __weak typeof(self) weakSelf = self;

// 日志输出
#ifdef DEBUG
#define PAZNRefreshLog(...) NSLog(__VA_ARGS__)
#else
#define PAZNRefreshLog(...)
#endif

// 过期提醒
#define PAZNRefreshDeprecated(instead) NS_DEPRECATED(2_0, 2_0, 2_0, 2_0, instead)

// 运行时objc_msgSend
#define PAZNRefreshMsgSend(...) ((void (*)(void *, SEL, UIView *))objc_msgSend)(__VA_ARGS__)
#define PAZNRefreshMsgTarget(target) (__bridge void *)(target)

// RGB颜色
#define PAZNRefreshColor(r, g, b) [UIColor colorWithRed:(r)/255.0 green:(g)/255.0 blue:(b)/255.0 alpha:1.0]

// 文字颜色
#define PAZNRefreshLabelTextColor PAZNRefreshColor(90, 90, 90)

// 字体大小
#define PAZNRefreshLabelFont [UIFont boldSystemFontOfSize:14]

// 常量
UIKIT_EXTERN const CGFloat PAZNRefreshLabelLeftInset;
UIKIT_EXTERN const CGFloat PAZNRefreshHeaderHeight;
UIKIT_EXTERN const CGFloat PAZNRefreshFooterHeight;
UIKIT_EXTERN const CGFloat PAZNRefreshFastAnimationDuration;
UIKIT_EXTERN const CGFloat PAZNRefreshSlowAnimationDuration;

UIKIT_EXTERN NSString *const PAZNRefreshKeyPathContentOffset;
UIKIT_EXTERN NSString *const PAZNRefreshKeyPathContentSize;
UIKIT_EXTERN NSString *const PAZNRefreshKeyPathContentInset;
UIKIT_EXTERN NSString *const PAZNRefreshKeyPathPanState;

UIKIT_EXTERN NSString *const PAZNRefreshHeaderLastUpdatedTimeKey;

UIKIT_EXTERN NSString *const PAZNRefreshHeaderIdleText;
UIKIT_EXTERN NSString *const PAZNRefreshHeaderPullingText;
UIKIT_EXTERN NSString *const PAZNRefreshHeaderRefreshingText;

UIKIT_EXTERN NSString *const PAZNRefreshAutoFooterIdleText;
UIKIT_EXTERN NSString *const PAZNRefreshAutoFooterRefreshingText;
UIKIT_EXTERN NSString *const PAZNRefreshAutoFooterNoMoreDataText;

UIKIT_EXTERN NSString *const PAZNRefreshBackFooterIdleText;
UIKIT_EXTERN NSString *const PAZNRefreshBackFooterPullingText;
UIKIT_EXTERN NSString *const PAZNRefreshBackFooterRefreshingText;
UIKIT_EXTERN NSString *const PAZNRefreshBackFooterNoMoreDataText;

UIKIT_EXTERN NSString *const PAZNRefreshHeaderLastTimeText;
UIKIT_EXTERN NSString *const PAZNRefreshHeaderDateTodayText;
UIKIT_EXTERN NSString *const PAZNRefreshHeaderNoneLastDateText;

// 状态检查
#define PAZNRefreshCheckState \
PAZNRefreshState oldState = self.state; \
if (state == oldState) return; \
[super setState:state];
