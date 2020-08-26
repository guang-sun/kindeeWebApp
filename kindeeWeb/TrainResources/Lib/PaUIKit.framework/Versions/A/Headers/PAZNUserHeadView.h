//
//  PAZNUserHeadView.h
//  MLPlayer
//
//  Created by 刘宏扬 on 2018/8/28.
//  Copyright © 2018年 w. All rights reserved.
//

/*  Notice
    镜像类：PALiveUserHeadView.h
    需同步调整
 */

#import <UIKit/UIKit.h>

typedef void(^HeadImageClick)(void);

typedef NS_ENUM(NSInteger,PASchoolLiveUserVerifyType){
    PASchoolLiveUserVerifyTypeStandard = 0,//标准
    PASchoolLiveUserVerifyTypeMaster,     //大咖委员会
    PASchoolLiveUserVerifyTypeExperiencer //学堂体验官
};

typedef NS_ENUM(NSInteger,PASchoolLiveUserGenderType){
    PASchoolLiveUserGenderTypeMale = 0,//男
    PASchoolLiveUserGenderTypeFemale,//女
    PASchoolLiveUserGenderTypeBird, //鸟宝
    PASchoolLiveUserGenderTypeDefault,//默认
};

@interface PAZNUserHeadView : UIView

/** 响应点击 默认响应*/
@property (nonatomic,assign) BOOL clickEnabled;
/** 点击回调 */
@property (nonatomic,copy)   HeadImageClick headImageClick;


- (void)setHeadViewWithImageUrl:(NSURL *)imageUrl
                      genderStr:(NSString *)genderStr
                      verifyStr:(NSString *)verifyStr;

- (void)setHeadViewWithImageUrl:(NSURL *)imageUrl
                      genderStr:(NSString *)genderStr
                      verifyStr:(NSString *)verifyStr
                    borderWidth:(CGFloat)borderWidth
                    borderColor:(UIColor *)borderColor;

- (void)setHeadViewWithImageUrl:(NSURL *)imageUrl
                     genderType:(PASchoolLiveUserGenderType)genderType
                     verifyType:(PASchoolLiveUserVerifyType)verifyType;

- (void)setHeadViewWithImageUrl:(NSURL *)imageUrl
                     genderType:(PASchoolLiveUserGenderType)genderType
                     verifyType:(PASchoolLiveUserVerifyType)verifyType
                    borderWidth:(CGFloat)borderWidth
                    borderColor:(UIColor *)borderColor;



@end
