//
//  PAZNRefreshNormalHeader+Additions.h
//  MLPlayer
//
//  Created by 王斌(平安科技智慧教育团队项目研发部知鸟研发团队移动开发组) on 2018/9/4.
//  Copyright © 2018年 w. All rights reserved.
//

#import <PaCoreSdk/PaCoreSdk.h>

@interface PAZNRefreshNormalHeader (Additions)

+ (instancetype)pa_refreshingBlock:(PAZNRefreshComponentRefreshingBlock)refreshingBlock;

@end

@interface PAZNRefreshBackNormalFooter (Additions)

+ (instancetype)pa_refreshingBlock:(PAZNRefreshComponentRefreshingBlock)refreshingBlock;

@end

@interface PAZNRefreshBackGifFooter (Additions)

+ (instancetype)pa_refreshingBlock:(PAZNRefreshComponentRefreshingBlock)refreshingBlock;

@end


