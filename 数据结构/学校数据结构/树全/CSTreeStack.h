#include <stdio.h>
#include <stdlib.h>
#define FALSE 0
#define TRUE 1
#define MAXSIZE 100
typedef char TreeElem;
typedef struct CSNode{
     TreeElem data;
     struct CSNode *firstchild, *nextsibling;  
}CSNode, *CSTree; 
typedef CSTree QueueElemType;
typedef CSTree StackElemType; 
typedef CSTree Elemtype;
typedef struct{
	StackElemType elem[MAXSIZE];
	int top;
}SeqStack;
typedef struct{
    QueueElemType element[MAXSIZE];
    int front;//队头
    int rear;//队尾
}SeqQueue;

void InitQueue(SeqQueue *Q){
    Q->front = Q->rear = 0;
}
int PushSeqQueue(SeqQueue *Q, QueueElemType x){
    if ((Q->rear + 1) % MAXSIZE == Q->front)///队列已经满了
    	return FALSE;
    Q->element[Q->rear] = x;
    Q->rear = (Q->rear + 1) % MAXSIZE;
    return TRUE;
}
int PopSeqQueue(SeqQueue *Q, QueueElemType *x){
    if (Q->front == Q->rear)
    	return FALSE;
    *x = Q->element[Q->front];
    Q->front = (Q->front + 1) % MAXSIZE;

    return TRUE;
}
int GetlenSeqQueue(SeqQueue *Q){
	if(Q->front>Q->rear) return MAXSIZE-(Q->front-Q->rear);
	return Q->rear-Q->front;
}
int GetHeadSeqQueue(SeqQueue *Q, QueueElemType *x){
    if (Q->front == Q->rear)
    	return FALSE;
    *x = Q->element[Q->front];
    return TRUE;

}
int IsEmptySeqQueue(SeqQueue *Q){
    if (Q->rear == Q->front)
    	return TRUE;
    else
    	return FALSE;
}

void InitStack(SeqStack *sq){
	sq->top = -1;
}
int PushSeqStack(SeqStack *sq,StackElemType e){
	if(sq->top==MAXSIZE-1) return FALSE;
	sq->top++;
	sq->elem[sq->top] = e;
	return TRUE;
}
int PopSeqStack(SeqStack *sq,StackElemType *e){
	if(sq->top==-1) return FALSE;
	*e = sq->elem[sq->top];
	sq->top--;
	return TRUE;
}
int GetHeadSeqStack(SeqStack *sq,StackElemType *e){
	if(sq->top==-1) return FALSE;
	*e = sq->elem[sq->top];
	return TRUE;
}
int IsEmptySeqStack(SeqStack *sq){
	if(sq->top==-1) return TRUE;
	return FALSE;
}
