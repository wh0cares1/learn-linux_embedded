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
int main(void)
{
    struct timespec req;
    req.tv_sec = 2; 
    req.tv_nsec = 0;

    puts("sleep start\n");
    //sleep(2);
    //usleep(2*1000*1000);
    nanosleep(&req,NULL);
    puts("sleep end\n");
    return 0;

}