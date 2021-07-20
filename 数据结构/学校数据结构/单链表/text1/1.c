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

//建立单链表
void jianli(SeqList* L)
{
    int x, i = 0;
    int flag = 1;
    L->last = 0;
    printf("请输入一组数，并以-1作为终结：");
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

//查找
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


//插入
int InsList(SeqList* L, int i, ElemType e)
{
    int k;
    if ((i < 1) || (i > L->last + 2))
    {
        printf("输入错误！");
        return(ERROR);
    }
    if (L->last >= MAXSIZE - 1)
    {
        printf("输入错误！");
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


//删除
int DelList(SeqList* L, int i, ElemType* e)
{
    int k;
    if ((i < 1) || (i > L->last + 1))
    {
        printf("输入错误！");
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

//遍历
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
    printf("建成的顺序链表为：");
    travel(L);
    printf("请输入要查找的数：");
    scanf("%d", &t);
    m = Locate(L, t);
    if (m != -1)
    {
        printf("此时要查找的数位于");
        printf("%d", m);
    }
    else
        printf("您查找的数不存在");
    printf("请输入您插入数的位置：\n");
    scanf("%d", &a);
    printf("请输入您插入数的数值：\n");
    scanf("%d", &b);
    InsList(&L, a, b);
    printf("最新的顺序链表为：");
    travel(L);
    printf("请输入您删除数的位置：\n");
    scanf("%d", &c);
    DelList(&L, c, &e);
    printf("最新的顺序链表为：");
    travel(L);
}
