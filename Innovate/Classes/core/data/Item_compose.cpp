#include "Item_compose.h"

#define KEY int2String(r->id)

namespace tables
{
	Item_compose::Item_compose(unsigned const char* data, size_t size)
	{
		InterDataCarrier carrier(data, size, fileName());
		Error = carrier.Error;
		if (!Error.empty())
		{
			return;
		}

		for (size_t i = 0; i < carrier.GetRecordCount(); i++)
		{
			Item_compose_table *r = new Item_compose_table();
			r->id = atoi(carrier.GetField(i, 0, "id").c_str());
			r->name = carrier.GetField(i, 1, "name", true);
			r->item_1 = atoi(carrier.GetField(i, 2, "item_1").c_str());
			r->item_num_1 = atoi(carrier.GetField(i, 3, "item_num_1").c_str());
			r->item_2 = atoi(carrier.GetField(i, 4, "item_2").c_str());
			r->item_num_2 = atoi(carrier.GetField(i, 5, "item_num_2").c_str());

			m_data[KEY] = *r;
		}
	}

	Item_compose::~Item_compose(void)
	{

	}

	Item_compose_table* Item_compose::getItem_composeVo(int id)
	{
		auto it = m_data.find(int2String(id));
		if (it == m_data.end())
		{
			return nullptr;
		} else {
			return &((*it).second);
		}
	}

	std::string Item_compose::int2String(int num)
	{
		std::stringstream ss;
		std::string str;
		ss<<num;
		ss>>str;
		return str;
	}

	const char* Item_compose::fileName()
	{
		return "Item_compose.csv";
	}
}