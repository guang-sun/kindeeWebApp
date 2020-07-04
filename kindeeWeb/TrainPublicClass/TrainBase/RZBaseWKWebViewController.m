//
//  RZBaseWKWebViewController.m
//  YGProject
//
//  Created by admin on 2017/10/30.
//  Copyright © 2017年 YG. All rights reserved.
//

#import "RZBaseWKWebViewController.h"
#import "RZWeakScriptMessageDelegate.h"

@interface RZBaseWKWebViewController ()

@end

@implementation RZBaseWKWebViewController
//@synthesize scalesPageToFit = _scalesPageToFit;

- (void)viewWillAppear:(BOOL)animated
{
    [super viewWillAppear:animated];
    
    dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(1.0f * NSEC_PER_SEC)), dispatch_get_main_queue(), ^{
        
        //        [self addAllScriptMsgHandle];
        
    });
}


-(void)viewWillDisappear:(BOOL)animated
{
    [super viewWillDisappear:animated];
   
    //    [self removeAllScriptMsgHandle];
    //    [RZProgressHUD hide];
    
    
}
- (void)viewDidLoad {
    [super viewDidLoad];
    
    self.view.backgroundColor  = [UIColor whiteColor];
    
//    // 解决 goBack 后 页面会无故上移 64 的问题
    if (@available(iOS 11.0, *)) {

        UIScrollView  *webScroll  = self.rzWebView.scrollView ;
        webScroll.contentInsetAdjustmentBehavior  = UIScrollViewContentInsetAdjustmentNever;
    } else {
        self.automaticallyAdjustsScrollViewInsets = NO;
    }
    [self addAllScriptMsgHandle];
    self.rzWebView.scrollView.bounces = NO ;
}


- (void)changeNavLeftButton {
    
//    if ([self.rzWebView canGoBack]) {
//
//        UIBarButtonItem   *backItem= [UIBarButtonItem initNavBackItem:self action:@selector(rzwebViewGoBack)];
//        UIBarButtonItem  *closeItem = [UIBarButtonItem initItemWithImage:kNavCloseImage highImage:kNavCloseImage target:self action:@selector(rzwebVIewPopView)];
//
//        self.navigationItem.leftBarButtonItems = @[backItem,closeItem]; //[UIBarButtonItem offsetItemWithItems:@[backItem]];
//    }else {
//
//        UIBarButtonItem   *backItem= [UIBarButtonItem initNavBackItem:self action:@selector(rzwebVIewPopView)];
//        self.navigationItem.leftBarButtonItem = backItem ;
//
//    }
}

- (void)evInitNavgation {
 
    self.navigationItem.title = self.navTitle ;
}

- (void)rzwebViewGoBack {
    
    if ([self.rzWebView canGoBack]) {
        
        [self.rzWebView goBack];
    }else {
        
        [self.navigationController popViewControllerAnimated:YES];
    }
}

- (void)rzwebVIewPopView {
    
    [self.navigationController popViewControllerAnimated:YES];
}

-(void)evAddSubviews {
    
    [self.view addSubview:self.rzWebView];
    [self rzwebviewLayout];
}

- (void)rzwebviewLayout {
    
    [self.rzWebView mas_remakeConstraints:^(MASConstraintMaker *make) {
      
        make.edges.equalTo(self.view).insets(UIEdgeInsetsMake(0, 0, 0, 0));
//        if (@available(iOS 11.0, *)) {
//            make.bottom.equalTo(self.view.mas_safeAreaLayoutGuideBottom);
//        } else {
//            // Fallback on earlier versions
//        }
    }];
}


- (void)loadWebView:(NSString *)url  {
    
    NSURLRequest  *req = [NSURLRequest requestWithURL:[NSURL URLWithString:url] ];
    
    [self.rzWebView loadRequest:req];
    
}



- (void)observeValueForKeyPath:(NSString *)keyPath ofObject:(id)object change:(NSDictionary<NSKeyValueChangeKey,id> *)change context:(void *)context {
    
    if ([keyPath isEqualToString: @"estimatedProgress"]) {
        CGFloat  newProgress = [[change objectForKey:NSKeyValueChangeNewKey] floatValue];
        CGFloat  oldProgress = [[change objectForKey:NSKeyValueChangeOldKey] floatValue];
        
        if (newProgress > oldProgress){
            
        }
    }
    
    
}

