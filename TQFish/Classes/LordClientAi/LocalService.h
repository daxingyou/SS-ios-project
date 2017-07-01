#ifndef Lstx_cocos2dX_LocalService_h
#define Lstx_cocos2dX_LocalService_h

#include <stdio.h>
#include <vector>
#include <string>
#include "cocos2d.h"
extern "C"
{
#include "LordRobotAi.h"
}

const int kPlayerHandCardCount = 17; //每个玩家手牌数量

using namespace std;
using namespace cocos2d;

class LocalService
{
public:
    LocalService();
    ~LocalService();
public:
	//发牌
    void shuffleCards();

    //创建AI机器人
    void creatRobotByPos(int pos);
    
    //删除AI机器人
    void deleteRobotByPos(int pos);

    //删除所有牌
    void removeAllCards();

    //lua通知本地  初始化机器人手牌
    void broadcastRobotHandCards();
    
    //本地 通知lua发牌牌值
    string getHandCardsByPos(int pos);
    
	//获取AI牌力
	int getRobotShowCardByPos(int pos);

    //AI叫分
    int getRobotCallScoreByPos(int pos);
    
    //设置地主
    void setLordPos(int pos);
    
    //lua通知本地出牌牌值
    void selfTakeCards(string strCardValue);
    
    //本地通知lua当前出牌人的出牌牌值  "-1"代表没有出
    string getTakeCardByPos(int pos);
    
    //本地通知lua出牌人的剩余牌数量 用于显示
    int getTakeCardsSurplusByPos(int pos);
    
	//bool InitLuaPro();
    
private:
    
    //获取出牌数量
    int GetSendCardCount(int cardArray[]);
	LordRobot* getLordRobotByPos(int pos);
    vector<int> DelimStringToVector(string str, const char *delim);
    vector<int> GetRandomSendCardValue();

private:
    int m_SerSendCard[20]; //出牌牌桌
	LordRobot *m_UpRobot; //上家机器人
	LordRobot *m_DownRobot; //下家机器人
    vector<int> m_vSerRobotHand; //每个人的手牌数
	vector<vector<int> > m_vvAllCardValue; //所有的牌值
};

#endif
