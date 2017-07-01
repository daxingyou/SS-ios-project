//
//  MailInfo.h
//  Lstx_cocos2dX
//  
//  Created by auto tools on 2012-07-27 14:42:01.
//  Copyright (c) 2012 renren. All rights reserved.
//

#ifndef Lstx_cocos2dX_MailInfo_h
#define Lstx_cocos2dX_MailInfo_h

#include "cocos2d.h"
using namespace cocos2d;


class MailInfo : public CCObject{

private:

	/**
	 * 邮件标题
	 */
	std::string mailTitle;
	/**
	 * 发件人
	 */
	std::string senderName;
	/**
	 * 邮件类型
	 */
	int mailTypeIndex;
	/**
	 * 邮件ID
	 */
	long mailId;
	/**
	 * 是否有附件
	 */
	bool hasAttachment;
	/**
	 * 邮件发送季
	 */
	std::string sendSeason;
	/**
	 * 邮件过期季节
	 */
	std::string expireSeason;
	/**
	 * 邮件发送年
	 */
	std::string sendYear;
	/**
	 * 是否已读
	 */
	bool checked;
	/**
	 * 邮件过期年
	 */
	std::string expireYear;
    
public:
    
    MailInfo(void){
    }
    
    ~MailInfo(void){
        const char *mailTitleChar = mailTitle.c_str();
        CC_SAFE_DELETE_ARRAY(mailTitleChar);
        const char *senderNameChar = senderName.c_str();
        CC_SAFE_DELETE_ARRAY(senderNameChar);
        const char *sendSeasonChar = sendSeason.c_str();
        CC_SAFE_DELETE_ARRAY(sendSeasonChar);
        const char *expireSeasonChar = expireSeason.c_str();
        CC_SAFE_DELETE_ARRAY(expireSeasonChar);
        const char *sendYearChar = sendYear.c_str();
        CC_SAFE_DELETE_ARRAY(sendYearChar);
        const char *expireYearChar = expireYear.c_str();
        CC_SAFE_DELETE_ARRAY(expireYearChar);
	}
    
	/**
	 * 邮件标题
	 */
	std::string getMailTitle() {
		return this->mailTitle;
	}
	/**
	 * 邮件标题
	 */
	void setMailTitle(std::string mailTitle){
		this->mailTitle = mailTitle;
	}
	/**
	 * 发件人
	 */
	std::string getSenderName() {
		return this->senderName;
	}
	/**
	 * 发件人
	 */
	void setSenderName(std::string senderName){
		this->senderName = senderName;
	}
	/**
	 * 邮件类型
	 */
	int getMailTypeIndex() {
		return this->mailTypeIndex;
	}
	/**
	 * 邮件类型
	 */
	void setMailTypeIndex(int mailTypeIndex){
		this->mailTypeIndex = mailTypeIndex;
	}
	/**
	 * 邮件ID
	 */
	long getMailId() {
		return this->mailId;
	}
	/**
	 * 邮件ID
	 */
	void setMailId(long mailId){
		this->mailId = mailId;
	}
	/**
	 * 是否有附件
	 */
	bool getHasAttachment() {
		return this->hasAttachment;
	}
	/**
	 * 是否有附件
	 */
	void setHasAttachment(bool hasAttachment){
		this->hasAttachment = hasAttachment;
	}
	/**
	 * 邮件发送季
	 */
	std::string getSendSeason() {
		return this->sendSeason;
	}
	/**
	 * 邮件发送季
	 */
	void setSendSeason(std::string sendSeason){
		this->sendSeason = sendSeason;
	}
	/**
	 * 邮件过期季节
	 */
	std::string getExpireSeason() {
		return this->expireSeason;
	}
	/**
	 * 邮件过期季节
	 */
	void setExpireSeason(std::string expireSeason){
		this->expireSeason = expireSeason;
	}
	/**
	 * 邮件发送年
	 */
	std::string getSendYear() {
		return this->sendYear;
	}
	/**
	 * 邮件发送年
	 */
	void setSendYear(std::string sendYear){
		this->sendYear = sendYear;
	}
	/**
	 * 是否已读
	 */
	bool getChecked() {
		return this->checked;
	}
	/**
	 * 是否已读
	 */
	void setChecked(bool checked){
		this->checked = checked;
	}
	/**
	 * 邮件过期年
	 */
	std::string getExpireYear() {
		return this->expireYear;
	}
	/**
	 * 邮件过期年
	 */
	void setExpireYear(std::string expireYear){
		this->expireYear = expireYear;
	}

};

#endif
