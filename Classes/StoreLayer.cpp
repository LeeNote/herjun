#include "StoreLayer.h"
#include "dbrw.h"

USING_NS_CC;


bool StoreLayer::init()
{

    if ( !Layer::init())
    {
        return false;
    }
    Size visibleSize = Director::getInstance()->getVisibleSize();
    
    s_pre_tab_index = 0;
    
    auto mix_background = Sprite::create("background/store_back.png");
    mix_background->setAnchorPoint(Vec2(0.5,1));
    mix_background->setPosition(Vec2(visibleSize.width*0.5f, visibleSize.height-545));
    mix_background->getTexture()->setAliasTexParameters();
    mix_background->setScale(5.0f);
    this->addChild(mix_background, 0);
    
    auto tab_spr_0 = MenuItemImage::create("ui/store_tab_f.png", "ui/store_tab_t.png", "ui/store_tab_t.png", CC_CALLBACK_1(StoreLayer::tabCallback, this));
    tab_spr_0->setAnchorPoint(Vec2(0.5,1));
    tab_spr_0->setTag(3);
    tab_spr_0->setPosition(Vec2(visibleSize.width*0.5f - 180, visibleSize.height-545));
    
    auto tab_spr_1 = MenuItemImage::create("ui/store_tab_f.png", "ui/store_tab_t.png", "ui/store_tab_t.png", CC_CALLBACK_1(StoreLayer::tabCallback, this));
    tab_spr_1->setAnchorPoint(Vec2(0.5,1));
    tab_spr_1->setTag(2);
    tab_spr_1->setPosition(Vec2(visibleSize.width*0.5f - 275 , visibleSize.height-545));
    
    auto tab_spr_2 = MenuItemImage::create("ui/store_tab_f.png", "ui/store_tab_t.png", "ui/store_tab_t.png", CC_CALLBACK_1(StoreLayer::tabCallback, this));
    tab_spr_2->setAnchorPoint(Vec2(0.5,1));
    tab_spr_2->setTag(1);
    tab_spr_2->setPosition(Vec2(visibleSize.width*0.5f - 370, visibleSize.height-545));
    
    auto tab_spr_3 = MenuItemImage::create("ui/store_tab_f.png", "ui/store_tab_t.png", "ui/store_tab_t.png", CC_CALLBACK_1(StoreLayer::tabCallback, this));
    tab_spr_3->setAnchorPoint(Vec2(0.5,1));
    tab_spr_3->setTag(0);
    tab_spr_3->setPosition(Vec2(visibleSize.width*0.5f - 465, visibleSize.height-545));
    
    
    auto menu = Menu::create(tab_spr_0, tab_spr_1, tab_spr_2, tab_spr_3, nullptr);
    menu->setAnchorPoint(Vec2(0,0));
    menu->setPosition(Vec2(0,0));
    this->addChild(menu , 10);
    
    tab_spr_3->setEnabled(false);
    
    
    m_listview = ListView::create();
    // set list view ex direction
    m_listview->setDirection(ui::ScrollView::Direction::VERTICAL);
    m_listview->setBounceEnabled(true);
    m_listview->setContentSize(Size(770, 770));
    m_listview->setAnchorPoint(Vec2(0.5, 0.5f));
    m_listview->setPosition(Vec2(visibleSize.width*0.5f-69, 662));
    m_listview->addEventListener((ui::ListView::ccListViewCallback)CC_CALLBACK_2(StoreLayer::selectedItemEvent, this));
   
    m_listview->setScrollBarPositionFromCorner(Vec2(7, 7));

    this->addChild(m_listview);
    
    for (int i = 0; i < 10; ++i)
    {
        Button* custom_button = Button::create("ui/store_buybtn_f.png", "ui/store_buybtn_t.png");
        custom_button->setName("Title Button");
        custom_button->setAnchorPoint(Vec2(1,0.5));
        custom_button->setTitleText("구 매");
        custom_button->setTitleFontSize(30.0f);
        //        custom_button->setScale9Enabled(true);
        //        custom_button->setContentSize(default_button->getContentSize());
        
        Layout *custom_item = Layout::create();
        custom_item->setContentSize(Size(770,200));
        custom_button->setPosition(Vec2(custom_item->getContentSize().width-10, custom_item->getContentSize().height / 2.0f));
        
        auto spr_back = Sprite::create("ui/item_box.png");
        spr_back->getTexture()->setAliasTexParameters();
        spr_back->setScale(5.0f);
        spr_back->setPosition(Vec2(custom_item->getContentSize().width*0.5f,custom_item->getContentSize().height*0.5f));
        
        custom_item->addChild(spr_back);
        custom_item->addChild(custom_button);
        
        m_listview->pushBackCustomItem(custom_item);
        
    }
    
    return true;
}

