#include "BedRoomLayer.h"

USING_NS_CC;


bool BedRoomLayer::init()
{

    if ( !Layer::init())
    {
        return false;
    }
    Size visibleSize = Director::getInstance()->getVisibleSize();
    
    auto bedroom_upbar_01 = Sprite::create("background/bedroom_upbar_01.png");
    bedroom_upbar_01->setAnchorPoint(Vec2(1,1));
    bedroom_upbar_01->setPosition(Vec2(visibleSize.width*0.5f, visibleSize.height-545));
    this->addChild(bedroom_upbar_01);
    
    auto bedroom_upbar_02 = Sprite::create("background/bedroom_upbar_02.png");
    bedroom_upbar_02->setAnchorPoint(Vec2(0,1));
    bedroom_upbar_02->setPosition(Vec2(visibleSize.width*0.5f, visibleSize.height-545));
    this->addChild(bedroom_upbar_02);
    
    auto bedroom_tile = Sprite::create("background/bedroom_tile.png");
    
    
    int tileCount = (visibleSize.width / bedroom_tile->getContentSize().width)+1;
    int tileWidth = bedroom_tile->getContentSize().width;
    float tile_start = (bedroom_upbar_01->getPosition().y - bedroom_upbar_01->getContentSize().height);
    for(int i=0; i<3; i++){
        for(int j = 0; j<tileCount; j++){
            auto spr_tile = Sprite::create("background/bedroom_tile.png");
            spr_tile->setAnchorPoint(Vec2(0, 1));
            spr_tile->setPosition(Vec2(j*tileWidth,tile_start - i*540));
            this->addChild(spr_tile);
        }
    }
    
    float width_blank = (( visibleSize.width-780 )* 0.25f) + 130;
    
    
    for(int i=0; i<3; i++){
        auto spr1_1 = Sprite::create("ui/bed_01_under.png");
        spr1_1->setPosition(Vec2(width_blank, 1050 - 340*i));
        auto spr1_2 = Sprite::create("ui/bed_01_up.png");
        spr1_2->setPosition(Vec2(width_blank, 1050 - 340*i));
        this->addChild(spr1_1);
        this->addChild(spr1_2);
        auto spr2_1 = Sprite::create("ui/bed_01_under.png");
        spr2_1->setPosition(Vec2(visibleSize.width*0.5f, 1050 - 340*i));
        auto spr2_2 = Sprite::create("ui/bed_01_up.png");
        spr2_2->setPosition(Vec2(visibleSize.width*0.5f, 1050 - 340*i));
        this->addChild(spr2_1);
        this->addChild(spr2_2);
        auto spr3_1 = Sprite::create("ui/bed_01_under.png");
        spr3_1->setPosition(Vec2(visibleSize.width-width_blank, 1050 - 340*i));
        auto spr3_2 = Sprite::create("ui/bed_01_up.png");
        spr3_2->setPosition(Vec2(visibleSize.width-width_blank, 1050 - 340*i));
        this->addChild(spr3_1);
        this->addChild(spr3_2);
    }
    
    return true;
}


void BedRoomLayer::setHideLayer(bool hide){
    if(hide){
        
    }else{
        
    }
}

//#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
//    exit(0);
//#endif

