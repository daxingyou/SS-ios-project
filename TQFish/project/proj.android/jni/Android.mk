LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := cocos2dlua_shared

LOCAL_MODULE_FILENAME := libcocos2dlua

LOCAL_SRC_FILES := ../../../AppConfig/AppDelegate.cpp \
				../../../Classes/Box2dInterface/FishBox2d/FishBox2dSupport.cpp \
				../../../Classes/Box2dInterface/FishBox2d/QContactListener.cpp \
				../../../Classes/Box2dInterface/FishBox2d/TransparentId.cpp \
				../../../Classes/Box2dInterface/FishBox2d/Lightning.cpp \
				../../../Classes/QRcodeInterface/QRSprite.cpp \
				../../../Classes/QRcodeInterface/libqrencode/bitstream.c \
				../../../Classes/QRcodeInterface/libqrencode/mask.c \
				../../../Classes/QRcodeInterface/libqrencode/qrencode.c \
				../../../Classes/QRcodeInterface/libqrencode/qrinput.c \
				../../../Classes/QRcodeInterface/libqrencode/qrspec.c \
				../../../Classes/QRcodeInterface/libqrencode/rscode.c \
				../../../Classes/QRcodeInterface/libqrencode/split.c \
				../../../Classes/event/Event.cpp \
				../../../Classes/event/EventDispather.cpp \
				../../../Classes/event/EventInvocation.cpp \
				../../../Classes/event/notification/NotificationCenter.cpp \
				../../../Classes/event/notification/NotificationEvent.cpp \
				../../../Classes/event/LordAi.cpp \
				../../../Classes/event/Services.cpp \
				../../../Classes/LordClientAi/LocalService.cpp \
				../../../Classes/LordClientAi/LordRobotAi.cpp \
				../../../Classes/lua/cocos2dx_support/CCLuaBridge.cpp \
				../../../Classes/lua/cocos2dx_support/CCLuaEngine.cpp \
				../../../Classes/lua/cocos2dx_support/CCLuaStack.cpp \
				../../../Classes/lua/cocos2dx_support/CCLuaValue.cpp \
				../../../Classes/lua/cocos2dx_support/Cocos2dxLuaLoader.cpp \
				../../../Classes/lua/cocos2dx_support/FishBox2dSupportLoad.cpp \
				../../../Classes/lua/cocos2dx_support/LuaCocos2d.cpp \
				../../../Classes/lua/cocos2dx_support/lua_cocos2dx_extensions_manual.cpp \
				../../../Classes/lua/cocos2dx_support/tolua_fix.c \
				../../../Classes/lua/cocos2dx_support/xxtea.c \
				../../../Classes/lua/cocos2dx_support/TransparentIdLoad.cpp \
				../../../Classes/lua/cocos2dx_support/platform/android/CCLuaJavaBridge.cpp \
    			../../../Classes/lua/cocos2dx_support/platform/android/org_cocos2dx_lib_Cocos2dxLuaJavaBridge.cpp \
				../../../Classes/lua/cocos2dx_support/platform/android/bugly/CrashReport.cpp \
				../../../Classes/lua/cocos2dx_support/PublicLuaBridge.cpp \
				../../../Classes/lua/cocos2dx_support/PublicLuaBridgeLoad.cpp \
				../../../Classes/lua/cocos2dx_support/SkeletonAnimationLoad.cpp\
				../../../Classes/lua/lua_extensions.c \
				../../../Classes/lua/cjson/fpconv.c \
				../../../Classes/lua/cjson/lua_cjson.c \
				../../../Classes/lua/cjson/strbuf.c \
				../../../Classes/lua/filesystem/lfs.c \
				../../../Classes/lua/socket/auxiliar.c \
				../../../Classes/lua/socket/buffer.c \
				../../../Classes/lua/socket/compat.c \
				../../../Classes/lua/socket/except.c \
				../../../Classes/lua/socket/inet.c \
				../../../Classes/lua/socket/io.c \
				../../../Classes/lua/socket/luasocket.c \
				../../../Classes/lua/socket/mime.c \
				../../../Classes/lua/socket/options.c \
				../../../Classes/lua/socket/select.c \
				../../../Classes/lua/socket/tcp.c \
				../../../Classes/lua/socket/timeout.c \
				../../../Classes/lua/socket/udp.c \
				../../../Classes/lua/socket/unix.c \
				../../../Classes/lua/socket/unixtcp.c \
				../../../Classes/lua/socket/unixudp.c \
				../../../Classes/lua/socket/usocket.c \
				../../../Classes/lua/loader/BaseMessageLoad.cpp \
				../../../Classes/lua/loader/LightningLoad.cpp \
				../../../Classes/lua/loader/LocalServiceLoad.cpp \
				../../../Classes/lua/loader/LordAiLoad.cpp \
				../../../Classes/lua/loader/LuaBox2D.cpp \
				../../../Classes/lua/loader/MessageServiceLoad.cpp \
				../../../Classes/lua/loader/NMBaseMessageLoad.cpp \
				../../../Classes/lua/loader/NotificationCenterLoad.cpp \
				../../../Classes/lua/loader/NotificationEventLoad.cpp \
				../../../Classes/lua/loader/QRSpriteLoad.cpp \
				../../../Classes/lua/loader/ServicesLoad.cpp \
				../../../Classes/lua/loader/SevTCliNotificationLoad.cpp \
				../../../Classes/network/message/BaseMessage.cpp \
				../../../Classes/network/message/bytebuffer/ByteBuffer.cpp \
				../../../Classes/network/message/MessageRegister.cpp \
				../../../Classes/network/message/MessageService.cpp \
				../../../Classes/network/message/NMBaseMessage.cpp \
				../../../Classes/network/message/odsocket/ODSocket.cpp \
				../../../Classes/network/message/odsocket/stdafx.cpp \
				../../../Classes/network/message/reflect/ClassFactory.cpp \
				../../../Classes/network/message/reflect/MessageRecognize.cpp \
				../../../Classes/network/message/SevTCliNotification.cpp \
				hellolua/main.cpp 


