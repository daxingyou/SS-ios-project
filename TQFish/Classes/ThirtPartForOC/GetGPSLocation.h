//
//  GetGPSLocation.h
//
//
//  Created by lixue on 17-5-8.
//
//

#import <CoreLocation/CoreLocation.h>

@interface GetGPSLocation :UIViewController<CLLocationManagerDelegate> {
    CLLocationManager * mlocationManager;
    
}
- (void)locatemap;

+ (void) openGPSLocation:(NSDictionary *)dict;
@end
