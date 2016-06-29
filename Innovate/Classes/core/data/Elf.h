#ifndef __TABLES_Elf_H__
#define __TABLES_Elf_H__
#include "cocos2d.h"
#include "../../core/data/database/TableHelper.h"

USING_NS_CC;

namespace tables
{
	class Elf_table 
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
		Elf_table()
		{
			memset(&id, 0, sizeof(id));
			memset(&name, 0, sizeof(name));
			memset(&hp, 0, sizeof(hp));
			memset(&attack, 0, sizeof(attack));
			memset(&velocity, 0, sizeof(velocity));
			memset(&character_in, 0, sizeof(character_in));
		}
	};

	class Elf
	{
	public:
		Elf(unsigned const char* data, size_t size);
		~Elf(void);
		std::map<std::string, std::unique_ptr<Elf_table>> m_data;
		static const char* fileName();
		std::string Error;
		
		Elf_table* getElfVo(int id);
		std::string int2String(int num);
	};
}

#endif  // __TABLES_Elf_H__
