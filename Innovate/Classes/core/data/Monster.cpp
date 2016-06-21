#include "Monster.h"

#define KEY int2String(r->id)

namespace tables
{
	Monster::Monster(unsigned const char* data, size_t size)
	{
		InterDataCarrier carrier(data, size, fileName());
		Error = carrier.Error;
		if (!Error.empty())
		{
			return;
		}

		for (size_t i = 0; i < carrier.GetRecordCount(); i++)
		{
			std::unique_ptr<Monster_table> r(new Monster_table);
			r->id = atoi(carrier.GetField(i, 0, "id").c_str());
			r->name = carrier.GetField(i, 1, "name", true).c_str();
			r->diropId = atoi(carrier.GetField(i, 2, "diropId").c_str());
			r->hp = atoi(carrier.GetField(i, 3, "hp").c_str());
			r->attack = atoi(carrier.GetField(i, 4, "attack").c_str());
			r->velocity = atof(carrier.GetField(i, 5, "velocity").c_str());
			r->character_in = carrier.GetField(i, 6, "character_in", true).c_str();
			r->sceneID = atoi(carrier.GetField(i, 7, "sceneID").c_str());
			r->minLevel = atoi(carrier.GetField(i, 8, "minLevel").c_str());
			r->maxLevel = atoi(carrier.GetField(i, 9, "maxLevel").c_str());
			r->raidID = atoi(carrier.GetField(i, 10, "raidID").c_str());
			r->monsterPoint = atoi(carrier.GetField(i, 11, "monsterPoint").c_str());

			m_data[KEY] = std::move(r);
		}
	}

	Monster::~Monster(void)
	{

	}

	Monster_table* Monster::getMonsterVo(int id)
	{
		auto it = m_data.find(int2String(id));
		if (it == m_data.end())
		{
			return nullptr;
		} else {
			return &(*(*it).second);
		}
	}

	const char* Monster::int2String(int num)
	{
		std::stringstream ss;
		std::string str;
		ss<<num;
		ss>>str;
		return str.c_str();
	}

	const char* Monster::fileName()
	{
		return "Monster.csv";
	}
}