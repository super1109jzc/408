#include<stdio.h>
#include<stdlib.h>
typedef int Elemtype;
typedef struct Node
{
	Elemtype data;
	struct Node* next;
}Node;
typedef struct Node* Linklist;

//β�巨
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

//ɾ����ֵ
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
		printf("�Ҳ���");
	}
	else
	{
		r = pre->next;
		pre->next =r ->next;
		free(r);
		return 1;
	}
}

//��ת
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
//����
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
	printf("������һ��������-1����������β�����뽨������:");
	p = weichafa();
	printf("���������");
	travel(p);
	printf("\n");
	printf("��ת�������");
	nizhuan(p);
	travel(p);
	printf("������Ҫɾ������");
	scanf("%d", &x);
	shanchu(p, x);
	printf("���������");
	travel(p);
}













