module(..., package.seeall)

local ServerConfigTable = {} --配置内容

function readMANAGERID_GET_SERVER_CONFIG_V2(dataTable)
	for i = 1, #dataTable["ConfigValueData"] do
		local VarName = dataTable["ConfigValueData"][i].VarName;
		local VarValue = dataTable["ConfigValueData"][i].VarValue;
		ServerConfigTable[VarName] = dataTable["ConfigValueData"][i];
		Common.log("GET_SERVER_CONFIG_V2 key == "..VarName);
		Common.log("GET_SERVER_CONFIG_V2 value == ".. VarValue);
	end

	framework.emit(MANAGERID_GET_SERVER_CONFIG_V2)
end

function getServerConfigDataTable(key)
	return ServerConfigTable[key];
end

registerMessage(MANAGERID_GET_SERVER_CONFIG_V2, readMANAGERID_GET_SERVER_CONFIG_V2)