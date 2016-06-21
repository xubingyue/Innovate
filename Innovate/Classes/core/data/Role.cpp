#include "Role.h"

#define KEY int2String(r->id)

namespace tables
{
	Role::Role(unsigned const char* data, size_t size)
	{
		InterDataCarrier carrier(data, size, fileName());
		Error = carrier.Error;
		if (!Error.empty())
		{
			return;
		}

		for (size_t i = 0; i < carrier.GetRecordCount(); i++)
		{
			std::unique_ptr<Role_table> r(new Role_table);
			r->id = atoi(carrier.GetField(i, 0, "id").c_str());
			r->name = carrier.GetField(i, 1, "name", true).c_str();
			r->hp = atoi(carrier.GetField(i, 2, "hp").c_str());
			r->attack = atoi(carrier.GetField(i, 3, "attack").c_str());
			r->velocity = atof(carrier.GetField(i, 4, "velocity").c_str());
			r->character_in = carrier.GetField(i, 5, "character_in", true).c_str();
			r->ski1 = atoi(carrier.GetField(i, 6, "ski1").c_str());
			r->darkAttack = atoi(carrier.GetField(i, 7, "darkAttack").c_str());
			r->darkResist = atoi(carrier.GetField(i, 8, "darkResist").c_str());
			r->fireAttack = atoi(carrier.GetField(i, 9, "fireAttack").c_str());
			r->fireResist = atoi(carrier.GetField(i, 10, "fireResist").c_str());
			r->windAttack = atoi(carrier.GetField(i, 11, "windAttack").c_str());
			r->windResist = atoi(carrier.GetField(i, 12, "windResist").c_str());
			r->soilAttack = atoi(carrier.GetField(i, 13, "soilAttack").c_str());
			r->soilResist = atoi(carrier.GetField(i, 14, "soilResist").c_str());
			r->recover = atoi(carrier.GetField(i, 15, "recover").c_str());
			r->absorb = atoi(carrier.GetField(i, 16, "absorb").c_str());

			m_data[KEY] = std::move(r);
		}
	}

	Role::~Role(void)
	{

	}

	Role_table* Role::getRoleVo(int id)
	{
		auto it = m_data.find(int2String(id));
		if (it == m_data.end())
		{
			return nullptr;
		} else {
			return &(*(*it).second);
		}
	}

	const char* Role::int2String(int num)
	{
		std::stringstream ss;
		std::string str;
		ss<<num;
		ss>>str;
		return str.c_str();
	}

	const char* Role::fileName()
	{
		return "Role.csv";
	}
}