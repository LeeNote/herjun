#include "IntroScene.h"
#include "GameScene.h"
#include "testScene.h"


Scene* IntroScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = IntroScene::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool IntroScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    loadCount = 0;
    inputCache();
    return true;
}


void IntroScene::inputCache(){
    Director::getInstance()->getTextureCache()->addImageAsync("background/back_1.png", CC_CALLBACK_1(IntroScene::loadingCallBack, this));
    Director::getInstance()->getTextureCache()->addImageAsync("background/back_2.png", CC_CALLBACK_1(IntroScene::loadingCallBack, this));
    Director::getInstance()->getTextureCache()->addImageAsync("background/mix_back.png", CC_CALLBACK_1(IntroScene::loadingCallBack, this));
    Director::getInstance()->getTextureCache()->addImageAsync("background/store_back.png", CC_CALLBACK_1(IntroScene::loadingCallBack, this));
    Director::getInstance()->getTextureCache()->addImageAsync("ui/mix_sidebar.png", CC_CALLBACK_1(IntroScene::loadingCallBack, this));
}

void IntroScene::loadingCallBack(cocos2d::Texture2D *texture){
    CCLOG("CallBack!! %d",loadCount);
    loadCount++;
    if(loadCount==5){
        
        Director::getInstance()->replaceScene(TransitionTurnOffTiles::create(1.0f, GameScene::createScene()));
    }
}

//void IntroScene::menuCloseCallback(Ref* pSender)
//{
//    Director::getInstance()->end();
//
//#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
//    exit(0);
//#endif
//}
