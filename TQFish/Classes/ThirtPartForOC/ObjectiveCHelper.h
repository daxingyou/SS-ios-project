
#import <Foundation/Foundation.h>

@interface ObjectiveCHelper : NSObject<UIWebViewDelegate>
{
    NSLock *lock;
}

+ (ObjectiveCHelper *)sharedObjectiveCHelper;

- (void) showAlbum;

- (void) changeHeader; //新版修改头像

- (void) uploadPortraitWithASIHTTPRequest:(UIImage *)image;

- (void) createWebview:(NSDictionary *)dict; //新版webview

- (NSLock *)getLock;

@end
