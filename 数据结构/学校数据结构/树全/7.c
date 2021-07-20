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
void outpath(BiTree T,SeqStack *s){
	BiTree p;
	while(T){
		PushSeqStack(s,T);
		if(T->lchild==NULL||T->rchild==NULL)
			tag[s->top]=1;
		if(T->lchild==NULL &&T->rchild==NULL) 
		{	
			PrintSeqStack(*s);
			while(tag[s->top]==1) 
			{
				tag[s->top]=0;
				PopSeqStack(s,&p);
			}
		}		
		else outpath(T->lchild,s);
		T=T->rchild;
	}
}
void main()
{
	BiTree T;
	SeqStack s;
	InitStack(&s);
	T=(BitNode *)malloc(sizeof(BitNode));
	puts("按照扩展的先序遍历序列输入二叉树的节点的数值域:");
	CreatBiTree(&T);
	outpath(T,&s);
} 
