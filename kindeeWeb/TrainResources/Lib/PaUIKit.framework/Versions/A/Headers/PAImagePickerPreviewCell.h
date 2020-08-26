//
//  PAImagePickerPreviewCell.h
//  MLPlayer
//
//  Created by 周大俊(智慧教育) on 2019/1/19.
//  Copyright © 2019年 平安知鸟. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "PAImagePreviewController.h"

NS_ASSUME_NONNULL_BEGIN


@interface PAImagePickerPreviewCell : UICollectionViewCell

@property(nonatomic, strong) UIImageView *imageView;

@property(nonatomic, copy) NSString *representedAssetIdentifier;

@end

NS_ASSUME_NONNULL_END
