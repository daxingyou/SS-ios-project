//
//  IAPPayment.m
//  demo
//
//  Created by spring on 14-3-31.
//
//

#import "IAPPayment.h"
#import "CCLuaObjcBridge.h"
#import "platform/ios/CCNativeIOS.h"
#import "Helper.h"

/*
 6=6*10=60
 30=30*12=360
 68=68*13=884
 128=128*15=1920
 328=328*18=5904
 648=648*20=12960
 */
#define ProductID_IAP6 @"com.tqgame.jinhua6"//6
#define ProductID_IAP30 @"com.tqgame.jinhua30"//30
#define ProductID_IAP68 @"com.tqgame.jinhua68"//68
#define ProductID_IAP128 @"com.tqgame.jinhua128"//128
#define ProductID_IAP328 @"com.tqgame.jinhua328"//328
#define ProductID_IAP648 @"com.tqgame.jinhua648"//648

static IAPPayment *iapPayment = nil;

@implementation IAPPayment

@synthesize yuanbao;

+(IAPPayment *)shareIAPPayment
{
    if(iapPayment == nil){
        iapPayment = [[IAPPayment alloc] init];
    }
    
    return iapPayment;
}

-(id)init
{
    if ((self = [super init])) {
        [[SKPaymentQueue defaultQueue] addTransactionObserver:self];
        //[self buy:IAP6];
    }
    return self;
}
-(void) getOrderID:(NSDictionary *)dict
{
    NSString *yuabbaoS = [dict objectForKeyedSubscript:@"yuanbao"];
    self.yuanbao =yuabbaoS;
    
    
    int callBackFunction = [[dict objectForKey:@"callback"] intValue];
    
    // 1. 将引用 ID 对应的 Lua function 放入 Lua stack
    CCLuaObjcBridge::pushLuaFunctionById(callBackFunction);
    
    // 2. 将需要传递给 Lua function 的参数放入 Lua stack
    
    CCLuaValueDict item;
    //useravatorInApp
    CCLuaObjcBridge::getStack()->pushCCLuaValueDict(item);
    
    // 3. 执行 Lua function
    CCLuaObjcBridge::getStack()->executeFunction(1);
    
    // 4. 释放引用 ID
    CCLuaObjcBridge::releaseLuaFunctionById(callBackFunction);
}

-(void)buy
{
    buyType = [self.yuanbao intValue];
    if ([SKPaymentQueue canMakePayments]) {
        //[[SKPaymentQueue defaultQueue] restoreCompletedTransactions];
        [self RequestProductData];
        
    }
    else
    {
        
        UIAlertView *alerView =  [[UIAlertView alloc] initWithTitle:@"提示"
                                                            message:@"你没允许应用程序内购买"
                                                           delegate:nil cancelButtonTitle:NSLocalizedString(@"关闭",nil) otherButtonTitles:nil];
        
        [alerView show];
        [alerView release];
        
    }
}

- (void)buyWithProductID:(NSString *)pID
{
    if ([SKPaymentQueue canMakePayments]) {
        [self RequestProductDataWithProductID:pID];
    }else {
        UIAlertView *alerView =  [[UIAlertView alloc] initWithTitle:@"提示"
                                                            message:@"你没允许应用程序内购买"
                                                           delegate:nil cancelButtonTitle:NSLocalizedString(@"关闭",nil) otherButtonTitles:nil];
        [alerView show];
        [alerView release];
    }
}

-(bool)CanMakePay
{
    return [SKPaymentQueue canMakePayments];
}

