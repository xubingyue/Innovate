#ifndef __TABLES_Role_H__
#define __TABLES_Role_H__
#include "cocos2d.h"
#include "TableHelper.h"

USING_NS_CC;

namespace tables
{
    class Role_table
    {
    public:
        //id
        int id;
        //数据
        std::string name;
        int hp;
        Role_table()
        {
            memset(&id, 0, sizeof(id));
            memset(&name, 0, sizeof(name));
            memset(&hp, 0, sizeof(hp));
        }
    };
    
    class Role
    {
    public:
        Role(unsigned const char* data, size_t size);
        ~Role(void);
        std::map<std::string, std::unique_ptr<Role_table>> m_data;
        static const char* fileName();
        std::string Error;
        
        Role_table* getRoleVo(int id);
        std::string int2String(int num);
    };
}

#endif  // __TABLES_Role_H__