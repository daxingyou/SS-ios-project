module(..., package.seeall)


local UserTable = {}
UserTable["SelfInfo"] = {}
UserTable["OtherInfo"] = {}

local AgeValueTable = {};--"保密", "00后","90后","80后","70后","60后","50后"
AgeValueTable[1] = {};
AgeValueTable[1].txt = "保密";
AgeValueTable[1].day = "0";

AgeValueTable[2] = {};
AgeValueTable[2].txt = "00后";
AgeValueTable[2].day = "2000-01-01";

AgeValueTable[3] = {};
AgeValueTable[3].txt = "90后";
AgeValueTable[3].day = "1990-01-01";

AgeValueTable[4] = {};
AgeValueTable[4].txt = "80后";
AgeValueTable[4].day = "1980-01-01";

AgeValueTable[5] = {};
AgeValueTable[5].txt = "70后";
AgeValueTable[5].day = "1970-01-01";

AgeValueTable[6] = {};
AgeValueTable[6].txt = "60后";
AgeValueTable[6].day = "1960-01-01";

AgeValueTable[7] = {};
AgeValueTable[7].txt = "50后";
AgeValueTable[7].day = "1950-01-01";

function setUserThirdPartPlatId(value)
	UserTable["SelfInfo"].thirdPartPlatId = value
end

function getUserThirdPartPlatId()
	local value = UserTable["SelfInfo"].thirdPartPlatId
	if value == nil then
		return 0
	else
		return tonumber(value)
	end
end

--[[--
--当前用户时候是通过WeChat登录
--]]
function getUserIsWeChatLogin()
	if getUserThirdPartPlatId() == 15 then
		return true;
	end
	return false;
end

--[[--
--根据年龄值获取对应的文本
--]]
function getAgeTxtByValue(value)
	for key, var in pairs(AgeValueTable) do
		if value  == AgeValueTable[key].day then
			return AgeValueTable[key].txt;
		end
	end
	return "保密";
end

--[[--
--根据txt获取年龄值
--]]
function getAgeValueByTxt(txt)
	for key, var in pairs(AgeValueTable) do
		if txt  == AgeValueTable[key].txt then
			return AgeValueTable[key].day;
		end
	end
	return "0";
end

--[[--
--获取年龄值 key table
--]]
function getAgeTxtTable()
	local txtTable  = {};
	for key, var in pairs(AgeValueTable) do
		table.insert(txtTable, AgeValueTable[key].txt);
	end
	return txtTable;
end

--int UserID; -- ID
--String NickName; -- 昵称
--String Password; -- 密码
--String birthday; -- 生日
--int yuanBao; -- 元宝
--long coin; -- 金币
--int masterScore; -- 大师分
--String Sex; -- 性别
--String City; -- 地址
--int Age; -- 年龄
--String PhotoUrl; -- 头像
--String sign; -- 签名
--int honor; -- 荣誉值
--int DuiJiangQuan; -- 兑奖券
--string userAvatorInSD --用户头像在SD卡的位置
------------------------- Vip相关 --------------------------
-- int VipLevel; -- Vip等级
-- long mnVipExpirationDate; -- VipExpirationDate Long Vip到期时间
-- int mnAmount; -- Amount Int 当月累计充值金额 单位：分
-- int mnBalance; -- Balance Int 到达下一级vip的差额 单位：分
-------------------------
-- int EnchargeAmount; -- 充值总金额
--
-- String bindNumber; -- 绑定手机号
-- int djqPieces; -- 兑奖券碎片数量
-- long historyMaxCoin; -- 历史最高金币值
---------------------------------
--
--	public int winRate;// 胜率
--	public int brokenRate;// 断线率
--	public int salaried;// 是否领过工资 1没领过 0领过 2没有资格
--	public int ladderDuan;// 天梯段位
--	public int ladderLevel;// 天梯等级
--	public int ladderScore;// 天梯积分
--	public int ladderUpScore;// 天梯升级积分
--	public int ladderDownScore;// 天梯降级积分
--	public int salary;// 工资
--	public int round;// 盘数
--	public String ladderTitleUrl;// 天梯称号网址
--	public int ladderRanking;// 天梯排名
--	public String grade;// 等级
--	public String title;// 称号

