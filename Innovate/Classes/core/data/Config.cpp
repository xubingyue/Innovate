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
			std::unique_ptr<Config_table> r(new Config_table);
			r->id = atoi(carrier.GetField(i, 0, "id").c_str());
			r->data = carrier.GetField(i, 1, "data", true).c_str();

			m_data[KEY] = std::move(r);
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
			return &(*(*it).second);
		}
	}

	const char* Config::int2String(int num)
	{
		std::stringstream ss;
		std::string str;
		ss<<num;
		ss>>str;
		return str.c_str();
	}

	const char* Config::fileName()
	{
		return "Config.csv";
	}
}