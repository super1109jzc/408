#include <stdio.h>
#include <stdlib.h>
#include<conio.h>
#include <malloc.h>
#define stackSize 3
typedef int ElementType;
//定义车辆信息的结构体
typedef struct {
    int BNo;
    int type;
    int arrivetime;
    int pushtime;
    int departuretime;
}BusInf;
//栈定义
typedef struct {
    BusInf elem[stackSize];
    int top;
}SeqStack;
//初始化栈
void InitStack(SeqStack* s)
{
    s->top = -1;
}
//判断栈空--为1表示空--位0表示非空
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
//判断栈满--0未满--1栈满
int IsFull(SeqStack* s)
{
    if (s->top == stackSize - 1)
    {
        return 1;
    }
    else
        return 0;
}
//进站--1表示入栈--0表示栈满
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
//出栈--1表示出栈，0表示栈空--用指针带出出栈的值
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
//队列
typedef struct Node {
    BusInf Bus;
    struct Node* next;
}LinkQueueNode;
typedef struct {
    LinkQueueNode* front;//头指针
    LinkQueueNode* rear;//队尾指针
}LinkQueue;
//初始化队列--将Q初始化为一个空的链队列
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
//入队操作
int EnterQueue(LinkQueue* Q, BusInf bus)
{
    //新建一个节点，插入队尾
    LinkQueueNode* NewNode = (LinkQueueNode*)malloc(sizeof(LinkQueueNode));
    if (NewNode != NULL)
    {
        NewNode->Bus = bus;
        NewNode->next = NULL;
        Q->rear->next = NewNode;
        //将最后一个插入的节点设为尾结点
        Q->rear = NewNode;
        return 1;
    }
    else {
        return 0;
    }
}
//出队操作
int DeleteQueue(LinkQueue* Q, BusInf* bus) {
    LinkQueueNode* p;
    if (Q->front == Q->rear) {
        return 0;
    }
    else {
        p = Q->front->next;
        Q->front->next = p->next;//将对头更新
        *bus = p->Bus;
        //判断如果这个时候是否队列为空，是的话收尾指针相等
        if (Q->rear == p)
        {
            Q->front = Q->rear;
        }
        //释放节点P
        free(p);
        return 1;
    }
}
//查找栈中有无车牌信息--temp代表出栈的位置....-1代表无车牌
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
    printf("已停靠车辆：\n");
    //int temp = (s->top)+1;
    printf(" 车牌号        到达时间        停车时间\n");
    for (int temp = 0; temp <= s->top; temp++)
    {
        printf(" %4d%14d%15d\n", s->elem[temp].BNo, s->elem[temp].arrivetime, s->elem[temp].pushtime);
    }
}
//显示队列里的车
void showQBus(LinkQueue* l) {
    LinkQueueNode* p = l->front->next;
    printf("等待车辆：\n");
    printf(" 车牌号        到达时间\n");
    while (p != NULL)
    {
        printf(" %4d%14d\n", p->Bus.BNo, p->Bus.arrivetime);
        p = p->next;
    }
}
int selectCar() {
    int flag = 0;
    printf("1.轿车  2.客车  3.卡车  ");
    printf("\n请选择车辆种类：\n");
    scanf("%d", &flag);
    if (flag != 1 && flag != 2 && flag != 3)
    {
        printf("输入错误重新输入：");
        scanf("%d", &flag);
    }
    return flag;
}
//输入车辆信息并且入栈或入队
void inputCarData(SeqStack* s, LinkQueue* l) {
    BusInf bus;
    printf("请输入车牌号:");
    scanf("%d", &bus.BNo);
    //判断车牌号是否重复
    if (searchBusNo(s, bus) != -2) {
        printf("车牌号重复！\n");
        printf("请重新输入车牌信息:");
        scanf("%d", &bus.BNo);
    }
    printf("请输入到达时间：\n");
    scanf("%d", &bus.arrivetime);
    if (bus.arrivetime < 0 || bus.arrivetime>24)
    {
        printf("时间输入不合法（0-24）重新输入：\n");
        scanf("%d", &bus.arrivetime);
    }
    bus.pushtime = bus.arrivetime;
    bus.type = selectCar();
    //车辆进栈--先判断栈是否满
    if (IsFull(s) == 1) {
        showBus(s);
        //栈满的情况，下面来的进队列中
        EnterQueue(l, bus);
        showQBus(l);
    }
    //栈没满的情况
    else {
        push(s, bus);
        //显示进栈车辆信息
        showBus(s);
    }
}

//离开停车位
void leaveStack(SeqStack* s, SeqStack* se, LinkQueue* Q)
{
    if (IsEmpty(s) == 1)
    {
        printf("此时没有车辆停靠！");
        return;
    }
    int pay[] = { 2,3,4 };
    int temp = 0;
    int leavetime = 0;
    BusInf bus;
    printf("请输入离开的车号");
    scanf("%d", &temp);
    bus.BNo = temp;
    int m = searchBusNo(s, bus);
    while (m == -2)
    {
        printf("输入错误重新输入");
        scanf("%d", &temp);
        bus.BNo = temp;
        m = searchBusNo(s, bus);
    }
    printf("请输入出栈时间:");
    scanf("%d", &leavetime);
    while (leavetime <= s->elem[m].arrivetime)
    {
        printf("离开时间必须大于停车时间！重新输入：");
        scanf("%d", &leavetime);
    }
    //显示出栈的车辆
    printf("******离去车辆信息******\n");
    printf(" 车牌号        价格         离开时间\n");
    s->elem[m].departuretime = leavetime;
    printf("%4d%13d%13d", s->elem[m].BNo, (leavetime - s->elem[m].arrivetime) * pay[s->elem[m].type - 1], s->elem[m].departuretime);
    printf("\n************\n");
    //这时m接收的就是出栈的位置--2中情况在栈顶和不在栈顶--让位时进入辅助栈se
    //离开的车在栈顶时
    if (m == s->top)
    {
        BusInf* b;
        b = (BusInf*)malloc(sizeof(BusInf));
        pop(s, b);
    }
    //不在栈顶
    else
    {
        for (int i = s->top; i >= m; i--) {
            BusInf* b = (BusInf*)malloc(sizeof(BusInf));
            //先入栈再出栈
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
    //判断队列是否有等待车辆--有的话对头入栈
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
//菜单选择
int menu()
{
    char n;
    printf("\n    ************* 停车场管理系统 **************\n");
    printf("    *%15c1---停车%19c\n", ' ', '*');
    printf("    *%15c2---离开%19c\n", ' ', '*');
    printf("    *%15c3---结束程序%15c\n", ' ', '*');
    printf("    *******************************************\n");
    printf("菜单选择：1,2,3: ");
    do {
        n = getch();
    } while (n < '1' || n>'3');
    printf("\n");
    return(n - 48);
}
int main()
{
    //车辆栈
    SeqStack* s = (SeqStack*)malloc(sizeof(SeqStack));
    InitStack(s);
    //车辆在路边停靠的队列
    LinkQueue* l = (LinkQueue*)malloc(sizeof(LinkQueue));
    InitQueue(l);
    //辅助栈存储让位的信息
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