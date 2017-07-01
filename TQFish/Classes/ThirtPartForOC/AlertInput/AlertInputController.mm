//
//  AlertInputController.m
//  demo
//
//  Created by spring on 14-3-6.
//
//

#import "AlertInputController.h"
#import "platform/ios/CCNativeIOS.h"

#import "CCLuaObjcBridge.h"
#import "EAGLView.h"


#import "MKEntryPanel.h"


@interface AlertInputController ()

@end

@implementation AlertInputController


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


+(AlertInputController *)open:(NSDictionary *)dict
{

    AlertInputController *viewController = [[AlertInputController alloc] init];
    viewController.view.frame = ((UIView *)[EAGLView sharedEGLView]).bounds;
    [[EAGLView sharedEGLView] addSubview:viewController.view];
    [viewController.view setTag:40000];
    [viewController openAlert:dict];
    return viewController;
    
    
}

-(void)openAlert:(NSDictionary *)dict
{
     NSString *call = [dict objectForKey:@"call"];
    NSString *msg = [dict objectForKey:@"flag"];
    [MKEntryPanel showPanelWithTitle:NSLocalizedString(@"输入内容", @"")
                             content:msg
                              inView:self.view
                       onTextEntered:^(NSString* enteredString)
     {
         NSLog(@"Entered: %@", enteredString);
         
         //回调
         int callBackFunction = [call intValue];
         
         // 1. 将引用 ID 对应的 Lua function 放入 Lua stack
         CCLuaObjcBridge::pushLuaFunctionById(callBackFunction);
         
         // 2. 将需要传递给 Lua function 的参数放入 Lua stack
         
         CCLuaValueDict item;
         //useravatorInApp
         std::string *bar = new std::string([enteredString UTF8String]);
         item["value"] = CCLuaValue::stringValue(*bar);
         
         
         CCLuaObjcBridge::getStack()->pushCCLuaValueDict(item);
         
         // 3. 执行 Lua function
         CCLuaObjcBridge::getStack()->executeFunction(1);
         
         // 4. 释放引用 ID
         CCLuaObjcBridge::releaseLuaFunctionById(callBackFunction);
         //[[EAGLView sharedEGLView] addSubview:viewController.view];
         //[[EAGLView sharedEGLView]]
         [[[[UIApplication sharedApplication] keyWindow] viewWithTag:40000] removeFromSuperview];
         //[self.view removeFromSuperview];
     }];
    


    
}
- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

@end
