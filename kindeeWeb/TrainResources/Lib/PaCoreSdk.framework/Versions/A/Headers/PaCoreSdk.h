//
//  PaCoreSdk.h
//  PaCoreSdk
//
//  Created by Cyril Zhou on 2017/3/2.
//  Copyright © 2017年 Cyril Zhou. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

#import <PaCoreSdk/PACoreSdkConstants.h>
#import <PaCoreSdk/PAWeakSelfDefine.h>
#import <PaCoreSdk/PACoreResourcesMacro.h>
#import <PaCoreSdk/PAZNLogDef.h>
#import <PaCoreSdk/PADeviceInfo.h>

//日志
#import <PaCoreSdk/PAZNLog.h>
#import <PaCoreSdk/PAZNData.h>
#import <PaCoreSdk/PAZNNumber.h>
#import <PaCoreSdk/PAZNRange.h>
#import <PaCoreSdk/PAZNAbstractDatabaseLogger.h>
#import <PaCoreSdk/PAZNASLLogger.h>
#import <PaCoreSdk/PAZNContextFilterLogFormatter.h>
#import <PaCoreSdk/PAZNDispatchQueueLogFormatter.h>
#import <PaCoreSdk/PAZNFileLogger.h>
#import <PaCoreSdk/PAZNTTYLogger.h>
#import <PaCoreSdk/PAZNASLLogCapture.h>
#import <PaCoreSdk/PAZNMultiFormatter.h>
#import <PaCoreSdk/PAZNAssertMacros.h>
#import <PaCoreSdk/PAZNOSLogger.h>
#import <PaCoreSdk/PAZNLog+LOGV.h>
#import <PaCoreSdk/PAZNCLIColor.h>

//网络
#import <PaCoreSdk/PAZNNetworkHelper.h>
#import <PaCoreSdk/PAZNAFNetworking.h>
#import <PaCoreSdk/PAZNBaseRequest.h>
#import <PaCoreSdk/PAZNFileTransTask.h>
#import <PaCoreSdk/PAZNFileTransManager.h>
#import <PaCoreSdk/PAZNModel.h>
#import <PaCoreSdk/PAZNCache.h>
#import <PaCoreSdk/PAZNAFNetworkActivityIndicatorManager.h>
#import <PaCoreSdk/PAZNWebView.h>
#import <PaCoreSdk/PAZNWebViewProgress.h>
#import <PaCoreSdk/PAZNEtcHostsURLProtocol.h>
#import <PaCoreSdk/PAHttpManager.h>

//数据库
#import <PaCoreSdk/PAZNFMDB.h>
#import <PaCoreSdk/PAZNDBManager.h>
#import <PaCoreSdk/PAZNUserDefault.h>
#import <PaCoreSdk/PAZNDbObject.h>
#import <PaCoreSdk/PADataObject.h>
#import <PaCoreSdk/PAZNDBManager.h>
#import <PaCoreSdk/PAZNFMDatabase+FTS3.h>
#import <PaCoreSdk/PAZNFMDatabase+InMemoryOnDiskIO.h>
#import <PaCoreSdk/PAZNFMTokenizers.h>
#import <PaCoreSdk/PAZNfts3_tokenizer.h>

//自动布局
#import <PaCoreSdk/PAZNMasonry.h>
#import <PaCoreSdk/PAZNMASConstraint+Private.h>

//toast 提示
#import <PaCoreSdk/PAZNMBProgressHUD.h>
#import <PaCoreSdk/PAZNRefresh.h>