function initUserInfo(userID)
    if userID ~= getSelfUserID() then
        UserTable["SelfInfo"] = {};
        UserTable["OtherInfo"] = {};
    end
end

--[[--
--变量=UserID,类型=int
]]
function getSelfUserID()
	local value = UserTable["SelfInfo"].UserID
	if value == nil then
		return 0
	else
		return value
	end
end

function setSelfUserID(value)
	UserTable["SelfInfo"].UserID = value
end

--[[--
--变量=password,类型=String
]]
function getSelfPassword()
	local value = UserTable["SelfInfo"].Password
	if value == nil then
		return ""
	else
		Common.log("getSelfPassword value =============== "..value)
		return value
	end
end

function setSelfPassword(value)
	if value == nil or value == "" then
		return
	end
	UserTable["SelfInfo"].Password = value
end

--[[--
--变量=NickName,类型=String
]]
function getSelfNickName()
	local value = UserTable["SelfInfo"].NickName
	if value == nil then
		return ""
	else
		return value
	end
end

function setSelfNickName(value)
	if value == nil or value == "" then
		return
	end
	UserTable["SelfInfo"].NickName = value
end

--[[--
--变量=Sex,类型=int
]]
function getSelfSex()
	local value = UserTable["SelfInfo"].Sex
	if value == nil then
		return 0
	else
		return tonumber(value)
	end
end

function setSelfSex(value)
	UserTable["SelfInfo"].Sex = value
end

--[[--
--变量=Age,类型=int
]]
function getSelfAge()
	local value = UserTable["SelfInfo"].Age
	if value == nil then
		return 0
	else
		return tonumber(value)
	end
end

function setSelfAge(value)
	UserTable["SelfInfo"].Age = value
end

--[[--
--生日
]]
function getSelfBirthDay()
	local value = UserTable["SelfInfo"].BirthDay
	if value == nil or value == "" then
		return "0"
	else
		return value
	end
end

function setSelfBirthDay(value)
	UserTable["SelfInfo"].BirthDay = value
end

--[[--
--变量=City,类型=String
]]
function getSelfCity()
	local value = UserTable["SelfInfo"].City
	if value == nil then
		return ""
	else
		return value
	end
end

function setSelfCity(value)
	UserTable["SelfInfo"].City = value
end

--[[--
--变量=PhotoUrl,类型=String
]]
function getSelfPhotoUrl()
	local value = UserTable["SelfInfo"].PhotoUrl
	if value == nil then
		return ""
	else
		return value
	end
end

function setSelfPhotoUrl(value)
	UserTable["SelfInfo"].PhotoUrl = value
end

--[[--
--变量=sign,类型=String
]]
function getSelfsign()
	local value = UserTable["SelfInfo"].sign
	if value == nil or value== "" then
		return "这个家伙很懒,什么都没有写"
	else
		return value
	end
end

function setSelfsign(value)
	UserTable["SelfInfo"].sign = value
end

--[[--
--变量=Coin,类型=int
]]
function getSelfCoin()
	local value = UserTable["SelfInfo"].Coin
	if value == nil then
		return 0
	else
		return tonumber(value)
	end
end

function setSelfCoin(value)
	UserTable["SelfInfo"].Coin = value
end

--[[--
--变量=yuanBao,类型=int
]]
function getSelfYuanBao()
	local value = UserTable["SelfInfo"].yuanBao
	if value == nil then
		return 0
	else
		return tonumber(value)
	end
end

function setSelfYuanBao(value)
	UserTable["SelfInfo"].yuanBao = value
end

--[[--
--变量=Honor,荣誉值,类型=int
]]
function getHonor()
	local value = UserTable["SelfInfo"].Honor
	if value == nil then
		return 0
	else
		return tonumber(value)
	end
end

--[[--
--修改荣誉值
]]
function setHonor(value)
	UserTable["SelfInfo"].Honor = value
end

--[[--
--变量=DuiJiangQuan,类型=int
]]
function getDuiJiangQuan()
	local value = UserTable["SelfInfo"].DuiJiangQuan
	if value == nil then
		return 0
	else
		return tonumber(value)
	end
