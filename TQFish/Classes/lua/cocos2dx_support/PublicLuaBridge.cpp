#include "PublicLuaBridge.h"
#include "CCLuaEngine.h"
#include "lua_extensions.h"
#include "SevTCliNotification.h"
#include "NotificationEvent.h"
#include "Services.h"
#include "MessageType.h"
#if CC_TARGET_PLATFORM == CC_PLATFORM_IOS
#include "BuglyLuaAgent.h"
#endif
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
#include "CCLuaJavaBridge.h"
#endif

CCLuaEngine* pEngine;

PublicLuaBridge* PublicLuaBridge::m_instance = NULL;

PublicLuaBridge* PublicLuaBridge::getInstance() {
	if (!m_instance) {
		m_instance = new PublicLuaBridge();
	}
	return m_instance;
}

PublicLuaBridge::PublicLuaBridge() {
    //设置当前是否是生产模式
    productionModels = false;

	pEngine = CCLuaEngine::defaultEngine();
	CCScriptEngineManager::sharedManager()->setScriptEngine(pEngine);

}

void PublicLuaBridge::toDoLuaFile(string luapath) {
	std::string path = CCFileUtils::sharedFileUtils()->fullPathForFilename(luapath.c_str());
	pEngine->executeScriptFile(path.c_str());
}

void PublicLuaBridge::toDoLuaString(string luastring) {
	pEngine->executeString(luastring.c_str());
}

void PublicLuaBridge::toDoLuaGlobalFunction(string founctionname) {
	pEngine->executeGlobalFunction(founctionname.c_str());
}

PublicLuaBridge::~PublicLuaBridge(void) {
	if (!pEngine) {
		pEngine = NULL;
	}
}

void PublicLuaBridge::initLua() {
	// register lua engine
	//CCLuaEngine* pEngine = CCLuaEngine::defaultEngine();
	//CCScriptEngineManager::sharedManager()->setScriptEngine(pEngine);

#if CC_TARGET_PLATFORM == CC_PLATFORM_IOS
    // register lua exception handler with lua engine
    BuglyLuaAgent::registerLuaExceptionHandler(pEngine);
#endif

	CCLuaStack *pStack = pEngine->getLuaStack();
	lua_State *tolua_s = pStack->getLuaState();

	luaopen_lua_extensions(tolua_s);

#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
	CCLuaJavaBridge::luaopen_luaj(tolua_s);
#endif

	std::string path = CCFileUtils::sharedFileUtils()->fullPathForFilename("pkg_res/script/main.lua");
	const char* searchPath = path.substr(0, path.find_last_of("/")).c_str();

	std::vector<std::string> vec_search;
	vec_search.push_back("pkg_res/");
	vec_search.push_back("cached_res/");
	CCFileUtils::sharedFileUtils()->setSearchPaths(vec_search);

	pEngine->addSearchPath(searchPath);

	pEngine->executeScriptFile(path.c_str());
}

void PublicLuaBridge::applicationEnterBackground() {
	if (LuaHandlerForApplicationEnterGame > 0) {
		CCLuaStack* stack = CCLuaEngine::defaultEngine()->getLuaStack();
		stack->pushString("EnterBackground");
		stack->executeFunctionByHandler(LuaHandlerForApplicationEnterGame, 1);
		//stack->clean();
	}
}

void PublicLuaBridge::applicationEnterForeground() {
	if (LuaHandlerForApplicationEnterGame > 0) {
		CCLuaStack* stack = CCLuaEngine::defaultEngine()->getLuaStack();
		stack->pushString("EnterForeground");
		stack->executeFunctionByHandler(LuaHandlerForApplicationEnterGame, 1);
		//stack->clean();
	}
}

//注册切出/入游戏lua方法
void PublicLuaBridge::registerEnterGameScriptHandler(int scriptHandler) {
	LuaHandlerForApplicationEnterGame = scriptHandler;
}

//socket消息状态改变
void PublicLuaBridge::changeMessageServiceState(int state) {
	if (state == MessageType::NETERR_CONN_FAILED) {
		//建立连接失败
		socketState = "NETERR_CONN_FAILED";
	} else if (state == MessageType::NETERR_NET_BROKEN) {
		//网络断开(开始重连)
		socketState = "NETERR_NET_BROKEN";
	} else if (state == MessageType::NETERR_CONN_SUCC) {
		//重连成功
		socketState = "NETERR_CONN_SUCC";
	} else if (state == MessageType::NETERR_CONN_HOST_FAILED) {
		//获取host失败
		socketState = "NETERR_CONN_HOST_FAILED";
	} else {
		socketState = "error";
	}
	//新版本已经抛弃
//	if (LuaHandlerForMessageService > 0) {
//		CCLuaStack* stack = CCLuaEngine::defaultEngine()->getLuaStack();
//		if (state == MessageType::NETERR_CONN_FAILED) {
//			//建立连接失败
//			stack->pushString("NETERR_CONN_FAILED");
//		} else if (state == MessageType::NETERR_NET_BROKEN) {
//			//网络断开(开始重连)
//			stack->pushString("NETERR_NET_BROKEN");
//		} else if (state == MessageType::NETERR_CONN_SUCC) {
//			//重连成功
//			stack->pushString("NETERR_CONN_SUCC");
//		} else if (state == MessageType::NETERR_CONN_HOST_FAILED) {
//			//获取host失败
//			stack->pushString("NETERR_CONN_HOST_FAILED");
//		}
//		stack->executeFunctionByHandler(LuaHandlerForMessageService, 1);
//		//stack->clean();
//	}
}

//注册socket消息状态改变回调lua方法
void PublicLuaBridge::registerMessageServiceScriptHandler(int scriptHandler) {
	LuaHandlerForMessageService = scriptHandler;
}

string PublicLuaBridge::getMessageServiceState() {
	return socketState;
}
