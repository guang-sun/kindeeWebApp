//
//  FSCalendarHeader.h
//  Pods
//
//  Created by Wenchao Ding on 29/1/15.
//
//

#import <UIKit/UIKit.h>


@class PAFSCalendar, PAFSCalendarAppearance, PAFSCalendarHeaderLayout, PAFSCalendarCollectionView;

@interface PAFSCalendarHeaderView : UIView

@property (weak, nonatomic) PAFSCalendarCollectionView *collectionView;
@property (weak, nonatomic) PAFSCalendarHeaderLayout *collectionViewLayout;
@property (weak, nonatomic) PAFSCalendar *calendar;

@property (assign, nonatomic) CGFloat scrollOffset;
@property (assign, nonatomic) UICollectionViewScrollDirection scrollDirection;
@property (assign, nonatomic) BOOL scrollEnabled;
@property (assign, nonatomic) BOOL needsAdjustingViewFrame;
@property (assign, nonatomic) BOOL needsAdjustingMonthPosition;

- (void)setScrollOffset:(CGFloat)scrollOffset animated:(BOOL)animated;
- (void)reloadData;
- (void)configureAppearance;

@end


@interface PAFSCalendarHeaderCell : UICollectionViewCell

@property (weak, nonatomic) UILabel *titleLabel;
@property (weak, nonatomic) PAFSCalendarHeaderView *header;

@end

@interface PAFSCalendarHeaderLayout : UICollectionViewFlowLayout

@end

@interface PAFSCalendarHeaderTouchDeliver : UIView

@property (weak, nonatomic) PAFSCalendar *calendar;
@property (weak, nonatomic) PAFSCalendarHeaderView *header;

@end
