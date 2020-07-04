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

@interface AppDelegate ()

@end

@implementation AppDelegate


- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    // Override point for customization after application launch.
    
    self.window = [[UIWindow alloc] initWithFrame:[[UIScreen mainScreen] bounds] ];
    self.window.backgroundColor = [UIColor whiteColor];
    [self.window makeKeyAndVisible];
    
    [self loginUmengShare];
    
   
    TrainWelcomeViewController *welcomeVC = [[TrainWelcomeViewController alloc]init];
    BOOL isFlag = [welcomeVC getWelcomeAD];
    if(isFlag) {

        RZBaseNavigationController *nav = [[RZBaseNavigationController alloc]initWithRootViewController:welcomeVC];
        self.window.rootViewController = nav ;

    }else {
        
        RZBaseNavigationController *nav = [[RZBaseNavigationController alloc]initWithRootViewController:[[TrainWebViewController alloc]init]];
        self.window.rootViewController = nav;
        [welcomeVC downloadWelcomAD];
    }
    
    
    

    return YES;
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
