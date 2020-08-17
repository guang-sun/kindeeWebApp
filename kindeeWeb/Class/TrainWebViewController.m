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


#import "TrainCustomCarmer.h"


@interface TrainWebViewController ()
{
 
    BOOL   _isLanjie ;  // 判断是新旧页面  根据 url
    __block BOOL   _isShowBack ;
}

@property (nonatomic, strong) UIButton   *backButton ;
@property (nonatomic, strong) UIView   *iconButton ;

@property (nonatomic, strong) UIView   *carameView ;
@property (nonatomic, strong) TrainCustomCarmer   *carmer ;
@property (nonatomic, assign) BOOL    isNavHidden ;

@end

@implementation TrainWebViewController

- (void)viewWillAppear:(BOOL)animated {
    [super viewWillAppear:animated];
        [self evSetLoginNavHiddenWithhidden:self.isNavHidden];
//    self.navigationController.navigationBar.hidden =YES;
    
    UIScreen * sc = [UIScreen mainScreen];
    if (@available(iOS 11.0,*)) {
        if (sc.isCaptured) {
            NSLog(@"正在录制-----%d",sc.isCaptured);
            [self handleSceenShot];
            
        }
    }else {
       //ios 11之前处理 未知
    }
    
    
}

- (void)viewDidLoad {
    [super viewDidLoad];
    [self evSetLoginNavHiddenWithhidden:YES];
    self.isNavHidden = YES ;

    [self evInitNavgation];
    [self evInitIconButton];
    
    NSString  *webUrl = [TrainUserDefault objectForKey:TrainWebHostText];
    NSString  *param = [TrainUserDefault objectForKey:TrainWebHomeParam];
    _isShowBack = NO;
    if (TrainStringIsEmpty(webUrl) || webUrl.length <= 8) {
        self.webUrl = @"https://learning.newvane.com.cn";
////        self.webUrl = @"https://tequ.newvane.com.cn";
//        self.webUrl = @"https://szcsot.newvane.com.cn";
//        self.webUrl = @"https://szshigang.newvane.com.cn" ;
        
    }else {
     
        webUrl = [NSString stringWithFormat:@"%@%@",webUrl,param];
        self.webUrl = webUrl ;
    }
    [self rzAddCarmarView];
    [self loadWebView:self.webUrl];
    [self registShareFunction];
    [self RegeistNoticeCenter];
    
    [self rtrainAddNoti];
    // Do any additional setup after loading the view.
}


- (void)trainCheckyueyu {
    
    if ([TrainControllerUtil isJailBroken]) {
     
        if (![TrainControllerUtil trainCompareFileHash]) {
            UIAlertController * alertVc =[UIAlertController alertControllerWithTitle:@"信息提示" message:@"抱歉, 文件不完整,请下载最新版本" preferredStyle:UIAlertControllerStyleAlert];
            UIAlertAction * knowAction =[UIAlertAction actionWithTitle:@"知道了" style:UIAlertActionStyleDefault handler:^(UIAlertAction * _Nonnull action) {
                [self trainCheckyueyu];
            }];
            [alertVc addAction:knowAction];
            [self presentViewController:alertVc animated:YES completion:nil];
        }else {
            
            UIAlertController * alertVc =[UIAlertController alertControllerWithTitle:@"信息提示" message:@"抱歉, 您的手机已越狱" preferredStyle:UIAlertControllerStyleAlert];
              UIAlertAction * knowAction =[UIAlertAction actionWithTitle:@"知道了" style:UIAlertActionStyleDefault handler:nil];
              [alertVc addAction:knowAction];
              [self presentViewController:alertVc animated:YES completion:nil];
        }
    }
}


- (void)rtrainAddNoti {
    
    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(handleSceenShot) name:UIApplicationUserDidTakeScreenshotNotification object:nil];
   //ios11之后才可以录屏
   if (@available(iOS 11.0,*)) {
     //检测设备
       [[NSNotificationCenter defaultCenter]addObserver:self selector:@selector(handleSceenShot) name:UIScreenCapturedDidChangeNotification  object:nil];
   }
    
}

