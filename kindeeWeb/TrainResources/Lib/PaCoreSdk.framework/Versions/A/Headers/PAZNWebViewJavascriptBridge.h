//
//  PAZNWebViewJavascriptBridge.h
//  ExampleApp-iOS
//
//  Created by Marcus Westin on 6/14/13.
//  Copyright (c) 2013 Marcus Westin. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "PAZNWebViewJavascriptBridgeBase.h"

#if defined __MAC_OS_X_VERSION_MAX_ALLOWED
    #import <WebKit/WebKit.h>
    #define PAZNWVJB_PLATFORM_OSX
    #define PAZNWVJB_WEBVIEW_TYPE WebView
    #define PAZNWVJB_WEBVIEW_DELEGATE_TYPE NSObject<PAZNWebViewJavascriptBridgeBaseDelegate>
    #define PAZNWVJB_WEBVIEW_DELEGATE_INTERFACE NSObject<PAZNWebViewJavascriptBridgeBaseDelegate, WebPolicyDelegate>
#elif defined __IPHONE_OS_VERSION_MAX_ALLOWED
    #import <UIKit/UIWebView.h>
    #define PAZNWVJB_PLATFORM_IOS
    #define PAZNWVJB_WEBVIEW_TYPE UIWebView
    #define PAZNWVJB_WEBVIEW_DELEGATE_TYPE NSObject<UIWebViewDelegate>
    #define PAZNWVJB_WEBVIEW_DELEGATE_INTERFACE NSObject<UIWebViewDelegate, PAZNWebViewJavascriptBridgeBaseDelegate>
#endif

@interface PAZNWebViewJavascriptBridge : PAZNWVJB_WEBVIEW_DELEGATE_INTERFACE

+ (instancetype)bridgeForWebView:(PAZNWVJB_WEBVIEW_TYPE*)webView;
+ (void)enableLogging;
+ (void)setLogMaxLength:(int)length;

- (void)registerHandler:(NSString*)handlerName handler:(WVJBHandler)handler;
- (void)callHandler:(NSString*)handlerName;
- (void)callHandler:(NSString*)handlerName data:(id)data;
- (void)callHandler:(NSString*)handlerName data:(id)data responseCallback:(WVJBResponseCallback)responseCallback;
- (void)setWebViewDelegate:(PAZNWVJB_WEBVIEW_DELEGATE_TYPE*)webViewDelegate;
@end
