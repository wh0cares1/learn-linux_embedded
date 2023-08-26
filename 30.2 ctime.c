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
    // // char tm_str[100] = {0};
    // struct tm tr;
    // struct tm utctr;
    // time_t t1;


    // t1 = time(NULL);
    // if(-1 == t1)
    // {
    //     perror("time error");
    //     return 1;
    // }
    // //ctime_r(&t1,tm_str);

    // //struct tm *localtime_r(const time_t *timep, struct tm *result);
    // localtime_r(&t1,&tr);

    // //struct tm *gmtime_r(const time_t *timep, struct tm *result);
    // gmtime_r(&t1,&utctr);

    
    // //printf("time is %s\n",tm_str);
    // printf("time is ->%d\n year ->%d\n month ->%d\n date, ->%d:%d:%d \n",
    // tr.tm_year+1900,tr.tm_mon,tr.tm_mday,tr.tm_hour,tr.tm_min,tr.tm_sec);

    // printf("utc time is ->%d\n year ->%d\n month ->%d\n date, ->%d:%d:%d \n",
    // utctr.tm_year+1900,utctr.tm_mon,utctr.tm_mday,utctr.tm_hour,utctr.tm_min,utctr.tm_sec);
    
    // struct tm localtr;
    // time_t t1;
    // t1 = time(NULL);
    // if(-1 == t1)
    // {
    //     perror("time error");
    //     return 1;
    // }
    // printf("second from system %ld\n",t1);
    // localtime_r(&t1,&localtr);
    // printf("time is ->%d\n year ->%d\n month ->%d\n date, ->%d:%d:%d \n",
    // localtr.tm_year+1900,localtr.tm_mon,localtr.tm_mday,localtr.tm_hour,localtr.tm_min,localtr.tm_sec);
    // printf("second from mktime fucntion %ld\n",mktime(&localtr));
    

    // struct tm localtr;
    // char tm_str[200] = {0};
    // time_t sec;
    // sec = time(NULL);
    // if(-1 == sec)
    // {
    //     perror("time error");
    //     return 1;
    // }
    // printf("second from system %ld\n",sec);
    // localtime_r(&sec,&localtr);
    // //convert the struct of tm to a string buffer which user giving
    // asctime_r(&localtr,tm_str);
    // printf("TIME is %s\n",tm_str);



    struct tm localtr;
    char tm_str[200] = {0};
    time_t t1;
    t1 = time(NULL);
    if(-1 == t1)
    {
        perror("time error");
        return 1;
    }
    localtime_r(&t1,&localtr);
    strftime(tm_str,sizeof(tm_str),"%Y-%m-%d %A %H:%M:%S",&localtr);
    printf("mjj time is %s\n",tm_str);
    // size_t strftime(char *s, size_t max, const char *format,
    //                    const struct tm *tm);
    return 0;
}