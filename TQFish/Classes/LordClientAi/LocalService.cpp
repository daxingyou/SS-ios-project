#include "LocalService.h"

LocalService::LocalService()
{
	srand((unsigned int)time(NULL));

	m_vSerRobotHand.clear();
	m_vvAllCardValue.clear();

	m_UpRobot = NULL;

	m_DownRobot = NULL;

	m_vSerRobotHand.resize(3);
	m_vvAllCardValue.resize(4);
	memset(m_SerSendCard, -1, 20*sizeof(int));
}

LocalService::~LocalService()
{
	m_vSerRobotHand.clear();
	m_vvAllCardValue.clear();
	m_vSerRobotHand.resize(3);
	m_vvAllCardValue.resize(4);
	memset(m_SerSendCard, -1, 20*sizeof(int));
}

LordRobot* LocalService::getLordRobotByPos(int pos)
{
	if (pos == 1){
		return m_DownRobot;
	}else if (pos == 2){
		return m_UpRobot;
	}else{
		return NULL;
	}
}

/***************与lua层交互的接口*************************/
//创建AI机器人
void LocalService::creatRobotByPos(int pos)
{
    if (pos == 1){
		m_DownRobot = createRobot(3,0);
	}
	if (pos == 2){
		m_UpRobot = createRobot(3,0);
	}

}

//删除AI机器人
void LocalService::deleteRobotByPos(int pos)
{
	if (pos == 1){
		destoryRobot(m_DownRobot);
	}
	if (pos == 2){
		destoryRobot(m_UpRobot);
	}
}

//lua通知本地服务器  初始化机器人手牌
void LocalService::broadcastRobotHandCards()
{
    //三家手牌
    int card0[kPlayerHandCardCount];
    int card1[kPlayerHandCardCount];
    int card2[kPlayerHandCardCount];

    for (int i = 0; i < m_vvAllCardValue[0].size(); ++i)
	{
        card0[i] = m_vvAllCardValue[0][i];
	}
    for (int i = 0; i < m_vvAllCardValue[1].size(); ++i)
	{
        card1[i] = m_vvAllCardValue[1][i];
	}
    for (int i = 0; i < m_vvAllCardValue[2].size(); ++i)
	{
        card2[i] = m_vvAllCardValue[2][i];
	}

    //当前ai对象，自己的牌，上家，下家
    initCard(getLordRobotByPos(1), card1, card0, card2);
    initCard(getLordRobotByPos(2), card2, card1, card0);
}


//删除所有牌
void LocalService::removeAllCards()
{
    m_vSerRobotHand.clear(); //三家手牌数量
	m_vSerRobotHand.resize(3);
    m_vvAllCardValue.clear(); //清空一副牌
    m_vvAllCardValue.resize(4);
    memset(m_SerSendCard, -1, 20*sizeof(int));
}

//本地服务器 通知lua发牌牌值  3代表底牌
string LocalService::getHandCardsByPos(int pos)
{
    string strResult = "";

    int nHandCardCount = 17;
    if (pos == 3)
        nHandCardCount = 3;

    for (int i = 0; i < nHandCardCount; ++i)
    {
        char szbuffer[32] = {0};
        sprintf(szbuffer, "%d_", m_vvAllCardValue[pos][i]);
        strResult += szbuffer;
    }

    strResult.erase(strResult.end()-1);

    //CCLOG("%s", strResult.c_str());

    return strResult;
}

//获取AI牌力
int LocalService::getRobotShowCardByPos(int pos)
{
	if (getLordRobotByPos(pos) == NULL){
		CCLOG("AI 牌力 =========== null");
		return 0;
	}
	//// bit 0-7:    0 表示当地主赢不了， 3表示赢概率比较大， 2 次之， 1 更次
	//// bit 8-15:  0 表示当上家农民赢不了， 3表示赢概率比较大， 2 次之， 1 更次
	//// bit 16-23: 0 表示当下家农民赢不了， 3表示赢概率比较大， 2 次之， 1 更次
	int ShowCard = showCard(getLordRobotByPos(pos));

	return ShowCard;
}

//AI叫分
int LocalService::getRobotCallScoreByPos(int pos)
{
	//CCLOG("AI 叫分 pos=========== %d", pos);
	if (getLordRobotByPos(pos) == NULL){
		//CCLOG("AI 叫分 =========== null");
		return -1;
	}
    int nRobotCallScore = callScore(getLordRobotByPos(pos));
	//CCLOG("AI 叫分=========== %d", nRobotCallScore);
    return nRobotCallScore;
}

