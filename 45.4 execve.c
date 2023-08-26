#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

//int execve(const char *pathname, char *const argv[],char *const envp[]);
int main(int argc, char **argv)
{
    char *arg_arr[6];
    char *env_arr[6]={"NAME1=a","NAME2=b","NAME3=c",NULL};
    if(2>argc)
    {
        exit(-1);
    }

    arg_arr[0] = argv[1];
    arg_arr[1] = "HELLO";
    arg_arr[2] = "WORLD";
    arg_arr[3] = NULL;
    execve(argv[1],arg_arr,env_arr);

    perror("execve error");
    return 0;
}