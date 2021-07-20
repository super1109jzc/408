#include <stdio.h>
#include <stdlib.h>
#include<conio.h>
#include <malloc.h>
#define stackSize 3
typedef int ElementType;
//���峵����Ϣ�Ľṹ��
typedef struct {
    int BNo;
    int type;
    int arrivetime;
    int pushtime;
    int departuretime;
}BusInf;
//ջ����
typedef struct {
    BusInf elem[stackSize];
    int top;
}SeqStack;
//��ʼ��ջ
void InitStack(SeqStack* s)
{
    s->top = -1;
}
//�ж�ջ��--Ϊ1��ʾ��--λ0��ʾ�ǿ�
int IsEmpty(SeqStack* s)
{
    if (s->top == -1)
    {
        return 1;
    }
    else 
    {
        return 0;
    }
}
//�ж�ջ��--0δ��--1ջ��
int IsFull(SeqStack* s)
{
    if (s->top == stackSize - 1)
    {
        return 1;
    }
    else
        return 0;
}
//��վ--1��ʾ��ջ--0��ʾջ��
int push(SeqStack* s, BusInf bus)
{
    if (IsFull(s) == 1)
    {
        return 0;
    }
    else
    {
        s->top++;
        s->elem[s->top] = bus;
        return 1;
    }
}
//��ջ--1��ʾ��ջ��0��ʾջ��--��ָ�������ջ��ֵ
int pop(SeqStack* s, BusInf* bus)
{
    if (IsEmpty(s) == 1)
    {
        return 0;
    }
    else
    {
        *bus = s->elem[s->top];
        s->top--;
        return 1;
    }
}
//����
typedef struct Node {
    BusInf Bus;
    struct Node* next;
}LinkQueueNode;
typedef struct {
    LinkQueueNode* front;//ͷָ��
    LinkQueueNode* rear;//��βָ��
}LinkQueue;
//��ʼ������--��Q��ʼ��Ϊһ���յ�������
int InitQueue(LinkQueue* Q)
{
    Q->front = (LinkQueueNode*)malloc(sizeof(LinkQueueNode));
    if (Q->front != NULL)
    {
        Q->rear = Q->front;
        Q->front->next = NULL;
        Q->rear->next = NULL;
        return 1;
    }
    else return 0;
}
//��Ӳ���
int EnterQueue(LinkQueue* Q, BusInf bus)
{
    //�½�һ���ڵ㣬�����β
    LinkQueueNode* NewNode = (LinkQueueNode*)malloc(sizeof(LinkQueueNode));
    if (NewNode != NULL)
    {
        NewNode->Bus = bus;
        NewNode->next = NULL;
        Q->rear->next = NewNode;
        //�����һ������Ľڵ���Ϊβ���
        Q->rear = NewNode;
        return 1;
    }
    else {
        return 0;
    }
}
//���Ӳ���
int DeleteQueue(LinkQueue* Q, BusInf* bus) {
    LinkQueueNode* p;
    if (Q->front == Q->rear) {
        return 0;
    }
    else {
        p = Q->front->next;
        Q->front->next = p->next;//����ͷ����
        *bus = p->Bus;
        //�ж�������ʱ���Ƿ����Ϊ�գ��ǵĻ���βָ�����
        if (Q->rear == p)
        {
            Q->front = Q->rear;
        }
        //�ͷŽڵ�P
        free(p);
        return 1;
    }
}
//����ջ�����޳�����Ϣ--temp�����ջ��λ��....-1�����޳���
int searchBusNo(SeqStack* s, BusInf bus)
{

    SeqStack* p = NULL;
    p = s;
    int temp = p->top;
    while (temp >= 0)
    {
        if (p->elem[temp].BNo == bus.BNo)
            return temp;
        temp--;
    }
    return -2;
}
void showBus(SeqStack* s) {
    printf("��ͣ��������\n");
    //int temp = (s->top)+1;
    printf(" ���ƺ�        ����ʱ��        ͣ��ʱ��\n");
    for (int temp = 0; temp <= s->top; temp++)
    {
        printf(" %4d%14d%15d\n", s->elem[temp].BNo, s->elem[temp].arrivetime, s->elem[temp].pushtime);
    }
}
//��ʾ������ĳ�
void showQBus(LinkQueue* l) {
    LinkQueueNode* p = l->front->next;
    printf("�ȴ�������\n");
    printf(" ���ƺ�        ����ʱ��\n");
    while (p != NULL)
    {
        printf(" %4d%14d\n", p->Bus.BNo, p->Bus.arrivetime);
        p = p->next;
    }
}
int selectCar() {
    int flag = 0;
    printf("1.�γ�  2.�ͳ�  3.����  ");
    printf("\n��ѡ�������ࣺ\n");
    scanf("%d", &flag);
    if (flag != 1 && flag != 2 && flag != 3)
    {
        printf("��������������룺");
        scanf("%d", &flag);
    }
    return flag;
}
//���복����Ϣ������ջ�����
void inputCarData(SeqStack* s, LinkQueue* l) {
    BusInf bus;
    printf("�����복�ƺ�:");
    scanf("%d", &bus.BNo);
    //�жϳ��ƺ��Ƿ��ظ�
    if (searchBusNo(s, bus) != -2) {
        printf("���ƺ��ظ���\n");
        printf("���������복����Ϣ:");
        scanf("%d", &bus.BNo);
    }
    printf("�����뵽��ʱ�䣺\n");
    scanf("%d", &bus.arrivetime);
    if (bus.arrivetime < 0 || bus.arrivetime>24)
    {
        printf("ʱ�����벻�Ϸ���0-24���������룺\n");
        scanf("%d", &bus.arrivetime);
    }
    bus.pushtime = bus.arrivetime;
    bus.type = selectCar();
    //������ջ--���ж�ջ�Ƿ���
    if (IsFull(s) == 1) {
        showBus(s);
        //ջ����������������Ľ�������
        EnterQueue(l, bus);
        showQBus(l);
    }
    //ջû�������
    else {
        push(s, bus);
        //��ʾ��ջ������Ϣ
        showBus(s);
    }
}

