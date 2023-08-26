
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
#include <sys/sysinfo.h>

       
int main(void)
{
    int ret=0;
    struct sysinfo info = {0};

    ret = sysinfo(&info);
    //int sysinfo(struct sysinfo *info);
    if(-1 == ret)
    {
        perror("sysinfo error");
        return 1;
    }

    printf("uptime: %ld\n",info.uptime);
    printf("total ram: %lu\n",info.totalram);
    printf("free ram: %lu\n",info.freeram);
    printf("procs: %u\n",info.procs);
    
    return 0;
}