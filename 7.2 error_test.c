#include<stdio.h>
#include<errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

int main(void)
{
    int fd;
    printf("errno =%d\n",errno);
    fd = open("haha.txt",O_RDONLY);
    if(-1==fd)
    {
        printf("errno =%d\n",errno);
        //printf("errno string is %s\n",strerror(errno));
        perror("");
        perror("add me!");
        return 1;
    }
    return 0;
}