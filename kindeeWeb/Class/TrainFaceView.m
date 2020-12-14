//
//  TrainFaceView.m
//  kindeeWeb
//
//  Created by Guang on 2020/11/28.
//  Copyright © 2020 WDG. All rights reserved.
//

#import "TrainFaceView.h"

#import "ASFCameraController.h"
#import "GLKitView.h"
#import "Utility.h"
#import "ASFVideoProcessor.h"
#import <ArcSoftFaceEngine/ArcSoftFaceEngine.h>

#import "UIImage+imageFace.h"


//当前屏幕宽高
#define kScreenWidth    ([UIScreen mainScreen].bounds.size.width)
#define kScreenHeight   ([UIScreen mainScreen].bounds.size.height)


float const ALERT_WIDTH              = 300.0f ;

@interface TrainFaceView ()<ASFCameraControllerDelegate, ASFVideoProcessorDelegate>
{
    
    BOOL    _isPhone;
}
@property (nonatomic, strong) UIView *contentBgView;

@property (nonatomic, strong) UILabel *titleLabel;

@property (nonatomic, strong) UIView *faceView;

@property (nonatomic, strong) UILabel *statusLabel;

@property (nonatomic, strong) UILabel *ddescLabel;

@property (nonatomic, strong) ASFCameraController* cameraController;

@property (nonatomic, strong) ASFVideoProcessor* videoProcessor;

@property (nonatomic, strong) NSMutableArray* arrayAllFaceRectView;

@property (strong, nonatomic) GLKitView *glView;


@property (nonatomic, strong) UIActivityIndicatorView  *actView;

@property (nonatomic, strong) NSString  *statusText;


@end


@implementation TrainFaceView



- (instancetype)init {
    
    self = [super init];
    if (self) {
        [self evAddSubview];
        [self evAddviewLayout];
        _isPhone = NO;
        
    }
    return self;
}

- (void)evAddSubview {
    
    [self addSubview:self.contentBgView];
    [self.contentBgView addSubview:self.titleLabel];
    [self.contentBgView addSubview:self.faceView];
    [self.contentBgView addSubview:self.statusLabel];
    [self.contentBgView addSubview:self.ddescLabel];
    
    [self.faceView addSubview:self.glView];
    [self.faceView addSubview:self.actView];
    
    self.backgroundColor = [[UIColor blackColor] colorWithAlphaComponent: 0.5];
    [self layoutIfNeeded];
    
    [self trainSetUpViewBorderLineView:self.faceView lineColor:UIColor.grayColor];
    
}

- (void)evAddviewLayout {
    
    self.frame = CGRectMake(0, 0, kScreenWidth, kScreenHeight);
    [self.contentBgView mas_remakeConstraints:^(MASConstraintMaker *make) {
        make.center.equalTo(self);
        make.width.mas_equalTo(ALERT_WIDTH);
    }];
    
    [self.titleLabel mas_remakeConstraints:^(MASConstraintMaker *make) {
        make.left.mas_equalTo(20);
        make.right.mas_equalTo(-20);
        make.top.mas_equalTo(20);
        make.height.mas_equalTo(40);
        
    }];
    
    [self.faceView mas_remakeConstraints:^(MASConstraintMaker *make) {
        make.centerX.mas_equalTo(self.contentBgView);
        make.top.mas_equalTo(self.titleLabel.mas_bottom).offset(20);
        make.width.height.mas_equalTo(200);
    }];
    
    [self.glView mas_remakeConstraints:^(MASConstraintMaker *make) {
        make.edges.equalTo(self.faceView);
    }];
    [self.actView mas_remakeConstraints:^(MASConstraintMaker *make) {
        make.center.equalTo(self.faceView);
        make.width.height.mas_equalTo(60);
    }];
    
    
    [self.statusLabel mas_remakeConstraints:^(MASConstraintMaker *make) {
        make.left.right.equalTo(self.titleLabel);
        make.top.mas_equalTo(self.faceView.mas_bottom).offset(20);
        make.height.mas_equalTo(30);
    }];
    
    [self.ddescLabel mas_remakeConstraints:^(MASConstraintMaker *make) {
        make.left.right.equalTo(self.titleLabel);
        make.top.equalTo(self.statusLabel.mas_bottom).offset(20);
        make.bottom.equalTo(self.contentBgView.mas_bottom).offset(-30);
    }];
}

