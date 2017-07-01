module(..., package.seeall)

local lastChatText -- 最新聊天信息
local userChatTable -- 用户发言信息
local IMID_OPERATE_CHAT_USER_TYPETable--取得屏蔽消息
local IMID_CHAT_ROOM_SEND_REWARD_V3Table = nil --小游戏领取打赏V3TableInfo

TYPE_ONE_COMMON = 1 --普通玩家/系统
TYPE_TWO_MINI_GAME = 2 --小游戏引导
TYPE_TWO_MINI_GAME_REWARD = 3 --小游戏打赏
TYPE_THREE_SVIP = 4 --SVIP
TYPE_FOUR_FAMILYCHAT = 5 --家族聊天

function getIMID_OPERATE_CHAT_USER_TYPETable()
	return IMID_OPERATE_CHAT_USER_TYPETable
end

function getLastChatText()
	return lastChatText
end

function getUserChatTable()
	return userChatTable
end

function getIMID_CHAT_ROOM_SEND_REWARD_V3Table()
	if IMID_CHAT_ROOM_SEND_REWARD_V3Table ~= nil and IMID_CHAT_ROOM_SEND_REWARD_V3Table ~= "" then
		Common.log("readUserChatTable========"..IMID_CHAT_ROOM_SEND_REWARD_V3Table.SpeechText)
	end
	return IMID_CHAT_ROOM_SEND_REWARD_V3Table
end

--function readLastChatText(dataTable)
--	lastChatText = dataTable["SpeechText"]
--	framework.emit(IMID_GET_LAST_CHAT_ROOM_SPEAK)
--end

function readUserChatTable(dataTable)
	--	userChatTable = dataTable
	--	Common.log("readUserChatTable====================2")
	--	if userChatTable.CheckCode ~= nil and userChatTable.CheckCode ~= "" then
	--		Common.log("readUserChatTable====================1")
	--		IMID_CHAT_ROOM_SEND_REWARD_V3Table = dataTable
	--	end
	--	framework.emit(IMID_CHAT_ROOM_SPEAK)
	--聊天和小游戏全都走的这个消息
	userChatTable = dataTable
	if userChatTable.ActionId == 0 then
		--普通聊天/系统消息
		userChatTable.chatType = TYPE_ONE_COMMON
	else
		--小游戏引导
		userChatTable.chatType = TYPE_TWO_MINI_GAME
	end
	if userChatTable.CheckCode ~= nil and userChatTable.CheckCode ~= "" then
		Common.log("readUserChatTable====================1")
		IMID_CHAT_ROOM_SEND_REWARD_V3Table = dataTable
	end
	framework.emit(IMID_CHAT_ROOM_SPEAK)
end

function readIMID_OPERATE_CHAT_USER_TYPE(dataTable)
	IMID_OPERATE_CHAT_USER_TYPETable = dataTable
	framework.emit(IMID_OPERATE_CHAT_USER_TYPE)
end

function readIMID_CHAT_ROOM_SEND_REWARD_V3(dataTable)
	IMID_CHAT_ROOM_SEND_REWARD_V3Table = dataTable
	framework.emit(IMID_CHAT_ROOM_SEND_REWARD_V3)
end

function setIMID_CHAT_ROOM_SEND_REWARD_V3TableNull()
	IMID_CHAT_ROOM_SEND_REWARD_V3Table = nil
end

--registerMessage(IMID_GET_LAST_CHAT_ROOM_SPEAK, readLastChatText)
registerMessage(IMID_CHAT_ROOM_SPEAK, readUserChatTable)
registerMessage(IMID_OPERATE_CHAT_USER_TYPE, readIMID_OPERATE_CHAT_USER_TYPE)
registerMessage(IMID_CHAT_ROOM_SEND_REWARD_V3, readUserChatTable)
