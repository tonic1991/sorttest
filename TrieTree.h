//Trie����cvte�����⣬��������ĸ���Զ��������о��и���Ļ�ĵ��ʣ������֣�

//test case
// TrieTree* trieTree = new TrieTree();
// trieTree->CreatTrieTree("CCTV1");
// trieTree->CreatTrieTree("C1TV1");
// trieTree->CreatTrieTree("C2TV1");
// trieTree->CreatTrieTree("C1AA1");
// trieTree->CreatTrieTree("HNTV1");
// trieTree->CreatTrieTree("HNTV3");
// trieTree->FindInTrieTree("A");
// trieTree->PrintPre("C1");

//ASCII �����ת��  ��0-9 ��A-Z,a-z ת����0-61��   0��30  A��41  �� a: 61  -->0-0 A-10 ; a:36; 
#include <iostream>
#include <string.h>
//#include <string>
using namespace std ;


class TrieTree
{
public:
	TrieTree();
	~TrieTree();
	static  const int MaxDic = 62;
	string strDic ;//�ֵ� 
	struct Trie{
		Trie* next[MaxDic];
	    int v ;               //v��ʾ����ĸ���ֵ���·�������Ĵ�����v=-1��ʾҶ�ӽڵ㣬����ʱword�ڴ�����������ʣ�
		char* word;
		Trie():word(NULL),v(0)
		{
			for (int i = 0; i < MaxDic; i++)
			{
				next[i] = NULL;
			}
		}
	};
	void CreatTrieTree(const char* str);  //�����ַ�������Trie;

	int FindInTrieTree(char* str);       //�����Ƿ��и��ַ�����

	bool DeleteTrieTree(Trie* T);
	//ASCII �����ת��  ��0-9 ��A-Z,a-z ת����0-61��   0��30  A��41  �� a: 61  -->0-0 A-10 ; a:36; 
	int  GetIndex(char s);                //
	//��indexת����char
	char GetChar(int index);
	//��ӡ�����Ը��ַ�Ϊǰ׺�Ĵ�
	void PrintPre(char* str);

	void PrintTree(Trie* p);
	Trie* trie;
};

TrieTree::TrieTree()
{
	strDic ="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"; //�ֵ�
    trie = new Trie();
	trie->v =0;
}
TrieTree::~TrieTree()
{
	DeleteTrieTree(trie);
}

void TrieTree::CreatTrieTree(const char* str)
{
	int len = strlen(str);
    Trie* p  = this->trie, *q;
	int index =0;
		for (int i = 0; i < len; i++)
		{
			index = GetIndex(str[i]);
			if (p->next[index] ==NULL)
			{
				q =new Trie();
				q->v =1;
				//q->word = str;
				p->next[index]  = q;
				p = p->next[index];
			}
			else
			{
				p->next[index]->v ++;
				p = p->next[index];
			}
			if (!p->word)  //��world û���ֹ�  //����λ�ô�����
			{
				p->word = new char[(i+1)*sizeof(char)];
				//strcpy_s(p->word ,1,&str[i]);
				//p->word = new char[strlen(str)+1];
		      //strcpy_s(p->word,strlen(str)+1,str); 
				//int a = strlen(str)+1;
				//strcpy_s(p->word,strlen(str)+1,str,i); 
				memcpy(p->word,str,(i+1)*sizeof(char));
			}
		}
		p->v  = -1;  //Ҷ�ӽڵ��־
}

int TrieTree::FindInTrieTree(char* str)
{
//	vector<char>  STROUT;
	if (NULL == str)
	{
		return -1;
	}
	size_t len = strlen(str); 
	Trie* p = trie;
	for (size_t i = 0;i<len ; i++)
	{
		int index = GetIndex(str[i]);
		if (p->next[index])
		{
			p = p->next[index];
		}		
		if(p == NULL) return false;   //��Ϊ�ռ�����ʾ�����Դ�Ϊǰ׺�Ĵ�
		if (p->v == -1)
		{
			return true ; //�ַ��������д��Ǵ˴���ǰ׺
		}
	}
	return -1;   //�˴����ַ�����ĳ����ǰ׺
}

bool TrieTree::DeleteTrieTree(Trie* T)
{
	   T  = this->trie;
	   return true;
}

//ASCII �����ת��  ��0-9 ��A-Z,a-z ת����0-61��   0��30  A��41  �� a: 61  -->0-0 A-10 ; a:36; 
int TrieTree::GetIndex(char s)
{
	int index = 0;
	if (s>='0'&&s<='9')
	{
		index = s - '0';
	}
	else if (s>='A'&&s<='Z')
	{
		index = s - 'A'+10;
	}
	else if (s>='a'&&s<='Z')
	{
		index = s - 'a'+10+26;
	}
	else //����Ϊ'0'
	{
		index = '0';
	}
	return index;

}

char TrieTree::GetChar(int index)
{
	return strDic[index];
}

void TrieTree::PrintPre(char* str)
{
	Trie* p  = this->trie;
	if (NULL == str)
	{
		return;
	}
	size_t len = strlen(str);
	int index;
	for (size_t i = 0 ; i <len ; i++)
	{
		 index = GetIndex(str[i]);
		 if (p->next[index])
		 {
			 p = p->next[index];
		 }
		 else
		 {
			 return;
		 }
	}
	cout<<"��"<<str<<"Ϊǰ׺�ĵ�����"<<endl;
	PrintTree(p);


}

void TrieTree::PrintTree(Trie* p)
{
	if (NULL == p)
	{
		return;
	}
	if (p->v<0)
	{
		cout<<"����Ϊ��"<<p->word<<"       ���ʵ�vΪ��"<<p->v<<endl;
	}
	for (int i = 0 ; i<MaxDic;i++	)
	{
		if (NULL != p->next[i])
		{
			PrintTree(p->next[i]);
		}
	}


}



