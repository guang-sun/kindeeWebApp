 //
//  RZUmengManager.m
//  CarePlan
//
//  Created by admin on 2017/6/6.
//  Copyright © 2017年 RZHL. All rights reserved.
//

#import "RZUMengManager.h"
#import "UMengHeader.h"
#import "UShareUI/UShareUI.h"

@interface RZUMengManager ()

@property (nonatomic, strong) UIViewController   *currentViewController ;

@end

@implementation RZUMengManager

static  RZUMengManager *mananger = nil;
+ (instancetype)sharedUMengManger  {
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        mananger = [[RZUMengManager alloc]init];
    });
    return mananger;
}

- (void)UMLoginGetUserInfoAndAuthForPlatform:(UMSocialPlatformType)formType completeHandle:(completeHandleBlock)complete{
    
    [[UMSocialManager defaultManager] getUserInfoWithPlatform:formType currentViewController:nil completion:^(id result, NSError *error) {
        
        
        if (!error && [result isKindOfClass:[UMSocialUserInfoResponse class]] ) {
           
            complete(result ,error);
            
        }else {
            
//            [RZProgressHUD showHUDWithError:@"取消授权"];
        }

        

    }];
}

- (void)UMAutoForPlatForm:(UMSocialPlatformType)formType completeHandle:(completeHandleBlock)complete {
    
    [[UMSocialManager defaultManager] authWithPlatform:formType currentViewController:nil completion:^(id result, NSError *error) {
        
        if (!error && [result isKindOfClass:[UMSocialAuthResponse class]] ) {
            UMSocialAuthResponse * resp = result;
            
            UMSocialUserInfoResponse *userInfoResp = [[UMSocialUserInfoResponse alloc] init];
            userInfoResp.uid            = resp.uid;
            userInfoResp.openid         = resp.openid;
            userInfoResp.accessToken    = resp.accessToken;
            userInfoResp.refreshToken   = resp.refreshToken;
            userInfoResp.expiration     = resp.expiration;
            
            
            
            
        }
        
    }];
}

- (void)UMCancleAutoForPlatForm:(UMSocialPlatformType)formType completeHandle:(completeHandleBlock)complete {
    
    [[UMSocialManager defaultManager] cancelAuthWithPlatform:formType completion:complete];
    
}

/**
 UMeng 分享的 api

 @param platformType    第三方 类型
 @param messageObj      分享的内容
 @param complete        分享后的回调
 */
- (void)UMAllShareToPlatformType:(UMSocialPlatformType)platformType
                   andMessageObj:(UMSocialMessageObject *)messageObj
                  completeHandle:(shareCompleteBlock)complete  {
    NSLog(@"121313==");
    [[UMSocialManager defaultManager] shareToPlatform:platformType messageObject:messageObj currentViewController: nil completion:^(id data, NSError *error) {
       NSLog(@"222222");
        NSLog(@"88888==%@===%@",error,data);

        if (error) {

            NSLog(@"1111111==%@",error);

            if(error.code == 2009){
                
//                [RZProgressHUD showHUDWithError:@"用户取消分享"];

            }else{
//                [RZProgressHUD showHUDWithError:@"分享失败"];
  
            }
            
            if(complete)complete(NO);

        }else{
            

            if ([data isKindOfClass:[UMSocialShareResponse class]]) {
                UMSocialShareResponse *resp = data;

//                if(!RZStringIsEmpty(resp.message)){
//
//                    [RZProgressHUD showHUDWithSuccess:resp.message];
//                }else {
//
//                    [RZProgressHUD showHUDWithSuccess:@"分享成功"];
//
//                };

                
            }else{
                
//                [RZProgressHUD showHUDWithSuccess:@"分享成功"];

                UMSocialLogInfo(@"response data is %@",data);
            }
            if(complete)complete(YES);

        }
    }];
 
    
}


- (void)UMShareDynamicWebPageToPlatformType:(UMSocialPlatformType)platformType
                                 dynamic_id:(NSString *)dynamic_id
                              dynamic_title:(NSString *)dynamic_title
                               dynamic_desc:(NSString *)dynamic_desc
                             completeHandle:(shareCompleteBlock)complete{
    
    //创建分享消息对象
    UMSocialMessageObject *messageObject = [UMSocialMessageObject messageObject];
    
    //创建网页内容对象
    UMShareWebpageObject *shareObject = [UMShareWebpageObject shareObjectWithTitle:UMS_Dynamic_Title descr:nil thumImage:[UIImage imageNamed:UMS_Dynamic_ThembName]];
    //设置网页地址
    
    NSString  *dynamicURL = @"" ;
    shareObject.webpageUrl = dynamicURL ;
    //分享消息对象设置分享内容对象
    messageObject.shareObject = shareObject;

    [self  UMAllShareToPlatformType:platformType andMessageObj:messageObject completeHandle:complete];
    
}

- (void)UMShareActivityWebPageToPlatformType:(UMSocialPlatformType)platformType
                                 activity_id:(NSString *)activity_id
                               activity_name:(NSString *)activity_name
                              adctivity_desc:(NSString *)adctivity_desc
                              completeHandle:(shareCompleteBlock)complete {
    NSLog(@"----");
    //创建分享消息对象
    UMSocialMessageObject *messageObject = [UMSocialMessageObject messageObject];
    messageObject.title =@"title";
    messageObject.text = @"text";
    
    //创建网页内容对象
//    UMShareWebpageObject *shareObject = [UMShareWebpageObject shareObjectWithTitle:activity_name descr:adctivity_desc thumImage:[UIImage imageNamed:UMS_Dynamic_ThembName]];
//    //设置网页地址
//
//    NSString  *acytivityURL =@"https://e.learnking.net/apple-app-site-association";
//
//    acytivityURL = [NSString stringWithFormat:@"%@&share=1",acytivityURL];
//
//    shareObject.webpageUrl = acytivityURL ;
//    //分享消息对象设置分享内容对象
//    messageObject.shareObject = shareObject;
    
    [self  UMAllShareToPlatformType:platformType andMessageObj:messageObject completeHandle:complete];
    
}


