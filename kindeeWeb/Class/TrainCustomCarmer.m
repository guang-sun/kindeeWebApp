//
//  TrainCustomCarmer.m
//  kindeeWeb
//
//  Created by Guang on 2020/7/4.
//  Copyright © 2020 WDG. All rights reserved.
//

#import "TrainCustomCarmer.h"

//#import "UIImage+DJResize.h"

@interface TrainCustomCarmer () <CAAnimationDelegate ,AVCapturePhotoCaptureDelegate >
/// 捕获设备，通常是前置摄像头，后置摄像头，麦克风（音频输入）
@property (nonatomic, strong) AVCaptureDevice *device;
/// AVCaptureDeviceInput 代表输入设备，他使用AVCaptureDevice 来初始化
@property (nonatomic, strong) AVCaptureDeviceInput *input;
/// 输出图片
@property (nonatomic ,strong) AVCapturePhotoOutput *imageOutput;
/// session：由他把输入输出结合在一起，并开始启动捕获设备（摄像头）
@property (nonatomic, strong) AVCaptureSession *session;
/// 图像预览层，实时显示捕获的图像
@property (nonatomic ,strong) AVCaptureVideoPreviewLayer *previewLayer;
/// 切换前后镜动画结束之后
@property (nonatomic, copy) void (^finishBlock)(void);

@property (nonatomic, copy) trainTakePhotoBlock  photoBlock;

@end

@implementation TrainCustomCarmer

#pragma mark - 初始化
- (instancetype)init
{
    self = [super init];
    if (self) {
        [self setup];
    }
    return self;
}

- (instancetype)initWithParentView:(UIView *)view
{
    self = [super init];
    if (self) {
       [self setup];
        [self configureWithParentLayer:view];
    }
   return self;
}

#pragma mark - 布置UI
- (void)setup
{
    self.session = [[AVCaptureSession alloc] init];
    self.previewLayer = [[AVCaptureVideoPreviewLayer alloc] initWithSession:self.session];
    self.previewLayer.videoGravity = AVLayerVideoGravityResizeAspectFill;
    //加入输入设备（前置或后置摄像头）
    [self addVideoInputFrontCamera:AVCaptureDevicePositionFront];
    //加入输出设备
    [self addStillImageOutput];

}

 /**
 *  添加输入设备
 *
  *  @param position 前或后摄像头
 */
- (void)addVideoInputFrontCamera:(AVCaptureDevicePosition )position {
    
    AVCaptureDeviceDiscoverySession *deviceSession = [AVCaptureDeviceDiscoverySession discoverySessionWithDeviceTypes:@[AVCaptureDeviceTypeBuiltInWideAngleCamera] mediaType:AVMediaTypeVideo position:position] ;
    NSArray *devices = deviceSession.devices;
    if (devices.count > 0) {
        
        self.device  = devices.firstObject ;
        NSError *error = nil;

        AVCaptureDeviceInput *frontFacingCameraDeviceInput =
        [AVCaptureDeviceInput deviceInputWithDevice:self.device error:&error];
        if (!error) {
            if ([_session canAddInput:frontFacingCameraDeviceInput]) {
                [_session addInput:frontFacingCameraDeviceInput];
                self.input = frontFacingCameraDeviceInput;
            } else {
                NSLog(@"Couldn't add front facing video input");
            }
        }else{
            NSLog(@"你的设备没有照相机");
        }
        
    }else {
        NSLog(@"你的设备没有照相机");
        
    }
}

/**
 *  添加输出设备
 */
