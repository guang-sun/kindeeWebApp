//
//  UIActionSheet+Blocks.h
//  Shibui
//
//  Created by Jiva DeVoe on 1/5/11.
//  Copyright 2011 Random Ideas, LLC. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "UIAlertView+PAZNBlocks.h"

@interface UIActionSheet (PAZNBlocks) <UIActionSheetDelegate>

-(id)initWithTitle:(NSString *)inTitle cancelButtonItem:(PAZNRIButtonItem *)inCancelButtonItem destructiveButtonItem:(PAZNRIButtonItem *)inDestructiveItem otherButtonItems:(PAZNRIButtonItem *)inOtherButtonItems, ... NS_REQUIRES_NIL_TERMINATION;

- (NSInteger)addButtonItem:(PAZNRIButtonItem *)item;

/** This block is called when the action sheet is dismssed for any reason.
 */
@property (copy, nonatomic) void(^dismissalAction)(void);

@end
