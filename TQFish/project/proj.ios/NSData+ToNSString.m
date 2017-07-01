//
//  NSData+ToNSString.m
//  LoanAssistant
//
//  Created by 宜信 on 13-12-16.
//  Copyright (c) 2013年 LoanAssistant. All rights reserved.
//

#import "NSData+ToNSString.h"

@implementation NSData (ToNSString)

-(NSString *)ConvertToNSString
{
    
    NSMutableString *strTemp = [NSMutableString stringWithCapacity:[self length]*2];
    
    const unsigned char *szBuffer = [self bytes];
    
    for (NSInteger i=0; i < [self length]; ++i) {
        
        [strTemp appendFormat:@"%02lx",(unsigned long)szBuffer[i]];
        
    }
    
    return [[strTemp retain] autorelease];
    
}

@end
