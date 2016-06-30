#ifndef __TABLES_Object_H__
#define __TABLES_Object_H__
#include "cocos2d.h"
#include "../../core/data/database/TableHelper.h"

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
		//类型
		int type;
		//值
		int value;
		//资源
		std::string res;
		Object_table()
		{
			
		}
	};

	class Object
	{
	public:
		Object(unsigned const char* data, size_t size);
		~Object(void);
		std::map<std::string, Object_table> m_data;
		static const char* fileName();
		std::string Error;
		
		Object_table* getObjectVo(int id);
		std::string int2String(int num);
	};
}

#endif  // __TABLES_Object_H__
