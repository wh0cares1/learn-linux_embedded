#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>
#include <unistd.h>


int main(int argc, char *argv[])
{
    printf("pid is %d\n",getpid());
    return 0;
}