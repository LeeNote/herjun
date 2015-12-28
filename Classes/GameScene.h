#ifndef __GAME_SCENE_H__
#define __GAME_SCENE_H__

#include "cocos2d.h"
#include "ui/CocosGUI.h"
#include "BedRoomLayer.h"
#include "MixLayer.h"
#include "StoreLayer.h"
#include "ResultLayer.h"
#include "GetitemLayer.h"

using namespace cocos2d::ui;
USING_NS_CC;

class GameScene : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    
    Size visibleSize;
    int pre_tab_index;
    
    BedRoomLayer* bed_layer;
    MixLayer* mix_layer;
    StoreLayer* store_layer;
    ResultLayer* result_layer;
    GetitemLayer* yakcho_layer;
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    
    void initUI();
    
    void tabCallback(Ref *pSender);

    
    // implement the "static create()" method manually
    CREATE_FUNC(GameScene);
};

#endif // __HELLOWORLD_SCENE_H__
