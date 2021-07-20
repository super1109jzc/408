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

//��չ�����������������
/*BiTree CreateBiTreeF()
{
    BiTree bt;
    int x;
    printf("�����������������ֵ��");
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

//����Ҷ�ӽڵ�
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

//�����Ҷ�ӽڵ�
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

//�߶�
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
//����ǰ���������������
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


//����������
void PreOrder(BiTree root)
{
    if (root != NULL)
    {
        printf("%d", root->data);
        PreOrder(root->LChild);
        PreOrder(root->RChild);
    }
}

//����������
void MiddleOrder(BiTree root)
{
    if (root != NULL)
    {
        MiddleOrder(root->LChild);
        printf("%d", root->data);
        MiddleOrder(root->RChild);
    }
}

//����������
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
    printf("������ǰ�������ĸ�����");
    scanf("%d", &size);
    printf("������ǰ��");
    for (i = 0; i < size; i++)
    {
        scanf("%d", &x);
        s1[i] = x;
    }
    printf("����������");
    for (j = 0; j < size; j++)
    {
        scanf("%d", &y);
        s2[j] = y;
    }
    m = FMchuangjian(s1, s2, size);
    printf("�����ɹ���\n");
    k1 = leaf(m);
    printf("��ʱҶ����Ϊ��\n");
    printf("%d", k1);
    k2 = unleaf(m);
    printf("\n��ʱ��Ҷ����Ϊ��\n");
    printf("%d", k2);
    u = gaodu(m);
    printf("\n��ʱ���ĸ߶�Ϊ\n");
    printf("%d", u);
    printf("\nǰ�����\n");
    PreOrder(m);
    printf("\n�������\n");
    MiddleOrder(m);
    printf("\n�������\n");
    LastOrder(m);
}