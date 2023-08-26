
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>

pid_t waitpid(pid_t pid, int *wstatus, int options);

int main(int argc, char *argv[])
{

    printf("hello\n");
    int pid = fork();
    switch (pid)
    {
    case /* constant-expression */-1:
        /* code */
        perror("fork error");
        return 1;
    case /* constant-expression */0:
        /* child code */
        printf("child process, %d\n",getpid());
        while (1)
        {
            sleep(1);
        }
        
        // return 0;
        //abort();
        //return 99;
        //exit(0);

    default://parent procss get here
        int ret;
        int status;
        printf("parent process\n");
        while(1)
        {
            ret = waitpid(-1,&status,WUNTRACED|WCONTINUED);//wait()
            if(-1== ret)
            {
                perror("wait error");
                return 1;
            }
            else if(0==ret)
            {
                printf("nothing changed from child\n");
            }
            else
            {
                //printf("%d,%d\n",ret,WIFEXITED(status));
                printf("%d,%d\n",ret,WEXITSTATUS(status));
                //printf("%d,%d\n",ret,WIFSIGNALED(status));
                //printf("%d,%d\n",ret,WTERMSIG(status));
        }
        }
        return 0;
    }
    return 0;
}
