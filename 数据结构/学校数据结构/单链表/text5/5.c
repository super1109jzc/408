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

//β�巨
LinkList CreateFromTail() //���������ַ�׷�ӵ������ĩβ
{
    LinkList L;
    Node* r, * s;
    int flag = 1;
    int x;
    L = (LinkList)malloc(sizeof(Node));  //����ͷ�ڵ�
    L->next = NULL;
    r = L;                  //rָ��ʼ�ն�ָ̬������ĵ�ǰ��β
    while (flag)           //��־,��ֵΪ1,����'$'ʱflagΪ0,�������
    {
        scanf("%d", &x);
        if (x != -1)
        {
            s = (LinkList)malloc(sizeof(Node));
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
/*LinkList chazhao1(LinkList L,int i)
{
    int j=1;
    Node *p=L->next;
    while(p!=NULL && j<i)
    {
        p=p->next;
        j++;
    }
    return p;
}


LinkList chazhao2(LinkList L,ElemType m)
{
    Node *p=L->next;
    while(p!=NULL && p->date!=e)
    {
        p=p->next;
    }
    return p;
}*/


//������
int charu(LinkList L, int i, ElemType e)
{
    int k = 0;
    //���ҵ���i-1������Ԫ�صĴ洢λ��,ʹָ��preָ����
    Node* pre = L, * s;
    while (pre != NULL && k < i - 1)
    {
        pre = pre->next;
        k = k + 1;
    }
    if (pre == NULL)
    {
        puts("����λ�ò�����!");
        return 0;
    }
    s = (LinkList)malloc(sizeof(Node));
    s->data = e;
    s->next = pre->next;
    pre->next = s;          //ע�����ͷ�ڵ������
    return 1;
}

//ɾ����
int shanchu(LinkList L, int i, int* e)
{
    Node* pre = L, * r;
    int k = 0;
    while (pre->next != NULL && k < i - 1) //Ѱ�ұ�ɾ�����i��ǰ�����
    {
        pre = pre->next;
        k = k + 1;
    }
    if (pre->next == NULL)
    {
        puts("ɾ������λ��i������!");
        return 0;
    }
    *e = pre->next->data;
    r = pre->next;
    pre->next = r->next;    //ɾ�����r
    free(r);                  //�ͷű�ɾ���Ľ����ռ���ڴ�ռ�
    return 1;
}
void Traver(LinkList p)
{
    Node* s;
    s = p->next;
    while (s)
    {
        printf("%d", s->data);
        s = s->next;
    }
}

//�������ͷ�
void DesList(LinkList L)
{
    Node* s = L, * r;
    r = s->next;
    while (r)
    {
        free(s);
        s = r;
        r = s->next;
    }
    free(s);
}
int main()
{
    LinkList p;
    int m, i;
    int e;
    printf("������һ��������-1�����������ײ����뽨������:");
    p = CreateFromHead();
    printf("���������");
    Traver(p);
    printf("\n");
    printf("������һ��������-1����������β�����뽨������:");
    p = CreateFromTail();
    printf("���������:");
    Traver(p);
    printf("\n");
    printf("�������������:");
    scanf("%d", &e);;
    printf("�����������λ��:");
    scanf("%d", &i);
    m = charu(p, i, e);
    if (m == 1)
    {
        printf("���������:");
        Traver(p);
    }
    else
        printf("����λ�ô���");
    printf("\n");
    printf("������ɾ��������λ��:");
    scanf("%d", &i);
    m = shanchu(p, i, &e);
    if (m == 1)
    {
        printf("���ɾ������:");
        printf("%d",e);
        printf("���������:");
        Traver(p);
    }
    else
        printf("ɾ��λ�ô���");
    DesList(p);
    return 0;
}