#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<stdio.h>
#include <string>

#include "LinkListTest.h"  //链表相关类
#include "NumConversion.h" //进制转换
#include "TrieTree.h"  //字典树的实现
#include "SortClass.h"   //排序类
#include "Sword.h"      //剑指offer练习

#include "SqList.h"//顺序表

#include "StackTest.h" //stack

#include "QueueTest.h" //queue
using namespace std;


void func(char ** str , int b[], int *c)
{
	//  a =  1;
	  b[1] = b[1] + 3 ;
	  c = c + 1;
	  int num = 1000;
	  *str = (char *)malloc(num);
	  *str = "world";
}


void main()
{
	SortClass sortClass;
   const int n = 8;
   int a[n] = {49,38,65,97,76,13,27,49}; 
  
  //sortClass.InsertSort(a,8);
   //int b[n] = {1,2,3,4,5,6,7,8};
   //cout<<sortClass.dichotomy(b,8,4)<<endl;   //二分查找
  // sortClass.ShellSort(a,8);

   //sortClass.SelectionSort(a,8);

  // sortClass.BubbleSort(a,8);  //原始冒泡
  
  // sortClass.BubbleSort_pos(a,8);  


//   sortClass.QuickSort(a,0,7);

  // sortClass.MergeSort(a,n);  //归并排序


   //LinkList测试
   //LinkListTestClass linkListClass;
   //LNode *linklist;
   //linkListClass.CreateList(linklist);
   //linkListClass.DeleteRepeat(linklist);
   //delete linklist;

   //TestLinkList();   //单独测试类



   //** 测试：

   //进制转换测试 10-exchange 输出固定4位“0001”
   //int num = 12345;    int exchange = 36;
   //NumConversion numConversion ; 
   //vector<char> strNumtoExchage = numConversion.NumConversionMethod(num,exchange);
  
   ////trie树测试：
   //TrieTree* trieTree = new TrieTree();
   //trieTree->CreatTrieTree("CCTV1");
   //trieTree->CreatTrieTree("C1TV1");
   //trieTree->CreatTrieTree("C2TV1");
   //trieTree->CreatTrieTree("C1AA1");
   //trieTree->CreatTrieTree("HNTV1");
   //trieTree->CreatTrieTree("HNTV3");
   //trieTree->FindInTrieTree("A");
   //trieTree->PrintPre("C");
  
   SwordTo swordto;
   //swordto.Print1ToMaxOfDigits(3); //打印从1到N位数
   //swordto.YangHuiTriangle(5);
   //swordto.MallocText();// 最大打印内存


   //测试顺序表
   //TestSqlist();

   // ---testStack
   // testStack();

   //---testQueue
   //TestQueue();  测试队列
   TestCircularQueue();   //测试循环队列

   system("pause");

}


