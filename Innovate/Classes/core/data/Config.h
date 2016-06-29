#ifndef __TABLES_Config_H__
#define __TABLES_Config_H__
#include "cocos2d.h"
#include "../../core/data/database/TableHelper.h"

USING_NS_CC;

namespace tables
{
	class Config_table 
	{
	public:
		//id
		int id;
		//数据
		std::string data;
		Config_table()
		{
			memset(&id, 0, sizeof(id));
			memset(&data, 0, sizeof(data));
		}
	};

	class Config
	{
	public:
		Config(unsigned const char* data, size_t size);
		~Config(void);
		std::map<std::string, std::unique_ptr<Config_table>> m_data;
		static const char* fileName();
		std::string Error;
		
		Config_table* getConfigVo(int id);
		std::string int2String(int num);
	};
}

#endif  // __TABLES_Config_H__
