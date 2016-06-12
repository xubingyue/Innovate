//
//  PlayerView.cpp
//  Innovate
//
//  Created by YUEBINBIN on 16/5/27.
//
//

#include "PlayerView.h"
#include "cocostudio/CocoStudio.h"
#include "../model/PlayerModel.h"
#include "../core/utils/StringUtil.h"

USING_NS_CC;
using namespace cocos2d::ui;


PlayerView* PlayerView::create()
{
    PlayerView * ret = new (std::nothrow) PlayerView();
    if (ret && ret->init())
    {
        ret->autorelease();
    }
    else
    {
        CC_SAFE_DELETE(ret);
    }
    return ret;
}

PlayerView::PlayerView()
{
    
}

PlayerView::~PlayerView()
{
    
}

bool PlayerView::init()
{
    auto playerModel = PlayerModel::getInstance();

    p_root = CSLoader::createNodeWithVisibleSize("res/ui/PlayerView/PlayerView.csb");
    addChild(p_root);
    
    Button *backBtn = static_cast<Button*>(Helper::seekWidgetByName(static_cast<Layout*>(p_root), "back_btn"));
    backBtn->addTouchEventListener(CC_CALLBACK_2(PlayerView::touchEventCallback, this));

    //初始化center部分
    ImageView *centerBg = static_cast<ImageView*>(Helper::seekWidgetByName(static_cast<Layout*>(p_root), "center_bg"));
    p_playerNode = centerBg->getChildByName("player_node");
    p_playerNode->addChild(Sprite::create("res/grossinis.png"));
    
    //初始化up部分
    auto upNode = p_root->getChildByName("up_node");
    
    Text *lvTxt = static_cast<Text*>(Helper::seekWidgetByName(static_cast<Layout*>(upNode), "lv_txt"));
    lvTxt->setString("等级:" + StringUtil::intToString(playerModel->level));
    
    Text *atkTxt = static_cast<Text*>(Helper::seekWidgetByName(static_cast<Layout*>(upNode), "atk_txt"));
    atkTxt->setString("攻击:" + StringUtil::intToString(playerModel->attack));
    
    Text *hpTxt = static_cast<Text*>(Helper::seekWidgetByName(static_cast<Layout*>(upNode), "hp_txt"));
    hpTxt->setString("血量:" + StringUtil::intToString(playerModel->hp));
    
    Text *veloTxt = static_cast<Text*>(Helper::seekWidgetByName(static_cast<Layout*>(upNode), "velocity_txt"));
    veloTxt->setString("速度:" + StringUtil::intToString(playerModel->velocity));
    
    Text *skillTxt = static_cast<Text*>(Helper::seekWidgetByName(static_cast<Layout*>(upNode), "skill_txt"));
    skillTxt->setString("技能:" + StringUtil::intToString(playerModel->skill));

    Text *darkAtkTxt = static_cast<Text*>(Helper::seekWidgetByName(static_cast<Layout*>(upNode), "dark_atk_txt"));
    darkAtkTxt->setString("暗攻:" + StringUtil::intToString(playerModel->darkAtk));
    
    Text *fireAtkTxt = static_cast<Text*>(Helper::seekWidgetByName(static_cast<Layout*>(upNode), "fire_atk_txt"));
    fireAtkTxt->setString("火攻:" + StringUtil::intToString(playerModel->fireAtk));
    
    Text *windAtkTxt = static_cast<Text*>(Helper::seekWidgetByName(static_cast<Layout*>(upNode), "wind_atk_txt"));
    windAtkTxt->setString("风攻:" + StringUtil::intToString(playerModel->windAtk));
    
    Text *soilAtkTxt = static_cast<Text*>(Helper::seekWidgetByName(static_cast<Layout*>(upNode), "soil_atk_txt"));
    soilAtkTxt->setString("土攻:" + StringUtil::intToString(playerModel->soilAtk));
    
    Text *recoverTxt = static_cast<Text*>(Helper::seekWidgetByName(static_cast<Layout*>(upNode), "recover_txt"));
    recoverTxt->setString("恢复:" + StringUtil::intToString(playerModel->recover));
    
    Text *darkRstTxt = static_cast<Text*>(Helper::seekWidgetByName(static_cast<Layout*>(upNode), "dark_resist_txt"));
    darkRstTxt->setString("暗抗:" + StringUtil::intToString(playerModel->darkRst));
    
    Text *fireRstTxt = static_cast<Text*>(Helper::seekWidgetByName(static_cast<Layout*>(upNode), "fire_resist_txt"));
    fireRstTxt->setString("火抗:" + StringUtil::intToString(playerModel->fireRst));
    
    Text *windRstTxt = static_cast<Text*>(Helper::seekWidgetByName(static_cast<Layout*>(upNode), "wind_resist_txt"));
    windRstTxt->setString("风抗:" + StringUtil::intToString(playerModel->windRst));
    
    Text *soilRstTxt = static_cast<Text*>(Helper::seekWidgetByName(static_cast<Layout*>(upNode), "soil_resisit_txt"));
    soilRstTxt->setString("土抗:" + StringUtil::intToString(playerModel->soilRst));
    
    Text *absorbTxt = static_cast<Text*>(Helper::seekWidgetByName(static_cast<Layout*>(upNode), "absorb_txt"));
    absorbTxt->setString("吸血:" + StringUtil::intToString(playerModel->absorb));
    
    return true;
}

void PlayerView::touchEventCallback(Ref *sender, Widget::TouchEventType controlEvent)
{
    if (controlEvent == Widget::TouchEventType::ENDED) {
        this->removeFromParentAndCleanup(true);
    }
}






