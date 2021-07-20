#include<stdio.h>
#include<stdlib.h>
typedef int ElemType;
typedef struct Node
{
    ElemType data;
    struct Node* next;
} Node, * LinkList;


//输入
LinkList headcreate()
{
    LinkList L;
    Node* s;
    int x;
    int flag = 1;
    L = (LinkList)malloc(sizeof(Node));
    L->next = NULL;
    while (flag)
    {
        scanf("%d", &x);
        if (x != -1)
        {
            s = (LinkList)malloc(sizeof(Node));
            s->data = x;
            s->next = L->next;
            L->next = s;
        }
        else
            flag = 0;
    }
    return L;
}

//长度确认
int changdu(LinkList L)
{
    int m = 0;
    while (L->next != NULL)
    {
        L = L->next;
        m++;
    }
    return m;
}
//后序查找
void lastfind(LinkList L, int k)
{
    int i, t, r;
    r = changdu(L);
    for (i = 0; i < r - k + 1; i++)
    {
        L = L->next;
        t = L->data;
    }
    printf("这个数为：");
    printf("%d", t);
}
//遍历
void travel(LinkList L)
{
    Node* s = L->next;
    while (s)
    {
        printf("%d", s->data);
        s = s->next;
        printf("\n");
    }
}

int main()
{
    int m, k;
    LinkList p;
    printf("请输入一组数：");
    p = headcreate();
    printf("此时链表为：");
    travel(p);
    printf("请输入您想查找倒数第几位元素");
    scanf("%d", &k);
    lastfind(p, k);
}
