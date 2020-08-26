//
//  PAHMMetaModel.h
//  Pods
//
//  Created by wans on 2017/9/15.
//
//

#import <Foundation/Foundation.h>

@interface PAHMMetaModel : NSObject

// 返回码
@property (nonatomic, assign) NSInteger    code;

// 返回信息
@property (nonatomic, strong) NSString      *message;

// 返回主体数据
@property (nonatomic, strong) id            body;

// 元数据
@property (nonatomic, strong) NSDictionary  *meta;

// 是否来自缓存
@property (nonatomic, assign) BOOL          isFromCache;

@end
