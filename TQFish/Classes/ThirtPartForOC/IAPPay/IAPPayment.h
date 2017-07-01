//
//  IAPPayment.h
//  demo
//
//  tongqu-2015-11-17
//  Created by spring on 14-3-31.
//
//

#import <UIKit/UIKit.h>
#import <StoreKit/StoreKit.h>

/*
 6=6*10=60
 30=30*12=360
 68=68*13=884
 128=128*15=1920
 328=328*18=5904
 648=648*20=12960
 */
enum{
    IAP6 = 60,
    IAP30 = 300,
    IAP68 = 680,
    IAP128 = 1280,
    IAP328 = 3280,
    IAP648 = 6480,
}buyCoinsTag;




@interface IAPPayment :UIViewController<SKProductsRequestDelegate,SKPaymentTransactionObserver,SKStoreProductViewControllerDelegate>
{
    int buyType;
    NSString *yuanbao;
}


@property(nonatomic,retain) NSString *yuanbao;

+(IAPPayment *)shareIAPPayment;

- (void) requestProUpgradeProductData;
-(void)RequestProductData;
-(void)RequestProductDataWithProductID:(NSString *)pID;

-(bool)CanMakePay;
-(void)buy;
- (void)buyWithProductID:(NSString *)pID;
- (void)paymentQueue:(SKPaymentQueue *)queue updatedTransactions:(NSArray *)transactions;
-(void) PurchasedTransaction: (SKPaymentTransaction *)transaction;
- (void) completeTransaction: (SKPaymentTransaction *)transaction;
- (void) failedTransaction: (SKPaymentTransaction *)transaction;
-(void) paymentQueueRestoreCompletedTransactionsFinished: (SKPaymentTransaction *)transaction;
-(void) paymentQueue:(SKPaymentQueue *) paymentQueue restoreCompletedTransactionsFailedWithError:(NSError *)error;
- (void) restoreTransaction: (SKPaymentTransaction *)transaction;
-(void)provideContent:(NSString *)product;
-(void)recordTransaction:(NSString *)product;

-(void) getOrderID:(NSDictionary *)dict;
@end