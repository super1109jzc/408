#include <stdio.h>
#include <stdlib.h> 
typedef char TreeElem;
typedef struct Node{
	TreeElem data;
	int ltag,rtag;
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
		(*T)->ltag=0;
		(*T)->rtag=0;
		CreatBiTree(&(*T)->lchild);
		CreatBiTree(&(*T)->rchild);	
	}
}
BitNode *pre=NULL;
void Inthread(BiTree root){
	if(root!=NULL)
	{
		Inthread(root->lchild);
		if(root->lchild==NULL)
		{
			root->ltag=1;root->lchild=pre;
		}
		if(pre!=NULL&&pre->rchild==NULL)
		{
			pre->rtag=1;
			pre->rchild=root;
		}	
		pre=root;
		Inthread(root->rchild);
	} 
}
BiTree FindInFirst(BiTree T){
	BitNode *p=T;
	if(p==NULL) return NULL;
	while(p->ltag==0) p=p->lchild;
	return p;
}
BiTree InPre(BitNode *T){
	BitNode *p;
	if(T==NULL) return NULL;
	if(T->ltag==1) return T->lchild;
	else
	{
		for(p=T->lchild;p->rtag==0;p=p->rchild)
		return p;
	}
}
BiTree InNext(BitNode *T){
	BitNode *q;
	if(T==NULL) return NULL;
	if(T->rtag==1) return T->rchild;
	else
	{
		
		for(q=T->rchild;q->ltag==0;q=q->lchild);
		return q;
	}
}
void main()
{
	BiTree T;
	BitNode *p;
	T=(BitNode *)malloc(sizeof(BitNode));
	puts("按照扩展的先序遍历序列输入二叉树的节点的数值域:");
	CreatBiTree(&T);
	Inthread(T);
	pre->rtag=1;pre->rchild=NULL;   //最后一个节点线索化 
	p=InNext(T);
	printf("%c\n",p->data);
	p=InPre(p);
	printf("%c\n",p->data);
	
}
