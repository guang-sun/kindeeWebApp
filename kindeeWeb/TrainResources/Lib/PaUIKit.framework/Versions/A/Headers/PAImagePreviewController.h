//
//  PAImagePreviewController.h
//  MLPlayer
//
//  Created by 周大俊(智慧教育) on 2019/1/19.
//  Copyright © 2019年 平安知鸟. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <Photos/Photos.h> 
#import "PAImagePickerController.h"

NS_ASSUME_NONNULL_BEGIN

typedef void (^Callback)(NSArray *selectedAssets);

@interface PAImagePreviewController : UIViewController

@property (nonatomic, strong) NSMutableArray *selectedAssets;

@property (nonatomic, strong) PHFetchResult<PHAsset *> *fetchResult;

@property (nonatomic, weak) PAImagePickerController *parent;

@property (nonatomic, strong) Callback callback;

@property(nonatomic, assign) NSInteger index;

@end

NS_ASSUME_NONNULL_END
