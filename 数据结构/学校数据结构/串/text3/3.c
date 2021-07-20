#include <stdio.h>
#include <stdlib.h>
#define MAXline 100
#define MAXpage 50

typedef struct node
{
    char data[50];
    struct node* next;
}strnode;

typedef struct head
{
    strnode* next;
    int length;
    int number;
}headnode;

typedef struct page
{
    headnode Head[MAXline];
    headnode* next;
    int length1;
    int pagenumber;
}pagee;
pagee k[MAXpage];

void Init()
{
    int i, j;
    for (i = 0; i < MAXpage; i++)
    {
        for (j = 0; j < MAXline; j++)
        {
            k[i].Head[j].length = 0;
        }       
    }
}

void HeadWord()
{

    printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\n\n");
    printf("\t\t****    Welcom to use our TXT edition system!    ****\n");
    printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\n\n");
}

void jiemian()
{
    printf("\n\n\t\t\t\t\t\t\t���б༭����");
    printf("\n\n\t\t\t\t\t\t\t��ӭ��ʹ�ã�");
    printf("\n\n\t\t\t\t\t\t�����ߣ���Ϣ1903����֣�\n");
    printf("\n\n\n\n\n\n\n\n\npress Enter to continue...");
    getchar();
    system("cls");
}

int Menu() 
{ 
    int t;
    HeadWord();
    printf("\n");
    printf("\t\t ____________________________________________________\n");
    printf("\t\t|                 �б༭�������˵�                     |\n");
    printf("\t\t|                                                    |\n");
    printf("\t\t|----> ����1��������������                             |\n");
    printf("\t\t|----> ����2��ɾ��ĳһҳ��ĳһ��                       |\n");
    printf("\t\t|----> ����3����ʾ��ǰ��������                         |\n");
    printf("\t\t|----> ����4�������ַ�����λ��                         |\n");
    printf("\t\t|----> ����5���˳��ı��༭��                           |\n");
    printf("\t\t|                                                    |\n");
    printf("\t\t|    ע���밴������ֵ���ʾ����                          |\n");
    printf("\t\t|____________________________________________________|\n");
    printf("  \t\t  ��ѡ��:");
    scanf("%d", &t);
    while (t > 6 || t <= 0)
    {
        printf("�������������������\n"); 
        scanf("%d", &t);
    } 
    return t;
}

void input()
{
    strnode* p;
    headnode* t;
    int i, a, j, m, LineNum, PageNum;
    char ch;
    while (1)
    {
        j = -1;
        a = 1;
        printf("\t\t������ҳ���ţ�1-10��***������һ���������10����***\n");
        printf("\t\t");
        scanf("%d", &PageNum);
        if (PageNum < 0 || PageNum >= MAXpage)
        {
            return;
        }
        printf("\t\t�������кţ�1-100��***���ز˵��������100����***\n");
        printf("\t\t");
        scanf("%d", &LineNum);
        if (LineNum < 0 || LineNum >= MAXline)
        {
            return;
        }
        printf("\t\t��������ѡҳ�е����ݣ�����#���ս�\n");
        i = LineNum;
        m = PageNum;
        k[m].pagenumber = PageNum;
        k[m].next = (strnode*)malloc(sizeof(strnode));
        k[m].Head[i].number = LineNum;
        k[m].Head[i].next = (headnode*)malloc(sizeof(headnode));
        p = k[m].Head[i].next;
        p->next = NULL;
        t = k[m].next;
        t->next = NULL;
        printf("\t\t");
        ch = getchar();
        while (ch != '#')
        {
            j++;
            if (j >= 500)
            {
                p->next = (strnode*)malloc(sizeof(strnode));
                p->next->next = NULL;
                p = p->next;
            }
            p->data[j % 500] = ch;
            ch = getchar();
        }
        k[m].Head[i].length = j + 1;
    }
}

