module(..., package.seeall)

local NiuNiuReviveInfoTable = {}
local NiuNiuReviveTable = {}
local lastTime = nil --距离破产送金还有多少秒
local hasRelive = nil --是否有破产礼包
local reviveCoin = 0 --破产送金金额
function readDOUNIU_MGR_REVIVE_INFO(dataTable)
	NiuNiuReviveInfoTable = dataTable
	if NiuNiuReviveInfoTable ~= nil then
		hasRelive = NiuNiuReviveInfoTable["hasRelive"]
		if hasRelive == 1 then
			lastTime = NiuNiuReviveInfoTable["Time"]
		end
	end
	framework.emit(DOUNIU_MGR_REVIVE_INFO)
end

function readDOUNIU_MGR_REVIVE(dataTable)
	NiuNiuReviveTable = dataTable
	if NiuNiuReviveTable ~= nil then
		reviveCoin = NiuNiuReviveTable["Coin"]
	end
	hasRelive = 0
	framework.emit(DOUNIU_MGR_REVIVE)
end

function getHasRelive()
	if hasRelive == 1 then
		return true
	else
		return false
	end
end

function getLastTime()
	return lastTime
end

function setLastTime(time)
	lastTime = time
end

function getCoin()
	return reviveCoin
end

registerMessage(DOUNIU_MGR_REVIVE_INFO , readDOUNIU_MGR_REVIVE_INFO);
registerMessage(DOUNIU_MGR_REVIVE , readDOUNIU_MGR_REVIVE);