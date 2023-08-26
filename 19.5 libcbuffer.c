#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
int main(void)
{
    // if(-1==setvbuf(stdout,NULL,_IONBF,0))
    // {
    //     perror("setvbuf error");
    //     return 1;
    // }
    printf("helloworld\n");
    printf("helloworld");

    //fflush(stdout);

    //fclose(stdout);
    // while(1)
    // {
    //     sleep(1);
    // }
    return 0;
}