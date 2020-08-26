//
//  PAZNWebViewJavascriptBridgeBase.h
//
//  Created by @LokiMeyburg on 10/15/14.
//  Copyright (c) 2014 @LokiMeyburg. All rights reserved.
//

#import <Foundation/Foundation.h>

//#define kCustomProtocolScheme @"wvjbscheme"
//#define kQueueHasMessage      @"__PAZNWVJB_QUEUE_MESSAGE__"
#define kBridgeLoaded         @"__BRIDGE_LOADED__"

#define kCustomProtocolScheme @"yy"
#define kQueueHasMessage @"__QUEUE_MESSAGE__"

typedef void (^WVJBResponseCallback)(BOOL success, id responseData);
typedef void (^WVJBHandler)(id data, WVJBResponseCallback responseCallback);
typedef NSDictionary WVJBMessage;

@protocol PAZNWebViewJavascriptBridgeBaseDelegate <NSObject>
- (NSString*) _evaluateJavascript:(NSString*)javascriptCommand;
@end

@interface PAZNWebViewJavascriptBridgeBase : NSObject


@property (weak, nonatomic) id <PAZNWebViewJavascriptBridgeBaseDelegate> delegate;
@property (strong, nonatomic) NSMutableArray* startupMessageQueue;
@property (strong, nonatomic) NSMutableDictionary* responseCallbacks;
@property (strong, nonatomic) NSMutableDictionary* messageHandlers;
@property (strong, nonatomic) WVJBHandler messageHandler;

+ (void)enableLogging;
+ (void)setLogMaxLength:(int)length;
- (void)reset;
- (void)sendData:(id)data responseCallback:(WVJBResponseCallback)responseCallback handlerName:(NSString*)handlerName;
- (void)flushMessageQueue:(NSString *)messageQueueString;
- (void)injectJavascriptFile;
- (BOOL)isCorrectProcotocolScheme:(NSURL*)url;
- (BOOL)isQueueMessageURL:(NSURL*)urll;
- (BOOL)isBridgeLoadedURL:(NSURL*)urll;
- (void)logUnkownMessage:(NSURL*)url;
- (NSString *)webViewJavascriptCheckCommand;
- (NSString *)webViewJavascriptFetchQueyCommand;

@end