#pragma  mark - ============== 给js传值 ============

/**
 通过 js  给 webView  传值
 
 @param funStr         webview 的方法   例 :  alert("123");
 @param handler        webview  调用 方法 后的 回调 查看 错误 和返回结果
 */
- (void)rzPostValueByJS:(NSString *)funStr  completionHandler:(rzPostValueByJsHandler)handler  {
    
    [self.rzWebView evaluateJavaScript:funStr completionHandler:^(id _Nullable obj , NSError * _Nullable error) {
        
        if (handler) {
            handler(obj, error);
        }
        NSLog(@"给 web 传值%@ === 结果 %@  -----   错误%@ ",funStr ,obj , error);
        
    }];
    
}



#pragma  mark - =========== WKWebView WKNavigationDelegate ==============

 //在发送请求之前，决定是否跳转

- (void)webView:(WKWebView *)webView decidePolicyForNavigationAction:(WKNavigationAction *)navigationAction decisionHandler:(void (^)(WKNavigationActionPolicy))decisionHandler {

    NSLog(@"start==%@",navigationAction.request.URL.absoluteString);
    BOOL resultBool = [self webView:webView shouldStartLoadWithRequest:navigationAction.request navigationType:navigationAction.navigationType];

    if (resultBool ) {
        if (navigationAction.targetFrame == nil) {
            [webView loadRequest:navigationAction.request];
        }
        decisionHandler(WKNavigationActionPolicyAllow);
    }
    else {
        decisionHandler(WKNavigationActionPolicyCancel);
    }
}

-(BOOL)webView:(WKWebView *)webView shouldStartLoadWithRequest:(NSURLRequest *)request navigationType:(WKNavigationType)navigationType {
    
    return YES;
}
// 在收到响应后，决定是否跳转
- (void)webView:(WKWebView *)webView decidePolicyForNavigationResponse:(WKNavigationResponse *)navigationResponse decisionHandler:(void (^)(WKNavigationResponsePolicy))decisionHandler{
    
    //允许跳转
    decisionHandler(WKNavigationResponsePolicyAllow);
    //不允许跳转
    //    decisionHandler(WKNavigationResponsePolicyCancel);
}

-(void)webView:(WKWebView *)webView didStartProvisionalNavigation:(WKNavigation *)navigation {
    
    
    NSLog(@" -[%@]--   开始加载 ",[self class] );
    
    [self webView:webView didStartLoad:navigation];
}

-(void)webView:(WKWebView *)webView didFinishNavigation:(WKNavigation *)navigation {
    
    NSLog(@" -[%@]--   加载完成 ",[self class] );
    
//    @DGWeakObj(self);
    [self.rzWebView evaluateJavaScript:@"document.title" completionHandler:^(id object, NSError * error) {

//        if (DGStringIsEmpty(weakself.navTitle)) {
            self.navigationItem.title =  object;
//        }
    }];
    [self webView:webView didFinishLoadNavigation:navigation];
    
    
}

- (void)webView:(WKWebView *)webView didFailNavigation:(WKNavigation *)navigation withError:(NSError *)error {
    
//    [RZProgressHUD hide];
    if ([error code] == NSURLErrorCancelled) {
        
        return;
        
    }else {
        
        NSLog(@" -[%@]--  失败  error== %@  ",[self class] , error );
//        [RZProgressHUD showHUDWithError:error.description];
        
    }
    [self webView:webView didFailLoadNavigation:navigation withError:error];
}

- (void)webView:(WKWebView *)webView didStartLoad:(WKNavigation *)navigation {
    
}

- (void)webView:(WKWebView *)webView didFinishLoadNavigation:(WKNavigation *)navigation {
    
}

- (void)webView:(WKWebView *)webView didFailLoadNavigation:(WKNavigation *)navigation withError:(NSError *)error {
    
}


#pragma  mark - =========== WKWebView UIDelegate ==============

- (void)webView:(WKWebView *)webView runJavaScriptAlertPanelWithMessage:(NSString *)message initiatedByFrame:(WKFrameInfo *)frame completionHandler:(void (^)(void))completionHandler {
    
    UIAlertController  *alertVC = [UIAlertController alertControllerWithTitle:@"提示" message:message preferredStyle:UIAlertControllerStyleAlert];
    
    
    [alertVC  addAction: [UIAlertAction actionWithTitle:@"确定" style:UIAlertActionStyleDefault handler:^(UIAlertAction * _Nonnull action) {
        
        completionHandler();
        
    }]];
    
    [self presentViewController:alertVC animated:YES completion:^{
        
    }];
    
    
}