//�뿪ͣ��λ
void leaveStack(SeqStack* s, SeqStack* se, LinkQueue* Q)
{
    if (IsEmpty(s) == 1)
    {
        printf("��ʱû�г���ͣ����");
        return;
    }
    int pay[] = { 2,3,4 };
    int temp = 0;
    int leavetime = 0;
    BusInf bus;
    printf("�������뿪�ĳ���");
    scanf("%d", &temp);
    bus.BNo = temp;
    int m = searchBusNo(s, bus);
    while (m == -2)
    {
        printf("���������������");
        scanf("%d", &temp);
        bus.BNo = temp;
        m = searchBusNo(s, bus);
    }
    printf("�������ջʱ��:");
    scanf("%d", &leavetime);
    while (leavetime <= s->elem[m].arrivetime)
    {
        printf("�뿪ʱ��������ͣ��ʱ�䣡�������룺");
        scanf("%d", &leavetime);
    }
    //��ʾ��ջ�ĳ���
    printf("******��ȥ������Ϣ******\n");
    printf(" ���ƺ�        �۸�         �뿪ʱ��\n");
    s->elem[m].departuretime = leavetime;
    printf("%4d%13d%13d", s->elem[m].BNo, (leavetime - s->elem[m].arrivetime) * pay[s->elem[m].type - 1], s->elem[m].departuretime);
    printf("\n************\n");
    //��ʱm���յľ��ǳ�ջ��λ��--2�������ջ���Ͳ���ջ��--��λʱ���븨��ջse
    //�뿪�ĳ���ջ��ʱ
    if (m == s->top)
    {
        BusInf* b;
        b = (BusInf*)malloc(sizeof(BusInf));
        pop(s, b);
    }
    //����ջ��
    else
    {
        for (int i = s->top; i >= m; i--) {
            BusInf* b = (BusInf*)malloc(sizeof(BusInf));
            //����ջ�ٳ�ջ
            if (i == m)
            {
                pop(s, b);
            }
            else {
                push(se, s->elem[i]);
                pop(s, b);
            }
        }
        for (int j = se->top; j >= 0; j--)
        {
            BusInf* b = (BusInf*)malloc(sizeof(BusInf));
            pop(se, b);
            push(s, *b);
        }
    }
    //�ж϶����Ƿ��еȴ�����--�еĻ���ͷ��ջ
    if (Q->rear != Q->front) {
        BusInf* b = (BusInf*)malloc(sizeof(BusInf));
        DeleteQueue(Q, b);
        b->pushtime = leavetime;
        push(s, *b);
        showBus(s);
        showQBus(Q);
    }
    else
        showBus(s);
}
//�˵�ѡ��
int menu()
{
    char n;
    printf("\n    ************* ͣ��������ϵͳ **************\n");
    printf("    *%15c1---ͣ��%19c\n", ' ', '*');
    printf("    *%15c2---�뿪%19c\n", ' ', '*');
    printf("    *%15c3---��������%15c\n", ' ', '*');
    printf("    *******************************************\n");
    printf("�˵�ѡ��1,2,3: ");
    do {
        n = getch();
    } while (n < '1' || n>'3');
    printf("\n");
    return(n - 48);
}
int main()
{
    //����ջ
    SeqStack* s = (SeqStack*)malloc(sizeof(SeqStack));
    InitStack(s);
    //������·��ͣ���Ķ���
    LinkQueue* l = (LinkQueue*)malloc(sizeof(LinkQueue));
    InitQueue(l);
    //����ջ�洢��λ����Ϣ
    SeqStack* se = (SeqStack*)malloc(sizeof(SeqStack));
    InitStack(se);
    while (1)
    {
        switch (menu()) {
        case 1:inputCarData(s, l);
            break;
        case 2:leaveStack(s, se, l);
            break;
        case 3:return 0;
        }
    }
    return 0;
}