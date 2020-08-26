//
//  PAPhotoBrowser.h
//  PAUIKit
//

#import <UIKit/UIKit.h>

@class PAPhotoBrowser;
@protocol PAPhotoBrowserDelegate <NSObject>

- (void)photoBrowser:(PAPhotoBrowser *)browser deleteAtIndex:(NSInteger)index;

@end

@interface PAPhotoBrowser : UIViewController

@property(nonatomic, weak) id<PAPhotoBrowserDelegate> delegate;

@property(nonatomic, copy) NSArray *imageViewsArray;

@property(nonatomic, copy) NSArray *imgDatasArray; // url strings, datas,

@property(nonatomic, assign) NSInteger curImgIndex;

@property(nonatomic, assign) BOOL hideStatusBar;

@property (nonatomic, assign) BOOL enableDelete;

@property (nonatomic, assign) BOOL enableSave;

@property (nonatomic, assign) BOOL showNoAnimate;

- (void)reload;

- (void)show; 
@end
