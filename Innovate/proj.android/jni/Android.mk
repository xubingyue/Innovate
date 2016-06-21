LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

$(call import-add-path,$(LOCAL_PATH)/../../cocos2d)
$(call import-add-path,$(LOCAL_PATH)/../../cocos2d/external)
$(call import-add-path,$(LOCAL_PATH)/../../cocos2d/cocos)

LOCAL_MODULE := cocos2dcpp_shared

LOCAL_MODULE_FILENAME := libcocos2dcpp

LOCAL_SRC_FILES := hellocpp/main.cpp \
                   ../../Classes/AppDelegate.cpp \
                   ../../Classes/LoadingScene.cpp \
                   ../../Classes/LayerManager.cpp \
                   ../../Classes/LocalDataManager.cpp \
                   ../../Classes/HelloWorldScene.cpp \
                   ../../Classes/core/algorithm/AStarFindPath.cpp \
                   ../../Classes/core/utils/md5.cpp \
                   ../../Classes/core/utils/LocalDataUtil.cpp \
                   ../../Classes/core/utils/StringUtil.cpp \
                   ../../Classes/core/utils/LanguageUtil.cpp \
                   ../../Classes/core/memory/MemManager.cpp \
                   ../../Classes/core/data/database/libcsv.c \
                   ../../Classes/core/data/database/TableHelper.cpp \
                   ../../Classes/core/data/DataManager.cpp \
                   ../../Classes/core/data/Config.cpp \
                   ../../Classes/core/data/Element.cpp \
                   ../../Classes/core/data/Drop_item.cpp \
                   ../../Classes/core/data/Drop.cpp \
                   ../../Classes/core/data/Raid_map.cpp \
                   ../../Classes/core/data/Scene_map.cpp \
                   ../../Classes/core/data/Elf.cpp \
                   ../../Classes/core/data/Language.cpp \
                   ../../Classes/core/data/Monster.cpp \
                   ../../Classes/core/data/Object.cpp \
                   ../../Classes/core/data/Role.cpp \
                   ../../Classes/core/data/Stage.cpp \
                   ../../Classes/model/MonsterModel.cpp \
                   ../../Classes/model/ModelBase.cpp \
                   ../../Classes/model/PlayerModel.cpp \
                   ../../Classes/model/GlobalModel.cpp \
                   ../../Classes/model/BagModel.cpp \
                   ../../Classes/role/RoleSprite.cpp \
                   ../../Classes/map/StageMapView.cpp \
                   ../../Classes/map/MapObjBase.cpp \
                   ../../Classes/map/MapObjDisplay.cpp \
                   ../../Classes/map/MapObjBuilding.cpp \
                   ../../Classes/map/MapObjMonster.cpp \
                   ../../Classes/battle/BattleObj/BattleObjBase.cpp \
                   ../../Classes/battle/BattleObj/BattleMonster.cpp \
                   ../../Classes/battle/BattleObj/BattlePlayer.cpp \
                   ../../Classes/battle/BattleObj/BattleElf.cpp \
                   ../../Classes/battle/BattleController.cpp \
                   ../../Classes/battle/BattleView.cpp \
                   ../../Classes/ui/UIComponent.cpp \
                   ../../Classes/ui/PlayerView.cpp \
                   ../../Classes/ui/BigCrystalView.cpp \
                   ../../Classes/ui/BagView.cpp \
                   ../../Classes/ui/BattleResultView.cpp \
                   ../../Classes/ui/MapTransferView.cpp \
                   ../../Classes/utils/IconUtil.cpp \
                   ../../Classes/utils/ShareUtils.cpp


LOCAL_C_INCLUDES := $(LOCAL_PATH)/../../Classes

# _COCOS_HEADER_ANDROID_BEGIN
# _COCOS_HEADER_ANDROID_END


LOCAL_STATIC_LIBRARIES := cocos2dx_static

# _COCOS_LIB_ANDROID_BEGIN
# _COCOS_LIB_ANDROID_END

include $(BUILD_SHARED_LIBRARY)

$(call import-module,.)

# _COCOS_LIB_IMPORT_ANDROID_BEGIN
# _COCOS_LIB_IMPORT_ANDROID_END
