#include <iostream>
#define  STACKINITSIZE 15

struct StackNode
{
	int *top;
	int *base;
	int stacksize;
};

class StackClass
{
public:
	bool initStack(StackNode* S);

	bool clearStack(StackNode *S); 
	
	bool destroyStack(StackNode *S);

	bool displayStack(StackNode *S);

	bool push(StackNode *S , int e);

	bool getTop(StackNode *S,int &e);

	bool pop(StackNode *S, int & e);

private:

};

bool testStack()
{
	StackNode Sa ;
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

	stacktest.getTop(&Sa, e);

	printf("getTop %d \r\n\t", e);

	return true;
}


bool StackClass::initStack(StackNode* S)
{
	S->base = (int *)malloc(STACKINITSIZE*sizeof(StackNode));
    if (S->base == NULL)
	{
		printf("Stack init error \r\n\t");
		return false;
	}
	S->top=S->base;
	S->stacksize = STACKINITSIZE;
	return true;
}

bool StackClass::clearStack(StackNode *S)
{
	S->top = S->base;
	return true;
}

bool StackClass::destroyStack(StackNode *S)
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

bool StackClass::displayStack(StackNode *S)
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

bool StackClass::push(StackNode *S , int e)
{
	if (S->base==NULL) 
	{
		printf("Push error !! \r\n\t");
		return false;
	}
	if (S->top - S->base == S->stacksize)
	{
		S->base = (int*)realloc(S->base, (S->stacksize+STACKINITSIZE)*sizeof(StackNode));
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

bool StackClass::pop(StackNode *S, int & e)
{
	if (!S->base || S->base == S->top)
	{
		printf("pop error! \r\n\t");
		return false;
	}
	e = *--S->top;
	return  true;
}

bool StackClass::getTop(StackNode *S,int &e)
{
	if (S->top == S->base)
	{
		printf("getTop error ! \r\n\t");

		e = -1;
		return false;
	}
	e = *(S->top-1);
	return true;
}




