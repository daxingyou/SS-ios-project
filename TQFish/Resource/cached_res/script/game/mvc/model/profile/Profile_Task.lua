module(..., package.seeall)
---------------------新版任务-----------------------------

local COMMONS_LIFETIME_TASKLISTTable = {};--成就任务列表
local COMMONS_GET_LIFETIME_TASKPRIZETable = {};--领取成就任务奖励
local AchievementTaskTimeStamp = nil;--领取成就任务时间戳

local COMMONS_DAILYTASKTable = {};--每日任务列表
local COMMONS_GET_DAILYTASK_PRIZETable = {};--领取每日任务奖励

--3.16.30 成就任务列表（COMMONS_LIFETIME_TASKLIST）
function readCOMMONS_LIFETIME_TASKLIST(dataTable)
	COMMONS_LIFETIME_TASKLISTTable = dataTable;
	framework.emit(COMMONS_LIFETIME_TASKLIST)
end
function getAchievementTask()
	return COMMONS_LIFETIME_TASKLISTTable;
end

--3.16.31 领取成就任务奖励（COMMONS_GET_LIFETIME_TASKPRIZE）
function readCOMMONS_GET_LIFETIME_TASKPRIZE(dataTable)
	COMMONS_GET_LIFETIME_TASKPRIZETable = dataTable;
	--将时间戳保存在本地
	AchievementTaskTimeStamp = COMMONS_GET_LIFETIME_TASKPRIZETable["TimeStamp"]
	Common.setDataForSqlite("AchievementTaskTimeStamp", AchievementTaskTimeStamp)
	framework.emit(COMMONS_GET_LIFETIME_TASKPRIZE)
end
function getAchievementTaskList()
	return COMMONS_GET_LIFETIME_TASKPRIZETable;
end

--[[--
--发送领取成就任务奖励
--]]--
function sendGetAchievementAward(taskId)
	AchievementTaskTimeStamp = Common.getDataForSqlite("AchievementTaskTimeStamp")
	if AchievementTaskTimeStamp == nil or AchievementTaskTimeStamp == "" then
		AchievementTaskTimeStamp = 0;
	end
	sendCOMMONS_GET_LIFETIME_TASKPRIZE(AchievementTaskTimeStamp,tonumber(taskId))
end


--3.16.32 每日任务列表（COMMONS_DAILYTASK）
function readCOMMONS_DAILYTASK(dataTable)
	COMMONS_DAILYTASKTable = dataTable;
	framework.emit(COMMONS_DAILYTASK)
end
function getEveryDayTask()
	return COMMONS_DAILYTASKTable;
end

--3.16.33 领取每日任务奖励（COMMONS_GET_DAILYTASK_PRIZE）
function readCOMMONS_GET_DAILYTASK_PRIZE(dataTable)
	COMMONS_GET_DAILYTASK_PRIZETable = dataTable;
	framework.emit(COMMONS_GET_DAILYTASK_PRIZE);
end
function getGetEveryDayPrize()
	return COMMONS_GET_DAILYTASK_PRIZETable;
end

--3.16.30 成就任务列表（COMMONS_LIFETIME_TASKLIST）
registerMessage(COMMONS_LIFETIME_TASKLIST, readCOMMONS_LIFETIME_TASKLIST)
--3.16.31 领取成就任务奖励（COMMONS_GET_LIFETIME_TASKPRIZE）
registerMessage(COMMONS_GET_LIFETIME_TASKPRIZE, readCOMMONS_GET_LIFETIME_TASKPRIZE)
--3.16.32 每日任务列表（COMMONS_DAILYTASK）
registerMessage(COMMONS_DAILYTASK, readCOMMONS_DAILYTASK)
--3.16.33 领取每日任务奖励（COMMONS_GET_DAILYTASK_PRIZE）
registerMessage(COMMONS_GET_DAILYTASK_PRIZE, readCOMMONS_GET_DAILYTASK_PRIZE)
