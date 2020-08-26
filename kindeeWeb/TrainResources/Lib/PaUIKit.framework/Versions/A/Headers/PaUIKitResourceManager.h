//
//  PaUIKitResourceManager.h
//  PaUIKit
//
//  Created by 罗红(EX-LUOHONG003) on 2019/2/21.
//  Copyright © 2019 周长川(智慧教育). All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

#define PaUIKitImageNamed(name)     [PaUIKitResourceManager imageWithName:name]

@interface PaUIKitResourceManager : NSObject

+ (UIImage *)imageWithName:(NSString *)imageName;

@end

NS_ASSUME_NONNULL_END
