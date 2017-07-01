#include "cocos2d.h"
#include "CCEGLView.h"
#include "AppDelegate.h"
#include "CCLuaEngine.h"
#include "SimpleAudioEngine.h"
#include "lua_extensions.h"
#include "Services.h"
#include "PublicLuaBridge.h"

#if CC_TARGET_PLATFORM == CC_PLATFORM_IOS
#include "CrashReport.h"
#endif

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS || CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID || CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)

#endif
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
#include "CCLuaJavaBridge.h"
#include "bugly/CrashReport.h"
#endif

using namespace CocosDenshion;
USING_NS_CC;

AppDelegate::AppDelegate() {
}

AppDelegate::~AppDelegate() {
	SimpleAudioEngine::end();
}

bool AppDelegate::applicationDidFinishLaunching() {

	// 调用bugly初始化,传入您自己的appid
	// Android和iOS需要区分不同的appid
	// 注意初始化方法要在执行engine->executeScriptFile("src/main.lua")之前
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)

	if (PublicLuaBridge::getInstance()->productionModels) {
		//正式版本
		CrashReport::initCrashReport("41afa1b72e", false);
	} else{
		//debug版本
		CrashReport::initCrashReport("ca64f2fee3", false);
	}
#elif (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	if (PublicLuaBridge::getInstance()->productionModels) {
		//正式版本
	    CrashReport::initCrashReport("946d25c725", false);
	} else{
	    //debug版本
	    CrashReport::initCrashReport("900019934", false);
	}
#endif

	// initialize director
	CCDirector *pDirector = CCDirector::sharedDirector();
	pDirector->setOpenGLView(CCEGLView::sharedOpenGLView());

	//
	CCSize frameSize = CCEGLView::sharedOpenGLView()->getFrameSize();
	CCSize lsSize = CCSizeMake(800, 480);

	CCEGLView::sharedOpenGLView()->setDesignResolutionSize(lsSize.width, lsSize.height, kResolutionExactFit);

    CCTexture2D::PVRImagesHavePremultipliedAlpha(true);

	// turn on display FPS
	pDirector->setDisplayStats(!PublicLuaBridge::getInstance()->productionModels);

	// set FPS. the default value is 1.0/60 if you don't call this
	pDirector->setAnimationInterval(1.0 / 60);

	// register lua engine
	PublicLuaBridge::getInstance()->initLua();

	return true;
}

// This function will be called when the app is inactive. When comes a phone call,it's be invoked too
void AppDelegate::applicationDidEnterBackground() {
	CCLOG("=======切出游戏=========\n");
#if CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID
	Services::getMessageService()->setCutOut(true);
    SimpleAudioEngine::sharedEngine()->pauseBackgroundMusic();
#endif
	CCDirector::sharedDirector()->stopAnimation();

	PublicLuaBridge::getInstance()->applicationEnterBackground();
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground() {
	CCLOG("=======重新进入游戏=========\n");

	CCDirector::sharedDirector()->startAnimation();
    Services::getMessageService()->setWaitReconnect(true);
    Services::getMessageService()->pauseSocket();

	PublicLuaBridge::getInstance()->applicationEnterForeground();
}
