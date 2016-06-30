#ifndef __TABLES_Language_H__
#define __TABLES_Language_H__
#include "cocos2d.h"
#include "../../core/data/database/TableHelper.h"

USING_NS_CC;

namespace tables
{
	class Language_table 
	{
	public:
		//id
		int id;
		//中文
		std::string zh_txt;
		//英文
		std::string en_txt;
		Language_table()
		{
			
		}
	};

	class Language
	{
	public:
		Language(unsigned const char* data, size_t size);
		~Language(void);
		std::map<std::string, Language_table> m_data;
		static const char* fileName();
		std::string Error;
		
		Language_table* getLanguageVo(int id);
		std::string int2String(int num);
	};
}

#endif  // __TABLES_Language_H__
