//
//  PAZNAlertMessageView.h
//  PaCoreSdk
//
//  Created by 刘宏扬 on 2019/6/4.
//

#import <UIKit/UIKit.h>

typedef NS_ENUM(NSInteger,PAlertMessageType){
    PAlertMessageTypeSuccess = 0, //成功 √
    PAlertMessageTypeNotice,    //提示 ！
    PAlertSignatureSuccess,
    PAlertSignatureFail,
};

NS_ASSUME_NONNULL_BEGIN

@interface PAZNAlertMessageView : UIView

+ (void)showWithTitle:(NSString *)title
              message:(NSString *)message
                 type:(PAlertMessageType)type;

+ (void)hidden;

@end

NS_ASSUME_NONNULL_END