-(void)RequestProductData
{
    NSLog(@"---------请求对应的产品信息------------");
    NSArray *product = nil;
    switch (buyType) {
        case IAP6:
            product=[[NSArray alloc] initWithObjects:ProductID_IAP6,nil];
            break;
        case IAP30:
            product=[[NSArray alloc] initWithObjects:ProductID_IAP30,nil];
            break;
        case IAP68:
            product=[[NSArray alloc] initWithObjects:ProductID_IAP68,nil];
            break;
        case IAP128:
            product=[[NSArray alloc] initWithObjects:ProductID_IAP128,nil];
            break;
        case IAP328:
            product=[[NSArray alloc] initWithObjects:ProductID_IAP328,nil];
            break;
        case IAP648:
            product=[[NSArray alloc] initWithObjects:ProductID_IAP648,nil];
            break;

            
            
        default:
            break;
    }
    NSSet *nsset = [NSSet setWithArray:product];
    SKProductsRequest *request=[[SKProductsRequest alloc] initWithProductIdentifiers: nsset];
    request.delegate=self;
    [request start];
    [product release];
}

-(void)RequestProductDataWithProductID:(NSString *)pID
{
    NSArray *product = @[pID];

    NSSet *nsset = [NSSet setWithArray:product];
    SKProductsRequest *request=[[SKProductsRequest alloc] initWithProductIdentifiers: nsset];
    request.delegate=self;
    [request start];
    //[product release];
}

//<SKProductsRequestDelegate> 请求协议
//收到的产品信息
- (void)productsRequest:(SKProductsRequest *)request didReceiveResponse:(SKProductsResponse *)response{
    
    NSLog(@"-----------收到产品反馈信息--------------");
    NSArray *myProduct = response.products;
    NSLog(@"产品Product ID:%@",response.invalidProductIdentifiers);
    NSLog(@"产品付费数量: %u", [myProduct count]);
    // populate UI
    for(SKProduct *product in myProduct){
        NSLog(@"product info");
        NSLog(@"SKProduct 描述信息%@", [product description]);
        NSLog(@"产品标题 %@" , product.localizedTitle);
        NSLog(@"产品描述信息: %@" , product.localizedDescription);
        NSLog(@"价格: %@" , product.price);
        NSLog(@"Product id: %@" , product.productIdentifier);
    }
//    SKPayment *payment = nil;
//    switch (buyType) {
//        case IAP6:
//            //payment  = [SKPayment paymentWithProductIdentifier:ProductID_IAP6];    //支付6
//            payment = [SKPayment paymentWithProduct:myProduct[0]];
//            break;
//        case IAP30:
//            payment  = [SKPayment paymentWithProductIdentifier:ProductID_IAP30];    //支付30
//            break;
//        case IAP68:
//            payment  = [SKPayment paymentWithProductIdentifier:ProductID_IAP68];    //支付68
//            break;
//        case IAP128:
//            payment  = [SKPayment paymentWithProductIdentifier:ProductID_IAP128];    //支付128
//            break;
//        case IAP328:
//            payment  = [SKPayment paymentWithProductIdentifier:ProductID_IAP328];    //支付328
//            break;
//        case IAP648:
//            payment  = [SKPayment paymentWithProductIdentifier:ProductID_IAP648];    //支付648
//            break;
//        default:
//            break;
//    }
    
    if (myProduct.count > 0) {
        NSLog(@"---------发送购买请求------------");

        SKPayment *payment = [SKPayment paymentWithProduct:myProduct[0]]; // 该数组就1个商品，取下标0即可
        [[SKPaymentQueue defaultQueue] addPayment:payment];
        [request autorelease];
    }else{
        NSLog(@"---------发送购买请求失败------------");
        NSString *productidTip = [NSString stringWithFormat:@"购买失败，请联系客服! 产品Product ID:%@", response.invalidProductIdentifiers];
        UIAlertView *alView =  [[UIAlertView alloc] initWithTitle:@"提示"
                                                             message:productidTip
                                                            delegate:nil cancelButtonTitle:NSLocalizedString(@"关闭",nil) otherButtonTitles:nil];
        
        [alView show];
        [alView release];
    }
    
}
- (void)requestProUpgradeProductData
{
    NSLog(@"------请求升级数据---------");
    NSSet *productIdentifiers = [NSSet setWithObject:@"com.productid"];
    SKProductsRequest* productsRequest = [[SKProductsRequest alloc] initWithProductIdentifiers:productIdentifiers];
    productsRequest.delegate = self;
    [productsRequest start];
    
}
//弹出错误信息
- (void)request:(SKRequest *)request didFailWithError:(NSError *)error{
    NSLog(@"-------弹出错误信息----------");
    UIAlertView *alerView =  [[UIAlertView alloc] initWithTitle:NSLocalizedString(@"Alert",NULL) message:[error localizedDescription]
                                                       delegate:nil cancelButtonTitle:NSLocalizedString(@"Close",nil) otherButtonTitles:nil];
    [alerView show];
    [alerView release];
}

