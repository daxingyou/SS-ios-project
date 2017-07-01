//
//  GoodsBean.h
//  Lstx_cocos2dX
//  
//  Created by auto tools on 2012-07-27 14:42:01.
//  Copyright (c) 2012 renren. All rights reserved.
//

#ifndef Lstx_cocos2dX_GoodsBean_h
#define Lstx_cocos2dX_GoodsBean_h

#include "cocos2d.h"
using namespace cocos2d;


class GoodsBean : public CCObject{

private:

	/**
	 * 商品id
	 */
	int goodsId;
	/**
	 * 商品图片
	 */
	std::string goodsPic;
	/**
	 * 兑换消耗
	 */
	long goodsCost;
	/**
	 * 商品描述
	 */
	std::string goodsDesc;
	/**
	 * 商品限制类型
	 */
	int goodsLimitType;
	/**
	 * 商品数量
	 */
	std::string goodsNum;
	/**
	 * 商品名字
	 */
	std::string goodsName;
	/**
	 * 商品类型
	 */
	int goodsType;
    
public:
    
    GoodsBean(void){
    }
    
    ~GoodsBean(void){
        const char *goodsPicChar = goodsPic.c_str();
        CC_SAFE_DELETE_ARRAY(goodsPicChar);
        const char *goodsDescChar = goodsDesc.c_str();
        CC_SAFE_DELETE_ARRAY(goodsDescChar);
        const char *goodsNumChar = goodsNum.c_str();
        CC_SAFE_DELETE_ARRAY(goodsNumChar);
        const char *goodsNameChar = goodsName.c_str();
        CC_SAFE_DELETE_ARRAY(goodsNameChar);
	}
    
	/**
	 * 商品id
	 */
	int getGoodsId() {
		return this->goodsId;
	}
	/**
	 * 商品id
	 */
	void setGoodsId(int goodsId){
		this->goodsId = goodsId;
	}
	/**
	 * 商品图片
	 */
	std::string getGoodsPic() {
		return this->goodsPic;
	}
	/**
	 * 商品图片
	 */
	void setGoodsPic(std::string goodsPic){
		this->goodsPic = goodsPic;
	}
	/**
	 * 兑换消耗
	 */
	long getGoodsCost() {
		return this->goodsCost;
	}
	/**
	 * 兑换消耗
	 */
	void setGoodsCost(long goodsCost){
		this->goodsCost = goodsCost;
	}
	/**
	 * 商品描述
	 */
	std::string getGoodsDesc() {
		return this->goodsDesc;
	}
	/**
	 * 商品描述
	 */
	void setGoodsDesc(std::string goodsDesc){
		this->goodsDesc = goodsDesc;
	}
	/**
	 * 商品限制类型
	 */
	int getGoodsLimitType() {
		return this->goodsLimitType;
	}
	/**
	 * 商品限制类型
	 */
	void setGoodsLimitType(int goodsLimitType){
		this->goodsLimitType = goodsLimitType;
	}
	/**
	 * 商品数量
	 */
	std::string getGoodsNum() {
		return this->goodsNum;
	}
	/**
	 * 商品数量
	 */
	void setGoodsNum(std::string goodsNum){
		this->goodsNum = goodsNum;
	}
	/**
	 * 商品名字
	 */
	std::string getGoodsName() {
		return this->goodsName;
	}
	/**
	 * 商品名字
	 */
	void setGoodsName(std::string goodsName){
		this->goodsName = goodsName;
	}
	/**
	 * 商品类型
	 */
	int getGoodsType() {
		return this->goodsType;
	}
	/**
	 * 商品类型
	 */
	void setGoodsType(int goodsType){
		this->goodsType = goodsType;
	}

};

#endif
