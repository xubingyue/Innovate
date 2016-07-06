//
//  NotificationType.h
//  Innovate
//
//  Created by YUEBINBIN on 16/5/15.
//
//

#ifndef NotificationType_h
#define NotificationType_h

//namespace Notification {
//    enum class NotifiyRef
//    {
//        nid,
//        value,
//    };
//}

/*
 * 消息通知参数类型
 */
class NotifiyRef : public cocos2d::Ref
{
public:
    int nid;
    int value;
};

//点击地图移动
#define TOUCH_MAP_TO_MOVE "touch_map_to_move"
//战斗死亡
#define BATTLE_DIE_TO_CRYSTAL "battle_die_to_crystal"
//切换关卡
#define GO_TO_SELETE_MAP "go_to_selete_map"
//打开并进入副本
#define OPEN_AND_INTO_FUBEN "open_and_into_fuben"
//点击背包物品
#define CLICK_BAG_ELEMENT "click_bag_element"

#endif /* NotificationType_h */
