module("LoginConfig", package.seeall)

local isChangeAccount = false--切换账号标示

local mUserIDValue = 0;--登录/注册界面存储的用户ID
local mUserNameValue = nil;--登录/注册界面存储的用户昵称
local mPasswordValue = nil;--登录/注册界面存储的用户密码

WECHAT_BIND = "wechat_bind" --微信绑定,用于微信登录透传
WECHAT_LOGIN = "wechat_login"--微信登录,用于微信登录透传

local WechatInfo = {}  --微信登陆回调信息

function getWechatInfo()
	return WechatInfo;
end

function getWeChatToken()
	local userInfo = Common.LoadShareTable(CommSqliteConfig.LAST_LOGIN_TOKEN);
	if userInfo ~= nil and next(userInfo) ~= nil and userInfo.token ~= "" then
		return userInfo.token;
	end
	return nil;
end

function setWeChatToken(token)
	Common.log("setWeChatToken token = " .. token);
	local userInfo = Common.LoadShareTable(CommSqliteConfig.LAST_LOGIN_TOKEN);
	if userInfo ~= nil and next(userInfo) ~= nil and userInfo.token == token then
		return;
	end
	local userInfo = {};
	userInfo.token = token
	Common.SaveShareTable(CommSqliteConfig.LAST_LOGIN_TOKEN, userInfo);
end

