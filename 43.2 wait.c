#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>
int main(int argc, char *argv[])
{

    printf("hello\n");
    switch (fork())
    {
    case /* constant-expression */-1:
        /* code */
        perror("fork error");
        return 1;
    case /* constant-expression */0:
        /* child code */
        printf("child process, %d\n",getpid());
        // return 0;
        //abort();
        //return 99;
        while(1)
        {
            sleep(1);
        }

    default://parent procss get here
        int ret;
        int status;
        printf("parent process\n");
        ret = wait(&status);
        if(-1== ret)
        {
            perror("wait error");
            return 1;
        }
        //printf("%d,%d\n",ret,WIFEXITED(status));
        //printf("%d,%d\n",ret,WEXITSTATUS(status));
        //printf("%d,%d\n",ret,WIFSIGNALED(status));
        printf("%d,%d\n",ret,WTERMSIG(status));
        return 0;
    }
    return 0;
}