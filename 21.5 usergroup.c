#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(void)
{
    int ret;
    ret = chown("./test.txt",0,0);
    if(-1==ret)
    {   
        perror("chown error");
        return 1;
    }
    return 0;
}