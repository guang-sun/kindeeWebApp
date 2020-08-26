//
//  PAEmoticonHelper.h
//  MLPlayer
//
//  Created by BearLi on 15/12/9.
//  Copyright © 2015年 w. All rights reserved.
//

#import <Foundation/Foundation.h>


/**
    评论表情管理类
 */
@interface PAEmoticonHelper : NSObject

/// 表情正则 例如 [偷笑]
+ (NSRegularExpression *)regexEmoticon;


/** 表情字典
 */
+ (NSDictionary *)emoticonDict;

//表情字典:{NSString: UIImage}
+ (NSDictionary *)emojiImageDict;


+ (UIImage*)imageWithName:(NSString*)imageName;

@end
