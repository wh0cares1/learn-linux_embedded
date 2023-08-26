#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

static void sig_handler(int sig) {
     puts("Alarm timeout");
}

int main(int argc, char *argv[])
{
    struct sigaction sig = {0};
    int second;

    if (2 > argc)
        exit(-1);
    //setup handler
    sig.sa_handler = sig_handler;
    sig.sa_flags = 0;
    if (-1 == sigaction(SIGALRM, &sig, NULL)) {
        perror("sigaction error");
        exit(-1);
    }
    //enable timer alarm
    second = atoi(argv[1]);
    printf("time: %d second\n", second);
    alarm(second);
    //going to sleep pause
    pause();
    puts("pause end");
    exit(0);
}
