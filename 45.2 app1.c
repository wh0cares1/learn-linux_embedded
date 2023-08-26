#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
extern char **environ;
int main(int argc, char **argv)
{
    //printf for argv
    for(int i =0;i<argc;i++)
    {
        printf("argv[%d]=%s\n",i,argv[i]);
    }
    //printf for env
    if(NULL == environ)
    {
        return 1;
    }
    for(int i =0;NULL!=environ[i];i++)
    {
        printf("%s\n",environ[i]);
    }
    return 0;
}