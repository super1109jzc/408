#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#define NUM 100										
#define N 20
#define M 2*N-1
typedef struct{
	double weight;
	int parent;
	int lchild,rchild;
}HTNode,HuffmanTree[M+1]; 
typedef char *HuffmanCode[N+1];
void select(HuffmanTree ht,int n,int *s1,int *s2){
	int i;double min=NUM;
	for(i=1;i<=n;i++)
	{
		if(ht[i].parent==0&&ht[i].weight<min)
		{
			
			min=ht[i].weight;
			*s1=i;
		}
	}
	min=NUM;
	for(i=1;i<=n;i++)
	{
		if(ht[i].parent==0&&ht[i].weight<min&&i!=*s1)
		{
			
			min=ht[i].weight;
			*s2=i;
		}
	}
}
void CrtHuffmanTree(HuffmanTree ht,double w[],int n){
	int i,m,s1,s2;
	for(i=1;i<=n;i++)
	{
		ht[i].weight=w[i];ht[i].parent=0;
		ht[i].lchild=0;ht[i].rchild=0;
	}
	m=2*n-1;
	for(i=n+1;i<=m;i++)
	{
		select(ht,i-1,&s1,&s2);
		ht[i].parent=0;
		ht[i].weight=ht[s1].weight+ht[s2].weight;
		ht[i].lchild=s1;ht[i].rchild=s2;
		ht[s1].parent=i;ht[s2].parent=i;
	}
}
void CrtHuffmanCode(HuffmanTree ht,HuffmanCode hc,int n){
	char *cd;
	int i,start,c,p;
	cd=(char *)malloc(n*sizeof(char));
	cd[n-1]='\0';
	for(i=1;i<=n;i++)
	{
		start=n-1;
		c=i;p=ht[i].parent;
		while(p!=0)
		{
			start--;
			if(ht[p].lchild==c) cd[start]='0';
			else cd[start]='1';
			c=p;p=ht[p].parent;
		}
		hc[i]=(char *)malloc((n-start)*sizeof(char));
		strcpy(hc[i],&cd[start]);
	}
	free(cd);
}
void main()
{
	HuffmanTree ht;
	HuffmanCode hc;
	int n,i,x;
	double w[N]={0};
	printf("请输入字母个数:");
	scanf("%d",&n);
	printf("请依次输入权重:\n");
	for(i=1;i<=n;i++)
		scanf("%lf",&w[i]);
	CrtHuffmanTree(ht,w,n);
	for(i=1;i<=2*n-1;i++)
	{
		printf("%.2lf p:%d l:%d r:%d\n",ht[i].weight,ht[i].parent,ht[i].lchild,ht[i].rchild);
	}
	CrtHuffmanCode(ht,hc,n);
	for(i=1;i<=n;i++)
		puts(hc[i]);
}
