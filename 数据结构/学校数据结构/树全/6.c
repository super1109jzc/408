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
int  LenthTree(BiTree root){
	if(root==NULL) return 0;
	BitNode *q;
	SeqQueue qu;
	int max=1,m=0,n;
	InitQueue(&qu);
	PushSeqQueue(&qu,root);
	n=1;
	while(!IsEmptySeqQueue(&qu)){
		PopSeqQueue(&qu,&q);
		n--;
		if(q->lchild) {PushSeqQueue(&qu,q->lchild);m++;}
		if(q->rchild) {PushSeqQueue(&qu,q->rchild);m++;}
		if(m>max) max=m;
		if(n==0) {n=m;m=0;}	
	}
	return max;
}
void main()
{
	BiTree T;
	T=(BitNode *)malloc(sizeof(BitNode));
	CreatBiTree(&T);
	printf("%d",LenthTree(T));
}
