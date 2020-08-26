//
//  RZBaseViewController.m
//  YGProject
//
//  Created by admin on 2017/10/30.
//  Copyright © 2017年 YG. All rights reserved.
//

#import "RZBaseViewController.h"

@interface RZBaseViewController ()

@property (nonatomic, assign) UIStatusBarStyle statusBarStyle;

@property (nonatomic, assign) BOOL statusBarHidden;

@end

@implementation RZBaseViewController

-(void) viewWillAppear:(BOOL)animated
{
    [super viewWillAppear:animated];
//    self.navBarAlpha = @"1.0";
    [[UINavigationBar appearance] setShadowImage:[[UIImage alloc] init]];

//    [RZAnalyticsManager rz_trackPageBegin:NSStringFromClass([self class])];
   
}

-(void) viewWillDisappear:(BOOL)animated
{
    [super viewWillDisappear:animated];
    
//    [RZAnalyticsManager rz_trackPageEnd:NSStringFromClass([self class])];
}


- (void)viewDidLoad {
    
    [super viewDidLoad];
    self.navigationController.navigationBar.translucent = NO;
    self.navigationController.interactivePopGestureRecognizer.enabled = YES;
    self.automaticallyAdjustsScrollViewInsets = NO;

    if (@available(iOS 11.0, *)) {
      self.navigationController.navigationBar.prefersLargeTitles = YES;
      self.navigationItem.largeTitleDisplayMode = UINavigationItemLargeTitleDisplayModeNever;
        
    }
//    if (@available(iOS 13.0, *)) {
//        self.navigationController.navigationBar.standardAppearance.largeTitleTextAttributes =  @{NSForegroundColorAttributeName:kNavbarTitleColor,NSFontAttributeName:[UIFont boldSystemFontOfSize:23.f]};
//   } else {
//       // Fallback on earlier versions
//   }
    self.view.backgroundColor = [UIColor whiteColor];
    
    [self evInitNavgation];
    [self evAddSubviews];
    [self evGetNewData];
    [self evBindViewModel];
    [self evAddLayout];
    
}

/* 添加控件 */
- (void)evAddSubviews {}

/* 添加布局 */
- (void)evAddLayout{}

/* 绑定 */
- (void)evBindViewModel {}

/* 设置navation */
- (void)evInitNavgation {}

/* 初次获取数据 */
- (void)evGetNewData {}




#pragma mark - 修改statusbar
- (void)changeStatusBarStyle:(UIStatusBarStyle)statusBarStyle
             statusBarHidden:(BOOL)statusBarHidden
     changeStatusBarAnimated:(BOOL)animated
{
    self.statusBarStyle     = statusBarStyle;
    self.statusBarHidden    = statusBarHidden;
    if (animated) {
        [UIView animateWithDuration:0.25 animations:^{
            [self setNeedsStatusBarAppearanceUpdate];
        }];
    }
    else{
        [self setNeedsStatusBarAppearanceUpdate];
    }
}


#pragma mark - system
- (UIStatusBarStyle)preferredStatusBarStyle
{
    if (self.statusBarStyle) {
        
        return self.statusBarStyle;
    } else {
        
        return UIStatusBarStyleDefault;
    }
}

- (BOOL)prefersStatusBarHidden {
    
    return self.statusBarHidden;
}



-(void)dealloc{
    
    NSLog (@"---dealloc ---%@----",[self class]);
}

- (void)evGotoLoginView  {
 
//    UIViewController  *loginVC = [[NSClassFromString(@"EVLoginViewController") alloc]init];
//    RZBaseNavigationController *nav = [[RZBaseNavigationController alloc]initWithRootViewController:loginVC];
//    [self presentViewController:nav animated:YES completion:^{
//
//    }];
    
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
