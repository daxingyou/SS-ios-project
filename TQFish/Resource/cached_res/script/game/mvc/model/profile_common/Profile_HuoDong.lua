module(..., package.seeall)

local OPERID_GET_OPER_TASK_LIST_V2Table = {}
local OPERID_GET_OPER_TASK_LISTTable = {}
local MonthlyHasData = false
local OperTaskHasData = false


--[[--
--获取活动信息
]]
function getOPERID_GET_OPER_TASK_LIST_V2Table()
	return OPERID_GET_OPER_TASK_LIST_V2Table
end

--[[--
--获取可更新的小游戏列表
--]]
function getCanUpdateOperTaskInfo()
	local itemTable = {}
	for i = 1,#OPERID_GET_OPER_TASK_LIST_V2Table do
		if(OPERID_GET_OPER_TASK_LIST_V2Table[i].isUpdate == 1) then
			table.insert(itemTable, OPERID_GET_OPER_TASK_LIST_V2Table[i])
		end
	end
	return itemTable
end

function getOPERID_GET_OPER_TASK_LISTTable()
	return OPERID_GET_OPER_TASK_LISTTable
end
 
--活动
function readOPERID_GET_OPER_TASK_LIST_V2Table(dataTable)
	OperTaskHasData = true
	OPERID_GET_OPER_TASK_LIST_V2Table = dataTable
	framework.emit(OPERID_GET_OPER_TASK_LIST_V2)
end

function getOperTaskHasData()
	return OperTaskHasData
end

function getMonthlyHasData()
	return MonthlyHasData
end

registerMessage(OPERID_GET_OPER_TASK_LIST_V2, readOPERID_GET_OPER_TASK_LIST_V2Table)
 