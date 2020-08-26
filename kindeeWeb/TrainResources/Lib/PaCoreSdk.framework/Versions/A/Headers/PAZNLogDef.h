//
//  PALiveLogDef.h
//  PaLiveSdk
//
//  Created by w-chen on 2018/1/12.
//  Copyright © 2018年 Cyril Zhou. All rights reserved.
//


#ifndef PAZNLogDef_h
#define PAZNLogDef_h

#import <PaCoreSdk/PAZNLog.h>

FOUNDATION_EXTERN PAZNLog * PAZNLoger;

#ifndef PAZNApp_LOG_LEVEL_DEF
#define PAZNApp_LOG_LEVEL_DEF ddLogLevel
#endif


#define PAZNApp_LOG_ASYNC_ENABLED YES

#define PAZNApp_LOG_ASYNC_INFO     (YES && PAZNApp_LOG_ASYNC_ENABLED)

#define PAZNApp_LOG_MACRO(isAsynchronous, lvl, flg, ctx, atag, fnct, frmt, ...) \
[PAZNLoger log : isAsynchronous                                     \
level : lvl                                                \
flag : flg                                                \
context : ctx                                                \
file : __FILE__                                           \
function : fnct                                               \
line : __LINE__                                           \
tag : atag                                               \
format : (frmt), ## __VA_ARGS__]

#define PAZNApp_LOG_MAYBE(async, lvl, flg, ctx, fnct, frmt, ...)                       \
do { if(lvl & flg) PAZNApp_LOG_MACRO(async, lvl, flg, ctx, nil, fnct, frmt, ##__VA_ARGS__); } while(0)

#define PAZNApp_LOG_OBJC_MAYBE(async, lvl, flg, ctx, frmt, ...) \
PAZNApp_LOG_MAYBE(async, lvl, flg, ctx, __PRETTY_FUNCTION__, frmt, ## __VA_ARGS__)

#define PAZNAppDDLogInfo(frmt, ...)  PAZNApp_LOG_OBJC_MAYBE(PAZNApp_LOG_ASYNC_INFO,    PAZNApp_LOG_LEVEL_DEF, PAZNLogFlagInfo,    0, frmt, ##__VA_ARGS__)


#define PAZNAppLogInfo(frmt, ...) PAZNAppDDLogInfo((@"zhiniao || file:%@" "-line:%@ ||" "%@ || \n" frmt), THIS_FILE, @(__LINE__), THIS_METHOD, ##__VA_ARGS__)

#endif /* PALiveLogDef_h */
