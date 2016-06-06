#ifndef __TABLES_Monster_H__
#define __TABLES_Monster_H__
#include "cocos2d.h"
#include "TableHelper.h"

USING_NS_CC;

namespace tables
{
	class Monster_table 
	{
	public:
		//id
		int id;
		//名字
		std::string name;
		//掉落id
		int diropId;
		//血量
		int hp;
		//攻击力
		int attack;
		//速度
		float velocity;
		//形象
		std::string character_in;
		//场景地图序号
		int sceneID;
		//玩家等级下限
		int minLevel;
		//玩家等级上限
		int maxLevel;
		//副本序号
		int raidID;
		//副本怪点
		int monsterPoint;
		Monster_table()
		{
			memset(&id, 0, sizeof(id));
			memset(&name, 0, sizeof(name));
			memset(&diropId, 0, sizeof(diropId));
			memset(&hp, 0, sizeof(hp));
			memset(&attack, 0, sizeof(attack));
			memset(&velocity, 0, sizeof(velocity));
			memset(&character_in, 0, sizeof(character_in));
			memset(&sceneID, 0, sizeof(sceneID));
			memset(&minLevel, 0, sizeof(minLevel));
			memset(&maxLevel, 0, sizeof(maxLevel));
			memset(&raidID, 0, sizeof(raidID));
			memset(&monsterPoint, 0, sizeof(monsterPoint));
		}
	};

	class Monster
	{
	public:
		Monster(unsigned const char* data, size_t size);
		~Monster(void);
		std::map<std::string, std::unique_ptr<Monster_table>> m_data;
		static const char* fileName();
		std::string Error;
		
		Monster_table* getMonsterVo(int id);
		std::string int2String(int num);
	};
}

#endif  // __TABLES_Monster_H__
