//
//  PAImagePickerAssetCell.h
//  imagePicker
//
//  Created by Davon Zhou on 2019/1/4.
//  Copyright © 2019 com.vz. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@class PAImagePickerAssetCell;
@protocol PAImagePickerAssetCellDelegate <NSObject>

- (void)assetCell:(PAImagePickerAssetCell *)cell checked:(BOOL)checked;
- (void)denyCheck;
@end

@interface PAImagePickerAssetCell : UICollectionViewCell

@property(nonatomic, weak) id<PAImagePickerAssetCellDelegate> delegate;

@property(nonatomic, strong) UIImageView *imageView;

@property(nonatomic, strong) UIButton *checkButton;

@property(nonatomic, strong) UIButton *maskView;

@property(nonatomic, copy) NSString *representedAssetIdentifier;

@property(nonatomic, assign) BOOL isForLive;

@end

NS_ASSUME_NONNULL_END
