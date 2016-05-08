#ifndef __APP_DataManager_H__
#define __APP_DataManager_H__

#include "Stage.h"
#include "Role.h"

USING_NS_CC;

#define TABLESNUM 2
typedef std::function<void(int)> loadCallback;

class DataManager
{
public:
    DataManager(void);
    ~DataManager(void);
    
    static DataManager* getInstance();
    
    void run();
    
    void loadTable(const loadCallback& callback, std::string localConfig);
    
    tables::Stage* m_Stage;
    tables::Role* m_Role;
    
#define STAGE_TABLE (DataManager::getInstance()->m_Stage)
#define GET_STAGE_DATA	(&(DataManager::getInstance()->m_Stage->m_data))
    
#define ROLE_TABLE (DataManager::getInstance()->m_Role)
#define GET_ROLE_DATA	(&(DataManager::getInstance()->m_Role->m_data))

};

#endif  // __APP_DataManager_H__