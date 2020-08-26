//
//  UIAlertView+Blocks.h
//  Shibui
//
//  Created by Jiva DeVoe on 12/28/10.
//  Copyright 2010 Random Ideas, LLC. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface PAZNRIButtonItem : NSObject
{
    NSString *label;
    void (^action)(void);
}

@property (retain, nonatomic) NSString *label;
@property (copy, nonatomic) void (^action)(void);

+(id)item;
+(id)itemWithLabel:(NSString *)inLabel;
+(id)itemWithLabel:(NSString *)inLabel action:(void(^)(void))action;

@end

@interface UIAlertView (PAZNBlocks)

-(id)initWithTitle:(NSString *)inTitle message:(NSString *)inMessage cancelButtonItem:(PAZNRIButtonItem *)inCancelButtonItem otherButtonItems:(PAZNRIButtonItem *)inOtherButtonItems, ... NS_REQUIRES_NIL_TERMINATION;

- (NSInteger)addButtonItem:(PAZNRIButtonItem *)item;


+ (UIAlertView*)pazn_showAlertViewWithTitle:(NSString *)title message:(NSString *)message cancelButtonTitle:(NSString *)cancelButtonTitle otherButtonTitles:(NSArray *)otherButtonTitles handler:(void (^)(UIAlertView *alertView, NSInteger buttonIndex))block;



@end
