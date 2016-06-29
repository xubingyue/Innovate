#include "Upgrade.h"

#define KEY int2String(r->level)

namespace tables
{
	Upgrade::Upgrade(unsigned const char* data, size_t size)
	{
		InterDataCarrier carrier(data, size, fileName());
		Error = carrier.Error;
		if (!Error.empty())
		{
			return;
		}

		for (size_t i = 0; i < carrier.GetRecordCount(); i++)
		{
			std::unique_ptr<Upgrade_table> r(new Upgrade_table);
			r->level = atoi(carrier.GetField(i, 0, "level").c_str());
			r->level_next = atoi(carrier.GetField(i, 1, "level_next").c_str());
			r->exp_get = atoi(carrier.GetField(i, 2, "exp_get").c_str());
			r->step = atoi(carrier.GetField(i, 3, "step").c_str());
			r->elf_num = atoi(carrier.GetField(i, 4, "elf_num").c_str());

			m_data[KEY] = std::move(r);
		}
	}

	Upgrade::~Upgrade(void)
	{

	}

	Upgrade_table* Upgrade::getUpgradeVo(int level)
	{
		auto it = m_data.find(int2String(level));
		if (it == m_data.end())
		{
			return nullptr;
		} else {
			return &(*(*it).second);
		}
	}

	std::string Upgrade::int2String(int num)
	{
		std::stringstream ss;
		std::string str;
		ss<<num;
		ss>>str;
		return str;
	}

	const char* Upgrade::fileName()
	{
		return "Upgrade.csv";
	}
}