module(..., package.seeall)

local StrangerListTable = {}


function getStrangerList()
	return StrangerListTable
end

function readJINHUA_MGR_STRANGER_LIST(dataTable)
	StrangerListTable = dataTable
	framework.emit(JINHUA_MGR_STRANGER_LIST)
end
--陌生人 按钮是否显示小红点
function getStrangerIsShowRedPoint()
	if StrangerListTable == nil or StrangerListTable["FriendList"] == nil or #StrangerListTable["FriendList"] == 0 then
		return false
	end
	
	for i=1,#StrangerListTable["FriendList"] do
	Common.log("StrangerListTable[FriendList][i].unreadCnt === === "..StrangerListTable["FriendList"][i].unreadCnt)
		if StrangerListTable["FriendList"][i].unreadCnt > 0 then
			Common.log("陌生人 按钮是否显示小红点 true")
			return true
		end
	end
	Common.log("陌生人 按钮是否显示小红点 false")
	return false
end


registerMessage(JINHUA_MGR_STRANGER_LIST, readJINHUA_MGR_STRANGER_LIST)