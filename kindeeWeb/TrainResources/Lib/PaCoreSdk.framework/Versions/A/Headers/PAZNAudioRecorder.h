//
//  PAZNAudioRecorder.h
//  AudioDownloadSDK
//
//  Created by txt on 16/3/14.
//  Copyright © 2016年 txt. All rights reserved.
//

#import <Foundation/Foundation.h>

//录音完成后发的通知
#define kPAAudioRecordFinishNotification      @"PAAudioRecordFinishNotification"


@interface PAZNAudioRecorder : NSObject

+(instancetype)shareInstance;

//采集原始音频文件路径名
@property(nonatomic,copy)  NSString   *audioFilePathName;

//编码后的mp3文件路径名,如果文件名audioFilePathName为空,则跟audioFilePathName文件同名加上.mp3后缀
@property(nonatomic,copy)  NSString   *audioFileEncodeName;

//音频录音时长,默认录音时长1分钟
@property(nonatomic,assign)  NSTimeInterval  audioRecordDuration;

//是否启用单声道，默认否
@property(nonatomic, assign) BOOL singleTrack;

//判断录音权限
-(BOOL)canRecord;

//判断耳机是否插入
- (BOOL)isHeadsetPluggedIn;

//判断是否正在录音
-(BOOL)isRecording;

//当前的录音时间
-(NSTimeInterval )currentTime;

//录制的recorder
-(AVAudioRecorder *)recorder;

//开始采集音频数据
-(void)startAudioRecord;

//停止采集音频数据
-(void)stopAudioRecord;

//暂停采集音频数据
-(void)pauseAudioRecord;

/**
 *  本地是否存在录音文件
 *
 *  @return YES存在，NO不存在
 */
-(BOOL)existFilePathName;

//删除已录制文件
-(void)deleteAudioFile;

//删除已录制文件
-(void)deleteAudioFileWithName:(NSString *)name;

@end
