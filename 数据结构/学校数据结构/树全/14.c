#include <stdio.h>
#include <stdlib.h> 
typedef char TreeElem;
typedef struct Node{
	TreeElem data;
	struct Node *lchild,*rchild;
}BitNode,*BiTree;
void CreatBiTree(BiTree *T){
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
void PrintTree(BiTree T,int nlayer){
	int i;
	if(T==NULL) return;
	PrintTree(T->rchild,nlayer+1);
	for(i=0;i<nlayer;i++)
		printf("  ");
	printf("%c\n",T->data);
	PrintTree(T->lchild,nlayer+1);
}
void main()
{
	BiTree T;
	T=(BitNode *)malloc(sizeof(BitNode));
	puts("按照扩展的先序遍历序列输入二叉树的节点的数值域:");
	CreatBiTree(&T);
	PrintTree(T,0);
}
