#ifndef __STORE_LAYER_H__
#define __STORE_LAYER_H__

#include "cocos2d.h"
#include "ui/CocosGUI.h"

USING_NS_CC;
using namespace cocos2d::ui;

class StoreLayer : public cocos2d::Layer
{
public:
    
    virtual bool init();
    
    int s_pre_tab_index;
    
    CREATE_FUNC(StoreLayer);
    
    ListView* m_listview;
    
    void setHideLayer(bool hide);

    void tabCallback(Ref *pSender);
    
    void selectedItemEvent(cocos2d::Ref* sender, cocos2d::ui::ListView::EventType type);
    
    void setTab1();
    void setTab2();
    void setTab3();
    void setTab4();
    
};

#endif 
