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
    
    //setup alarm handler
    sig.sa_handler = sig_handler;
    sig.sa_flags = 0;
    if (-1 == sigaction(SIGALRM, &sig, NULL)) {
        perror("sigaction error");
        return 1;
    }
    //start enable alarm
    second = atoi(argv[1]);
    printf("setup : %d second\n", second);
    alarm(second);

    while(1)
        sleep(1);

    exit(0);
}