//
//  UpdateItunesController.h
//  demo
//
//  Created by spring on 14-4-18.
//
//

#import <UIKit/UIKit.h>

@interface UpdateItunesController : UIViewController<UIAlertViewDelegate>
{
    NSString *url;
}
@property(nonatomic,retain) NSString *url;
+(UpdateItunesController *)openUpdateAlert;

-(void)update;
@end
