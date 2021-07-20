#include <stdio.h>
#include <unistd.h>
int main() {
    int p_b, p_c, p_d, p_e;
    while((p_b=fork()) == -1) ;
    if(0 == p_b) {
        while((p_c=fork()) == -1) ;
        if(0 == p_c) {
            printf("process c\'s pid is %d, c\'s ppid is %d\n", getpid(), getppid());
        } else {
            printf("process b\'s pid is %d, b\'s ppid is %d\n", getpid(), getppid());
        }
    } else {
        while((p_d=fork()) == -1) ;
        if (0 == p_d) {
            while((p_e=fork()) == -1) ;
            if (0 == p_e) {
                printf("process e\'s pid is %d, e\'s ppid is %d\n", getpid(), getppid());
            } else {
                printf("process d\'s pid is %d, d\'s ppid is %d\n", getpid(), getppid());
            }
        } else {
            printf("process a\'s pid is %d, a\'s ppid is %d\n", getpid(), getppid());
        }
    }
    sleep(1);
}
