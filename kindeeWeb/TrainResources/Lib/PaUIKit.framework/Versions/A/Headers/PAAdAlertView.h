//
//  PAAdAlertView.h
//  PAAdAlertViewApp
//
//  Created by Daniel Yao on 16/12/16.
//  Copyright © 2016年 Daniel Yao. All rights reserved.
//

#import <UIKit/UIKit.h>

@protocol PAAdAlertDelegate <NSObject>

-(void)PAAdAlertClickAlertViewAtIndex:(NSInteger)index;
-(void)PAAdAlertDidDismissForSuperView;

@end

@interface PAAdAlertView : UIView

@property(nonatomic,weak)id<PAAdAlertDelegate> delegate;

+(PAAdAlertView *)showInView:(UIView *)view theDelegate:(id)delegate theADInfo: (NSArray *)dataList placeHolderImage: (NSString *)placeHolderStr;

@end


@interface PAAdItemView : UIView

@property(nonatomic,assign)NSInteger index;//记录当前第几个item
@property(nonatomic,strong)UIImageView*imageView;//自定义视图

@end
