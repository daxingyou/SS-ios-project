module(..., package.seeall)

local ImageToastTable = {}

function readGAMEID_IMAGE_TOAST(dataTable)
	ImageToastTable = dataTable
	framework.emit(GAMEID_IMAGE_TOAST)
end

function getImageToastTable()
	return ImageToastTable
end

registerMessage(GAMEID_IMAGE_TOAST, readGAMEID_IMAGE_TOAST)