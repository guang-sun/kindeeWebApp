//
//  PAZNWebView.h
//  IMY_ViewKit
//
//  Created by ljh on 15/7/1.
//  Copyright (c) 2015年 IMY. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <WebKit/WKScriptMessageHandler.h>

typedef NS_ENUM(NSInteger, PAZNWebViewNavigationType) {
    PAZNWebViewNavigationTypeLinkClicked,
    PAZNWebViewNavigationTypeFormSubmitted,
    PAZNWebViewNavigationTypeBackForward,
    PAZNWebViewNavigationTypeReload,
    PAZNWebViewNavigationTypeFormResubmitted,
    PAZNWebViewNavigationTypeOther
};

@class PAZNWebView;

@protocol PAZNWebViewDelegate <NSObject>
@optional

- (void)webViewDidStartLoad:(PAZNWebView *)webView;
- (void)webViewDidFinishLoad:(PAZNWebView *)webView;
- (void)webView:(PAZNWebView *)webView didFailLoadWithError:(NSError *)error;
- (BOOL)webView:(PAZNWebView *)webView shouldStartLoadWithRequest:(NSURLRequest *)request navigationType:(PAZNWebViewNavigationType)navigationType;
- (void)webViewDidPlayVideoOrAudio:(PAZNWebView *)webView;

@end

@interface PAZNWebView : UIView

@property (nonatomic, weak) id<PAZNWebViewDelegate> delegate;

///内部使用的webView
@property (nonatomic, readonly) id realWebView;

///预估网页加载进度
@property (nonatomic, readonly) double estimatedProgress;

@property (nonatomic, readonly) NSURLRequest *originRequest;

///---- UI 或者 WK 的API
@property (nonatomic, readonly) UIScrollView *scrollView;

@property (nonatomic, readonly, copy) NSString *title;
@property (nonatomic, readonly) NSURLRequest *currentRequest;
@property (nonatomic, readonly) NSURL *URL;
@property (nonatomic, readonly, getter=isLoading) BOOL loading;
@property (nonatomic, readonly) BOOL canGoBack;
@property (nonatomic, readonly) BOOL canGoForward;
@property (nonatomic, copy) NSString *customUserAgent;

///是否根据视图大小来缩放页面  默认为YES
@property (nonatomic, assign) BOOL scalesPageToFit;

/**
 *  添加js回调oc通知方式，适用于 iOS8 之后
 */
- (void)addScriptMessageHandler:(id <WKScriptMessageHandler>)scriptMessageHandler name:(NSString *)name;

/**
 *  注销 注册过的js回调oc通知方式，适用于 iOS8 之后
 */
- (void)removeScriptMessageHandlerForName:(NSString *)name;

///back 层数
- (NSInteger)countOfHistory;
- (void)gobackWithStep:(NSInteger)step;

- (id)loadRequest:(NSURLRequest *)request;
- (id)loadHTMLString:(NSString *)string baseURL:(NSURL *)baseURL;

//模仿ios9系统提供的接口
- (id)loadFileURL:(NSURL *)reqURL allowingReadAccessToURL:(NSURL *)accessURL;

- (id)goBack;
- (id)goForward;
- (id)reload;
- (id)reloadFromOrigin;
- (void)stopLoading;

- (void)evaluateJavaScript:(NSString *)javaScriptString completionHandler:(void (^)(id, NSError *))completionHandler;
///不建议使用这个办法  因为会在内部等待webView 的执行结果
- (NSString *)stringByEvaluatingJavaScriptFromString:(NSString *)javaScriptString; //__deprecated_msg("Method deprecated. Use [evaluateJavaScript:completionHandler:]");

//- (NSString *)currentUserAgent;
- (void)currentUserAgent:(void (^)(NSString *agent))completion;

@end
