#ifndef __GETITEM_LAYER_H__
#define __GETITEM_LAYER_H__

#include "cocos2d.h"
#include "ui/CocosGUI.h"

USING_NS_CC;
using namespace cocos2d::ui;

class GetitemLayer : public cocos2d::Layer
{
public:
    
    virtual bool init();
    
    CREATE_FUNC(GetitemLayer);
    
    void setHideLayer(bool hide);

};

#endif 
