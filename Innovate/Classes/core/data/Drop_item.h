#ifndef __TABLES_Drop_item_H__
#define __TABLES_Drop_item_H__
#include "cocos2d.h"
#include "../../core/data/database/TableHelper.h"

USING_NS_CC;

namespace tables
{
	class Drop_item_table 
	{
	public:
		//物品库id
		int id;
		//物品
		std::string item_id;
		//权重
		std::string weight;
		Drop_item_table()
		{
			
		}
	};

	class Drop_item
	{
	public:
		Drop_item(unsigned const char* data, size_t size);
		~Drop_item(void);
		std::map<std::string, Drop_item_table> m_data;
		static const char* fileName();
		std::string Error;
		
		Drop_item_table* getDrop_itemVo(int id);
		std::string int2String(int num);
	};
}

#endif  // __TABLES_Drop_item_H__
