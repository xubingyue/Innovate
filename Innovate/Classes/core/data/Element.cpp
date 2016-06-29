#include "Element.h"

#define KEY int2String(r->id)

namespace tables
{
	Element::Element(unsigned const char* data, size_t size)
	{
		InterDataCarrier carrier(data, size, fileName());
		Error = carrier.Error;
		if (!Error.empty())
		{
			return;
		}

		for (size_t i = 0; i < carrier.GetRecordCount(); i++)
		{
			std::unique_ptr<Element_table> r(new Element_table);
			r->id = atoi(carrier.GetField(i, 0, "id").c_str());
			r->name = carrier.GetField(i, 1, "name", true);
			r->type = atoi(carrier.GetField(i, 2, "type").c_str());
			r->level = atoi(carrier.GetField(i, 3, "level").c_str());
			r->element1 = atoi(carrier.GetField(i, 4, "element1").c_str());
			r->num1 = atoi(carrier.GetField(i, 5, "num1").c_str());
			r->element2 = atoi(carrier.GetField(i, 6, "element2").c_str());
			r->num2 = atoi(carrier.GetField(i, 7, "num2").c_str());
			r->quality = atoi(carrier.GetField(i, 8, "quality").c_str());
			r->icon = carrier.GetField(i, 9, "icon", true);

			m_data[KEY] = std::move(r);
		}
	}

	Element::~Element(void)
	{

	}

	Element_table* Element::getElementVo(int id)
	{
		auto it = m_data.find(int2String(id));
		if (it == m_data.end())
		{
			return nullptr;
		} else {
			return &(*(*it).second);
		}
	}

	std::string Element::int2String(int num)
	{
		std::stringstream ss;
		std::string str;
		ss<<num;
		ss>>str;
		return str;
	}

	const char* Element::fileName()
	{
		return "Element.csv";
	}
}