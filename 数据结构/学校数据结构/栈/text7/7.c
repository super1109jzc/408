/*�ߡ���֪������f�д洢�Ķ�������������ʵ����������ĵݹ��㷨��
��1����������������
��2��������ڵ�ĸ�����ע�⣺������ͷ�ڵ㣩*/
#include<stdio.h>
#include<stdlib.h>
typedef int ElemType;
typedef struct node
{
    ElemType data;
    struct node* next;
} node, * LinkList;
void xinjian(LinkList* L)
{
    *L = (LinkList)malloc(sizeof(node));
    (*L)->next = NULL;
}
void toucha(LinkList L)
{
    LinkList s;
    int x;
    int flag = 1;
    printf("������һ������");
    while (flag)
    {
        scanf("%d", &x);
        if (x != -1)
        {
            s = (LinkList)malloc(sizeof(node));
            s->data = x;
            s->next = L->next;
            L->next = s;
        }
        else
            flag = 0;
    }
}
int f(LinkList q)
{
    int max;
    if (!q->next)
    {
        max = q->data;
        return max;
    }
    max = f(q->next);
    if (max >= q->data)
    {
        max = max;
    }
    else
    {
        max = q->data;
    }
}
int g(LinkList q)
{
    int len=0;
    if (!q->next)
    {
        len = len;
        return len;
    }
    else
        len=g(q->next) + 1;
}
int main()
{
    int  s,m;
    LinkList L;
    xinjian(&L);
    toucha(L);
    s = f(L->next);
    m = g(L);
    printf("%d", s);
    printf("\n");
    printf("%d", m);
}



