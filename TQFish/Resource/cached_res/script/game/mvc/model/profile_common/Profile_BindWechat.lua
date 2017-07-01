module(..., package.seeall)

local BindWechatTable = {}
local Result = 0
local LoginName = nil

local isBindWechatUserTable = {}

--是否绑定成功  1成功;0不成功
function getBindWechatResult()
	if Result == nil then
		return 0
	end
	return Result;
end

--绑定后的登录名  --修改登录名则返回  否则返回""
function getBindWechatLoginName()
	if LoginName == nil then
		return ""
	end
	return LoginName
end

--是否是微信绑定用户 1是;0否
function getisBindWechatUserResult()
	local result = isBindWechatUserTable["Result"]
	if result == nil then
		return 0
	end
	return result
end

function readMANAGERID_WECHAT_BIND(dataTable)
	BindWechatTable = dataTable;
	Result = dataTable["Result"];
	LoginName = dataTable["LoginName"];
	framework.emit(MANAGERID_WECHAT_BIND);
end

local isHint = 0;
local AwardCoin = "";

--[[--
--是否提示用户绑定微信
--]]
function isHintBindWeChat()
	if isHint == 0 then
		return false;
	end
	return true;
end

--[[--
--绑定微信提示信息
--]]
function getAwardCoin()
	return AwardCoin;
end

function readMANAGERID_HINT_BIND_WECHAT(dataTable)
	--isHint	byte	是否需要提示用户绑定微信	0不提示，1提示
	isHint = dataTable["isHint"];
	--AwardCoin	text	绑定微信提示信息
	AwardCoin = dataTable["AwardCoin"];
	framework.emit(MANAGERID_HINT_BIND_WECHAT)
end

function readMANAGERID_IS_BIND_WECHAT(dataTable)
	isBindWechatUserTable = dataTable
	framework.emit(MANAGERID_IS_BIND_WECHAT)
end

registerMessage(MANAGERID_WECHAT_BIND, readMANAGERID_WECHAT_BIND)
registerMessage(MANAGERID_HINT_BIND_WECHAT, readMANAGERID_HINT_BIND_WECHAT)
registerMessage(MANAGERID_IS_BIND_WECHAT, readMANAGERID_IS_BIND_WECHAT)
