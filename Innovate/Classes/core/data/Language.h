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
		const char* zh_txt;
		//英文
		const char* en_txt;
		Language_table()
		{
			memset(&id, 0, sizeof(id));
			memset(&zh_txt, 0, sizeof(zh_txt));
			memset(&en_txt, 0, sizeof(en_txt));
		}
	};

	class Language
	{
	public:
		Language(unsigned const char* data, size_t size);
		~Language(void);
		std::map<const char*, std::unique_ptr<Language_table>> m_data;
		static const char* fileName();
		std::string Error;
		
		Language_table* getLanguageVo(int id);
		const char* int2String(int num);
	};
}

#endif  // __TABLES_Language_H__
