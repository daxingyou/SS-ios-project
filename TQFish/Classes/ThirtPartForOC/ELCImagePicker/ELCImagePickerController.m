//
//  ELCImagePickerController.m
//  ELCImagePickerDemo
//
//  Created by ELC on 9/9/10.
//  Copyright 2010 ELC Technologies. All rights reserved.
//

#import "ELCImagePickerController.h"
#import "ELCAsset.h"
#import "ELCAssetCell.h"
#import "ELCAssetTablePicker.h"
#import "ELCAlbumPickerController.h"
#import <CoreLocation/CoreLocation.h>

@implementation ELCImagePickerController

- (id)initWithRootViewController:(UIViewController *)rootViewController
{
    self = [super initWithRootViewController:rootViewController];
    if (self) {
//        self.maximumImagesCount = FLT_MAX;
    }
    return self;
}

- (void)cancelImagePicker
{
	if ([_imagePickerDelegate respondsToSelector:@selector(elcImagePickerControllerDidCancel:)]) {
		[_imagePickerDelegate performSelector:@selector(elcImagePickerControllerDidCancel:) withObject:self];
	}
}

- (BOOL)shouldSelectAsset:(ELCAsset *)asset previousCount:(NSUInteger)previousCount
{
    BOOL shouldSelect = previousCount < self.maximumImagesCount;
    if (!shouldSelect) {
        NSString *message = [NSString stringWithFormat:NSLocalizedString(@"最多只能选择%d图片", nil), self.maximumImagesCount];
        [[[UIAlertView alloc] initWithTitle:nil
                                    message:message
                                   delegate:nil
                          cancelButtonTitle:nil
                          otherButtonTitles:NSLocalizedString(@"确定", nil), nil] show];
    }
    return shouldSelect;
}

- (void)selectedAssets:(NSArray *)assets
{
	NSMutableArray *returnArray = [[NSMutableArray alloc] init];
	
	for(ALAsset *asset in assets) {
		id obj = [asset valueForProperty:ALAssetPropertyType];
		if (!obj) {
			continue;
		}
		NSMutableDictionary *workingDictionary = [[NSMutableDictionary alloc] init];
		
		CLLocation* wgs84Location = [asset valueForProperty:ALAssetPropertyLocation];
		if (wgs84Location) {
			[workingDictionary setObject:wgs84Location forKey:ALAssetPropertyLocation];
		}
        
        [workingDictionary setObject:obj forKey:UIImagePickerControllerMediaType];

        //defaultRepresentation returns image as it appears in photo picker, rotated and sized,
        //so use UIImageOrientationUp when creating our image below.
        ALAssetRepresentation *assetRep = [asset defaultRepresentation];
        
        CGImageRef imgRef = [assetRep fullScreenImage];
        UIImage *img = [UIImage imageWithCGImage:imgRef
                                           scale:1.0f
                                     orientation:UIImageOrientationUp];
        [workingDictionary setObject:img forKey:UIImagePickerControllerOriginalImage];
		[workingDictionary setObject:[[asset valueForProperty:ALAssetPropertyURLs] valueForKey:[[[asset valueForProperty:ALAssetPropertyURLs] allKeys] objectAtIndex:0]] forKey:UIImagePickerControllerReferenceURL];
		
		[returnArray addObject:workingDictionary];
		
	}    
	if (_imagePickerDelegate != nil && [_imagePickerDelegate respondsToSelector:@selector(elcImagePickerController:didFinishPickingMediaWithInfo:)]) {
		[_imagePickerDelegate performSelector:@selector(elcImagePickerController:didFinishPickingMediaWithInfo:) withObject:self withObject:returnArray];
	} else {
        [self popToRootViewControllerAnimated:NO];
    }
}

- (BOOL)shouldAutorotateToInterfaceOrientation:(UIInterfaceOrientation)toInterfaceOrientation
{
    if (UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPad) {
        return YES;
    } else {
        return toInterfaceOrientation != UIInterfaceOrientationPortraitUpsideDown;
    }
}

@end