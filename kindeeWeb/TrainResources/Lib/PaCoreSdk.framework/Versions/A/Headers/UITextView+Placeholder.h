//
//  UITextView+Placeholder.h
//  GGCharts
//
//  Created by Davon Zhou on 2018/12/3.
//  Copyright © 2018 PAZN. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface UITextView (Placeholder)

@property (nonatomic, readonly) UITextView *placeholderTextView;

@property (nonatomic, strong) IBInspectable NSString *placeholder;
@property (nonatomic, strong) NSAttributedString *attributedPlaceholder;
@property (nonatomic, strong) IBInspectable UIColor *placeholderColor;

+ (UIColor *)defaultPlaceholderColor;

@end

NS_ASSUME_NONNULL_END
