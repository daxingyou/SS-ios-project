//
//  URLConnect.m
//  BrithdaySMS
//
//  Created by huang he on 12-10-23.
//  Copyright (c) 2012年 huang he. All rights reserved.
//

#import "URLConnect.h"

@implementation URLConnect


@synthesize delegate;
@synthesize theConnection;
@synthesize userInfo;
@synthesize responsData;

+ (URLConnect*)connectionWithRequest:(NSURLRequest *)request delegate:(id)delegate userInfo:(NSDictionary *)user{
    URLConnect *urlConnect  = [[URLConnect alloc] init];
    urlConnect.userInfo = user;
    urlConnect.delegate = delegate;
    urlConnect.theConnection = [NSURLConnection connectionWithRequest:request delegate:urlConnect];
    return urlConnect;
}

-(void)start{
    [theConnection start];
}
-(void)cancel{
    [theConnection cancel];
}

- (void)connection:(NSURLConnection *)connection didReceiveResponse:(NSURLResponse *)respons{
    responsData = [NSMutableData  new]; 
}
- (void)connection:(NSURLConnection *)connection didReceiveData:(NSData *)data{
    [responsData appendData:data];
//    [delegate connection:self didReceiveData:data userInfo:userInfo];
//    [delegate connection:connection didReceiveData:data userInfo:userInfo];
    
}

- (void)connectionDidFinishLoading:(NSURLConnection *)connection{
    
    [delegate connectionDidFinishLoading:self data:responsData userInfo:userInfo];
   
    [self autorelease];

}


-(void)dealloc{
    [theConnection release];
    [userInfo release];
    [responsData release];
    [super dealloc];
}



@end
