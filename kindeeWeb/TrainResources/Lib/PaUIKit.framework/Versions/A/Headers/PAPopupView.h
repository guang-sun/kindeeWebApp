//
//  PAPopupView.h
//  MLPlayer
//
//  Created by Davon Zhou on 2018/10/1.
//  Copyright © 2018 w. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, PAPopupViewPosition) {
    PAPopupViewPositionMiddle,
    PAPopupViewPositionBottom
};

@protocol PAPopupViewDelegate <NSObject>

@optional
- (void)popupViewDismissed:(id)object;
- (void)popupViewShowed;

@end

@interface PAPopupView : UIView

@property(nonatomic, weak) id<PAPopupViewDelegate> delegate;

@property(nonatomic, strong) UIView *containerView;
@property(nonatomic, assign) PAPopupViewPosition position;
@property (nonatomic, assign) CGFloat cornerRadius;
@property (nonatomic, assign) BOOL canDismissWithTap;

@property(nonatomic, assign) BOOL canInput;

- (CGFloat)contentViewWidth;
- (CGFloat)contentViewHeight;

- (void)initSubview;

- (void)show;
- (void)showOnView:(UIView *)onView;
- (void)dismiss;
@end

NS_ASSUME_NONNULL_END
