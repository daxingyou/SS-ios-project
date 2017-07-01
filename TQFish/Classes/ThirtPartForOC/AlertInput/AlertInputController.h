//
//  AlertInputController.h
//  demo
//
//  Created by spring on 14-3-6.
//
//

#import <UIKit/UIKit.h>

@interface AlertInputController : UIViewController<UIAlertViewDelegate>
{
    
}


+(AlertInputController *) open:(NSDictionary *)dict;

-(void) openAlert:(NSDictionary *)dict;
@end