- (void)webView:(WKWebView *)webView runJavaScriptConfirmPanelWithMessage:(NSString *)message initiatedByFrame:(WKFrameInfo *)frame completionHandler:(void (^)(BOOL))completionHandler {
    
    
}

- (void)webView:(WKWebView *)webView runJavaScriptTextInputPanelWithPrompt:(NSString *)prompt defaultText:(NSString *)defaultText initiatedByFrame:(WKFrameInfo *)frame completionHandler:(void (^)(NSString * _Nullable))completionHandler {
    
    UIAlertController  *alertVC = [UIAlertController alertControllerWithTitle:@"提示" message:prompt preferredStyle:UIAlertControllerStyleAlert];
    
    [alertVC addTextFieldWithConfigurationHandler:^(UITextField * _Nonnull textField) {
        
        textField.placeholder = defaultText;
        
    }];
    
    [alertVC  addAction: [UIAlertAction actionWithTitle:@"确定" style:UIAlertActionStyleDefault handler:^(UIAlertAction * _Nonnull action) {
        
        UITextField   *textfield = [alertVC.textFields firstObject];
        
        completionHandler(textfield.text);
        
    }]];
    
    
    [alertVC  addAction: [UIAlertAction actionWithTitle:@"取消" style:UIAlertActionStyleCancel handler:^(UIAlertAction * _Nonnull action) {
        
    }]];
    
    [self presentViewController:alertVC animated:YES completion:^{
        
    }];
    
}


- (void)registerNativeFunctions {
    [self registShareFunction];
    
//    [self registLocationFunction];
//
//    [self registPayFunction];
}

- (void)registShareFunction {
    [self.webViewBridge registerHandler:@"shareClick" handler:^(id data, WVJBResponseCallback responseCallback) {
        // data 的类型与 JS中传的参数有关
        NSDictionary *tempDic = data;
        // 在这里执行分享的操作
        NSString *title = [tempDic objectForKey:@"title"];
        NSString *content = [tempDic objectForKey:@"content"];
        NSString *url = [tempDic objectForKey:@"url"];
        NSLog(@"JS 传递给 OC 的参数:%@",[NSString stringWithFormat:@"分享成功:%@,%@,%@",title,content,url]);
        
        // 将分享的结果返回到JS中
        NSString *result = [NSString stringWithFormat:@"分享成功:%@,%@,%@",title,content,url];
        responseCallback(result);
    }];
}

//- (void)webView:(WKWebView *)webView
//decidePolicyForNavigationAction:(WKNavigationAction *)navigationAction
//decisionHandler:(void (^)(WKNavigationActionPolicy))decisionHandler {
//    if (webView != self.rzWebView) { return; }
//    NSURL *url = navigationAction.request.URL;
//    __strong typeof(_webViewDelegate) strongDelegate = _webViewDelegate;
//
//    if ([_base isCorrectProcotocolScheme:url]) {
//        // 在这里拦截wvjbscheme://__BRIDGE_LOADED__
//        if ([_base isBridgeLoadedURL:url]) {
//            // 这里会注入js
//            [_base injectJavascriptFile];
//        } else if ([_base isQueueMessageURL:url]) {
//            [self WKFlushMessageQueue];
//        } else {
//            [_base logUnkownMessage:url];
//        }
//        decisionHandler(WKNavigationActionPolicyCancel);
//    }
//
//    if (strongDelegate && [strongDelegate respondsToSelector:@selector(webView:decidePolicyForNavigationAction:decisionHandler:)]) {
//        [_webViewDelegate webView:webView decidePolicyForNavigationAction:navigationAction decisionHandler:decisionHandler];
//    } else {
//        decisionHandler(WKNavigationActionPolicyAllow);
//    }
//
//}


//- (void)injectJavascriptFile {
//    //读取js 内容
//    NSString *js = WebViewJavascriptBridge_js();
//    // 执行Native 的API，实现将js 注入 到HMTL中。
//    [self _evaluateJavascript:js];
//    if (self.startupMessageQueue) {
//        NSArray* queue = self.startupMessageQueue;
//        self.startupMessageQueue = nil;
//        for (id queuedMessage in queue) {
//            [self _dispatchMessage:queuedMessage];
//        }
//    }
//}

