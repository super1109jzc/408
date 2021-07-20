/*六、已知递归函数如下：
要求：*/

#include<stdio.h>
#include<stdlib.h>

//（1）编写递归算法
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
    printf("请输入您的第一个元素：");
    scanf("%d",&x);
    printf("请输入您的第二个元素：");
    scanf("%d",&y);
    s=g(x,y);
    printf("您得到的数为：");
    printf("%d",s);
}*/

//（2）将递归算法改为非递归算法
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
    printf("请输入您的第一个元素：");
    scanf("%d", &x);
    printf("请输入您的第二个元素：");
    scanf("%d", &y);
    s = g(x, y);
    printf("您得到的数为：");
    printf("%d", s);
}