//此函数用于发送消息
#include <sys/types.h>
#include <sys/msg.h>
#include <sys/ipc.h>
#include <stdio.h>
#include <stdlib.h>
#define MSGKEY 75 
struct msgform//消息结构
{
        long mtype;//消息类型
        char mtext[1000];//消息的文本
}msg; 
int msgqid;  
void client() 
{
        int i; 
        msgqid=msgget(MSGKEY,0777); /*打开 75#消息队列，0777为所有人提供读/写权限*/ 
        for(i=10;i>=1;i--)
        {
                msg.mtype=i; 
                printf("(client)sent\n");
                msgsnd(msgqid,&msg,1024,0); /*发送消息，发送消息msg入msgid消息队列*/ 
        } 
        exit(0); 
} 
int main()  
{   
        client(); 
}
