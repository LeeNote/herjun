#ifndef __BEDROOM_LAYER_H__
#define __BEDROOM_LAYER_H__

#include "cocos2d.h"
#include "ui/CocosGUI.h"
#include <spine/spine-cocos2dx.h>

USING_NS_CC;
using namespace spine;
using namespace cocos2d::ui;

class BedRoomLayer : public cocos2d::Layer
{
public:
    
    virtual bool init();
    
    CREATE_FUNC(BedRoomLayer);
    
    void setHideLayer(bool hide);

};

#endif 
