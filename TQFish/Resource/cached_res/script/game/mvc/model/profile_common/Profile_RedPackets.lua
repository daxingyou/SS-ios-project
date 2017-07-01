module(..., package.seeall)

local RedPacketsInfoTable = {} --红包信息table
local RedPacketsReceiveTable = {} --领取红包table

--获取红包信息
function readMANAGERID_GET_RED_PACKETS_INFO(dataTable)
	RedPacketsInfoTable = dataTable
	framework.emit(MANAGERID_GET_RED_PACKETS_INFO)
end

function getRedPacketsInfoTable()
	return RedPacketsInfoTable
end

--获取领取红包结果
function readMANAGERID_RECEIVE_RED_PACKETS(dataTable)
	RedPacketsReceiveTable = dataTable
	framework.emit(MANAGERID_RECEIVE_RED_PACKETS)
end

function getRedPacketsReceiveTable()
	return RedPacketsReceiveTable
end



registerMessage(MANAGERID_GET_RED_PACKETS_INFO , readMANAGERID_GET_RED_PACKETS_INFO);
registerMessage(MANAGERID_RECEIVE_RED_PACKETS , readMANAGERID_RECEIVE_RED_PACKETS);