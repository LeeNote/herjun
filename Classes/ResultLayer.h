#ifndef __RESULT_LAYER_H__
#define __RESULT_LAYER_H__

#include "cocos2d.h"
#include "ui/CocosGUI.h"

USING_NS_CC;
using namespace cocos2d::ui;

class Character : public Sprite
{
public:
    char* name;
    char* hobby;
    char* sick_name;
    char* sick_state;
    char* medician;
    
    CREATE_FUNC(Character);
    
    void setItem(char* _name, char* _hobby, char* _sickname, char* _sickstate, char* _medician){
        name = _name;
        hobby = _hobby;
        sick_name = _sickname;
        sick_state = _sickstate;
        medician = _medician;
    }
    
};


class ResultLayer : public cocos2d::Layer
{
public:
    
    virtual bool init();
    
    CREATE_FUNC(ResultLayer);
    
    Vector<Character*> m_arr;
    
    Size visibleSize;
    
    ListView* m_listview;
    
    void setHideLayer(bool hide);
    
    void settingListview();
    
    void selectedItemEvent(cocos2d::Ref* sender, cocos2d::ui::ListView::EventType type);
    
};

#endif 
