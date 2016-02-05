//
//  ViewController.h
//  Escape from Limbo Cocoa
//
//  Created by Jason Charrier on 11/18/2015.
//  Copyright © 2015 Jason Charrier. All rights reserved.
//

#import <Cocoa/Cocoa.h>

@interface ViewController : NSViewController
@property (weak) IBOutlet NSButton *navButtonNorth;
@property (weak) IBOutlet NSButton *navButtonWest;
@property (weak) IBOutlet NSButton *navButtonEast;
@property (weak) IBOutlet NSButton *navButtonSouth;
@property (unsafe_unretained) IBOutlet NSTextView *textDisplay;


@end

