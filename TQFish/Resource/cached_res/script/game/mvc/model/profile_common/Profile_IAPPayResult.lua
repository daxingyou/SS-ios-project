module(..., package.seeall)

local IAPPayResult = {}

IAPPayResult["Result"] = 2 -- 0成功    1失败
IAPPayResult["Msg"] = ""

--[[--
--Result
]]
function getResult()
	local value = IAPPayResult["Result"]
	if value == nil then
		return 2
	else
		return value
	end
end

function setResult(result)
	IAPPayResult["Result"] = result
end

--[[--
--ResultText
]]
function getResultText()
	local value = IAPPayResult["Msg"]
	if value == nil then
		return ""
	else
		return value
	end
end
--[[--
--orderID
--]]
function getResultOrder()
	local value = IAPPayResult["orderID"]
	if value == nil then
		return ""
	else
		return value
	end
end


function setResultText(resultText)
	IAPPayResult["Msg"] = resultText
end

function setIAPPayInfo(dataTable)
	IAPPayResult["Result"] = dataTable["Result"]
	IAPPayResult["Msg"] = dataTable["Msg"]
    IAPPayResult["orderID"] = dataTable["orderID"]
	framework.emit(MANAGERID_VALIDATE_IAP_V2)
end

registerMessage(MANAGERID_VALIDATE_IAP_V2, setIAPPayInfo)