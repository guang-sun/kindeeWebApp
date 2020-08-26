//
//  PAAssetPickerController.h
//  imagePicker
//
//  Created by Davon Zhou on 2019/1/7.
//  Copyright © 2019 com.vz. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <Photos/Photos.h>
#import "PAAssetSelectionDelegate.h"
#import "PAImagePickerController.h"

NS_ASSUME_NONNULL_BEGIN
 
@interface PAAssetPickerController : UIViewController

@property (nonatomic, strong) PHAssetCollection *assetGroup;

@property (nonatomic, weak) PAImagePickerController *parent;

@end

NS_ASSUME_NONNULL_END
