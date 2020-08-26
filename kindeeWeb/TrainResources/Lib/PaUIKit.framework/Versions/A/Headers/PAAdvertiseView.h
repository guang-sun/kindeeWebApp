//
//  PAAdvertiseView.h
//  MLPlayer
//
//  Created by xing di on 2017/7/5.
//  Copyright © 2017年 w. All rights reserved.
//

#import <UIKit/UIKit.h>

@protocol PAAdvertiseViewDelegate <NSObject>

- (void)PAAdvertiseViewDidBack:(id)userInfo;
- (BOOL)PAAdvertiseViewShouldTap:(id)userInfo;
- (void)PAAdvertiseViewDidTap:(id)userInfo;

@end

@interface PAAdvertiseView : UIView <UIGestureRecognizerDelegate>

@property (nonatomic, weak) id<PAAdvertiseViewDelegate> delegate;
@property (nonatomic, strong) NSData *imageData;
@property (nonatomic, strong) UIImage *placeholdImage;
@property (nonatomic, strong) NSString *imageUrl;
@property (nonatomic, assign) NSUInteger showTime;
@property (nonatomic, strong) id userInfo;

- (void)startShow;
- (void)refreshImageUrl:(NSString *)imageUrl;

@end
