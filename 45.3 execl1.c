#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
extern char **environ;
// int execl(const char *pathname, const char *arg, ...
//                        /* (char  *) NULL */);
//        int execlp(const char *file, const char *arg, ...
//                        /* (char  *) NULL */);
//        int execle(const char *pathname, const char *arg, ...
//                        /*, (char *) NULL, char *const envp[] */);


//        int execv(const char *pathname, char *const argv[]);
//        int execvp(const char *file, char *const argv[]);
//        int execvpe(const char *file, char *const argv[],
//                        char *const envp[]);
int main(int argc, char **argv)
{
    char *argv_arr[]={
        "ls",
        "-a",
        "-l",
        NULL
    };
    execvpe("ls",argv_arr,environ);
    perror("execl error");
    return 0;
}