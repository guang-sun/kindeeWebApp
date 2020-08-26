//
//  PAZNWebViewProgress.h
//
//  Created by Satoshi Aasano on 4/20/13.
//  Copyright (c) 2013 Satoshi Asano. All rights reserved.
//

#import <UIKit/UIKit.h>

extern const float PAZNInitialProgressValue;
extern const float PAZNInteractiveProgressValue;
extern const float PAZNFinalProgressValue;

typedef void (^PAZNWebViewProgressBlock)(float progress);

@protocol PAZNWebViewProgressDelegate;

@interface PAZNWebViewProgress : NSObject <UIWebViewDelegate>

@property (nonatomic, weak) id<PAZNWebViewProgressDelegate> progressDelegate;
@property (nonatomic, weak) id<UIWebViewDelegate> webViewProxyDelegate;
@property (nonatomic, copy) PAZNWebViewProgressBlock progressBlock;
@property (nonatomic, readonly) float progress; // 0.0..1.0

- (void)reset;

@end

@protocol PAZNWebViewProgressDelegate <NSObject>

- (void)webViewProgress:(PAZNWebViewProgress *)webViewProgress updateProgress:(float)progress;

@end

