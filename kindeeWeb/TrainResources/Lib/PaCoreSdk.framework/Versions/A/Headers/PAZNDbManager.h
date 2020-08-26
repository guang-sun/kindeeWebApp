//
//  PAZNDbManager.h
//  MLPlayer
//
//  Created by Cyril Zhou on 2017/3/15.
//  Copyright © 2017年 w. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "PAZNDbObject.h"

@interface PAZNDbManager : NSObject

- (PAZNDbManager *)initDBWithFilePath:(NSString *)filePath;

#pragma mark - 增删改查

- (BOOL)createTable:(PAZNDbObject *)obj;
- (void)updateObject:(PAZNDbObject *)obj;
- (BOOL)saveObject:(PAZNDbObject *)obj;
- (BOOL)deleteObject:(PAZNDbObject *)obj;

- (void)saveModels:(NSArray *)objs;
- (void)deleteModels:(NSArray *)objs;

- (PAZNDbObject *)findFirstByCriteria:(NSString *)criteria objClass:(Class)objClass;
- (NSArray *)findByCriteria:(NSString *)criteria objClass:(Class)objClass;

@end
