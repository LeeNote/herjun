#include "GameScene.h"
#include "dbrw.h"
#include "firstinput.h"

Scene* GameScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = GameScene::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool GameScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    pre_tab_index = 0;
    
    initUI();
    
    return true;
}

void GameScene::initUI(){
    auto back_1 = Sprite::create("background/back_1.png");
    back_1->setAnchorPoint(Vec2(1,1));
    back_1->setPosition(Vec2(visibleSize.width*0.5f, visibleSize.height));
    this->addChild(back_1);
    
    auto back_2 = Sprite::create("background/back_2.png");
    back_2->setAnchorPoint(Vec2(0,1));
    back_2->setPosition(Vec2(visibleSize.width*0.5f, visibleSize.height));
    this->addChild(back_2);
    
    bed_layer = BedRoomLayer::create();
    bed_layer->setName("BED_LAYER");
    this->addChild(bed_layer);
    
    mix_layer = MixLayer::create();
    mix_layer->setName("MIX_LAYER");
    this->addChild(mix_layer);
    mix_layer->setVisible(false);
    
    store_layer = StoreLayer::create();
    store_layer->setName("STORE_LAYER");
    this->addChild(store_layer);
    store_layer->setVisible(false);
    
    result_layer = ResultLayer::create();
    result_layer->setName("RESULT_LAYER");
    this->addChild(result_layer, 11);
    result_layer->setVisible(false);
    
    yakcho_layer = GetitemLayer::create();
    yakcho_layer->setName("YAKCHO_LAYER");
    this->addChild(yakcho_layer);
    yakcho_layer->setVisible(false);
    
    auto tab_spr_0 = MenuItemImage::create("ui/tab_icon.png", "ui/tab_t_icon.png", "ui/tab_t_icon.png", CC_CALLBACK_1(GameScene::tabCallback, this));
    tab_spr_0->setAnchorPoint(Vec2(0.5,0));
    tab_spr_0->setTag(4);
    tab_spr_0->setPosition(Vec2(visibleSize.width - 95, visibleSize.height-545));
    
    auto tab_spr_1 = MenuItemImage::create("ui/tab_icon.png", "ui/tab_t_icon.png", "ui/tab_t_icon.png", CC_CALLBACK_1(GameScene::tabCallback, this));
    tab_spr_1->setAnchorPoint(Vec2(0.5,0));
    tab_spr_1->setTag(3);
    tab_spr_1->setPosition(Vec2(visibleSize.width - 279 , visibleSize.height-545));
    
    auto tab_spr_2 = MenuItemImage::create("ui/tab_icon.png", "ui/tab_t_icon.png", "ui/tab_t_icon.png", CC_CALLBACK_1(GameScene::tabCallback, this));
    tab_spr_2->setAnchorPoint(Vec2(0.5,0));
    tab_spr_2->setTag(2);
    tab_spr_2->setPosition(Vec2(visibleSize.width - 464, visibleSize.height-545));
    
    auto tab_spr_3 = MenuItemImage::create("ui/tab_icon.png", "ui/tab_t_icon.png", "ui/tab_t_icon.png", CC_CALLBACK_1(GameScene::tabCallback, this));
    tab_spr_3->setAnchorPoint(Vec2(0.5,0));
    tab_spr_3->setTag(1);
    tab_spr_3->setPosition(Vec2(visibleSize.width - 649, visibleSize.height-545));
    
    auto tab_spr_4 = MenuItemImage::create("ui/tab_icon.png", "ui/tab_t_icon.png", "ui/tab_t_icon.png", CC_CALLBACK_1(GameScene::tabCallback, this));
    tab_spr_4->setAnchorPoint(Vec2(0.5,0));
    tab_spr_4->setTag(0);
    tab_spr_4->setPosition(Vec2(visibleSize.width - 834,visibleSize.height-545));
    
    auto menu = Menu::create(tab_spr_0, tab_spr_1, tab_spr_2, tab_spr_3, tab_spr_4, nullptr);
    menu->setAnchorPoint(Vec2(0,0));
    menu->setPosition(Vec2(0,0));
    this->addChild(menu , 10);
    
    firstinput _first;
    _first.makeDB();
    
    dbrw _db;
    int j = _db.selectData();
    
    CCLOG("TEST dbrw : %d", j);
    
    tab_spr_4->setEnabled(false);
}



/*
        Button Click Touch Event
 */
void GameScene::tabCallback(Ref *pSender){
    auto spr = static_cast<MenuItemImage*>(pSender);
    auto pre_menu =  dynamic_cast<MenuItemImage*>(spr->getParent()->getChildByTag(pre_tab_index));
    pre_menu->setEnabled(true);
    spr->setEnabled(false);
    switch(spr->getTag()){
        case 0:
            CCLOG("병실이 나옴");
            bed_layer->setHideLayer(true);
            bed_layer->setVisible(true);
            break;
        case 1:
            CCLOG("제조실이 나옴");
            mix_layer->setHideLayer(true);
            mix_layer->setVisible(true);
            break;
        case 2:
            CCLOG("약초상이 나옴");
            store_layer->setHideLayer(true);
            store_layer->setVisible(true);
            break;
        case 3:
            CCLOG("약초수집이 나옴");
            result_layer->setHideLayer(true);
            result_layer->setVisible(true);
            break;
        case 4:
            CCLOG("처방기록서 나옴");
            yakcho_layer->setHideLayer(true);
            yakcho_layer->setVisible(true);
            break;
    }
    switch(pre_tab_index){
        case 0:
            bed_layer->setHideLayer(false);
            bed_layer->setVisible(false);
            break;
        case 1:
            mix_layer->setHideLayer(false);
            mix_layer->setVisible(false);
            break;
        case 2:
            store_layer->setHideLayer(false);
            store_layer->setVisible(false);
            break;
        case 3:
            result_layer->setHideLayer(false);
            result_layer->setVisible(false);
            break;
        case 4:
            yakcho_layer->setHideLayer(false);
            yakcho_layer->setVisible(false);
            break;
    }
    pre_tab_index = spr->getTag();
}

//void IntroScene::menuCloseCallback(Ref* pSender)
//{
//    Director::getInstance()->end();
//
//#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
//    exit(0);
//#endif
//}
