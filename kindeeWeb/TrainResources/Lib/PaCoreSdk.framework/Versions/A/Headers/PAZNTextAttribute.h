//
//  PAZNTextAttribute.h
//  PAZNText <https://github.com/ibireme/PAZNText>
//
//  Created by ibireme on 14/10/26.
//  Copyright (c) 2015 ibireme.
//
//  This source code is licensed under the MIT-style license found in the
//  LICENSE file in the root directory of this source tree.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

#pragma mark - Enum Define

/// The attribute type
typedef NS_OPTIONS(NSInteger, PAZNTextAttributeType) {
    PAZNTextAttributeTypeNone     = 0,
    PAZNTextAttributeTypeUIKit    = 1 << 0, ///< UIKit attributes, such as UILabel/UITextField/drawInRect.
    PAZNTextAttributeTypeCoreText = 1 << 1, ///< CoreText attributes, used by CoreText.
    PAZNTextAttributeTypePAZNText   = 1 << 2, ///< PAZNText attributes, used by PAZNText.
};

/// Get the attribute type from an attribute name.
extern PAZNTextAttributeType PAZNTextAttributeGetType(NSString *attributeName);

/**
 Line style in PAZNText (similar to NSUnderlineStyle).
 */
typedef NS_OPTIONS (NSInteger, PAZNTextLineStyle) {
    // basic style (bitmask:0xFF)
    PAZNTextLineStyleNone       = 0x00, ///< (        ) Do not draw a line (Default).
    PAZNTextLineStyleSingle     = 0x01, ///< (──────) Draw a single line.
    PAZNTextLineStyleThick      = 0x02, ///< (━━━━━━━) Draw a thick line.
    PAZNTextLineStyleDouble     = 0x09, ///< (══════) Draw a double line.
    
    // style pattern (bitmask:0xF00)
    PAZNTextLineStylePatternSolid      = 0x000, ///< (────────) Draw a solid line (Default).
    PAZNTextLineStylePatternDot        = 0x100, ///< (‑ ‑ ‑ ‑ ‑ ‑) Draw a line of dots.
    PAZNTextLineStylePatternDash       = 0x200, ///< (— — — —) Draw a line of dashes.
    PAZNTextLineStylePatternDashDot    = 0x300, ///< (— ‑ — ‑ — ‑) Draw a line of alternating dashes and dots.
    PAZNTextLineStylePatternDashDotDot = 0x400, ///< (— ‑ ‑ — ‑ ‑) Draw a line of alternating dashes and two dots.
    PAZNTextLineStylePatternCircleDot  = 0x900, ///< (••••••••••••) Draw a line of small circle dots.
};

/**
 Text vertical alignment.
 */
typedef NS_ENUM(NSInteger, PAZNTextVerticalAlignment) {
    PAZNTextVerticalAlignmentTop =    0, ///< Top alignment.
    PAZNTextVerticalAlignmentCenter = 1, ///< Center alignment.
    PAZNTextVerticalAlignmentBottom = 2, ///< Bottom alignment.
};

/**
 The direction define in PAZNText.
 */
typedef NS_OPTIONS(NSUInteger, PAZNTextDirection) {
    PAZNTextDirectionNone   = 0,
    PAZNTextDirectionTop    = 1 << 0,
    PAZNTextDirectionRight  = 1 << 1,
    PAZNTextDirectionBottom = 1 << 2,
    PAZNTextDirectionLeft   = 1 << 3,
};

/**
 The trunction type, tells the truncation engine which type of truncation is being requested.
 */
typedef NS_ENUM (NSUInteger, PAZNTextTruncationType) {
    /// No truncate.
    PAZNTextTruncationTypeNone   = 0,
    
    /// Truncate at the beginning of the line, leaving the end portion visible.
    PAZNTextTruncationTypeStart  = 1,
    
    /// Truncate at the end of the line, leaving the start portion visible.
    PAZNTextTruncationTypeEnd    = 2,
    
    /// Truncate in the middle of the line, leaving both the start and the end portions visible.
    PAZNTextTruncationTypeMiddle = 3,
};



#pragma mark - Attribute Name Defined in PAZNText

