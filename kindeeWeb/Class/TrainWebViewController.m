//
//  TrainWebViewController.m
//  kindeeWeb
//
//  Created by Guang on 2020/2/7.
//  Copyright © 2020 WDG. All rights reserved.
//

#import "TrainWebViewController.h"
#import "RZUMengManager.h"
#import "TrainScanViewController.h"
#import "TrainMacroDefine.h"
#import <YYKit.h>
@interface TrainWebViewController ()
{
 
    BOOL   _isLanjie ;  // 判断是新旧页面  根据 url
    __block BOOL   _isShowBack ;
}

@property (nonatomic, strong) UIButton   *backButton ;
@property (nonatomic, strong) UIView   *iconButton ;
@end

@implementation TrainWebViewController

- (void)viewWillAppear:(BOOL)animated {
    [super viewWillAppear:animated];
//    self.navigationController.navigationBar.hidden =YES;
}

- (void)viewDidLoad {
    [super viewDidLoad];
    [self evSetLoginNavHiddenWithhidden:YES];
    
    [self evInitNavgation];
    [self evInitIconButton];
    
    NSString  *webUrl = [TrainUserDefault objectForKey:TrainWebHostText];
    NSString  *param = [TrainUserDefault objectForKey:TrainWebHomeParam];
    _isShowBack = NO;
    if (TrainStringIsEmpty(webUrl) || webUrl.length <= 8) {
//        self.webUrl = @"https://learning.newvane.com.cn";
        self.webUrl = @"https://tequ.newvane.com.cn";
    }else {
     
        webUrl = [NSString stringWithFormat:@"%@%@",webUrl,param];
        self.webUrl = webUrl ;
    }
//    UIColor *color  =  [UIColor colorWithHexString:@"#d00403"];
//
//    UIButton  *button  = [UIButton buttonWithType:UIButtonTypeCustom];
//    button.backgroundColor = color;
//    [button setTitle:@"share" forState:UIControlStateNormal];
//    button.frame = CGRectMake(0, 50, 100, 150);
//    [button addTarget:self action:@selector(trainShareAppWithUrl) forControlEvents:UIControlEventTouchUpInside];
//    [self.view addSubview:button];
////
//
//    UIButton  *button1  = [UIButton buttonWithType:UIButtonTypeCustom];
//       button1.backgroundColor = [UIColor redColor];
//       [button1 setTitle:@"scan" forState:UIControlStateNormal];
//       button1.frame = CGRectMake(0, 210, 100, 50);
//    [button1 addTarget:self action:@selector(trainShareAppWithUrl1) forControlEvents:UIControlEventTouchUpInside];
//       [self.view addSubview:button1];
//
//    UIButton  *button2  = [UIButton buttonWithType:UIButtonTypeCustom];
//       button2.backgroundColor = [UIColor redColor];
//       [button2 setTitle:@"share" forState:UIControlStateNormal];
//       button2.frame = CGRectMake(0, 310, 100, 50);
//    [button2 addTarget:self action:@selector(trainShareAppWithUrl2) forControlEvents:UIControlEventTouchUpInside];
//       [self.view addSubview:button2];

    
    [self loadWebView:self.webUrl];
    [self registShareFunction];
    [self RegeistNoticeCenter];

    // Do any additional setup after loading the view.
}

- (void)evInitNavgation {
 
    UIButton  *button = [UIButton buttonWithType:UIButtonTypeCustom];
    [button setImage:[UIImage imageNamed:@"nav_button_fanhui_2_default"] forState:UIControlStateNormal];
    button.frame = CGRectMake(0, 0, 50, 40);
    button.contentHorizontalAlignment = UIControlContentHorizontalAlignmentLeft ;
    [button addTarget:self action:@selector(evBackView) forControlEvents:UIControlEventTouchUpInside];
    self.backButton = button ;
    
}

-(void)evInitIconButton {
    
    UIImageView  *imageView = [[UIImageView alloc]initWithImage:[UIImage imageNamed:@"newnavce_zhou_icon"]];
    imageView.contentMode = UIViewContentModeScaleAspectFit;
    imageView.frame = CGRectMake(0, 0, 150, 40);
    
    UIView  *view = [[UIView alloc]initWithFrame:CGRectMake(0, 0, 150, 44)];
    [view addSubview:imageView];
    self.iconButton = view ;
    

}

