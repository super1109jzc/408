/*����ƥ��*/
#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100
typedef char StackElementType;
typedef struct
{
    StackElementType  elem[MAXSIZE];
    int top;

} SeqStack, *sqStack;


InitStack(SeqStack *s)//ջ�ĳ�ʼ��
{
    s->top = -1;
}


int push(SeqStack *s, StackElementType x)//��ջ
{
    if (s->top == MAXSIZE - 1)//ջ��ʱ
        return 0;
    s->elem[s->top++] = x;
    return 1;
}


int pop(sqStack s, char* x)//��ջ
{
    if (s->top == -1)//��s->top==0ʱ,˵��ջΪ��
        return 0;
    *x = s->elem[--s->top];
    return 1;
}


int getTops(sqStack s, char *x)//��ջ���õ�һ������
{
    if (s->top == -1)
        return 0;
    else
    {
        *x = s->elem[s->top-1];
    }
}


int match(char ch1, char ch2)//����������Ƿ���������ƥ��
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
    printf("������һ���ַ���:\n");
    scanf("%s",&str);
    char a;
    char ch;
    for (i = 0; str[i] != 0; i++)
    {
        switch (str[i])//�������ַ����е�ÿ���ַ������ж�
        {
        case '{':
        case '[':
        case '('://��ǰ�ַ����Ϊ������,����������ջ
            push(s, str[i]);
            break;
        case '}':
        case ']':
        case ')'://��ǰ�ַ�Ϊ������ʱ

            if (isEmpty(s) == 1)
            {
                printf("����ƥ��ʧ��\n");
                return 0;//���ջΪ�գ����Ų�ƥ��
            }

            getTops(s,&ch);//���ջ��Ϊ�գ���ջ����ȡһ��������
            if (match(ch, str[i]))//����ȡ���������Ƿ��뵱ǰ������ƥ��
            {
                pop(s, &a);//���ƥ��,�������ų�ջ
            }
        }
    }
    if (isEmpty(s) == 1)//��ջ��Ԫ��Ϊ��ʱ,����ƥ��
    {
        printf("����ƥ��ɹ�\n");
        return 1;
    }
    else
    {
        printf("����ƥ��ʧ��\n");
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