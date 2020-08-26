//
//  NSObject+PAPermission.h
//  PaCoreSdk
//
//  Created by Davon Zhou on 2018/11/14.
//  Copyright © 2018 Cyril Zhou. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, PAPermissionStatus){
    Allowed,
    Denied,
    NotDetermined,
    NotDeterminedThenDenied,
};

@interface NSObject (PAPermission)

- (void)checkMicrophone:(void(^)(PAPermissionStatus status))completed;

- (void)checkPhotoLibrary:(void(^)(PAPermissionStatus status))completed;

@end

NS_ASSUME_NONNULL_END
