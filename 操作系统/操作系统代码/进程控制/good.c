#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
 
int main()
{
    if ( fork() == 0 )       // 子进程1
    {
        printf("b\n");
        exit(0);
    }
    else
    {
        if ( fork() == 0 )   // 子进程2
        {
            printf("c\n");
            exit(0);
        }
 
        printf("a\n");      // 父进程
        exit(0);
    }
}

