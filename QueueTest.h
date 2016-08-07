#include <iostream>

/*
	测试队列QueueClass  和循环circularQueue 队列
*/
#define  MAXCQUEUESIZE 10


struct QNode
{
	int data;
	QNode *next;
};
struct LinkQueue
{
	QNode * front;
	QNode * rear;
};

//循环队列数据结构  注意起数据结构的内寸分布
struct CQueue
{
	int *pBase;
	int front; //指向队列第一个元素 
	int rear; // 指向队列最后一个元素的下一个元素
	int maxsize; 
};

//循环队列实现类
class CircularQueue
{
public:
	bool initCQueue(CQueue * cQueue);   //理解初始化方式与数组联系

	bool traverseCQueue(CQueue *cQueue);

	bool FullCQueue(CQueue *cQueue);

	bool emptyCQueue(CQueue *cQueue);

	bool enCQueue(CQueue *cQueue, int e);

	bool deCQueue(CQueue *cQueue, int *e);

private:

};

void TestCircularQueue()
{
	CircularQueue circularQueue;

	CQueue cQueue;
	
	int e;

	circularQueue.initCQueue(&cQueue);
	
	for (int i = 3; i < 15; i++)
	{
		circularQueue.enCQueue(&cQueue, i);
	}

	circularQueue.traverseCQueue(&cQueue);

	for (int i = 0; i < 5;i++)
	{
		circularQueue.deCQueue(&cQueue,&e);
	}
	
	circularQueue.traverseCQueue(&cQueue);

	for (int i = 88; i <= 95; i++)
	{
		circularQueue.enCQueue(&cQueue, i);
	}

	circularQueue.traverseCQueue(&cQueue);

}


bool CircularQueue::initCQueue(CQueue * cQueue)
{
	cQueue->pBase = (int *)malloc( MAXCQUEUESIZE*sizeof(int));
	if (cQueue->pBase==NULL)
	{
		printf("init cqueue error! \r\n\t");
		return false;
	}
	else
	{
		cQueue->front = 0;
		cQueue->rear = 0;
		cQueue->maxsize = MAXCQUEUESIZE;

		printf("\tinit cqueue ok ! \r\n\t");
		return true;
	}
}

bool CircularQueue::traverseCQueue(CQueue *cQueue)
{
	if (cQueue->pBase==NULL )
	{
		printf("traverse error cq is null");
		return false;
	}
	else
	{
		int i = cQueue->front;
		while (i!=cQueue->rear)
		{
			printf(" %d ", cQueue->pBase[i]);
			i = (i + 1) % cQueue->maxsize;
		}
		printf("\r\n\t");
		return true;
	}
}

