//
//  AVPlayerView.h
//  AVPlayerController
//
//  Created by MacPro on 2017/3/8.
//  Copyright © 2017年 MacPro. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <AVKit/AVKit.h>
#import <AVFoundation/AVFoundation.h>

@protocol PAZNVideoPlayerViewDelegate <NSObject>

- (void)viewDidTouched:(id)sender;

@end

@interface PAZNVideoPlayerView : UIView

@property (nonatomic, retain) AVPlayer *player;
@property (nonatomic, assign) CGPoint beginpoint;
@property (nonatomic, assign) CGPoint moveArrow;
@property (nonatomic, weak) id<PAZNVideoPlayerViewDelegate> delegate;
@property (nonatomic, assign) BOOL isInView;
@property (nonatomic, strong) UIActivityIndicatorView *indicator;

- (void)setPlayer:(AVPlayer *)player;
- (void)setVideoFillMode:(NSString *)fillMode;
- (void)showIndicator;
- (void)stopIndicator;
@end
