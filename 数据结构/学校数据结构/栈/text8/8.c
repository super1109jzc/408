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
		printf("������!");
		return 0;
	}
	else
	{
		Q->elem[Q->rear] = x;
		Q->rear = (Q->rear + 1) % MAXSIZE;
		printf("�����!", x);
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
		printf("��Ϊ��!");
		return 0;
	}
	else
	{
		*x = Q->elem[Q->front];
		Q->front = (Q->front + 1) % MAXSIZE;
		printf("�ѳ���!", *x);
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
		printf("\n������һ������1��ʾ��ӣ�2��ʾ���ӣ�3��ʾ�˳�����\n");
		scanf("%d", &i);
		switch (i)
		{
		case 1:
			printf("����������:");
			scanf("%d", &x);
			EnterQueue(&Q, x);
			break;
		case 2:
			DeleteQueue(&Q, &x);
			break;
		case 3:
			printf("�ټ�\n");
			return 0;
		default:
			printf("����!");
			break;
		}
	}
}