////    // 如果不需要参数，不需要回调，使用这个
////    [_webViewBridge callHandler:@"testJSFunction"];
////    // 如果需要参数，不需要回调，使用这个
////    [_webViewBridge callHandler:@"testJSFunction" data:@"一个字符串"];
//    // 如果既需要参数，又需要回调，使用这个
//    [_webViewBridge callHandler:@"testJSFunction" data:@"一个字符串" responseCallback:^(id responseData) {
//        NSLog(@"调用完JS后的回调：%@",responseData);
//    }];

#pragma mark - ============== WKScriptMessageHandler ============

- (void)userContentController:(WKUserContentController *)userContentController didReceiveScriptMessage:(WKScriptMessage *)message {
    
    NSLog(@"web VIew  方法  ----   %@",message);
    [self rzUserContentController:userContentController didReceiveScriptMessage:message];
    
}

- (void)rzUserContentController:(WKUserContentController *)userContentController didReceiveScriptMessage:(WKScriptMessage *)message {
    
    
    
    
}



- (void)deleteWebCache {
    
    //    return ;
    if ([[UIDevice currentDevice].systemVersion floatValue] >= 9.0) {
        
        NSSet *websiteDataTypes
        
        = [NSSet setWithArray:@[
                                
                                WKWebsiteDataTypeDiskCache,
                                
                                WKWebsiteDataTypeOfflineWebApplicationCache,
                                
                                WKWebsiteDataTypeMemoryCache,
                                //
                                //                                WKWebsiteDataTypeLocalStorage,
                                //
                                //                                WKWebsiteDataTypeCookies,
                                //
                                WKWebsiteDataTypeSessionStorage,
                                //
                                //                                WKWebsiteDataTypeIndexedDBDatabases,
                                //
                                //                                WKWebsiteDataTypeWebSQLDatabases
                                
                                ]];
        
        NSDate *dateFrom = [NSDate dateWithTimeIntervalSince1970:0];
        
        [[WKWebsiteDataStore defaultDataStore] removeDataOfTypes:websiteDataTypes modifiedSince:dateFrom completionHandler:^{
            
        }];
    } else {
        
        NSString *libraryPath = [NSSearchPathForDirectoriesInDomains(NSLibraryDirectory, NSUserDomainMask, YES) objectAtIndex:0];
        
        NSString *cookiesFolderPath = [libraryPath stringByAppendingString:@"/Cookies"];
        
        NSError *errors;
        
        [[NSFileManager defaultManager] removeItemAtPath:cookiesFolderPath error:&errors];
        
        
        
    }
    
}




-(void)dealloc{
    
    if (_showProgress) {
        
        [self.rzWebView removeObserver:self forKeyPath:@"estimatedProgress"];
    }
    
    
    
    NSLog(@"----dealloc---%@",[self class]);
    
}

// WKWebView  的js 回调 的
-(void)addAllScriptMsgHandle{
    
    if (self.rzWebView) {
        WKUserContentController *controller = self.rzWebView.configuration.userContentController;
        [controller addScriptMessageHandler:[[RZWeakScriptMessageDelegate alloc]initWithDelegate:self] name:kWKWebViewJSName];
    }
}

-(void)removeAllScriptMsgHandle{
    
    if (self.rzWebView) {
        WKUserContentController *controller = self.rzWebView.configuration.userContentController;
        [controller removeScriptMessageHandlerForName:kWKWebViewJSName];
    }
}

#pragma mark - ============== setter/ getter ============

- (void)setNavTitle:(NSString *)navTitle {
    
    _navTitle = navTitle;
//    if ( !DGStringIsEmpty(navTitle)) {
//        self.navigationItem.title = navTitle ;
//    }
}

- (void)setShowProgress:(BOOL)showProgress {
    
    _showProgress = showProgress;
    if (showProgress) {
        
        
//        [self.rzWebView addObserver:self forKeyPath:@"estimatedProgress" options:NSKeyValueObservingOptionOld|NSKeyValueObservingOptionNew context:nil];
    }else {
        
       
    }
}

