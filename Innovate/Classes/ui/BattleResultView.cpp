//
//  BattleResultView.cpp
//  Innovate
//
//  Created by YUEBINBIN on 16/6/3.
//
//

#include "BattleResultView.h"
#include "cocostudio/CocoStudio.h"
#include "BattleController.h"
#include "DataManager.h"
#include "StringUtil.h"
#include "../utils/IconUtil.h"
#include "BagModel.h"

USING_NS_CC;
using namespace cocos2d::ui;


BattleResultView* BattleResultView::create(int flag, int monsterId)
{
    BattleResultView * ret = new (std::nothrow) BattleResultView();
    if (ret && ret->init(flag, monsterId))
    {
        ret->autorelease();
    }
    else
    {
        CC_SAFE_DELETE(ret);
    }
    return ret;
}

BattleResultView::BattleResultView()
{
    
}

BattleResultView::~BattleResultView()
{
    
}

bool BattleResultView::init(int flag, int monsterId)
{
    p_root = CSLoader::createNodeWithVisibleSize("res/ui/BattleView/DropListView.csb");
    addChild(p_root);
    
    Button *backBtn = static_cast<Button*>(Helper::seekWidgetByName(static_cast<Layout*>(p_root), "back_btn"));
    backBtn->addTouchEventListener(CC_CALLBACK_2(BattleResultView::touchEventCallback, this));
    
    Text *resultTxt = static_cast<Text*>(Helper::seekWidgetByName(static_cast<Layout*>(p_root), "result_txt"));
    switch (flag) {
        case BattleResultType::WIN:
            resultTxt->setString("战斗胜利");
            break;
        case BattleResultType::FAIL:
            resultTxt->setString("战斗失败");
            break;
        case BattleResultType::ESCAPE:
            resultTxt->setString("战斗失败");
            break;
        default:
            resultTxt->setString("战斗失败");
            break;
    }
    
    if (flag == BattleResultType::ESCAPE)
    {
        vector<DropItem> *dropList = new vector<DropItem>();
        getDorpList(monsterId, *dropList);

        Layout *layout = static_cast<Layout*>(Helper::seekWidgetByName(static_cast<Layout*>(p_root), "result_panel"));
        auto dropNode = layout->getChildByName("drop_node");
        int posX = 0;
        for (DropItem di : *dropList)
        {
            auto icon = IconUtil::getInstance()->getIconById(IconType::IconType_ELEMENT, di.dropId, di.count);
            dropNode->addChild(icon);
            icon->setPositionX(posX);
            posX += 74;
            
            auto eleVo = ELEMENT_TABLE->getElementVo(di.dropId);
            BagItem *item = new BagItem();
            item->itemId = eleVo->id;
            item->type = BagType::ELEMENT;
            BagModel::getInstance()->addItem(item, di.count);
        }
        //销毁
        dropList->clear();
        delete dropList;
    }

    return true;
}

void BattleResultView::touchEventCallback(Ref *sender, Widget::TouchEventType controlEvent)
{
    if (controlEvent == Widget::TouchEventType::ENDED) {
        this->removeFromParentAndCleanup(true);
        BattleController::getInstance()->exitBattle();
    }
}

void BattleResultView::getDorpList(int monsterId, std::vector<DropItem> &list)
{
    auto monsterVo = MONSTER_TABLE->getMonsterVo(monsterId);
    auto dropVo = DROP_TABLE->getDropVo(monsterVo->diropId);
    
    srand((int)time(0));
    if (dropVo->dropID0 != 0)
    {
        int x = rand() % 100;
        if (x <= dropVo->weight0 * 100)
        {
            auto di = getDropItem(dropVo->dropID0);
            list.push_back(di);
        }
    }
    if (dropVo->dropID1 != 0)
    {
        int x = rand() % 100;
        if (x <= dropVo->weight1 * 100)
        {
            auto di = getDropItem(dropVo->dropID1);
            list.push_back(di);
        }
    }
    if (dropVo->dropID2 != 0)
    {
        int x = rand() % 100;
        if (x <= dropVo->weight2 * 100)
        {
            auto di = getDropItem(dropVo->dropID2);
            list.push_back(di);
        }
    }
    if (dropVo->dropID3 != 0)
    {
        int x = rand() % 100;
        if (x <= dropVo->weight3 * 100)
        {
            auto di = getDropItem(dropVo->dropID3);
            list.push_back(di);
        }
    }
}

DropItem BattleResultView::getDropItem(int dId)
{
    auto dropItemVo = DROP_ITEM_TABLE->getDrop_itemVo(dId);
    string wei = dropItemVo->weight;
    vector<string>* dropWei = new vector<string>();
    string delim1 = ";";
    StringUtil::split(wei, delim1, dropWei);
    
    string items = dropItemVo->item_id;
    vector<string>* dropId = new vector<string>();
    string delim2 = ";";
    StringUtil::split(items, delim2, dropId);
    
    int tempCount = 0;
    int i = 0;
    
    while (i < dropWei->size()) {
        tempCount += StringUtil::stringToFloat((*dropWei)[i])*100;
        i++;
    }
    int y = rand() % tempCount;
    i = 0;
    int pre = 0;
    DropItem di;
    while(i < dropWei->size())
    {
        int curr = StringUtil::stringToFloat((*dropWei)[i])*100;
        if (y > pre && y < curr + pre)
        {
            string drop = (*dropId)[i];
            vector<string>* result = new vector<string>();
            string delim3 = "#";
            StringUtil::split(drop, delim3, result);
            di.dropId = StringUtil::stringToInt((*result)[0]);
            di.count = StringUtil::stringToInt((*result)[1]);
            delete result;
            return di;
        }
        pre = pre + curr;
        i++;
    }
    delete dropWei;
    delete dropId;
    return di;
}



