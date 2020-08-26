//
//  NSMutableArray+PAZNUtilityButtons.h
//  PAZNTableViewCell
//
//  Created by Matt Bowman on 11/27/13.
//  Copyright (c) 2013 Chris Wendel. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSMutableArray (PAZNUtilityButtons)

- (void)pazn_addUtilityButtonWithColor:(UIColor *)color title:(NSString *)title;
- (void)pazn_addUtilityButtonWithColor:(UIColor *)color attributedTitle:(NSAttributedString *)title;
- (void)pazn_addUtilityButtonWithColor:(UIColor *)color icon:(UIImage *)icon;
- (void)pazn_addUtilityButtonWithColor:(UIColor *)color normalIcon:(UIImage *)normalIcon selectedIcon:(UIImage *)selectedIcon;

@end


@interface NSArray (PAZNUtilityButtons)

- (BOOL)pazn_isEqualToButtons:(NSArray *)buttons;

@end
