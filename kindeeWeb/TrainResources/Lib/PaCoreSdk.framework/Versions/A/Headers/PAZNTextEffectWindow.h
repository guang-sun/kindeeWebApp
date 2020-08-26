//
//  PAZNTextEffectWindow.h
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
#import <PAZNText/PAZNTextMagnifier.h>
#import <PAZNText/PAZNTextSelectionView.h>
#else
#import "PAZNTextMagnifier.h"
#import "PAZNTextSelectionView.h"
#endif

NS_ASSUME_NONNULL_BEGIN

/**
 A window to display magnifier and extra contents for text view.
 
 @discussion Use `sharedWindow` to get the instance, don't create your own instance.
 Typically, you should not use this class directly.
 */
@interface PAZNTextEffectWindow : UIWindow

/// Returns the shared instance (returns nil in App Extension).
+ (nullable instancetype)sharedWindow;

/// Show the magnifier in this window with a 'popup' animation. @param mag A magnifier.
- (void)showMagnifier:(PAZNTextMagnifier *)mag;
/// Update the magnifier content and position. @param mag A magnifier.
- (void)moveMagnifier:(PAZNTextMagnifier *)mag;
/// Remove the magnifier from this window with a 'shrink' animation. @param mag A magnifier.
- (void)hideMagnifier:(PAZNTextMagnifier *)mag;


/// Show the selection dot in this window if the dot is clipped by the selection view.
/// @param selection A selection view.
- (void)showSelectionDot:(PAZNTextSelectionView *)selection;
/// Remove the selection dot from this window.
/// @param selection A selection view.
- (void)hideSelectionDot:(PAZNTextSelectionView *)selection;

@end

NS_ASSUME_NONNULL_END
