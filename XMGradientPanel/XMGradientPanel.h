//
//  XMGradientPanel.h
//  DateLine 2
//
//  Created by Alex Clarke on 5/05/11.
//  Copyright 2011 MachineCodex Software. All rights reserved.
//

#import <Foundation/Foundation.h>

@class XMGradientPicker;
@class XMGradientWell;

#define XMGradientPanelGradientChangedNotification @"XMGradientPanelGradientChangedNotification"

@interface XMGradientPanel : NSPanel <NSSplitViewDelegate>

+ (XMGradientPanel *)sharedGradientPanel;
+ (BOOL)sharedGradientPanelExists;

@property (nonatomic, retain) NSGradient * gradient;
@property (retain) IBOutlet XMGradientPicker * picker;
@property (retain) IBOutlet XMGradientWell * previewSwatch;
@property (weak) IBOutlet NSSplitView * splitView;
@property (weak) IBOutlet NSView * swatchWellsView;
@property (assign) BOOL isContinuous;
@property (assign) SEL action;
@property (assign) id target;

- (void) deactivateOtherWells:(id)sender;

- (IBAction) reverseGradient:(id)sender;

@end


#pragma mark -
#pragma mark -
#pragma mark Gradient List 

@interface XMGradientPanel (GradientWells)

- (void) restoreGradientWells;
- (void) saveGradientWells;

@end
