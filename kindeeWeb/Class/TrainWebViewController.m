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

@interface TrainWebViewController ()
{
 
    BOOL   _isLanjie ;  // 判断是新旧页面  根据 url
    BOOL   _isShowBack ;
}

@property (nonatomic, strong) UIButton   *backButton ;
@end

@implementation TrainWebViewController

- (void)viewWillAppear:(BOOL)animated {
    [super viewWillAppear:animated];
//    self.navigationController.navigationBar.hidden =YES;
}

- (void)viewDidLoad {
    [super viewDidLoad];
    
    NSString  *webUrl = [TrainUserDefault objectForKey:TrainWebHostText];
    NSString  *param = [TrainUserDefault objectForKey:TrainWebHomeParam];
    _isShowBack = YES;
    if (TrainStringIsEmpty(webUrl) || webUrl.length <= 8) {
//        self.webUrl = @"https://tequ.newvane.com.cn";
        self.webUrl = @"https://demo.elearnplus.com/learn/admin/course/list/login.html#/";
//        https://demo.elearnplus.com/learn//admin/course/list/index.html#/
    }else {
     
        webUrl = [NSString stringWithFormat:@"%@%@",webUrl,param];
        self.webUrl = webUrl ;
    }
//    UIButton  *button  = [UIButton buttonWithType:UIButtonTypeCustom];
//    button.backgroundColor = [UIColor redColor];
//    [button setTitle:@"share" forState:UIControlStateNormal];
//    button.frame = CGRectMake(0, 110, 100, 50);
//    [button addTarget:self action:@selector(trainShareAppWithUrl) forControlEvents:UIControlEventTouchUpInside];
//    [self.view addSubview:button];
//
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
    
    [self evInitNavgation];
    
    [self loadWebView:self.webUrl];
    [self registShareFunction];
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
        make.edges.equalTo(self.view).insets(UIEdgeInsetsMake(TrainNavHeight, 0, 0, 0));
//        if (@available(iOS 11.0, *)) {
//            make.bottom.equalTo(self.view.mas_safeAreaLayoutGuideBottom);
//        } else {
//            // Fallback on earlier versions
//        }
    }];
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
    if (_isShowBack) {
        [self evSetNavHiddenWithhidden: NO];
    }else {
        _isShowBack = YES ;
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
                self.navigationItem.title =  object;
        }];
    if ([Url hasPrefix:@"http"]){
        _isLanjie = YES ;
    }else {
        _isLanjie = NO ;
    }
    if ([Url containsString:@"login"]) {
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
