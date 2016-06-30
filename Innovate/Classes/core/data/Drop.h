#ifndef __TABLES_Drop_H__
#define __TABLES_Drop_H__
#include "cocos2d.h"
#include "../../core/data/database/TableHelper.h"

USING_NS_CC;

namespace tables
{
	class Drop_table 
	{
	public:
		//id
		int id;
		//个数
		int num;
		//物品库0
		int dropID0;
		//概率0
		float weight0;
		//物品库1
		int dropID1;
		//概率1
		float weight1;
		//物品库2
		int dropID2;
		//概率2
		float weight2;
		//物品库3
		int dropID3;
		//概率3
		float weight3;
		Drop_table()
		{
			
		}
	};

	class Drop
	{
	public:
		Drop(unsigned const char* data, size_t size);
		~Drop(void);
		std::map<std::string, Drop_table> m_data;
		static const char* fileName();
		std::string Error;
		
		Drop_table* getDropVo(int id);
		std::string int2String(int num);
	};
}

#endif  // __TABLES_Drop_H__
