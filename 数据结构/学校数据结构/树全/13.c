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
BiTree FindNode(BiTree T,TreeElem ch){
	BitNode *p;
	p=FindInFirst(T);
	while(p&&p->data!=ch)
		p=InNext(p);
	return p;
}
void InsertNode(BitNode *p,BitNode *s){
	BitNode *r;
	if(p->rtag==1)
	{
		s->rtag=1;
		s->rchild=p->rchild;
		s->lchild=p;
		p->rchild=s;
		p->ltag=1;
	}
	else
	{
		r=p->rchild;
		while(r->ltag==0) r=r->lchild;
		r->lchild=s;
		s->rchild=p->rchild;
		s->rtag=0;
		s->ltag=1;
		s->lchild=p;
		p->rchild=s; 
	}
}
void TInOrder(BiTree T){
	BitNode *p;
	p=FindInFirst(T);
	while(p)
	{
		printf("%c",p->data);
		p=InNext(p);
	}
}
BiTree Findparent(BitNode *p,BiTree T){
	BitNode *s;
	s=FindInFirst(T);
	while(s&&s!=p)
		s=InNext(s);
	return s;
}
void delNode(BitNode *p){
	if(p->ltag==0&&p->rtag==0) return; //���ڵ����������ӣ�����ɾ��
	 
}
void main()
{
	BiTree T;
	BitNode *p,*s;
	TreeElem ch,ch1;
	T=(BitNode *)malloc(sizeof(BitNode));
	puts("������չ�����������������������Ľڵ����ֵ��:");
	CreatBiTree(&T);
	Inthread(T);
	pre->rtag=1;pre->rchild=NULL;   //���һ���ڵ������� 
	puts("����������ڵ�Ͳ���λ�õ���ֵ��");
	getchar();scanf("%c%c",&ch,&ch1);
	s=(BiTree)malloc(sizeof(BitNode));
	s->data=ch;
	p=FindNode(T,ch1);
	TInOrder(T); 
	printf("\n");
	InsertNode(p,s);
	TInOrder(T); 
	getchar();scanf("%c",&ch1);
	p=FindNode(T,ch1);
	
}