/// The value of this attribute is a `PAZNTextBackedString` object.
/// Use this attribute to store the original plain text if it is replaced by something else (such as attachment).
UIKIT_EXTERN NSString *const PAZNTextBackedStringAttributeName;

/// The value of this attribute is a `PAZNTextBinding` object.
/// Use this attribute to bind a range of text together, as if it was a single charactor.
UIKIT_EXTERN NSString *const PAZNTextBindingAttributeName;

/// The value of this attribute is a `PAZNTextShadow` object.
/// Use this attribute to add shadow to a range of text.
/// Shadow will be drawn below text glyphs. Use PAZNTextShadow.subShadow to add multi-shadow.
UIKIT_EXTERN NSString *const PAZNTextShadowAttributeName;

/// The value of this attribute is a `PAZNTextShadow` object.
/// Use this attribute to add inner shadow to a range of text.
/// Inner shadow will be drawn above text glyphs. Use PAZNTextShadow.subShadow to add multi-shadow.
UIKIT_EXTERN NSString *const PAZNTextInnerShadowAttributeName;

/// The value of this attribute is a `PAZNTextDecoration` object.
/// Use this attribute to add underline to a range of text.
/// The underline will be drawn below text glyphs.
UIKIT_EXTERN NSString *const PAZNTextUnderlineAttributeName;

/// The value of this attribute is a `PAZNTextDecoration` object.
/// Use this attribute to add strikethrough (delete line) to a range of text.
/// The strikethrough will be drawn above text glyphs.
UIKIT_EXTERN NSString *const PAZNTextStrikethroughAttributeName;

/// The value of this attribute is a `PAZNTextBorder` object.
/// Use this attribute to add cover border or cover color to a range of text.
/// The border will be drawn above the text glyphs.
UIKIT_EXTERN NSString *const PAZNTextBorderAttributeName;

/// The value of this attribute is a `PAZNTextBorder` object.
/// Use this attribute to add background border or background color to a range of text.
/// The border will be drawn below the text glyphs.
UIKIT_EXTERN NSString *const PAZNTextBackgroundBorderAttributeName;

/// The value of this attribute is a `PAZNTextBorder` object.
/// Use this attribute to add a code block border to one or more line of text.
/// The border will be drawn below the text glyphs.
UIKIT_EXTERN NSString *const PAZNTextBlockBorderAttributeName;

/// The value of this attribute is a `PAZNTextAttachment` object.
/// Use this attribute to add attachment to text.
/// It should be used in conjunction with a CTRunDelegate.
UIKIT_EXTERN NSString *const PAZNTextAttachmentAttributeName;

/// The value of this attribute is a `PAZNTextHighlight` object.
/// Use this attribute to add a touchable highlight state to a range of text.
UIKIT_EXTERN NSString *const PAZNTextHighlightAttributeName;

/// The value of this attribute is a `NSValue` object stores CGAffineTransform.
/// Use this attribute to add transform to each glyph in a range of text.
UIKIT_EXTERN NSString *const PAZNTextGlyphTransformAttributeName;



#pragma mark - String Token Define

UIKIT_EXTERN NSString *const PAZNTextAttachmentToken; ///< Object replacement character (U+FFFC), used for text attachment.
UIKIT_EXTERN NSString *const PAZNTextTruncationToken; ///< Horizontal ellipsis (U+2026), used for text truncation  "…".



#pragma mark - Attribute Value Define

/**
 The tap/long press action callback defined in PAZNText.
 
 @param containerView The text container view (such as PAZNLabel/PAZNTextView).
 @param text          The whole text.
 @param range         The text range in `text` (if no range, the range.location is NSNotFound).
 @param rect          The text frame in `containerView` (if no data, the rect is CGRectNull).
 */
typedef void(^PAZNTextAction)(UIView *containerView, NSAttributedString *text, NSRange range, CGRect rect);


/**
 PAZNTextBackedString objects are used by the NSAttributedString class cluster
 as the values for text backed string attributes (stored in the attributed 
 string under the key named PAZNTextBackedStringAttributeName).
 
 It may used for copy/paste plain text from attributed string.
 Example: If :) is replace by a custom emoji (such as😊), the backed string can be set to @":)".
 */
