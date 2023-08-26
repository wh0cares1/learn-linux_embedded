#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>
#include <unistd.h>

//extern char **environ;

//int main(int argc, char *argv[],char *env[])
int main(int argc, char *argv[])
{
    // for(int i =0;NULL!=env[i];i++)
    // {
    //     printf("%s\n",env[i]);
    // }
    const char *env=NULL;
    if(2>argc)
    {
        return 1;
    }
    env = getenv(argv[1]);
    if (NULL==env)
    {
        printf("getenv error\n");
        return 1;
    }
    printf("%s\n",env);
    return 0;
}