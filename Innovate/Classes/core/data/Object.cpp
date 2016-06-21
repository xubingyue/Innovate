#include "Object.h"

#define KEY int2String(r->id)

namespace tables
{
	Object::Object(unsigned const char* data, size_t size)
	{
		InterDataCarrier carrier(data, size, fileName());
		Error = carrier.Error;
		if (!Error.empty())
		{
			return;
		}

		for (size_t i = 0; i < carrier.GetRecordCount(); i++)
		{
			std::unique_ptr<Object_table> r(new Object_table);
			r->id = atoi(carrier.GetField(i, 0, "id").c_str());
			r->name = carrier.GetField(i, 1, "name", true).c_str();
			r->type = atoi(carrier.GetField(i, 2, "type").c_str());
			r->value = atoi(carrier.GetField(i, 3, "value").c_str());
			r->res = carrier.GetField(i, 4, "res", true).c_str();

			m_data[KEY] = std::move(r);
		}
	}

	Object::~Object(void)
	{

	}

	Object_table* Object::getObjectVo(int id)
	{
		auto it = m_data.find(int2String(id));
		if (it == m_data.end())
		{
			return nullptr;
		} else {
			return &(*(*it).second);
		}
	}

	const char* Object::int2String(int num)
	{
		std::stringstream ss;
		std::string str;
		ss<<num;
		ss>>str;
		return str.c_str();
	}

	const char* Object::fileName()
	{
		return "Object.csv";
	}
}