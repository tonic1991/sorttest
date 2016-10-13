#ifndef _ARRAYINITTEST_H_
#define _ARRAYINITTEST_H_
#pragma once
#include <stdio.h>
#include <iostream>
using namespace std;
//字符串数组
void stringArray()
{
	printf(" \nTest String Array!!!\n ");
	
	char *kkk = "aaa";

	printf("\n%s \n", kkk);

	char *a[4] = {"aa","bbb","cccc","asd" };
	printf("sizeof =  %d   \n", sizeof(a));      // = 12???
	printf("a = %x  \n", a);
	printf("a = %x  \n", a+1);

		
	int arr[5] = { 1,2,3 };
	cout << endl << "cout << " << a << endl;
	printf("\nsizeof = %d \n", sizeof(arr));
	printf("\narr = %d \n", arr);

	char ka[2][2] = { 1,2 };

	enum EMM
	{
		A,
		B,
		C=100,
		D,
		E = 1,
		F
	}EEMM;

	printf("%d \n", A);
	printf("%d \n", B);
	printf("%d \n", C);
	printf("%d \n", D);
	printf("%d \n", E);
	printf("%d \n", F);

	char* str = "\x12\x34\x56\x78";
	printf("\x12\x34\x56\x78 %x \n" ,*(int*)str);

	char str1[] = { 0x56, 0x78, 0x12, 0x34 };
	printf("%x", *(int*)str1);
}










void TestArrayInit()
{
	//测试C++ ,数组 以及初始化相关 
	stringArray();



}










#endif // !_ARRAYINITTEST_H_