//当用户截屏了 怎么办 目前来说 只能进行提示。
-(void)handleSceenShot {
    UIAlertController * alertVc =[UIAlertController alertControllerWithTitle:@"信息提示" message:@"为保证数据安全,请不要截屏或录屏!" preferredStyle:UIAlertControllerStyleAlert];
    UIAlertAction * knowAction =[UIAlertAction actionWithTitle:@"知道了" style:UIAlertActionStyleDefault handler:nil];
    [alertVc addAction:knowAction];
    [self presentViewController:alertVc animated:YES completion:nil];
}

-(void)dealloc {
   
    [[NSNotificationCenter defaultCenter] removeObserver:self name:UIApplicationUserDidTakeScreenshotNotification object:nil];
    if (@available(iOS 11.0, *)) {
          [[NSNotificationCenter defaultCenter] removeObserver:self name:UIScreenCapturedDidChangeNotification object:nil];
      } else {
          // Fallback on earlier versions
      }
}



- (void)evInitNavgation {
 
    UIButton  *button = [UIButton buttonWithType:UIButtonTypeCustom];
    [button setImage:[UIImage imageNamed:@"nav_button_fanhui_2_default"] forState:UIControlStateNormal];
    button.frame = CGRectMake(0, 0, 50, 40);
    button.contentHorizontalAlignment = UIControlContentHorizontalAlignmentLeft ;
    [button addTarget:self action:@selector(evBackView) forControlEvents:UIControlEventTouchUpInside];
    self.backButton = button ;
    
}

- (void)rzAddCarmarView {
    
    [self.view addSubview:self.carameView];
    [self.carameView mas_makeConstraints:^(MASConstraintMaker *make) {
        make.right.equalTo(self.view);
        make.centerY.equalTo(self.view);
        make.width.height.mas_equalTo(100);
    }];
    self.carameView.layer.cornerRadius  = 50 ;
    self.carameView.layer.masksToBounds = YES ;
    
    [self.carameView layoutIfNeeded];
    
    self.carmer = [[TrainCustomCarmer alloc]initWithParentView:self.carameView];
 
    self.carameView.hidden = YES ;
//    [self.carmer startCapRuning];

//    dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(5 * NSEC_PER_SEC)), dispatch_get_main_queue(), ^{
//        [self addbutake];
//    });
   
}

