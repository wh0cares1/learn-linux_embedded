
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
int main(void)
{
    int ret=0;
    struct utsname info = {0};

    ret = uname(&info);
    if(-1 == ret)
    {
        perror("uname error");
        return 1;
    }

    printf("OS name: %s\n",info.sysname);
    printf("host name: %s\n",info.nodename);
    printf("kernel version: %s\n",info.release);
    printf("dist version: %s\n",info.version);
    printf("hardware: version%s\n",info.machine);
    return 0;
}