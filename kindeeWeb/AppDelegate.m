//
//  AppDelegate.m
//  kindeeWeb
//
//  Created by Guang on 2020/2/6.
//  Copyright © 2020 WDG. All rights reserved.
//

#import "AppDelegate.h"
#import "TrainWebViewController.h"
#import "TrainWelcomeViewController.h"
#import <UMShare/UMShare.h>
#import "UMengHeader.h"
#import <UMCommon/UMCommon.h>

#import "RZBaseNavigationController.h"
#import "TrainAlertTools.h"
@interface AppDelegate ()

@property (nonatomic, strong)  UIVisualEffectView *effectView;

@end

@implementation AppDelegate


- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    // Override point for customization after application launch.
    
    self.window = [[UIWindow alloc] initWithFrame:[[UIScreen mainScreen] bounds] ];
    self.window.backgroundColor = [UIColor whiteColor];
    [self.window makeKeyAndVisible];
    sleep(1);
    [self loginUmengShare];
    [self getAppUpdate];
    [self evAddAdView];

    return YES;
}

- (void)evAddAdView {
    TrainWelcomeViewController *welcomeVC = [[TrainWelcomeViewController alloc]init];
    BOOL isFlag = [welcomeVC getWelcomeAD];
    if(isFlag) {
        RZBaseNavigationController *nav = [[RZBaseNavigationController alloc]initWithRootViewController:welcomeVC];
        self.window.rootViewController = nav ;

    }else {
        [self rzSetHomeView];
        [welcomeVC downloadWelcomAD];
    }
}


- (void)rzSetHomeView {
    
    RZBaseNavigationController *nav = [[RZBaseNavigationController alloc]initWithRootViewController:[[TrainWebViewController alloc]init]];
    self.window.rootViewController = nav;
}

/**
 友盟的出事画
 */
- (void)loginUmengShare{
    
    [UMConfigure initWithAppkey:@"5e44e4c80feb474e621fb21f" channel:@"App Store"];
    [UMConfigure setLogEnabled:YES];
    
    [[UMSocialManager defaultManager] openLog:YES];
//    [[UMSocialManager defaultManager] app]
//
//    NSString *version = [[[NSBundle mainBundle] infoDictionary] objectForKey:@"CFBundleShortVersionString"];
//    [MobClick setAppVersion:version];
//
//    /* 设置友盟appkey */
//    [[UMSocialManager defaultManager] setUmSocialAppkey:UMENGAPPKEY];
//    
    [self configUSharePlatforms];
    
    [self confitUShareSettings];
    
}

- (void)confitUShareSettings
{
    /*
     * 打开图片水印
     */
    //[UMSocialGlobal shareInstance].isUsingWaterMark = YES;
    
    /*
     * 关闭强制验证https，可允许http图片分享，但需要在info.plist设置安全域名
     <key>NSAppTransportSecurity</key>
     <dict>
     <key>NSAllowsArbitraryLoads</key>
     <true/>
     </dict>
     */
    //[UMSocialGlobal shareInstance].isUsingHttpsWhenShareContent = NO;
 
}

- (void)configUSharePlatforms
{
    /* 设置微信的appKey和appSecret */
    [[UMSocialManager defaultManager] setPlaform:UMSocialPlatformType_WechatSession appKey:WeChat_AppID  appSecret:WeChat_AppSecret redirectURL:@""];
//    [[UMSocialManager defaultManager] setPlaform:UMSocialPlatformType_WechatTimeLine appKey:WeChat_AppID  appSecret:WeChat_AppSecret redirectURL:@"http://mobile.umeng.com/social"];

    
    [UMSocialGlobal shareInstance].universalLinkDic = @{@(UMSocialPlatformType_WechatSession):@"https://e.learnking.net/"};
    /*
     * 移除相应平台的分享，如微信收藏
     */
    [[UMSocialManager defaultManager] removePlatformProviderWithPlatformTypes:@[@(UMSocialPlatformType_WechatFavorite)]];
    /* 设置dingding的appKey和appSecret */
    
    [[UMSocialManager defaultManager] setPlaform:UMSocialPlatformType_DingDing appKey:dingding_AppID  appSecret:dingding_AppSecret redirectURL:@""];
  
}

#pragma mark - ======  app 更新  =============
/*
     apkUrl = 1;
     content = 1;
     isUpdate = 1;
     updateTime = "2019-12-25 15:45:13.0000";
     version = 1;
     versionCode = 1;
 */

