//
//  XMViewControl.h
//  XMGradientPanel
//
//  Created by Alex Clarke on 2/07/11.
//  Copyright 2011 MachineCodex Software. All rights reserved.
//

#import <Cocoa/Cocoa.h>

@interface XMViewControl : NSView 
@property (readwrite, nonatomic, assign) BOOL isEnabled;
@property (readwrite, assign) id target;
@property (readwrite, assign) SEL action;

- (void) performAction;

@end
