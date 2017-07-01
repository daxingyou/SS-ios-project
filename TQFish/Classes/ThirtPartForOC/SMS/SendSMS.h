//
//  LSSendSMS.h
//  LongSMS
//
//  Created by he huang on 11-11-26.
//  Copyright (c) 2011年 __MyCompanyName__. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <MessageUI/MFMessageComposeViewController.h>

@interface SendSMS : UIViewController<MFMessageComposeViewControllerDelegate>{
    //    NSString *smsContent;
    //    NSString *telephone;
    
}
//@property(nonatomic,retain) NSString *smsContent;
//@property(nonatomic,retain) NSString *telephone;
+ (void)sendMessage:(NSString *)content toContacts:(NSArray *)contacts delegate:(UIViewController *)delegate;

@end


@interface MFMessageComposeViewController (Screen)

@end
