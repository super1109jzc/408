#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
#include<unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
void waiting();
void stop();
void alarming();

int wait_mark;

void main(){
    int pid1, pid2;
    //signal(SIGINT,stop);
    while((pid1 = fork()) == -1);
    if(pid1 > 0 ){
	signal(SIGQUIT,stop);
        while((pid2 = fork()) == -1);
        if(pid2 > 0){
            wait_mark = 1;
           // signal(SIGINT,stop);
            signal(SIGALRM,alarming);
            waiting();

            kill(pid1, 16);
            kill(pid2, 17);

            wait(0);
            wait(0);
            printf("parent precess is killed!\n");
            exit(0);
        }
        else{
            wait_mark = 1;
            signal(17,stop);
            while(wait_mark != 0);
            lockf(1,1,0);
            printf("child process2 is killed by parent!\n");
            lockf(1,0,0);
            exit(0);
        }
    }
    else{
        wait_mark = 1;
        signal(16,stop);
        while(wait_mark != 0);
        lockf(1,1,0);
        printf("child process1 is killed by parent!\n");
        lockf(1,0,0);
        exit(0);
    }
}

void waiting(){
    sleep(5);
    if(wait_mark != 0) kill(getpid(), SIGALRM);
}
void alarming(){
    wait_mark = 0;
}
void stop(){
    wait_mark = 0;
}
