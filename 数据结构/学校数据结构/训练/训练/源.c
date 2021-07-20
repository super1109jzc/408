#include<stdio.h>
#include<stdlib.h>
typedef int Elemtype;
typedef struct Node
{
	Elemtype data;
	struct Node* next;
}Node;
typedef struct Node* Linklist;

//尾插法
Linklist weichafa()
{
	Linklist L;
	int x,flag = 1;
	Node* r, * s;
	L = (Linklist)malloc(sizeof(Node));
	L->next = NULL;
	r = L;
	while (flag)
	{
		scanf("%d", &x);
		if (x != -1)
		{
			s = (Linklist)malloc(sizeof(Node));
			s->data = x;
			r->next = s;
			r = s;
		}
		else
		{
			flag = 0;
			r->next = NULL;
		}
	}
	return L;
}

//删除数值
int shanchu(Linklist p,int x)
{
	Node* pre = p;
	Node* r;
	while (pre->next != NULL && pre->next->data != x)
	{
		pre = pre->next;
	}
	if (pre->next == NULL)
	{
		printf("找不到");
	}
	else
	{
		r = pre->next;
		pre->next =r ->next;
		free(r);
		return 1;
	}
}

//逆转
void nizhuan(Linklist p)
{
	Node* pre, * a, * l;
	pre = p->next;
	a = pre;
	l = pre->next;
	while (l!=NULL)
	{
		pre->next = l->next;
		l->next = a;
		p->next = l;
		l = pre->next;
		a = p->next;
	}
}
//遍历
void travel(Linklist p)
{
	Node* s;
	s = p->next;
	while (s)
	{
		printf("%d", s->data);
		s = s->next;
	}
}
int main()
{
	Linklist p;
	int x;
	printf("请输入一批数，以-1结束，采用尾部插入建立链表:");
	p = weichafa();
	printf("输出该链表：");
	travel(p);
	printf("\n");
	printf("反转后的链表");
	nizhuan(p);
	travel(p);
	printf("请输入要删除的数");
	scanf("%d", &x);
	shanchu(p, x);
	printf("输出该链表：");
	travel(p);
}













