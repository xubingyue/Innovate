#include "Drop.h"

#define KEY int2String(r->id)

namespace tables
{
	Drop::Drop(unsigned const char* data, size_t size)
	{
		InterDataCarrier carrier(data, size, fileName());
		Error = carrier.Error;
		if (!Error.empty())
		{
			return;
		}

		for (size_t i = 0; i < carrier.GetRecordCount(); i++)
		{
			std::unique_ptr<Drop_table> r(new Drop_table);
			r->id = atoi(carrier.GetField(i, 0, "id").c_str());
			r->num = atoi(carrier.GetField(i, 1, "num").c_str());
			r->dropID0 = atoi(carrier.GetField(i, 2, "dropID0").c_str());
			r->weight0 = atof(carrier.GetField(i, 3, "weight0").c_str());
			r->dropID1 = atoi(carrier.GetField(i, 4, "dropID1").c_str());
			r->weight1 = atof(carrier.GetField(i, 5, "weight1").c_str());
			r->dropID2 = atoi(carrier.GetField(i, 6, "dropID2").c_str());
			r->weight2 = atof(carrier.GetField(i, 7, "weight2").c_str());
			r->dropID3 = atoi(carrier.GetField(i, 8, "dropID3").c_str());
			r->weight3 = atof(carrier.GetField(i, 9, "weight3").c_str());

			m_data[KEY] = std::move(r);
		}
	}

	Drop::~Drop(void)
	{

	}

	Drop_table* Drop::getDropVo(int id)
	{
		auto it = m_data.find(int2String(id));
		if (it == m_data.end())
		{
			return nullptr;
		} else {
			return &(*(*it).second);
		}
	}

	std::string Drop::int2String(int num)
	{
		std::stringstream ss;
		std::string str;
		ss<<num;
		ss>>str;
		return str;
	}

	const char* Drop::fileName()
	{
		return "Drop.csv";
	}
}