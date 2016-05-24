#ifndef __TABLES_Object_H__
#define __TABLES_Object_H__
#include "cocos2d.h"
#include "TableHelper.h"

USING_NS_CC;

namespace tables
{
	class Object_table 
	{
	public:
		//id
		int id;
		//名字
		std::string name;
		//血量
		int hp;
		Object_table()
		{
			memset(&id, 0, sizeof(id));
			memset(&name, 0, sizeof(name));
			memset(&hp, 0, sizeof(hp));
		}
	};

	class Object
	{
	public:
		Object(unsigned const char* data, size_t size);
		~Object(void);
		std::map<std::string, std::unique_ptr<Object_table>> m_data;
		static const char* fileName();
		std::string Error;
		
		Object_table* getObjectVo(int id);
		std::string int2String(int num);
	};
}

#endif  // __TABLES_Object_H__
