//
//  PaUIKitData.h
//  PaCoreSdk
//
//  Created by 王斌(平安科技智慧教育团队项目研发部知鸟研发团队移动开发组) on 2019/1/16.
//

#import <Foundation/Foundation.h>


@interface PaUIKitData : NSObject

+ (void)trackEvent:(NSString *)eventId
             label:(NSString *)eventLabel;

+ (void)trackEvent:(NSString *)eventId
             label:(NSString *)eventLabel
        parameters:(NSDictionary *)parameters;

@end

