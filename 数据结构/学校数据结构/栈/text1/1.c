/*括号匹配*/
#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100
typedef char StackElementType;
typedef struct
{
    StackElementType  elem[MAXSIZE];
    int top;

} SeqStack, *sqStack;


InitStack(SeqStack *s)//栈的初始化
{
    s->top = -1;
}


int push(SeqStack *s, StackElementType x)//入栈
{
    if (s->top == MAXSIZE - 1)//栈满时
        return 0;
    s->elem[s->top++] = x;
    return 1;
}


int pop(sqStack s, char* x)//出栈
{
    if (s->top == -1)//当s->top==0时,说明栈为空
        return 0;
    *x = s->elem[--s->top];
    return 1;
}


int getTops(sqStack s, char *x)//从栈顶得到一个括号
{
    if (s->top == -1)
        return 0;
    else
    {
        *x = s->elem[s->top-1];
    }
}


int match(char ch1, char ch2)//检测左括号是否与右括号匹配
{
    if ((ch1 == '(' && ch2 == ')') || (ch1 == '{' && ch2 == '}') || (ch1 == '[' && ch2 == ']'))
        return 1;
    else
        return 0;
}


int isEmpty(sqStack s)
{
    if (s->top == -1)
        return 1;
    else
        return 0;
}


int BracketMatch (sqStack s)
{
    char str[100];
    int i = 0;
    printf("请输入一组字符串:\n");
    scanf("%s",&str);
    char a;
    char ch;
    for (i = 0; str[i] != 0; i++)
    {
        switch (str[i])//挨个对字符串中的每个字符进行判定
        {
        case '{':
        case '[':
        case '('://当前字符如果为左括号,则左括号入栈
            push(s, str[i]);
            break;
        case '}':
        case ']':
        case ')'://当前字符为右括号时

            if (isEmpty(s) == 1)
            {
                printf("括号匹配失败\n");
                return 0;//如果栈为空，括号不匹配
            }

            getTops(s,&ch);//如果栈不为空，从栈顶获取一个左括号
            if (match(ch, str[i]))//看获取的左括号是否与当前右括号匹配
            {
                pop(s, &a);//如果匹配,则左括号出栈
            }
        }
    }
    if (isEmpty(s) == 1)//当栈顶元素为空时,括号匹配
    {
        printf("括号匹配成功\n");
        return 1;
    }
    else
    {
        printf("括号匹配失败\n");
        return 0;
    }
}

int main()
{
    sqStack s;
    char ch1, ch2, x;
    InitStack(&s);
    BracketMatch(s);
    return 0;
}