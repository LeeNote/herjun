#include "GetitemLayer.h"

USING_NS_CC;


bool GetitemLayer::init()
{

    if ( !Layer::init())
    {
        return false;
    }
    Size visibleSize = Director::getInstance()->getVisibleSize();
    
    auto background = Sprite::create("background/yakcho_back_1.png");
    background->getTexture()->setAliasTexParameters();
    background->setScale(5.0f);
    background->setAnchorPoint(Vec2(0.5,1));
    background->setPosition(Vec2(visibleSize.width*0.5f, visibleSize.height-545));
    this->addChild(background, 0);
    
    auto background_2 = Sprite::create("background/yakcho_back_2.png");
    background_2->getTexture()->setAliasTexParameters();
    background_2->setScale(5.0f);
    background_2->setAnchorPoint(Vec2(0.5,1));
    background_2->setPosition(Vec2(visibleSize.width*0.5f, visibleSize.height-1500));
    this->addChild(background_2, 10);
    
    auto btn_buy = Button::create("ui/yakcho/yakcho_btn.png");
    btn_buy->setPosition(Vec2(visibleSize.width*0.5+300, 308));
    this->addChild(btn_buy, 10);
    
    auto spr_glass_0 = Sprite::create("ui/yakcho/yakcho_glass_0.png");
    spr_glass_0->getTexture()->setAliasTexParameters();
    spr_glass_0->setScale(5.0f);
    spr_glass_0->setPosition(Vec2(visibleSize.width*0.5f+303, 455));
    this->addChild(spr_glass_0,5);
 
    auto spr_glass_1 = Sprite::create("ui/yakcho/yakcho_glass_0.png");
    spr_glass_1->getTexture()->setAliasTexParameters();
    spr_glass_1->setScale(5.0f);
    spr_glass_1->setPosition(Vec2(visibleSize.width*0.5f-253, 510));
    this->addChild(spr_glass_1,4);
    
    auto spr_rock_2 = Sprite::create("ui/yakcho/yakcho_rock_0.png");
    spr_rock_2->getTexture()->setAliasTexParameters();
    spr_rock_2->setScale(5.0f);
    spr_rock_2->setPosition(Vec2(visibleSize.width*0.5f-194, 460));
    this->addChild(spr_rock_2,4);
    
    auto spr_glass_2 = Sprite::create("ui/yakcho/yakcho_glass_0.png");
    spr_glass_2->getTexture()->setAliasTexParameters();
    spr_glass_2->setScale(5.0f);
    spr_glass_2->setPosition(Vec2(visibleSize.width*0.5f+108, 640));
    this->addChild(spr_glass_2,3);
    
    auto spr_glass_3 = Sprite::create("ui/yakcho/yakcho_glass_0.png");
    spr_glass_3->getTexture()->setAliasTexParameters();
    spr_glass_3->setScale(5.0f);
    spr_glass_3->setPosition(Vec2(visibleSize.width*0.5f-173, 725));
    this->addChild(spr_glass_3,2);
    
    auto spr_rock_1 = Sprite::create("ui/yakcho/yakcho_rock_1.png");
    spr_rock_1->getTexture()->setAliasTexParameters();
    spr_rock_1->setScale(5.0f);
    spr_rock_1->setPosition(Vec2(visibleSize.width*0.5f+14, 693));
    this->addChild(spr_rock_1,2);
    
    auto spr_glass_4 = Sprite::create("ui/yakcho/yakcho_glass_0.png");
    spr_glass_4->getTexture()->setAliasTexParameters();
    spr_glass_4->setScale(5.0f);
    spr_glass_4->setPosition(Vec2(visibleSize.width*0.5f+288, 845));
    this->addChild(spr_glass_4,1);
    
    auto spr_rock_3 = Sprite::create("ui/yakcho/yakcho_rock_2.png");
    spr_rock_3->getTexture()->setAliasTexParameters();
    spr_rock_3->setScale(5.0f);
    spr_rock_3->setPosition(Vec2(visibleSize.width*0.5f+411, 758));
    this->addChild(spr_rock_3,1);
    
    
    auto spr_glass_5 = Sprite::create("ui/yakcho/yakcho_glass_0.png");
    spr_glass_5->getTexture()->setAliasTexParameters();
    spr_glass_5->setScale(5.0f);
    spr_glass_5->setPosition(Vec2(visibleSize.width*0.5f-388, 900));
    this->addChild(spr_glass_5,0);
    
    return true;
}


void GetitemLayer::setHideLayer(bool hide){
    if(hide){
        
    }else{
        
    }
}

//#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
//    exit(0);
//#endif