//- (void)touchesEnded:(NSSet<UITouch *> *)touches withEvent:(UIEvent *)event {
//    [self addbutake];
//}
-(void)addbutake {

    [self.carmer takePhotoWithImageBlock:^(UIImage *originImage) {

        NSData *imageData = UIImageJPEGRepresentation(originImage, 1);
        NSString *string = imageData.base64EncodedString ;
    }];

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
    
    UIBarButtonItem *item = [[UIBarButtonItem alloc]init];
      self.navigationItem.leftBarButtonItem = item ;
            
//      if (hidden) {
//
//           UIBarButtonItem *item = [[UIBarButtonItem alloc]init];
//           self.navigationItem.leftBarButtonItem = item ;
//
//      }else {
//          self.navigationItem.title = @"";
//          UIBarButtonItem *item = [[UIBarButtonItem alloc]initWithCustomView:self.iconButton];
//          self.navigationItem.leftBarButtonItem = item ;
//
//      }
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

 
- (void)trainShareAppWithUrl1:(void (^)(NSString *str))complete {
    
    TrainScanViewController *scanVC = [[TrainScanViewController alloc]init];
    @weakify(self);
    scanVC.trainScanBlock = ^(NSString *result) {
        @strongify(self);
//        NSMutableDictionary *dic = [NSMutableDictionary dictionary];
//        [dic setObject:result forKey:@"result"];
        complete(result);
//
//            [self.webViewBridge callHandler:@"ycScanResult" data:dic responseCallback:^(id responseData) {
//                   NSLog(@"2调用完JS后的回调：%@",responseData);
//               }];
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
    
    @weakify(self);
    [self.webViewBridge registerHandler:@"loginUser" handler:^(id data, WVJBResponseCallback responseCallback) {
        // data 的类型与 JS中传的参数有关
        NSDictionary *tempDic = data;
   
        NSLog(@"JS 传递给 OC 的参数:%@",[NSString stringWithFormat:@"分享成功:%@",tempDic]);
        
        NSString *url = tempDic[@"url"];
        if (![url hasPrefix:@"http"]) {
            url = [NSString stringWithFormat:@"https://%@",url];
        }
//        [self evSetLoginNavHiddenWithhidden:NO];
        [weak_self evInitZhouIconWithHidden:NO];

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
        [weak_self evSetNavHiddenWithhidden: isHidden];
    }];
    
    [self.webViewBridge registerHandler:@"ycGotoScan" handler:^(id data, WVJBResponseCallback responseCallback) {
        [self trainShareAppWithUrl1:^(NSString *result) {
              NSMutableDictionary *dic = [NSMutableDictionary dictionary];
             [dic setObject:result forKey:@"result"];
             responseCallback(dic) ;
        }];
    }];
    
    [self.webViewBridge registerHandler:@"setloginNavHidden" handler:^(id data, WVJBResponseCallback responseCallback) {
        [weak_self evSetLoginNavHiddenWithhidden:YES];
      }];
    
  
   [self.webViewBridge registerHandler:@"setloginNavShow" handler:^(id data, WVJBResponseCallback responseCallback) {
       [weak_self evSetLoginNavHiddenWithhidden:NO];
     }];
       
    [self.webViewBridge registerHandler:@"setHomeIconShow" handler:^(id data, WVJBResponseCallback responseCallback) {
          NSDictionary *tempDic = data;
          BOOL isHidden = [tempDic[@"isShow"] boolValue];
        [weak_self evInitZhouIconWithHidden:!isHidden];

      }];
    
    [self.webViewBridge registerHandler:@"setFaceViewShow" handler:^(id data, WVJBResponseCallback responseCallback) {
       
        NSDictionary *tempDic = data;
        BOOL isHidden = ![tempDic[@"isShow"] boolValue];
//        self.carameView.hidden = isHidden ;
        if (isHidden) {
            [weak_self.carmer stopCapRuning];
        }else {
            [weak_self.carmer startCapRuning];
        }
        
      }];
    
//    @weakify(self);
    [self.webViewBridge registerHandler:@"setFaceTakePhoto" handler:^(id data, WVJBResponseCallback responseCallback) {
        [weak_self.carmer takePhotoWithImageBlock:^(UIImage *originImage) {
            
            NSData *imageData = UIImageJPEGRepresentation(originImage, 1);
            NSString *string = imageData.base64EncodedString ;
            responseCallback(string);
            
        }];
    }];
    
    [self.webViewBridge registerHandler:@"setHomeWord" handler:^(id data, WVJBResponseCallback responseCallback) {
       NSDictionary *tempDic = data;
       NSInteger index = [tempDic[@"isShow"] integerValue];
       if (index > 0) {
           
       }else {
           
       }
    }];
    
    

    
}
//- (void)trainTakePhotoBackToWeb:(UIImage *)image {
//
//
//    [self.webViewBridge callHandler:"setImagePhoto" data:string responseCallback:^(id responseData) {
//        //        NSLog(@"testJavascriptHandler responded: %@", response);
//
//
//    }];
//
//
//}

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
    
    self.isNavHidden = isHidden ;
    [self.navigationController setNavigationBarHidden:isHidden animated:YES] ;
//    [self updateWebViewTopWithNavShow:!isHidden];
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
//        if (![object isEqual:@"首页"]) {
            self.navigationItem.title =  object;
//        }
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


- (UIView *)carameView {
    if (!_carameView) {
        UIView *viw = [[UIView alloc]init];
        viw.backgroundColor = [UIColor whiteColor];
        
        _carameView = viw ;
    }
    return _carameView;
}

//- (TrainCustomCarmer *)carmer {
//
//    if (_carmer) {
//        TrainCustomCarmer *car = [[TrainCustomCarmer alloc]initWithParentView:self.carameView];
////        
//        _carmer = car;
//    }
//    return _carmer;
//}



/*
#pragma mark - Navigation

// In a storyboard-based application, you will often want to do a little preparation before navigation
- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender {
    // Get the new view controller using [segue destinationViewController].
    // Pass the selected object to the new view controller.
}
*/

@end
