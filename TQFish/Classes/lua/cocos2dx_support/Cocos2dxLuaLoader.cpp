/****************************************************************************
 Copyright (c) 2011 cocos2d-x.org

 http://www.cocos2d-x.org

 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:

 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.

 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 ****************************************************************************/
#include "Cocos2dxLuaLoader.h"
#include "PublicLuaBridge.h"
#include <string>
#include <algorithm>

using namespace cocos2d;
using namespace std;

string fileNameList[15] = {
		"Luaoc",
		"Luaj",
		"BaseController",
		"ControllerInterface",
		"Framework",
		"CCNodeExtend",
	 	"ccs",
	 	"CCSLayerExtend",
	 	"CCSLayoutExtend",
	 	"CCSWidgetExtend",
	 	"functions",
	 	"ViewTool",
	 	"ViewEvent",
	 	"ViewTags",
	 	"MassageConnect"
	};

extern "C" {

int cocos2dx_lua_loader(lua_State *L) {
	std::string filename(luaL_checkstring(L, 1));
	size_t pos = filename.rfind(".lua");
	if (pos != std::string::npos) {
		filename = filename.substr(0, pos);
	}

	pos = filename.find_first_of(".");

	size_t posLast = filename.find_last_of(".");
	std::string filePathName = filename.substr(posLast + 1, filename.length() - posLast - 1);

	while (pos != std::string::npos) {
		filename.replace(pos, 1, "/");
		pos = filename.find_first_of(".");
	}
	filename.append(".lua");

	unsigned long codeBufferSize = 0;
	unsigned char* codeBuffer = CCFileUtils::sharedFileUtils()->getFileData(filename.c_str(), "rb", &codeBufferSize);

	if (codeBuffer) {
		bool isDispose = false;

		for (int i = 0; i < sizeof(fileNameList) / sizeof(*fileNameList); i++) {
			if (fileNameList[i] == filePathName.c_str()) {
				const int keyLen = 12;
				char key[keyLen] = { 'd', 'h', 'd', 's', 'c', 'x', 'g', 'c', 't', 'q', 'y', 'x' };
				int keyPos = 0;
				for (int i = 0; i < codeBufferSize; i++) {
					codeBuffer[i] ^= key[keyPos];
					keyPos++;
					if (keyPos >= keyLen) {
						keyPos = 0;
					}
				}
				isDispose = true;
				break;
			}
		}

        if (PublicLuaBridge::getInstance()->productionModels && !isDispose) {
			//解密
			//CCLog("decrypt %s \n", filename.c_str());
			for (int i = 0; i < codeBufferSize; i++) {
				if (codeBuffer[i] >= 0 && codeBuffer[i] <= 127) {
					codeBuffer[i] += 5;
				}
			}
		}

		//解密完成
		if (luaL_loadbuffer(L, (char*) codeBuffer, codeBufferSize, filename.c_str()) != 0) {
			luaL_error(L, "error loading module %s from file %s :\n\t%s", lua_tostring(L, 1), filename.c_str(), lua_tostring(L, -1));
		}

		delete[] codeBuffer;
	} else {
		CCLog("can not get file data of %s", filename.c_str());
	}

	return 1;
}

}
