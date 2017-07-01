//
//  URLConnect.h
//  BrithdaySMS
//
//  Created by huang he on 12-10-23.
//  Copyright (c) 2012年 huang he. All rights reserved.
//

#import <Foundation/Foundation.h>

@class URLConnect;
@protocol URLConnectDelegeta <NSObject>


- (void)connectionDidFinishLoading:(URLConnect *)connection data:(NSData *)data userInfo:(NSDictionary *)userInfo;


@end

@interface URLConnect : NSObject{
    int tag;
    id<URLConnectDelegeta> delegate;
    NSURLConnection *theConnection;
    NSDictionary *userInfo;
    NSMutableData * responsData;
}
@property(nonatomic,retain)NSDictionary *userInfo;
@property(nonatomic,assign)id delegate;
@property(nonatomic,retain)NSURLConnection *theConnection;
@property(nonatomic,retain)NSMutableData * responsData;

+ (URLConnect*)connectionWithRequest:(NSURLRequest *)request delegate:(id)delegate userInfo:(NSDictionary *)user;

- (void)start;
-(void)cancel;

@end
