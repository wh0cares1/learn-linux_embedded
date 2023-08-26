#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>


int main(void)
{

    switch (fork())
    {
    case /* constant-expression */-1:
        perror("fork error");
        exit(-1);
        /* code */
        break;
    case /* constant-expression */0:
        printf("child %d parent %d\n",getpid(),getppid());
        sleep(4);
        printf("parent %d\n",getppid());
        _exit(0);
    default://parent 
        break;
    }
    sleep(1);
    printf("parent  exit first !\n");
    exit(0);
}