//UI 控件
#import <PaCoreSdk/PAZNTabBar.h>
#import <PaCoreSdk/PAZNTabBarItem.h>
#import <PaCoreSdk/PAZNTabBarController.h>
#import <PaCoreSdk/PAZNSwitch.h>
#import <PaCoreSdk/PAZNSlider.h>
#import <PaCoreSdk/PAZNSwitchTabController.h>
#import <PaCoreSdk/PAZNTabView.h>
#import <PaCoreSdk/PAZNTableViewCell.h>
#import <PaCoreSdk/PAZNCellScrollView.h>
#import <PaCoreSdk/PAZNUtilityButtonView.h>
#import <PaCoreSdk/PAZNUtilityButtonTapGestureRecognizer.h>
#import <PaCoreSdk/PAZNLongPressGestureRecognizer.h>
#import <PaCoreSdk/PAZNCaptchaInputView.h>
#import <PaCoreSdk/PAZNRouter.h>
#import <PaCoreSdk/PAZNPhoneVerificationCodeViewController.h>

//图片下载
#import <PaCoreSdk/PAZNImageCache.h>
#import <PaCoreSdk/PAZNAFAutoPurgingImageCache.h>
#import <PaCoreSdk/PAZNAFImageDownloader.h>
//#import <PaCoreSdk/PAZNImageDecoder.h>
#import <PaCoreSdk/PAZNSDWebImageDownloaderOperation.h>
#import <PaCoreSdk/PAZNSDWebImagePrefetcher.h>
#import <PaCoreSdk/PAAnimatedImage.h>

//富媒体
#import <PaCoreSdk/PAZNText.h>
#import <PaCoreSdk/PAZNTextAsyncLayer.h>
#import <PaCoreSdk/PAZNTextContainerView.h>
#import <PaCoreSdk/PAZNTextEffectWindow.h>
#import <PaCoreSdk/PAZNTextMagnifier.h>
#import <PaCoreSdk/PAZNTextSelectionView.h>
#import <PaCoreSdk/PAZNTextTransaction.h>
#import <PaCoreSdk/PAZNTextWeakProxy.h>
#import <PaCoreSdk/UIView+PAZNText.h>

//常用扩展
#import <PaCoreSdk/NSData+PAZNCommon.h>
#import <PaCoreSdk/NSData+PAZNExtra.h>
#import <PaCoreSdk/NSString+PAZNCommon.h>
#import <PaCoreSdk/NSString+PAZNExtra.h>
#import <PaCoreSdk/NSObject+PAZNHUD.h>
#import <PaCoreSdk/UIAlertView+PAZNBlocks.h>
#import <PaCoreSdk/UIAlertView+PAZNPrompt.h>
#import <PaCoreSdk/UIActionSheet+PAZNBlocks.h>
#import <PaCoreSdk/UIView+PAZNCustomAutoLayout.h>
#import <PaCoreSdk/UIView+PAZNAdditions.h>
#import <PaCoreSdk/UIImage+PAZNExtra.h>
#import <PaCoreSdk/NSData+PAZNImageContentType.h>
#import <PaCoreSdk/UIButton+PAZNWebCache.h>
#import <PaCoreSdk/UIImageView+PAZNWebCache.h>
#import <PaCoreSdk/UIActivityIndicatorView+PAZNAFNetworking.h>
#import <PaCoreSdk/UIButton+PAZNAFNetworking.h>
#import <PaCoreSdk/UIImage+PAZNAFNetworking.h>
#import <PaCoreSdk/UIImage+MultiFormat.h>
//#import <PaCoreSdk/UIImage+PAZNWebP.h>
#import <PaCoreSdk/UIImageView+PAZNAFNetworking.h>
#import <PaCoreSdk/UIImageView+HighlightedWebCache.h>
#import <PaCoreSdk/MKAnnotationView+WebCache.h>
#import <PaCoreSdk/UIProgressView+PAZNAFNetworking.h>
#import <PaCoreSdk/UIRefreshControl+PAZNAFNetworking.h>
#import <PaCoreSdk/UIView+WebCacheOperation.h>
#import <PaCoreSdk/UIWebView+PAZNAFNetworking.h>
#import <PaCoreSdk/UIImage+GIF.h>
#import <PaCoreSdk/UIKit+PAZNAFNetworking.h>
#import <PaCoreSdk/UIColor+PAZNHex.h>
#import <PaCoreSdk/NSObject+PAZNAssociate.h>
#import <PaCoreSdk/NSTimer+PAZNExtra.h>
#import <PaCoreSdk/UIButton+PAZNExtra.h>
#import <PaCoreSdk/UIFont+PAZNExtra.h>
#import <PaCoreSdk/UILabel+PAZNExtra.h>
#import <PaCoreSdk/UIDevice+PAZNExtra.h>
#import <PaCoreSdk/NSMutableArray+PAZNUtilityButtons.h>
#import <PaCoreSdk/NSArray+PAZNExtra.h>
#import <PaCoreSdk/NSMutableArray+PAZNExtra.h>
#import <PaCoreSdk/UIScrollView+PAZNEmptyDataSet.h>
#import <PaCoreSdk/NSDate+PAZNExt.h>
#import <PACoreSDK/NSObject+PAPermission.h>
#import <PACoreSDK/UITextView+Placeholder.h>
#import <PACoreSDK/UIView+KeyFrameAnimation.h>
#import <PACoreSDK/PAZNViewAdditions.h>
#import <PACoreSDK/PAAnimatedImageView.h>
#import <PaCoreSdk/PAAnimatedImage.h>
#import <PaCoreSdk/UIButton+Block.h>
#import <PaCoreSdk/UIView+BlockGesture.h>
#import <PaCoreSdk/UIViewController+PAZNNavigationItem.h>
#import <PaCoreSdk/UIViewController+PAZNRoute.h>
#import <PaCoreSdk/UIScrollView+PALYEmptySet.h>
#import <PaCoreSdk/UIAlertController+Blocks.h>
#import <PaCoreSdk/UIView+PAZNGradientColor.h>

