#ifndef __TABLES_Element_H__
#define __TABLES_Element_H__
#include "cocos2d.h"
#include "TableHelper.h"

USING_NS_CC;

namespace tables
{
	class Element_table 
	{
	public:
		//id
		int id;
		//名字
		std::string name;
		//类型
		int type;
		//激活等级
		int level;
		//需求元素1
		int element1;
		//元素1个数
		int num1;
		//需求元素2
		int element2;
		//元素2个数
		int num2;
		//品质
		int quality;
		//形象
		std::string icon;
		Element_table()
		{
			memset(&id, 0, sizeof(id));
			memset(&name, 0, sizeof(name));
			memset(&type, 0, sizeof(type));
			memset(&level, 0, sizeof(level));
			memset(&element1, 0, sizeof(element1));
			memset(&num1, 0, sizeof(num1));
			memset(&element2, 0, sizeof(element2));
			memset(&num2, 0, sizeof(num2));
			memset(&quality, 0, sizeof(quality));
			memset(&icon, 0, sizeof(icon));
		}
	};

	class Element
	{
	public:
		Element(unsigned const char* data, size_t size);
		~Element(void);
		std::map<std::string, std::unique_ptr<Element_table>> m_data;
		static const char* fileName();
		std::string Error;
		
		Element_table* getElementVo(int id);
		std::string int2String(int num);
	};
}

#endif  // __TABLES_Element_H__
