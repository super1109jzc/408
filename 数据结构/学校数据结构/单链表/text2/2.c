#include<stdio.h>
#define MAXSIZE 100
typedef struct
{
    int elem[MAXSIZE];
    int last;
} SeqList;

//建立
void jianli(SeqList* L)
{
    int k, x, i = 0;
    int flag = 1;
    L->last = 0;
    printf("请输入一组数,并以-1作为终结：");
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

//奇偶排序
void jio_paixu(SeqList *L)
{
    int i, m, t;
    int j = 0;
    for (i = 0; i < L->last; i++)
    {
        if (L->elem[i]%2 == 1)
        {
            m = L->elem[i];
            t = L->elem[j];
            L->elem[j] = m;
            L->elem[i] = t;
            j++;
        }
    }
}



//遍历
void travel(SeqList L)
{
    int k;
    for (k = 0; k < L.last; k++)
    {
        printf("%d ", L.elem[k]);
    }
}


int main()
{
    SeqList L;
    jianli(&L);
    printf("建成的顺序链表为：");
    travel(L);
    printf("奇偶排序后链表为：");
    jio_paixu(&L);
    travel(L);
}
