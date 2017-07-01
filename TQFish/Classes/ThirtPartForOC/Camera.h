//
//  Camera.h
//  demo
//
//  Created by spring on 14-1-14.
//
//

#import <Foundation/Foundation.h>

@interface Camera :UIViewController<UIImagePickerControllerDelegate,UINavigationControllerDelegate> {
    
}
+(Camera*)TakePhoto;
//打开摄像头
-(void)OpenCamera;
@end