LOCAL_C_INCLUDES :=  $(LOCAL_PATH)/../../../AppConfig \
					 $(LOCAL_PATH)/../../../Classes \
					 $(LOCAL_PATH)/../../../Classes/Box2dInterface \
					 $(LOCAL_PATH)/../../../Classes/Box2dInterface/FishBox2d \
					 $(LOCAL_PATH)/../../../Classes/QRcodeInterface \
					 $(LOCAL_PATH)/../../../Classes/QRcodeInterface/libqrencode \
					 $(LOCAL_PATH)/../../../Classes/event \
					 $(LOCAL_PATH)/../../../Classes/event/notification \
					 $(LOCAL_PATH)/../../../Classes/LordClientAi \
					 $(LOCAL_PATH)/../../../Classes/lua \
					 $(LOCAL_PATH)/../../../Classes/lua/cocos2dx_support \
					 $(LOCAL_PATH)/../../../Classes/lua/cocos2dx_support/platform/android \
					 $(LOCAL_PATH)/../../../Classes/lua/cocos2dx_support/platform/android/bugly \
					 $(LOCAL_PATH)/../../../Classes/lua/cjson \
					 $(LOCAL_PATH)/../../../Classes/lua/filesystem \
					 $(LOCAL_PATH)/../../../Classes/lua/loader \
					 $(LOCAL_PATH)/../../../Classes/lua/socket \
					 $(LOCAL_PATH)/../../../Classes/network/message \
					 $(LOCAL_PATH)/../../../Classes/network/message/beans \
					 $(LOCAL_PATH)/../../../Classes/network/message/bytebuffer \
					 $(LOCAL_PATH)/../../../Classes/network/message/odsocket \
					 $(LOCAL_PATH)/../../../Classes/network/message/reflect

LOCAL_STATIC_LIBRARIES := curl_static_prebuilt

LOCAL_CPPFLAGS += -std=c++11

LOCAL_WHOLE_STATIC_LIBRARIES := cocos2dx_static
LOCAL_WHOLE_STATIC_LIBRARIES += cocosdenshion_static
LOCAL_WHOLE_STATIC_LIBRARIES += cocos_lua_static
LOCAL_WHOLE_STATIC_LIBRARIES += box2d_static
LOCAL_WHOLE_STATIC_LIBRARIES += chipmunk_static
LOCAL_WHOLE_STATIC_LIBRARIES += cocos_extension_static

include $(BUILD_SHARED_LIBRARY)

$(call import-add-path, E:/javawork/TqAndroidGit/TqCocos2d-x-Lord/libs)
$(call import-add-path, E:/javawork/TqAndroidGit/TqCocos2d-x-Lord/libs/cocos2dx/platform/third_party/android/prebuilt)

$(call import-module,cocos2dx)
$(call import-module,CocosDenshion/android)
$(call import-module,lua/proj.android)
$(call import-module,cocos2dx/platform/third_party/android/prebuilt/libcurl)
$(call import-module,extensions)
$(call import-module,external/Box2D)
$(call import-module,external/chipmunk)