//
//  RZBaseNavigationController.m
//  PandaCar
//
//  Created by Year on 2017/11/20.
//  Copyright © 2017年 RoZSoft. All rights reserved.
//

#import "RZBaseNavigationController.h"
#import <YYKit.h>

@interface RZBaseNavigationController ()

@property (nonatomic, strong) UIButton *backButton;

@end

@implementation RZBaseNavigationController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    [self config];
}

- (void)config {
    
    //导航主题（系统自带的主题样式）
//    self.navigationBar.barStyle = UIBarStyleDefault;
    //导航颜色
    [[UINavigationBar appearance] setTranslucent:NO];

    UIColor *color  =  [UIColor colorWithHexString:@"#e8e8e8"];
//    UIColor *color  =  [UIColor colorWithRed:190/255.0 green:41/255.0 blue:28/255.0 alpha:1];
//    UIColor *textcolor  =  [UIColor colorWithHexString:@"ffffff"];
    UIColor *textcolor  =  [UIColor colorWithHexString:@"333333"];

    UINavigationBar *navigationBar = [UINavigationBar appearance];
    [navigationBar setBarTintColor:color];
    [navigationBar setTintColor:textcolor];
    [navigationBar setBackgroundColor:color];
   
    NSMutableDictionary  *keyDic = [NSMutableDictionary dictionary];
    [keyDic setObject:[UIFont systemFontOfSize:17.0f] forKey:NSFontAttributeName];
    [keyDic setObject:textcolor forKey:NSForegroundColorAttributeName];
    [navigationBar setTitleTextAttributes:keyDic];
  
    NSMutableDictionary  *largeDic = [NSMutableDictionary dictionary];
    [largeDic setObject:[UIFont systemFontOfSize:23.f weight:UIFontWeightSemibold] forKey:NSFontAttributeName];
    [largeDic setObject:textcolor forKey:NSForegroundColorAttributeName];
    
    if (@available(iOS 13.0, *)) {
        
        navigationBar.standardAppearance.largeTitleTextAttributes = largeDic;
        navigationBar.standardAppearance.backgroundColor = color;
                 
    } else if (@available(iOS 11.0, *)) {
      
        [navigationBar setLargeTitleTextAttributes:largeDic];
        navigationBar.backgroundColor = color;
    }
 
    // 去除x底下的黑线
    navigationBar.shadowImage = [UIImage new] ;

}

- (void)pushViewController:(UIViewController *)viewController animated:(BOOL)animated {

    if (self.viewControllers.count > 0 ) {

        viewController.hidesBottomBarWhenPushed = YES;
        [viewController.navigationItem setHidesBackButton:YES];

        UIBarButtonItem *item = [[UIBarButtonItem alloc] initWithCustomView:self.backButton];

        if (self.noBackButtonVC &&
            [viewController isKindOfClass:[self.noBackButtonVC class]]) {

            [viewController.navigationItem setHidesBackButton:YES];

        } else {

            viewController.navigationItem.leftBarButtonItem = item;
        }
    }
    [super pushViewController:viewController animated:animated];

}


- (void)backMethod {
    
    if (self.baseDelegate &&
        [self.baseDelegate respondsToSelector:@selector(backClick)]) {
        [self.baseDelegate backClick];
    } else {
       [self popViewControllerAnimated:YES];
    }
}

- (UIButton *)backButton {
    
    if (_backButton == nil) {
        _backButton = [UIButton buttonWithType:UIButtonTypeCustom];
        _backButton.frame = CGRectMake(0, 0, 300, 44);
//        _backButton.backgroundColor = [UIColor redColor];
        _backButton.contentHorizontalAlignment = UIControlContentHorizontalAlignmentLeft;
        [_backButton addTarget:self
                        action:@selector(backMethod)
              forControlEvents:UIControlEventTouchUpInside];
        _backButton.tag = 99;
        [_backButton setImage:[UIImage imageNamed:@"nav_button_fanhui_2_default"] forState:UIControlStateNormal];
    }
    return _backButton;
}

- (UIStatusBarStyle)preferredStatusBarStyle {

    return UIStatusBarStyleDefault;
}

/**
 在navigationController中重写该方法，再在子页面中调用preferredStatusBarStyle，即可修改状态栏系统样式
 
 @return 一个可为空的视图
 */
- (nullable UIViewController *)childViewControllerForStatusBarStyle {
    return self.topViewController;
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

/*
#pragma mark - Navigation

// In a storyboard-based application, you will often want to do a little preparation before navigation
- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender {
    // Get the new view controller using [segue destinationViewController].
    // Pass the selected object to the new view controller.
}
*/

@end