- (void)evAddFaceConfig {
    
    UIInterfaceOrientation uiOrientation = [[UIApplication sharedApplication] statusBarOrientation];
    AVCaptureVideoOrientation videoOrientation = (AVCaptureVideoOrientation)uiOrientation;
    
    self.arrayAllFaceRectView = [NSMutableArray arrayWithCapacity:0];
    
    self.videoProcessor = [[ASFVideoProcessor alloc] init];
    self.videoProcessor.delegate = self;
    [self.videoProcessor initProcessor];
    
    self.cameraController = [[ASFCameraController alloc]init];
    self.cameraController.delegate = self;
    [self.cameraController setupCaptureSession:videoOrientation];
}


#pragma mark - Action
-(void)showFaceView {
    
    [[UIApplication sharedApplication].keyWindow addSubview:self];
    self.alpha = 0.0;
    [self evAddFaceConfig];
    [self.glView setNeedsDisplay ];
    [self.actView startAnimating];
    _isPhone = NO;
    [UIView animateWithDuration:.5  animations:^{
        self.alpha = 1;
    } completion:^(BOOL finished) {
        self.alpha = 1;
        [self.actView stopAnimating];
        [self resetFaceCheckStart];
    }];
}

-(void)dismissFaceView {
    
    [UIView animateWithDuration:.5 animations:^{
        self.alpha = 0.0;
    } completion:^(BOOL finished) {
        
        [self removeFromSuperview];
    }];
    _isPhone = NO;

    [self.cameraController stopCaptureSession];
    [self.videoProcessor uninitProcessor];
}
- (void)resetFaceCheck {
     _isPhone = NO;
    [self.cameraController startCaptureSession];
    self.statusText = @"检测失败,请重新检测...";
    dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(1.0 * NSEC_PER_SEC)), dispatch_get_main_queue(), ^{
        _isPhone = YES ;
        [self.actView stopAnimating];

    });
}

- (void)resetFaceCheckStart {
     _isPhone = NO;
    [self.cameraController startCaptureSession];
    self.statusText = @"正在检测...";
    dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(1.0 * NSEC_PER_SEC)), dispatch_get_main_queue(), ^{
        _isPhone = YES ;
        [self.actView stopAnimating];

    });
}

- (void)captureOutput:(AVCaptureOutput *)captureOutput didOutputSampleBuffer:(CMSampleBufferRef)sampleBuffer fromConnection:(AVCaptureConnection *)connection
{
    CVImageBufferRef cameraFrame = CMSampleBufferGetImageBuffer(sampleBuffer);
    ASF_CAMERA_DATA* cameraData = [Utility getCameraDataFromSampleBuffer:sampleBuffer];
    NSArray *arrayFaceInfo = [self.videoProcessor process:cameraData];
    dispatch_sync(dispatch_get_main_queue(), ^{
        [self.glView renderWithCVPixelBuffer:cameraFrame orientation:0 mirror:NO];
        for (NSUInteger face = 0; face < arrayFaceInfo.count; face++) {

            ASFVideoFaceInfo *faceInfo = [arrayFaceInfo objectAtIndex:face];
//            self.statusText = @"已检测到人脸,正在验证是否活体";
            if (faceInfo.liveness == 1 && _isPhone) {
                self.statusText = @"已检测到人脸,请等待...";
                CIImage *image = [CIImage imageWithCVPixelBuffer:cameraFrame];
                UIImage  *img = [UIImage imageWithCIImage:image];
                
                [self.actView startAnimating];
                [self.cameraController stopCaptureSession];
                dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(1.0 * NSEC_PER_SEC)), dispatch_get_main_queue(), ^{
                    [self evUploadIUseriMage:img];
                });
            
            }
        }
    });
    [Utility freeCameraData:cameraData];
}


