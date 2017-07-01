//
//  UIView+Alert.h
//  TqLord
//
//  Created by huang he on 12-12-1.
//  Copyright (c) 2012年 huang he. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "TKLoadingView.h"
#import "TKAlertCenter.h"

@interface NSObject (Alert)

@property(nonatomic,retain)TKLoadingView *tkLoadingView;
-(void)alertWithString:(NSString *)content;
@end


//@interface UIButton<nskey> (value)
//
//@end
