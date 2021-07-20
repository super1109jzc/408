#include <stdio.h>
#include <sys/types.h>
#include <signal.h>
#include <unistd.h>
void saler(int);     
void driver(int);    
pid_t pid;  
int main()
{
    while((pid=fork())==-1);
    if (pid == 0)  
    {
        signal(SIGINT, saler);    
        signal(SIGQUIT, saler);   
        signal(SIGUSR1, saler); 
        signal(SIGTSTP, SIG_IGN);  
        while (1)
            pause();
    }
    else  //父进程（司机）
    {
        signal(SIGINT, SIG_IGN);
        signal(SIGQUIT, SIG_IGN);
        signal(SIGTSTP, driver);
        signal(SIGUSR1, driver);
        signal(SIGUSR2, driver);
        while (1)
            pause();
    }
    return 0;
}

void saler(int no)
{
    if (no == SIGINT)
        kill(getppid(), SIGUSR1);  
    if (no == SIGQUIT)
        kill(getppid(), SIGUSR2);
    if (no == SIGUSR1)
    {
        printf("please get off the bus!\n");
        kill(0, SIGKILL);  
    }
}

void driver(int no)
{
    if (no == SIGUSR1)
        printf("let's gogogo!\n");
    if (no == SIGUSR2)
        printf("stop the bus!\n");
    if (no == SIGTSTP)
        kill(pid, SIGUSR1); 
}
