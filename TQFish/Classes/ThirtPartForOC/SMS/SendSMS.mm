//
//  LSSendSMS.m
//  LongSMS
//
//  Created by he huang on 11-11-26.
//  Copyright (c) 2011年 __MyCompanyName__. All rights reserved.
//

#import "SendSMS.h"
#import "AppDelegate.h"
 

static SendSMS *sendSMS;
@implementation SendSMS


+ (void)sendMessage:(NSString *)content toContacts:(NSArray *)contacts delegate:(UIViewController *)delegate {
    
    if(sendSMS == nil){
        sendSMS = [[SendSMS alloc] init];
    }
    
	if([[UIDevice currentDevice].systemVersion floatValue] >= 4.0){
		if([MFMessageComposeViewController canSendText]){
			
			MFMessageComposeViewController *controller = [[MFMessageComposeViewController alloc] init];
			controller.navigationBar.tintColor = [UIColor blackColor];
			controller.messageComposeDelegate = sendSMS;
			
    
            controller.recipients = contacts;
            
         
			controller.body = content;
            
            [[UIApplication sharedApplication].keyWindow.rootViewController presentModalViewController:controller animated:YES];
    
			//[delegate presentViewController:controller animated:YES completion:nil];
            
            [controller release];
		
		}
		else{
			UIAlertView *alert = [[UIAlertView alloc] initWithTitle:@"出错了" message:@"您的设备不能发送短信" delegate:nil cancelButtonTitle:@"取消" otherButtonTitles:nil];
			[alert show];
	
		}
	}
	else {
		[[UIApplication sharedApplication] openURL:[NSURL URLWithString:[NSString stringWithFormat:@"sms:%@", @""]]];
	}
}

- (void)messageComposeViewController:(MFMessageComposeViewController *)controller didFinishWithResult:(MessageComposeResult)result{
	NSString *msg = nil;
    
    
	switch (result) {
		case MessageComposeResultCancelled:
            msg = @"短信发送取消";
			break;
			
		case MessageComposeResultSent:
			msg = @"短信发送成功";
            
            
			break;
			
		case MessageComposeResultFailed:
			msg = @"短信发送失败";
			break;
			
		default:
			break;
	}
	
	if (msg){
        //UIAlertView *alert = [[UIAlertView alloc] initWithTitle:@"" message:msg delegate:nil cancelButtonTitle:@"确认" otherButtonTitles:nil];
        //[alert show];
        //[alert release];
    }
    
	[controller dismissViewControllerAnimated:false completion:nil];
    [self.view removeFromSuperview];
    [[[[UIApplication sharedApplication] keyWindow] viewWithTag:20000] removeFromSuperview];
    

}

-(void)dealloc{

    [super dealloc];
}

@end


@implementation MFMessageComposeViewController(Screen)

- (BOOL)shouldAutorotateToInterfaceOrientation:(UIInterfaceOrientation)interfaceOrientation
{
	// iPhone only
    //    [UIApplication sharedApplication].statusBarHidden = YES;
    
	if( [[UIDevice currentDevice] userInterfaceIdiom] == UIUserInterfaceIdiomPhone )
		return UIInterfaceOrientationIsLandscape(interfaceOrientation);
	
	// iPad only
	// iPhone only
	return UIInterfaceOrientationIsLandscape(interfaceOrientation);
}

@end
