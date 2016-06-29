#ifndef __TABLES_Upgrade_H__
#define __TABLES_Upgrade_H__
#include "cocos2d.h"
#include "../../core/data/database/TableHelper.h"

USING_NS_CC;

namespace tables
{
	class Upgrade_table 
	{
	public:
		//等级
		int level;
		//升级所需经验
		int level_next;
		//战斗获得经验
		int exp_get;
		//探索步数
		int step;
		//精灵个数
		int elf_num;
		Upgrade_table()
		{
			memset(&level, 0, sizeof(level));
			memset(&level_next, 0, sizeof(level_next));
			memset(&exp_get, 0, sizeof(exp_get));
			memset(&step, 0, sizeof(step));
			memset(&elf_num, 0, sizeof(elf_num));
		}
	};

	class Upgrade
	{
	public:
		Upgrade(unsigned const char* data, size_t size);
		~Upgrade(void);
		std::map<std::string, std::unique_ptr<Upgrade_table>> m_data;
		static const char* fileName();
		std::string Error;
		
		Upgrade_table* getUpgradeVo(int level);
		std::string int2String(int num);
	};
}

#endif  // __TABLES_Upgrade_H__
