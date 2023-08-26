#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
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
        printf("child process\n");
        break;

    default://parent procss get here
        sleep(1);
        printf("parent process\n");
        break;
    }
    return 0;
}