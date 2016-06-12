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
			memset(&id, 0, sizeof(id));
			memset(&num, 0, sizeof(num));
			memset(&dropID0, 0, sizeof(dropID0));
			memset(&weight0, 0, sizeof(weight0));
			memset(&dropID1, 0, sizeof(dropID1));
			memset(&weight1, 0, sizeof(weight1));
			memset(&dropID2, 0, sizeof(dropID2));
			memset(&weight2, 0, sizeof(weight2));
			memset(&dropID3, 0, sizeof(dropID3));
			memset(&weight3, 0, sizeof(weight3));
		}
	};

	class Drop
	{
	public:
		Drop(unsigned const char* data, size_t size);
		~Drop(void);
		std::map<std::string, std::unique_ptr<Drop_table>> m_data;
		static const char* fileName();
		std::string Error;
		
		Drop_table* getDropVo(int id);
		std::string int2String(int num);
	};
}

#endif  // __TABLES_Drop_H__
