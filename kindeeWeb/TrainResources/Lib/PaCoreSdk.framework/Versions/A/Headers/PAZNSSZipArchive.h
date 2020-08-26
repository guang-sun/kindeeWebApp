//
//  SSPAZNZipArchive.h
//  SSPAZNZipArchive
//
//  Created by Sam Soffes on 7/21/10.
//  Copyright (c) Sam Soffes 2010-2015. All rights reserved.
//

#ifndef _PAZNSSZIPARCHIVE_H
#define _PAZNSSZIPARCHIVE_H

#import <Foundation/Foundation.h>
#include "PAZNCommon.h"

@protocol PAZNSSZipArchiveDelegate;

@interface PAZNSSZipArchive : NSObject

// Unzip
+ (BOOL)unzipFileAtPath:(NSString *)path toDestination:(NSString *)destination;
+ (BOOL)unzipFileAtPath:(NSString *)path toDestination:(NSString *)destination delegate:(id<PAZNSSZipArchiveDelegate>)delegate;

+ (BOOL)unzipFileAtPath:(NSString *)path toDestination:(NSString *)destination overwrite:(BOOL)overwrite password:(NSString *)password error:(NSError **)error;
+ (BOOL)unzipFileAtPath:(NSString *)path toDestination:(NSString *)destination overwrite:(BOOL)overwrite password:(NSString *)password error:(NSError **)error delegate:(id<PAZNSSZipArchiveDelegate>)delegate;

+ (BOOL)unzipFileAtPath:(NSString *)path
		  toDestination:(NSString *)destination
		progressHandler:(void (^)(NSString *entry, pazn_file_info zipInfo, long entryNumber, long total))progressHandler
	  completionHandler:(void (^)(NSString *path, BOOL succeeded, NSError *error))completionHandler;

+ (BOOL)unzipFileAtPath:(NSString *)path
		  toDestination:(NSString *)destination
			  overwrite:(BOOL)overwrite
			   password:(NSString *)password
		progressHandler:(void (^)(NSString *entry, pazn_file_info zipInfo, long entryNumber, long total))progressHandler
	  completionHandler:(void (^)(NSString *path, BOOL succeeded, NSError *error))completionHandler;

// Zip
+ (BOOL)createZipFileAtPath:(NSString *)path withFilesAtPaths:(NSArray *)filenames;
+ (BOOL)createZipFileAtPath:(NSString *)path withContentsOfDirectory:(NSString *)directoryPath;
+ (BOOL)createZipFileAtPath:(NSString *)path withContentsOfDirectory:(NSString *)directoryPath keepParentDirectory:(BOOL)keepParentDirectory;

- (instancetype)initWithPath:(NSString *)path;
@property (NS_NONATOMIC_IOSONLY, readonly) BOOL open;
- (BOOL)writeFile:(NSString *)path;
- (BOOL)writeFileAtPath:(NSString *)path withFileName:(NSString *)fileName;
- (BOOL)writeData:(NSData *)data filename:(NSString *)filename;
@property (NS_NONATOMIC_IOSONLY, readonly) BOOL close;

@end

@protocol PAZNSSZipArchiveDelegate <NSObject>

@optional

- (void)zipArchiveWillUnzipArchiveAtPath:(NSString *)path zipInfo:(pazn_global_info)zipInfo;
- (void)zipArchiveDidUnzipArchiveAtPath:(NSString *)path zipInfo:(pazn_global_info)zipInfo unzippedPath:(NSString *)unzippedPath;

- (BOOL)zipArchiveShouldUnzipFileAtIndex:(NSInteger)fileIndex totalFiles:(NSInteger)totalFiles archivePath:(NSString *)archivePath fileInfo:(pazn_file_info)fileInfo;
- (void)zipArchiveWillUnzipFileAtIndex:(NSInteger)fileIndex totalFiles:(NSInteger)totalFiles archivePath:(NSString *)archivePath fileInfo:(pazn_file_info)fileInfo;
- (void)zipArchiveDidUnzipFileAtIndex:(NSInteger)fileIndex totalFiles:(NSInteger)totalFiles archivePath:(NSString *)archivePath fileInfo:(pazn_file_info)fileInfo;
- (void)zipArchiveDidUnzipFileAtIndex:(NSInteger)fileIndex totalFiles:(NSInteger)totalFiles archivePath:(NSString *)archivePath unzippedFilePath:(NSString *)unzippedFilePath;

- (void)zipArchiveProgressEvent:(unsigned long long)loaded total:(unsigned long long)total;
- (void)zipArchiveDidUnzipArchiveFile:(NSString *)zipFile entryPath:(NSString *)entryPath destPath:(NSString *)destPath;

@end

#endif /* _SSZIPARCHIVE_H */