- (void)UMShareFoundWebPageToPlatformType:(UMSocialPlatformType)platformType
                                 found_id:(NSString *)found_id
                              found_title:(NSString *)found_title
                               found_desc:(NSString *)found_desc
                               found_image:(NSString *)found_image
                           completeHandle:(shareCompleteBlock)complete {
    
    //创建分享消息对象
    UMSocialMessageObject *messageObject = [UMSocialMessageObject messageObject];
    

    //创建网页内容对象
    UMShareWebpageObject *shareObject = [UMShareWebpageObject shareObjectWithTitle:found_title descr:found_desc thumImage: [UIImage imageNamed:UMS_Dynamic_ThembName]];
    //设置网页地址
    NSString  *dynamicURL = @"";
    dynamicURL = [NSString stringWithFormat:@"%@&share=1",dynamicURL];
    shareObject.webpageUrl = dynamicURL ;
    //分享消息对象设置分享内容对象
    messageObject.shareObject = shareObject;
    
    [self  UMAllShareToPlatformType:platformType andMessageObj:messageObject completeHandle:complete];
    
}

/**
 友盟 网页分享邀请好友的
 */
- (void)UMShareFirendWebPageToWeChatcompleteHandle:(shareCompleteBlock )complete {
    
    //创建分享消息对象
    UMSocialMessageObject *messageObject = [UMSocialMessageObject messageObject];

    //创建网页内容对象
    UMShareWebpageObject *shareObject = [UMShareWebpageObject shareObjectWithTitle:UMS_Invation_Title descr:@"期待您的加入" thumImage: [UIImage imageNamed:UMS_Dynamic_ThembName]];
    //设置网页地址
    shareObject.webpageUrl = UMS_Invation_URL ;
    //分享消息对象设置分享内容对象
    messageObject.shareObject = shareObject;

    [self  UMAllShareToPlatformType:UMSocialPlatformType_WechatSession andMessageObj:messageObject completeHandle:complete];
    
}

- (UIViewController *)currentViewController {
    
    if (!_currentViewController) {
        
         _currentViewController  = [TrainControllerUtil getTrainCurrentVC];
        
    }
    return _currentViewController;
}

+ (void)showShareViewACtionSheetWith:(UIViewController *)viewController
                       callbackBlock:(rzsheetShareCallBlock)block {
    
    
    
    [UMSocialUIManager setPreDefinePlatforms:@[@(UMSocialPlatformType_WechatSession),@(UMSocialPlatformType_WechatTimeLine),@(UMSocialPlatformType_DingDing)]];
    
    //  设置背景色
//    [UMSocialShareUIConfig shareInstance].sharePageGroupViewConfig.sharePageGroupViewBackgroundColor = RZColorFromRGB16(0xF9F9F9);
    
    [UMSocialShareUIConfig shareInstance].sharePageGroupViewConfig.sharePageGroupViewPostionType = UMSocialSharePageGroupViewPositionType_Bottom;
    
    // 设置 title 的文字
    [UMSocialShareUIConfig shareInstance].shareTitleViewConfig.shareTitleViewTitleString = @"分享到";
//    [UMSocialShareUIConfig shareInstance].shareTitleViewConfig.shareTitleViewFont = [UIFont customFontOfSize:13.0f];
//    [UMSocialShareUIConfig shareInstance].shareTitleViewConfig.shareTitleViewTitleColor = RZColorFromRGB16(0x333333);
    [UMSocialShareUIConfig shareInstance].shareTitleViewConfig.shareTitleViewPaddingTop = 10;
//    [UMSocialShareUIConfig shareInstance].shareTitleViewConfig. = RZMargin;

    // 中间的 设置
    [UMSocialShareUIConfig shareInstance].sharePageScrollViewConfig.shareScrollViewPageMaxRowCountForPortraitAndBottom = 1;
    [UMSocialShareUIConfig shareInstance].sharePageScrollViewConfig.shareScrollViewPageMaxColumnCountForPortraitAndBottom = 5;
   

    [UMSocialShareUIConfig shareInstance].sharePageScrollViewConfig.shareScrollViewPageItemStyleType = UMSocialPlatformItemViewBackgroudType_IconAndBGRadius;

    
    [UMSocialShareUIConfig shareInstance].shareCancelControlConfig.shareCancelControlText       = @"取消";
//    [UMSocialShareUIConfig shareInstance].shareCancelControlConfig.shareCancelControlTextColor  = RZColorFromRGB16(0x666666);
//    [UMSocialShareUIConfig shareInstance].shareCancelControlConfig.shareCancelControlTextFont   = [UIFont customFontOfSize:13.0f] ;
//    [UMSocialShareUIConfig shareInstance].shareCancelControlConfig.shareCancelControlBackgroundColor =  RZColorFromRGB16(0xF9F9F9);

    
    [UMSocialUIManager showShareMenuViewInWindowWithPlatformSelectionBlock:^(UMSocialPlatformType platformType, NSDictionary *userInfo) {
        
        if (block) {
            block(platformType);
        }
        
//        [RZCusAlertView shareWebPageToPlatformType:platformType];

    }];
    
}
@end
