#include<stdio.h>
#include<stdlib.h>
typedef struct Node
{
	int data;
	struct Node* LChild;
	struct Node* RChild;
}BiNode, * BiTree;

//��չ����
BiTree kuozhan()
{
	BiTree bt;
	int x;
	printf("�����������������");
	scanf("%d", &x);
	if (x == -1)
	{
		bt = NULL;
	}
	else
	{
		bt = (BiTree)malloc(sizeof(BiNode));
		bt->data = x;
		bt->LChild = kuozhan();
		bt->RChild = kuozhan();
	}
	return bt;
}

//��Ҫ���ö���
//���л����Ĳ�������������գ����룬ɾ��
typedef struct LNode
{
	int data;
	struct LNode* next;
}LNode;
typedef struct
{
	LNode* front;
	LNode* rear;
}BigNode;

//����
int jianli(BigNode* p1)
{
	p1->front = (LNode*)malloc(sizeof(LNode));
	if (p1->front != NULL)
	{
		p1->rear = p1->front;
		p1->front->next = NULL;
		return 1;
	}
	else
		return 0;
}

//���
int chakong(BigNode *p1)
{
	if (p1->front == p1->rear)
	{
		return 1;
	}
	else
		return 0;
}

//����
BigNode* charu(BigNode* p1, int x)
{
	LNode* p = (LNode*)malloc(sizeof(LNode));
	if(p!=NULL)
	{
		p->data = x;
		p->next = NULL;
		p1->rear->next = p;
		p1->rear = p;
	}
	else
	{
		printf("����ʧ��");
	}
	return p1;
}

//ɾ��
BigNode* shanchu(BigNode* p1)
{
	LNode* p;
	if (p1->front == p1->rear)
	{
		return 0;
	}
	p = p1->front->next;
	p1->front->next = p->next;
	if (p1->rear == p)
	{
		p1->rear = p1->front;
	}
	free(p);
	return p1;
}

void cengci(BiTree p)
{
	BigNode* p1;
	p1 = (BigNode*)malloc(sizeof(BigNode));
	jianli(p1);
	int m;
	if (p != NULL)
	{
		charu(p1,p->data);
	}
	m = chakong(p1);
	while (m == 0)
	{
		printf("%d", p1->front->data);
		if (p->LChild != NULL)
		{
			charu(p1, p->LChild->data);
		}
		if (p->RChild != NULL)
		{
			charu(p1, p->RChild->data);
		}
		shanchu(p1);
		m = chakong(p1);
	}
}

int main()
{
	BigNode* p;
	BiTree p1;
	int x,*e;
	p1=kuozhan();
	cengci(p1);
}
