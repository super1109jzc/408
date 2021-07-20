#include<stdio.h>
#include<stdlib.h>
#include"malloc.h"
#include<math.h>
#include<stdbool.h>
#define FALSE 0
#define TRUE 1
#define Stack_Size 50

typedef struct node
{
	int data;
	struct node* next;
}LinkStackNode;
typedef LinkStackNode* LinkStack;


InitStackList(LinkStack* p)
{
	*p = (LinkStackNode*)malloc(sizeof(LinkStackNode));
	(*p)->next = NULL;
}

int Push(LinkStack p, int x)
{
	LinkStackNode* temp;
	temp = (LinkStackNode*)malloc(sizeof(LinkStackNode));
	if (temp == NULL) return(FALSE);
	temp->data = x;
	temp->next = p->next;
	p->next = temp;
	return(TRUE);
}

int Pop(LinkStack p, int* x)
{
	LinkStackNode* temp;
	temp = p->next;
	if (temp == NULL)
		return(FALSE);
	*x = temp->data;
	p->next = temp->next;
	free(temp);
	return(TRUE);
}

/*int GetNumber(char ch[])
{
	return ch - '0';
}*/
int GetNumber(char ch[])
{
	int n = strlen(ch);
	int x = 0, t = 1, i;
	for (i = n - 1; i >= 0; i--)
	{
		x += (ch[i] - '0') * t;
		t *= 10;
	}
	return x;
}

bool IsEmpty(LinkStack top)
{
	if (top->next == NULL)
	{
		return false;
	}
	else
		return true;
}

int In(char ch)
{
	if (ch == '-' || ch == '+' || ch == '*' || ch == '/' || ch == '#' || ch == '^' || ch == '(' || ch==')')
		return(1);
	else
		return(0);
}

int GetTop(LinkStack top)
{
	if (top->next == NULL)
	{
		return 1;
	}
	else
		return top->next->data;
}

char Compare(char ch1, char ch2)
{
	switch (ch1)
	{
	case'#':
		switch (ch2) {
		case '#':return '=';
		case '+':
		case '-':
		case '*':
		case '/':
		case '^':
		case ')':
		case '(':return '<';
		}
	case'+':
		switch (ch2) {
		case '#':
		case '(':
		case ')':return '>';
		case '+':
		case '-':
		case '*':
		case '/':
		case '^':return '<';
		
		}
	case'-':
		switch (ch2) {
		case '#':
		case '(':
		case ')':return '>';
		case '+':
		case '-':
		case '*':
		case '/':
		case '^':return '<';

		}
	case'*':
		switch (ch2) {
		case '#':
		case '+':
		case '-':
		case '(':return '>';
		case '*':
		case '/':
		case '^':
		case ')':return '<';
		}
	case'/':
		switch (ch2) {
		case '#':
		case '+':
		case '-':return '>';
		case '*':
		case '/':
		case '^':
		case ')':
		case '(':return '<';
		}
	case'^':
		switch (ch2) {
		case '#':
		case '+':
		case '-':
		case '*':
		case '/':return '>';
		case '^':
		case ')':
		case '(':return '<';
		}
	case'(':
		switch (ch2) {
		case '#':
		case '+':
		case '-':
		case '*':
		case '/':
		case '^':return '>';
		case ')':
		case '(':return '=';
		}
	case')':
		switch (ch2) {
		case '#':
		case '+':
		case '-':
		case '*':
		case '/':
		case '^':return '<';
		case '(':
		case ')':return '=';
		}
	}
}

int Execute(int a, char op, int b)
{
	int c;
	switch (op)
	{
	case '-':c = a - b; break;
	case '+':c = a + b; break;
	case '*':c = a * b; break;
	case '/':c = a / b; break;
	case '^':c = pow(a, b); break;
	default:c = 0;
	}
	return c;
}

int ExpEvaluation()
{
	LinkStack OPTR, OVS;
	int n, a, op, b, v;
	char ch[11];
	InitStackList(&OPTR);
	InitStackList(&OVS);
	Push(OPTR, '#');
	printf("请输入一组计算式，并以#为终结：");
	scanf("%s", ch);
	while (ch[0] != '#' || GetTop(OPTR) != '#')
	{
		if (!In(ch[0]))
		{
			n = GetNumber(ch);
			Push(OVS, n);
			scanf("%s", ch);
		}

		else
			switch (Compare(ch[0], GetTop(OPTR)))
			{
			case '>':Push(OPTR, ch[0]);
				scanf("%s", ch);
				break;
			case '=':Pop(OPTR,&op);
				scanf("%s", ch);
				break;
			case '<':
			    Pop(OPTR, &op);
				Pop(OVS, &b);
				Pop(OVS, &a);
				v = Execute(a, op, b);
				Push(OVS, v);
				break;
			}
	}
	v = GetTop(OVS);
	return(v);
}

int main()
{
	int ans = ExpEvaluation();
	printf("%d", ans);
	return 0;
}