-(void) requestDidFinish:(SKRequest *)request
{
    NSLog(@"----------反馈信息结束--------------");
    
}

-(void) PurchasedTransaction: (SKPaymentTransaction *)transaction{
    NSLog(@"-----PurchasedTransaction----");
    NSArray *transactions =[[NSArray alloc] initWithObjects:transaction, nil];
    [self paymentQueue:[SKPaymentQueue defaultQueue] updatedTransactions:transactions];
    [transactions release];
}

//<SKPaymentTransactionObserver> 千万不要忘记绑定，代码如下：
//----监听购买结果
//[[SKPaymentQueue defaultQueue] addTransactionObserver:self];

- (void)paymentQueue:(SKPaymentQueue *)queue updatedTransactions:(NSArray *)transactions//交易结果
{
    [Helper hideLoadingView:[[NSDictionary alloc] initWithObjectsAndKeys:@"",@"", nil]];
    
    for (SKPaymentTransaction *transaction in transactions)
    {
        switch (transaction.transactionState)
        {
            case SKPaymentTransactionStatePurchased://交易完成
            {
                [self completeTransaction:transaction];
                
                UIAlertView *alerView =  [[UIAlertView alloc] initWithTitle:@"提示"
                                                                    message:@"购买成功"
                                                                   delegate:nil cancelButtonTitle:NSLocalizedString(@"关闭",nil) otherButtonTitles:nil];
                
                [alerView show];
                [alerView release];
            }
                break;
            case SKPaymentTransactionStateFailed://交易失败
            {
                NSLog(@"==ios payment error:%@", transaction.error);
                [self failedTransaction:transaction];
                
                UIAlertView *alerView2 =  [[UIAlertView alloc] initWithTitle:@"提示"
                                                                     message:@"购买失败，请重新尝试购买"
                                                                    delegate:nil cancelButtonTitle:NSLocalizedString(@"关闭",nil) otherButtonTitles:nil];
                
                [alerView2 show];
                [alerView2 release];
            }
                break;
            case SKPaymentTransactionStateRestored://已经购买过该商品
            {
                [self restoreTransaction:transaction];
            }
                
            case SKPaymentTransactionStatePurchasing:      //商品添加进列表
                
                break;
            default:
                break;
        }
    }
}
- (void) completeTransaction: (SKPaymentTransaction *)transaction
{
    NSLog(@"-----completeTransaction--------");
    // Your application should implement these two methods.
    NSString *temptransactionReceipt  = [[NSString alloc] initWithData:[transaction transactionReceipt] encoding:NSUTF8StringEncoding];
    NSString *productid = transaction.payment.productIdentifier;
    NSLog(@"productid = %@", transaction.payment.productIdentifier);
    
    //回调
    int callBackFunction = [[[NSUserDefaults standardUserDefaults] objectForKey:@"iapPayCallback"] intValue];
    // 1. 将引用 ID 对应的 Lua function 放入 Lua stack
    CCLuaObjcBridge::pushLuaFunctionById(callBackFunction);
    
    // 2. 将需要传递给 Lua function 的参数放入 Lua stack
    
    CCLuaValueDict item;
    //useravatorInApp

    std::string *msg = new std::string([temptransactionReceipt UTF8String]);
    std::string *mProductid = new std::string([productid UTF8String]);
   
    item["receipt"] = CCLuaValue::stringValue(*msg);
    item["productid"] = CCLuaValue::stringValue(*mProductid);
    
    CCLuaObjcBridge::getStack()->pushCCLuaValueDict(item);
    
    // 3. 执行 Lua function
    CCLuaObjcBridge::getStack()->executeFunction(1);
    
    // 4. 释放引用 ID
    //CCLuaObjcBridge::releaseLuaFunctionById(callBackFunction);
    // Remove the transaction from the payment queue.
    
    [[SKPaymentQueue defaultQueue] finishTransaction: transaction];
    
}

