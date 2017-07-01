module(..., package.seeall)

--[[--
--解析心跳
--]]
function readMSG_IDLE(dataTable)
	framework.emit(MSG_IDLE)
end

registerMessage(MSG_IDLE, readMSG_IDLE) -- 心跳消息