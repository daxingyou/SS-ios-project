

#ifndef Lstx_cocos2dX_Event_h
#define Lstx_cocos2dX_Event_h

#include "cocos2d.h"
USING_NS_CC;


class Event : public CCObject 
{        
   
public:
    Event();
    ~Event();   
    
public:
    static Event* create();
    static Event* create(int type);
    static Event* create(int type, CCObject* data,std::string dataName);
    
    virtual bool init();
    virtual bool init(int type);
    virtual bool init(int type, CCObject* data,std::string dataName);
    
public:               
		static const int NONE                                = 0	;
		static const int ONENTER                             = 1	;
		static const int ONEXIT                              = 2	;

		static const int ACCELERATION_EVENT                  = 6	;

		static const int TOUCH_DOWN                          = 11	;
		static const int TOUCH_MOVE                          = 12	;
		static const int TOUCH_END                           = 13	;
		static const int TOUCH_DRAG_INSIDE                   = 14	;
		static const int TOUCH_DRAG_OUTSIDE                  = 15	;
		static const int TOUCH_DRAG_ENTER                    = 16	;
		static const int TOUCH_DRAG_EXIT                     = 17	;
		static const int TOUCH_TOUCH_UP_INSIDE               = 18	;
		static const int TOUCH_TOUCH_UP_OUTSIDE              = 19	;
		static const int TOUCH_TOUCH_CANCEL                  = 20	;
		static const int TOUCH_VALUE_CHANGED                 = 21	;
																 	
		static const int RESOURCE_NOT_FOUND					 = 51	;
		static const int RESOURCE_LOAD_SUCCESS             	 = 52	;
		static const int RESOURCE_LOAD_FAIL				     = 53	;
		static const int RESOURCE_LOAD_RETRY			   	 = 54	;
		static const int RESOURCE_LOAD_FINISH			   	 = 55	;
		static const int RESOURCE_CHECK_FINISH			     = 56	;
		static const int RESOURCE_SERVER_NOT_REACH			 = 57	;
		static const int RESOURCE_LOAD_UPDATE				 = 58	;
		static const int LOADING_PROCESS                     = 59	;
																 	
		static const int BUTTON_CLICK                        = 201	;
		static const int COMPONENT_TEXY_CHANGED              = 202	;
		static const int COMPONENT_SELETED                   = 203	;
		static const int COMPONENT_SCRALLBAR_CHANGE_VALUE    = 204	;
		static const int COMPONENT_RADIOBOX_SELECTED         = 205	;
		static const int COMPONENT_TABBAR_SELECTED           = 206	;
		static const int CONTAINER_INSERT_CONTENT            = 207	;
		static const int CONTAINER_REMOVE_CONTENT            = 208	;
		static const int CONTAINER_REMOVE_ALL_CONTENT        = 209	;
		static const int CONTAINER_MOVE                      = 210	;
		static const int TABBAR_CHANGE                       = 211	;
		static const int CONTAINER_CHILD_SELECTD             = 212	;
		static const int CONTAINER_DISPLAY_CHANGED           = 213	;
		static const int PUSHACTORSTATE                      = 214	;
		static const int HTTPRESPONSE                        = 215	;
		static const int ACTIONFINISH                        = 216	;
		static const int COMPONENT_CHECKBOX_SELECTED         = 217	;
		static const int COUNTDOWN_OVER                      = 218	;
		static const int CLEAN_UP_SENCE                      = 219	;
        static const int CONTAINER_SCROLL_TOUCH_END          = 230	;
        static const int CONTAINER_SCROLL_MOVE_END           = 231	;
        static const int COMPONENT_TOUCH                      = 232	;
        static const int CONTAINER_CHILD_TOUCH                = 233	;
        static const int CONTAINER_MOVE_IGNORE_BIAS          = 234 ;
    
		static const int INPUT_GET_POINT                     = 301	;
        static const int INPUT_LOSE_POINT                    = 306;
		static const int CONTAINER_DISPLAY_END               = 302	;

		static const int TABNAVGATOR_GET_POINT                = 304 ;
		static const int CONTAINER_TO_END                     = 305 ;
    
    	static const int TOUCH_OUTSIDE                       = 310  ;
    	static const int LOGIN_SUCCESS_91                    = 400;
        static const int PLATFORM_LOGOUT                    = 401;   
        static const int RETURN_GAME                         = 402;
        static const int HTTP_ERROR                          = 403;
    
 public:
    CC_SYNTHESIZE(int, m_type, EventType);
    CC_SYNTHESIZE(CCObject*, m_data, EventData); 
    CC_SYNTHESIZE(std::string, m_name, EventName);
    
    
};

#endif