end
--[[--
--变量=DuiJiangQuan,类型=int
]]
function getOtherDuiJiangQuan()
	local value = UserTable["OtherInfo"].DuiJiangQuan
	if value == nil then
		return 0
	else
		return tonumber(value)
	end
end

function setDuiJiangQuan(value)
	UserTable["SelfInfo"].DuiJiangQuan = value
end

--[[--
--变量=FangkaCount,类型=int奖状数
]]
function getFangkaCnt()
	local value = UserTable["SelfInfo"].fangkaCnt
	if value == nil then
		return 0
	else
		return tonumber(value)
	end
end

function setFangkaCnt(value)
	UserTable["SelfInfo"].fangkaCnt = value
end
------------------------------------vip相关信息 VipLevel  VipExpirationDate  Amount  Balance  --------------

--[[--
--变量=VipLevel,类型=int
]]
function getSelfVipLevel()
	local value = UserTable["SelfInfo"].VipLevel
	if value == nil then
		return 0
	else
		return tonumber(value)
	end
end

function setSelfVipLevel(value)
	UserTable["SelfInfo"].VipLevel = value
end

--[[--
--变量=VipExpirationDate,类型=long VipExpirationDate Long Vip到期时间
]]
function getVipExpirationDate()
	local value = UserTable["SelfInfo"].VipExpirationDate
	if value == nil then
		return 0
	else
		return tonumber(value)
	end
end
--[[--
--变量=Amount,类型=int当月累计充值金额 单位：分
]]
function getSelfAmount()
	local value = UserTable["SelfInfo"].Amount
	if value == nil then
		return 0
	else
		return tonumber(value)
	end
end
--[[--
--变量=Balance,类型=int到达下一级vip的差额 单位：分
]]
function getSelfBalance()
	local value = UserTable["SelfInfo"].Balance
	if value == nil then
		return 0
	else
		return tonumber(value)
	end
end

--[[--
--变量=djqPieces,类型=int
]]
function getSelfdjqPieces()
	local value = UserTable["SelfInfo"].djqPieces
	if value == nil then
		return 0
	else
		return tonumber(value)
	end
end

function setSelfdjqPieces(value)
	UserTable["SelfInfo"].djqPieces = value
end

--[[--
--获取用户充值金额
]]
function getSelfEnchargeAmount()
	local value = UserTable["SelfInfo"].EnchargeAmount
	if value == nil then
		return 0
	else
		return tonumber(value)
	end
end

function setSelfEnchargeAmount(value)
	UserTable["SelfInfo"].EnchargeAmount = value
end
--[[--
--获取用户头像在SD卡的位置
]]
function getSelfUserAvatorInSD()
	local value = UserTable["SelfInfo"].userAvatorInSD
	if value == nil then
		return ""
	else
		return value
	end
end

function setSelfUserAvatorInSD(value)
	UserTable["SelfInfo"].userAvatorInSD = value
end

-------------------------------------------------vip相关------------------------------
--	public int winRate;// 胜率
function getSelfWinRate()
	local value = UserTable["SelfInfo"].winRate
	if value == nil then
		return 0
	else
		return value
	end
end
--	public int brokenRate;// 断线率
function getSelfBrokenRate()
	local value = UserTable["SelfInfo"].brokenRate
	if value == nil then
		return 0
	else
		return value
	end
end
--	public int salaried;// 是否领过工资 1没领过 0领过 2没有资格
function getSelfSalaried()
	local value = UserTable["SelfInfo"].salaried
	if value == nil then
		return 0
	else
		return value
	end
end
--	public int ladderDuan;// 天梯段位
function getSelfLadderDuan()
	local value = UserTable["SelfInfo"].ladderDuan
	if value == nil then
		return 1
	else
		return value
	end
end
--[[--
--设置自己的天梯段位
--]]
function setSelfLadderDuan(ladderDuan)
	UserTable["SelfInfo"].ladderDuan = ladderDuan
end

--	public int ladderLevel;// 天梯等级
function getSelfLadderLevel()
	local value = UserTable["SelfInfo"].ladderLevel
	if value == nil then
		return 1
	else
		return value
	end
