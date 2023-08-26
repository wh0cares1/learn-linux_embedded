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
    // time_t t1;
    // t1 = time(NULL);
    // if(-1 == t1)
    // {
    //     perror("time error");
    //     return 1;
    // }
    // printf("time is %ld\n",t1);

    
    struct timeval tvalue;
    int ret;
    ret = gettimeofday(&tvalue,NULL);
    if(-1 == ret)
    {
        perror("gettimeofday error");
        return 1;
    }
    printf("time %ld second + %ld ms\n",tvalue.tv_sec,tvalue.tv_usec);

    return 0;
}