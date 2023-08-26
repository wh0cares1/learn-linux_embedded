#define _GNU_SOURCE
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
int main(void)
{
    int fd;
    int ret;
    char buf[4096] __attribute((aligned (4096)))={0};//4k buff first condition
    fd = open("./test.txt",O_WRONLY|O_CREAT|O_EXCL|O_DIRECT,0666);//O_DIRECT bypass kernel buffer
    if(-1 == fd)
    {
        perror("fopen error");
        return 1;
    }
    
    lseek(fd,4096,SEEK_SET);// second condition

    for(int i=0;i<4096;i++)//write 4096 times of 4k buff
    {
        ret = write(fd,buf,sizeof(buf));//third condition
        if(-1==ret)
        {
            perror("write error");
            close(fd);
            return 1;

        }
    }
    close(fd);
}