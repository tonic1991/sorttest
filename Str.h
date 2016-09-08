#pragma once
#include<iostream>

//������а�����ָ�����Ա����m_data�������а���ָ�����Ա����ʱ��һ��Ҫ�����俽�����캯������ֵ��������������
class MyString
{
public:
	MyString(const char *str = NULL); // ��ͨ���캯�� 
	MyString(const MyString &other); // �������캯�� 
	~MyString(void); // �������� 
	MyString & operator =(const MyString &other); // ��ֵ���� 
private:
	char *m_data; // ���ڱ����ַ��� 
};


//��ͨ���캯���� (1) ����ΪNULL�ͷ�NULL
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

//�������캯�� ��1��������룬��2������ռ�
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

// �����������ͷ��ڴ�
MyString::~MyString()
{
	delete m_data;
}

//���ظ�ֵ�� ��1���ж��Ƿ����� (2)���ͷſռ� ��3������ռ� ��4�������ڴ�
MyString& MyString::operator= (const MyString & other)
{
	if (this == &other) 
		return *this;   //  �ж��Ƿ�����
	
	delete m_data;    //ʩ�������ڴ棻

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