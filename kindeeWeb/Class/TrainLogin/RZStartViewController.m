//
//  RZStartViewController.m
//  kindeeWeb
//
//  Created by Guang on 2020/7/11.
//  Copyright © 2020 WDG. All rights reserved.
//

#import "RZStartViewController.h"
#import <YYKit.h>


@interface RZStartViewController ()<UIScrollViewDelegate>

@property (nonatomic ,strong) UIScrollView      *guideScrollView;

@property (nonatomic ,copy)   NSArray           *guideImageArr;

@property (nonatomic, strong) UIButton          *button ;

@property (nonatomic, strong) UIPageControl     *indexPage ;

@property (nonatomic, strong) UIButton          *nextBtn ;
@end

@implementation RZStartViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    self.navigationController.navigationBar.hidden = YES;
    
    [self initScrollView];

    // Do any additional setup after loading the view.
}



- (void)initScrollView{
    
    [self.view addSubview:self.guideScrollView];
   
//    [self.view addSubview:self.nextBtn];
   
    [self.view addSubview:self.indexPage];
    
    CGFloat  bottom = [TrainControllerUtil safeBottomHeight];
    
//    [self.nextBtn mas_makeConstraints:^(MASConstraintMaker *make) {
//
//        make.right.equalTo(self.view).offset(- 20);
//        make.top.equalTo(self.view).offset(  60);
//        make.width.height.mas_equalTo(40);
//    }];
    
    [self.indexPage mas_makeConstraints:^(MASConstraintMaker *make) {
          
        make.centerX.equalTo(self.view);
        make.bottom.equalTo(self.view).offset(- (bottom + 20));
        make.height.mas_equalTo(20);
    }];
    
    [self.guideScrollView mas_makeConstraints:^(MASConstraintMaker *make) {
       
        make.edges.equalTo(self.view).insets(UIEdgeInsetsMake(0 , 0, 0, 0));
        
    }];
     // 必须加个中间的过度页面 才可以
    UIView *containerView = [[UIView alloc]init];
    [self.guideScrollView addSubview:containerView];
    
    
    [containerView mas_makeConstraints:^(MASConstraintMaker *make) {
        make.edges.equalTo(self.guideScrollView);
        make.height.equalTo(self.guideScrollView);
    }];
    
    UIView  *lastView = nil;
    for (int  i = 0 ; i < self.guideImageArr.count ; i++) {
        
        UIImageView *imageView = [[UIImageView alloc]init];
        imageView.userInteractionEnabled = YES;
        imageView.contentMode = UIViewContentModeScaleAspectFit ;
        
//        imageView.backgroundColor = RZColorFromRGB(i * 50, i* 30, i * 40);
        NSString  *name = self.guideImageArr[i];
        
        imageView.image = [UIImage imageNamed:name];
        [containerView addSubview:imageView];
        
        
        if (i == self.guideImageArr.count - 1) {
            
            [imageView addSubview: self.button];
            [self.button  mas_makeConstraints:^(MASConstraintMaker *make) {
                CGFloat  off_y = bottom + 40 ;
                make.bottom.equalTo(imageView).offset(- off_y);
                make.centerX.equalTo(imageView);
                make.width.mas_equalTo(110);
                make.height.mas_equalTo(40);
            }];
            
        }
                
        [imageView mas_makeConstraints:^(MASConstraintMaker *make) {
            make.top.and.bottom.equalTo(containerView);
            make.width.equalTo(self.guideScrollView);
            
            if (lastView)
            {
                make.left.mas_equalTo(lastView.mas_right);
            }
            else
            {
                make.left.mas_equalTo(0);
            }
        }];
        lastView = imageView;
    }
    [containerView mas_makeConstraints:^(MASConstraintMaker *make) {
        make.right.mas_equalTo(lastView.mas_right);
    }];
}


- (void)scrollViewDidScroll:(UIScrollView *)scrollView{
    
    CGFloat  off_x = scrollView.contentOffset.x;
    
    NSInteger  index = off_x / kScreenWidth ;
    self.indexPage.currentPage = index ;

}

- (void)pushToLoginView{
    
    AppDelegate *app = (AppDelegate *)[UIApplication sharedApplication].delegate ;
    [app rzSetHomeView];
}



#pragma  mark -- setter or getter

- (UIScrollView *)guideScrollView{
    
    if (! _guideScrollView) {
        UIScrollView  *scrollView = [[UIScrollView alloc]init];
        scrollView.showsHorizontalScrollIndicator   = NO;
        scrollView.showsVerticalScrollIndicator     = NO;
        scrollView.pagingEnabled                    = YES;
        scrollView.bounces                          = NO;
        scrollView.delegate                         = self;
        scrollView.backgroundColor = [UIColor whiteColor];
        _guideScrollView = scrollView;
//        _guideScrollView.contentSize = CGSizeMake(kScreenWidth * self.guideImageArr.count + 1 , 0);
    }
    return _guideScrollView;
}

- (UIButton *)button {
    
    if (!_button) {
        
        UIButton  *btn = [[UIButton alloc]init];
        [btn  setTitle:@"立即进入" forState:UIControlStateNormal];
        [btn setTitleColor:[UIColor colorWithHexString:@"E85340"] forState:UIControlStateNormal];
        
        [btn addTarget:self action:@selector(pushToLoginView) forControlEvents:UIControlEventTouchUpInside];
        
        _button = btn;
    }
    return _button;
}

- (UIButton *)nextBtn {
    
    if (!_nextBtn) {
        
        UIButton  *btn = [[UIButton alloc]init];
        [btn setTitle:@"跳过" forState:UIControlStateNormal];
        [btn setBackgroundColor: [UIColor colorWithWhite:0.0 alpha:0.2]];
        
        [btn addTarget:self action:@selector(pushToLoginView) forControlEvents:UIControlEventTouchUpInside];

        
        _nextBtn = btn;
    }
    return _nextBtn;
}

- (UIPageControl *)indexPage {
    if (!_indexPage) {
        UIPageControl *page = [[UIPageControl alloc]init];
        page.userInteractionEnabled =  NO ;
        page.numberOfPages = self.guideImageArr.count ;
        page.pageIndicatorTintColor = [[UIColor colorWithHexString:@"#E85340"] colorWithAlphaComponent:0.5];
        page.currentPageIndicatorTintColor = [UIColor colorWithHexString:@"#E85340"];
        

        _indexPage = page ;
    }
    return _indexPage ;
}


- (NSArray *)guideImageArr{
    if (!_guideImageArr) {
        NSArray  *arr = @[@"app_welcom_1",@"app_welcom_2",@"app_welcom_3"];
        _guideImageArr = arr;
    }
    return _guideImageArr;
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
