/*��֪�����µ�����(a1,a2,a3,a4,��,an)��Ҫ���дһ��ʱ�临�Ӷ�ΪO(n)���ռ临�Ӷ�ΪO(1)���㷨��
���õ�����ת�������½ṹ��an,an-2,����a4,a2,a1,a3, ����an-3,an-1��*/
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
    printf("������һ��������-1�����������ײ����뽨������:");
    p = CreateFromHead();
    printf("���������");
    Traver(p);
    printf("�޸ĺ�Ϊ��");
    chongpai(p);
    Traver(p);
}

