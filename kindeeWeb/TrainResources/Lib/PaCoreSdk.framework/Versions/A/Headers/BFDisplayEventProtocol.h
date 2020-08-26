//
//  BFDisplayEventProtocol.h
//  HomePage https://github.com/wans3112/BFDisplayEvent
//
//  Created by wans on 2017/4/12.
//  Copyright © 2017年 wans,www.wans3112.cn All rights reserved.
//

#ifndef BFDisplayEventProtocol_h
#define BFDisplayEventProtocol_h

#import "BFEventModel.h"

/**
 参数传递block

 @param eventModel 参数model
 */
typedef void (^BFEventManagerBlock)(BFEventModel* eventModel);
typedef void (^BFEventManagerDoneBlock)(void);


/**
 显示数据协议
 */
@protocol BFDisplayProtocol <NSObject>

@optional
- (void)em_displayWithModel:(BFEventManagerBlock)eventBlock;

- (void)em_displayWithDataModel:(id)model;

@end



/**
 点击事件协议
 */
@protocol BFEventManagerProtocol <NSObject>

- (void)em_didSelectItemWithModel:(BFEventModel *)eventModel;

- (void)em_didSelectItemWithModelBlock:(BFEventManagerBlock)eventBlock;

@required
- (NSString *)em_eventManagerWithPropertName;

@end

#endif /* BFDisplayEventProtocol_h */