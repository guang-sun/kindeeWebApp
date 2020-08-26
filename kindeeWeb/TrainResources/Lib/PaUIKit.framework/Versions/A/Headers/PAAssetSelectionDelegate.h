//
//  PAAssetSelectionDelegate.h
//  imagePicker
//
//  Created by Davon Zhou on 2019/1/7.
//  Copyright © 2019 com.vz. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <Photos/Photos.h>

NS_ASSUME_NONNULL_BEGIN

@protocol PAAssetSelectionDelegate <NSObject>

@optional
- (void)selectedAssets:(NSArray *)assets;
- (BOOL)shouldSelectAsset:(PHAsset *)asset previousCount:(NSUInteger)previousCount;
- (void)cancelSelectionAsset:(PHAsset *)asset;

@end

NS_ASSUME_NONNULL_END
