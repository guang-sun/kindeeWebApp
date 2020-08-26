//
//  PAImagePickerAlbumCell.h
//  imagePicker
//
//  Created by 周大俊(智慧教育) on 2019/1/9.
//  Copyright © 2019年 com.vz. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface PAImagePickerAlbumCell : UITableViewCell

@property (nonatomic, strong) UIImageView *coverImageView;
@property (nonatomic, strong) UILabel *nameLabel;
@property (nonatomic, strong) UILabel *countLabel;

@end

NS_ASSUME_NONNULL_END