//设置地主
void LocalService::setLordPos(int pos)
{
	//CCLOG("设置地主 pos=========== %d", pos);

    //三张底牌
    int downCard[3];
    for (int i = 0; i< m_vvAllCardValue[3].size(); ++i)
    {
        downCard[i] = m_vvAllCardValue[3][i];
    }

    //先确定谁是地主 玩家叫分信息 Player_number, 0: down player,1: up player. 2: cur player 谁是地主
	//beLord(getLordRobotByPos((lord+0)%3),pot,2);
	//beLord(getLordRobotByPos((lord+1)%3),pot,1);
	//beLord(getLordRobotByPos((lord+2)%3),pot,0);
    if (pos == 0)
    {
        beLord(getLordRobotByPos(1), downCard, 1);
        beLord(getLordRobotByPos(2), downCard, 0);
    }
    else if (pos == 1)
    {
		beLord(getLordRobotByPos(2), downCard, 1);
        beLord(getLordRobotByPos(1), downCard, 2);
    }
    else if (pos == 2)
    {
        beLord(getLordRobotByPos(1), downCard, 0);
        beLord(getLordRobotByPos(2), downCard, 2);
    }
    m_vSerRobotHand[pos] += 3;  //地主多三张牌
}

//lua通知本地服务器出牌牌值
void LocalService::selfTakeCards(string strCardValue)
{
	memset(m_SerSendCard, -1, 20*sizeof(int));

	if (!(strCardValue.empty() || strCardValue == ""))
	{
		vector<int> vCardValue = DelimStringToVector(strCardValue, "_");

		//CCLOG("vCardValue.size() ==== %d", vCardValue.size());

		for (int i = 0; i<vCardValue.size(); ++i)
		{
			m_SerSendCard[i] = vCardValue[i];
			//CCLOG("m_SerSendCard[i] ==== %d", m_SerSendCard[i]);
		}
		m_vSerRobotHand[0] -= vCardValue.size(); //自己出牌的数量
	}

	//CCLOG("m_SerSendCard[0] ==== %d", m_SerSendCard[0]);

    // 0: down player, 1: up player.
    getPlayerTakeOutCards(getLordRobotByPos(1), m_SerSendCard, 1) ;
    getPlayerTakeOutCards(getLordRobotByPos(2), m_SerSendCard, 0) ;
}

//本地服务器通知lua当前出牌人的出牌牌值  "-1"代表没有出
string LocalService::getTakeCardByPos(int pos)
{
    string strResult = "";

    //清空出牌数据
    //memset(m_SerSendCard, -1, 20*sizeof(int));
    //for (int i = 0; i< 20; ++i)
    //{
    //	CCLOG("m_SerSendCard[i] ==== %d", m_SerSendCard[i]);
    //}
    int bSendSucc = takeOut(getLordRobotByPos(pos), m_SerSendCard); //返回是否出牌  0代表不出
	//CCLOG("AI 出牌 bSendSucc=========== %d", bSendSucc);
	//CCLOG("AI 出牌 m_SerSendCard[0] ==== %d", m_SerSendCard[0]);
	// 0: down player, 1: up player.
	if (pos == 1)
	{
		getPlayerTakeOutCards(getLordRobotByPos(2), m_SerSendCard, 1);
	}else if (pos == 2)
	{
		getPlayerTakeOutCards(getLordRobotByPos(1), m_SerSendCard, 0);
	}
    if (bSendSucc <= 0)
    {
        strResult = "-1"; //没有出牌
        return strResult;
    }
    int nSendCount = GetSendCardCount(m_SerSendCard); //成功出牌后的出牌数量
    for (int i = 0; i < nSendCount; ++i)
    {
        char szbuffer[32] = {0};
        sprintf(szbuffer, "%d_", m_SerSendCard[i]);
        strResult += szbuffer;
    }
    strResult.erase(strResult.end()-1);

	m_vSerRobotHand[pos] -= nSendCount;

    return strResult;

}

//本地服务器通知lua出牌人的剩余牌数量 用于显示
int LocalService::getTakeCardsSurplusByPos(int pos)
{
    return m_vSerRobotHand[pos];
}


