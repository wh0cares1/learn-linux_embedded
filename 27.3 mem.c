
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

int main(void)
{

    char buf[128] = {'H','H','K'};
    puts(buf);

    //memset(buf,0x0,sizeof(buf));
    bzero(buf,200000);
    puts(buf);

    return 0;
}