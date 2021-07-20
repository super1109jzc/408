#include<stdio.h>
#include<stdlib.h>
#include"malloc.h"
#include<math.h>
#include<stdbool.h>
#define FALSE 0
#define TRUE 1
#define Stack_Size 50

//���Ļ�������
typedef int DataType;
int unleafcount = 0;
typedef struct Node
{
	DataType data;
	struct Node* LChild;
	struct Node* RChild;
} BiTNode, * BiTree;

//��չ�����������������
BiTree CreateBiTreeF()
{
	BiTree bt;
	int x;
	printf("�����������������ֵ��");
	scanf("%d", &x);
	if (x == -1)
	{
		bt = NULL;
	}
	else
	{
		bt = (BiTree)malloc(sizeof(BiTNode));
		bt->data = x;
		bt->LChild = CreateBiTreeF();
		bt->RChild = CreateBiTreeF();
	}
	return bt;
}

//ջ�Ļ�������
typedef struct node
{
	int data1;
	struct node* next;
}LinkStackNode;
typedef LinkStackNode* LinkStack;

//��ʼ��
InitStackList(LinkStack* p)
{
	*p = (LinkStackNode*)malloc(sizeof(LinkStackNode));
	(*p)->next = NULL;
}

//����
int Push(LinkStack p, int x)
{
	LinkStackNode* temp;
	temp = (LinkStackNode*)malloc(sizeof(LinkStackNode));
	if (temp == NULL) return(FALSE);
	temp->data1 = x;
	temp->next = p->next;
	p->next = temp;
	return(TRUE);
}

//����
int Pop(LinkStack p, int* x)
{
	LinkStackNode* temp;
	temp = p->next;
	if (temp == NULL)
		return(FALSE);
	*x = temp->data1;
	p->next = temp->next;
	free(temp);
	return(TRUE);
}

//��
void xunzhao(BiTree node,int search)
{
	int* y;
	LinkStack p;
	InitStackList(&p);
	if (node==NULL)
		return NULL;
	Push(p,node->data);
	if (node->data == search)
	{
		while (p->next != NULL)
		{
			printf("%d", p->data1);
		}
	}
	xunzhao(node->LChild, search);
	xunzhao(node->RChild, search);
	if (node->data != search)
	{
		Pop(p,y);
	}	
}

int main()
{
	BiTree m;
	int x;
	m = CreateBiTreeF();
	printf("������Ҫ���ҵ���");
	scanf("%d", &x);
	xunzhao(m, x);
}