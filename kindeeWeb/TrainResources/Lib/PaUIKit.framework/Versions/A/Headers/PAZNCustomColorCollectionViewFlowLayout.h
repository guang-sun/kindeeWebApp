//
//  PAZNCustomColorCollectionViewFlowLayout.h
//  testFunction
//
//  Created by 文泽亮 on 2018/10/8.
//  Copyright © 2018年 文泽亮. All rights reserved.
//

#import <UIKit/UIKit.h>

/// 扩展section的背景色
@protocol PAZNCustomColorCollectionViewDelegateFlowLayout <UICollectionViewDelegateFlowLayout>

- (UIColor *)collectionView:(UICollectionView *)collectionView layout:(UICollectionViewLayout*)collectionViewLayout colorForSectionAtIndex:(NSInteger)section;
@end

typedef NS_ENUM(NSInteger,AlignType){
    AlignWithLeft,
    AlignWithCenter,
    AlignWithRight
};

@interface PAZNCustomColorCollectionViewFlowLayout : UICollectionViewFlowLayout
/** 两个Cell之间的距离 */
@property (nonatomic,assign)CGFloat betweenOfCell;
/** cell对齐方式 */
@property (nonatomic,assign)AlignType cellType;

-(instancetype)initWthType:(AlignType)cellType;

-(instancetype)initWithType:(AlignType)cellType betweenOfCell:(CGFloat)betweenOfCell;
@end





