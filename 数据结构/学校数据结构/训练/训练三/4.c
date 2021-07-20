#include <stdio.h>
#include <stdlib.h>
typedef int Elemtype;
typedef struct Node
{
    Elemtype data;
    struct Node* next;
} Node, * LinkList;


LinkList pairen(int x)
{  
    LinkList L = (Node*)malloc(sizeof(Node));
    L->data = 1;
    L->next = L;
    LinkList r, s;
    int i ;
    int flag = 1;
    r = L;
    Elemtype a;
    
    for (i = 2; i <= x; i++)
    {
        s = (Node*)malloc(sizeof(Node));
        s->data = i;
        r->next = s;
        r = s;
    }
    r->next = L;
    return L;
}

void yuesefuhuan(LinkList head,  int m)
{
    Node* tail = head, * p = head;
    while (tail->next != head) 
    {
        tail = tail->next;
    }
    while (p->next != p) 
    {
        for (int i = 1; i < m; i++)
        {
            tail = p;
            p = p->next;
        }
        tail->next = p->next;
        printf("出列人的编号为:%d\n", p->data);
        free(p);
        p = tail->next;
    }
    printf("出列人的编号为:%d\n", p->data);
    free(p);
}

int main() 
{
    LinkList L,T;
    int x;
    printf("请输入圆桌上的人数:");
    scanf("%d", &x);
    T=pairen(x);
    printf("数到m的人出列：");
    int m;
    scanf("%d", &m);
    yuesefuhuan(T, m);
    return 0;
}