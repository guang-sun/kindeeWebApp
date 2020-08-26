//
//  PAPhotoView.h
//  PAUIKit
//

#import <UIKit/UIKit.h>
#import "PAZNSDAnimatedImageView.h"

@protocol PAPhotoViewDelegate <NSObject>

- (void)photoViewSingleTap:(NSInteger)index;

- (BOOL)photoIsShowingPhotoViewAtIndex:(NSUInteger)index;

- (void)updatePhotoProgress:(CGFloat)progress andIndex:(NSInteger)index;

@end

@interface PAPhotoView : UIView

@property(nonatomic, strong) PAZNSDAnimatedImageView *itemImageView;

@property(nonatomic, strong)PAZNSDAnimatedImage *itemImage;

@property(nonatomic, strong)id itemImageData; 

@property(nonatomic, assign)CGFloat itemImageProgress;

@property(nonatomic, weak)id<PAPhotoViewDelegate> photoViewDelegate;

- (void)resetSize;

@end
