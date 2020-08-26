// Software License Agreement (BSD License)
//
// Copyright (c) 2010-2016, Deusty, LLC
// All rights reserved.
//
// Redistribution and use of this software in source and binary forms,
// with or without modification, are permitted provided that the following conditions are met:
//
// * Redistributions of source code must retain the above copyright notice,
//   this list of conditions and the following disclaimer.
//
// * Neither the name of Deusty nor the names of its contributors may be used
//   to endorse or promote products derived from this software without specific
//   prior written permission of Deusty, LLC.

/**
 * Welcome to CocoaLumberjack!
 *
 * The project page has a wealth of documentation if you have any questions.
 * https://github.com/CocoaLumberjack/CocoaLumberjack
 *
 * If you're new to the project you may wish to read "Getting Started" at:
 * Documentation/GettingStarted.md
 *
 * Otherwise, here is a quick refresher.
 * There are three steps to using the macros:
 *
 * Step 1:
 * Import the header in your implementation or prefix file:
 *
 * #import <CocoaLumberjack/CocoaLumberjack.h>
 *
 * Step 2:
 * Define your logging level in your implementation file:
 *
 * // Log levels: off, error, warn, info, verbose
 * static const PAZNLogLevel ddLogLevel = PAZNLogLevelVerbose;
 *
 * Step 2 [3rd party frameworks]:
 *
 * Define your LOG_LEVEL_DEF to a different variable/function than ddLogLevel:
 *
 * // #undef LOG_LEVEL_DEF // Undefine first only if needed
 * #define LOG_LEVEL_DEF myLibLogLevel
 *
 * Define your logging level in your implementation file:
 *
 * // Log levels: off, error, warn, info, verbose
 * static const PAZNLogLevel myLibLogLevel = PAZNLogLevelVerbose;
 *
 * Step 3:
 * Replace your NSLog statements with PAZNLog statements according to the severity of the message.
 *
 * NSLog(@"Fatal error, no dohickey found!"); -> PAZNLogError(@"Fatal error, no dohickey found!");
 *
 * PAZNLog works exactly the same as NSLog.
 * This means you can pass it multiple variables just like NSLog.
 **/

#import <Foundation/Foundation.h>

// Disable legacy macros
#ifndef PAZN_LEGACY_MACROS
    #define PAZN_LEGACY_MACROS 0
#endif

// Core
#import "PAZNLog.h"

// Main macros
#import "PAZNLogMacros.h"
#import "PAZNAssertMacros.h"

// Capture ASL
#import "PAZNASLLogCapture.h"

// Loggers
#import "PAZNTTYLogger.h"
#import "PAZNASLLogger.h"
#import "PAZNFileLogger.h"
#import "PAZNOSLogger.h"

// CLI
#if __has_include("CLIColor.h") && TARGET_OS_OSX
#import "CLIColor.h"
#endif