void StoreLayer::tabCallback(Ref *pSender){
    auto spr = static_cast<MenuItemImage*>(pSender);
    auto pre_menu =  dynamic_cast<MenuItemImage*>(spr->getParent()->getChildByTag(s_pre_tab_index));
    pre_menu->setEnabled(true);
    spr->setEnabled(false);
    switch(spr->getTag()){
        case 0:
            setTab1();
            CCLOG("병실이 나옴");
            break;
        case 1:
            setTab2();
            CCLOG("제조실이 나옴");
            break;
        case 2:
            setTab3();
            CCLOG("약초상이 나옴");
            break;
        case 3:
            setTab4();
            CCLOG("약초수집이 나옴");
            break;
    }
    switch(s_pre_tab_index){
        case 0:
            break;
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
    }
    s_pre_tab_index = spr->getTag();
}

void StoreLayer::setHideLayer(bool hide){
    if(hide){
        
    }else{
        
    }
}

void StoreLayer::selectedItemEvent(Ref *pSender, ListView::EventType type)
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
            
            switch(s_pre_tab_index){
                case 0:
                    CCLOG("첫번째 탭의 구매 = %ld", listView->getCurSelectedIndex());
                    break;
                case 1:
                    CCLOG("두번째 탭의 구매 = %ld", listView->getCurSelectedIndex());
                    break;
                case 2:
                    CCLOG("세번째 탭의 구매 = %ld", listView->getCurSelectedIndex());
                    break;
                case 3:
                    CCLOG("네번째 탭의 구매 = %ld", listView->getCurSelectedIndex());
                    auto label = Label::createWithSystemFont("", "", 40);
                    label->setPosition(Vec2(200,200));
                    dbrw _dbrw;
                    int a = _dbrw.selectData();
                    label->setString(StringUtils::format("Test %d", a));
                    this->addChild(label);
                    break;
                
            }
            
            break;
        }
        default:
            break;
    }
}

void StoreLayer::setTab1()
{
    m_listview->removeAllItems();
    m_listview->scrollToTop(0.3f, true);
    for (int i = 0; i < 10; ++i)
    {
        Button* custom_button = Button::create("ui/store_buybtn_f.png", "ui/store_buybtn_t.png");
        custom_button->setName("Title Button");
        custom_button->setAnchorPoint(Vec2(1,0.5));
        custom_button->setTitleText("구 매");
        custom_button->setTitleFontSize(30.0f);
//        custom_button->setScale9Enabled(true);
//        custom_button->setContentSize(default_button->getContentSize());
        
        Layout *custom_item = Layout::create();
        custom_item->setContentSize(Size(770,200));
        custom_button->setPosition(Vec2(custom_item->getContentSize().width-10, custom_item->getContentSize().height / 2.0f));
        
        auto spr_back = Sprite::create("ui/item_box.png");
        spr_back->getTexture()->setAliasTexParameters();
        spr_back->setScale(5.0f);
        spr_back->setPosition(Vec2(custom_item->getContentSize().width*0.5f,custom_item->getContentSize().height*0.5f));
        
        custom_item->addChild(spr_back);
        custom_item->addChild(custom_button);
        
        m_listview->pushBackCustomItem(custom_item);
        
    }
}

