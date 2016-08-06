#pragma once
#include <iostream>
#include <vector>
#include <string>

using namespace  std;


struct LNode
{
	int data;
	LNode *next;
	LNode():next(NULL){}
	LNode(int x):data(x),next(NULL){}
};


//单链表测试2
class LinkList
{
public:
	LinkList();

	bool display(LNode* linkList);


	bool createLinkList(LNode* linkList,int n ,int i);

	bool deleteLinkList(LNode* linkList , int x);

	bool MergeLinkList(LNode* La,LNode* Lb, LNode* Lc);
};
bool TestLinkList()
{
	LNode* La = new LNode;
	LinkList linklistIns;
	linklistIns.createLinkList(La, 8 , 2);

	linklistIns.deleteLinkList(La,6);

	LNode* Lb = new LNode;
	LNode* Lc = new LNode;

	linklistIns.createLinkList(Lb,5,3);
	
	linklistIns.MergeLinkList(La,Lb,Lc);

	return true;
}

LinkList::LinkList()
{
	printf("LinkList Test please TestLinkList() ! \r\n\t"); 
}


bool LinkList::display(LNode* linkList)
{
	if (linkList==NULL)
	{
		printf("display an empty list!\r\n\t");
	}
	printf("display an  list:  ! ");
	LNode *p ;
	p = linkList->next;
	while (p!=NULL)
	{
		cout<<p->data<<" ";
		p =p->next;	
	} 
	cout<<endl;

	return true;
}

//建立带头结点的linklist  借用两个head tail
bool LinkList::createLinkList(LNode* linkList ,int n ,int i )
{
	
	cout<<"input the length of linkList"<<endl;

	//int n = 8;
		//int n;
	//cin >> n;

	//linkList = new LNode;
	linkList->next =NULL;
	LNode *head,*tail;  //
	head = linkList;
	
	//int i = 2;
	while (n>0)
	{
		
		printf("cin %d node : " ,n);
		tail = new LNode;
		//cin>>tail->data;
		tail->data = i*2;

		tail->next=NULL;
		//insert in tail; cout in orderl
		head->next = tail;
		head = tail;
		n--;
		i++;
	}
	display(linkList);
		
	return true;
}

bool LinkList::deleteLinkList(LNode* linkList , int x)
{
	if (linkList==NULL)
	{
		printf("linklist is null \r\n\t");
		return false;
	}
	LNode * p ,*q;
	p = linkList;
	while (p->next==NULL&&p->next->data!=x)
	{
		p = p->next;
	}
	if (p->next!=NULL)
	{
		q = p->next;
		p->next=q->next;
		delete q;
		printf("delete %d done! \r\n\t",x);
		
	}else
	{
		printf("without %d",x);
	}
	return true;
}

bool LinkList::MergeLinkList(LNode* La,LNode* Lb,LNode* Lc)
{
	if (La==NULL||Lb==NULL)
	{
		printf("List is NUll;Merge errot");
		return false;
	}
	LNode *pa = La , *pb = Lb;
	LNode *head,*tail;
	head = Lc;
	while(pa->next!=NULL && pb->next!=NULL)
	{
		if (pa->next->data<=pb->next->data)
		{
			tail=new LNode(pa->next->data);
			head->next = tail;
			head= tail;
			pa=pa->next;
		}else
		{
			tail=new LNode(pb->next->data);
			head->next = tail;
			head= tail;
			pb=pb->next;
		}
	}
	//head = Lc;
	while (pa->next!=NULL)
	{
		tail=new LNode(pa->next->data);
		head->next = tail;
		head  = tail;
		pa=pa->next;
	}
	//head = Lc;
	while (pb->next!=NULL)
	{
		tail=new LNode(pb->next->data);
		head->next =tail;
		head = tail;
		pb=pb->next;
	}
	display(Lc);
	return true;
}






//单链表相关类
class LinkListTestClass
{
public:
	//struct LNode
	//{
	//	int data;
	//	LNode *next;
	//};
	//建立带头结点的linklist  借用两个head tail
	void CreateList(LNode* &linklist)
	{
		int n;
		cout<<"input the length of linkList"<<endl;
		cin >> n;

		linklist = new LNode;
		linklist->next = NULL;
		LNode *head, *tail;
		head = linklist;
		while (n>0)
		{
			cout<<"cin a node"<<endl;
			tail = new LNode;
			cin>>tail->data;
			//头插法，建立顺序与输入顺序相反
			//p->next = linkList->next;  //NULL
			//linkList->next =p;
			//尾插法  顺序输出
			tail->next = NULL;
			head->next = tail;
			head = tail;
			//此处可以参考leetcode 上第二题的思路（其实是一样的） 
			n--;
		}
		PrintList(linklist);
		 //不需要删除，此处删除了linklist 也没了
	}
	
	
	////输出带头结点的linklist
	void PrintList(LNode* linklist)
	{
		if(linklist == NULL)
		{
			cout<<"empty list"<<endl;
			return ;
		}
		LNode *p ;
		p = linklist->next;
		while (p!=NULL)
		{
			cout<<p->data<<" ";
			p =p->next;	
		} 
		cout<<endl;
	}
	
	//对链表的删除：复制改节点出来，释放 
	//此利用了两个LNode *p *q *r 来辅助
	void DeleteRepeat(LNode* &linklist)   //用&的原因？ 怕不会改变即传引用，（？是不是可以传**指针的指针？）
		//传**的用法？ 如何调用？
	{
		LNode *p, *q ,*r;
		if ( linklist->next == NULL)
		{
			cout<<"空表"<<endl;
			return ;
		}
		p = linklist->next;
		while (NULL != p->next)
		{
			q = p;  //复制当前节点
			while (q->next)
			{
				if (q->next->data == p->data)
				{
					r = q->next;    //重复节点
					q->next = q->next->next; //删除R;
					delete r;
				}
				else
				{
					q = q->next ;  //向后移动
				}

			}
			p = p->next;

		}
		PrintList(linklist);
	}

private:
	
};



class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		vector<int> reVector;
		for(size_t i = 0 ;  i <nums.size() ;i++   )
		{
			for (size_t j= 0 ; j<nums.size() ;j++)
			{
				if (  nums[i]+nums[j]==target && i < j  )
				{
					  reVector.push_back(i);
				      reVector.push_back(j);
				}
			}
		}
	}
};





