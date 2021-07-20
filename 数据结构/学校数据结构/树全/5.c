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
//层次遍历(顺序循环队列） 
void  LevelOrder(BiTree root){
	if(root==NULL) return;
	BitNode *q;
	SeqQueue qu;
	InitQueue(&qu);
	PushSeqQueue(&qu,root);
	while(!IsEmptySeqQueue(&qu)){
		PopSeqQueue(&qu,&q);
		printf("%c",q->data);
		if(q->lchild) PushSeqQueue(&qu,q->lchild);
		if(q->rchild) PushSeqQueue(&qu,q->rchild);
	}
}
void main()
{
	BiTree T;
	T=(BitNode *)malloc(sizeof(BitNode));
	CreatBiTree(&T);
	LevelOrder(T);
}
