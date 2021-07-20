#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100
typedef int StackElementType;
typedef struct
{
    StackElementType  elem[MAXSIZE];
    int top;

} SeqStack, * sqStack;


InitStack(SeqStack* s)//栈的初始化
{
    s->top = -1;
}


int push(SeqStack* s, StackElementType x)//入栈
{
    if (s->top == MAXSIZE - 1)//栈满时
        return 0;
    s->top++;
    s->elem[s->top] = x;
    return 1;
}


int pop(sqStack s, StackElementType* x)//出栈
{
    if (s->top == -1)//当s->top==0时,说明栈为空
        return 0;
    *x = s->elem[s->top];
    s->top--;
    return 1;
}

int isEmpty(sqStack s)
{
    if (s->top == -1)
        return 1;
    else
        return 0;
}

void jinzhihua(int m, int r)
{
    SeqStack s;
    int x;
    InitStack(&s);
    while (m)
    {
        push(&s, m % r);
        m = m / r;
    }
    while (!isEmpty(&s))
    {
        pop(&s, &x);
        printf("%d", x);
    }
}
int main()
{
    int m, r;
    sqStack s;
    InitStack(&s);
    printf("请输入要转换的数：");
    scanf("%d", &m);
    printf("请输入要转换的进制：");
    scanf("%d", &r);
    jinzhihua(m, r);

}