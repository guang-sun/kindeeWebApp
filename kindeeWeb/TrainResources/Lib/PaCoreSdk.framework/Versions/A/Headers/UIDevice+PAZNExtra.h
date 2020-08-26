//
//  UIDevice+PAZNExtra.h
//  MLPlayer
//
//  Created by BearLi on 15/12/21.
//  Copyright © 2015年 w. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UIDevice (PAZNExtra)

/**
 *  系统剩余内存大小 (KB)
 *  @return 系统剩余内存大小
 */
+ (CGFloat)freeDiskSpace;

/**
 *  目标文件大小是否有多余空间装载
 *
 *  @param fileSize 文件大小（MB）
 *
 *  @return YES or NO
 */
+ (BOOL)hasFreeDiskWithFileSize:(CGFloat)fileSize;

/**
 * 目标文件大小是否有空余空间装载
 *
 *  @param fileSize       文件大小 (MB)
 *  @param constraintSize 要约束的剩余空间大小 (MB)
 *
 *  @return YES or NO
 */
+ (BOOL)hasFreeDiskWithFileSize:(CGFloat)fileSize constraintSize:(CGFloat)constraintSize;

@end
