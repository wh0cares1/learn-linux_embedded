#include <unistd.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <utime.h>
#include <time.h>
#include <dirent.h>
#include <errno.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>
#include <sys/utsname.h>
#include <sys/time.h>
#include <signal.h>

//typedef void (*sighandler_t)(int); //user defined funciton to receive the signal 
static void sig_handler(int sig)
{
    printf("received signal number is %d\n",sig);
}

//sighandler_t signal(int signum, sighandler_t handler);

int main(void)
{
    // sig_t ret = NULL;
    // //ret = signal(SIGINT, (sig_t)sig_handler);//user capture signals
    // //ret = signal(SIGINT, SIG_DFL);//system will do default operation
    // ret = signal(SIGINT, SIG_IGN);//ignore
    // if(SIG_ERR==ret)
    // {
    //     perror("registed error");
    //     return 1;
    // }
    
        //        struct sigaction {
        //        void     (*sa_handler)(int);
        //        void     (*sa_sigaction)(int, siginfo_t *, void *);
        //        sigset_t   sa_mask;
        //        int        sa_flags;
        //        void     (*sa_restorer)(void);
        //    };
        struct sigaction sig = {0};
        int ret;
        sig.sa_handler = sig_handler;
        sig.sa_flags = 0;

        ret = sigaction(SIGINT,&sig,NULL);
        if(-1==ret)
        {
            perror("sigaction registed error");
            return 1;
        }

        while(1)
        {
            sleep(1);
        }

        return 0;
}