module(..., package.seeall)

local BindPhoneTable = {}
local BindPhone = 0
local ResultMsg = nil
local bindPhoneRewards = 0 --斗牛绑定手机的金币奖励

--[[--
--解析绑定手机
--0未知
1移动
2联通
3电信
]]
--我的绑定手机
function getBindPhone()
	return BindPhone
end
--绑定手机号列表
function getBindPhoneList()
	return BindPhoneTable
end

function readBindPhone(dataTable)
	BindPhone = dataTable["MoblieNumber"]
	BindPhoneTable = dataTable["NumberTable"]
	framework.emit(DBID_GET_SMS_NUMBER)
end
--[[--
--解析绑定手机随机内容
]]
function getBindPhoneMsg()
	return ResultMsg
end

function readBindPhoneMsg(dataTable)
	ResultMsg = dataTable["ResultMsg"]
	framework.emit(MANAGERID_GET_BINDING_PHONE_RANDOM)
end

--[[--
--绑定手机奖励
]]
function getBindPhoneRewards()
	if bindPhoneRewards ~= nil then
		return bindPhoneRewards
	else
		return 0
	end
end

local function readDOUNIU_MGR_BINDPHONE_REWARDS(dataTable)
	bindPhoneRewards = dataTable["rewards"]
	framework.emit(DOUNIU_MGR_BINDPHONE_REWARDS)
end

registerMessage(DBID_GET_SMS_NUMBER, readBindPhone)
registerMessage(MANAGERID_GET_BINDING_PHONE_RANDOM, readBindPhoneMsg)
registerMessage(DOUNIU_MGR_BINDPHONE_REWARDS, readDOUNIU_MGR_BINDPHONE_REWARDS)