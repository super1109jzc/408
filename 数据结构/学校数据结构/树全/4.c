#include <stdio.h>
#include <stdlib.h> 
typedef char Elemtype;
typedef struct Node{
	Elemtype data;
	struct Node *lchild,*rchild;
}BitNode,*BiTree;
void CreatBiTree(BiTree *T){//���������н����������Ķ�������
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
int m=0,n=0;	
int Depth(BiTree T){//���������
	if(T==NULL) return 0;
	else{
		m=Depth(T->lchild);
		n=Depth(T->rchild);
		if(m>n) return m+1;
		else return n+1;
	}
}
void main()
{
	BiTree T;
	T=(BitNode *)malloc(sizeof(BitNode));
	puts("������չ�����������������������Ľڵ����ֵ��:");
	CreatBiTree(&T);
	printf("%d",Depth(T));
} 
