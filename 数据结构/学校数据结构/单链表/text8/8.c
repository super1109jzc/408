/*已知由如下单链表(a1,a2,a3,a4,…,an)，要求编写一个时间复杂度为O(n)，空间复杂度为O(1)的算法，
将该单链表转换成如下结构（an,an-2,…，a4,a2,a1,a3, …，an-3,an-1）*/
#include<stdio.h>
#include<stdlib.h>
typedef int ElemType;
typedef struct Node
{
    ElemType data;
    struct Node* next;
} Node;
typedef struct Node* LinkList;

LinkList CreateFromHead()
{
    LinkList L;
    Node* s;
    int flag = 1;
    int x;
    L = (LinkList)malloc(sizeof(Node));
    L->next = NULL;
    while (flag)
    {
        scanf("%d", &x);
        if (x != -1)
        {
            s = (Node*)malloc(sizeof(Node));
            s->data = x;
            s->next = L->next;
            L->next = s;
            //scanf("%d",&x);
        }
        else
            flag = 0;
    }

    return L;
}
void chongpai(LinkList L)
{
    LinkList tmp, p, pre, a, s;
    pre = L->next;
    a = pre;
    p = pre->next;
    while (p)
    {
        pre->next = p->next;
        p->next = a;
        L->next = p;
        pre = pre->next;
        p = pre->next;
        a = L->next;
    }
}

void Traver(LinkList p)
{
    Node* s;
    s = p->next;
    while (s)
    {
        printf("%d", s->data);
        s = s->next;
        printf("\n");
    }
}

int main()
{
    int left, right, s[100];
    LinkList t1, t2, t3;
    LinkList p;
    printf("请输入一批数，以-1结束，采用首部插入建立链表:");
    p = CreateFromHead();
    printf("输出该链表：");
    Traver(p);
    printf("修改后为：");
    chongpai(p);
    Traver(p);
}

