//
//  ViewController.m
//  Escape from Limbo Cocoa
//
//  Created by Jason Charrier on 11/18/2015.
//  Copyright © 2015 Jason Charrier. All rights reserved.
//

#import "ViewController.h"

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];

    // Do any additional setup after loading the view.
}

- (void)setRepresentedObject:(id)representedObject {
    [super setRepresentedObject:representedObject];

    // Update the view, if already loaded.
}

- (IBAction)navButtonPushed:(NSButtonCell *)sender {

    [self.textDisplay insertText:sender.title];

}

@end
