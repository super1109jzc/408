#include<stdio.h>
#define MAXSIZE 100
typedef struct
{
    int elem[MAXSIZE];
    int last;
}SeqList;



//����
void jianli(SeqList* L)
{
    int k, x, i = 0;
    int flag = 1;
    L->last = 0;
    printf("������һ����,����-1��Ϊ�ս᣺");
    while (flag)
    {
        scanf("%d", &x);
        if (x != -1)
        {
            L->elem[i] = x;
            i++;
            L->last++;
        }
        else
            flag = 0;
    }
}

//���
void delete_qingjie(SeqList* L)
{
    int k,i,j=1;
    for (i = 1; i <= L->last; i++)
    {
        if (L->elem[i] != L->elem[i - 1])
        {
            L->elem[j] = L->elem[i];
            j++;
        }
    }
    L->last = j - 1;
    for (k = 0; k < L->last; k++)
    {
        printf("%d  ", L->elem[k]);
    }
}


//����
void travel(SeqList L)
{
    int k;
    for (k = 0; k < L.last; k++)
    {
        printf("%d  ", L.elem[k]);
    }
}

int main()
{
    SeqList L;
    jianli(&L);
    printf("���ɵ�˳������Ϊ��");
    travel(L);
    printf("��������������Ϊ");
    delete_qingjie(&L);
}