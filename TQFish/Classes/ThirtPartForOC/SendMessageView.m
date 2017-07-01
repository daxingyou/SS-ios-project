//
//  SendMessageView.m
//  demo
//
//  Created by spring on 14-3-4.
//
//

#import "SendMessageView.h"
#import "SendSMS.h"


@interface SendMessageView ()

@end

@implementation SendMessageView


- (id)initWithNibName:(NSString *)nibNameOrNil bundle:(NSBundle *)nibBundleOrNil
{
    self = [super initWithNibName:nibNameOrNil bundle:nibBundleOrNil];
    if (self) {
        // Custom initialization
    }
    return self;
}

- (void)viewDidLoad
{
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    
}


+(SendMessageView *)openView:(NSDictionary *)dict
{
    UIWindow *window = [[UIApplication sharedApplication] keyWindow];
    SendMessageView *viewController = [[SendMessageView alloc] init];
    [window addSubview:viewController.view];
    [viewController sendMsg:viewController msg:dict];
    [viewController.view setTag:20000];
    return viewController;
}
-(void)sendMsg:(UIViewController *)view msg:(NSDictionary *)dict
{
    NSString *num = [dict objectForKey:@"mobilevalue"];
    NSString *msg = [dict objectForKey:@"messagevalue"];
    
    
    [SendSMS sendMessage:msg toContacts:[NSArray arrayWithObjects:num, nil]  delegate:view];
    
    
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}


@end
