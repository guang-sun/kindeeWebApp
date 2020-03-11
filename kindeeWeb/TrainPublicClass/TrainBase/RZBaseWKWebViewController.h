//
//  RZBaseWKWebViewController.h
//  YGProject
//
//  Created by admin on 2017/10/30.
//  Copyright © 2017年 YG. All rights reserved.
//

#import "RZBaseViewController.h"
#import <JavaScriptCore/JavaScriptCore.h>
#import <WebKit/WebKit.h>
#import <WKWebViewJavascriptBridge.h>

static NSString* const kWKWebViewJSName = @"kindeeWebjsiOS";

typedef  void  (^rzPostValueByJsHandler)(id  obj , NSError   *error) ;

@interface RZBaseWKWebViewController : RZBaseViewController <WKNavigationDelegate,WKUIDelegate,WKScriptMessageHandler>

@property (nonatomic, copy)  NSString               *webUrl;

@property (nonatomic, strong) NSString              *navTitle;

@property (nonatomic, strong) WKWebView             *rzWebView;

//@property (nonatomic ,assign) BOOL                  scalesPageToFit ;
/** bridge */
@property(nonatomic, strong)WKWebViewJavascriptBridge *webViewBridge;

@property (nonatomic, assign,getter = isshowProgress) BOOL          showProgress;


- (void)loadWebView:(NSString *)url ;

- (void)changeNavLeftButton ;

- (void)deleteWebCache ;

// WKWebView  的js 回调 的delegate 
-(void)addAllScriptMsgHandle ;

-(void)removeAllScriptMsgHandle ;

/**
 webView  开始加载
 
 */
- (void)webView:(WKWebView *)webView didStartLoad:(WKNavigation  *)navigation ;

/**
 webView  完成 加载
 
 */
- (void)webView:(WKWebView *)webView didFinishLoadNavigation:(WKNavigation *)navigation;

/**
 webView  加载失败
 
 */
- (void)webView:(WKWebView *)webView didFailLoadNavigation:(WKNavigation *)navigation withError:(NSError *)error ;
/**
 webURL 加载之前 判断是否加载 本次链接
 */
-(BOOL)webView:(WKWebView *)webView shouldStartLoadWithRequest:(NSURLRequest *)request navigationType:(WKNavigationType)navigationType ;


/**
 通过 js  给 webView  传值
 
 @param funStr         webview 的方法   例 :  alert("123");
 @param handler        webview  调用 方法 后的 回调 查看 错误 和返回结果
 */
- (void)rzPostValueByJS:(NSString *)funStr  completionHandler:(rzPostValueByJsHandler)handler ;

/**
 webView 调 OC 的 回调方法
 
 */
- (void)rzUserContentController:(WKUserContentController *)userContentController didReceiveScriptMessage:(WKScriptMessage *)message ;


@end