- (void)evInitZhouIconWithHidden:(BOOL) hidden {
    
      if (hidden) {
          
           UIBarButtonItem *item = [[UIBarButtonItem alloc]init];
           self.navigationItem.leftBarButtonItem = item ;
          
      }else {
          self.navigationItem.title = @"";
          UIBarButtonItem *item = [[UIBarButtonItem alloc]initWithCustomView:self.iconButton];
          self.navigationItem.leftBarButtonItem = item ;
         
      }
}

- (void)evBackView {
    
    if (_isLanjie) {
       
        [self.rzWebView goBack];
    }else {
        [self.webViewBridge callHandler:@"back" data:nil responseCallback:^(id responseData) {
                                 NSLog(@"1后的回调：%@",responseData);
         }];
    }
  

    
}
- (void)rzwebviewLayout {
    
    [self.rzWebView mas_remakeConstraints:^(MASConstraintMaker *make) {
        make.edges.equalTo(self.view).insets(UIEdgeInsetsMake(0, 0, 0, 0));
    }];
}

- (void)updateWebViewTopWithNavShow:(BOOL)isShow {
//    CGFloat height = (isShow)? TrainNavHeight : 0 ;
//
//    [self.rzWebView mas_updateConstraints:^(MASConstraintMaker *make) {
//        make.top.equalTo(self.view).offset(height);
//    }];
//
//    [UIView animateWithDuration:0.5 animations:^{
//        [self.view layoutIfNeeded];
//    }];
    
}

-(void)RegeistNoticeCenter {
    //将要进入全屏
    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(startFullScreen) name:UIWindowDidResignKeyNotification object:nil];
//    UIWindowDidBecomeVisibleNotification   UIWindowDidResignKeyNotification UIWindowDidBecomeKeyNotification
    //退出全屏
    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(endFullScreen) name:UIWindowDidBecomeHiddenNotification object:nil];
}

-(void)startFullScreen {
    NSLog(@"进入全屏");
//    UIApplication *application=[UIApplication sharedApplication];
//    [application setStatusBarOrientation: UIInterfaceOrientationLandscapeRight];
//    application.keyWindow.transform=CGAffineTransformMakeRotation(M_PI/2);
//    CGRect frame = [UIScreen mainScreen].applicationFrame;
//    application.keyWindow.bounds = CGRectMake(0, 0, frame.size.height + 20, frame.size.width);
    if (self.rzWebView.bounds.size.width < self.rzWebView.bounds.size.height) {

    [[UIDevice currentDevice] setValue:[NSNumber numberWithInteger:UIInterfaceOrientationLandscapeRight] forKey:@"orientation"];

    } else {

    [[UIDevice currentDevice] setValue:[NSNumber numberWithInteger:UIInterfaceOrientationPortrait] forKey:@"orientation"];

    }

    

   
    
}

-(void)endFullScreen {
    NSLog(@"退出全屏XXXX");
//    UIApplication *application=[UIApplication sharedApplication];
//    [application setStatusBarOrientation: UIInterfaceOrientationLandscapeRight];
//    CGRect frame = [UIScreen mainScreen].applicationFrame;
//    application.keyWindow.bounds = CGRectMake(0, 0, frame.size.width, frame.size.height + 20);
//    [UIView animateWithDuration:0.25 animations:^{
//        application.keyWindow.transform=CGAffineTransformMakeRotation(M_PI * 2);
//    }];

    if (self.rzWebView.bounds.size.width < self.rzWebView.bounds.size.height) {

    [[UIDevice currentDevice] setValue:[NSNumber numberWithInteger:UIInterfaceOrientationLandscapeRight] forKey:@"orientation"];

    } else {

    [[UIDevice currentDevice] setValue:[NSNumber numberWithInteger:UIInterfaceOrientationPortrait] forKey:@"orientation"];

    }

   
}


