//
//  PAZNDbObject.h
//  MLPlayer
//
//  Created by Cyril Zhou on 2017/3/15.
//  Copyright © 2017年 w. All rights reserved.
//

#import <Foundation/Foundation.h>

/** SQLite五种数据类型 */
#define SQLTEXT                 @"TEXT"
#define SQLINTEGER              @"INTEGER"
#define SQLREAL                 @"REAL"
#define SQLBLOB                 @"BLOB"
#define SQLNULL                 @"NULL"
#define PrimaryKey              @"primary key"
#define primaryId               @"pk"

@interface PAZNDbObject : NSObject

/** 主键 id */
@property (nonatomic, assign) int pk;

/** 列名 */
@property (retain, readonly, nonatomic) NSMutableArray *columeNames;

/** 列类型 */
@property (retain, readonly, nonatomic) NSMutableArray *columeTypes;

+ (NSString *)tableName;
+ (NSString *)getColumeAndTypeString;
+ (NSDictionary *)getAllProperties;

//兼容知鸟现有数据库，效率太低，后续考虑删除
+ (NSString *)stringAsPropertyString:(NSString *)proNames;

@end
