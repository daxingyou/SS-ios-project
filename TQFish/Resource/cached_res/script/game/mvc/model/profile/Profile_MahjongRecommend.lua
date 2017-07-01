module(..., package.seeall)

local MJReceiveRewardTable = {}--邀请好友领奖消息
local MJRecommendInfoTable = {}--邀请好友基本信息

local ShareToWXTable = {} --微信分享返回table


--[[--
--推荐好友领奖界面消息
--]]
local function readMJ_SC_RECEIVE_REWARD(dataTable)
	MJReceiveRewardTable = dataTable
	framework.emit(MJ_SC_RECEIVE_REWARD)
end

function getMJReceiveRewardTable()
	return MJReceiveRewardTable
end


--[[--
--邀请好友基本信息
--]]
local function readMJ_SC_RECOMMEND_INFO(dataTable)
	MJRecommendInfoTable = dataTable
	framework.emit(MJ_SC_RECOMMEND_INFO)
end

function getMJRecommendInfoTable()
	return MJRecommendInfoTable
end

--微信分享
local function readMJ_SC_SHARE_INFO(dataTable)
	ShareToWXTable = dataTable
	framework.emit(MJ_SC_SHARE_INFO)
end

function getShareToWXTable()
	return ShareToWXTable
end

function getShareToWxUrl()
	local value = ShareToWXTable["sharingURL"]
	if value == nil then
		value = ""
	end
	return value
end

function getShareToWxKey()
	local value = ShareToWXTable["Cdkey"]
	if value == nil then
		value = 0
	end
	return value
end

registerMessage(MJ_SC_RECOMMEND_INFO , readMJ_SC_RECOMMEND_INFO);
registerMessage(MJ_SC_RECEIVE_REWARD , readMJ_SC_RECEIVE_REWARD);

registerMessage(MJ_SC_SHARE_INFO , readMJ_SC_SHARE_INFO);