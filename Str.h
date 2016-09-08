#pragma once
#include<iostream>

//这个类中包括了指针类成员变量m_data，当类中包括指针类成员变量时，一定要重载其拷贝构造函数、赋值函数和析构函数
class MyString
{
public:
	MyString(const char *str = NULL); // 普通构造函数 
	MyString(const MyString &other); // 拷贝构造函数 
	~MyString(void); // 析构函数 
	MyString & operator =(const MyString &other); // 赋值函数 
private:
	char *m_data; // 用于保存字符串 
};


//普通构造函数， (1) 考虑为NULL和非NULL
MyString::MyString(const char *str)
{
	if (str == NULL)
	{
		m_data = new char[1];
		*m_data = '\0';
	}
	else
	{
		int length = strlen(str) + 1; 
		m_data = new char[length];
		memcpy(m_data, str, length);
	}
}

//拷贝构造函数 （1）检查输入，（2）分配空间
MyString::MyString(const MyString &other)
{
	if (other.m_data == NULL)
	{
		m_data = new char[1];
		*m_data = '\0';
	}
	else
	{
		int len = strlen(other.m_data) + 1;
		m_data = new char[len];
		strcpy(m_data, other.m_data);
	}
}

// 析构函数，释放内存
MyString::~MyString()
{
	delete m_data;
}

//重载赋值。 （1）判断是否自身 (2)先释放空间 （3）申请空间 （4）复制内存
MyString& MyString::operator= (const MyString & other)
{
	if (this == &other) 
		return *this;   //  判断是否自身；
	
	delete m_data;    //施放已有内存；

	if (other.m_data == NULL)
	{
		m_data = new char[1];
		m_data = '\0';
	}
	else
	{
		memcpy(m_data, other.m_data, strlen(other.m_data) + 1);
	}
	return *this;
}