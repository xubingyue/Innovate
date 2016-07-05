#ifndef __TABLES_Item_compose_H__
#define __TABLES_Item_compose_H__
#include "cocos2d.h"
#include "../../core/data/database/TableHelper.h"

USING_NS_CC;

namespace tables
{
	class Item_compose_table 
	{
	public:
		//id
		int id;
		//名称
		std::string name;
		//所需道具1
		int item_1;
		//道具1个数
		int item_num_1;
		//所需道具2
		int item_2;
		//道具2个数
		int item_num_2;
		Item_compose_table()
		{
			
		}
	};

	class Item_compose
	{
	public:
		Item_compose(unsigned const char* data, size_t size);
		~Item_compose(void);
		std::map<std::string, Item_compose_table> m_data;
		static const char* fileName();
		std::string Error;
		
		Item_compose_table* getItem_composeVo(int id);
		std::string int2String(int num);
	};
}

#endif  // __TABLES_Item_compose_H__