- (void)trainShareAppWithUrl {
    
    [RZUMengManager showShareViewACtionSheetWith:self callbackBlock:^(UMSocialPlatformType formType) {
        NSLog(@"1111111");
        [[RZUMengManager sharedUMengManger] UMShareActivityWebPageToPlatformType:formType activity_id:@"" activity_name:@"" adctivity_desc:@"" completeHandle:^(BOOL isComplete) {
            NSLog(@"33333");

        }];
    }];
    
}

 
- (void)trainShareAppWithUrl1 {
    
    TrainScanViewController *scanVC = [[TrainScanViewController alloc]init];
    @weakify(self);
    scanVC.trainScanBlock = ^(NSString *result) {
        @strongify(self);
        NSMutableDictionary *dic = [NSMutableDictionary dictionary];
        [dic setObject:result forKey:@"result"];
        
            [self.webViewBridge callHandler:@"ycScanResult" data:dic responseCallback:^(id responseData) {
                   NSLog(@"2调用完JS后的回调：%@",responseData);
               }];
    };
//    UINavigationController *nav = [[UINavigationController alloc]initWithRootViewController:scanVC];
//    nav.navigationItem.title = @"扫一扫";
    [self.navigationController pushViewController:scanVC animated:YES];
   
}

- (void)trainShareAppWithUrl2 {
    
    UMSocialMessageObject *obj = [UMSocialMessageObject messageObject];
    obj.title =@"111";
    obj.text = @"1212";
    [[RZUMengManager sharedUMengManger] UMLoginGetUserInfoAndAuthForPlatform:UMSocialPlatformType_WechatSession completeHandle:^(id result, NSError *error) {
        
    }];
    
//    [[UMSocialManager defaultManager] shareToPlatform:UMSocialPlatformType_QQ messageObject:obj currentViewController:nil completion:^(id result, NSError *error) {
//
//    }];

    
}

- (void)registShareFunction {
    [self.webViewBridge registerHandler:@"loginUser" handler:^(id data, WVJBResponseCallback responseCallback) {
        // data 的类型与 JS中传的参数有关
        NSDictionary *tempDic = data;
   
        NSLog(@"JS 传递给 OC 的参数:%@",[NSString stringWithFormat:@"分享成功:%@",tempDic]);
        
        NSString *url = tempDic[@"url"];
        if (![url hasPrefix:@"http"]) {
            url = [NSString stringWithFormat:@"https://%@",url];
        }
//        [self evSetLoginNavHiddenWithhidden:NO];
        [self evInitZhouIconWithHidden:NO];

        NSString  *params = @"/learn/admin/course/list/index.html#/index?";
        NSString *fullName = tempDic[@"fullName"];
        NSString *userId = tempDic[@"userId"];
        NSString *uuid = tempDic[@"uuid"];
        NSString *userName = tempDic[@"userName"];
        params = [NSString stringWithFormat:@"%@username=%@&uuid=%@&user_id=%@",params,userName,uuid,userId];
        [TrainUserDefault setObject:url forKey:TrainWebHostText];
        [TrainUserDefault setObject:params forKey:TrainWebHomeParam];

        // 将分享的结果返回到JS中
//        NSString *result = [NSString stringWithFormat:@"分享成功:%@,%@,%@",title,content,url];
        responseCallback(@"11");
    }];
    
    [self.webViewBridge registerHandler:@"ycNavBackHidden" handler:^(id data, WVJBResponseCallback responseCallback) {
        NSDictionary *tempDic = data;
        BOOL isHidden = [tempDic[@"ishidden"] boolValue];
        _isShowBack = !isHidden;
        [self evSetNavHiddenWithhidden: isHidden];
    }];
    
    [self.webViewBridge registerHandler:@"ycGotoScan" handler:^(id data, WVJBResponseCallback responseCallback) {
        [self trainShareAppWithUrl1];
    }];
    
    [self.webViewBridge registerHandler:@"setloginNavHidden" handler:^(id data, WVJBResponseCallback responseCallback) {
        [self evSetLoginNavHiddenWithhidden:YES];
      }];
    
  
   [self.webViewBridge registerHandler:@"setloginNavShow" handler:^(id data, WVJBResponseCallback responseCallback) {
       [self evSetLoginNavHiddenWithhidden:NO];
     }];
       
    [self.webViewBridge registerHandler:@"setHomeIconShow" handler:^(id data, WVJBResponseCallback responseCallback) {
          NSDictionary *tempDic = data;
          BOOL isHidden = [tempDic[@"isShow"] boolValue];
        [self evInitZhouIconWithHidden:!isHidden];

      }];
    

}