//
//- (void)setScalesPageToFit:(BOOL)scalesPageToFit
//{
//
//    if (_scalesPageToFit == scalesPageToFit) {
//        return;
//    }
//
//    WKWebView* webView = self.rzWebView;
//
//    NSString* jScript =
//    @"var head = document.getElementsByTagName('head')[0];\
//    var hasViewPort = 0;\
//    var metas = head.getElementsByTagName('meta');\
//    for (var i = metas.length; i>=0 ; i--) {\
//    var m = metas[i];\
//    if (m.name == 'viewport') {\
//    hasViewPort = 1;\
//    break;\
//    }\
//    }; \
//    if(hasViewPort == 0) { \
//    var meta = document.createElement('meta'); \
//    meta.name = 'viewport'; \
//    meta.content = 'width=device-width, initial-scale=1.0, maximum-scale=1.0, user-scalable=no'; \
//    head.appendChild(meta);\
//    }";
//
//    WKUserContentController *userContentController = webView.configuration.userContentController;
//    NSMutableArray<WKUserScript *> *array = [userContentController.userScripts mutableCopy];
//    WKUserScript* fitWKUScript = nil;
//    for (WKUserScript* wkUScript in array) {
//        if ([wkUScript.source isEqual:jScript]) {
//            fitWKUScript = wkUScript;
//            break;
//        }
//    }
//    if (scalesPageToFit) {
//        if (!fitWKUScript) {
//            fitWKUScript = [[NSClassFromString(@"WKUserScript") alloc] initWithSource:jScript injectionTime:WKUserScriptInjectionTimeAtDocumentEnd forMainFrameOnly:NO];
//            [userContentController addUserScript:fitWKUScript];
//        }
//    }
//    else {
//        if (fitWKUScript) {
//            [array removeObject:fitWKUScript];
//        }
//        ///没法修改数组 只能移除全部 再重新添加
//        [userContentController removeAllUserScripts];
//        for (WKUserScript* wkUScript in array) {
//            [userContentController addUserScript:wkUScript];
//        }
//    }
//    _scalesPageToFit = scalesPageToFit;
//}
//- (BOOL)scalesPageToFit
//{
//    return _scalesPageToFit;
//}

-(WKWebView *)rzWebView{
    if (! _rzWebView) {
        
        //创建一个WKWebView的配置对象
        WKWebViewConfiguration *configur = [[WKWebViewConfiguration alloc] init];
        
        //设置configur对象的preferences属性的信息
        WKPreferences *preferences = [[WKPreferences alloc] init];
//        preferences.javaScriptCanOpenWindowsAutomatically = YES ;
//        preferences.minimumFontSize = 30.0;
        //是否允许与js进行交互，默认是YES的，如果设置为NO，js的代码就不起作用了
              preferences.javaScriptEnabled = YES;
          
        configur.preferences = preferences;
        configur.allowsInlineMediaPlayback = YES;
      
//        WKUserContentController *userContentController = [[WKUserContentController alloc]init];
//        [userContentController addScriptMessageHandler:[[RZWeakScriptMessageDelegate alloc]initWithDelegate:self] name:kWKWebViewJSName];
        WKWebView *wkWebView = [[WKWebView alloc] initWithFrame:CGRectZero configuration:configur];
        
        wkWebView.allowsBackForwardNavigationGestures = YES;  // 允许左滑返回上个页面
        //重点(当然需要遵守协议，不然会有警告)（当然遵守了这个你就可以侧滑返回上个页面了）
        wkWebView.navigationDelegate = self;

        //这句代码是让竖直方向的滚动条显示在正确的位置
        wkWebView.scrollView.scrollIndicatorInsets = wkWebView.scrollView.contentInset;
        wkWebView.scrollView.showsVerticalScrollIndicator = NO;
        wkWebView.scrollView.showsHorizontalScrollIndicator = NO;
        wkWebView.UIDelegate = self;
        wkWebView.backgroundColor = [UIColor whiteColor] ;
        
        _rzWebView = wkWebView;
    }
    return _rzWebView;
}

-  (WKWebViewJavascriptBridge *)webViewBridge {
 
    if (!_webViewBridge) {
        WKWebViewJavascriptBridge *bridge = [WKWebViewJavascriptBridge bridgeForWebView:self.rzWebView];
        [bridge setWebViewDelegate:self];
        
        _webViewBridge = bridge ;
    }
    return _webViewBridge ;
}



- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
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
