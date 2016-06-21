#include "Raid_map.h"

#define KEY int2String(r->id)

namespace tables
{
	Raid_map::Raid_map(unsigned const char* data, size_t size)
	{
		InterDataCarrier carrier(data, size, fileName());
		Error = carrier.Error;
		if (!Error.empty())
		{
			return;
		}

		for (size_t i = 0; i < carrier.GetRecordCount(); i++)
		{
			std::unique_ptr<Raid_map_table> r(new Raid_map_table);
			r->id = atoi(carrier.GetField(i, 0, "id").c_str());
			r->map_name = carrier.GetField(i, 1, "map_name", true).c_str();
			r->minLevel = atoi(carrier.GetField(i, 2, "minLevel").c_str());
			r->maxLevel = atoi(carrier.GetField(i, 3, "maxLevel").c_str());

			m_data[KEY] = std::move(r);
		}
	}

	Raid_map::~Raid_map(void)
	{

	}

	Raid_map_table* Raid_map::getRaid_mapVo(int id)
	{
		auto it = m_data.find(int2String(id));
		if (it == m_data.end())
		{
			return nullptr;
		} else {
			return &(*(*it).second);
		}
	}

	const char* Raid_map::int2String(int num)
	{
		std::stringstream ss;
		std::string str;
		ss<<num;
		ss>>str;
		return str.c_str();
	}

	const char* Raid_map::fileName()
	{
		return "Raid_map.csv";
	}
}