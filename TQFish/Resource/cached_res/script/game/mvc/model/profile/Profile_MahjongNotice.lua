module(..., package.seeall)

local NoticeTable = {}
local TimeStamp = 0

local function readMJ_SC_NOTICE(dataTable)
	NoticeTable = dataTable
	if NoticeTable ~= nil then
		TimeStamp = NoticeTable["Timestamp"]
	end

	if NoticeTable["RecordList"] == nil or #NoticeTable["RecordList"] <= 0 then
		return
	end
	framework.emit(MJ_SC_NOTICE)
end

function getNoticeTable()
	return NoticeTable
end

--[[--
--获取一条大厅公告
--]]
function getOneNotice()
	local notice = nil
	if NoticeTable["RecordList"] ~= nil and #NoticeTable["RecordList"] > 0 then
		notice = NoticeTable["RecordList"][1]
		table.remove(NoticeTable["RecordList"], 1);
	else
		notice = ""
		sendMJ_SC_NOTICE(TimeStamp)
	end
	return notice
end

--[[--
--获取大厅公告时间戳
--]]
function getNoticeTimeStamp()
	return TimeStamp
end

registerMessage(MJ_SC_NOTICE, readMJ_SC_NOTICE)
