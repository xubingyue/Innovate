#include "Config.h"

#define KEY int2String(r->id)

namespace tables
{
	Config::Config(unsigned const char* data, size_t size)
	{
		InterDataCarrier carrier(data, size, fileName());
		Error = carrier.Error;
		if (!Error.empty())
		{
			return;
		}

		for (size_t i = 0; i < carrier.GetRecordCount(); i++)
		{
			Config_table *r = new Config_table();
			r->id = atoi(carrier.GetField(i, 0, "id").c_str());
			r->data = carrier.GetField(i, 1, "data", true);

			m_data[KEY] = *r;
		}
	}

	Config::~Config(void)
	{

	}

	Config_table* Config::getConfigVo(int id)
	{
		auto it = m_data.find(int2String(id));
		if (it == m_data.end())
		{
			return nullptr;
		} else {
			return &((*it).second);
		}
	}

	std::string Config::int2String(int num)
	{
		std::stringstream ss;
		std::string str;
		ss<<num;
		ss>>str;
		return str;
	}

	const char* Config::fileName()
	{
		return "Config.csv";
	}
}