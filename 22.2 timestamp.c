#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <utime.h>
#include <time.h>
#include <sys/stat.h>
#include <sys/types.h>

#define FILETOCHECK "./test.txt"

int main(void)
{
    int ret;
    struct utimbuf times = {0};
    time_t cur_sec;
    time(&cur_sec);
    times.actime = cur_sec+1000;
    times.modtime = cur_sec+1000;
    
    //ret = utime("./test.txt",NULL);
    ret = utime("./test.txt",&times);

    if(-1==ret)
    {
        perror("utime error");
        return -1;
    }
    return 0;
}