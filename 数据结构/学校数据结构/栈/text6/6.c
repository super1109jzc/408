/*������֪�ݹ麯�����£�
Ҫ��*/

#include<stdio.h>
#include<stdlib.h>

//��1����д�ݹ��㷨
/*int g(int m,int n)
{
    if(m==0 && n>=0)
    {
        return m;
    }
    if(m>0 && n>=0)
    {
        return g(m-1,2*n)+n;
    }
}
int main()
{
    int x,y,s;
    printf("���������ĵ�һ��Ԫ�أ�");
    scanf("%d",&x);
    printf("���������ĵڶ���Ԫ�أ�");
    scanf("%d",&y);
    s=g(x,y);
    printf("���õ�����Ϊ��");
    printf("%d",s);
}*/

//��2�����ݹ��㷨��Ϊ�ǵݹ��㷨
int g(int m, int n)
{
    int p = 0;
    while (m > 0 && n >= 0)
    {
        p = p + n;
        m--;
        n = n * 2;
    }
    return p;
}
int main()
{
    int x, y, s;
    printf("���������ĵ�һ��Ԫ�أ�");
    scanf("%d", &x);
    printf("���������ĵڶ���Ԫ�أ�");
    scanf("%d", &y);
    s = g(x, y);
    printf("���õ�����Ϊ��");
    printf("%d", s);
}