#include "ResultLayer.h"

USING_NS_CC;


bool ResultLayer::init()
{

    if ( !Layer::init())
    {
        return false;
    }
    visibleSize = Director::getInstance()->getVisibleSize();
    
    auto mix_background = Sprite::create("ui/paper/paper_back.png");
    mix_background->getTexture()->setAliasTexParameters();
    mix_background->setScale(5.0f);
    mix_background->setAnchorPoint(Vec2(0.5,1));
    mix_background->setPosition(Vec2(visibleSize.width*0.5f, visibleSize.height-530));
    this->addChild(mix_background, 0);
    
    m_listview = ListView::create();
    // set list view ex direction
    m_listview->setDirection(ui::ScrollView::Direction::VERTICAL);
    m_listview->setBounceEnabled(true);
    m_listview->setContentSize(Size(755, 900));
    m_listview->setAnchorPoint(Vec2(0.5, 0.5f));
    m_listview->setPosition(Vec2(visibleSize.width*0.5f-30, 650));
    m_listview->addEventListener((ui::ListView::ccListViewCallback)CC_CALLBACK_2(ResultLayer::selectedItemEvent, this));
    
    m_listview->setScrollBarPositionFromCorner(Vec2(7, 7));
    
    this->addChild(m_listview);
    
    settingListview();
    
    return true;
}

void ResultLayer::settingListview(){
    m_listview->removeAllItems();
    m_arr.clear();
    
    auto spr1 = Character::create();
    spr1->setTexture("ui/paper/character_test.png");
    spr1->getTexture()->setAliasTexParameters();
    spr1->setScale(5.0f);
    spr1->setTextureRect(Rect(0, 0, 28, 28));
    spr1->setItem("김도팔","농민","열사병","어지러움, 구토증상","백호탕");
    m_arr.pushBack(spr1);
    
    auto spr2 = Character::create();
    spr2->setTexture("ui/paper/character_test.png");
    spr2->getTexture()->setAliasTexParameters();
    spr2->setScale(5.0f);
    spr2->setTextureRect(Rect(0, 0, 28, 28));
    spr2->setItem("박민성","귀족","상사병","어지러움, 기운없음","큐피트의탕");
    m_arr.pushBack(spr2);
    
    auto spr3 = Character::create();
    spr3->setTexture("ui/paper/character_test.png");
    spr3->getTexture()->setAliasTexParameters();
    spr3->setScale(5.0f);
    spr3->setTextureRect(Rect(0, 0, 28, 28));
    spr3->setItem("김세찬","농민","감기","어지러움, 열남, 몸살","백호탕");
    m_arr.pushBack(spr3);
    
    auto spr4 = Character::create();
    spr4->setTexture("ui/paper/character_test.png");
    spr4->getTexture()->setAliasTexParameters();
    spr4->setScale(5.0f);
    spr4->setTextureRect(Rect(0, 0, 28, 28));
    spr4->setItem("박기성","농민","독감","어지러움, 열남, 몸살","백호탕");
    m_arr.pushBack(spr4);
    
    
    for(Character* _item : m_arr){
        Layout *custom_item = Layout::create();
        custom_item->setContentSize(Size(755,285));
        
        auto box = Sprite::create("ui/paper/paper_box.png");
        box->getTexture()->setAliasTexParameters();
        box->setScale(5.0f);
        box->setAnchorPoint(Vec2(0,0.5));
        box->setPosition(Vec2(30, 142));
        
        _item->setAnchorPoint(  Vec2(0, 0.5) );
        _item->setPosition(50,142);
        

        
        auto line = Sprite::create("ui/paper/paper_line.png");
        line->getTexture()->setAliasTexParameters();
        line->setScale(5.0f);
        line->setAnchorPoint(Vec2(0,0));
        line->setPosition(Vec2(0, 0));
        
        
        auto test_0 = Label::createWithSystemFont("", "", 30.0f);
        test_0->setString(StringUtils::format("이름  %s", _item->name));
        test_0->setAnchorPoint(Vec2(0,0.5));
        test_0->setTextColor(Color4B(147, 148, 127, 255));
        test_0->setPosition(Vec2(223,242));
        
        auto test_1 = Label::createWithSystemFont("", "", 30.0f);
        test_1->setString(StringUtils::format("직업  %s", _item->hobby));
        test_1->setAnchorPoint(Vec2(0,0.5));
        test_1->setTextColor(Color4B(147, 148, 127, 255));
        test_1->setPosition(Vec2(223,197));
        
        auto test_2 = Label::createWithSystemFont("", "", 30.0f);
        test_2->setString(StringUtils::format("상태  %s", _item->sick_name));
        test_2->setAnchorPoint(Vec2(0,0.5));
        test_2->setTextColor(Color4B(147, 148, 127, 255));
        test_2->setPosition(Vec2(223,152));
        
        auto test_3 = Label::createWithSystemFont("", "", 30.0f);
        test_3->setString(StringUtils::format("증상  %s", _item->sick_state));
        test_3->setAnchorPoint(Vec2(0,0.5));
        test_3->setTextColor(Color4B(147, 148, 127, 255));
        test_3->setPosition(Vec2(223,106));
        
        auto test_4 = Label::createWithSystemFont("", "", 30.0f);
        test_4->setString(StringUtils::format("처방  %s", _item->medician));
        test_4->setAnchorPoint(Vec2(0,0.5));
        test_4->setTextColor(Color4B(147, 148, 127, 255));
        test_4->setPosition(Vec2(223,62));
        
        custom_item->addChild(box);
        
        custom_item->addChild(line);
        custom_item->addChild(test_0);
        custom_item->addChild(test_1);
        custom_item->addChild(test_2);
        custom_item->addChild(test_3);
        custom_item->addChild(test_4);
        custom_item->addChild(_item);
        m_listview->pushBackCustomItem(custom_item);
    }
    
}

void ResultLayer::setHideLayer(bool hide){
    if(hide){
        
    }else{
        
    }
}

void ResultLayer::selectedItemEvent(Ref *pSender, ListView::EventType type)
{
    switch (type)
    {
        case cocos2d::ui::ListView::EventType::ON_SELECTED_ITEM_START:
        {
            ListView* listView = static_cast<ListView*>(pSender);
            CC_UNUSED_PARAM(listView);
            CCLOG("select child start index = %ld", listView->getCurSelectedIndex());
            break;
        }
        case cocos2d::ui::ListView::EventType::ON_SELECTED_ITEM_END:
        {
            ListView* listView = static_cast<ListView*>(pSender);
            CC_UNUSED_PARAM(listView);
            CCLOG("select child end index = %ld", listView->getCurSelectedIndex());
            
            break;
        }
        default:
            break;
    }
}

//#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
//    exit(0);
//#endif