bool CircularQueue::FullCQueue(CQueue *cQueue)
{
	if (cQueue->front == (cQueue->rear+1)%cQueue->maxsize)  //循环队列满 留了一个没用
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool CircularQueue::emptyCQueue(CQueue *cQueue)
{
	if (cQueue->front == cQueue->rear)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool CircularQueue::enCQueue(CQueue *cQueue, int e)
{
	if (FullCQueue(cQueue)==true)
	{
		printf("cq is full en error! \r\n\t");
		return false;
	}
	else
	{
		cQueue->pBase[cQueue->rear] = e;
		cQueue->rear = (cQueue->rear + 1) % cQueue->maxsize;
		return true;
	}
}

bool CircularQueue::deCQueue(CQueue *cQueue, int *e)
{
	if (emptyCQueue(cQueue)==true)
	{
		printf("deCQueue error empty cq !\r\n\t");
		return false;
	}
	else
	{
		*e = cQueue->pBase[cQueue->front];
		cQueue->front = (cQueue->front + 1) % cQueue->maxsize;
		printf(" de cqueue print e : %d  \r\n\t", *e);
		return true;
	}
}





//队列（链式）实现类
class QueueClass
{
public:
	bool initQueue(LinkQueue *Q);

	bool clearQueue(LinkQueue *Q);

	bool destroyQueue(LinkQueue *Q);

	bool queueEmpty(LinkQueue *Q);

	int queueLength(LinkQueue *Q);

	bool Gethead(LinkQueue *Q ,int *e);

	bool enQueue(LinkQueue *Q, int e);

	bool deQueue(LinkQueue *Q, int *e);
	
	bool traverseQueue(LinkQueue *Q);


private:

};

// 测试队列
bool TestQueue()
{
	printf("\t test queue ! \r\n\t");
	QueueClass queueInstance;
	LinkQueue  Q;
	int e = 0;
	
	queueInstance.initQueue(&Q);

	for (int i = 11; i < 30; i++)
	{
		queueInstance.enQueue(&Q, i);
	}
	queueInstance.traverseQueue(&Q);

	for (int i = 0; i < 5; i ++)
	{
		queueInstance.deQueue(&Q, &e);
	}

	queueInstance.traverseQueue(&Q);

	queueInstance.Gethead(&Q,&e);

	//queueInstance.clearQueue(&Q);

	queueInstance.Gethead(&Q, &e);

	queueInstance.destroyQueue(&Q);

	queueInstance.Gethead(&Q, &e);

	return true;
}

bool QueueClass::initQueue(LinkQueue *Q)
{
	Q->front = (QNode *)malloc(sizeof(QNode));
	if (Q->front==NULL)
	{
		printf("init Queue error! \r\n\t");
		return false;
	}
	Q->rear = Q->front;
	Q->front->next = NULL;
	printf("init ok ! \r\n\t");
	return true;
}

//清空队列
bool QueueClass::clearQueue(LinkQueue *Q)
{  
	if (Q->front == NULL)
	{
		printf("clear queue error \r\n\t");
		return false;
	}
	printf("clear queue start:\r\n\t ");
	QNode *p;
	Q->rear = Q->front->next;
	
	while (Q->rear)
	{
		p = Q->rear->next;  //
		free(Q->rear);
		Q->rear = p;
	}
	Q->rear = Q->front;
	return true;


}

bool QueueClass::destroyQueue(LinkQueue *Q)
{
	// 不操作rear？觉得有点问题
	if (Q->front == NULL)
	{
		printf("destroy error ! \r\n\t");
		return false;
	}
	while (Q->front)
	{
		Q->rear = Q->front->next;
		free(Q->front);
		Q->front = Q->rear;
	}
	Q->rear = Q->front = NULL;

	return true;
}

bool QueueClass::queueEmpty(LinkQueue *Q)
{
	if (Q->front == NULL || Q->front == Q->rear)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int QueueClass::queueLength(LinkQueue *Q)
{
	QNode *p; 
	int count = 0; 
	p = Q->front->next;
	while (p!=NULL)
	{
		p = p->next;
		count++;
	}
	return count;
}

bool QueueClass::Gethead(LinkQueue *Q, int *e)
{
	if(queueEmpty(Q) == true)
	{
		printf("get head error! \r\n\t");
		return false;
	}
	else
	{
		*e = Q->front->next->data;
		printf("%d \r\n\t", *e);
		return true;
	}
}

bool QueueClass::enQueue(LinkQueue *Q, int e)
{
	QNode *p;
	p = (QNode *)malloc(sizeof(QNode));
	if (!p)
	{
		printf("enqueue malloc error ! \r\n\t");
		return false;
	}
	
	p->data = e; p->next = NULL;
	Q->rear->next = p;
	Q->rear = p;
	return true;
}

bool QueueClass::deQueue(LinkQueue *Q, int *e)
{
	QNode *p ;
	if (queueEmpty(Q))
	{
		printf("dequeue error!");
		return false;
	}
	else
	{
		p = Q->front->next;
		*e = p->data;
		Q->front->next = p->next;
		if (Q->rear==p)
		{
			Q->rear = Q->front;
		}
		free(p);
		return true;
	}

}

bool QueueClass::traverseQueue(LinkQueue *Q)
{
	if (Q->front == NULL)
	{
		printf("traverse Queue error! \r\n\t");
		return false;
	}
	else
	{
		QNode *p;
		p = Q->front->next;
		while(p!= NULL)
		{
			printf(" %d ",p->data);
			p = p->next;
		}
		cout << endl;

		return true;
	}

}



