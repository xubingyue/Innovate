#ifndef __APP_DataManager_H__
#define __APP_DataManager_H__

#include "Config.h"
#include "Elf.h"
#include "Language.h"
#include "Monster.h"
#include "Object.h"
#include "Role.h"
#include "Stage.h"

USING_NS_CC;

#define TABLESNUM 7
typedef std::function<void(int)> loadCallback;

class DataManager
{
public:
	DataManager(void);
	~DataManager(void);

	static DataManager* getInstance();

	void loadTable(const loadCallback& callback, std::string localConfig);
	
	tables::Config* m_Config;
	tables::Elf* m_Elf;
	tables::Language* m_Language;
	tables::Monster* m_Monster;
	tables::Object* m_Object;
	tables::Role* m_Role;
	tables::Stage* m_Stage;

#define CONFIG_TABLE (DataManager::getInstance()->m_Config)
#define GET_CONFIG_DATA	(&(DataManager::getInstance()->m_Config->m_data))
#define ELF_TABLE (DataManager::getInstance()->m_Elf)
#define GET_ELF_DATA	(&(DataManager::getInstance()->m_Elf->m_data))
#define LANGUAGE_TABLE (DataManager::getInstance()->m_Language)
#define GET_LANGUAGE_DATA	(&(DataManager::getInstance()->m_Language->m_data))
#define MONSTER_TABLE (DataManager::getInstance()->m_Monster)
#define GET_MONSTER_DATA	(&(DataManager::getInstance()->m_Monster->m_data))
#define OBJECT_TABLE (DataManager::getInstance()->m_Object)
#define GET_OBJECT_DATA	(&(DataManager::getInstance()->m_Object->m_data))
#define ROLE_TABLE (DataManager::getInstance()->m_Role)
#define GET_ROLE_DATA	(&(DataManager::getInstance()->m_Role->m_data))
#define STAGE_TABLE (DataManager::getInstance()->m_Stage)
#define GET_STAGE_DATA	(&(DataManager::getInstance()->m_Stage->m_data))
};

#endif  // __APP_DataManager_H__