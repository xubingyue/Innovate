#include "Stage.h"

#define KEY int2String(r->id)

namespace tables
{
	Stage::Stage(unsigned const char* data, size_t size)
	{
		InterDataCarrier carrier(data, size, fileName());
		Error = carrier.Error;
		if (!Error.empty())
		{
			return;
		}

		for (size_t i = 0; i < carrier.GetRecordCount(); i++)
		{
			Stage_table *r = new Stage_table();
			r->id = atoi(carrier.GetField(i, 0, "id").c_str());
			r->data = carrier.GetField(i, 1, "data", true);

			m_data[KEY] = *r;
		}
	}

	Stage::~Stage(void)
	{

	}

	Stage_table* Stage::getStageVo(int id)
	{
		auto it = m_data.find(int2String(id));
		if (it == m_data.end())
		{
			return nullptr;
		} else {
			return &((*it).second);
		}
	}

	std::string Stage::int2String(int num)
	{
		std::stringstream ss;
		std::string str;
		ss<<num;
		ss>>str;
		return str;
	}

	const char* Stage::fileName()
	{
		return "Stage.csv";
	}
}