end
--[[--
--设置自己的天梯等级
--]]
function setSelfLadderLevel(ladderLevel)
	UserTable["SelfInfo"].ladderLevel = ladderLevel
end
--	public int ladderScore;// 天梯积分
function getSelfLadderScore()
	local value = UserTable["SelfInfo"].ladderScore
	if value == nil then
		return 0
	else
		return value
	end
end
--[[--
--设置自己的天梯积分
--]]
function setSelfLadderScore(ladderScore)
	TTShengjiLogic.preLadderScore = UserTable["SelfInfo"].ladderScore
	UserTable["SelfInfo"].ladderScore = ladderScore
	TTShengjiLogic.CurrentLadderScore = UserTable["SelfInfo"].ladderScore
end
--	public int ladderUpScore;// 天梯升级积分
function getSelfLadderUpScore()
	local value = UserTable["SelfInfo"].ladderUpScore
	if value == nil then
		return 0
	else
		return value
	end
end
--[[--
--设置自己的天梯升级积分
--]]
function setSelfLadderUpScore(ladderUpScore)
	TTShengjiLogic.selfLadderPreUpScore = UserTable["SelfInfo"].ladderUpScore
	UserTable["SelfInfo"].ladderUpScore = ladderUpScore
	TTShengjiLogic.selfLadderUpScore = UserTable["SelfInfo"].ladderUpScore
end
--	public int ladderDownScore;// 天梯降级积分
function getSelfLadderDownScore()
	local value = UserTable["SelfInfo"].ladderDownScore
	if value == nil then
		return 0
	else
		return value
	end
end
--[[--
--设置自己的天梯降级积分
--]]
function setSelfLadderDownScore(ladderDownScore)
	--上一级初始天梯分(降级积分)
	TTShengjiLogic.selfLadderPreDownScore = UserTable["SelfInfo"].ladderDownScore
	UserTable["SelfInfo"].ladderDownScore = ladderDownScore
	--当前段初始天梯分(降级积分)
	TTShengjiLogic.selfLadderDownScore = UserTable["SelfInfo"].ladderDownScore
end
--	public int salary;// 工资
function getSelfSalary()
	local value = UserTable["SelfInfo"].salary
	if value == nil then
		return 0
	else
		return value
	end
end
--	public int round;// 盘数
function getSelfRound()
	local value = UserTable["SelfInfo"].round
	if value == nil then
		return 0
	else
		return value
	end
end
--	public String ladderTitleUrl;// 天梯称号网址
function getSelfLadderTitleUrl()
	local value = UserTable["SelfInfo"].ladderTitleUrl
	if value == nil then
		return ""
	else
		return value
	end
end
--	public int ladderRanking;// 天梯排名
function getSelfLadderRanking()
	local value = UserTable["SelfInfo"].ladderRanking
	if value == nil then
		return 0
	else
		return value
	end
end
--	public String grade;// 等级
function getSelfGrade()
	local value = UserTable["SelfInfo"].grade
	if value == nil then
		return ""
	else
		return value
	end
end
--	public String title;// 称号
function getSelfTitle()
	local value = UserTable["SelfInfo"].title
	if value == nil then
		return ""
	else
		return value
	end
end

--3.8.1 获取用户充值信息(GIFTBAGID_USER_ENCHARGE_INFO)
function readGIFTBAGID_USER_ENCHARGE_INFO(dataTable)
	UserTable["SelfInfo"].EnchargeAmount = dataTable["EnchargeAmount"]
	Common.log("======================= 获取用户充值信息"..UserTable["SelfInfo"].EnchargeAmount)
end

COIN = "coin"; -- 金币
YUANBAO = "yuanbao"; -- 元宝
HONOR = "honor"; -- 荣誉值
DUIJIANG = "duijiang"; -- 兑奖券
VIPLEVEL = "viplevel"; -- VIP等级
DJQPiece = "djqPiece"; -- 兑奖券碎片
--CHARM = "Charm"; -- 魅力

