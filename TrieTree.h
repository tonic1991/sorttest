//Trie树，cvte笔试题，输入首字母，自动返回所有具有该字幕的单词（含数字）

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

//ASCII 码相关转换  将0-9 ，A-Z,a-z 转换成0-61；   0：30  A：41  ； a: 61  -->0-0 A-10 ; a:36; 
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
	string strDic ;//字典 
	struct Trie{
		Trie* next[MaxDic];
	    int v ;               //v表示该字母在字典中路径经过的次数，v=-1表示叶子节点，（此时word内寸的是整个单词）
		char* word;
		Trie():word(NULL),v(0)
		{
			for (int i = 0; i < MaxDic; i++)
			{
				next[i] = NULL;
			}
		}
	};
	void CreatTrieTree(const char* str);  //将该字符串插入Trie;

	int FindInTrieTree(char* str);       //查找是否有该字符串；

	bool DeleteTrieTree(Trie* T);
	//ASCII 码相关转换  将0-9 ，A-Z,a-z 转换成0-61；   0：30  A：41  ； a: 61  -->0-0 A-10 ; a:36; 
	int  GetIndex(char s);                //
	//将index转换成char
	char GetChar(int index);
	//打印所有以该字符为前缀的词
	void PrintPre(char* str);

	void PrintTree(Trie* p);
	Trie* trie;
};

TrieTree::TrieTree()
{
	strDic ="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"; //字典
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
			if (!p->word)  //该world 没出现过  //具体位置待考虑
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
		p->v  = -1;  //叶子节点标志
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
		if(p == NULL) return false;   //若为空集，表示不存以此为前缀的串
		if (p->v == -1)
		{
			return true ; //字符集中已有串是此串的前缀
		}
	}
	return -1;   //此串是字符集中某串的前缀
}

bool TrieTree::DeleteTrieTree(Trie* T)
{
	   T  = this->trie;
	   return true;
}

//ASCII 码相关转换  将0-9 ，A-Z,a-z 转换成0-61；   0：30  A：41  ； a: 61  -->0-0 A-10 ; a:36; 
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
	else //否则为'0'
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
	cout<<"以"<<str<<"为前缀的单词有"<<endl;
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
		cout<<"单词为："<<p->word<<"       单词的v为："<<p->v<<endl;
	}
	for (int i = 0 ; i<MaxDic;i++	)
	{
		if (NULL != p->next[i])
		{
			PrintTree(p->next[i]);
		}
	}


}



