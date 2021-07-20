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
void PrintSeqStack(SeqStack sq){
	int i;
	if(sq.top==-1) return;
	for(i=0;i<=sq.top;i++)
		printf("%c",sq.elem[i]->data);
	printf("\n");
}
int tag[100]={0};
void outpathR(BiTree T,SeqStack *s,TreeElem r){
	BiTree p;
	while(T){
		PushSeqStack(s,T);
		if(T->lchild==NULL||T->rchild==NULL)
			tag[s->top]=1;
		if(T->data==r)	{PrintSeqStack(*s);exit(0);}
		if(T->lchild==NULL &&T->rchild==NULL) 
		{	
			while(tag[s->top]==1) 
			{
				tag[s->top]=0;
				PopSeqStack(s,&p);
			}
		}	
		else outpathR(T->lchild,s,r);
		T=T->rchild;
	}
}

void main()
{
	BiTree T;
	SeqStack s;
	TreeElem r; 
	InitStack(&s);
	T=(BitNode *)malloc(sizeof(BitNode));
	puts("按照扩展的先序遍历序列输入二叉树的节点的数值域:");
	CreatBiTree(&T);
	puts("请输入r所指数值域：");
	getchar();
	scanf("%c",&r);
	outpathR(T,&s,r);
} 
