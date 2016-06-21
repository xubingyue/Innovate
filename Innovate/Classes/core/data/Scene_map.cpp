#include "Scene_map.h"

#define KEY int2String(r->id)

namespace tables
{
	Scene_map::Scene_map(unsigned const char* data, size_t size)
	{
		InterDataCarrier carrier(data, size, fileName());
		Error = carrier.Error;
		if (!Error.empty())
		{
			return;
		}

		for (size_t i = 0; i < carrier.GetRecordCount(); i++)
		{
			std::unique_ptr<Scene_map_table> r(new Scene_map_table);
			r->id = atoi(carrier.GetField(i, 0, "id").c_str());
			r->map_name = carrier.GetField(i, 1, "map_name", true).c_str();
			r->minLevel = atoi(carrier.GetField(i, 2, "minLevel").c_str());
			r->maxLevel = atoi(carrier.GetField(i, 3, "maxLevel").c_str());
			r->probability = atof(carrier.GetField(i, 4, "probability").c_str());
			r->probability_grow = atof(carrier.GetField(i, 5, "probability_grow").c_str());
			r->attenuation = atof(carrier.GetField(i, 6, "attenuation").c_str());

			m_data[KEY] = std::move(r);
		}
	}

	Scene_map::~Scene_map(void)
	{

	}

	Scene_map_table* Scene_map::getScene_mapVo(int id)
	{
		auto it = m_data.find(int2String(id));
		if (it == m_data.end())
		{
			return nullptr;
		} else {
			return &(*(*it).second);
		}
	}

	const char* Scene_map::int2String(int num)
	{
		std::stringstream ss;
		std::string str;
		ss<<num;
		ss>>str;
		return str.c_str();
	}

	const char* Scene_map::fileName()
	{
		return "Scene_map.csv";
	}
}