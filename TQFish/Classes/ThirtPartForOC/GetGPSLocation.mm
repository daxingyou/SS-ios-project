//
//  GetGPSLocation.m
//  
//
//  Created by lixue on 17-5-8.
//
//

#import "GetGPSLocation.h"
#import "CCLuaObjcBridge.h"
#import "cocos2d.h"


@interface GetGPSLocation ()

@end

@implementation GetGPSLocation

int locationCallBackFunction = -1;

+ (void)openGPSLocation:(NSDictionary *)dict
{
     // OC调用Lua方法
    locationCallBackFunction = [[dict objectForKey:@"getLocationCallback"] intValue];
    
    GetGPSLocation *viewController = [[GetGPSLocation alloc] init];
    [viewController locatemap];
    
}

- (void)locatemap {
    //判断定位功能是否打开
    if([CLLocationManager locationServicesEnabled]){
        mlocationManager = [[CLLocationManager alloc] init];
        mlocationManager.delegate = self;
        [mlocationManager requestAlwaysAuthorization];
        
        [mlocationManager requestWhenInUseAuthorization];
        //设置寻址经度
        mlocationManager.desiredAccuracy = kCLLocationAccuracyBest;
        mlocationManager.distanceFilter = 5.0;
        [mlocationManager startUpdatingLocation];
    }
}


#pragma mark CoreLocation deleagte (定位失败)
/*定位失败则执行此代理方法*/
/*定位失败弹出提示窗，点击打开定位按钮 按钮，会打开系统设置，提示打开定位服务*/
-(void)locationManager:(CLLocationManager *)manager didFailWithError:(NSError *)error{
    /*设置提示提示用户打开定位服务*/
    UIAlertController * alert = [UIAlertController alertControllerWithTitle:@"允许\"定位\"提示" message:@"请在设置中打开定位" preferredStyle:UIAlertControllerStyleAlert];
    UIAlertAction * ok =[UIAlertAction actionWithTitle:@"打开定位" style:UIAlertActionStyleDefault handler:^(UIAlertAction * _Nonnull action) {
        /*打开定位设置*/
        NSURL * settingsURL = [NSURL URLWithString:UIApplicationOpenSettingsURLString];
        [[UIApplication sharedApplication]openURL:settingsURL];
    }];
    UIAlertAction * cacel = [UIAlertAction actionWithTitle:@"取消" style:UIAlertActionStyleCancel handler:^(UIAlertAction * _Nonnull action) {
        
    }];
    [alert addAction:ok];
    [alert addAction:cacel];
    [self presentViewController:alert animated:YES completion:nil];
}

/*定位成功后则执行此代理方法*/
#pragma mark 定位成功
-(void)locationManager:(CLLocationManager *)manager didUpdateLocations:(NSArray<CLLocation *> *)locations{
    NSLog(@"didUpdateLocations");
    [mlocationManager stopUpdatingLocation];
    /*旧值*/
    CLLocation * currentLocation = [locations lastObject];
    /*打印当前经纬度*/
    NSLog(@"GetGPSLocation ==  %f#%f",currentLocation.coordinate.latitude,currentLocation.coordinate.longitude);
    
    
    NSString *parameters = [NSString stringWithFormat:@"%f#%f",currentLocation.coordinate.latitude, currentLocation.coordinate.longitude];
    
  //  cocos2d::CCUserDefault::sharedUserDefault()->setStringForKey("locationManagerInfo", parameters.UTF8String);
    if(locationCallBackFunction >= 0) {
        // 1. 将引用 ID 对应的 Lua function 放入 Lua stack
        cocos2d::CCLuaObjcBridge::pushLuaFunctionById(locationCallBackFunction);
        
        // 2. 将需要传递给 Lua function 的参数放入 Lua stack
        
        // 传给Lua的函数参数，Lua中的数组既是数组也可以是字典
        cocos2d::CCLuaObjcBridge::getStack()->pushCCLuaValue(cocos2d::CCLuaValue::stringValue(parameters.UTF8String));
        
        // 3. 执行 Lua function
        cocos2d::CCLuaObjcBridge::getStack()->executeFunction(1);
        
        // 4. 释放引用 ID
        cocos2d::CCLuaObjcBridge::releaseLuaFunctionById(locationCallBackFunction);
        
        locationCallBackFunction = -1;
    }
}

@end