- (void)addStillImageOutput
{
    AVCapturePhotoOutput *tmpOutput = [[AVCapturePhotoOutput alloc] init];
    NSDictionary *outputSettings = [[NSDictionary alloc] initWithObjectsAndKeys:AVVideoCodecJPEG,AVVideoCodecKey,nil];//输出jpeg
    AVCapturePhotoSettings  *setting = [AVCapturePhotoSettings photoSettingsWithFormat:outputSettings];
    [tmpOutput setPreparedPhotoSettingsArray: @[setting] completionHandler:nil];
//    tmpOutput.outputSettings = outputSettings;
    if ([self.session canAddOutput:tmpOutput]) {
        [_session addOutput:tmpOutput];
    }
    _session.sessionPreset = AVCaptureSessionPreset640x480 ;
    [_session commitConfiguration];
    self.imageOutput = tmpOutput;
    
}

  - (void)configureWithParentLayer:(UIView *)parent
{
  parent.userInteractionEnabled = YES;

  if (!parent) {
//      [XHToast showCenterWithText:@"请加入负载视图"];
      return;
  }
    self.previewLayer.frame = parent.bounds;
    [parent.layer addSublayer:self.previewLayer];

    
}

#pragma mark - 切换闪光灯模式（切换顺序：最开始是auto，然后是off，最后是on，一直循环）
- (void)switchFlashMode:(UIButton*)sender{

    Class captureDeviceClass = NSClassFromString(@"AVCaptureDevice");
    if (!captureDeviceClass) {
//        [XHToast showCenterWithText:@"您的设备没有拍照功能"];
  
  return;
    }
    NSString *imgStr = @"";
    AVCaptureDevice *device = [AVCaptureDevice defaultDeviceWithMediaType:AVMediaTypeVideo];
    [device lockForConfiguration:nil];
    if ([device hasFlash]) {
        if (device.flashMode == AVCaptureFlashModeOff) {
            device.flashMode = AVCaptureFlashModeOn;
            imgStr = @"flashing_on.png";
      
  } else if (device.flashMode == AVCaptureFlashModeOn) {
      device.flashMode = AVCaptureFlashModeAuto;
      imgStr = @"flashing_auto.png";
      
 } else if (device.flashMode == AVCaptureFlashModeAuto) {
      device.flashMode = AVCaptureFlashModeOff;
      imgStr = @"flashing_off.png";
  }
  if (sender) {
      [sender setImage:[UIImage imageNamed:imgStr] forState:UIControlStateNormal];
  }
    } else {
//        [XHToast showCenterWithText:@"您的设备没有闪光灯功能"];
  }
  [device unlockForConfiguration];
}

/**
 *  前后镜
 *
 *  isFrontCamera
 */
- (void)switchCamera:(BOOL)isFrontCamera didFinishChanceBlock:(void(^)(id))block;
{
    if (!_input) {
  
    if (block) {
      block(@"");
  }
//  [XHToast showCenterWithText:@"您的设备没有摄像头"];

  return;
    }
    if (block) {
  self.finishBlock = [block copy];
    }
  CABasicAnimation *caAnimation = [CABasicAnimation animationWithKeyPath:@"opacity"];
  //    caAnimation.removedOnCompletion = NO;
  //    caAnimation.fillMode = kCAFillModeForwards;
  caAnimation.fromValue = @(0);
  caAnimation.toValue = @(M_PI);
  caAnimation.duration = 1.f;
  caAnimation.repeatCount = 1;
  caAnimation.delegate = self;
  caAnimation.timingFunction = [CAMediaTimingFunction functionWithName:kCAMediaTimingFunctionDefault];
  [self.previewLayer addAnimation:caAnimation forKey:@"anim"];


     dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0), ^{
      [self.session beginConfiguration];
      [self.session removeInput:self.input];
    //  [self addVideoInputFrontCamera:isFrontCamera];
      [self.session commitConfiguration];

      dispatch_async(dispatch_get_main_queue(), ^{
          
            });
        });
    }

- (void)startCapRuning  {
    if (!self.session.isRunning) {
        [self.session startRunning];
    }
}

- (void)stopCapRuning  {
  if (self.session.isRunning) {
        [self.session stopRunning];
  }
}

- (void)animationDidStop:(CAAnimation *)anim finished:(BOOL)flag
{
    if (self.finishBlock) {
        self.finishBlock();
    }
}
/**
 *  拍照
 *
 *  @param block
 */
