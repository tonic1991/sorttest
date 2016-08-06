//////////////////////////////////////////////////////////////////////////
//����ת��
#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <stack>   //std::stack numconversion
using namespace  std;
//����ת������ 10-exchange ����̶�4λ��0001��
//int num = 12345;    int exchange = 36;
//NumConversion numConversion ; 
//vector<char> strNumtoExchage = numConversion.NumConversionMethod(num,exchange);

//��ջstd::stack



//ʮ����תexchange���� ������רΪ4λ�����0001��  ��ʵò����vectorҲͦ����ģ�������size�ж� 
//�����⣬�ַ��������������޸�?  *(str+i)ֻ������ֵ
class NumConversion
{
public:
	vector<char> NumConversionMethod(int inputNum , int exchang);
	
private:
	void printResult(vector<char> vecInput,int exchange);
	int num;

};
//ʮ����תexchange���� ������רΪ4λ�����0001��  ��ʵò����vectorҲͦ����ģ�������size�ж� 
//�����⣬�ַ��������������޸�?  *(str+i)ֻ������ֵ ����vector;
//params �� ����ʮ������inputNum ��exchange ת���ɼ������� 
vector<char> NumConversion::NumConversionMethod(int inputNum , int exchang)
{
	this->num = inputNum;
	char str[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";        //�ֵ�
	vector<char> vecOutput;
	string exchangStr ="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	stack<int> mStack;
	while (inputNum!= 0 )   //�˴���Ҫ��push�ٽ��� �޸�inputNum
	{		 
		mStack.push(inputNum%exchang);
		inputNum = inputNum/exchang;
	}
	//ò���������ˣ����ն̳�������������������λ�϶�������ģ������Ǹ�λ����ʡȥ�����������4λ����Ҫ���Ǹ�λ��ֱ��ȡ��4λ��ok
	int n = mStack.size();
	if (mStack.size() <= 4)
	{
		for (int i = 0; i<4-n;i++ )                  //��λ��0
		{
			vecOutput.push_back(exchangStr[0]);  
		}
		for (int i = 0;i < n ;i++)         //ȡ��mStack.size()λ
		{
			vecOutput.push_back(str[mStack.top()]);
			mStack.pop();
		}
	}//ֱ��ȡ��4λ
	else
	{
		for (int i = 0 ; i<n-4;i++)    //ȥ����λ  ��4
		{
			mStack.pop();
		}
		for (int i = 0;i < 4 ;i++)
		{
			vecOutput.push_back( exchangStr[mStack.top()]);   //ע��˴�����ȡ��4λ����Ӧ��ȡ��4λ����˼·��1��mstack����ȡǰ4����2pop�������
			mStack.pop();
		}
	}	
	printResult(vecOutput,exchang);
	return vecOutput;
};
void NumConversion::printResult(vector<char> vecInput,int exchange)
{
	//����ת������ 10-exchange ����̶�4λ��0001��
	cout<<"10��������"<<num<<"ת��"<<exchange<<"���������̶����4λΪ��"<<endl;
	for (int i = 0 ; i< 4 ; i++)
	{
		cout<<vecInput[i]<<" ";
	}
	cout<<endl;
}