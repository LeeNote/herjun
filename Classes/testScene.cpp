#include "testScene.h"
#include "GameScene.h"



Scene* testScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = testScene::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool testScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    auto spr = Sprite::create("background/testsample.png");
    spr->getTexture()->setAliasTexParameters();
    spr->setScale(5.0f);
    spr->setPosition(Vec2(visibleSize.width*0.5f, visibleSize.height*0.5f));
    this->addChild(spr);
    
    auto test_spr = Sprite::create("character/herb_01.png");
    test_spr->getTexture()->setAliasTexParameters();
    test_spr->setScale(4.0f);
    test_spr->setPosition(Vec2(visibleSize.width*0.5f, visibleSize.height*0.5f));
    //this->addChild(test_spr);
    
    
    return true;
}




//void IntroScene::menuCloseCallback(Ref* pSender)
//{
//    Director::getInstance()->end();
//
//#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
//    exit(0);
//#endif
//}
