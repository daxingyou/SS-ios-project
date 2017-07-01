//
//  ToastViewController.h
//  demo
//
//  Created by spring on 14-3-7.
//
//

#import <UIKit/UIKit.h>

@interface ToastViewController : UIViewController<UIGestureRecognizerDelegate>
{
    
}
+(ToastViewController *)open:(NSDictionary *)dict;
-(void)openToast:(NSDictionary *)dict;

@end
