//
//  UICollectionView+FooterRefresh.h
//  MLPlayer
//
//  Created by 刘宏扬 on 2018/11/3.
//  Copyright © 2018年 w. All rights reserved.
//

#import <UIKit/UIKit.h>

@class PACollectionRefreshFooter;
@interface UICollectionView (FooterRefresh)

@property (nonatomic, strong) PACollectionRefreshFooter *sideRefreshFooter;

@property (nonatomic, assign, readonly) UIEdgeInsets side_inset;
@property (nonatomic, assign) CGFloat side_insetL;
@property (nonatomic, assign) CGFloat side_insetR;

@end
