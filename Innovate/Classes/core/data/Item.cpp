#include "Item.h"

#define KEY int2String(r->id)

namespace tables
{
	Item::Item(unsigned const char* data, size_t size)
	{
		InterDataCarrier carrier(data, size, fileName());
		Error = carrier.Error;
		if (!Error.empty())
		{
			return;
		}

		for (size_t i = 0; i < carrier.GetRecordCount(); i++)
		{
			Item_table *r = new Item_table();
			r->id = atoi(carrier.GetField(i, 0, "id").c_str());
			r->name = carrier.GetField(i, 1, "name", true);
			r->icon = carrier.GetField(i, 2, "icon", true);
			r->type = atoi(carrier.GetField(i, 3, "type").c_str());
			r->factor1 = atoi(carrier.GetField(i, 4, "factor1").c_str());
			r->factor2 = atoi(carrier.GetField(i, 5, "factor2").c_str());
			r->tips = carrier.GetField(i, 6, "tips", true);

			m_data[KEY] = *r;
		}
	}

	Item::~Item(void)
	{

	}

	Item_table* Item::getItemVo(int id)
	{
		auto it = m_data.find(int2String(id));
		if (it == m_data.end())
		{
			return nullptr;
		} else {
			return &((*it).second);
		}
	}

	std::string Item::int2String(int num)
	{
		std::stringstream ss;
		std::string str;
		ss<<num;
		ss>>str;
		return str;
	}

	const char* Item::fileName()
	{
		return "Item.csv";
	}
}