//Base64
#import <PaCoreSdk/PAZNBase64.h>
#import <PaCoreSdk/PAZNGTMBase64.h>
#import <PaCoreSdk/PAZNBase64Data.h>
#import <PaCoreSdk/PAZNGTMDefines.h>

//加密
#import <PaCoreSdk/PAZNRSAEncrypt.h>
#import <PaCoreSdk/PAZNSecKeyWrapper.h>
#import <PaCoreSdk/PAZNOpenUDID.h>
#import <PaCoreSdk/PAZNCocoaSecurity.h>

//Hook
#import <PaCoreSdk/PAZNAspects.h>

//hybrid
#import <PaCoreSdk/PAZNWebViewJavascriptBridge.h>
#import <PaCoreSdk/PAZNWebViewJavascriptBridge_JS.h>
#import <PaCoreSdk/PAZNWKWebViewJavascriptBridge.h>

//文件处理
#import <PaCoreSdk/PAZNSSZipArchive.h>

//视频处理
#import <PaCoreSdk/PAZNVideoPlayerView.h>
#import <PaCoreSdk/PAZNAVPlayerController.h>

//音频录制
#import <PaCoreSdk/PAZNAudioRecorder.h>

//业务模块
#import <PaCoreSdk/PAZNBaseMgrProtocol.h>
#import <PaCoreSdk/PAZNGCDMulticastDelegate.h>
#import <PaCoreSdk/PAZNBaseManager.h>

#import <PaCoreSdk/BFDisplayEvent.h>
#import <PaCoreSdk/LYSegment.h>
#import <PaCoreSdk/ZYKeyboardUtil.h>
//#import <PaCoreSdk/RegexKitLite.h>
//! Project version number for PaCoreSdk.
FOUNDATION_EXPORT double PaCoreSdkVersionNumber;

//! Project version string for PaCoreSdk.
FOUNDATION_EXPORT const unsigned char PaCoreSdkVersionString[];

// In this header, you should import all the public headers of your framework using statements like #import <PaCoreSdk/PublicHeader.h>


