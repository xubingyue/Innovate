#ifndef __TABLES_Role_H__
#define __TABLES_Role_H__
#include "cocos2d.h"
#include "TableHelper.h"

USING_NS_CC;

namespace tables
{
	class Role_table 
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
		//战斗内形象
		std::string character_in;
		//技能
		int ski1;
		//暗攻击
		int darkAttack;
		//暗抗性
		int darkResist;
		//火攻击
		int fireAttack;
		//火抗性
		int fireResist;
		//风攻击
		int windAttack;
		//风抗性
		int windResist;
		//土攻击
		int soilAttack;
		//土抗性
		int soilResist;
		//恢复
		int recover;
		//吸血
		int absorb;
		Role_table()
		{
			memset(&id, 0, sizeof(id));
			memset(&name, 0, sizeof(name));
			memset(&hp, 0, sizeof(hp));
			memset(&attack, 0, sizeof(attack));
			memset(&velocity, 0, sizeof(velocity));
			memset(&character_in, 0, sizeof(character_in));
			memset(&ski1, 0, sizeof(ski1));
			memset(&darkAttack, 0, sizeof(darkAttack));
			memset(&darkResist, 0, sizeof(darkResist));
			memset(&fireAttack, 0, sizeof(fireAttack));
			memset(&fireResist, 0, sizeof(fireResist));
			memset(&windAttack, 0, sizeof(windAttack));
			memset(&windResist, 0, sizeof(windResist));
			memset(&soilAttack, 0, sizeof(soilAttack));
			memset(&soilResist, 0, sizeof(soilResist));
			memset(&recover, 0, sizeof(recover));
			memset(&absorb, 0, sizeof(absorb));
		}
	};

	class Role
	{
	public:
		Role(unsigned const char* data, size_t size);
		~Role(void);
		std::map<std::string, std::unique_ptr<Role_table>> m_data;
		static const char* fileName();
		std::string Error;
		
		Role_table* getRoleVo(int id);
		std::string int2String(int num);
	};
}

#endif  // __TABLES_Role_H__
