#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>  
#include <sys/wait.h>
int pid1,pid2;
int main()
{
        int fd[2];
        char outpipe[100],inpipe[100];
        pipe(fd);//规定此时不能给pipe定义为int类型                    
        while ((pid1=fork( ))==-1);
        if(pid1==0)
        {
                lockf(fd[1],1,0);
                sprintf(outpipe,"child 1 process is sending message!");
                write(fd[1],outpipe,50);     
                sleep(5);                 
                lockf(fd[1],0,0);
                exit(0);
        }
        else
        {
                while((pid2=fork( ))==-1);
                if(pid2==0)
                {
                        lockf(fd[1],1,0);//此时理解为fd为一个文件，fd[0],fd[1]分别为他的两个接口，但所作的改变对应一个文件,filedes[1]是写入端，filedes[0]是读出端           
                        sprintf(outpipe,"child 2 process is sending message!");//此时sprintf不是输出，理解为放置在缓冲区
                        write(fd[1],outpipe,50);
                        sleep(5);
                        lockf(fd[1],0,0);
                        exit(0);
                }
               else
               {
                         wait(0);//先让子进程运行，此时理解为wait(0)与最邻近的子进程为一对，所以此处为pid2==0为一对，先运行pid2==0 的进程              
                         read(fd[0],inpipe,50);   
                         printf("%s\n",inpipe);
                         wait(0);//与pid1==0为一对。
                         read(fd[0],inpipe,50);
                         printf("%s\n",inpipe);
                         exit(0);
               }
        }
}
