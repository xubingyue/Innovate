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

	std::string Role::int2String(int num)
	{
		std::stringstream ss;
		std::string str;
		ss<<num;
		ss>>str;
		return str;
	}

	const char* Role::fileName()
	{
		return "Role.csv";
	}
}