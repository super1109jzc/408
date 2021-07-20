#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 100
#define OK 1
#define ERROR 0
typedef int ElemType;
typedef struct
{
    ElemType elem[MAXSIZE];
    int last;
} SeqList;

//����������
void jianli(SeqList* L)
{
    int x, i = 0;
    int flag = 1;
    L->last = 0;
    printf("������һ����������-1��Ϊ�ս᣺");
    while (flag)
    {
        scanf("%d", &x);
        if (x != -1)
        {
            L->elem[i] = x;
            L->last++;
            i++;
        }
        else
            flag = 0;
    }
}

//����
int Locate(SeqList L, ElemType e)
{
    int i = 0;
    while ((i <= L.last) && (L.elem[i] != e))
        i++;
    if (i <= L.last)
        return(i + 1);
    else
        return(-1);
}


//����
int InsList(SeqList* L, int i, ElemType e)
{
    int k;
    if ((i < 1) || (i > L->last + 2))
    {
        printf("�������");
        return(ERROR);
    }
    if (L->last >= MAXSIZE - 1)
    {
        printf("�������");
        return(ERROR);
    }
    for (k = L->last; k >= i - 1; k--)
    {
        L->elem[k + 1] = L->elem[k];
    }
    L->elem[i - 1] = e;
    L->last++;
    return(OK);
}


//ɾ��
int DelList(SeqList* L, int i, ElemType* e)
{
    int k;
    if ((i < 1) || (i > L->last + 1))
    {
        printf("�������");
        return(ERROR);
    }
    *e = L->elem[i - 1];
    for (k = i; k < L->last; k++)
    {
        L->elem[k - 1] = L->elem[k];
    }
    L->last--;
    return(OK);
}

//����
void travel(SeqList L)
{
    int k;
    for (k = 0; k < L.last; k++)
    {
        printf("%d", L.elem[k]);
    }
}


int main()
{
    int t, m, a, b, c;
    int* e;
    SeqList L;
    jianli(&L);
    printf("���ɵ�˳������Ϊ��");
    travel(L);
    printf("������Ҫ���ҵ�����");
    scanf("%d", &t);
    m = Locate(L, t);
    if (m != -1)
    {
        printf("��ʱҪ���ҵ���λ��");
        printf("%d", m);
    }
    else
        printf("�����ҵ���������");
    printf("����������������λ�ã�\n");
    scanf("%d", &a);
    printf("������������������ֵ��\n");
    scanf("%d", &b);
    InsList(&L, a, b);
    printf("���µ�˳������Ϊ��");
    travel(L);
    printf("��������ɾ������λ�ã�\n");
    scanf("%d", &c);
    DelList(&L, c, &e);
    printf("���µ�˳������Ϊ��");
    travel(L);
}
