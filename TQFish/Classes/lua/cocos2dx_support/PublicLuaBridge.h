#ifndef MyCocos2d_PublicLuaBridge_h
#define MyCocos2d_PublicLuaBridge_h

#include "cocos2d.h"
#include <string>
using namespace std;

USING_NS_CC;

#define TQ_PLATFORM_MAIN_GAME          0
#define TQ_PLATFORM_LIANYUN_GAME       1

#define TQ_TARGET_PLATFORM   TQ_PLATFORM_MAIN_GAME

class PublicLuaBridge: public CCObject {
public:
	PublicLuaBridge(void);
	~PublicLuaBridge(void);
	static PublicLuaBridge* getInstance();
    
    string socketState;//
    
    //当前是否是生成模式
    bool productionModels;
	//执行lua文件
    void toDoLuaFile(string luapath);
	//执行lua语句
    void toDoLuaString(string luastring);
	//执行一个lua全局的方法
    void toDoLuaGlobalFunction(string founctionname);

    void initLua();

    void applicationEnterBackground();//切出游戏

    void applicationEnterForeground();//进入游戏
    
    void registerEnterGameScriptHandler(int scriptHandler);//注册切出/入游戏回调lua方法
    
    void changeMessageServiceState(int state);//socket消息状态改变
    
    void registerMessageServiceScriptHandler(int scriptHandler);//注册socket消息状态改变回调lua方法
    
    string getMessageServiceState();//获取socket消息状态
private:
	static PublicLuaBridge* m_instance;
    
private:
    int LuaHandlerForApplicationEnterGame;//切出/入游戏监听
    int LuaHandlerForMessageService;//socket消息状态改变监听
};

#endif
