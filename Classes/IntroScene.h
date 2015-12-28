#ifndef __INTRO_SCENE_H__
#define __INTRO_SCENE_H__

#include "cocos2d.h"

USING_NS_CC;

class IntroScene : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    
    
    int loadCount;
    
    // a selector callback
    void inputCache();
    void loadingCallBack(cocos2d::Texture2D *texture);
    
    
    // implement the "static create()" method manually
    CREATE_FUNC(IntroScene);
};

#endif // __HELLOWORLD_SCENE_H__
