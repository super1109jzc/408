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
BiTree Creatbyprein(char *ch1,char *ch2){//先序和中序
	char c1l[1000],c1r[1000],c2l[1000],c2r[1000];
	int i,j=0;
	BiTree T;
	if(ch1[0]) {
		T=(BiTree)malloc(sizeof(BitNode));
		T->data=ch1[0];
		for(i=0;ch2[i]&&ch2[i]!=ch1[0];i++) {c1l[i]=ch1[i+1];c2l[i]=ch2[i];}
		c1l[i]=0;c2l[i]=0;
		i++;
		for(i;ch2[i]&&ch2[i];i++) {c1r[j]=ch1[i];c2r[j]=ch2[i];j++;} 
		c1r[j]=0;c2r[j]=0;
		T->lchild=Creatbyprein(c1l,c2l);
		T->rchild=Creatbyprein(c1r,c2r);
	}
	else T=NULL;
	return T;
} 
BiTree Creatbyinpost(char *ch1,char *ch2){//中序和后序 
	char c1l[1000],c1r[1000],c2l[1000],c2r[1000];
	int i=0,j=0,n;
	BiTree T;
	if(ch1[0]) {
		while(ch1[i]!=0) i++;
		n=i-1;
		T=(BiTree)malloc(sizeof(BitNode));
		T->data=ch1[n];
		for(i=0;ch2[i]&&ch2[i]!=ch1[n];i++) {c1l[i]=ch1[i];c2l[i]=ch2[i];}
		c1l[i]=0;c2l[i]=0;
		i++;
		for(i;ch2[i]&&ch2[i];i++) {c1r[j]=ch1[i-1];c2r[j]=ch2[i];j++;} 
		c1r[j]=0;c2r[j]=0;
		T->lchild=Creatbyinpost(c1l,c2l);
		T->rchild=Creatbyinpost(c1r,c2r);
	}
	else T=NULL;
	return T;
} 
void main()
{
	BiTree T;
	char ch1[100],ch2[100];
	puts("请输入先序遍历:");
	gets(ch1);
	puts("请输入中序遍历:");
	gets(ch2);
	T=Creatbyprein(ch1,ch2);
	PreOrder(T);
	printf("\n");
	InOrder(T);
	printf("\n");
	PostOrder(T);
	printf("\n");
	puts("请输入中序遍历:");
	gets(ch2);
	puts("请输入后序遍历:");
	gets(ch1);
	T=Creatbyinpost(ch1,ch2);
	PreOrder(T);
	printf("\n");
	InOrder(T);
	printf("\n");
	PostOrder(T);
	printf("\n");
}
