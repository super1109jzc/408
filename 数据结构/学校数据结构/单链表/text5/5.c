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

//尾插法
LinkList CreateFromTail() //将新增的字符追加到链表的末尾
{
    LinkList L;
    Node* r, * s;
    int flag = 1;
    int x;
    L = (LinkList)malloc(sizeof(Node));  //生成头节点
    L->next = NULL;
    r = L;                  //r指针始终动态指向链表的当前表尾
    while (flag)           //标志,初值为1,输入'$'时flag为0,建表结束
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


//插入数
int charu(LinkList L, int i, ElemType e)
{
    int k = 0;
    //先找到第i-1个数据元素的存储位置,使指针pre指向它
    Node* pre = L, * s;
    while (pre != NULL && k < i - 1)
    {
        pre = pre->next;
        k = k + 1;
    }
    if (pre == NULL)
    {
        puts("插入位置不合理!");
        return 0;
    }
    s = (LinkList)malloc(sizeof(Node));
    s->data = e;
    s->next = pre->next;
    pre->next = s;          //注意次序及头节点的作用
    return 1;
}

//删除数
int shanchu(LinkList L, int i, int* e)
{
    Node* pre = L, * r;
    int k = 0;
    while (pre->next != NULL && k < i - 1) //寻找被删除结点i的前驱结点
    {
        pre = pre->next;
        k = k + 1;
    }
    if (pre->next == NULL)
    {
        puts("删除结点的位置i不合理!");
        return 0;
    }
    *e = pre->next->data;
    r = pre->next;
    pre->next = r->next;    //删除结点r
    free(r);                  //释放被删除的结点所占的内存空间
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

//单链表释放
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
    printf("请输入一批数，以-1结束，采用首部插入建立链表:");
    p = CreateFromHead();
    printf("输出该链表：");
    Traver(p);
    printf("\n");
    printf("请输入一批数，以-1结束，采用尾部插入建立链表:");
    p = CreateFromTail();
    printf("输出该链表:");
    Traver(p);
    printf("\n");
    printf("请出入待插入的数:");
    scanf("%d", &e);;
    printf("请出入待插入的位置:");
    scanf("%d", &i);
    m = charu(p, i, e);
    if (m == 1)
    {
        printf("输出该链表:");
        Traver(p);
    }
    else
        printf("插入位置错误！");
    printf("\n");
    printf("请出入待删除的数的位置:");
    scanf("%d", &i);
    m = shanchu(p, i, &e);
    if (m == 1)
    {
        printf("输出删除的数:");
        printf("%d",e);
        printf("输出该链表:");
        Traver(p);
    }
    else
        printf("删除位置错误！");
    DesList(p);
    return 0;
}