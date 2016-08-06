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


//���������2
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

//������ͷ����linklist  ��������head tail
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






//�����������
class LinkListTestClass
{
public:
	//struct LNode
	//{
	//	int data;
	//	LNode *next;
	//};
	//������ͷ����linklist  ��������head tail
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
			//ͷ�巨������˳��������˳���෴
			//p->next = linkList->next;  //NULL
			//linkList->next =p;
			//β�巨  ˳�����
			tail->next = NULL;
			head->next = tail;
			head = tail;
			//�˴����Բο�leetcode �ϵڶ����˼·����ʵ��һ���ģ� 
			n--;
		}
		PrintList(linklist);
		 //����Ҫɾ�����˴�ɾ����linklist Ҳû��
	}
	
	
	////�����ͷ����linklist
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
	
	//�������ɾ�������ƸĽڵ�������ͷ� 
	//������������LNode *p *q *r ������
	void DeleteRepeat(LNode* &linklist)   //��&��ԭ�� �²���ı伴�����ã������ǲ��ǿ��Դ�**ָ���ָ�룿��
		//��**���÷��� ��ε��ã�
	{
		LNode *p, *q ,*r;
		if ( linklist->next == NULL)
		{
			cout<<"�ձ�"<<endl;
			return ;
		}
		p = linklist->next;
		while (NULL != p->next)
		{
			q = p;  //���Ƶ�ǰ�ڵ�
			while (q->next)
			{
				if (q->next->data == p->data)
				{
					r = q->next;    //�ظ��ڵ�
					q->next = q->next->next; //ɾ��R;
					delete r;
				}
				else
				{
					q = q->next ;  //����ƶ�
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





