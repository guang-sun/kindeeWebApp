//
//  NSObject+associate.h
//  Simple
//
//  Created by suruochang on 11/30/15.
//  Copyright © 2015 suruochang. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSObject (PAZNAssociate)

/*
 *根据key关联一个可以retain类型的object
 */
- (void)associateObject:(id)object forKey:(NSString *)key;

/*
 *关联一个weak类型的object
 */
- (void)associateWeaklyObject:(id)object forKey:(NSString *)key;

/*
 *关联一个可以copy类型的object：block、NSString
 */
- (void)associateCopyObject:(id)object forKey:(NSString *)key;

/*
 *根据关联的key求出关联的值
 */
- (id)associateObjectForKey:(NSString *)key;

/*
 *根据key删除已经被关联的值
 */
- (void)removeAssociateObjectForKey:(NSString *)key;

@end
