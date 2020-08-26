//
//  PAInputImpressionView.h
//  PaUIKit
//
//  Created by 黄漫(EX-HUANGMAN001) on 2020/6/16.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface PAInputImpression : NSObject

//标签评分等级 1：[0-6]很差；2：[7-8]一般；3：[9-10]很好；
/// 大等级
@property (nonatomic, copy) NSString *mainLevel;

/// 标签id
@property (nonatomic, copy) NSString *identifier;

/// 标签标题
@property (nonatomic, copy) NSString *label;

/// 标签等级
@property (nonatomic, copy) NSString *labelLevel;

@end

@interface PAInputImpressionView : UIView

/// 已选印象标签集合回调
@property (nonatomic, copy) void(^selectedBlock)(PAInputImpression *impression);

/// 印象标签数据源
@property (nonatomic, strong) NSArray<PAInputImpression *>*impressions;

@end

NS_ASSUME_NONNULL_END
