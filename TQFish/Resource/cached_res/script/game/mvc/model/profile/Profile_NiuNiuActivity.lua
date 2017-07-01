module(..., package.seeall)

local NiuNiuActivityTable = {} --斗牛首页推广

local function readDOUNIU_MGR_INDEX_ACTIVITY(dataTable)
	NiuNiuActivityTable = dataTable
	framework.emit(DOUNIU_MGR_INDEX_ACTIVITY)
end

function getNiuNiuActivityTable()
	return NiuNiuActivityTable
end

--[[--
--获取推广列表图片地址
--]]
function getActivityImgTable()
	--去除不显示的模块
	local imgTable = {}
	for i = 1,#NiuNiuActivityTable["ActivityList"] do
		table.insert(imgTable,NiuNiuActivityTable["ActivityList"][i].imgURL)
	end
	return imgTable
end

registerMessage(DOUNIU_MGR_INDEX_ACTIVITY, readDOUNIU_MGR_INDEX_ACTIVITY)