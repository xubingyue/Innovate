#include <thread>
#include "DataManager.h"

#define LOAD_TABLE(tablePtr, tableClass, tableFile, callback, count) \
{\
std::string jsonpath = FileUtils::getInstance()->fullPathForFilename(tableFile);\
data = FileUtils::getInstance()->getDataFromFile(jsonpath);\
tablePtr = new tableClass(data.getBytes(), (int)data.getSize());\
count++;\
if (callback != nullptr)\
{\
callback(count);\
}\
}

static DataManager* _instance = nullptr;

DataManager::DataManager(void)
{
}


DataManager::~DataManager(void)
{
    
}

DataManager* DataManager::getInstance()
{
    if(_instance == nullptr)
    {
        _instance = new DataManager();
    }
    return _instance;
}

void DataManager::loadTable(const loadCallback& callback, std::string localConfig)
{
    int count = 0;
    Data data;
    LOAD_TABLE(m_Stage, tables::Stage, localConfig + "/" + tables::Stage::fileName(), callback, count);
    LOAD_TABLE(m_Role, tables::Role, localConfig + "/" + tables::Role::fileName(), callback, count);
    
}
