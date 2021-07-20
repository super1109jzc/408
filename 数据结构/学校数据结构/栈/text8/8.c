#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 3
typedef int SeqQueueElemType;

typedef struct queue {
	SeqQueueElemType elem[MAXSIZE];
	int front;
	int rear;
	int tag;
}SeqQueue; 

void Initqueue(SeqQueue* Q)
{
	Q->front = Q->rear = 0;   
	Q->tag = 0;             
}

int EnterQueue(SeqQueue* Q, SeqQueueElemType x)
{
	if (Q->front == Q->rear && Q->tag == 1)
	{
		printf("队已满!");
		return 0;
	}
	else
	{
		Q->elem[Q->rear] = x;
		Q->rear = (Q->rear + 1) % MAXSIZE;
		printf("已入队!", x);
		if (Q->front == Q->rear)
		{
			Q->tag = 1;
		}
	}
}

int DeleteQueue(SeqQueue* Q, SeqQueueElemType* x)
{
	if (Q->front == Q->rear && Q->tag == 0)
	{
		printf("队为空!");
		return 0;
	}
	else
	{
		*x = Q->elem[Q->front];
		Q->front = (Q->front + 1) % MAXSIZE;
		printf("已出队!", *x);
		if (Q->front == Q->rear)  
		{
			Q->tag = 0;
		}
	}
}

int main()
{
	SeqQueue Q;
	int i = 1, count = 0;    
	SeqQueueElemType x;
	Initqueue(&Q);
	while (i)
	{
		printf("\n请输入一个数，1表示入队，2表示出队，3表示退出程序\n");
		scanf("%d", &i);
		switch (i)
		{
		case 1:
			printf("请输入数据:");
			scanf("%d", &x);
			EnterQueue(&Q, x);
			break;
		case 2:
			DeleteQueue(&Q, &x);
			break;
		case 3:
			printf("再见\n");
			return 0;
		default:
			printf("重输!");
			break;
		}
	}
}