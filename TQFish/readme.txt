3.26 2015-11-17
1、友盟更新
2、添加appstore评价（动态）
3、支付宝更新15.0.1 并添加支付宝开关（同用微信开关）
4、userinfo输入框初始化位置修改
5、金花牌桌 禁比 换牌（千王场）QuickPay数据配置 表情包UI显示更改
6、增加推送功能

  2015-12-24
xcode升级到7.2以后  需要更改bitcode 的值 为NO
并设置http--就是在info.plist 中加入代码   	
<key>NSAppTransportSecurity</key>
	<dict>
		<key>NSAllowsArbitraryLoads</key>
		<true/>
	</dict>

应用第三方需要添加白名单  在info.plist 中加入代码 
<key>LSApplicationQueriesSchemes</key>
   	 <array>
        <string>alipay://</string>
		<string>xyzsapp://</string>
		<string>weixin</string>
		<string>wechat</string>
		<string>alipay</string>
		<string>alipayauth</string>
    </array>