#include<stdio.h>
#include<unistd.h>
int main()
{
    int p1, p2, p3;//b, c, d
    while((p1=fork()) == -1) ;
    if(p1 != 0)
    {
        printf("process a\'s pid is %d, a\'s ppid is %d\n", getpid(), getppid());
    } 
    else 
    {
        while((p2=fork()) == -1) ;
        if(p2 != 0)
        {
            printf("process b\'s pid is %d, b\'s ppid is %d\n", getpid(), getppid());
        }
        else
        {
            while((p3=fork()) == -1) ;
            if(p3 != 0)
            {
                printf("process c\'s pid is %d, c\'s ppid is %d\n", getpid(), getppid());
            }
            else
            {
                printf("process d\'s pid is %d, d\'s ppid is %d\n", getpid(), getppid());
            }
        }
    }
    sleep(1);
}
