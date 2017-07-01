//
//  UIView+Alert.m
//  TqLord
//
//  Created by huang he on 12-12-1.
//  Copyright (c) 2012年 huang he. All rights reserved.
//

#import "NSObject+Alert.h"


static TKLoadingView *theLoadingView = nil;
@implementation NSObject (Alert)
@dynamic tkLoadingView;

-(void)alertWithString:(NSString *)content{
    [[TKAlertCenter defaultCenter] postAlertWithMessage:content];
    
}

-(TKLoadingView *)tkLoadingView{
    if(theLoadingView == nil){
        theLoadingView = [[TKLoadingView alloc] initWithTitle:@"加载中"];
    }
    return theLoadingView;
}
@end
