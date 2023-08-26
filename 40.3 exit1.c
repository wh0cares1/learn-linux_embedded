#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>
#include <unistd.h>


int main(int argc, char *argv[])
{
    printf("hi 1\n");
    //exit(0);//lib call _exit()
    _exit(16);//system call 
    printf("hi 2\n");
    return 0;
}