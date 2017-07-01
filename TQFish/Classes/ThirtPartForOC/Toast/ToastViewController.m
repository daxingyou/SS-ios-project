//
//  ToastViewController.m
//  demo
//
//  Created by spring on 14-3-7.
//
//

#import "ToastViewController.h"
#import "Toast+UIView.h"
#import "EAGLView.h"


@interface ToastViewController ()

@end

@implementation ToastViewController

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

+(ToastViewController *)open:(NSDictionary *)dict{
    ToastViewController *viewController = [[ToastViewController alloc] init];
    //viewController.view.frame = ((UIView *)[EAGLView sharedEGLView]).bounds;
    [[EAGLView sharedEGLView] addSubview:viewController.view];
    [viewController openToast:dict];
    return viewController;
}
-(void)openToast:(NSDictionary *)dict{
    NSString *msg = [dict objectForKey:@"msg"];
    float time = [[dict objectForKey:@"time"] floatValue];
    [self.view makeToast:msg
                duration:time
                position:@"center"];
    
}

#pragma mark - Rotation

- (BOOL)shouldAutorotateToInterfaceOrientation:(UIInterfaceOrientation)interfaceOrientation {
    return YES;
}

#pragma mark - Lifecycle

- (void)viewDidUnload {
    [super viewDidUnload];

}

#pragma mark - Memory Management

- (void)dealloc {
    [super dealloc];
}


@end
