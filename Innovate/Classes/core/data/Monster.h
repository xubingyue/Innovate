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
		//血量
		int hp;
		//攻击力
		int attack;
		//速度
		float velocity;
		//形象
		std::string character_in;
		Monster_table()
		{
			memset(&id, 0, sizeof(id));
			memset(&name, 0, sizeof(name));
			memset(&hp, 0, sizeof(hp));
			memset(&attack, 0, sizeof(attack));
			memset(&velocity, 0, sizeof(velocity));
			memset(&character_in, 0, sizeof(character_in));
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
