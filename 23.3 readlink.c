#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <utime.h>
#include <time.h>
#include <sys/stat.h>
#include <sys/types.h>


int main(void)
{
    int ret;
    char buf[128] = {0};

    ret = readlink("softlink_test",buf,128);
    if(-1==ret)
    {
        perror("readlink error");
        return 1;
    }
    printf("readlink -> %d\n",ret);
    printf("PATH IN the link file ->%s\n",buf);
    return 0;

}