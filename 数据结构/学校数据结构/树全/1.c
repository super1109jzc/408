#include <stdio.h>
#include <stdlib.h> 
typedef char Elemtype;
typedef struct Node{
	Elemtype data;
	struct Node *lchild,*rchild;
}BitNode,*BiTree;
//递归算法 
void Visit(Elemtype d){
	printf("%c",d);
}
void PreOrder(BiTree root){
	if(root==NULL) return;
	Visit(root->data);
	PreOrder(root->lchild);
	PreOrder(root->rchild);
}
void InOrder(BiTree root){
	if(root==NULL) return;
	InOrder(root->lchild);
	Visit(root->data);
	InOrder(root->rchild);
}
void PostOrder(BiTree root){
	if(root==NULL) return;
	PostOrder(root->lchild);
	PostOrder(root->rchild);
	Visit(root->data);
}
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
void main()
{
		BiTree T;
		T=(BitNode *)malloc(sizeof(BitNode));
		CreatBiTree(&T);
		PreOrder(T);
		printf("\n");
		InOrder(T);
		printf("\n");
		PostOrder(T);
}
