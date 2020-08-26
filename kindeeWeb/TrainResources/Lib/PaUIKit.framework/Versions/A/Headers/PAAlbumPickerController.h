//
//  PAAlbumPickerController.h
//  imagePicker
//
//  Created by Davon Zhou on 2019/1/7.
//  Copyright © 2019 com.vz. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "PAAssetSelectionDelegate.h"

NS_ASSUME_NONNULL_BEGIN

@interface PAAlbumPickerController : UITableViewController <PAAssetSelectionDelegate>

@property (nonatomic, weak) id<PAAssetSelectionDelegate> parent;
@property (nonatomic, strong) NSMutableArray *assetGroups;
@property (nonatomic, strong) NSArray *mediaTypes; 

@end

NS_ASSUME_NONNULL_END
