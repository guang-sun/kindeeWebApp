//
//  PAUIKitLangManager.h
//  PaUIKit-PaUIKit
//
//  Created by 林文平(EX-LINWENPING002) on 2019/10/9.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface PAUIKitLangManager : NSObject

+ (void)configLanguage:(NSString *)language;

/*!
 @brief 下拉刷新
 */
+ (NSString *)downrefreshString;

/*!
 @brief 释放刷新
 */
+ (NSString *)releaserefreshString;

/*!
 @brief 努力刷新中
 */
+ (NSString *)downRefreshloadingString;

/*!
 @brief 上拉加载更多
 */
+ (NSString *)PBLoadMorePullUpString;

/*!
 @brief 释放加载
 */
+ (NSString *)PBLoadMoreReleaseString;

/*!
 @brief 努力加载中
 */
+ (NSString *)PBLoadMoreLoadingString;

/*!
 @brief 没有更多内容啦
 */
+ (NSString *)PBLoadMoreNoDataString;

/*!
 @brief 左滑加载更多
 */
+ (NSString *)PBLeftDragLoadMoreString;


+ (NSString *)PaUIKit_SignatureTipsString;
+ (NSString *)PaUIKit_ExamSignatureTipsString;
+ (NSString *)PaUIKit_InternalInformationString;
+ (NSString *)PaUIKit_FeelFreeToSignString;
+ (NSString *)PaUIKit_ClearScreenString;
+ (NSString *)PaUIKit_NoLongerReminderString;
+ (NSString *)PaUIKit_WatermarkAddedString;
+ (NSString *)PaUIKit_TagTheCommentsString;

/*!
 @brief 您输入的字数已超过最大限制啦
 */
+ (NSString *)wordMaximumLimitString;

/*!
 @brief 删除
 */
+ (NSString *)deleteString;

/*!
 @brief 跳过
 */
+ (NSString *)skipString;

/*!
 @brief 收藏成功
 */
+ (NSString *)successFavoriteString;

/*!
 @brief 确定
 */
+ (NSString *)sureString;

/*!
 @brief 相册授权
 */
+ (NSString *)albumAuthoreString;

/*!
 @brief 选择照片需要访问系统相册,请前往“设置－隐私－照片”中开启。
 */
+ (NSString *)photoPrivacyTipsString;

/*!
 @brief 我知道了
 */
+ (NSString *)knownString;

/*!
 @brief 去设置
 */
+ (NSString *)goToSetString;

/*!
 @brief 保存失败
 */
+ (NSString *)saveFailString;

/*!
 @brief 保存成功
 */
+ (NSString *)saveSuccessString;

/*!
 @brief 您可以在“我的-我的收藏”菜单中找到它！
 */
+ (NSString *)favoriteMenuTipsString;

/*!
 @brief 取消
 */
+ (NSString *)cancelString;

/*!
 @brief 最多只能添加%d张图片
 */
+ (NSString *)maximumImageCountString;


@end

NS_ASSUME_NONNULL_END
