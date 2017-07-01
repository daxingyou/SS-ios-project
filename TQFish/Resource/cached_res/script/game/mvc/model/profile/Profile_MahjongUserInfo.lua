module(..., package.seeall)

local mjHallInfoTable = {}--大厅基础配置信息
local exchangeRoomCardTable = {}--兑换房卡

--大厅基本信息
local function readMJ_SC_HALL_INFO(dataTable)
	mjHallInfoTable = dataTable
	framework.emit(MJ_SC_HALL_INFO)
end

function getMJHallInfoTable()
	return mjHallInfoTable
end

--兑换房卡
local function readMJ_SC_MGR_EXCHANGE_CODE(dataTable)
	exchangeRoomCardTable = dataTable
	framework.emit(MJ_SC_MGR_EXCHANGE_CODE)
end

function getExchangeRoomCardTable()
	return exchangeRoomCardTable
end


registerMessage(MJ_SC_HALL_INFO , readMJ_SC_HALL_INFO);
registerMessage(MJ_SC_MGR_EXCHANGE_CODE , readMJ_SC_MGR_EXCHANGE_CODE); --兑换房卡
