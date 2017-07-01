module(..., package.seeall)

local ConvertTable = {}
ConvertTable["ConvertList"] = {}
local ExchangeList = false

function setConvertTable(dataTable)
	Common.log("model兑换列表")
	--ConvertTable["ConvertList"] = dataTable["GoodsData"]
	--干掉自由兑换
	local j = 1
	for i = 1, #dataTable["GoodsData"] do
		if dataTable["GoodsData"][i].Name == "自由兑换" then
		else
			ConvertTable["ConvertList"][j] = {}
			ConvertTable["ConvertList"][j] =  dataTable["GoodsData"][i]
			j = j+1
		end
	end
	ExchangeList = true
	framework.emit(DBID_EXCHANGE_LIST)
end

function getConvertTable()
	return ConvertTable["ConvertList"]
end

function getExchangeList()
	return ExchangeList
end

registerMessage(DBID_EXCHANGE_LIST,setConvertTable)