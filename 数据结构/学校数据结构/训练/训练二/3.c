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
	int x, flag = 1;
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
//����
int changdu(Linklist p)
{
	Node* s;
	int m=0;
	s = p->next;
	while (s)
	{
		m = m + 1;
	}
	return m;
}
//��ȡ
int duqu(Linklist L,int i,int *e)
{
	Linklist p = L;
	int k = 0;
	while (k < i)
	{
		p = p->next;
	}
	*e = p->data;
}
�ϲ�
Linklist hebing(Linklist p1, Linklist p2,int x1,int x2)
{
	for (int i = 0; i < x2; i++)
	{
		int count = 0;
		for (int j = 0; j < x1; j++)
		{
			if (A.elem[j] == B.elem[i]) {
				count += 1;

			}
		}
		if (count == 0)
		{
			A.elem[A.length++] = B.elem[i];
		}
	}
}

//�ϲ�
Linklist hebing(Linklist p1, Linklist p2,Linklist p)
{
	int a, b;
	int i, j, count;
	int flag = 1;
	if (changdu(p1) == 0 && changdu(p2) == 0)
		return 0;
	else
	{
		for (i = 1; i <= changdu(p2); i++)
		{
			flag = 1;
			duqu(p2,i, &a);
			for (j = 1; j <= changdu(p1); j++)
			{
				duqu(p1,j, &b);
				if (a == b)
				{
					flag = 0;
					break;
				}
			}
			if (flag == 1)
			{
				lc.Insert(lb.Length() + 1, a);
			}
		}
		for (j = 1; j <= lb.Length(); j++)
		{
			lb.GetElem(j, b);
			lc.Insert(lc.Length() + 1, b);
		}
		return 1;
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
	Linklist p1,p2,p;
	int x,x1,x2;
	printf("������һ��������-1������������һ����������β�����뽨������:");
	p1 = weichafa();
	printf("���������");
	travel(p1);
	printf("������һ��������-1�����������ڶ�����������β�����뽨������:");
	p2 = weichafa();
	printf("���������");
	travel(p2);
	printf("\n");
	x1=changdu(p1);
	printf("%d", x1);
	x2 = changdu(p1);
	printf("%d", x2);
	printf("����ϲ��������");
	p=hebing(p1, p2, x1, x2);
	printf("���������");
	travel(p);
}

/*#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 100
typedef int ElemType;
typedef struct
{
	ElemType elem[MAXSIZE];
	int last;
} SeqList;

//����������
int jianli(SeqList* L)
{
	int x, i = 0;
	int flag = 1;
	L->last = 0;
	printf("������һ����������-1��Ϊ�ս᣺");
	while (flag)
	{
		scanf("%d", &x);
		if (x != -1)
		{
			L->elem[i] = x;
			L->last++;
			i++;
		}
		else
			flag = 0;
	}
	return L->last;
}

//�ϲ�
int hebing(SeqList* p1, SeqList* p2, int x1, int x2)
{
	int i, j;
	for (i = 0; i < x2; i++)
	{
		int count = 0;
		for (j = 0; j < x1; j++)
		{
			if (p1->elem[j] == p2->elem[i]) 
			{
				count = 1;
			}
		}
		if (count == 0)
		{
			p1->elem[x1++] = p2->elem[i];
			p1->last++;
		}
	}
	return x1;
}

//����
SeqList* paixu(SeqList* p1 , int x1)
{
	ElemType temp;
	int i, j;
	for (i = 0; i < x1 - 1; i++)
	{
		for (j = 0; j < x1 - 1 - i; j++) 
		{ 
			if (p1->elem[j] > p1->elem[j + 1])
			{ 
				temp = p1->elem[j];
				p1->elem[j] = p1->elem[j + 1];
				p1->elem[j + 1] = temp;
			}
		}
	}
	return p1;
}

����
void travel(SeqList* L)
{
	int k;
	for (k = 0; k < L->last; k++)
	{
		printf("%d", L->elem[k]);
	}
}


int main()
{
	int x1, x2, a;
	int* e;
	SeqList p1,  p2;
	SeqList* p3, * p4;
	x1 = jianli(&p1);
	printf("���ɵ�һ��˳������");
	travel(&p1);
	printf("\n");
	x2 = jianli(&p2);
	printf("���ɵڶ���˳������");
	travel(&p2);
	printf("\n");
	a=hebing(&p1, &p2, x1, x2);
	p4=paixu(&p1, a);
	travel(p4);
}*/