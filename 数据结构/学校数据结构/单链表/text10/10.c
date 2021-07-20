#include <stdio.h>
#include <stdlib.h>
#define Elemtype int
int z = 0;
typedef struct Node
{
    Elemtype data1;
    Elemtype data2;
    struct Node* next;
} Node, * LinkList;
void Initlist(LinkList* L)
{
    *L = (LinkList)malloc(sizeof(Node));
    (*L)->next = *L;
}
void CreateTail(LinkList L)
{
    LinkList r, s;
    int i = 0;
    int flag = 1;
    r = L;
    Elemtype a, b;
    while (flag)
    {
        scanf("%d%d", &a, &b);
        if (a != 0 && b != 0)
        {
            s = (Node*)malloc(sizeof(Node));
            s->data1 = a;
            s->data2 = b;
            r->next = s;
            r = s;
            i++;
        }
        else
        {
            flag = 0;
            r->next = L;
        }
    }
}

void jiopaixu(LinkList L)
{
    Node* q, * p, * m, * t, * v;
    q = L->next;
    p = L;
    v = L->next;
    m = q->next;
    while (q->next != L && q != L)
    {
        q->next = m->next;
        m->next = v;
        p->next = m;
        p = m;
        q = q->next;
        m = q->next;
        p = L->next;
        z++;
    }
}
void bianli1(LinkList L)
{
    LinkList p, v;
    p = L->next;
    v = L;
    while (p != v)
    {
        printf("%dx^%d", p->data1, p->data2);
        p = p->next;
    }
}

void bianli2(LinkList L)
{
    LinkList p, v;
    p = L->next;
    v = L;
    int i = 0;
    while (i++ < z)
    {
        printf("%dx^%d", p->data1, p->data2);
        p = p->next;
    }
    printf("/n");
    while (p != v)
    {
        printf("%dx^%d", p->data1, p->data2);
        p = p->next;
    }
    printf("/n");
}
int main()
{
    LinkList L;
    Initlist(&L);
    printf("请您依次输入每个单项式的系数、指数：\n");
    CreateTail(L);
    bianli1(L);
    jiopaixu(L);
    bianli2(L);
    printf("/n");
    return 0;
}