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
int NodeCount(BiTree T){ //����������� 
	if(T==NULL) return 0;
	else return NodeCount(T->lchild)+NodeCount(T->rchild)+1; 
}
int LeafCount(BiTree T){ //������Ҷ�ӽ���� 
	if(T==NULL) return 0;
	if(T->lchild==NULL&&T->rchild==NULL) return 1;
	else return LeafCount(T->lchild)+LeafCount(T->rchild);
}
int NonLeafNode(BiTree T){
	return NodeCount(T)-LeafCount(T);
}
void main()
{
	BiTree T;
	T=(BitNode *)malloc(sizeof(BitNode));
	puts("������չ�����������������������Ľڵ����ֵ��:");
	CreatBiTree(&T);
	printf("leaf:%d\n",LeafCount(T));
	printf("nonleaf:%d\n",NonLeafNode(T));
}