--[[--
--更新用户数据
]]
local function updataUserInfo(name, value)
	if name == nil or value == nil then
		Common.log("更新用户数据-----数据异常");
		return;
	end

	if name == COIN then
		UserTable["SelfInfo"].Coin = tonumber(value)
		Common.log("更新用户数据User.Self.coin = "..UserTable["SelfInfo"].Coin);
	elseif name == YUANBAO then
		UserTable["SelfInfo"].yuanBao = tonumber(value)
		Common.log("更新用户数据User.Self.yuanBao = "..UserTable["SelfInfo"].yuanBao);
	elseif name == HONOR then
		UserTable["SelfInfo"].Honor = tonumber(value)
		Common.log("更新用户数据User.Self.honor = "..UserTable["SelfInfo"].Honor);
	elseif name == DUIJIANG then
		UserTable["SelfInfo"].DuiJiangQuan = tonumber(value)
		Common.log("更新用户数据User.Self.duiJiang = "..UserTable["SelfInfo"].DuiJiangQuan);
	elseif name == VIPLEVEL then
        UserTable["SelfInfo"].VipLevel = tonumber(value)
        Common.log("updataUserInfo == == ="..UserTable["SelfInfo"].VipLevel)
		Common.log("更新用户数据User.Self.mnVipLevel = "..UserTable["SelfInfo"].VipLevel);
	elseif name == DJQPiece then
--		local djqPieces = tonumber(value)
--		if djqPieces > 0 then
--			UserTable["SelfInfo"].djqPieces = djqPieces;
--		end
--		Common.log("更新用户数据User.Self.djqPieces = "..UserTable["SelfInfo"].djqPieces);
--	elseif name == CHARM then
--		UserTable["SelfInfo"].Coin = tonumber(value)
--		Common.log("更新用户数据User.Self.coin = "..UserTable["SelfInfo"].Coin);
	end
end

mnRemainCount = -1

--[[--
--解析破产送金
]]
function readMANAGERID_GIVE_AWAY_GOLD(dataTable)
	-- RemainCount byte 当天剩余破产送金次数
	mnRemainCount = dataTable["mnRemainCount"]
	--ResultMsg  提示语
	local ResultMsg = dataTable["ResultMsg"]
	--IsSuccess byte 是否成功1成功0不成功
	local isSuccess = dataTable["isSuccess"]
	--新版的弹界面
	if isSuccess == 1 then
		-- 破产送金成功
		Common.log("破产送金成功")
--		SendGoldLogic.setValue(ResultMsg)
--		mvcEngine.createModule(GUI_SENDGOLD)
		AudioManager.playGameSound(AudioManager.TableSound.GET_COIN, false, AudioManager.SOUND);
	else
		Common.showToast(ResultMsg, 2)
	end
	framework.emit(MANAGERID_GIVE_AWAY_GOLD)
	framework.emit(BASEID_GET_BASEINFO)

end

--[[--
--GameID用户信息同步
]]
function readGAMEID_USER_ATTR(dataTable)
	local num = #dataTable["UserAttr"]
	Common.log("num ============ "..num)
	for i = 1 , num do
		-- …name Text 属性名
		-- 金币：coin元宝：yuanbao荣誉值：honor兑奖券：duijiang VIP等级：viplevel
		local name = dataTable["UserAttr"][i].name
		-- …value Text 属性值
		local value = dataTable["UserAttr"][i].value
		updataUserInfo(name, value)
	end
	--	profile.GameData.setMySelfCoin(UserTable["SelfInfo"].Coin)
	framework.emit(BASEID_GET_BASEINFO)
end

--[[--
--接受个人信息推送
]]
local function readMJ_SC_MGR_UPDATE_FANGKA(dataTable)
	Common.log("接受个人信息推送#####################");
	--UserID  用户ID
	local userID = dataTable["targetUserId"]
	local GameId = dataTable["GameId"]
	if GameId == GameConfig.GAME_ID and userID == UserTable["SelfInfo"].UserID then
		--NickName  昵称
		UserTable["SelfInfo"].fangkaCnt = dataTable["fangkaCnt"]
	end

	framework.emit(MJ_SC_MGR_UPDATE_FANGKA)