//记录交易
-(void)recordTransaction:(NSString *)product{
    NSLog(@"-----记录交易--------");
}

//处理下载内容
-(void)provideContent:(NSString *)product{
    NSLog(@"-----下载--------");
}

- (void) failedTransaction: (SKPaymentTransaction *)transaction{
    NSLog(@"失败");
    if (transaction.error.code != SKErrorPaymentCancelled)
    {
    }
    [[SKPaymentQueue defaultQueue] finishTransaction: transaction];
    
    
}
-(void) paymentQueueRestoreCompletedTransactionsFinished: (SKPaymentTransaction *)transaction{
    
}

- (void) restoreTransaction: (SKPaymentTransaction *)transaction

{
    NSLog(@" 交易恢复处理");
    
}

-(void) paymentQueue:(SKPaymentQueue *) paymentQueue restoreCompletedTransactionsFailedWithError:(NSError *)error{
    NSLog(@"-------paymentQueue----");
}


#pragma mark connection delegate
- (void)connection:(NSURLConnection *)connection didReceiveData:(NSData *)data
{
    NSLog(@"%@",  [[[NSString alloc] initWithData:data encoding:NSUTF8StringEncoding] autorelease]);
}
- (void)connectionDidFinishLoading:(NSURLConnection *)connection{
    
}

- (void)connection:(NSURLConnection *)connection didReceiveResponse:(NSURLResponse *)response{
    switch([(NSHTTPURLResponse *)response statusCode]) {
        case 200:
        case 206:
            break;
        case 304:
            break;
        case 400:
            break;
        case 404:
            break;
        case 416:
            break;
        case 403:
            break;
        case 401:
        case 500:
            break;
        default:
            break;
    }
}

- (void)connection:(NSURLConnection *)connection didFailWithError:(NSError *)error {
    NSLog(@"test");
}

-(void)dealloc
{
    [[SKPaymentQueue defaultQueue] removeTransactionObserver:self];//解除监听
    [super dealloc];
}

- (void)showStoreProductInApp{
    
    Class isAllow = NSClassFromString(@"SKStoreProductViewController");
    
    if (isAllow != nil) {
        
        SKStoreProductViewController *sKStoreProductViewController = [[SKStoreProductViewController alloc] init];
        [sKStoreProductViewController.view setFrame:CGRectMake(0, 200, 320, 200)];
        [sKStoreProductViewController setDelegate:self];
        [sKStoreProductViewController loadProductWithParameters:@{SKStoreProductParameterITunesItemIdentifier:@"935568626"}
                                                completionBlock:^(BOOL result, NSError *error) {
                                                    if (result) {
                                                        [self presentViewController:sKStoreProductViewController
                                                                           animated:YES
                                                                         completion:nil];
                                                    }else{
                                                        NSLog(@"error:%@",error);
                                                    }
                                                }];
    }else{
        //低于iOS6的系统版本没有这个类,不支持这个功能
        NSString *string = [NSString stringWithFormat:@"https://itunes.apple.com/cn/app/feng-kuang-dou-zhu-zhen-ren+chuang/id935568626?mt=8"];
        [[UIApplication sharedApplication] openURL:[NSURL URLWithString:string]];
    }  
}


@end