- (void)evUploadIUseriMage:(UIImage *)image {
    
    if (image) {
        if (self.delegate && [self.delegate respondsToSelector:@selector(trainFacceInfo:)]) {
            [self.delegate trainFacceInfo:image];
        }
    }
    
}



#pragma mark - AFVideoProcessorDelegate
- (void)processRecognized:(NSString *)personName
{
    NSString *result = [NSString stringWithFormat:@"%@%@", @"比对结果：", personName];
}

- (void)trainSetUpViewBorderLineView:(UIView *)view  lineColor:(UIColor *)color {
    
    if (view) {
        view.layer.borderColor = color.CGColor;
        view.layer.borderWidth = 4.0f;
    }
}


- (void)setStatusText:(NSString *)statusText {
    _statusText = statusText ;
    self.statusLabel.text = statusText ;
}
- (UIView *)contentBgView {
    if (!_contentBgView) {
        UIView *view = [[UIView alloc]init];
        view.backgroundColor = [UIColor whiteColor];
        view.layer.cornerRadius = 20.0f;
        
        _contentBgView = view;
    }
    return _contentBgView;
}

- (UILabel *)titleLabel {
    if (!_titleLabel) {
        UILabel *label = [[UILabel alloc]init];
        label.text = @"人脸识别验证";
//        label.textColor =
        label.font = [UIFont systemFontOfSize:20.f weight:UIFontWeightMedium];
        label.textAlignment = NSTextAlignmentCenter;
        _titleLabel = label;
    }
    return _titleLabel
    ;
}

- (UIView *)faceView {
    if (!_faceView) {
        UIView *view = [[UIView alloc]init];
        view.backgroundColor = [UIColor whiteColor];
        view.layer.cornerRadius = 100.0f;
        view.layer.masksToBounds = YES;
        _faceView = view;
    }
    return _faceView;
}

- (GLKitView *)glView {
    if (!_glView) {
        GLKitView *view = [[GLKitView alloc]init];
        
        _glView =view;
    }
    return _glView;
}

- (UILabel *)statusLabel {
    if (!_statusLabel) {
        UILabel *label = [[UILabel alloc]init];
//        label.text = @"正在检测...";
//        label.textColor =
        label.font = [UIFont systemFontOfSize:13.f];
        label.textAlignment = NSTextAlignmentCenter;
        _statusLabel = label;
    }
    return _statusLabel;
}

- (UILabel *)ddescLabel {
    if (!_ddescLabel) {
        UILabel *label = [[UILabel alloc]init];
        label.text = @"请在安静、明亮的环境下操作,并确保正脸水平面对屏幕";
//        label.textColor =
        label.font = [UIFont systemFontOfSize:13.f];
        label.textAlignment = NSTextAlignmentCenter;
        label.numberOfLines = 0 ;
        _ddescLabel = label;
    }
    return _ddescLabel;
}

- (UIActivityIndicatorView *)actView {
    if (!_actView) {
        if (@available(iOS 13.0, *)) {
            UIActivityIndicatorView *view = [[UIActivityIndicatorView alloc]initWithActivityIndicatorStyle:UIActivityIndicatorViewStyleLarge];
            
            _actView = view ;
        } else {
            UIActivityIndicatorView *view = [[UIActivityIndicatorView alloc]initWithActivityIndicatorStyle:UIActivityIndicatorViewStyleWhiteLarge];
            _actView = view ;
            // Fallback on earlier versions
        }
    }
    return _actView;
}

/*
// Only override drawRect: if you perform custom drawing.
// An empty implementation adversely affects performance during animation.
- (void)drawRect:(CGRect)rect {
    // Drawing code
}
*/

@end
