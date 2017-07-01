module("profile", package.seeall)

local path = "script.game.mvc.model.profile.Profile_"

AndroidExit = Load.LuaRequire(path .. "AndroidExit")
ButtonsStatus = Load.LuaRequire(path .. "ButtonsStatus")
DailyTasks = Load.LuaRequire(path .. "DailyTasks")
Gift = Load.LuaRequire(path .. "Gift")
HongDian = Load.LuaRequire(path .. "HongDian")
IM = Load.LuaRequire(path .. "IM")
Pack = Load.LuaRequire(path .. "Pack")
ShareAwardRecipients = Load.LuaRequire(path .. "ShareAwardRecipients")--领取分享的奖励
ShareToWX = Load.LuaRequire(path .. "ShareToWX")
SystemListNotice = Load.LuaRequire(path .. "SystemListNotice")
TableReport = Load.LuaRequire(path .. "TableReport")
TableTips = Load.LuaRequire(path .. "TableTips")
User = Load.LuaRequire(path .. "User")
VIPData = Load.LuaRequire(path .. "VIPData")
VIPState = Load.LuaRequire(path .. "VIPState")
XYPlatformGiftBagExchange = Load.LuaRequire(path .. "XYPlatformGiftBagExchange")--XY新用户礼包兑换
StrangerData = Load.LuaRequire(path .. "StrangerData") --金花陌生人列表
Task = Load.LuaRequire(path .. "Task")--任务

NiuNiuRevive = Load.LuaRequire(path .. "NiuNiuRevive") -- 破产送金
NiuNiuVip = Load.LuaRequire(path .. "NiuNiuVip")--VIP特权
NiuNiuBuildTable = Load.LuaRequire(path .. "NiuNiuBuildTable")--自建房间
NiuNiuActivity = Load.LuaRequire(path .. "NiuNiuActivity")--首页推广



----------------------------------------------------------------------
MahjongUserInfo = Load.LuaRequire(path .. "MahjongUserInfo")--麻将个人信息
MahjongNotice = Load.LuaRequire(path .. "MahjongNotice")--麻将大厅广播
MahjongRecommend = Load.LuaRequire(path .. "MahjongRecommend")--麻将推荐
MahjongRecord = Load.LuaRequire(path .. "MahjongRecord")--麻将战绩