@interface PAZNTextBackedString : NSObject <NSCoding, NSCopying>
+ (instancetype)stringWithString:(nullable NSString *)string;
@property (nullable, nonatomic, copy) NSString *string; ///< backed string
@end


/**
 PAZNTextBinding objects are used by the NSAttributedString class cluster
 as the values for shadow attributes (stored in the attributed string under
 the key named PAZNTextBindingAttributeName).
 
 Add this to a range of text will make the specified characters 'binding together'.
 PAZNTextView will treat the range of text as a single character during text 
 selection and edit.
 */
@interface PAZNTextBinding : NSObject <NSCoding, NSCopying>
+ (instancetype)bindingWithDeleteConfirm:(BOOL)deleteConfirm;
@property (nonatomic) BOOL deleteConfirm; ///< confirm the range when delete in PAZNTextView
@end


/**
 PAZNTextShadow objects are used by the NSAttributedString class cluster
 as the values for shadow attributes (stored in the attributed string under
 the key named PAZNTextShadowAttributeName or PAZNTextInnerShadowAttributeName).
 
 It's similar to `NSShadow`, but offers more options.
 */
@interface PAZNTextShadow : NSObject <NSCoding, NSCopying>
+ (instancetype)shadowWithColor:(nullable UIColor *)color offset:(CGSize)offset radius:(CGFloat)radius;

@property (nullable, nonatomic, strong) UIColor *color; ///< shadow color
@property (nonatomic) CGSize offset;                    ///< shadow offset
@property (nonatomic) CGFloat radius;                   ///< shadow blur radius
@property (nonatomic) CGBlendMode blendMode;            ///< shadow blend mode
@property (nullable, nonatomic, strong) PAZNTextShadow *subShadow;  ///< a sub shadow which will be added above the parent shadow

+ (instancetype)shadowWithNSShadow:(NSShadow *)nsShadow; ///< convert NSShadow to PAZNTextShadow
- (NSShadow *)nsShadow; ///< convert PAZNTextShadow to NSShadow
@end


/**
 PAZNTextDecorationLine objects are used by the NSAttributedString class cluster
 as the values for decoration line attributes (stored in the attributed string under
 the key named PAZNTextUnderlineAttributeName or PAZNTextStrikethroughAttributeName).
 
 When it's used as underline, the line is drawn below text glyphs;
 when it's used as strikethrough, the line is drawn above text glyphs.
 */
@interface PAZNTextDecoration : NSObject <NSCoding, NSCopying>
+ (instancetype)decorationWithStyle:(PAZNTextLineStyle)style;
+ (instancetype)decorationWithStyle:(PAZNTextLineStyle)style width:(nullable NSNumber *)width color:(nullable UIColor *)color;
@property (nonatomic) PAZNTextLineStyle style;                   ///< line style
@property (nullable, nonatomic, strong) NSNumber *width;       ///< line width (nil means automatic width)
@property (nullable, nonatomic, strong) UIColor *color;        ///< line color (nil means automatic color)
@property (nullable, nonatomic, strong) PAZNTextShadow *shadow;  ///< line shadow
@end


/**
 PAZNTextBorder objects are used by the NSAttributedString class cluster
 as the values for border attributes (stored in the attributed string under
 the key named PAZNTextBorderAttributeName or PAZNTextBackgroundBorderAttributeName).
 
 It can be used to draw a border around a range of text, or draw a background
 to a range of text.
 
 Example:
    ╭──────╮
    │ Text │
    ╰──────╯
 */
@interface PAZNTextBorder : NSObject <NSCoding, NSCopying>
+ (instancetype)borderWithLineStyle:(PAZNTextLineStyle)lineStyle lineWidth:(CGFloat)width strokeColor:(nullable UIColor *)color;
+ (instancetype)borderWithFillColor:(nullable UIColor *)color cornerRadius:(CGFloat)cornerRadius;
@property (nonatomic) PAZNTextLineStyle lineStyle;              ///< border line style
@property (nonatomic) CGFloat strokeWidth;                    ///< border line width
@property (nullable, nonatomic, strong) UIColor *strokeColor; ///< border line color
@property (nonatomic) CGLineJoin lineJoin;                    ///< border line join
@property (nonatomic) UIEdgeInsets insets;                    ///< border insets for text bounds
@property (nonatomic) CGFloat cornerRadius;                   ///< border corder radius
@property (nullable, nonatomic, strong) PAZNTextShadow *shadow; ///< border shadow
@property (nullable, nonatomic, strong) UIColor *fillColor;   ///< inner fill color
@end


