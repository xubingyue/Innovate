#ifndef __TABLES_Raid_map_H__
#define __TABLES_Raid_map_H__
#include "cocos2d.h"
#include "../../core/data/database/TableHelper.h"

USING_NS_CC;

namespace tables
{
	class Raid_map_table 
	{
	public:
		//id
		int id;
		//地图引用
		std::string map_name;
		//最低等级
		int minLevel;
		//最高等级
		int maxLevel;
		Raid_map_table()
		{
			
		}
	};

	class Raid_map
	{
	public:
		Raid_map(unsigned const char* data, size_t size);
		~Raid_map(void);
		std::map<std::string, Raid_map_table> m_data;
		static const char* fileName();
		std::string Error;
		
		Raid_map_table* getRaid_mapVo(int id);
		std::string int2String(int num);
	};
}

#endif  // __TABLES_Raid_map_H__
