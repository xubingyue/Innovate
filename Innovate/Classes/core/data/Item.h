#ifndef __TABLES_Item_H__
#define __TABLES_Item_H__
#include "cocos2d.h"
#include "../../core/data/database/TableHelper.h"

USING_NS_CC;

namespace tables
{
	class Item_table 
	{
	public:
		//id
		int id;
		//名称
		std::string name;
		//图标
		std::string icon;
		//类别
		int type;
		//因数1
		int factor1;
		//因数2
		int factor2;
		//说明
		std::string tips;
		Item_table()
		{
			
		}
	};

	class Item
	{
	public:
		Item(unsigned const char* data, size_t size);
		~Item(void);
		std::map<std::string, Item_table> m_data;
		static const char* fileName();
		std::string Error;
		
		Item_table* getItemVo(int id);
		std::string int2String(int num);
	};
}

#endif  // __TABLES_Item_H__
