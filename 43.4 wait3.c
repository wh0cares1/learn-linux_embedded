#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
int main(void) 
{
    int status;
    int ret;
    int i;
    
    for (i = 1; i <= 3; i++) {
        switch (fork()) {
        case -1:
        perror("fork error");
        exit(-1);

        case 0:
            printf("child <%d> created\n", getpid());
            sleep(i);
            _exit(i);
        default:
            break;
        }
    }   

    sleep(1);
    printf("*******************)\n");
    for (i = 1; i <= 3; i++) 
    {
            ret = wait(&status);
            if (-1 == ret) 
            {
                if (ECHILD == errno) {
                printf("no child process any more\n");
                exit(0);
            }
            else 
            {
                perror("wait error");
                exit(-1);   
            }   
        }
        printf("get child <%d>, end it<%d>\n", ret,
        WEXITSTATUS(status));
    }
    exit(0);
}