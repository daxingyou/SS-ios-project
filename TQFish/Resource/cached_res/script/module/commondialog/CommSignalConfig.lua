
--服务器消息信号注册
framework.addSlot2Signal(GAMEID_SERVER_MSG, CommDialogConfig.showServerMsg, true)

--初始化图片
framework.addSlot2Signal(MANAGERID_GET_INIT_PIC, CommDialogConfig.initImageList, true)

--登录消息
framework.addSlot2Signal(BASEID_LOGIN, CommDialogConfig.logicLogin, true)

--注册消息
framework.addSlot2Signal(BASEID_REGISTER, CommDialogConfig.logicRegister, true)
-- 预加载webview信息
framework.addSlot2Signal(COMMONS_HTTPPROXY, CommDialogConfig.preLoadWebViewCommMessage, true)

-- 红包分享V3
--framework.addSlot2Signal(OPERID_SHARING_V3_BASE_INFO, CommShareConfig.saveLocalRedGiftShareBaseInfo)

framework.addSlot2Signal(MANAGERID_GET_SERVER_CONFIG_V2, CommDialogConfig.getMANAGERID_GET_SERVER_CONFIG_V2, true)
--小游戏领取打赏V3
--framework.addSlot2Signal(IMID_CHAT_ROOM_SEND_REWARD_V3, HallLogic.showSystemNotice)

-- 图文Toast
framework.addSlot2Signal(GAMEID_IMAGE_TOAST, CommDialogConfig.showImageToast, true)

--iap订单验证
framework.addSlot2Signal(MANAGERID_VALIDATE_IAP_V2, RechargeCenterLogic.updataIAPPay, true)

--破产红包
framework.addSlot2Signal(MANAGERID_GET_RED_PACKETS_INFO, CommDialogConfig.showRedPackets, true)

--心跳消息
framework.addSlot2Signal(MSG_IDLE, CommDialogConfig.msgIdle, true)

--微信分享消息(创建二维码等)
framework.addSlot2Signal(MJ_SC_SHARE_INFO, CommDialogConfig.slot_MJ_SC_SHARE_INFO, true)

--获取牌局录像信息
framework.addSlot2Signal(MJ_SC_MGR_GET_ROOM_RECORD, CommDialogConfig.slot_MJ_SC_MGR_GET_ROOM_RECORD, true)