//
//  XMViewControl.m
//  XMGradientPanel
//
//  Created by Alex Clarke on 2/07/11.
//  Copyright 2011 MachineCodex Software. All rights reserved.
//

#import "XMViewControl.h"

@implementation XMViewControl

#pragma mark -
#pragma mark Setup

- (id)initWithFrame:(NSRect)theFrame {

	if(![super initWithFrame:theFrame])
		return nil;
    
	self.isEnabled = YES;
	return self;
}

- (id)initWithCoder:(NSCoder*)theCoder {
    
	if (![super initWithCoder:theCoder])
		return nil;
    
	self.isEnabled = YES;
	return self;
}

- (void)encodeWithCoder:(NSCoder*)theCoder {
	
	[super encodeWithCoder:theCoder];
}


#pragma mark -
#pragma mark Drawing

- (void)drawInContext:(CGContextRef)theContext {
    
	// subclasses can override this to do custom drawing
}

- (void)drawRect:(NSRect)theRect {
	
	CGContextRef aContext = [[NSGraphicsContext currentContext] graphicsPort];
    [self drawInContext:aContext];
}


#pragma mark -
#pragma mark Perform Action

- (void)performAction {
    
	if([_target respondsToSelector:_action])
		[_target performSelector:_action withObject:self];
}


#pragma mark -
#pragma mark Accessors

- (void)setIsEnabled:(BOOL)theBool {
    
    [self willChangeValueForKey:@"isEnabled"];
	_isEnabled = theBool;
    [self didChangeValueForKey:@"isEnabled"];
    
	if(theBool==NO && [[self window] firstResponder]==self)
		[[self window] makeFirstResponder:nil];
    
	[self setNeedsDisplay:YES];
}

@end