/**
 PAZNTextAttachment objects are used by the NSAttributedString class cluster 
 as the values for attachment attributes (stored in the attributed string under 
 the key named PAZNTextAttachmentAttributeName).
 
 When display an attributed string which contains `PAZNTextAttachment` object,
 the content will be placed in text metric. If the content is `UIImage`, 
 then it will be drawn to CGContext; if the content is `UIView` or `CALayer`, 
 then it will be added to the text container's view or layer.
 */
@interface PAZNTextAttachment : NSObject<NSCoding, NSCopying>
+ (instancetype)attachmentWithContent:(nullable id)content;
@property (nullable, nonatomic, strong) id content;             ///< Supported type: UIImage, UIView, CALayer
@property (nonatomic) UIViewContentMode contentMode;            ///< Content display mode.
@property (nonatomic) UIEdgeInsets contentInsets;               ///< The insets when drawing content.
@property (nullable, nonatomic, strong) NSDictionary *userInfo; ///< The user information dictionary.
@end


/**
 PAZNTextHighlight objects are used by the NSAttributedString class cluster
 as the values for touchable highlight attributes (stored in the attributed string
 under the key named PAZNTextHighlightAttributeName).
 
 When display an attributed string in `PAZNLabel` or `PAZNTextView`, the range of 
 highlight text can be toucheds down by users. If a range of text is turned into 
 highlighted state, the `attributes` in `PAZNTextHighlight` will be used to modify 
 (set or remove) the original attributes in the range for display.
 */
@interface PAZNTextHighlight : NSObject <NSCoding, NSCopying>

/**
 Attributes that you can apply to text in an attributed string when highlight.
 Key:   Same as CoreText/PAZNText Attribute Name.
 Value: Modify attribute value when highlight (NSNull for remove attribute).
 */
@property (nullable, nonatomic, copy) NSDictionary<NSString *, id> *attributes;

/**
 Creates a highlight object with specified attributes.
 
 @param attributes The attributes which will replace original attributes when highlight,
        If the value is NSNull, it will removed when highlight.
 */
+ (instancetype)highlightWithAttributes:(nullable NSDictionary<NSString *, id> *)attributes;

/**
 Convenience methods to create a default highlight with the specifeid background color.
 
 @param color The background border color.
 */
+ (instancetype)highlightWithBackgroundColor:(nullable UIColor *)color;

// Convenience methods below to set the `attributes`.
- (void)setFont:(nullable UIFont *)font;
- (void)setColor:(nullable UIColor *)color;
- (void)setStrokeWidth:(nullable NSNumber *)width;
- (void)setStrokeColor:(nullable UIColor *)color;
- (void)setShadow:(nullable PAZNTextShadow *)shadow;
- (void)setInnerShadow:(nullable PAZNTextShadow *)shadow;
- (void)setUnderline:(nullable PAZNTextDecoration *)underline;
- (void)setStrikethrough:(nullable PAZNTextDecoration *)strikethrough;
- (void)setBackgroundBorder:(nullable PAZNTextBorder *)border;
- (void)setBorder:(nullable PAZNTextBorder *)border;
- (void)setAttachment:(nullable PAZNTextAttachment *)attachment;

/**
 The user information dictionary, default is nil.
 */
@property (nullable, nonatomic, copy) NSDictionary *userInfo;

/**
 Tap action when user tap the highlight, default is nil.
 If the value is nil, PAZNTextView or PAZNLabel will ask it's delegate to handle the tap action.
 */
@property (nullable, nonatomic, copy) PAZNTextAction tapAction;

/**
 Long press action when user long press the highlight, default is nil.
 If the value is nil, PAZNTextView or PAZNLabel will ask it's delegate to handle the long press action.
 */
@property (nullable, nonatomic, copy) PAZNTextAction longPressAction;

@end

NS_ASSUME_NONNULL_END