--[[--
--微信登录native的回调(android)
--]]--
function setWechatLoginDataForAndroid(wechatData)
	local UserTable = Common.FGUtilStringSplit(wechatData, "#")
	Common.log("setWechatLoginData length == "..#UserTable)
	WechatInfo = {};
	WechatInfo.code = UserTable[1];
	WechatInfo.openId = UserTable[2];
	WechatInfo.state = UserTable[3];
	WechatInfo.transaction = UserTable[4];
	WechatInfo.url = UserTable[5];
	--	Common.log("setWechatLoginData code == "..WechatInfo.code)
	--	Common.log("setWechatLoginData state == "..WechatInfo.state)
	--	Common.log("setWechatLoginData url == "..WechatInfo.url)
	if WechatInfo.code == "-1" or WechatInfo.state == "-1" then
		Common.showNativeToast("微信信息获取失败，请稍后重试！", 2);
		return;
	end
end

--[[--
--微信登录native的回调(IOS)
--]]--
function setWechatLoginDataForIOS(wechatData)
	WechatInfo = {};
	WechatInfo.code = wechatData["wxcode"];
	WechatInfo.state = wechatData["wxstate"];
	--	Common.log("setWechatLoginData code == "..WechatInfo.code)
	--	Common.log("setWechatLoginData state == "..WechatInfo.state)
	if WechatInfo.code == "-1" or WechatInfo.state == "-1" then
		Common.showToast("微信信息获取失败，请稍后重试！", 2);
		return;
	end
end

--[[--
-- 微信登出
--]]
function setWechatLogout()
	WechatInfo = {};
	local userInfo = {};
	userInfo.token = ""
	Common.SaveShareTable(CommSqliteConfig.LAST_LOGIN_TOKEN, userInfo);
end

--[[--
--绑定微信
--]]--
function bindWechatUserInfo()
	if WechatInfo.code == nil then
		return;
	end
	--发消息
	local strToken = WechatInfo.code
	sendMANAGERID_WECHAT_BIND(strToken)
	if WechatInfo.state ~= nil then
		WechatInfo.state = -1;--清除数据
	end
	CommDialogConfig.showProgressDialog();
end

--[[--
--微信登陆
--]]
function sendWeChatThirdPartLogin()
	if WechatInfo.code == nil and getWeChatToken() == nil then
		return;
	end
	local strToken = ""
	if getWeChatToken() ~= nil then
		strToken = getWeChatToken();
	end
	if WechatInfo.code ~= nil then
		strToken = WechatInfo.code;
	end
	local strThirdPartPlatUID = ""
	local nThirdPartPlatId = 15 --微信
	local lastUsername = "" --java
	local lastPassword = "" --java
--	local bIsHasData, nUserID, sUsernamevalue, sPasswordvalue = getLastUserInfo();
--	if bIsHasData then
--		if sPasswordvalue == "" then
--			sPasswordvalue = GameConfig.DefaultPassword;
--		end
--		lastUsername = sUsernamevalue;
--		lastPassword = sPasswordvalue;
--	end
	sendBASEID_THIRD_PART_PLAT_LOGIN(strToken, strThirdPartPlatUID, nThirdPartPlatId, lastUsername, lastPassword);
	if WechatInfo.state ~= nil and WechatInfo.state ~= -1 then
		WechatInfo.state = -1;--清除数据
		CommDialogConfig.showProgressDialog();
	end
end

function sendWeChatLoginMessage()
	local isNeedReturn = false;
	if next(getWechatInfo()) ~= nil then
		--可以使用微信登录
		Common.log("可以使用微信登录 ================")
		if getWechatInfo().state == WECHAT_LOGIN then
			--微信登录/注册
			--微信注册账号，微信登录老账号
			Common.log("重连以后需要发送 微信登录/注册");
			sendWeChatThirdPartLogin();
			isNeedReturn = true;
		end
	end
	return isNeedReturn;
end

function sendWeChatBindMessage()
	if next(getWechatInfo()) ~= nil then
		--可以使用微信登录
		Common.log("可以使用微信绑定 ================")
		if getWechatInfo().state == WECHAT_BIND then
			--微信绑定
			Common.log("重连以后需要发送 微信绑定");
			bindWechatUserInfo();
		end
	end
end

--[[--
--解析微信绑定信息
--]]
function readWeChatBind()
	CommDialogConfig.closeProgressDialog();
	Common.log("收到绑定微信回调")
	--是否绑定成功  1成功;0不成功
	local result = profileCommon.BindWechat.getBindWechatResult();
	if result == 1 then
		if WechatInfo.code ~= nil then
			setWeChatToken(WechatInfo.code);
		end
		profile.User.setUserThirdPartPlatId(15);
		local loginName = profileCommon.BindWechat.getBindWechatLoginName();
		--绑定微信之后，用户昵称可能会修改（用户没有修改过昵称时，会使用微信昵称）
		if loginName ~= "" then
			profile.User.setSelfNickName(loginName)
			LoginConfig.saveUserData()
		end
		if mvcEngine.logicModuleIsShow(GUI_BINDWECHAT) then
			mvcEngine.destroyModule(GUI_BINDWECHAT);
		end
		--刷新用户数据
		sendDOUNIU_MGR_USER_INFO(profile.User.getSelfUserID());
	end
end

function getLoginUserID()
	return mUserIDValue;
end

function setLoginUserID(userID)
	mUserIDValue = userID;
end

function getLoginUserName()
	return mUserNameValue;
end

function setLoginUserName(username)
	mUserNameValue = username;
end

function getLoginPassword()
	return mPasswordValue;
end

function setLoginPassword(password)
	mPasswordValue = password;
end

--[[--
--设置是否是切换账号
--]]
function setChangeAccount(isChange)
	isChangeAccount = isChange
end

--[[--
--切换账号时初始化数据
--]]
function initAllGameData(userID)
	if isChangeAccount == true then
		isChangeAccount = false;
		Common.log("-----------切换账号时初始化数据-------------")
		profile.User.initUserInfo(userID);
		GameConfig.isRegister = false;
		GameConfig.isFirstEnterGame = false;
		HallChatLogic.initAllChatData();
		GameConfig.initGameCommonData();
		--清除大厅公告数据
		profile.SystemListNotice.clearData();
		--清除大厅按钮数据
		profile.ButtonsStatus.clearData();
		ImageToast.OverFunction = nil;
		--清除大厅预读消息数据
		MessagesPreReadManage.clearData();
		--清除小游戏列表消息数据
		GameCommonProfile.MiniGame.clearData();
	end
end

--[[--
--保存用户数据
--]]
function saveUserData()
	local userinfo = {}
	local UserID = profile.User.getSelfUserID()
	local username = profile.User.getSelfNickName()
	local password = profile.User.getSelfPassword()
	userinfo["UserID"] = UserID
	userinfo["nickname"] = username
	userinfo["password"] = password
	Common.log("saveUserData UserID == "..UserID);
	Common.log("saveUserData username == "..username);
	Common.log("saveUserData password == "..password);
	if UserID == 0 or username == "" then
		return;
	end
	local bIsHasData, nUserID, sUsernamevalue, sPasswordvalue = getLastUserInfo();
	local userIDAndPassword = Common.getDataForSqlite(CommSqliteConfig.UserNicknameAndPassword .. username)
	if bIsHasData and userIDAndPassword ~= nil then
		if nUserID == UserID and sUsernamevalue == username and sPasswordvalue == password then
			return;
		end
	end
	if Common.platform == Common.TargetIos then
		Common.SaveShareUserTable("lastLoginUserInfo", userinfo)
		--斗地主记录所有登陆昵称和密码
		Common.setDataForSqlite(CommSqliteConfig.UserNicknameAndPassword..username, UserID .. "#" .. password)
	else
		if UserID ~= "" and username ~= "" and password ~= "" then
			Common.SaveShareUserTable("lastLoginUserInfo", userinfo)
			--斗地主记录所有登陆昵称和密码
			Common.setDataForSqlite(CommSqliteConfig.UserNicknameAndPassword..username, UserID .. "#" .. password)
		end
	end
end

--[[--
--界面收到登录消息后处理
--]]--
function loginManage()
	local result = profileCommon.UserLoginReg.getResult()
	local resultText = profileCommon.UserLoginReg.getResultText()

	if ServerConfig.isAppstoreReview() then
		if (result == 0) then
			local BaseInfo = {};
			BaseInfo = profileCommon.UserLoginReg.getBaseInfo();

			initAllGameData(BaseInfo["UserID"]);--切换账号时，重置数据

			profile.User.setSelfUserID(BaseInfo.UserID);
			profile.User.setSelfNickName(BaseInfo.NickName);
			profile.User.setSelfPassword(mPasswordValue);
			profile.User.setSelfCoin(BaseInfo.Coin);
			profile.User.setSelfYuanBao(BaseInfo.YuanBao);
			profile.User.setUserThirdPartPlatId(BaseInfo.thirdPartPlatId);

			saveUserData();

			GameLoadModuleConfig.startMiniGameByID(GameLoadModuleConfig.MahjongSichuanGameID, GameLoadModuleConfig.MahjongSichuanPackage,"AppstoreReview");
		else
			if GameConfig.getTheCurrentBaseLayer() == GUI_LOADING then
				--不使用微信登录
				mvcEngine.createModule(GUI_LOGIN)
			elseif GameConfig.getTheCurrentBaseLayer() == GUI_LOGIN then
				Common.showToast(resultText, 2)
			end
		end

		return
	end


	if (result == 0) then

		if profile.User.getUserIsWeChatLogin() then
			--如果是微信登录用户
			if WechatInfo.code ~= nil then
				setWeChatToken(WechatInfo.code);
			end
		else
			--不是微信登录，则清除微信相关数据
			setWechatLogout();
		end

		local BaseInfo = {};
		BaseInfo = profileCommon.UserLoginReg.getBaseInfo();

		initAllGameData(BaseInfo["UserID"]);--切换账号时，重置数据

		profile.User.setSelfUserID(BaseInfo.UserID);
		profile.User.setSelfNickName(BaseInfo.NickName);
		profile.User.setSelfPassword(mPasswordValue);
		profile.User.setSelfCoin(BaseInfo.Coin);
		profile.User.setSelfYuanBao(BaseInfo.YuanBao);
		profile.User.setUserThirdPartPlatId(BaseInfo.thirdPartPlatId);

		saveUserData();

		if not ServerConfig.isAppstoreReview() then
			--非appstore评审版本，才发送发送预读消息
			MessagesPreReadManage.sendPreReadingMessages();
		end
		mvcEngine.createModule(GUI_HALL)
	else
		if GameConfig.getTheCurrentBaseLayer() == GUI_LOADING then
			--不使用微信登录
			mvcEngine.createModule(GUI_LOGIN)
		elseif GameConfig.getTheCurrentBaseLayer() == GUI_LOGIN then
			Common.showToast(resultText, 2)
		end
	end
end

--[[--
--界面收到注册消息后处理
--]]--
function RegisterManage()
	local result = profileCommon.UserLoginReg.getResult()
	local resultText = profileCommon.UserLoginReg.getResultText()

	if ServerConfig.isAppstoreReview() then
		if (result == 0) then
			local BaseInfo = {};
			BaseInfo = profileCommon.UserLoginReg.getBaseInfo();

			initAllGameData(BaseInfo["UserID"]);--切换账号时，重置数据

			profile.User.setSelfUserID(BaseInfo.UserID);
			profile.User.setSelfNickName(BaseInfo.NickName);
			profile.User.setSelfPassword(BaseInfo.Password);
			profile.User.setSelfCoin(BaseInfo.Coin);
			profile.User.setSelfYuanBao(BaseInfo.YuanBao);
			profile.User.setUserThirdPartPlatId(BaseInfo.thirdPartPlatId);

			saveUserData();

			GameConfig.isRegister = true;
			GameConfig.isFirstEnterGame = true

			GameLoadModuleConfig.startMiniGameByID(GameLoadModuleConfig.MahjongSichuanGameID, GameLoadModuleConfig.MahjongSichuanPackage,"AppstoreReview");
		else
			if GameConfig.getTheCurrentBaseLayer() == GUI_LOADING then
				mvcEngine.createModule(GUI_LOGIN)
			elseif GameConfig.getTheCurrentBaseLayer() == GUI_LOGIN then
				Common.showToast(resultText, 2)
			end
		end

		return
	end

	if (result == 0) then
		local BaseInfo = {};
		BaseInfo = profileCommon.UserLoginReg.getBaseInfo();

		initAllGameData(BaseInfo["UserID"]);--切换账号时，重置数据

		profile.User.setSelfUserID(BaseInfo.UserID);
		profile.User.setSelfNickName(BaseInfo.NickName);
		profile.User.setSelfPassword(BaseInfo.Password);
		profile.User.setSelfCoin(BaseInfo.Coin);
		profile.User.setSelfYuanBao(BaseInfo.YuanBao);
		profile.User.setUserThirdPartPlatId(BaseInfo.thirdPartPlatId);

		saveUserData();

		GameConfig.isRegister = true;
		GameConfig.isFirstEnterGame = true
		if not ServerConfig.isAppstoreReview() then
			--非appstore评审版本，才发送发送预读消息
			MessagesPreReadManage.sendPreReadingMessages();
		end
		mvcEngine.createModule(GUI_HALL);
	else
		if GameConfig.getTheCurrentBaseLayer() == GUI_LOADING then
			mvcEngine.createModule(GUI_LOGIN)
		elseif GameConfig.getTheCurrentBaseLayer() == GUI_LOGIN then
			Common.showToast(resultText, 2)
		end
	end
end

--[[--
--获取设备IMEI信息下用户数
--]]
function IMEIUserListManage()
	if GameConfig.getTheCurrentBaseLayer() ~= GUI_LOADING then
		--不是在loading界面
		if GameConfig.getTheCurrentBaseLayer() == GUI_LOGIN then
			--在登录界面
			if isHasUserInfo() then
				--由用户数据
				return;
			end
		else
			return;
		end
	end

	if not ServerConfig.isAppstoreReview() then
		--非AppStore审核期间
		if profileCommon.MoreUser.geLastLoginUserIsBindWeChat() then
			--绑定过微信
			Common.log("绑定过微信");
			if GameConfig.getTheCurrentBaseLayer() ~= GUI_LOGIN then
				mvcEngine.createModule(GUI_LOGIN);
			end
			return;
		end
	end

	local UserSize = profileCommon.MoreUser.getUserSize() --用户总数

	if UserSize == 0 then
		Common.log("获取当前手机用户登录列表数量是0,新设备 ============== ");
        if GameConfig.getTheCurrentBaseLayer() ~= GUI_LOGIN then
            mvcEngine.createModule(GUI_LOGIN);
        end
        return;
	else
		Common.log("获取当前手机用户登录列表数量是" .. UserSize .. ",老设备 ============== ");
		local NickName = profileCommon.MoreUser.geLastLoginUserName();
		if NickName ~= nil then
			Common.log("当前手机用户登录列表信息 username == " .. NickName);
			LoginConfig.setLoginUserName(NickName); --设置用户名，用以登录失败以后检测该用户是否是经过微信关联
			sendBASEID_LOGIN(0, LoginConfig.getLoginUserName(), GameConfig.DefaultPassword, Common.getDeviceInfo());
		else
			if GameConfig.getTheCurrentBaseLayer() ~= GUI_LOGIN then
				mvcEngine.createModule(GUI_LOGIN);
			end
		end
	end
end

--[[--
--是否有用户数据
--]]
function isHasUserInfo()
	local UserID = profile.User.getSelfUserID();
	local username = profile.User.getSelfNickName();
	local password = profile.User.getSelfPassword();
	if (UserID ~= 0 and username ~= nil and password ~= nil) then
		--内存有用户数据
		Common.log("内存有用户数据");
		return true;
	end

	--没有内存数据
	local bIsHasData, nUserID, sUsernamevalue, sPasswordvalue = getLastUserInfo();

	return bIsHasData;
end

--[[--
--获取存储在设备上的用户数据(文件中)
--@return #boolean 是否有数据
--@return #number UserID
--@return #string nickname
--@return #string password
--]]
function getLastUserInfo()
	local logininfo = Common.LoadShareUserTable("lastLoginUserInfo");
	local isHasData = false
	local UserID = -1
	local UserName = ""
	local Password = ""
	if logininfo ~= nil and next(logininfo) ~= nil and logininfo["UserID"] ~= nil and logininfo["nickname"] ~= nil and logininfo["password"] ~= nil then
		UserID = tonumber(logininfo["UserID"]);
		UserName = logininfo["nickname"];
		Password = logininfo["password"];
		isHasData = true
	end
	return isHasData, UserID, UserName, Password;
end

--获取用户列表
framework.addSlot2Signal(MANAGERID_USERLIST_FROM_IMIE, IMEIUserListManage, true);
-- 微信绑定
framework.addSlot2Signal(MANAGERID_WECHAT_BIND, readWeChatBind, true);
