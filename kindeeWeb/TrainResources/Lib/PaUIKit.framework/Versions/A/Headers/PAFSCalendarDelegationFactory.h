//
//  PAFSCalendarDelegationFactory.h
//  PAFSCalendar
//
//  Created by dingwenchao on 19/12/2016.
//  Copyright © 2016 wenchaoios. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "PAFSCalendarDelegationProxy.h"

@interface PAFSCalendarDelegationFactory : NSObject

+ (PAFSCalendarDelegationProxy *)dataSourceProxy;
+ (PAFSCalendarDelegationProxy *)delegateProxy;

@end
