module(..., package.seeall)

local AllRedPointDataTable = {}--所有红点数据（不包含：站内信、家族）

--服务器约定的常量是对应的Int型

CHARMRANK = "501" --501魅力排行榜
COINRANK = "502" --502财富排行榜
RECHARGERANK = "503" --503每日充值排行榜
EARNRANK = "504" --504每日赚金排行榜
ARENARANK = "505" --505竞技场排行榜
DAILYTASK = "506" --506每日任务
ACHIEVEMENTTASK = "507" --507成就任务
PHONEBIND = "509" --509手机绑定
MONTHCARD = "510" --510月卡
WECHATBIND = "511" --511微信绑定
ARENA = "35"     --35.竞技场

local RedPointConstant = {
	501,--501魅力排行榜
	502,--502财富排行榜
	503,--503每日充值排行榜
	504,--504每日赚金排行榜
	505,--505竞技场排行榜
	506,--506每日任务
	507,--507成就任务
	508,--508邮件
	509,--509手机绑定
	510,--510月卡
	511,--511微信绑定
	35,--35竞技场
}

--[[--
--获取需要同步红点定义列表
--]]
function getRedPointConstant()
	return RedPointConstant;
end

--[[--
--删除标签红点数据(通过 红点数据类型)
--@param #string parentId 红点数据类型
--]]
function removeParentRedPointDataByPointId(parentId)
	if next(AllRedPointDataTable) == nil then
		return
	end
	--删除本地红点
	AllRedPointDataTable[parentId] = nil;
end

--[[--
--获取指定模块红点列表数据（例如：商城列表）
--@param #string parentId 模块ID
--@return #table 对应的子列表数据
--]]
function getChildRedPointTableByParentID(parentId)
	if next(AllRedPointDataTable) == nil or AllRedPointDataTable[parentId] == nil then
		return nil
	end
	return AllRedPointDataTable[parentId]["ID"]
end

--[[--
--删除列表红点数据(通过 红点数据类型 红点ID)
--@param #string parentId 红点数据类型
--@param #number redPointId 红点ID
--]]
function removeChildRedPointDataByPointId(parentId, redPointId)
	if next(AllRedPointDataTable) == nil or AllRedPointDataTable[parentId] == nil then
		return
	end
	--删除本地红点
	for key, ChildID in pairs(AllRedPointDataTable[parentId]["ID"]) do
		if tonumber(redPointId) == tonumber(ChildID) then
			AllRedPointDataTable[parentId]["ID"][key] = nil;
		end
	end
end

--[[--
--获取大厅界面红点整合数据
--]]
function getHallShowRedPointTable()
	local tab = {}
	for layoutId, HongDianItem in pairs(AllRedPointDataTable) do
		if layoutId == ACHIEVEMENTTASK or layoutId == DAILYTASK then
			--507.成就任务  --506.每日任务
			if next(HongDianItem["ID"]) ~= nil then
				tab[ACHIEVEMENTTASK.."_"..DAILYTASK] = 1;
			end
		elseif layoutId== WECHATBIND or layoutId == PHONEBIND then
			--509手机绑定 or 511微信绑定
			if next(HongDianItem["ID"]) ~= nil then
				tab[WECHATBIND.."_"..PHONEBIND] = 1;
			end
		elseif layoutId== CHARMRANK or layoutId == COINRANK or layoutId== RECHARGERANK or layoutId == EARNRANK or layoutId== ARENARANK then
			--501魅力排行榜 --502财富排行榜 --503每日充值排行榜 --504每日赚金排行榜 --505竞技场排行榜
			if next(HongDianItem["ID"]) ~= nil then
				tab[CHARMRANK.."_"..COINRANK.."_"..RECHARGERANK.."_"..EARNRANK.."_"..ARENARANK] = 1;
			end
		else
			--其他
			if next(HongDianItem["ID"]) ~= nil then
				tab[layoutId] = 1;
			end
		end
	end
	return tab
end

