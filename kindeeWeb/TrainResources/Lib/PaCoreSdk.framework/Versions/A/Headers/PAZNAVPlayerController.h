//
//  AVPlayerController.h
//  AVPlayerController
//
//  Created by 邢迪 on 2017/3/7.
//  Copyright © 2017年 MacPro. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <AVFoundation/AVFoundation.h>
#import <AVKit/AVKit.h>
#import "PAZNVideoPlayerView.h"

#define StateBufferNotify       @"PAZNAV_BUFFER_NOTIFY"
#define StatePlayingNotify       @"PAZNAV_PLAYING_NOTIFY"
typedef NS_ENUM(NSInteger, PAZNAVPlayerState) {
    PAZNAVPlayerStateFailed,             //播放失败
    PAZNAVPlayerStateBuffering,          //缓冲中,包括一进来时，控制菊花
    PAZNAVPlayerStateStopped,            //停止播放
    PAZNAVPlayerStatePlaying,            //播放中
    PAZNAVPlayerStatePaused,             //暂停
};

typedef NS_ENUM(NSInteger, PAZNAVPlayerType) {
    PAZNAVPlayerType_DESK,
    PAZNAVPlayerType_CAMERA,
    PAZNAVPlayerType_CONNECT,
};

@protocol PAZNAVPlayerDelegate <NSObject>

@optional
//获取缓冲进度
- (void)updateBufferProgress:(CGFloat)bufferProgress;
- (void)updatePlayerState:(PAZNAVPlayerState)state;
- (void)updatePlayerEnd;
- (void)updateCurrentTime:(NSInteger)currentTime totalTime:(NSInteger)totalTime sliderValue:(CGFloat)value;

@end

@interface PAZNAVPlayerController : NSObject

@property (nonatomic, copy) NSURL *contentURL;
@property (nonatomic, assign) NSTimeInterval currentPlaybackTime;
@property (nonatomic, assign) NSTimeInterval duration;
@property (nonatomic, assign) NSTimeInterval startTime;
@property (nonatomic, strong) PAZNVideoPlayerView *view;
@property (nonatomic, strong) UIActivityIndicatorView *loadingView;
@property (nonatomic, strong) AVPlayer *player;
@property (nonatomic, strong) AVPlayerItem *playerItem;
@property (nonatomic, strong) AVPlayerItemVideoOutput * itemVideoOutput;
@property (nonatomic, strong) AVURLAsset *urlAsset;
@property (nonatomic, assign) PAZNAVPlayerState state;
@property (nonatomic, assign) PAZNAVPlayerType type;
@property (nonatomic, assign) BOOL isAutoEnd;
@property (nonatomic, assign) BOOL isPauseByUser;
@property (nonatomic, assign) BOOL isRepeat;
@property (nonatomic, weak) id<PAZNAVPlayerDelegate> delegate;
@property (nonatomic, strong) id timeObserve;
@property (nonatomic, assign) CGFloat playbackRate;

- (instancetype)initWithContentURL:(NSURL *)url startTime:(NSTimeInterval)startTime withDelegate:(id)del;
- (instancetype)initWithContentURL:(NSURL *)url startTime:(NSTimeInterval)startTime withDelegate:(id)del isAutoPlay:(BOOL)isAutoPlay;
- (void)play;
- (void)stop;
- (void)pause;
- (void)mute;
- (void)resetPlayer;
- (void)configPlayer;
- (UIImage *)snapshotImage;
- (NSTimeInterval)currentPlaybackTime;
- (void)setCurrentPlaybackTime:(NSTimeInterval)timeInterval;
- (void)setState:(PAZNAVPlayerState)state;

- (void)addPalyTimeObserve;
- (void)removePalyTimeObserver;
@end
