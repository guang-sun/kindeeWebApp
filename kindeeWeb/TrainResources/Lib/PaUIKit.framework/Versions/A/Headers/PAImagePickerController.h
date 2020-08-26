//
//  PAImagePickerController.h
//  imagePicker
//
//  Created by Davon Zhou on 2019/1/4.
//  Copyright © 2019 com.vz. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "PAAssetSelectionDelegate.h"

NS_ASSUME_NONNULL_BEGIN

@class PAImagePickerController;

@protocol PAImagePickerControllerDelegate <UINavigationControllerDelegate>

@optional
- (void)paImagePickerController:(PAImagePickerController *)picker didFinishPickingMediaWithInfo:(NSArray *)info;

- (void)paImagePickerControllerDidCancel:(PAImagePickerController *)picker;

-(void)paImagePickerController:(PAImagePickerController *)picker didSelectedVideoURL:(NSString*)UrlString;

- (void)paImagePickerController:(PAImagePickerController *)picker didSelectedWithImageReferenceURLStr:(NSString *)imageReferenceURLStr;

- (void)paImagePickerController:(PAImagePickerController *)picker didCancelSelectedWithImageReferenceURLStr:(NSString *)imageReferenceURLStr;

- (void)paImagePickerController:(PAImagePickerController *)picker didFinishPickingMediaWithAssetIds:(NSMutableArray *)assetIds;

@end

@interface PAImagePickerController : UINavigationController<PAAssetSelectionDelegate>

@property (nonatomic, weak) id<PAImagePickerControllerDelegate> delegate;

@property(nonatomic, strong) NSMutableArray *selectedAssetIDs;

@property (nonatomic, assign) NSInteger maximumImagesCount;

@property (nonatomic, assign) NSInteger pickedCountFromCamera;//相机拍照的图片数量

@property(nonatomic, assign) BOOL isForLive;

@property(nonatomic, assign) BOOL suppertGIF;
@property(nonatomic, assign) NSUInteger maxGIFSize; // default: 4*1024*1024;

- (void)cancelImagePicker;

- (instancetype)initWithDefaultRootViewController;

@end

NS_ASSUME_NONNULL_END
