#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<stdio.h>
#include <string>

#include "LinkListTest.h"  //���������
#include "NumConversion.h" //����ת��
#include "TrieTree.h"  //�ֵ�����ʵ��
#include "SortClass.h"   //������
#include "Sword.h"      //��ָoffer��ϰ

#include "SqList.h"//˳���

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
   //cout<<sortClass.dichotomy(b,8,4)<<endl;   //���ֲ���
  // sortClass.ShellSort(a,8);

   //sortClass.SelectionSort(a,8);

  // sortClass.BubbleSort(a,8);  //ԭʼð��
  
  // sortClass.BubbleSort_pos(a,8);  


//   sortClass.QuickSort(a,0,7);

  // sortClass.MergeSort(a,n);  //�鲢����


   //LinkList����
   //LinkListTestClass linkListClass;
   //LNode *linklist;
   //linkListClass.CreateList(linklist);
   //linkListClass.DeleteRepeat(linklist);
   //delete linklist;

   //TestLinkList();   //����������



   //** ���ԣ�

   //����ת������ 10-exchange ����̶�4λ��0001��
   //int num = 12345;    int exchange = 36;
   //NumConversion numConversion ; 
   //vector<char> strNumtoExchage = numConversion.NumConversionMethod(num,exchange);
  
   ////trie�����ԣ�
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
   //swordto.Print1ToMaxOfDigits(3); //��ӡ��1��Nλ��
   //swordto.YangHuiTriangle(5);
   //swordto.MallocText();// ����ӡ�ڴ�


   //����˳���
   //TestSqlist();

   // ---testStack
   // testStack();

   //---testQueue
   //TestQueue();  ���Զ���
   TestCircularQueue();   //����ѭ������

   system("pause");

}


