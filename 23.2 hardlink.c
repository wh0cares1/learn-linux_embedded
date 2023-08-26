#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <utime.h>
#include <time.h>
#include <sys/stat.h>
#include <sys/types.h>

#define FILETEST "./test.txt"

int main(void)
{
    int ret;
    ret = link(FILETEST,"hardlink_test");
    if(-1==ret)
    {
        perror("link error");
        return 1;
    }
    return 0;

}