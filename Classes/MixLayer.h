#ifndef __MIX_LAYER_H__
#define __MIX_LAYER_H__

#include "cocos2d.h"
#include "ui/CocosGUI.h"

USING_NS_CC;
using namespace cocos2d::ui;

class itemBtn : public cocos2d::ui::Button
{
public:
    
    int item_x;
    int item_y;
    bool make;
    CREATE_FUNC(itemBtn);
    
    
};

class MixLayer : public cocos2d::Layer
{
public:
    
    virtual bool init();
    
    CREATE_FUNC(MixLayer);
    
    Vec2 savePoint;
    ScrollView* scrollView;
    void setHideLayer(bool hide);
    
    void touchEvent(Ref *pSender, Widget::TouchEventType type);
    
//    bool onTouchBegan(Touch *touch, Event *unused_event);
//    void onTouchMoved(Touch *touch, Event *unused_event);
//    void onTouchEnded(Touch *touch, Event *unused_event);
//    void onTouchCancelled(Touch *touch, Event *unused_event);
};

#endif 
