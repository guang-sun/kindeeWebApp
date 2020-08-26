//
//  PATransparentNavigationBar.h
//  自定义透明度渐变导航栏
//
//  Created by wans on 16/6/6.
//  Copyright © 2016年 QuanYan. All rights reserved.
//

#import <UIKit/UIKit.h>

@protocol PATransparentShowDelegate <NSObject>
/**
 *  可选
 */
- (void) pa_TransparentNavigationWillShow:(BOOL)show;

@optional

@end

typedef void (^PATNButtonItemsActionBlock)(NSInteger itemIndex);

NS_ASSUME_NONNULL_BEGIN
@interface PATransparentNavigationBar : UIView
//标题
@property (nonatomic, strong) NSString                    *title;
//标题颜色 默认黑色
@property (nonatomic, strong) UIColor                     *titleColor;
//导航栏颜色 默认系统导航栏颜色
@property (nonatomic, strong) UIColor                     *bgColor;
//返回按钮
@property (nonatomic, strong) UIButton                    *backButton;

//透明时按钮着色
@property (nonatomic, strong) UIColor                     *tintOpaqueColor;
//非透明时按钮着色
@property (nonatomic, strong) UIColor                     *tintNormalColor;

/**
 自定义标题视图
 */
@property (nonatomic, strong) UIView                      *titleView;

/**
 *  title不跟随偏移透明度渐变，默认为no
 */
@property (nonatomic, assign) BOOL                        titleAlwaysShow;

@property (nonatomic, weak) id<PATransparentShowDelegate> delegate;

/**
 *  根据tag获取button
 */
@property (nonatomic,copy) UIButton *(^indexButton)(NSInteger tag);
/**
 *  根据 changeBarStatus  记录时候改变状态改变,默认是no
 */
@property (nonatomic, assign) BOOL                        changeBarStatus;

/**
 顶端忽略距离
 */
@property (nonatomic, assign) CGFloat                     ignoreOffsetTop;

/**
 是否隐藏底部分割线
 */
@property (nonatomic, assign) BOOL                        isHideBottomLine;

/**
 *  初始化自定义导航栏
 *
 *  @param title      导航栏标题
 *  @param tableView  绑定tableview，滑动设置导航栏透明
 *  @param backAction 绑定返回事件
 *  @param backImage  图片
 *
 *  @return 导航栏实例
 */
- (instancetype)initWithTitle:(NSString *)title bindTableView:(UITableView *)tableView backAction:(void(^)(NSInteger index))backAction backImage:(UIImage *)backImage;
- (instancetype)initWithTitle:(NSString *)title bindTableView:(nullable UITableView *)tableView backAction:(nullable void(^)(NSInteger index))backAction;
- (instancetype)initWithTitle:(NSString *)title backImage:(UIImage *)backImage backAction:(void(^)(NSInteger index))backAction;
- (instancetype)initWithTitle:(NSString *)title backImage:(UIImage *)backImage;
- (instancetype)initWithTitle:(NSString *)title;

/**
 *  绑定tableview
 *
 *  @param tableView  列表
 *  @param backAction 返回事件
 */
- (void)bindTableView:(UITableView *)tableView backAction:(void(^)(NSInteger))backAction;

/**
 *  添加右部按钮
 *
 *  @param imagesArray         透明时按钮图片数组
 *  @param opacitasImagesArray 不透明按钮图片数组
 *  @param block               按钮点击事件
 */
- (void)setRightButtonItemsWithImages:(NSArray<UIImage *> *)imagesArray opacitasImages:(nullable NSArray<UIImage *> *)opacitasImagesArray actionBlock:(PATNButtonItemsActionBlock)block;
- (void)setRightButtonItemsWithImages:(NSArray<UIImage *> *)imagesArray actionBlock:(PATNButtonItemsActionBlock)block;
- (void)setRightButtonItemsWithTitles:(NSArray<NSString *> *)titlesArray actionBlock:(PATNButtonItemsActionBlock)block;

- (void)setLeftButtonWithImage:(UIImage *)leftImage actionBlock:(PATNButtonItemsActionBlock)block;

@end
NS_ASSUME_NONNULL_END
