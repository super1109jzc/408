#include <stdio.h>
#include <stdlib.h> 
typedef char Elemtype;
typedef struct Node{
	Elemtype data;
	struct Node *lchild,*rchild;
}BitNode,*BiTree;
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

void inorder(BiTree T){
	BiTree p;
	p=T;
	int top=0,flag=1;
	BiTree s[100];
	while(p||top||flag)
	{
		flag=0;
		while(p)
		{
			top=top+1;
			s[top]=p;
			p=p->lchild;
		}
		if(top!=0)
		{
			p=s[top];
			top=top-1;
			printf("%c",p->data);
			p=p->rchild;
		}
	}
}
void postorder(BiTree T){
	BiTree p;
	p=T;
	int top=0;
	BiTree s[100];
	int tag[100]={0};
	while(p||top)
	{
		while(p)
		{
			top=top+1;
			s[top]=p;
			tag[top]=0;
			p=p->lchild;
		}
		if(top)
		{
			while(tag[top]==1)
			{
				p=s[top];
				top--;
				printf("%c",p->data);
			}
			if(top==0) break;
			p=s[top];
			p=p->rchild;
			tag[top]=1;
		}
			
	}
}
void Visit(Elemtype d){
	printf("%c",d);
}
void PreOrder(BiTree root){
	if(root==NULL) return;
	Visit(root->data);
	PreOrder(root->lchild);
	PreOrder(root->rchild);
}
void main()
{
	BiTree T;
	T=(BitNode *)malloc(sizeof(BitNode));
	CreatBiTree(&T);
	inorder(T);
	printf("\n");
	postorder(T);	
}