void StoreLayer::setTab2()
{
    m_listview->removeAllItems();
    m_listview->scrollToTop(0.3f, true);
    for (int i = 0; i < 10; ++i)
    {
        Button* custom_button = Button::create("ui/store_buybtn_f.png", "ui/store_buybtn_t.png");
        custom_button->setName("Title Button");
        custom_button->setAnchorPoint(Vec2(1,0.5));
        custom_button->setTitleText("구 매");
        custom_button->setTitleFontSize(30.0f);
        //        custom_button->setScale9Enabled(true);
        //        custom_button->setContentSize(default_button->getContentSize());
        
        Layout *custom_item = Layout::create();
        custom_item->setContentSize(Size(770,200));
        custom_button->setPosition(Vec2(custom_item->getContentSize().width-10, custom_item->getContentSize().height / 2.0f));
        
        auto spr_back = Sprite::create("ui/item_box.png");
        spr_back->getTexture()->setAliasTexParameters();
        spr_back->setScale(5.0f);
        spr_back->setPosition(Vec2(custom_item->getContentSize().width*0.5f,custom_item->getContentSize().height*0.5f));
        
        custom_item->addChild(spr_back);
        custom_item->addChild(custom_button);
        
        m_listview->pushBackCustomItem(custom_item);
        
    }
}

void StoreLayer::setTab3()
{
    m_listview->removeAllItems();
    m_listview->scrollToTop(0.3f, true);
    for (int i = 0; i < 10; ++i)
    {
        Button* custom_button = Button::create("ui/store_buybtn_f.png", "ui/store_buybtn_t.png");
        custom_button->setName("Title Button");
        custom_button->setAnchorPoint(Vec2(1,0.5));
        custom_button->setTitleText("구 매");
        custom_button->setTitleFontSize(30.0f);
        //        custom_button->setScale9Enabled(true);
        //        custom_button->setContentSize(default_button->getContentSize());
        
        Layout *custom_item = Layout::create();
        custom_item->setContentSize(Size(770,200));
        custom_button->setPosition(Vec2(custom_item->getContentSize().width-10, custom_item->getContentSize().height / 2.0f));
        
        //item image set
        
        auto spr_item = Sprite::create();
        spr_item->setTexture("character/herb_01.png");
        spr_item->setAnchorPoint(Vec2(0,0.5));
        spr_item->setPosition(Vec2(Vec2(20,custom_item->getContentSize().height/2.0f)));
        
        //item test set
        
        auto label_name = Label::createWithSystemFont("장뇌삼", "", 35.0f);
        label_name->setPosition(Vec2(200, 140));
        label_name->setAnchorPoint(Vec2(0,0.5));
        
        auto label_content = Label::createWithSystemFont("내용쓰는 곳이지롱!", "", 25.0f);
        label_content->setPosition(Vec2(200, 95));
        label_content->setAnchorPoint(Vec2(0,0.5));
        
        
        auto spr_back = Sprite::create("ui/item_box.png");
        spr_back->getTexture()->setAliasTexParameters();
        spr_back->setScale(5.0f);
        spr_back->setPosition(Vec2(custom_item->getContentSize().width*0.5f,custom_item->getContentSize().height*0.5f));
        
        custom_item->addChild(spr_back);
        custom_item->addChild(custom_button);
        custom_item->addChild(label_name);
        custom_item->addChild(label_content);
        custom_item->addChild(spr_item);

        
        m_listview->pushBackCustomItem(custom_item);
        
    }
}

void StoreLayer::setTab4()
{
    m_listview->removeAllItems();
    m_listview->scrollToTop(0.3f, true);
    for (int i = 0; i < 10; ++i)
    {
        Button* custom_button = Button::create("ui/store_buybtn_f.png", "ui/store_buybtn_t.png");
        custom_button->setName("Title Button");
        custom_button->setAnchorPoint(Vec2(1,0.5));
        custom_button->setTitleText("구 매");
        custom_button->setTitleFontSize(30.0f);
        //        custom_button->setScale9Enabled(true);
        //        custom_button->setContentSize(default_button->getContentSize());
        
        Layout *custom_item = Layout::create();
        custom_item->setContentSize(Size(770,200));
        custom_button->setPosition(Vec2(custom_item->getContentSize().width-10, custom_item->getContentSize().height / 2.0f));
        
        auto spr_back = Sprite::create("ui/item_box.png");
        spr_back->getTexture()->setAliasTexParameters();
        spr_back->setScale(5.0f);
        spr_back->setPosition(Vec2(custom_item->getContentSize().width*0.5f,custom_item->getContentSize().height*0.5f));
        
        custom_item->addChild(spr_back);
        custom_item->addChild(custom_button);
        
        m_listview->pushBackCustomItem(custom_item);
        
    }
}

//#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
//    exit(0);
//#endif