- (void)takePhotoWithImageBlock:(trainTakePhotoBlock )block {
    AVCapturePhotoSettings  *setting = [[AVCapturePhotoSettings alloc]init ];
    setting.flashMode =  AVCaptureFlashModeOff ;

    self.photoBlock = block ;
     AVCaptureConnection *captureConnection = [self.imageOutput connectionWithMediaType:AVMediaTypeVideo];
    if (!captureConnection) {
        return;
    }
    
    AVCaptureDevicePosition currentPosition=[self.device position];
    if (currentPosition == AVCaptureDevicePositionUnspecified || currentPosition == AVCaptureDevicePositionFront) {
         captureConnection.videoMirrored = YES;
    } else {
         captureConnection.videoMirrored = NO;
    }
    captureConnection.videoOrientation =  AVCaptureVideoOrientationPortrait ;//self.evGetVideoOrientation ;
     [self.imageOutput capturePhotoWithSettings:setting delegate:self];
    
 
}

- (AVCaptureVideoOrientation )evGetVideoOrientation {
    
    UIDeviceOrientation devOri = UIDevice.currentDevice.orientation ;
    UIInterfaceOrientation deviceOrientation = [[UIApplication sharedApplication] statusBarOrientation];

    AVCaptureVideoOrientation orint ;
    switch (devOri) {
        case UIDeviceOrientationPortrait:  UIDeviceOrientationFaceUp : UIDeviceOrientationFaceDown:
            orint = AVCaptureVideoOrientationPortrait ;
            break;
        case UIDeviceOrientationPortraitUpsideDown:
            orint = AVCaptureVideoOrientationPortrait ;
            break;
        case UIDeviceOrientationLandscapeLeft:
            orint = AVCaptureVideoOrientationLandscapeRight ;
            break;
        case UIDeviceOrientationLandscapeRight:
            orint = AVCaptureVideoOrientationLandscapeLeft ;
            break;
        default:
            orint = AVCaptureVideoOrientationPortrait ;

            break;
    }
    
    return  orint;;
    
}

/**
  *  查找摄像头连接设备
 *
*
  */
- (AVCaptureConnection *)findVideoConnection
{
      AVCaptureConnection *videoConnection = nil;
      for (AVCaptureConnection *connection in _imageOutput.connections) {
          for (AVCaptureInputPort *port in connection.inputPorts) {
              if ([[port mediaType] isEqual:AVMediaTypeVideo]) {
                  videoConnection = connection;
                  break;
              }
          }
          if (videoConnection) {
              break;
          }
      }
      return videoConnection;
}

- (void)captureOutput:(AVCapturePhotoOutput *)captureOutput didFinishProcessingPhotoSampleBuffer:(nullable CMSampleBufferRef)photoSampleBuffer previewPhotoSampleBuffer:(nullable CMSampleBufferRef)previewPhotoSampleBuffer resolvedSettings:(AVCaptureResolvedPhotoSettings *)resolvedSettings bracketSettings:(nullable AVCaptureBracketedStillImageSettings *)bracketSettings error:(nullable NSError *)error{
    NSData *imageData = [AVCapturePhotoOutput  JPEGPhotoDataRepresentationForJPEGSampleBuffer:photoSampleBuffer previewPhotoSampleBuffer:previewPhotoSampleBuffer];
    UIImage *image = [self fixOrientation:[UIImage imageWithData:imageData]];
    self.photoBlock(image);
//    self.photoShowView.image = [UIImage imageWithData:imageData];
//    [self.captureSession stopRunning];
    
}
- (void)captureOutput:(AVCapturePhotoOutput *)output didFinishProcessingPhoto:(AVCapturePhoto *)photo error:(NSError *)error  API_AVAILABLE(ios(11.0)){
        if (error != nil) {
        NSLog(@"huqu图片error=%@", error.localizedDescription);
       }
    NSData  *imageData = photo.fileDataRepresentation ;
    
    UIImage *image = [self fixOrientation:[UIImage imageWithData:imageData]];
    
//    CGImageRef  imageRef =  [UIImage imageWithData:imageData].CGImage ;
//    UIImage  *image ;
//    if (self.device.position == AVCaptureDevicePositionFront) {
//        image = [UIImage imageWithCGImage:imageRef scale:1 orientation:UIImageOrientationRightMirrored];
//    }else {
//        image = [UIImage imageWithCGImage:imageRef scale:1 orientation:UIImageOrientationRight];
//    }
    self.photoBlock(image);
 
}

