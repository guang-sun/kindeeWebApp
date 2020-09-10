//
//  PALYEmptySet.h
//  Pods
//
//  Created by wans on 2017/9/11.
//
//

#import <UIKit/UIKit.h>

@interface UIScrollView (PALYEmptySet)

@property (nonatomic, assign) BOOL           pazn_emptyDefaultEnable; //!< 是否开启默认占位图

@property (nonatomic, strong) NSString       *pazn_emptyTitle; //!< 占位文字

@property (nonatomic, strong) NSString       *pazn_emptyBtnText; //!< 网络异常时按钮上面文字显示

@property (nonatomic, strong) NSString       *pazn_emptyBtnTitle; //!< 网络异常时按钮文字

@property (nonatomic, strong) UIImage        *pazn_emptyBtnImage; //!< 网络异常按钮图片

@property (nonatomic, strong) UIFont         *pazn_emptyTitleFont; //!< 占位文字字体

@property (nonatomic, strong) UIColor        *pazn_emptyTitleColor; //!< 占位文字颜色

@property (nonatomic, strong) UIColor        *pazn_emptyBtnColor; //!< 网络异常时按钮文字颜色

@property (nonatomic, strong) UIFont         *pazn_emptyBtnFont; //!< 网络异常时按钮文字字体

@property (nonatomic, strong) UIImage        *pazn_emptyImage; //!< 占位图片

@property (nonatomic, assign) CGFloat        pazn_emptySpace; //!< 占位图片与文字距离

@property (nonatomic, assign) CGFloat        pazn_emptyOffset; //!< 占位控件竖向偏移距离

@property (nonatomic, assign) BOOL           pazn_emptyHidden; //!< 占位控件是否显示（默认不显示）

@property (nonatomic, assign) BOOL           pazn_emptyAllowScroll; //!< 占位控件是否可以滑动

@property (nonatomic, assign) CGSize         pazn_emptyBtnSize; //!< 网络异常时按钮的大小


@property (nonatomic, assign) BOOL           pazn_emptyIsError; //!< 网络是否正常

@property (nonatomic, copy)                  void (^pazn_emptyBtnAction)(void); //!< 无网络时按钮的点击事件

@property (nonatomic, copy)                  void (^pazn_emptyErrorBtn)(UIButton *button); //!< 无网络时按钮

@property (nonatomic, strong) UIView         *pazn_emptyCustomView; //!< 自定义view

@property (nonatomic, strong) NSAttributedString       *pazn_emptyAttributedTitle; //!< 占位富文本

@end

@interface UITableView (PALYEmptySet)

- (void)pazn_emptyUpdate;

@end

@interface UICollectionView (PALYEmptySet)

- (void)pazn_emptyUpdate;

@end
