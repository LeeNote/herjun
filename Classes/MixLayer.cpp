#include "MixLayer.h"

USING_NS_CC;


bool MixLayer::init()
{

    if ( !Layer::init())
    {
        return false;
    }
    Size visibleSize = Director::getInstance()->getVisibleSize();
    
    auto mix_background = Sprite::create("background/mix_back.png");
    mix_background->setAnchorPoint(Vec2(0.5,1));
    mix_background->setPosition(Vec2(visibleSize.width*0.5f, visibleSize.height-545));
    this->addChild(mix_background, 0);
    
    auto mix_machine = Sprite::create("ui/mix_machine_01.png");
    mix_machine->setPosition(Vec2(visibleSize.width*0.5f, 450));
    this->addChild(mix_machine, 2);
    
    auto mix_machine_out = Sprite::create("ui/mix_machine_02.png");
    mix_machine_out->setPosition(Vec2(visibleSize.width*0.5f, 450));
    this->addChild(mix_machine_out, 1);
    
    
    auto mix_sidebar = Sprite::create("ui/mix_sidebar.png");
    mix_sidebar->setAnchorPoint(Vec2(0.5,1));
    mix_sidebar->setPosition(Vec2(visibleSize.width*0.5f, visibleSize.height-545));
    this->addChild(mix_sidebar, 4);
    
    scrollView = ui::ScrollView::create();
    scrollView->setBounceEnabled(true);
    scrollView->setDirection(ui::ScrollView::Direction::HORIZONTAL);
    scrollView->setContentSize(Size(950.0f, 400.0f));
    scrollView->setPosition(Vec2(60,1250));
    scrollView->setAnchorPoint(Vec2(0,1));
    scrollView->setInnerContainerSize(Size(50*170,400.0f));
    scrollView->setScrollBarPositionFromCorner(Vec2(4, 4));
    scrollView->setScrollBarColor(Color3B::YELLOW);
    
//    auto listener = EventListenerTouchOneByOne::create();
//    listener->onTouchBegan = CC_CALLBACK_2(MixLayer::onTouchBegan, this);
//    listener->onTouchMoved = CC_CALLBACK_2(MixLayer::onTouchMoved, this);
//    listener->onTouchEnded = CC_CALLBACK_2(MixLayer::onTouchEnded, this);
//    listener->onTouchCancelled = CC_CALLBACK_2(MixLayer::onTouchCancelled, this);
//    Director::getInstance()->getEventDispatcher()->addEventListenerWithFixedPriority(listener, 1);
    
    for(int i=0; i<100; i++){
        int j = i%2;
        auto btn = itemBtn::create();
        btn->init("character/herb_01.png");
        btn->setAnchorPoint(Vec2(0,0));
        btn->item_x = i;
        btn->item_y = j;
        btn->make = false;
        btn->setPosition(Vec2(i/2*170, 30+j*160));
        btn->addTouchEventListener(CC_CALLBACK_2(MixLayer::touchEvent, this));
        scrollView->addChild(btn);
        
    }

    auto drawnode = DrawNode::create();

    drawnode->drawSolidRect(Vec2(0, 850), Vec2(visibleSize.width, 1250), Color4F(0,0,0,0.5f));
    this->addChild(drawnode);
    
    this->addChild(scrollView);
    
    return true;
}


void MixLayer::setHideLayer(bool hide){
    if(hide){
        
    }else{
        
    }
}

void MixLayer::touchEvent(Ref *pSender, Widget::TouchEventType type)
{
    switch (type)
    {
        case Widget::TouchEventType::BEGAN:{
            CCLOG("touch down!");
            auto btn = ((itemBtn*)pSender);
            savePoint = btn->getTouchBeganPosition();
            btn->setOpacity(180);
            CCLOG("p x : %f , p y : %f",savePoint.x, savePoint.y);
        }
            break;
        case Widget::TouchEventType::MOVED:{
            CCLOG("touch Moved!");
            auto btn = ((itemBtn*)pSender);
            Vec2 p2 = btn->getTouchMovePosition();
            if(savePoint.y  - p2.y >= 50 && btn->make == false){
                CCLOG("Scroll Stop!!");
                btn->make = true;
                scrollView->setTouchEnabled(false);
                auto make_btn = itemBtn::create();
                make_btn->init("character/herb_01.png");
                make_btn->setAnchorPoint(Vec2(0,0));
                make_btn->item_x = btn->item_x;
                make_btn->item_y = btn->item_y;
                make_btn->make = false;
                make_btn->setPosition(Vec2(btn->item_x/2*170, 30+btn->item_y*160));
                make_btn->addTouchEventListener(CC_CALLBACK_2(MixLayer::touchEvent, this));
                btn->retain();
                btn->removeFromParentAndCleanup(false);
                this->addChild(btn, 1);
                btn->setAnchorPoint(Vec2(0.5,0.5));
                btn->release();
                scrollView->addChild(make_btn);
                
            }else if(btn->make == true){
                btn->setPosition(btn->getTouchMovePosition());
            }
            CCLOG("p2 x : %f , p2 y : %f",p2.x, p2.y);
        }
            break;
        
        case Widget::TouchEventType::ENDED:{
    
            CCLOG("touch ENDED!");
            auto btn = ((itemBtn*)pSender);
            btn->setOpacity(255);
            scrollView->setTouchEnabled(true);
            
        }
            break;
            
        case Widget::TouchEventType::CANCELED:{
            CCLOG("touch CANCELD!");
            auto btn = ((itemBtn*)pSender);
            btn->setOpacity(255);
            scrollView->setTouchEnabled(true);
        }
            break;
        default:
            break;
    }
}

//bool MixLayer::onTouchBegan(Touch *touch, Event *unused_event){
//    CCLOG("Main Touch down!");
//
//    return true;
//}
//void MixLayer::onTouchMoved(Touch *touch, Event *unused_event){
//    CCLOG("Main Touch  Moved!");
//    
//}
//void MixLayer::onTouchEnded(Touch *touch, Event *unused_event){
//    CCLOG("Main Touch  Ended!");
//}
//void MixLayer::onTouchCancelled(Touch *touch, Event *unused_event){
//    
//}

//#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
//    exit(0);
//#endif

