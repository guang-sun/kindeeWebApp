//
//  RZUmengManager.h
//  CarePlan
//
//  Created by admin on 2017/6/6.
//  Copyright © 2017年 RZHL. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UMShare/UMShare.h>

typedef void (^completeHandleBlock)(id result ,NSError  *error);
typedef void (^shareCompleteBlock)(BOOL  isComplete);

/**
 *  分享的回调block
 */
typedef void (^rzsheetShareCallBlock)(UMSocialPlatformType  formType);

@interface RZUMengManager : NSObject


+ (instancetype)sharedUMengManger ;

/**
 获取授权 并且获取用户的信息

 */
- (void)UMLoginGetUserInfoAndAuthForPlatform:(UMSocialPlatformType )formType completeHandle:(completeHandleBlock )complete;

/**
 获取授权
  */
- (void)UMAutoForPlatForm:(UMSocialPlatformType )formType completeHandle:(completeHandleBlock )complete;

/**
 取消授权
  */
- (void)UMCancleAutoForPlatForm:(UMSocialPlatformType )formType completeHandle:(completeHandleBlock )complete;



/**
 友盟 网页分享
 @param platformType 分享平台
 @param dynamic_id   分享动态的id  获取动态详情的url
 */
- (void)UMShareDynamicWebPageToPlatformType:(UMSocialPlatformType)platformType
                                 dynamic_id:(NSString *)dynamic_id
                              dynamic_title:(NSString *)dynamic_title
                              dynamic_desc:(NSString *)dynamic_desc
                             completeHandle:(shareCompleteBlock )complete;


/**
 友盟 网页分享
 @param platformType 分享平台
 @param found_id   分享动态的id
 */
- (void)UMShareFoundWebPageToPlatformType:(UMSocialPlatformType)platformType
                                 found_id:(NSString *)found_id
                              found_title:(NSString *)found_title
                               found_desc:(NSString *)found_desc
                              found_image:(NSString *)found_image
                             completeHandle:(shareCompleteBlock )complete;



/**
 友盟 活动分享


 */
- (void)UMShareActivityWebPageToPlatformType:(UMSocialPlatformType)platformType
                                 activity_id:(NSString *)activity_id
                               activity_name:(NSString *)activity_name
                              adctivity_desc:(NSString *)adctivity_desc
                              completeHandle:(shareCompleteBlock)complete ;


/**
 友盟 网页分享邀请好友的
 */
- (void)UMShareFirendWebPageToWeChatcompleteHandle:(shareCompleteBlock )complete;


/**
 显示分享列表的sheet

 */
+ (void)showShareViewACtionSheetWith:(UIViewController *)viewController
                       callbackBlock:(rzsheetShareCallBlock)block;


@end
