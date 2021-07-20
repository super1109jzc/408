/*七、已知单链表f中存储的都是整型数，请实现下列运算的递归算法。
（1）求链表的最大整数
（2）求链表节点的个数（注意：不计算头节点）*/
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
    printf("请输入一组数：");
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