//bool LocalService::InitLuaPro()
//{
//	creatRobotByPos(1);
//	creatRobotByPos(2);
//
//    shuffleCards();
//
//    //1,获取每家的手牌
//    CCLOG("0家的手牌%s", getHandCardsByPos(0).c_str());
//    CCLOG("1家的手牌%s", getHandCardsByPos(1).c_str());
//    CCLOG("2家的手牌%s", getHandCardsByPos(2).c_str());
//    CCLOG("3家的手牌%s", getHandCardsByPos(3).c_str());
//
//    //2,把所有的牌通知机器人
//    broadcastRobotHandCards();
//
//	//机器人明牌
//	CCLOG("1showCard%d", getRobotShowCardByPos(1));
//	CCLOG("2showCard%d", getRobotShowCardByPos(2));
//
//    //3,获取机器人的叫分
//    CCLOG("1getRobotCallScoreByPos%d", getRobotCallScoreByPos(1));
//    CCLOG("2getRobotCallScoreByPos%d", getRobotCallScoreByPos(2));
//	
//	//机器人抢地主
//	//CCLOG("1forceLord%d", forceLord(getLordRobotByPos(1)));
//	//CCLOG("2forceLord%d", forceLord(getLordRobotByPos(2)));
//	
//	//机器人的加倍
//	//CCLOG("1doubleGame%d", doubleGame(getLordRobotByPos(1)));
//	//CCLOG("2doubleGame%d", doubleGame(getLordRobotByPos(2)));
//
//	//// 1 表示加倍，0 表示不加倍
//	//int doubleGame(LordRobot* robot);
//	//// bit 0-7:    0 表示当地主赢不了， 3表示赢概率比较大， 2 次之， 1 更次
//	//// bit 8-15:  0 表示当上家农民赢不了， 3表示赢概率比较大， 2 次之， 1 更次
//	//// bit 16-23: 0 表示当下家农民赢不了， 3表示赢概率比较大， 2 次之， 1 更次
//	//int showCard(LordRobot* robot);
//	////1 表示抢地主，0 表示不抢
//	//int forceLord(LordRobot* robot);
//
// //   //4,设置自己是地主  如果自己是地主则不需要第3步
// //   setLordPos(1);
//
//    //5,自己出牌
//    //char szfbuffer[32] = {0};
//    //sprintf(szfbuffer, "%d", m_vvAllCardValue[3][0]);
//    //ClientToServer_MyselfTakeCard(szfbuffer);
//
//    //6,询问机器人是否出牌
//    //CCLOG("%s", ServerToClient_TakeCardValue(1).c_str());
//    //CCLOG("%s", ServerToClient_TakeCardValue(2).c_str());
//
//    //5,询问机器人是否出牌
//    //CCLOG("%s", ServerToClient_TakeCardValue(1).c_str());
//    //CCLOG("%s", ServerToClient_TakeCardValue(2).c_str());
//
//    return true;
//}

vector<int> LocalService::GetRandomSendCardValue()

{
    vector<int> vCardValue;
    for (int i = 0; i < 54; ++i)
    {
        vCardValue.push_back(i);
    }
	int index, tmp, nCount;
	nCount = vCardValue.size();
	for(int i = 0; i < nCount; i++)
	{
	index=rand()%(nCount-i)+i;
	if(index != i)
	{
	tmp=vCardValue[i];
	vCardValue[i]=vCardValue[index];
	vCardValue[index]=tmp;
	}
	}

    return vCardValue;
}

//发牌
void LocalService::shuffleCards()
{
    vector<int> vCardValue;
    vCardValue = GetRandomSendCardValue();

    m_vvAllCardValue.resize(4);

    //CCLOG("**********************玩家0手牌********************");
    for (int i = 0; i < 17; ++i)
    {
        m_vvAllCardValue[0].push_back(vCardValue[i]);
        //CCLOG("玩家0手牌:%s", GetCardValue(vCardValue[i]).c_str());
    }
    //CCLOG("**********************玩家1手牌********************");
    for (int i = 17; i < 34; ++i)
    {
        m_vvAllCardValue[1].push_back(vCardValue[i]);
        //CCLOG("玩家1手牌:%s", GetCardValue(vCardValue[i]).c_str());
    }
    //CCLOG("**********************玩家2手牌********************");
    for (int i = 34; i < 51; ++i)
    {
        m_vvAllCardValue[2].push_back(vCardValue[i]);
        //CCLOG("玩家2手牌:%s", GetCardValue(vCardValue[i]).c_str());
    }
    //CCLOG("**********************3张底牌********************");
    for (int i = 51; i < 54; ++i)
    {
        m_vvAllCardValue[3].push_back(vCardValue[i]);
        //CCLOG("底牌:%s", GetCardValue(vCardValue[i]).c_str());
    }

	for (int i = 0; i < m_vSerRobotHand.size(); ++i)
    {
        m_vSerRobotHand[i] = 17;  //每人17张手牌
    }
}

int LocalService::GetSendCardCount(int cardArray[])
{
    int nReuslt = 0;
    for (int i = 0; i < 20; ++i)
    {
        if (cardArray[i] >= 0)
            ++nReuslt;
        else
            break;
    }
    return nReuslt;
}

vector<int> LocalService::DelimStringToVector(string str, const char *delim)
{
    vector<int> vResult;
    str += delim;
    const int len = strlen(delim);
    size_t index = 0;
    size_t spos = str.find(delim, index);
    while(spos != string::npos)
    {
        string strNum = str.substr(index, spos-index);
        //cout << strNum << endl;
        vResult.push_back(atoi(strNum.c_str()));
        index = spos+len;
        spos = str.find(delim,index);
    }
    return vResult;
}


