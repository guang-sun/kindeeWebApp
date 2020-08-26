//
//  PAZNText.h
//  PAZNText <https://github.com/ibireme/PAZNText>
//
//  Created by ibireme on 15/2/25.
//  Copyright (c) 2015 ibireme.
//
//  This source code is licensed under the MIT-style license found in the
//  LICENSE file in the root directory of this source tree.
//

#import <UIKit/UIKit.h>

#if __has_include(<PAZNText/PAZNText.h>)
FOUNDATION_EXPORT double PAZNTextVersionNumber;
FOUNDATION_EXPORT const unsigned char PAZNTextVersionString[];
#import <PAZNText/PAZNLabel.h>
#import <PAZNText/PAZNTextView.h>
#import <PAZNText/PAZNTextAttribute.h>
#import <PAZNText/PAZNTextArchiver.h>
#import <PAZNText/PAZNTextParser.h>
#import <PAZNText/PAZNTextRunDelegate.h>
#import <PAZNText/PAZNTextRubyAnnotation.h>
#import <PAZNText/PAZNTextLayout.h>
#import <PAZNText/PAZNTextLine.h>
#import <PAZNText/PAZNTextInput.h>
#import <PAZNText/PAZNTextDebugOption.h>
#import <PAZNText/PAZNTextKeyboardManager.h>
#import <PAZNText/PAZNTextUtilities.h>
#import <PAZNText/NSAttributedString+PAZNText.h>
#import <PAZNText/NSParagraphStyle+PAZNText.h>
#import <PAZNText/UIPasteboard+PAZNText.h>
#else
#import "PAZNLabel.h"
#import "PAZNTextView.h"
#import "PAZNTextAttribute.h"
#import "PAZNTextArchiver.h"
#import "PAZNTextParser.h"
#import "PAZNTextRunDelegate.h"
#import "PAZNTextRubyAnnotation.h"
#import "PAZNTextLayout.h"
#import "PAZNTextLine.h"
#import "PAZNTextInput.h"
#import "PAZNTextDebugOption.h"
#import "PAZNTextKeyboardManager.h"
#import "PAZNTextUtilities.h"
#import "NSAttributedString+PAZNText.h"
#import "NSParagraphStyle+PAZNText.h"
#import "UIPasteboard+PAZNText.h"
#endif
