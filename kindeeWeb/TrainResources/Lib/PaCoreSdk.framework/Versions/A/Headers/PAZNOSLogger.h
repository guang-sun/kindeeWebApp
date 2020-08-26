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

#import <Foundation/Foundation.h>

// Disable legacy macros
#ifndef PAZN_LEGACY_MACROS
    #define PAZN_LEGACY_MACROS 0
#endif

#import "PAZNLog.h"

/**
 * This class provides a logger for the Apple os_log facility.
 **/
@interface PAZNOSLogger : PAZNAbstractLogger <PAZNLogger>

/**
 *  Singleton method
 *
 *  @return the shared instance
 */
@property (class, readonly, strong) PAZNOSLogger *sharedInstance;

@end
