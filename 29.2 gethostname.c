
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
    char hostname[256]={0};
    int ret;
    
    memset(hostname,0,sizeof(hostname));
    ret = gethostname(hostname,sizeof(hostname));
    if(-1 == ret)
    {
        perror("gethostname error");
        return 1;
    }
    puts(hostname);
    
    return 0;
}