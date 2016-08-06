#include <iostream>
#define  STACKINITSIZE 15

struct SqNode
{
	int *top;
	int *base;
	int stacksize;
};

class StackClass
{
public:
	bool initStack(SqNode* S);

	bool clearStack(SqNode *S); 
	
	bool destroyStack(SqNode *S);

	bool displayStack(SqNode *S);

	bool push(SqNode *S , int e);

	bool getTop(SqNode *S,int &e);

	bool pop(SqNode *S, int & e);

private:

};

bool testStack()
{
	SqNode Sa ;
	int e = 0;
	StackClass stacktest;
	stacktest.initStack(&Sa);
	 
	for (int i = 22; i<30;i++  )
	{
		stacktest.push(&Sa,i);	
	}
	stacktest.displayStack(&Sa);

	e = 99;
	stacktest.push(&Sa,e);
	stacktest.push(&Sa,e-11);

	stacktest.displayStack(&Sa);

	stacktest.pop(&Sa,e);

	stacktest.displayStack(&Sa);
	
	stacktest.destroyStack(&Sa);

	stacktest.displayStack(&Sa);



	return true;
}


bool StackClass::initStack(SqNode* S)
{
	 S->base = (int *)malloc(STACKINITSIZE*sizeof(SqNode));
    if (S->base==NULL)
	{
		printf("Stack init error \r\n\t");
		return false;
	}
	S->top=S->base;
	S->stacksize = STACKINITSIZE;
	return true;
}

bool StackClass::clearStack(SqNode *S)
{
	S->top = S->base;
	return true;
}

bool StackClass::destroyStack(SqNode *S)
{
	if (S->base == NULL)
	{
		return false;
	}
	free(S->base);
	S->base =NULL;
	S->top = NULL;
	return true;
}

bool StackClass::displayStack(SqNode *S)
{
	printf("display stack:\t");
	if (S->base == NULL)
	{
		printf(" stack: is  null \r\n\t");
		return false;
	}
	int i = 0 ;
	while (S->top > (S->base+i))
	{
		printf("%d ",*(S->base+i));
		i++;
	}
	cout<<endl;
	return true;
}

bool StackClass::push(SqNode *S , int e)
{
	if (S->base==NULL) 
	{
		printf("Push error !! \r\n\t");
		return false;
	}
	if (S->top - S->base == S->stacksize)
	{
		S->base = (int*)realloc(S->base, (S->stacksize+STACKINITSIZE)*sizeof(SqNode));
		if (!S->base)
		{
			return false;
		}
		S->top = S->base+S->stacksize;
		S->stacksize +=STACKINITSIZE;
	}
	*(S->top)++ = e;

	return true;
}

bool StackClass::pop(SqNode *S, int & e)
{
	if (!S->base || S->base == S->top)
	{
		printf("pop error! \r\n\t");
		return false;
	}
	e = *--S->top;
	return  true;
}

bool StackClass::getTop(SqNode *S,int &e)
{
	if (S->top == S->base)
	{
		return false;
	}
	e = *(S->top-1);
	return true;
}




