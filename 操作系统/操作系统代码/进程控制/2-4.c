#include<stdio.h>
#include<unistd.h>
int main()
{
    int p1, p2, p3, p4;//b,c,d,e
    while((p1=fork()) == -1 || (p3=fork()) == -1) ;
    if(p1 > 0 && p3 > 0)
    {
        printf("process a\'s pid is %d, a\'s ppid is %d\n", getpid(), getppid());
    }
    else if(p1 > 0)
    {
        while((p2=fork()) == -1) ;
        if(p2 > 0)
        {
            printf("process b\'s pid is %d, b\'s ppid is %d\n", getpid(), getppid());
        }
        else
        {
            printf("process c\'s pid is %d, c\'s ppid is %d\n", getpid(), getppid());
        }
    }
    else if (p3 > 0)
    {
        while((p4=fork()) == -1) ;
        if(p4 > 0)
        {
            printf("process d\'s pid is %d, d\'s ppid is %d\n", getpid(), getppid());
        }
        else
        {
            printf("process e\'s pid is %d, e\'s ppid is %d\n", getpid(), getppid());
        }
    }
    sleep(1);
}