- (void)captureOutput:(AVCapturePhotoOutput *)output willCapturePhotoForResolvedSettings:(AVCaptureResolvedPhotoSettings *)resolvedSettings{
   /// 释放声音
   AudioServicesDisposeSystemSoundID(1108);
}

- (void)captureOutput:(AVCapturePhotoOutput *)output
didCapturePhotoForResolvedSettings:(AVCaptureResolvedPhotoSettings *)resolvedSettings {
    
    
}

- (UIImage *)fixOrientation:(UIImage *)aImage {
      
    // No-op if the orientation is already correct
    if (aImage.imageOrientation == UIImageOrientationUp)
        return aImage;
      
    // We need to calculate the proper transformation to make the image upright.
    // We do it in 2 steps: Rotate if Left/Right/Down, and then flip if Mirrored.
    CGAffineTransform transform = CGAffineTransformIdentity;
      
    switch (aImage.imageOrientation) {
        case UIImageOrientationDown:
        case UIImageOrientationDownMirrored:
            transform = CGAffineTransformTranslate(transform, aImage.size.width, aImage.size.height);
            transform = CGAffineTransformRotate(transform, M_PI);
            break;
              
        case UIImageOrientationLeft:
        case UIImageOrientationLeftMirrored:
            transform = CGAffineTransformTranslate(transform, aImage.size.width, 0);
            transform = CGAffineTransformRotate(transform, M_PI_2);
            break;
              
        case UIImageOrientationRight:
        case UIImageOrientationRightMirrored:
            transform = CGAffineTransformTranslate(transform, 0, aImage.size.height);
            transform = CGAffineTransformRotate(transform, -M_PI_2);
            break;
        default:
            break;
    }
      
    switch (aImage.imageOrientation) {
        case UIImageOrientationUpMirrored:
        case UIImageOrientationDownMirrored:
            transform = CGAffineTransformTranslate(transform, aImage.size.width, 0);
            transform = CGAffineTransformScale(transform, -1, 1);
            break;
              
        case UIImageOrientationLeftMirrored:
        case UIImageOrientationRightMirrored:
            transform = CGAffineTransformTranslate(transform, aImage.size.height, 0);
            transform = CGAffineTransformScale(transform, -1, 1);
            break;
        default:
            break;
    }
      
    // Now we draw the underlying CGImage into a new context, applying the transform
    // calculated above.
    CGContextRef ctx = CGBitmapContextCreate(NULL, aImage.size.width, aImage.size.height,
                                             CGImageGetBitsPerComponent(aImage.CGImage), 0,
                                             CGImageGetColorSpace(aImage.CGImage),
                                             CGImageGetBitmapInfo(aImage.CGImage));
    CGContextConcatCTM(ctx, transform);
    switch (aImage.imageOrientation) {
        case UIImageOrientationLeft:
        case UIImageOrientationLeftMirrored:
        case UIImageOrientationRight:
        case UIImageOrientationRightMirrored:
            // Grr...
            CGContextDrawImage(ctx, CGRectMake(0,0,aImage.size.height,aImage.size.width), aImage.CGImage);
            break;
              
        default:
            CGContextDrawImage(ctx, CGRectMake(0,0,aImage.size.width,aImage.size.height), aImage.CGImage);
            break;
    }
      
    // And now we just create a new UIImage from the drawing context
    CGImageRef cgimg = CGBitmapContextCreateImage(ctx);
    UIImage *img = [UIImage imageWithCGImage:cgimg];
    CGContextRelease(ctx);
    CGImageRelease(cgimg);
    return img;
}

@end
