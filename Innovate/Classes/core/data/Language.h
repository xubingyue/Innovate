#ifndef __TABLES_Language_H__
#define __TABLES_Language_H__
#include "cocos2d.h"
#include "TableHelper.h"

USING_NS_CC;

namespace tables
{
	class Language_table 
	{
	public:
		//id
		int id;
		//数据
		std::string data;
		Language_table()
		{
			memset(&id, 0, sizeof(id));
			memset(&data, 0, sizeof(data));
		}
	};

	class Language
	{
	public:
		Language(unsigned const char* data, size_t size);
		~Language(void);
		std::map<std::string, std::unique_ptr<Language_table>> m_data;
		static const char* fileName();
		std::string Error;
		
		Language_table* getLanguageVo(int id);
		std::string int2String(int num);
	};
}

#endif  // __TABLES_Language_H__