void Find()
{
    int x, i, m, n, e, o1, o2;
    char y, q[100];
    int flag = 1;
    printf("\t\t����������ҵ��ַ�����\t\n");
    scanf("%d", &x);
    printf("\t\t����������ҵ��ַ�\t\n");
    for (i = 0; i <= x; i++)
    {
        scanf("%c", &y);
        q[i] = y;
    }
    printf("\t\t|>>________________________________________________<<|\n");
    for (m = 0; m <= MAXpage; m++)
    {
        for (n = 0; n <= MAXline; n++)
        {
            for (e = 0; e < x; e++)
            {
                if (k[m].Head[n].length>0 && k[m].Head[n].next->data[e] == q[e])
                {
                    flag = 0;
                    o1 = m;
                    o2 = n;
                }
            }          
        }
    } 
    if (flag == 0)
    {
        printf("\t\t�ַ�����ҳΪ��");
        printf("%d", o1);
        printf("\t\t�ַ�������Ϊ��");
        printf("%d", o2);
    }
    
}
void Delline()
{
    strnode* p, * q;
    headnode* t, * r;
    int i, j,a=0, LineNum, PageNum;
    while (1)
    {
        printf("\t\t������ҳ���ţ�1-10��***������һ���������10����***\n");
        printf("\t\t");
        scanf("%d", &PageNum);
        if (PageNum < 0 || PageNum >= MAXpage)
        {
            return;
        }
        printf("\t\t�������кţ�1-100��***���ز˵��������100����***\n");
        printf("\t\t");
        scanf("%d", &LineNum);
        if (LineNum < 0 || LineNum >= MAXline)
        {
            return;
        }
        i = LineNum;
        j = PageNum;
        p = k[j].Head[i].next;
        if (k[j].Head[i].length > 0)
        {
            while (p != NULL && a<1)
            {
                q = p->next;
                free(p);
                p = q;
                a++;
            }
            k[j].Head[i].length = 0;
            k[j].Head[i].number = 0;
        }
    }
}

void TiHuan()
{
    char at[3];
    strnode* p, * q;
    headnode* t, * r;
    int i, j, t1, a = 0, LineNum, PageNum;
    while (1)
    {
        printf("\t\t������ҳ���ţ�1-10��***������һ���������10����***\n");
        printf("\t\t");
        scanf("%d", &PageNum);
        if (PageNum < 0 || PageNum >= MAXpage)
        {
            return;
        }
        printf("\t\t�������кţ�1-100��***���ز˵��������100����***\n");
        printf("\t\t");
        scanf("%d", &LineNum);
        if (LineNum < 0 || LineNum >= MAXline)
        {
            return;
        }
        i = LineNum;
        j = PageNum;
        p = k[j].Head[i].next;
        printf("\t\t������һ���µ�3λ���飺\n");
        for (i = 0; i < 3; i++)
        {
            scanf("%c", at[i]);
        }
        if (k[j].Head[i].length > 0)
        {
            for (t1 = 0; t1 < 3; t1++)
            {
                p->data[t1] = at[t1];
            }
        }
    }
}

void List()
{
    strnode* p;
    int i, j, m, n, e;
    for (j = 0; j < MAXpage; j++)
    {
        for (i = 0; i < MAXline; i++)
        {
            if (k[j].Head[i].length > 0)
            {
                printf("\n");
                printf("\n\t\tҳ��%d", k[j].pagenumber);
                printf("\n");
                printf("\n\t\t����%d", k[j].Head[i].number);
                printf("\n");
                n = k[j].Head[i].length;
                m = 1;
                p = k[j].Head[i].next;
                printf("\t\t��ʱ����õ�������������������Ϊ��");
                for (e = 0; e < n; ++e)
                {
                    if (e >= 50 * m)
                    {
                        p = p->next;
                        ++m;
                    }
                    else
                    {                     
                        printf("%c", p->data[e % 50]);
                    }
                }
            }
        }
    }
    printf("\n");
}

int main()
{
    int sel;
    jiemian();
    Init();
    while (1) 
    {
        sel = Menu();
        switch (sel)
        {
        case 1:
            HeadWord();
            input();       
            break;
        case 2:
            Delline();
            break;
        case 3:
            HeadWord();
            printf("\n\t\t ____________________��������Ϊ______________________\n");
            printf("\n");
            getchar();
            List();                    
            break;
        case 4:
            Find();
            break;
        case 5:
            exit(0);
        case 6:
            TiHuan();
        }
    }
    return 0;
}