- (void)getAppUpdate {
    
    @weakify(self);
    [[TrainNetWorkAPIClient client] trainGetAppUpdateWithsuccess:^(NSDictionary *dic) {
        NSString  *appVersion = TrainAPPVersions ;;
        NSComparisonResult ss  = [dic[@"appVersion"] compare:appVersion options:NSLiteralSearch] ;
        if(ss == NSOrderedDescending){
            [weak_self rzCompareVersion:dic];
        }
    } andFailure:^(NSInteger errorCode, NSString *errorMsg) {
        
    } ];
}

- (void)rzCompareVersion:(NSDictionary *)dic {
    
    @weakify(self);
    NSString *msg = dic[@"updateContent"];
    NSString *title = dic[@"message"];
    title = (TrainStringIsEmpty(title)) ? @"更新提示" : title;
    NSString *url = dic[@"appUrl"];
    UIViewController  *viewVC = [TrainControllerUtil getTrainCurrentVC];
    if ([dic[@"isUpdate"] boolValue]) {
        
        @weakify(self);
        [TrainAlertTools showAlertWith:viewVC title:@"强制更新" message:msg callbackBlock:^(NSInteger btnIndex) {
            if(btnIndex == 0) {
                [weak_self zwbp_openAppStoreWithURL:url];
                [weak_self rzCompareVersion:dic] ;
            }
            
        } cancelButtonTitle:nil destructiveButtonTitle:@"更新" otherButtonTitles:nil, nil];
      
    }else {
    
       [ TrainAlertTools showAlertWith:viewVC title:@"更新提示" message:msg callbackBlock:^(NSInteger btnIndex) {
            
            if (btnIndex == 1) {
                
                [weak_self zwbp_openAppStoreWithURL:url];
            }
        } cancelButtonTitle:@"取消" destructiveButtonTitle:@"更新" otherButtonTitles:nil, nil];
    }
}

- (void)zwbp_openAppStoreWithURL:(NSString *)appUrl {
    
    NSURL* url = [NSURL URLWithString:appUrl];
    UIApplication *application = [UIApplication sharedApplication];
    if([application canOpenURL:url])
    {
       [application openURL:url options:@{} completionHandler:^(BOOL success) {
        }];
        
    }else {
    }
}



// 支持所有iOS系统
- (BOOL)application:(UIApplication *)application openURL:(NSURL *)url sourceApplication:(NSString *)sourceApplication annotation:(id)annotation
{
    //6.3的新的API调用，是为了兼容国外平台(例如:新版facebookSDK,VK等)的调用[如果用6.2的api调用会没有回调],对国内平台没有影响
    BOOL result = [[UMSocialManager defaultManager] handleOpenURL:url sourceApplication:sourceApplication annotation:annotation];
    NSLog(@"---url%@",url);
    if (!result) {
         // 其他如支付等SDK的回调
    }
    return result;
}

-(BOOL)application:(UIApplication *)application continueUserActivity:(NSUserActivity *)userActivity restorationHandler:(void (^)(NSArray * _Nullable))restorationHandler{
 
    NSLog(@"userActivity : %@",userActivity.webpageURL.description);
    return YES;
}

// 进入后台
- (void)applicationWillResignActive:(UIApplication *)application {
   
    
    [[[UIApplication sharedApplication] keyWindow] addSubview:self.effectView];

}

// 退出后台
- (void)applicationDidBecomeActive:(UIApplication *)application {
    [UIView animateWithDuration:0.5 animations:^{
           [self.effectView removeFromSuperview];
       }];
}

- (UIVisualEffectView *)effectView {
    if (!_effectView) {
        // 毛玻璃view 视图
        _effectView = [[UIVisualEffectView alloc] initWithEffect:[UIBlurEffect effectWithStyle:UIBlurEffectStyleLight]];
        // 设置模糊透明度
        _effectView.alpha = 1.f;
        _effectView.frame = [UIScreen mainScreen].bounds;
    }
    
    return _effectView;
}

#pragma mark - UISceneSession lifecycle


//- (UISceneConfiguration *)application:(UIApplication *)application configurationForConnectingSceneSession:(UISceneSession *)connectingSceneSession options:(UISceneConnectionOptions *)options {
//    // Called when a new scene session is being created.
//    // Use this method to select a configuration to create the new scene with.
//    return [[UISceneConfiguration alloc] initWithName:@"Default Configuration" sessionRole:connectingSceneSession.role];
//}


//- (void)application:(UIApplication *)application didDiscardSceneSessions:(NSSet<UISceneSession *> *)sceneSessions {
//    // Called when the user discards a scene session.
//    // If any sessions were discarded while the application was not running, this will be called shortly after application:didFinishLaunchingWithOptions.
//    // Use this method to release any resources that were specific to the discarded scenes, as they will not return.
//}


@end