- (void)evSetNavHiddenWithhidden:(BOOL)isHidden {

    if (isHidden) {
        
         UIBarButtonItem *item = [[UIBarButtonItem alloc]init];
         self.navigationItem.leftBarButtonItem = item ;
        
    }else {
        
        UIBarButtonItem *item = [[UIBarButtonItem alloc]initWithCustomView:self.backButton];
        self.navigationItem.leftBarButtonItem = item ;
       
    }
 
}

- (void)evSetLoginNavHiddenWithhidden:(BOOL)isHidden {
    [self.navigationController setNavigationBarHidden:isHidden animated:YES] ;
    [self updateWebViewTopWithNavShow:!isHidden];
}

/**
 webView  开始加载
 
 */
- (void)webView:(WKWebView *)webView didStartLoad:(WKNavigation  *)navigation  {
 
    NSLog(@"开始");
}

/**
 webView  完成 加载
 
 */
- (void)webView:(WKWebView *)webView didFinishLoadNavigation:(WKNavigation *)navigation {
    NSLog(@"完成");
    NSString *Url = webView.URL.absoluteString ;

    if (![[Url lowercaseString] containsString:@"login"] ) {
        if (_isShowBack) {
            [self evSetNavHiddenWithhidden: NO];
        }else {
            _isShowBack = YES ;
        }
    }
}

/**
 webView  加载失败
 
 */
- (void)webView:(WKWebView *)webView didFailLoadNavigation:(WKNavigation *)navigation withError:(NSError *)error  {
    NSLog(@"失败");

}
/**
 webURL 加载之前 判断是否加载 本次链接
 */
-(BOOL)webView:(WKWebView *)webView shouldStartLoadWithRequest:(NSURLRequest *)request navigationType:(WKNavigationType)navigationType {
              NSString *Url = request.URL.absoluteString ;
    NSLog(@"---url = %@", Url);

    [self.rzWebView evaluateJavaScript:@"document.title" completionHandler:^(id object, NSError * error) {
        if (![object isEqual:@"首页"]) {
            self.navigationItem.title =  object;
        }
    }];
    if ([Url hasPrefix:@"http"]){
        _isLanjie = YES ;
    }else {
        _isLanjie = NO ;
    }
    if ([[Url lowercaseString] containsString:@"login"] ) {
        [self evSetNavHiddenWithhidden: YES];
    }else {

    }
    return YES;
}


///**
// 通过 js  给 webView  传值
//
// @param funStr         webview 的方法   例 :  alert("123");
// @param handler        webview  调用 方法 后的 回调 查看 错误 和返回结果
// */
//- (void)rzPostValueByJS:(NSString *)funStr  completionHandler:(rzPostValueByJsHandler)handler  {
//
//}

/**
 webView 调 OC 的 回调方法
 
 */
- (void)rzUserContentController:(WKUserContentController *)userContentController didReceiveScriptMessage:(WKScriptMessage *)message  {
    
    NSLog(@"%@===== %@", [self class], message.body);
     
     if ([message.name isEqual: kWKWebViewJSName ]) {
         
         NSDictionary  *dic = message.body;
         NSString  *key = dic[@"mothed"];
         id  para = dic[@"params"];
         if ([ key isEqualToString:@"getLoginHost"]) {
             
         }else if ([ key isEqualToString:@"gotoShareUrl"]){
             
         }else if ([ key isEqualToString:@"gotoScan"]){
             
         }else if ([ key isEqualToString:@"getLoginHost"]){
             
         }
     }
    
    
}



/*
#pragma mark - Navigation

// In a storyboard-based application, you will often want to do a little preparation before navigation
- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender {
    // Get the new view controller using [segue destinationViewController].
    // Pass the selected object to the new view controller.
}
*/

@end
