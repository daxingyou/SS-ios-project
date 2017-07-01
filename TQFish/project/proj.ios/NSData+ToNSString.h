//
//  NSData+ToNSString.h
//  LoanAssistant
//
//  Created by 宜信 on 13-12-16.
//  Copyright (c) 2013年 LoanAssistant. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSData (ToNSString)

// 去掉<213  123313 123> 中的前后尖括号和空格
-(NSString *)ConvertToNSString;

@end
