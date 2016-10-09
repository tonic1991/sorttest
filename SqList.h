//#include <iostream>

#define LIST_INIT_SIZE  15
#define SQLIST_INCTEASEMRNT  5


struct  SqList
{
	int* elem;   //base addresss;
	int lenth;
	int listsize;
};

//顺序表练习
class SqListClass
{
	
public:
	SqListClass();

	bool initSqList(SqList &sqList);
	
	bool insertSqList(SqList& sqList , int pos , int e);

	bool traverseList(SqList L);

	bool getvalSqList(SqList L , int pos, int & e);

	bool locateListVal(SqList L ,int e);

	bool DestroySqList(SqList &L);

	bool deleteListValue(SqList &L,int pos , int &e);

	bool unionSqList(SqList LA ,SqList LB ,SqList &LC);
    
	bool mergeSqList(SqList LA ,SqList LB ,SqList &LC);
	//SqList sqList;


};

//  顺序表测试方法；
bool TestSqlist()
{
	SqListClass sqListClass;
	SqList La;
	sqListClass.initSqList(La);
	for (int i = 1 ; i<6 ; i++)
	{
		sqListClass.insertSqList(La,i,i*2 );
	}
	sqListClass.traverseList(La);



	int e ;
	sqListClass.getvalSqList(La,2,e);

	sqListClass.locateListVal(La,12);

	sqListClass.deleteListValue(La,3,e);


	SqList Lb;
	sqListClass.initSqList(Lb);
	for (int i =1 ; i <20;i++)
	{
		sqListClass.insertSqList(Lb,i,i);
	}
	sqListClass.traverseList(Lb);

	SqList Lc;
	sqListClass.unionSqList(La,Lb,Lc);
	

	sqListClass.mergeSqList(La,Lb,Lc);
	sqListClass.traverseList(Lc);


	return true;
}

SqListClass::SqListClass()
{
	printf("Sqlist Test class ,Please use TestSqlist() to do the test \r\n\t");
}

bool SqListClass::initSqList(SqList &sqList)
{

	sqList.elem =(int*)malloc(LIST_INIT_SIZE*sizeof(int));
	if (sqList.elem == NULL)
	{
		return false;
	}else
	{
		sqList.listsize = LIST_INIT_SIZE;
		sqList.lenth = 0;
		return true;
	}
}

bool SqListClass::insertSqList(SqList& sqList , int pos , int e)
{
	if (pos<0||sqList.elem==NULL){ printf("insert false") ; return false;} 
	if(sqList.lenth>=sqList.listsize)
	{
		int* newbase = (int*)realloc(sqList.elem,(SQLIST_INCTEASEMRNT+sqList.lenth)*sizeof(int));
		sqList.elem = newbase;
		if(sqList.elem==NULL) return false;
		sqList.listsize = SQLIST_INCTEASEMRNT + sqList.lenth;
	}
	int* q = &sqList.elem[pos-1];
	for (int*p = &sqList.elem[sqList.lenth-1];p>=q;--p)
	{
		*(p+1)=*p;
	}
	*q = e;
	sqList.lenth++;
	return true;
}

bool SqListClass::traverseList(SqList L)
{
	if (L.elem==NULL||L.lenth==0)  return false;

		printf("L .length = %d  \r\n\t" ,L.lenth);
		int pos = 0;
		while(L.elem[pos]&&pos<L.lenth)
		{
			printf(" %d",(L.elem[pos])); pos++;			
		}
		printf("\r\n");
		return true;
		
}

bool SqListClass::getvalSqList(SqList L , int pos, int & e)
{
	if (pos<1 ||pos>L.lenth-1)
	{
		return false;
	}
	e = L.elem[pos-1];
	printf("POS:%d val:%d \r\n\t",pos , e);
	return true;
}

bool SqListClass::locateListVal(SqList L ,int e)
{
	while (L.elem ==NULL)
	{
		return false;
	}
	int pos = 1;
	while (pos<L.lenth && L.elem[pos-1]!=e)
	{
		pos++;
	}
	if (pos>=L.lenth)
	{
		printf("locate false\r\n\t");
		return false;
	}
	printf("Val: %d is on %d \r\n\t ",e,pos);
	return true;
}

bool SqListClass::DestroySqList(SqList &L)
{
	if (L.elem!=NULL)
	{
		free(L.elem);
		return true;
	}
	return false;

}

bool SqListClass::deleteListValue(SqList &L,int pos , int &e)
{
	if (L.elem==NULL||pos<1||pos>L.lenth)
	{
		return false;
	}
	e = L.elem[pos-1];
	for (int*p = &L.elem[pos];p< L.elem+L.lenth;p++ )
	{  
		*(p-1) = *p;
	}

	L.lenth--;
	printf("on Pos %d  ， delete: %d \r\n\t",pos, e);
	traverseList(L);
	return true ;
}

bool SqListClass::unionSqList(SqList LA ,SqList LB ,SqList &LC)
{
	if (LA.elem==NULL||LB.elem==NULL)
	{
		return false;
	}
	initSqList(LC);
	int pa = 0 ,pb= 0,index =1;
	while(pa<LA.lenth&&pb<LB.lenth)
	{
		if (LA.elem[pa]==LB.elem[pb])
		{
			insertSqList(LC,index ,LA.elem[pa]);
			index++;
			pa++;
			pb++;
		}
		else if (LA.elem[pa]<LB.elem[pb])
		{
			pa++; continue;
		}else
		{
			pb++; continue;
		}
	}
	traverseList(LC);
	return true;
}

bool SqListClass::mergeSqList(SqList LA ,SqList LB ,SqList &LC)
{
	//输入判断 预定义La，lb有序
	//1不见了。。。
	int pa =0,pb =0,index=0;
	initSqList(LC);
	while (pa<LA.lenth&&pb<LB.lenth)
	{
		if (LA.elem[pa]<=LB.elem[pb])
		{
			index++;insertSqList(LC,index,LA.elem[pa]); pa++;
		}
		else
		{
			index++;insertSqList(LC,index,LB.elem[pb]); pb++;
		}
	}
	while (pa<LA.lenth)
	{
		index++;	insertSqList(LC,index,LA.elem[pa]);pa++;
	}

	while (pb<LB.elem[pb])
	{
	index++;	insertSqList(LC,index,LB.elem[pb]); pb++;
	}
	
	return true;
}


