#ifndef __TABLES_Element_H__
#define __TABLES_Element_H__
#include "cocos2d.h"
#include "../../core/data/database/TableHelper.h"

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
			
		}
	};

	class Element
	{
	public:
		Element(unsigned const char* data, size_t size);
		~Element(void);
		std::map<std::string, Element_table> m_data;
		static const char* fileName();
		std::string Error;
		
		Element_table* getElementVo(int id);
		std::string int2String(int num);
	};
}

#endif  // __TABLES_Element_H__
