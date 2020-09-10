//
//  PAPunchPopupView.h
//  PaCourseSdk
//
//  Created by 罗红(EX-LUOHONG003) on 2020/6/12.
//  Copyright © 2020 平安知鸟. All rights reserved.
//

#import "PAPopupView.h"

typedef NS_ENUM(NSInteger,PAPunchPopupViewType){
    PAPunchPopupViewTypeUnfinish = 0,
    PAPunchPopupViewTypeFinished = 1
};

NS_ASSUME_NONNULL_BEGIN

@interface PAPunchPopupView : PAPopupView

/// 字体适应宽度
@property (nonatomic, assign) BOOL titleFontSizeAutoFit;
/// 标题富文本
@property (nonatomic, strong) NSAttributedString *titleAttr;

- (instancetype)initWithType:(PAPunchPopupViewType)type punchAction:(void(^)(void))block;
- (instancetype)initWithType:(PAPunchPopupViewType)type content:(NSString *)content punchAction:(void(^)(void))block;

@end

NS_ASSUME_NONNULL_END
