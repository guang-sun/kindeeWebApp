//
//  TrainFaceView.h
//  kindeeWeb
//
//  Created by Guang on 2020/11/28.
//  Copyright © 2020 WDG. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@protocol TrainFaceImageDelegate <NSObject>

- (void)trainFacceInfo:(UIImage *)image ;

@end

@interface TrainFaceView : UIView

@property (nonatomic, assign) id<TrainFaceImageDelegate>  delegate;

- (void)showFaceView ;

- (void)resetFaceCheck ;

-(void)dismissFaceView ;

@end

NS_ASSUME_NONNULL_END
