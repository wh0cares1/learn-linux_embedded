#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int system_byus(const char * command)
{
    if(NULL==command)// 1first case return 
    {
        if(system does have shell program like sh/csh/bash)
        return anything not 0;
        else
        return 0;
    }

    pid_t pid = fork();
    switch (pid)
    {
    case /* constant-expression */-1:
        /* code */
        return -1;// cannot create new process by fork 2second case return
        break;
    case 0:
        execl("/bin/sh","sh","-c",command,NULL);  
        _exit(127); //load shell failed  3third case return
    
    default://parent here
        int status, ret;
        ret = waitpid(pid,&status,NULL);
        if(-1==ret)
        {
            return -1;//4forth case return
        }
        return status;//5fith case return
        break;
    }


}

int main(int argc, char **argv)
{
    int ret = -1;
    ret = system("ls -al");
    if(-1==ret)
    {
        perror("execl error");
        return -1;
    }
    printf("%d\n",WIFEXITED(ret));//1 is normal exit

    return 0;
}