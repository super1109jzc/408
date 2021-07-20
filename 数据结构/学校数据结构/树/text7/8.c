#include<stdio.h>
#include<stdlib.h>
typedef struct Node
{
	int data;
	struct Node* LChild;
	struct Node* RChild;
}BiNode, * BiTree;

//扩展插入
BiTree kuozhan()
{
	BiTree bt;
	int x;
	printf("请依次输入二叉树：");
	scanf("%d", &x);
	if (x == -1)
	{
		bt = NULL;
	}
	else
	{
		bt = (BiTree)malloc(sizeof(BiNode));
		bt->data = x;
		bt->LChild = kuozhan();
		bt->RChild = kuozhan();
	}
	return bt;
}

void LeafPath(BiTree root,int path[], int len)
{
	if (root == NULL)
	{
		return;
	}
	path[len++] = root->data;
	if (root->LChild == NULL && root->RChild == NULL)
	{
		for (int i = 0; i < len; i++)
		{
			printf("%d", path[i]);
		}
		printf("\n");
	}
	else
	{
		
		LeafPath(root->LChild, path, len);
		LeafPath(root->RChild, path, len);
	}
}

int main()
{
	BiTree m;
	int path[100];
	int len = 0;
	m = kuozhan();
	LeafPath(m,path,len);
}