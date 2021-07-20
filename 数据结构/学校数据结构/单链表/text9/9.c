#include<stdio.h>
#include<stdlib.h>
typedef int ElemType;
typedef struct Node
{
    ElemType data;
    struct Node* prior;
    struct Node* next;
} Node, * LinkList;

LinkList CreateFromTail()
{
    LinkList L;
    LinkList s, r;
    ElemType t;
    int flag = 1;
    L = (LinkList)malloc(sizeof(Node));
    L->next = NULL;
    r = L;
    printf("请输入数据元素:");
    while (flag)
    {
        scanf("%d", &t);
        if (t != -1)
        {
            s = (LinkList)malloc(sizeof(Node));
            s->data = t;
            r->next = s;
            s->prior = r;
            r = s;
        }
        else
        {
            s->next = NULL;
            flag = 0;
        }
    }
    return L;
}
LinkList fanzhuan(LinkList L)
{
    LinkList p1 = L->next;
    LinkList p2 = NULL;
    LinkList pnext;
    while (p1)
    {
        pnext = p1->next;
        p1->next = p2;
        p1->prior = pnext;
        p2 = p1;
        p1 = pnext;
    }
    return p2;
}
void bianli1(LinkList L)
{
    LinkList p;
    p = L->next;
    while (p)
    {
        printf("%d", p->data);
        printf("\n");
        p = p->next;
    }
}

void bianli2(LinkList L)
{
    LinkList p;
    p = L;
    while (p)
    {
        printf("%d", p->data);
        printf("\n");
        p = p->next;
    }
}
void shouhui(LinkList* L)
{
    LinkList p, q;
    p = *L;
    q = p->next;
    while (q != NULL)
    {
        free(p);
        p = q;
        q = p->next;
    }
}

int main()
{
    LinkList L;
    L = CreateFromTail();
    bianli1(L);
    L = fanzhuan(L);
    bianli2(L);
    shouhui(&L);
    return 0;
}
