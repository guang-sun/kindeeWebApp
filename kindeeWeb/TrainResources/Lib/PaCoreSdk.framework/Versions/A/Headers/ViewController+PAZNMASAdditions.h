//
//  UIViewController+MASAdditions.h
//  Masonry
//
//  Created by Craig Siemens on 2015-06-23.
//
//

#import "PAZNMASUtilities.h"
#import "PAZNMASConstraintMaker.h"
#import "PAZNMASViewAttribute.h"

#ifdef MAS_VIEW_CONTROLLER

@interface MAS_VIEW_CONTROLLER (PAZNMASAdditions)

/**
 *	following properties return a new MASViewAttribute with appropriate UILayoutGuide and NSLayoutAttribute
 */
@property (nonatomic, strong, readonly) PAZNMASViewAttribute *pazn_mas_topLayoutGuide;
@property (nonatomic, strong, readonly) PAZNMASViewAttribute *pazn_mas_bottomLayoutGuide;
@property (nonatomic, strong, readonly) PAZNMASViewAttribute *pazn_mas_topLayoutGuideTop;
@property (nonatomic, strong, readonly) PAZNMASViewAttribute *pazn_mas_topLayoutGuideBottom;
@property (nonatomic, strong, readonly) PAZNMASViewAttribute *pazn_mas_bottomLayoutGuideTop;
@property (nonatomic, strong, readonly) PAZNMASViewAttribute *pazn_mas_bottomLayoutGuideBottom;


@end

#endif
