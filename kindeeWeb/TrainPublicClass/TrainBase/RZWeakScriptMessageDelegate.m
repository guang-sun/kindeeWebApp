//
//  RZWeakScriptMessageDelegate.m
//  YGProject
//
//  Created by admin on 2017/10/30.
//  Copyright © 2017年 YG. All rights reserved.
//

#import "RZWeakScriptMessageDelegate.h"

@implementation RZWeakScriptMessageDelegate


- (instancetype)initWithDelegate:(id<WKScriptMessageHandler>)scriptDelegate
{
    self = [super init];
    if (self) {
        _scriptDelegate = scriptDelegate;
    }
    return self;
}

- (void)userContentController:(WKUserContentController *)userContentController didReceiveScriptMessage:(WKScriptMessage *)message
{
    [self.scriptDelegate userContentController:userContentController didReceiveScriptMessage:message];
}

- (void)dealloc
{
    
    NSLog(@"WKWebViewWeakDelegate==>>%@",[self class]);
}

@end
