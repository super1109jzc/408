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
        printf("�����˵ı��Ϊ:%d\n", p->data);
        free(p);
        p = tail->next;
    }
    printf("�����˵ı��Ϊ:%d\n", p->data);
    free(p);
}

int main() 
{
    LinkList L,T;
    int x;
    printf("������Բ���ϵ�����:");
    scanf("%d", &x);
    T=pairen(x);
    printf("����m���˳��У�");
    int m;
    scanf("%d", &m);
    yuesefuhuan(T, m);
    return 0;
}