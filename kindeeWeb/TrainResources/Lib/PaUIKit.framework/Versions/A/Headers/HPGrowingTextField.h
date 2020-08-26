//
//  HPTextView.h
//
//  Created by Hans Pinckaers on 29-06-10.
//
//	MIT License
//
//	Copyright (c) 2011 Hans Pinckaers
//
//	Permission is hereby granted, free of charge, to any person obtaining a copy
//	of this software and associated documentation files (the "Software"), to deal
//	in the Software without restriction, including without limitation the rights
//	to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
//	copies of the Software, and to permit persons to whom the Software is
//	furnished to do so, subject to the following conditions:
//
//	The above copyright notice and this permission notice shall be included in
//	all copies or substantial portions of the Software.
//
//	THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//	IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//	FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
//	AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//	LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
//	OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
//	THE SOFTWARE.

#import <UIKit/UIKit.h>

#if __IPHONE_OS_VERSION_MAX_ALLOWED < 60000
	// UITextAlignment is deprecated in iOS 6.0+, use NSTextAlignment instead.
	// Reference: https://developer.apple.com/library/ios/documentation/uikit/reference/NSString_UIKit_Additions/Reference/Reference.html
	#define NSTextAlignment UITextAlignment
#endif

@class HPGrowingTextField;

@protocol HPGrowingTextFieldDelegate

@optional
- (BOOL)growingTextViewShouldBeginEditing:(HPGrowingTextField *)growingTextView;
- (BOOL)growingTextViewShouldEndEditing:(HPGrowingTextField *)growingTextView;

- (void)growingTextViewDidBeginEditing:(HPGrowingTextField *)growingTextView;
- (void)growingTextViewDidEndEditing:(HPGrowingTextField *)growingTextView;

- (BOOL)growingTextView:(HPGrowingTextField *)growingTextView shouldChangeTextInRange:(NSRange)range replacementText:(NSString *)text;
- (void)growingTextViewDidChange:(HPGrowingTextField *)growingTextView;

- (void)growingTextView:(HPGrowingTextField *)growingTextView willChangeHeight:(float)height;
- (void)growingTextView:(HPGrowingTextField *)growingTextView didChangeHeight:(float)height;

- (void)growingTextViewDidChangeSelection:(HPGrowingTextField *)growingTextView;
- (BOOL)growingTextViewShouldReturn:(HPGrowingTextField *)growingTextView;
@end

@interface HPGrowingTextField : UIView <UITextFieldDelegate> {
	UITextField *internalTextView;
    
    int maxTextLength;
	
	int minHeight;
	int maxHeight;
	
	BOOL animateHeightChange;
    NSTimeInterval animationDuration;
	
	//uitextview properties
	NSObject <HPGrowingTextFieldDelegate> *__unsafe_unretained delegate;
	NSTextAlignment textAlignment;

	BOOL editable;
	UIReturnKeyType returnKeyType;
	UIKeyboardType keyboardType;
    
    UIEdgeInsets contentInset;
}

//real class properties
@property (nonatomic) int maxTextLength;
@property (nonatomic) int maxHeight;
@property (nonatomic) int minHeight;
@property BOOL animateHeightChange;
@property NSTimeInterval animationDuration;
@property (nonatomic, strong) NSString *placeholder;
@property (nonatomic, strong) UIColor *placeholderColor;
@property (nonatomic, strong) UITextField *internalTextView;


//uitextview properties
@property(unsafe_unretained) NSObject<HPGrowingTextFieldDelegate> *delegate;
@property(nonatomic,strong) NSString *text;
@property(nonatomic,strong) UIFont *font;
@property(nonatomic,strong) UIColor *textColor;
@property(nonatomic) NSTextAlignment textAlignment;    // default is NSTextAlignmentLeft
@property(nonatomic,getter=isEditable) BOOL editable;
@property (nonatomic) UIReturnKeyType returnKeyType;
@property (nonatomic) UIKeyboardType keyboardType;
@property (assign) UIEdgeInsets contentInset;
@property (nonatomic) BOOL isScrollable;
@property(nonatomic) BOOL enablesReturnKeyAutomatically;

#if __IPHONE_OS_VERSION_MIN_REQUIRED >= 70000
- (id)initWithFrame:(CGRect)frame textContainer:(NSTextContainer *)textContainer;
#endif

//uitextview methods
//need others? use .internalTextView
- (BOOL)becomeFirstResponder;
- (BOOL)resignFirstResponder;
- (BOOL)isFirstResponder;

- (BOOL)hasText;



@end
