//
//  SendMessageView.h
//  demo
//
//  Created by spring on 14-3-4.
//
//

#import <UIKit/UIKit.h>

@interface SendMessageView : UIViewController<UINavigationControllerDelegate>{
    //UIViewController *delegate;

}

//@property(nonatomic,assign)UIViewController *delegate;
+(SendMessageView *)openView:(NSDictionary *)dict;

-(void)sendMsg:(UIViewController *) view msg:(NSDictionary *)dict;


@end
