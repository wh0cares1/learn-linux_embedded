#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>
#include <unistd.h>
// static void byebye(void)
// {
//     printf("hi goodbye\n");
// }
// static void byebye1(void)
// {
//     printf("hi goodbye1\n");
// }
// static void byebye2(void)
// {
//     printf("hi goodbye2\n");
// }

int main(int argc, char *argv[])
{
    // atexit(byebye);
    // atexit(byebye1);
    // atexit(byebye2);
    printf("hihihihi");
    sleep(2);
    exit(0);//lib call _exit()
    //_exit(0);//system call 
    return 0;
}