#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
int main(int argc, char *argv[])
{
    //printf("Current pid=%d, Parent pid=%d\n",getpid(),getppid());
    //1) return 2 times, one is for parent, other one is for child
    //2) child is a copy of parent
    int fd;
    fd = open("./test.txt",O_WRONLY|O_TRUNC);
    if(-1==fd)
    {
        perror("open error");
        return 1;
    }

    printf("hello\n");
    switch (fork())
    {
    case /* constant-expression */-1:
        /* code */
        perror("fork error");
        close(fd);
        return 1;
    case /* constant-expression */0:
        /* child code */
        printf("child process\n");
        write(fd,"child says hello",17);
        close(fd);
        return 0;

    default://parent procss get here
        printf("parent process\n");
        write(fd,"parent says hello",18);
        close(fd);
        return 0;
    }
    return 0;
}