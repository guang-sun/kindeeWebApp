//
//  PAAdBannerView.h
//  Pods
//
//  Created by 胡铭(智慧教育) on 2020/5/7.
//

#import <UIKit/UIKit.h>
@class PAAdBannerView;

NS_ASSUME_NONNULL_BEGIN

@protocol PAAdBannerViewDelegate <NSObject>

/// 获取广告，返回广告id，第一个广告自己处理展示事件
/// @param adBannerView - adBannerView
/// @param containView - 广告视图
/// @param completion - 广告加载回调（成功或者失败）
- (NSString *)adIdOfAdBannerView:(PAAdBannerView *)adBannerView
      prepareForAdForContainView:(UIImageView *)containView
                  loadCompletion:(void(^)(BOOL hasLoaded,NSString *adsId))completion;

/// 展示了新广告
/// @param adBannerView - adBannerView
- (void)adBannerView:(PAAdBannerView *)adBannerView showAdWithAdId:(NSString *)adId;

/// 用户点击了广告
/// @param adBannerView - adBannerView
- (void)adBannerView:(PAAdBannerView *)adBannerView clickAdWithAdId:(NSString *)adId;

/// 广告视图销毁
/// @param adBannerView - adBannerView
- (void)dismissAdBannerView:(PAAdBannerView *)adBannerView;

/// 广告视图销毁回调
/// @param adBannerView - adBannerView
- (void)deallocAdBannerView:(PAAdBannerView *)adBannerView;

///通过adid获取content的size
- (CGSize)adBannerView:(PAAdBannerView *)adBannerView contentSizeWithAdId:(NSString *)adId;

///反馈更新了content
- (void)adBannerView:(PAAdBannerView *)adBannerView reloadContentSizeWithAdId:(NSString *)adId;

/// 广告加载失败
/// @param adBannerView - adBannerView
- (void)didLoadFailAdBannerView:(PAAdBannerView *)adBannerView;

@end

typedef NS_ENUM(NSUInteger, PAAdBannerViewStyle) {
    PAAdBannerView_Search,
    PAAdBannerView_CoursePause_StoreCourse = 1,
    PAAdBannerView_CoursePause_EnterPriseCourse = 2,
    PAAdBannerView_CoursePause_PublicCourse = 3,
    PAAdBannerView_CourseDetail,
    PAAdBannerView_Search_Enterprise,
    PAAdBannerView_LearnBarCategory
};

typedef NS_ENUM(NSInteger, PAAdBannerViewShowStyle) {
    ///小屏幕
    PAAdBannerView_ShowCustom = 0,
    ///横屏屏幕
    PAAdBannerView_All_Lanscape = 1,
    ///竖屏幕
    PAAdBannerView_All_Portrait = 2,
};

typedef void(^PAAdBannerLoad)(BOOL loaded,NSString *adsId);

@interface PAAdBannerView : UIView

@property (nonatomic, assign, readonly) PAAdBannerViewStyle style;  //类型
@property (nonatomic, assign) BOOL autoScolled;  //是否开启自动滚动
@property (nonatomic, assign) NSTimeInterval duration;  //多少秒滚动一次
@property (nonatomic, weak) id<PAAdBannerViewDelegate> delegate;
@property (nonatomic, assign) BOOL showCloseButton;  //是否显示关闭按钮

@property (nonatomic, copy) NSString *currentAdId;                  ///< 当前广告id

@property (nonatomic, strong) NSMutableArray *inmobiAds;


- (instancetype)init __attribute__((unavailable("call other method instead")));
- (instancetype)initWithFrame:(CGRect)frame __attribute__((unavailable("call other method instead")));
- (instancetype)initWithFrame:(CGRect)frame andStyle:(PAAdBannerViewStyle)style andDelegate:(id<PAAdBannerViewDelegate>)delegate;

/// 显示下一个广告
- (void)showNextAd;

- (void)reloadContentFrame;
@end

NS_ASSUME_NONNULL_END
