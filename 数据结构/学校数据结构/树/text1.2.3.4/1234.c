#include<stdio.h>
#include<stdlib.h>
typedef int DataType;
int unleafcount = 0;
typedef struct Node
{
    DataType data;
    struct Node* LChild;
    struct Node* RChild;
} BiTNode, * BiTree;

//扩展的先序遍历序列输入
/*BiTree CreateBiTreeF()
{
    BiTree bt;
    int x;
    printf("请依次输入二叉树的值：");
    scanf("%d", &x);
    if (x == -1)
    {
        bt = NULL;
    }
    else
    {
        bt = (BiTree)malloc(sizeof(BiTNode));
        bt->data = x;
        bt->LChild = CreateBiTreeF();
        bt->RChild = CreateBiTreeF();
    }
    return bt;
}*/

//计算叶子节点
int leaf(BiTree root)
{
    int leafcount;
    if (root == NULL)
    {
        leafcount = 0;
    }
    else if ((root->LChild == NULL) && (root->RChild == NULL))
    {
        leafcount = 1;
    }
    else
        leafcount = leaf(root->LChild) + leaf(root->RChild);
    return leafcount;
}

//计算非叶子节点
int unleaf(BiTree root)
{
    if (root != NULL)
    {
        if (root->LChild != NULL || root->RChild != NULL)
        {
            unleafcount++;
        }
        unleaf(root->LChild);
        unleaf(root->RChild);

    }
    return unleafcount;
}

//高度
int gaodu(BiTree root)
{
    if (root == NULL)
    {
        return 0;
    }
    else if (root->LChild == NULL && root->RChild == NULL)
    {
        return 1;
    }
    else
    {
        int x1, x2;
        x1 = gaodu(root->LChild);
        x2 = gaodu(root->RChild);
        if (x1 > x2)
            return x1 + 1;
        else
            return x2 + 1;
    }
}
//根据前序和中序创立二叉树
BiTree FMchuangjian(int s1[], int s2[], int size)
{
    if (size == 0)
    {
        return NULL;
    }
    int i, t, sum;
    BiTree bt, m;
    t = s1[0];
    sum = -2;
    for (i = 0; i < size; i++)
    {
        if (s2[i] == t)
        {
            sum = i;
        }
    }
    if (sum == -2)
    {
        return NULL;
    }
    bt = (BiTree)malloc(sizeof(BiTNode));
    bt->data = t;
    bt->LChild = FMchuangjian(s1 + 1, s2, sum);
    bt->RChild = FMchuangjian(s1 + sum + 1, s2 + sum + 1, size - 1 - sum);
    return bt;
}


//先序遍历输出
void PreOrder(BiTree root)
{
    if (root != NULL)
    {
        printf("%d", root->data);
        PreOrder(root->LChild);
        PreOrder(root->RChild);
    }
}

//中序遍历输出
void MiddleOrder(BiTree root)
{
    if (root != NULL)
    {
        MiddleOrder(root->LChild);
        printf("%d", root->data);
        MiddleOrder(root->RChild);
    }
}

//后序遍历输出
void LastOrder(BiTree root)
{
    if (root != NULL)
    {
        LastOrder(root->LChild);
        LastOrder(root->RChild);
        printf("%d", root->data);
    }
}

int main()
{
    int size, i, j, x, y, k1, k2, u;
    int s1[100], s2[100];
    BiTree m;
    //m = CreateBiTreeF();
    printf("请输入前序和中序的个数：");
    scanf("%d", &size);
    printf("请输入前序：");
    for (i = 0; i < size; i++)
    {
        scanf("%d", &x);
        s1[i] = x;
    }
    printf("请输入中序：");
    for (j = 0; j < size; j++)
    {
        scanf("%d", &y);
        s2[j] = y;
    }
    m = FMchuangjian(s1, s2, size);
    printf("建立成功！\n");
    k1 = leaf(m);
    printf("此时叶子数为：\n");
    printf("%d", k1);
    k2 = unleaf(m);
    printf("\n此时非叶子数为：\n");
    printf("%d", k2);
    u = gaodu(m);
    printf("\n此时树的高度为\n");
    printf("%d", u);
    printf("\n前序遍历\n");
    PreOrder(m);
    printf("\n中序遍历\n");
    MiddleOrder(m);
    printf("\n后序遍历\n");
    LastOrder(m);
}