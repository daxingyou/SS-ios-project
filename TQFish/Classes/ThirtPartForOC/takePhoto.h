//
//  takePhoto.h
//  cocos2d-ImageTest
//
//  Created by spring on 14-1-14.
//
//

#import <UIKit/UIKit.h>

@interface takePhoto : UIViewController<UIImagePickerControllerDelegate,UINavigationControllerDelegate>



+(takePhoto *)snapImage;

-(void)openPhoto;


@end
