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
    struct timespec timesp_arr[2];
    int fd;
    fd = open("./test.txt",O_RDWR);
    if(-1==fd)
    {
        perror("open error");
        return -1;
    }

    #if 0
    ret = futimens(fd,NULL);//set current time stamp
    #endif
    //UTIME_OMIT
    //UTIME_NOW
    #if 0
    timesp_arr[0].tv_nsec = UTIME_OMIT; //dont set this time
    timesp_arr[1].tv_nsec = UTIME_NOW; //set current time
    ret = futimens(fd,timesp_arr);//set time stamp
    #endif

    #if 1
    timesp_arr[0].tv_nsec = UTIME_NOW; //set current time
    timesp_arr[1].tv_nsec = UTIME_OMIT; //dont set this time
    ret = futimens(fd,timesp_arr);//set time stamp
    #endif
    
    if(-1==ret)
    {
        perror("futimens error");
        return 1;
    }

    close(fd);

    return 0;
}