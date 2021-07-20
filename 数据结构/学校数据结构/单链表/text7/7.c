#include<stdio.h>
#include<stdlib.h>
typedef int ElemType;
typedef struct Node
{
	ElemType data;
	struct Node* next;
}Node, * Linklist;
Linklist CreateFromTail()
{
	Linklist L;
	Linklist s, r;
	L = (Linklist)malloc(sizeof(Node));
	L->next = NULL;
	r = L;
	ElemType t;
	int flag = 1;
	printf("请输入数据元素:");
	while (flag)
	{	
		scanf("%d", &t);
		if (t != -1)
		{
			s = (Linklist)malloc(sizeof(Node));
			s->data = t;
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

void bianli(Linklist L)
{
	Linklist p;
	p = L->next;
	while (p != NULL)
	{
		printf("%d", p->data);
		printf(" ");
		p = p->next;
	}
}
void shouhui(Linklist* L)
{
	Linklist p, q;
	p = *L;
	q = p->next;
	while (q != NULL)
	{
		free(p);
		p = q;
		q = p->next;
	}
}
void daoxu(Linklist L, int left, int right)
{
	Linklist pre, p, tmp, m, a, b;
	int i = 0, j = 0;
	pre = L;
	m = pre;
	b = L;
	while (i < left - 1)
	{
		pre = pre->next;
		i++;
	}
	a = pre->next;
	while (j < right)
	{
		b = b->next;
		j++;
	}
	m = b->next;
	p = a;
	while (p != m)
	{
		tmp = p->next;
		p->next = pre->next;
		pre->next = p;
		p = tmp;
	}
	a->next = m;
	pre->next = b;
}
int main()
{
	Linklist L;
	int left, right;
	L = CreateFromTail();
	printf("请输入左侧整数和右侧整数:");
	scanf("%d%d", &left, &right);
	daoxu(L, left, right);
	bianli(L);
	shouhui(&L);
	return 0;
}
