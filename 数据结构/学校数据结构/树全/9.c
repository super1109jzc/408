#include <stdio.h>
#include <stdlib.h> 
#include "QueStack.h"
void CreatBiTree(BiTree *T){//按先序序列建立二叉树的二叉链表
	char c;
	scanf("%c",&c);
	if(c=='.') *T=NULL;
	else
	{
		*T=(BiTree)malloc(sizeof(BitNode));
		(*T)->data = c;
		CreatBiTree(&(*T)->lchild);
		CreatBiTree(&(*T)->rchild);	
	}
} 
void path(SeqStack sq,char *ch){
	int i;
	if(sq.top==-1) return;
	for(i=0;i<=sq.top;i++)
		ch[i]=sq.elem[i]->data;
	ch[i]=0;
}
void findroot(char *ch1,char *ch2){
	int i=0,j;
	while(ch1[i]) i++;
	i--;
	for(i;i>=0;i--)
		for(j=0;ch2[j];j++)
		{
			if(ch1[i]==ch2[j])
			{
				printf("%c",ch1[i]);
				i=-1;
				break;
			}
		}
}
int tag[100]={0};
int flag=0;
void Findfirstroot(BiTree T,SeqStack *s,char *ch1,char *ch2,TreeElem r1,TreeElem r2){
	BiTree p;
	while(T){
		PushSeqStack(s,T);
		if(T->lchild==NULL||T->rchild==NULL)
			tag[s->top]=1;
		if(T->data==r1)
		{
			path(*s,ch1);
			flag++;
		}
		else if(T->data==r2)
		{
			path(*s,ch2);
			flag++;
		}
		if(flag==2) 
		{
			findroot(ch1,ch2);
			exit(0);
		}
		if(T->lchild==NULL &&T->rchild==NULL) 
		{	
			while(tag[s->top]==1) 
			{
				tag[s->top]=0;
				PopSeqStack(s,&p);
			}
		}		
		else Findfirstroot(T->lchild,s,ch1,ch2,r1,r2);
		T=T->rchild;
	}
}
void main()
{
	BiTree T;
	SeqStack s;
	TreeElem r1,r2;
	char ch1[100],ch2[100];
	InitStack(&s);
	T=(BitNode *)malloc(sizeof(BitNode));
	puts("按照扩展的先序遍历序列输入二叉树的节点的数值域:");
	CreatBiTree(&T);
	puts("请输入两个节点：");
	getchar();
	scanf("%c%c",&r1,&r2);
	Findfirstroot(T,&s,ch1,ch2,r1,r2);
} 
