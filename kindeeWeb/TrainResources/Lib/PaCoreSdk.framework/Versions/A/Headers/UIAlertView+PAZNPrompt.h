//
//  UIAlertView+PAZNPrompt.h
//  MLPlayer
//
//  Created by suruochang on 16/5/9.
//  Copyright © 2016年 w. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UIAlertView (PAZNPrompt)

+ (UITextField *)inputWithTitle:(NSString *)title
                        message:(NSString *)message
              cancelButtonTitle:(NSString *)cancelButtonTitle
             approveButtonTitle:(NSString *)approveButtonTitle
                     completion:(void(^)(NSString *input, BOOL cancelled))completion;

+ (UITextField *)inputWithTitle:(NSString *)title
                        message:(NSString *)message
                secureTextEntry:(BOOL)secureTextEntry
              cancelButtonTitle:(NSString *)cancelButtonTitle
             approveButtonTitle:(NSString *)approveButtonTitle
                     completion:(void(^)(NSString *input, BOOL cancelled))completion;

@end
