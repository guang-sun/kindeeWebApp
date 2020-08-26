/**
//  @header PAZNZipArchive.h
//  
//  An objective C wrapper for minizip and libz for creating and exanding ZIP files.
//
//  @author Created by aish on 08-9-11.
//  acsolu@gmail.com
//  @copyright Copyright 2008  Inc. All rights reserved.
//
*/


typedef NS_ENUM(NSInteger, PAZNZipArchiveCompression) {
    PAZNZipArchiveCompressionDefault = -1,
    PAZNZipArchiveCompressionNone    =  0,
    PAZNZipArchiveCompressionSpeed   =  1,
    PAZNZipArchiveCompressionBest    =  9,
};


/**
 a block that is called from UnzipFileTo:overwrite:withProgressBlock: where the percentage of
 files processed (as an integer from 0 to 100), the number of files processed so far and the
 total number of files in the archive is called after each file is processed.
 */
typedef void(^PAZNZipArchiveProgressUpdateBlock)(int percentage, int filesProcessed, unsigned long numFiles);
	
/**
    @protocol
    @discussion  methods for a delegate to receive error notifications and control overwriting of files
*/

@protocol PAZNZipArchiveDelegate <NSObject>
@optional

/**
    @brief   Delegate method to be notified of errors
    
    PAZNZipArchive calls this selector on the delegate when errors are encountered.
    
    @param      msg     a string describing the error.
*/

-(void) ErrorMessage:(NSString*) msg;

/**
    @brief   Delegate method to determine if a file should be replaced
    
    When an zip file is being expanded and a file is about to be replaced, this selector
    is called on the delegate to notify that file is about to be replaced. The delegate method
    should return YES to overwrite the file, or NO to skip it.
 
    @param      file - path to the file to be overwritten.
    @result     a BOOL - YES to replace, NO to skip
*/

-(BOOL) OverWriteOperation:(NSString*) file;

@end

/**
    @class
    @brief      An object that can create zip files and expand existing ones.
    This class provides methods to create a zip file (optionally with a password) and
    add files to that zip archive. 
                 
    It also provides methods to expand an existing archive file (optionally with a password),
    and extract the files.
*/

@interface PAZNZipArchive : NSObject {
@private
	void*           _zipFile;
	void*           _unzFile;
	
    unsigned long   _numFiles;
	NSString*       _password;
	id              _delegate;
    PAZNZipArchiveProgressUpdateBlock _progressBlock;
    
    NSArray*    _unzippedFiles;
    
    NSFileManager* _fileManager;
    NSStringEncoding _stringEncoding;
}

/** a delegate object conforming to PAZNZipArchiveDelegate protocol */
@property (nonatomic, retain) id<PAZNZipArchiveDelegate> delegate;
@property (nonatomic, readonly) unsigned long numFiles;
@property (nonatomic, copy) PAZNZipArchiveProgressUpdateBlock progressBlock;

@property (nonatomic, assign) PAZNZipArchiveCompression compression;

/**
    @brief      String encoding to be used when interpreting file names in the zip file.
*/
@property (nonatomic, assign) NSStringEncoding stringEncoding;

/** an array of files that were successfully expanded. Available after calling UnzipFileTo:overWrite: */
@property (nonatomic, readonly) NSArray* unzippedFiles;

-(id) initWithFileManager:(NSFileManager*) fileManager;

-(BOOL) CreateZipFile2:(NSString*) zipFile;
-(BOOL) CreateZipFile2:(NSString*) zipFile append:(BOOL)isAppend;
-(BOOL) CreateZipFile2:(NSString*) zipFile Password:(NSString*) password;
-(BOOL) CreateZipFile2:(NSString*) zipFile Password:(NSString*) password append:(BOOL)isAppend;
-(BOOL) addFileToZip:(NSString*) file newname:(NSString*) newname;
-(BOOL) addDataToZip:(NSData*) data fileAttributes:(NSDictionary *)attr newname:(NSString*) newname;
-(BOOL) CloseZipFile2;

-(BOOL) UnzipOpenFile:(NSString*) zipFile;
-(BOOL) UnzipOpenFile:(NSString*) zipFile Password:(NSString*) password;
-(BOOL) UnzipFileTo:(NSString*) path overWrite:(BOOL) overwrite;
-(NSDictionary *)UnzipFileToMemory;//To avoid memory issue, only use this method for small zip files.
-(BOOL) UnzipCloseFile;

// List the contents of the zip archive. must be called after UnzipOpenFile.
// If zip file was appended with `CreateZipFile2:append:` or ``CreateZipFile2:Password:append:`,
// `getZipFileContents` result won't be updated until re-unzip-open after close write handle (`CloseZipFile2` then `UnzipCloseFile` then (`UnzipOpenFile:` or `UnzipOpenFile:Password`) get called).
-(NSArray*) getZipFileContents;

@end
