#include<stdio.h>
#include<stdlib.h>
#include"malloc.h"
#include<math.h>
#include<stdbool.h>
#define FALSE 0
#define TRUE 1
#define Stack_Size 50

//树的基础代码
typedef int DataType;
int unleafcount = 0;
typedef struct Node
{
	DataType data;
	struct Node* LChild;
	struct Node* RChild;
} BiTNode, * BiTree;

//扩展的先序遍历序列输入
BiTree CreateBiTreeF()
{
	BiTree bt;
	int x;
	printf("请依次输入二叉树的值：");
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

//栈的基础代码
typedef struct node
{
	int data1;
	struct node* next;
}LinkStackNode;
typedef LinkStackNode* LinkStack;

//初始化
InitStackList(LinkStack* p)
{
	*p = (LinkStackNode*)malloc(sizeof(LinkStackNode));
	(*p)->next = NULL;
}

//进入
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

//弹出
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

//查
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
	printf("请输入要查找的数");
	scanf("%d", &x);
	xunzhao(m, x);
}