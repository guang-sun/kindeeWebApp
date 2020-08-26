//
//  PADrainagePopupView.h
//  MLPlayer
//
//  Created by 罗红(EX-LUOHONG003) on 2020/5/26.
//  Copyright © 2020 平安知鸟. All rights reserved.
//

#import "PAPopupView.h"

typedef NS_ENUM(NSInteger,PADrainageType){
    PADrainageTypeCourse = 0, //课程
    PADrainageTypeEBook, //电子书
    PADrainageTypeLive //直播
};

NS_ASSUME_NONNULL_BEGIN

@interface PADrainagePopupView : PAPopupView

- (instancetype)initWithType:(PADrainageType)type countDown:(NSInteger)maxLimit coverPic:(NSString *)urlStr content:(NSString *)content extraInfo:(NSDictionary *)extraInfo autoOpenCallBack:(void(^)(NSDictionary *extraInfo))openBlock colseCallBack:(void(^)(void))closeBlock;

@end

NS_ASSUME_NONNULL_END
