module("profilePay", package.seeall)

local path = "script.game.mvc.model.profile_pay.Profile_"

PayChannelData = Load.LuaRequire(path .. "PayChannelData")
PaymentResult = Load.LuaRequire(path .. "PaymentResult")
RechargeRecord = Load.LuaRequire(path .. "RechargeRecord")
RechargeResult = Load.LuaRequire(path .. "RechargeResult")
PaymentMode = Load.LuaRequire(path .. "PaymentMode")
