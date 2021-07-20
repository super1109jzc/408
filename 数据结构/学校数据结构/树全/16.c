#include <stdio.h>
#include <stdlib.h> 
#include "CSTreeStack.h"
void CreatCSTree(CSTree *T){
	TreeElem ch;
	scanf("%c",&ch);
	if(ch=='.') *T=NULL;
	else
	{
		*T=(CSTree)malloc(sizeof(CSNode));  
		(*T)->data=ch;
		CreatCSTree(&(*T)->firstchild);	
		CreatCSTree(&(*T)->nextsibling);
	}
}
void Printstack(SeqStack s){
	int i;
	if(s.top==-1) return;
	else
	{
		for(i=0;i<=s.top;i++)
			printf("%c",s.elem[i]->data);
	}
	printf("\n");
}
void OutPath(CSTree T, SeqStack *s ) {  
	CSNode *p;
    while (T) {
         PushSeqStack(s,T);
         if ( !T->firstchild ) Printstack(*s);
         else OutPath( T->firstchild, s );
         PopSeqStack(s,&p);
         T = T->nextsibling;
    } 
}
void main(){
	CSTree T;
	SeqStack s;
	InitStack(&s);
	T=(CSTree)malloc(sizeof(CSNode));
	CreatCSTree(&T);
	OutPath(T,&s);
}

