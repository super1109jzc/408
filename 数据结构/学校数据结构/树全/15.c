#include <stdio.h>
#include <stdlib.h> 
typedef char TreeElem;
typedef struct CSNode{
     TreeElem data;
     struct CSNode *firstchild, *nextsibling;  
}CSNode, *CSTree; 
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
int Depth(CSTree T)
{
	int h,d1,d2;
    if (T==NULL)  return 0;
    else{
       d1 = Depth(T->firstchild);
       d2 = Depth(T->nextsibling);
       if(d1+1>d2) h=d1+1;
       else h=d2;
   }
   return h;
}
void main()
{
	CSTree T;
	T=(CSTree)malloc(sizeof(CSNode));
	CreatCSTree(&T);
	printf("%d",Depth(T));
}

