// #include <stdio.h>
// #include <stdlib.h>
// #include <signal.h>
// #include <unistd.h>

// static void sig_handler(int sig) {
//     printf("signal process \n");
// }

// int main(int argc, char *argv[])
// {
//     struct sigaction sig = {0};
//     sigset_t sig_set;

//     //setup SIGINT handler
//     sig.sa_handler = sig_handler;
//     sig.sa_flags = 0;
//     if (-1 == sigaction(SIGINT, &sig, NULL)) {
//         perror("sigaction error");
//         return 1;
//     }
//     //init set group
//     sigemptyset(&sig_set);
//     sigaddset(&sig_set,SIGINT);

//     //register mask signals
//     if(-1==sigprocmask(SIG_BLOCK,&sig_set,NULL))
//     {
//         return 1;
//     }
//     //raise
//     while(1)
//     {
//         sleep(1);
//         raise(SIGINT);
//     }    
//     return 0;
// }


#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

static void sig_handler(int sig) {
    printf("signal process \n");
}

int main(int argc, char *argv[])
{
    struct sigaction sig = {0};
    sigset_t sig_set;

    //setup SIGINT handler
    sig.sa_handler = sig_handler;
    sig.sa_flags = 0;
    if (-1 == sigaction(SIGINT, &sig, NULL)) {
        perror("sigaction error");
        return 1;
    }
    //init set group
    sigemptyset(&sig_set);
    sigaddset(&sig_set,SIGINT);

    //register mask signals
    if(-1==sigprocmask(SIG_BLOCK,&sig_set,NULL))
    {
        return 1;
    }
    //raise
    raise(SIGINT);
    printf("raise signal over1\n");

    sleep(2);

    //register unmask signals
    if(-1==sigprocmask(SIG_UNBLOCK,&sig_set,NULL))
    {
        return 1;
    }

    raise(SIGINT);
    printf("raise signal over2\n");
    sleep(2);
    
    return 0;
}