--[[--
--获取大厅界面需要删除的红点整合数据
--]]
function getHallRemoveRedPointTable()
	local tab = {}

	tab[ACHIEVEMENTTASK.."_"..DAILYTASK] = 0;
	tab[WECHATBIND.."_"..PHONEBIND] = 0;
	tab[CHARMRANK.."_"..COINRANK.."_"..RECHARGERANK.."_"..EARNRANK.."_"..ARENARANK] = 0;
	tab[MONTHCARD] = 0; --510月卡

	for layoutId, HongDianItem in pairs(AllRedPointDataTable) do
		if layoutId == ACHIEVEMENTTASK or layoutId == DAILYTASK then
			--24.金花成就任务  --25.金花每日任务
			if next(HongDianItem["ID"]) ~= nil then
				tab[ACHIEVEMENTTASK.."_"..DAILYTASK] = 1;
			end
		elseif layoutId == WECHATBIND or layoutId == PHONEBIND then
			--509手机绑定 --511微信绑定
			if next(HongDianItem["ID"]) ~= nil then
				tab[WECHATBIND.."_"..PHONEBIND] = 1;
			end
		elseif layoutId== CHARMRANK or layoutId == COINRANK or layoutId== RECHARGERANK or layoutId == EARNRANK or layoutId== ARENARANK then
			--501魅力排行榜 --502财富排行榜 --503每日充值排行榜 --504每日赚金排行榜 --505竞技场排行榜
			if next(HongDianItem["ID"]) ~= nil then
				tab[CHARMRANK.."_"..COINRANK.."_"..RECHARGERANK.."_"..EARNRANK.."_"..ARENARANK] = 1;
			end
		else
			if next(HongDianItem["ID"]) ~= nil then
				tab[layoutId] = 1;
			end
		end
	end
	return tab
end

--------------获取红点数据------------------------
function getMANAGERID_REQUEST_REDP_HongDian_Table()
	return AllRedPointDataTable
end


--[[--
--根据模块判断当前是否有红点
--]]--
function getIsHaveRedForModuleId(moduleId)
	if AllRedPointDataTable["" .. moduleId] == nil then
		return false;
	end
	if AllRedPointDataTable["" .. moduleId]["ID"] ~= nil and next(AllRedPointDataTable["" .. moduleId]["ID"]) ~= nil then
		return true
	else
		return false
	end
end

--[[--
--读取红点数据
--]]
function readMANAGERID_REQUEST_REDP(dataTable)
	Common.log("readMANAGERID_REQUEST_REDP ")
	AllRedPointDataTable = {}
	for i = 1, #dataTable do
		local pointId = dataTable[i].RedPointId--红点ID
		local reddetail = dataTable[i]["isRed"]--红点详情
		if reddetail ~=	"" then
			AllRedPointDataTable["" .. pointId] = {}
			AllRedPointDataTable["" .. pointId]["ID"] = {}
			--有红点
			for j = 1, #GamePub.split(reddetail, ",") do
				AllRedPointDataTable["".. pointId]["ID"][j] = GamePub.split(reddetail, ",")[j]
			end
		end
	end
	framework.emit(MANAGERID_REQUEST_REDP)
end

--[[--
--推送红点数据
--]]
function readMANAGERID_PUSH_REDP(dataTable)
	framework.emit(MANAGERID_PUSH_REDP)
end
--=============牛牛好友小红点  单独的消息
local friendRedMarkTable = {}
function readDOUNIU_MGR_FRIEND_HAVE_REDP(dataTable)
	friendRedMarkTable = dataTable
	framework.emit(DOUNIU_MGR_FRIEND_HAVE_REDP)
end
function getFriendRedMarkTable()
	return friendRedMarkTable
end


registerMessage(MANAGERID_REQUEST_REDP, readMANAGERID_REQUEST_REDP)
registerMessage(DOUNIU_MGR_FRIEND_HAVE_REDP, readDOUNIU_MGR_FRIEND_HAVE_REDP)
registerMessage(MANAGERID_PUSH_REDP, readMANAGERID_PUSH_REDP)
