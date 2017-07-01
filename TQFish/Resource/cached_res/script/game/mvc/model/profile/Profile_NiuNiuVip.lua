module(..., package.seeall)

local VipDataTable = {}

--获取VIP特权
local function readDOUNIU_VIPINFO(dataTable)

	VipDataTable = dataTable

	framework.emit(DOUNIU_VIPINFO)
end

function getVipDataTable()
	return VipDataTable
end

registerMessage(DOUNIU_VIPINFO, readDOUNIU_VIPINFO);