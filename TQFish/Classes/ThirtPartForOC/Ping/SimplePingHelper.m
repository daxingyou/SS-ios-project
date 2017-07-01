#import "SimplePingHelper.h"

@interface SimplePingHelper()
@property(nonatomic,retain) SimplePing* simplePing;
@property(nonatomic,retain) id target;
@property(nonatomic,assign) SEL sel;
- (id)initWithAddress:(NSString*)address target:(id)_target sel:(SEL)_sel;
- (void)go;
@end

@implementation SimplePingHelper
@synthesize simplePing, target, sel;

#pragma mark - Run it

// Pings the address, and calls the selector when done. Selector must take a NSnumber which is a bool for success
+ (void)ping:(NSString*)address luaCallback:(int)luaCallback target:(id)target sel:(SEL)sel {
	// The helper retains itself through the timeout function
    [[[[SimplePingHelper alloc] initWithAddress:address luaCallback:luaCallback target:target sel:sel] autorelease] go];
}

#pragma mark - Init/dealloc

- (void)dealloc {
	self.simplePing = nil;
	self.target = nil;
	[super dealloc];
}

- (id)initWithAddress:(NSString*)address luaCallback:(int)luaCallback target:(id)_target sel:(SEL)_sel {
	if (self = [self init]) {
        self.simplePing = [SimplePing simplePingWithHostName:address luaCallBack:luaCallback];
        assert(self.simplePing != nil);
        
        // By default we use the first IP address we get back from host resolution (.Any)
        // but these flags let the user override that.
        
//        if (self.forceIPv4 && ! self.forceIPv6) {
//            self.simplePing.addressStyle = SimplePingAddressStyleICMPv4;
//        } else if (self.forceIPv6 && ! self.forceIPv4) {
//            self.simplePing.addressStyle = SimplePingAddressStyleICMPv6;
//        }
        self.simplePing.delegate = self;
		self.target = _target;
		self.sel = _sel;
	}
	return self;
}

#pragma mark - Go

- (void)go {
	[self.simplePing start];
	[self performSelector:@selector(endTime) withObject:nil afterDelay:3]; // This timeout is what retains the ping helper
}

#pragma mark - Finishing and timing out

// Called on success or failure to clean up
- (void)killPing {
	[self.simplePing stop];
	[[self.simplePing retain] autorelease]; // In case, higher up the call stack, this got called by the simpleping object itself
	self.simplePing = nil;
}

- (void)successPing {
    NSString *hostName = self.simplePing.hostName;
    int callback = self.simplePing.luaCallBack;
    int result = 1;
    [self killPing];
    NSDictionary *dict = [NSDictionary dictionaryWithObjectsAndKeys:hostName, @"ipAddr", [NSNumber numberWithInt:callback], @"pingCallback", [NSNumber numberWithInt:result], @"result",nil];
    [target performSelector:sel withObject:dict];
}

- (void)failPing:(NSString*)reason {
    NSString *hostName = self.simplePing.hostName;
    int callback = self.simplePing.luaCallBack;
    int result = 0;
    [self killPing];
    NSDictionary *dict = [NSDictionary dictionaryWithObjectsAndKeys:hostName, @"ipAddr", [NSNumber numberWithInt:callback], @"pingCallback", [NSNumber numberWithInt:result], @"result",nil];
	[target performSelector:sel withObject:dict];
}

// Called 1s after ping start, to check if it timed out
- (void)endTime {
	if (self.simplePing) { // If it hasn't already been killed, then it's timed out
		[self failPing:@"timeout"];
	}
}

#pragma mark - Pinger delegate

/*
 * PingDelegate: 套接口开启之后发送ping数据
 *
 */
- (void)simplePing:(SimplePing *)pinger didStartWithAddress:(NSData *)address {
	[self.simplePing sendPingWithData:nil];
}

/*
 * PingDelegate: ping命令发生错误之后，立即停止线程
 *
 */
- (void)simplePing:(SimplePing *)pinger didFailWithError:(NSError *)error {
	[self failPing:@"didFailWithError"];
}

/*
 * PingDelegate: 发送ping数据失败
 */
- (void)simplePing:(SimplePing *)pinger didFailToSendPacket:(NSData *)packet sequenceNumber:(uint16_t)sequenceNumber error:(NSError *)error {
	// Eg they're not connected to any network
	[self failPing:@"didFailToSendPacket"];
}

/*
 * PingDelegate: 成功接收到PingResponse数据
 */
- (void)simplePing:(SimplePing *)pinger didReceivePingResponsePacket:(NSData *)packet sequenceNumber:(uint16_t)sequenceNumber {
	[self successPing];
}

@end
