//����ʹ����ջʵ�ֻ��Ĵ����жϡ�     
#include<stdio.h>
#include<stdlib.h>
#include"malloc.h"
#define FALSE 0
#define TRUE 1
#define Stack_Size 50
typedef struct node
{
	char data;
	struct node* next;
}LinkStackNode;
typedef LinkStackNode* LinkStack;
InitStackList(LinkStack* p)
{
	*p = (LinkStackNode*)malloc(sizeof(LinkStackNode));
	(*p)->next = NULL;
}
int Push(LinkStack p, char x)
{
	LinkStackNode* temp;
	temp = (LinkStackNode*)malloc(sizeof(LinkStackNode));
	if (temp == NULL) return(FALSE);
	temp->data = x;
	temp->next = p->next;
	p->next = temp;
	return(TRUE);
}
int Pop(LinkStack p, char* x)
{
	LinkStackNode* temp;
	temp = p->next;
	if (temp == NULL)
		return(FALSE);
	p->next = temp->next;
	*x = temp->data;
	free(temp);
	return(TRUE);
}
char shoushu(LinkStack p)
{
	return p->next->data;
}
int main()
{
	LinkStack L;
	InitStackList(&L);
	char c, a[Stack_Size];
	int i = 0, j = 0, q,k=0;
	int flag = 1;
	char* x;
	char m;
	printf("�������ַ���������");
	scanf("%d", &q);
	printf("������һ���ַ���,����0Ϊ��β��");
	for (i = 0; i < q; i++)
	{
		scanf("%s", &a[i]);
	}
	while (a[k] != '\0')
	{
		printf("%d", k);
		printf("%c", a[k]);
		Push(L, a[k]);
		k++;
	}
	while (a[j] != '\0')
	{
		m = shoushu(L);
		if (a[j] != m)
		{
			flag = 0;
			break;
		}
		Pop(L, &x);
		j++;
	}
	if (flag==1)
		printf("��");
	else
		printf("����");
	return 0;
}
