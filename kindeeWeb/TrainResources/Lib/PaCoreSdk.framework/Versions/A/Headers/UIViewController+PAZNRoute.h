//
//  UIViewController+PAZNRoute.h
//  PAZNNavigationExample
//
//  Created by wans on 2017/5/25.
//  Copyright © 2017年 wans. All rights reserved.
//

#import <UIKit/UIKit.h>

// 快速注册viewcontroller
#undef  PAZN_IMPLEMENT_LOAD
#define PAZN_IMPLEMENT_LOAD( url ) \
+ (void)load { \
@autoreleasepool { \
    [UIViewController registerWithUrl:url viewControllerClass:[self class]]; \
} \
}

@class PAZNNode;

typedef void (^PAZNReplyAction)(id result);
typedef void (^PAZNCompleteAction)();

typedef void (^PAZNParams)(PAZNNode *node);

@interface PAZNNode : NSObject

@property (nonatomic, strong) NSString       *url;

@property (nonatomic, assign) BOOL           animate;

@property (nonatomic, strong) id             params;

@property (nonatomic, copy) PAZNCompleteAction completeAction;

@property (nonatomic, copy) PAZNReplyAction    replyAction;

@end

@interface UIViewController (PAZNRoute)

@property (nonatomic, strong) id             pazn_params;

@property (nonatomic, copy) PAZNReplyAction    pazn_replyAction;

- (instancetype)pazn_initWithParams:(id)params;
- (instancetype)pazn_initWithParams:(id)params replyAction:(PAZNReplyAction)replyAction;
+ (instancetype)pazn_initWithUrl:(NSString *)url params:(id)params;
+ (instancetype)pazn_initWithUrl:(NSString *)url params:(id)params replyAction:(PAZNReplyAction)replyAction;

- (void)pazn_pushViewController:(NSString *)url;
- (void)pazn_pushViewController:(NSString *)url animated:(BOOL)animated;
- (void)pazn_pushViewController:(NSString *)url params:(id)params animated:(BOOL)animated;
- (void)pazn_pushViewController:(NSString *)url params:(id)params replyAction:(PAZNReplyAction)replyAction animated:(BOOL)animated;
- (void)pazn_pushViewControllerIntact:(PAZNParams)params;

- (void)pazn_popViewController;
- (void)pazn_popViewControllerAnimate:(BOOL)animated;
- (void)pazn_popToRootViewControllerAnimated:(BOOL)animated;
- (void)pazn_popToViewControllerWithUrl:(NSString *)url animated:(BOOL)animated;


- (void)pazn_presentViewController:(NSString *)url;
- (void)pazn_presentViewController:(NSString *)url animated:(BOOL)animated;
- (void)pazn_presentViewController:(NSString *)url params:(id)params animated:(BOOL)animated;
- (void)pazn_presentViewController:(NSString *)url params:(id)params replyAction:(PAZNReplyAction)replyAction animated:(BOOL)animated;
- (void)pazn_presentViewControllerIntact:(PAZNParams)params;

- (void)pazn_dismissViewController;
- (void)pazn_dismissViewControllerAnimated:(BOOL)animated;
- (void)pazn_dismissViewControllerAnimated:(BOOL)animated completion:(PAZNCompleteAction)completion;

+ (void)registerWithUrl:(NSString *)url viewControllerClass:(Class)cls;

@end

@interface UINavigationController (PAZNRoute)

- (void)removeViewControllerWithUrl:(NSString *)url;

- (Class)findViewControllerClassWithUrl:(NSString *)url;

- (BOOL)existViewControllerWithUrl:(NSString *)url;

- (UIViewController *)findViewControllerIfExistWithUrl:(NSString *)url;

- (void)deregisterUrl:(NSString *)url;

@end
