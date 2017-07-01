module(..., package.seeall)

local MoreUserTable = {}

MoreUserTable["cnt"] = 0
MoreUserTable["usernameTable"] = {}
MoreUserTable["telnum"] = 0
MoreUserTable["LoginWithMore"] = ""

local UserListFromIMEI = {};--获取当前手机用户登录列表信息

--[[--
--LoginWithMore
--]]
function getLoginWithMore()
	local value = MoreUserTable["LoginWithMore"]
	if value == nil then
		return ""
	else
		return value
	end
end

function setLoginWithMore(loginWithMore)
	--此方法为客户端信号，不用注册
	MoreUserTable["LoginWithMore"] = loginWithMore
	framework.emit(signal.common.Signal_BASEID_GET_LOGINCHANEUSERNAMME)
end

--[[--
--删除一条用户信息
--]]
function deleteOneUserInfo(index)
	table.remove(MoreUserTable["usernameTable"], index);
end

--[[--
--获取此手机上次登录的用户名
--]]
function geLastLoginUserName()
	if UserListFromIMEI["NickList"] ~= nil and next(UserListFromIMEI["NickList"]) ~= nil then
		return UserListFromIMEI["NickList"][1].NickName;
	end
	return nil;
end

--[[--
--获取此手机上次登录的用户是否使用微信登录
--]]
function geLastLoginUserIsBindWeChat()
	if UserListFromIMEI["NickList"] ~= nil and next(UserListFromIMEI["NickList"]) ~= nil then
		if UserListFromIMEI["NickList"][1].IsBindWeChat == 1 then
			return true;
		end
	end
	return false;
end

--[[--
--获取此手机登录的用户数量
--]]
function getUserSize()
	if UserListFromIMEI["NickList"] ~= nil then
		return #UserListFromIMEI["NickList"];
	end
	return 0;
end

--[[--
--获取用户列表
--]]
function getUserListFromIMEI()
	return UserListFromIMEI["NickList"];
end

--3.7.157 获取当前手机用户登录列表信息(MANAGERID_USERLIST_FROM_IMIE)
function setMANAGERID_USERLIST_FROM_IMIE(dataTable)

	--NickCnt	int	昵称数量	loop
	--…NickName	text	登陆过此手机的昵称
	--…IsBindWeChat	byte	此账号是否绑定微信	0：没有；1：有
	UserListFromIMEI["NickList"] = dataTable["NickList"];

	framework.emit(MANAGERID_USERLIST_FROM_IMIE)
end

registerMessage(MANAGERID_USERLIST_FROM_IMIE, setMANAGERID_USERLIST_FROM_IMIE)