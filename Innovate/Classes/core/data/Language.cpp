#include "Language.h"

#define KEY int2String(r->id)

namespace tables
{
	Language::Language(unsigned const char* data, size_t size)
	{
		InterDataCarrier carrier(data, size, fileName());
		Error = carrier.Error;
		if (!Error.empty())
		{
			return;
		}

		for (size_t i = 0; i < carrier.GetRecordCount(); i++)
		{
			std::unique_ptr<Language_table> r(new Language_table);
			r->id = atoi(carrier.GetField(i, 0, "id").c_str());
			r->zh_txt = carrier.GetField(i, 1, "zh_txt", true).c_str();
			r->en_txt = carrier.GetField(i, 2, "en_txt", true).c_str();

			m_data[KEY] = std::move(r);
		}
	}

	Language::~Language(void)
	{

	}

	Language_table* Language::getLanguageVo(int id)
	{
		auto it = m_data.find(int2String(id));
		if (it == m_data.end())
		{
			return nullptr;
		} else {
			return &(*(*it).second);
		}
	}

	const char* Language::int2String(int num)
	{
		std::stringstream ss;
		std::string str;
		ss<<num;
		ss>>str;
		return str.c_str();
	}

	const char* Language::fileName()
	{
		return "Language.csv";
	}
}