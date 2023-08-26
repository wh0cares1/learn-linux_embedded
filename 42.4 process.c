#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>
#include <unistd.h>
int main(int argc, char *argv[])
{
    //printf("Current pid=%d, Parent pid=%d\n",getpid(),getppid());
    //1) return 2 times, one is for parent, other one is for child
    //2) child is a copy of parent
    int ret;
    int a=19;
    printf("hello\n");
    ret = fork();
    if(-1==ret)
    {
        perror("fork error");
        return 1;
    }
    else if (0==ret)
    {   
        printf("child pid=%d\n",getpid());
        // printf("child a-> +%d\n",a);
        // a=100;
        // printf("child a-> +%d\n",a);
        
        //printf("child pid=%d, Parent pid=%d\n",getpid(),getppid());
    }
    else
    {
        sleep(1);
        printf("parent pid=%d\n",getpid());
        // printf("parent a-> +%d\n",a);
        //printf("parent pid=%d, Parent parent pid=%d, child pid=%d\n",getpid(),getppid(),ret);
        //sleep(1);
    }
    //printf("%d\n",ret);
    // printf("Hello\n");
    return 0;
}