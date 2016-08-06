//////////////////////////////////////////////////////////////////////////
//进制转换
#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <stack>   //std::stack numconversion
using namespace  std;
//进制转换测试 10-exchange 输出固定4位“0001”
//int num = 12345;    int exchange = 36;
//NumConversion numConversion ; 
//vector<char> strNumtoExchage = numConversion.NumConversionMethod(num,exchange);

//用栈std::stack



//十进制转exchange进制 ，并且专为4位输出“0001”  其实貌似用vector也挺不错的，可以用size判断 
//大问题，字符串常量不可以修改?  *(str+i)只能做右值
class NumConversion
{
public:
	vector<char> NumConversionMethod(int inputNum , int exchang);
	
private:
	void printResult(vector<char> vecInput,int exchange);
	int num;

};
//十进制转exchange进制 ，并且专为4位输出“0001”  其实貌似用vector也挺不错的，可以用size判断 
//大问题，字符串常量不可以修改?  *(str+i)只能做右值 故用vector;
//params ： 输入十进制树inputNum ，exchange 转换成几进制数 
vector<char> NumConversion::NumConversionMethod(int inputNum , int exchang)
{
	this->num = inputNum;
	char str[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";        //字典
	vector<char> vecOutput;
	string exchangStr ="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	stack<int> mStack;
	while (inputNum!= 0 )   //此处需要先push再进行 修改inputNum
	{		 
		mStack.push(inputNum%exchang);
		inputNum = inputNum/exchang;
	}
	//貌似理解错误了，按照短除法，这类操作都是最低位肯定是满足的，反而是高位可能省去，即如果大于4位不需要考虑高位，直接取低4位就ok
	int n = mStack.size();
	if (mStack.size() <= 4)
	{
		for (int i = 0; i<4-n;i++ )                  //高位补0
		{
			vecOutput.push_back(exchangStr[0]);  
		}
		for (int i = 0;i < n ;i++)         //取低mStack.size()位
		{
			vecOutput.push_back(str[mStack.top()]);
			mStack.pop();
		}
	}//直接取低4位
	else
	{
		for (int i = 0 ; i<n-4;i++)    //去除高位  》4
		{
			mStack.pop();
		}
		for (int i = 0;i < 4 ;i++)
		{
			vecOutput.push_back( exchangStr[mStack.top()]);   //注意此处不能取高4位，而应该取低4位两个思路，1：mstack仅仅取前4个，2pop掉多余的
			mStack.pop();
		}
	}	
	printResult(vecOutput,exchang);
	return vecOutput;
};
void NumConversion::printResult(vector<char> vecInput,int exchange)
{
	//进制转换测试 10-exchange 输出固定4位“0001”
	cout<<"10进制数："<<num<<"转成"<<exchange<<"进制数，固定输出4位为："<<endl;
	for (int i = 0 ; i< 4 ; i++)
	{
		cout<<vecInput[i]<<" ";
	}
	cout<<endl;
}