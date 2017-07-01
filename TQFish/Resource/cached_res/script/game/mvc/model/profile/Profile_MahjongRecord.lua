module(..., package.seeall)

local roomRecordData = {}--房间记录
local tableRecordData = {}--牌局记录

local vedioInfoData = {}--获取牌局录像

--[[--
--房间记录消息
--]]
local function readMJ_SC_MGR_ROOM_RECORD(dataTable)
	roomRecordData = dataTable
	framework.emit(MJ_SC_MGR_ROOM_RECORD)
end

function getRoomRecordTable()
	return roomRecordData["infoList"]
end


--[[--
--牌局记录消息
--]]
local function readMJ_SC_MGR_INNING_RECORD(dataTable)
	tableRecordData = dataTable
	framework.emit(MJ_SC_MGR_INNING_RECORD)
end

function getTableRecordTable()
	return tableRecordData
end


--[[--
--获取牌局录像消息
--]]
local function readMJ_SC_MGR_GET_ROOM_RECORD(dataTable)
	vedioInfoData = dataTable
	framework.emit(MJ_SC_MGR_GET_ROOM_RECORD)
end

function getVedioInfoTable()
	return vedioInfoData
end



registerMessage(MJ_SC_MGR_ROOM_RECORD , readMJ_SC_MGR_ROOM_RECORD); --房间记录
registerMessage(MJ_SC_MGR_INNING_RECORD , readMJ_SC_MGR_INNING_RECORD); --牌局记录

registerMessage(MJ_SC_MGR_GET_ROOM_RECORD , readMJ_SC_MGR_GET_ROOM_RECORD); --获取牌局录像
