#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <utime.h>
#include <time.h>
#include <sys/stat.h>
#include <sys/types.h>

#define DIR_TEST "new_dir"

int main(void)
{
    int ret;
    ret = mkdir(DIR_TEST,0666);
    if(-1==ret)
    {
        perror("mkdir error");
        return 1;
    }
    return 0;

}