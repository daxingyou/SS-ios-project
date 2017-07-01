module(..., package.seeall)

TYPE_DOUNIU = 1;  --看牌抢庄
TYPE_JINNIU = 2; --炸金牛

local BuildTableInfoTable = nil --自建房间数据
local CreateRoomTable = nil --创建房间数据
local EnterRoomTable = nil --进入房间数据
local BuildRoomCountDownTable = nil --自建房间倒计时广播数据
local BuildRoomContinueTable = nil --自建房间续桌广播数据
local BuildTableRoomCodeTable = nil --自建房间号


--自建牌桌信息
local function readDOUNIU_MGR_BUILD_TABLE_INFO(dataTable)

	BuildTableInfoTable = dataTable

	framework.emit(DOUNIU_MGR_BUILD_TABLE_INFO)
end
--获取自建牌桌信息table
function getBuildTableInfoTable()
--	local dataTable = {}
--
--	dataTable["DouNiuBetList"] = {}
--	local DouNiuBetListCnt = 5
--	for i = 1, DouNiuBetListCnt do
--		dataTable["DouNiuBetList"][i] = {}
--		dataTable["DouNiuBetList"][i].minCoin = 10000*i;
--		dataTable["DouNiuBetList"][i].baseCoin = 500*i
--	end
--	--DouNiuTableTimeList	Loop	斗牛底注设定列表
--	dataTable["DouNiuTableTimeList"] = {}
--	local DouNiuTableTimeListCnt = 4
--	for i = 1, DouNiuTableTimeListCnt do
--		dataTable["DouNiuTableTimeList"][i] = {}
--		dataTable["DouNiuTableTimeList"][i].TableTime = 30*i
--	end
--	dataTable["DouNiuTableCost"] = 12345
--
--	--JinNiuBetList	Loop	斗牛底注设定列表
--	dataTable["JinNiuBetList"] = {}
--	local JinNiuBetListCnt = 5
--	for i = 1, JinNiuBetListCnt do
--		dataTable["JinNiuBetList"][i] = {}
--		dataTable["JinNiuBetList"][i].minCoin = 30000*i
--		dataTable["JinNiuBetList"][i].baseCoin = 1000*i
--	end
--	dataTable["JinNiuTableTimeList"] = {}
--	local JinNiuTableTimeListCnt = 4
--	for i = 1, JinNiuTableTimeListCnt do
--		dataTable["JinNiuTableTimeList"][i] = {}
--		dataTable["JinNiuTableTimeList"][i].TableTime = 25*i
--	end
--	--JinNiuTableCost	Int	金牛组桌费
--	dataTable["JinNiuTableCost"] = 54321
--
--	dataTable["SelfCharm"] = 555555555
--	dataTable["CountDownTimeStamp"] = 30
--	dataTable["ContinueTableType"] = 1
--
--	return dataTable

	return BuildTableInfoTable
end

--创建房间
local function readDOUNIU_MGR_BUILD_TABLE(dataTable)

	CreateRoomTable = dataTable

	framework.emit(DOUNIU_MGR_BUILD_TABLE)
end
--获取创建房间table
function getCreateRoomTable()
	return CreateRoomTable
end

--进入房间
local function readDOUNIU_MGR_ENTER_BUILD_TABLE(dataTable)
	EnterRoomTable = dataTable
	framework.emit(DOUNIU_MGR_ENTER_BUILD_TABLE)
end
--获取进入房间table
function getEnterRoomTable()
	return EnterRoomTable
end

--自建房间倒计时广播
local function readDOUNIU_MGR_BUILD_TABLE_COUNTDOWN_BROADCAST(dataTable)
	BuildRoomCountDownTable = dataTable
	framework.emit(DOUNIU_MGR_BUILD_TABLE_COUNTDOWN_BROADCAST)
end
--获取自建房间倒计时广播数据
function getBuildRoomCountDownTable()
	return BuildRoomCountDownTable
end

--自建房续桌广播
local function readDOUNIU_MGR_BUILD_TABLE_CONTINUE_BROADCAST(dataTable)
	BuildRoomContinueTable = dataTable
	framework.emit(DOUNIU_MGR_BUILD_TABLE_CONTINUE_BROADCAST)
end
--获取自建房续桌广播数据
function getBuildRoomContinueTable()
	return BuildRoomContinueTable
end

--自建房续桌广播
local function readDOUNIU_MGR_BUILD_TABLE_ROOMCODE(dataTable)
	BuildTableRoomCodeTable = dataTable
	framework.emit(DOUNIU_MGR_BUILD_TABLE_ROOMCODE)
end
--获取自建房续桌广播数据
function getBuildTableRoomCode()
	local roomCode = BuildTableRoomCodeTable["RoomCode"]
	if roomCode ~= nil then
		return roomCode
	end
	return -1
end

registerMessage(DOUNIU_MGR_BUILD_TABLE_INFO , readDOUNIU_MGR_BUILD_TABLE_INFO);
registerMessage(DOUNIU_MGR_BUILD_TABLE , readDOUNIU_MGR_BUILD_TABLE); --创建房间
registerMessage(DOUNIU_MGR_ENTER_BUILD_TABLE , readDOUNIU_MGR_ENTER_BUILD_TABLE); --进入房间
registerMessage(DOUNIU_MGR_BUILD_TABLE_COUNTDOWN_BROADCAST , readDOUNIU_MGR_BUILD_TABLE_COUNTDOWN_BROADCAST);
registerMessage(DOUNIU_MGR_BUILD_TABLE_CONTINUE_BROADCAST , readDOUNIU_MGR_BUILD_TABLE_CONTINUE_BROADCAST);
registerMessage(DOUNIU_MGR_BUILD_TABLE_ROOMCODE , readDOUNIU_MGR_BUILD_TABLE_ROOMCODE);

