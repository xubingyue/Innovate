#ifndef __TABLES_Scene_map_H__
#define __TABLES_Scene_map_H__
#include "cocos2d.h"
#include "../../core/data/database/TableHelper.h"

USING_NS_CC;

namespace tables
{
	class Scene_map_table 
	{
	public:
		//场景地图序号
		int id;
		//地图引用
		std::string map_name;
		//最低等级
		int minLevel;
		//最高等级
		int maxLevel;
		//暗雷初始几率
		float probability;
		//暗雷步长
		float probability_grow;
		//等级步长衰减
		float attenuation;
		Scene_map_table()
		{
			memset(&id, 0, sizeof(id));
			memset(&map_name, 0, sizeof(map_name));
			memset(&minLevel, 0, sizeof(minLevel));
			memset(&maxLevel, 0, sizeof(maxLevel));
			memset(&probability, 0, sizeof(probability));
			memset(&probability_grow, 0, sizeof(probability_grow));
			memset(&attenuation, 0, sizeof(attenuation));
		}
	};

	class Scene_map
	{
	public:
		Scene_map(unsigned const char* data, size_t size);
		~Scene_map(void);
		std::map<std::string, std::unique_ptr<Scene_map_table>> m_data;
		static const char* fileName();
		std::string Error;
		
		Scene_map_table* getScene_mapVo(int id);
		std::string int2String(int num);
	};
}

#endif  // __TABLES_Scene_map_H__