end
--[[
解析vip信息  VipLevel  VipExpirationDate  Amount  Balance
]]----
function readMANAGERID_GET_VIP_MSG(dataTable)
	--VipLevel	Int	当前vip等级
    UserTable["SelfInfo"].VipLevel = dataTable["VipLevel"]
    Common.log("readMANAGERID_GET_VIP_MSG == == ="..UserTable["SelfInfo"].VipLevel)
	--VipExpirationDate	Long	Vip到期时间
	UserTable["SelfInfo"].VipExpirationDate = dataTable["VipExpirationDate"]
	--Amount	Int	当月累计充值金额
	UserTable["SelfInfo"].Amount = dataTable["Amount"]
	--Balance	Int	到达下一级vip的差额
	UserTable["SelfInfo"].Balance = dataTable["Balance"]
	framework.emit(MANAGERID_GET_VIP_MSG)
end
--[[--
--接收个人信息
--UserID  NickName   Sex Age City  PhotoUrl sign Coin yuanBao taoJin DuiJiangQuan commendationCnt VipLevel djqPieces
]]

local function readMJ_SC_MGR_PLAYER_INFO(dataTable)
	Common.log("接收个人信息 =======readMJ_SC_MGR_PLAYER_INFO======= ")

	if dataTable["userID"] == UserTable["SelfInfo"].UserID then
		--接收自己的信息
		UserTable["SelfInfo"].UserID = dataTable["userID"]
		-- NickName text 昵称
		UserTable["SelfInfo"].NickName = dataTable["nickName"]
		-- Sex byte 性别 1男 2女
		UserTable["SelfInfo"].Sex = dataTable["sex"]
		-- Ip
		UserTable["SelfInfo"].ip = dataTable["ip"]
		-- PhotoUrl text 头像URL
		UserTable["SelfInfo"].PhotoUrl = dataTable["photoUrl"]
		-- FangkaCount	Int	房卡数量
		UserTable["SelfInfo"].fangkaCnt = dataTable["fangkaCnt"]
		-- Distance	Int	和我的距离	米
		UserTable["SelfInfo"].Distance = dataTable["Distance"]

	else
		-- NickName text 昵称
		UserTable["OtherInfo"].UserID = dataTable["userID"]
		-- NickName text 昵称
		UserTable["OtherInfo"].NickName = dataTable["nickName"]
		-- Sex byte 性别 1男 2女
		UserTable["OtherInfo"].Sex = dataTable["sex"]
		-- Age byte 年龄
		UserTable["OtherInfo"].Age = dataTable["ip"]
		-- PhotoUrl text 头像URL
		UserTable["OtherInfo"].PhotoUrl = dataTable["photoUrl"]
		-- fangkaCnt	Int	房卡数量
		UserTable["OtherInfo"].fangkaCnt = dataTable["fangkaCnt"]
		-- Distance	Int	和我的距离	米
		UserTable["OtherInfo"].Distance = dataTable["Distance"]
	end
	framework.emit(MJ_SC_MGR_PLAYER_INFO)
end

function getOtherUserInfo()
	return UserTable["OtherInfo"];
end

function getSelfUserInfo()
	return UserTable["SelfInfo"];
end

registerMessage(MANAGERID_GIVE_AWAY_GOLD, readMANAGERID_GIVE_AWAY_GOLD)
registerMessage(GAMEID_USER_ATTR, readGAMEID_USER_ATTR)
--registerMessage(BASEID_GET_BASEINFO, readBASEID_GET_BASEINFO)
registerMessage(MANAGERID_GET_VIP_MSG, readMANAGERID_GET_VIP_MSG)
--registerMessage(DBID_USER_INFO, readDBID_USER_INFO)
registerMessage(GIFTBAGID_USER_ENCHARGE_INFO, readGIFTBAGID_USER_ENCHARGE_INFO)


registerMessage(MJ_SC_MGR_PLAYER_INFO , readMJ_SC_MGR_PLAYER_INFO); --个人信息
registerMessage(MJ_SC_MGR_UPDATE_FANGKA , readMJ_SC_MGR_UPDATE_FANGKA); --更新用户信息(房卡)