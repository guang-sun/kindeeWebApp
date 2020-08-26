#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

typedef NS_ENUM(NSInteger, PAZNUILabelCountingMethod) {
    PAZNUILabelCountingMethodEaseInOut,
    PAZNUILabelCountingMethodEaseIn,
    PAZNUILabelCountingMethodEaseOut,
    PAZNUILabelCountingMethodLinear,
    PAZNUILabelCountingMethodEaseInBounce,
    PAZNUILabelCountingMethodEaseOutBounce
};

typedef NSString* (^PAZNCountingLabelFormatBlock)(CGFloat value);
typedef NSAttributedString* (^PAZNCountingLabelAttributedFormatBlock)(CGFloat value);

@interface PAZNCountingLabel : UILabel

@property (nonatomic, strong) NSString *format;
@property (nonatomic, assign) PAZNUILabelCountingMethod method;
@property (nonatomic, assign) NSTimeInterval animationDuration;

@property (nonatomic, copy) PAZNCountingLabelFormatBlock formatBlock;
@property (nonatomic, copy) PAZNCountingLabelAttributedFormatBlock attributedFormatBlock;
@property (nonatomic, copy) void (^completionBlock)(void);

-(void)countFrom:(CGFloat)startValue to:(CGFloat)endValue;
-(void)countFrom:(CGFloat)startValue to:(CGFloat)endValue withDuration:(NSTimeInterval)duration;

-(void)countFromCurrentValueTo:(CGFloat)endValue;
-(void)countFromCurrentValueTo:(CGFloat)endValue withDuration:(NSTimeInterval)duration;

-(void)countFromZeroTo:(CGFloat)endValue;
-(void)countFromZeroTo:(CGFloat)endValue withDuration:(NSTimeInterval)duration;

- (CGFloat)currentValue;

@end

