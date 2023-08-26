#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>


static void wait_child(int sig)
{
    printf("parents wait here\n");
    while(waitpid(-1,NULL,WNOHANG)>0)
    {
        continue;
    }
}

int main(void)
{
    struct sigaction sig={0};
    sigemptyset(&sig.sa_mask);
    sig.sa_handler = wait_child;
    sig.sa_flags = 0;

    if(-1==sigaction(SIGCHLD,&sig,NULL))
    {
        perror("sigaction error");
        exit(-1);
    }

    switch (fork())
    {
    case /* constant-expression */-1:
        perror("fork error");
        exit(-1);
        /* code */
        break;
    case /* constant-expression */0:
        printf("child %d\n",getpid());
        sleep(1);
        printf("child exit\n");
        _exit(0);
    default://parent 
        break;
    }
    while(1)
    {
        sleep(1);
    }
    exit(0);
}