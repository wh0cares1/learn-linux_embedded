#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
int main(void)
{
    int fd;
    int ret;
    fd = open("./hello.txt",O_WRONLY|O_CREAT|O_EXCL,0644);
    if(-1==fd)
    {
        printf("open error\n");
        return 1;
    }
    printf("open ok !\n");
    ret = write(fd,"hello world",11);
    if(-1==ret)
    {
        printf("write error\n");
        close(fd);
        return 1;
    }
    printf("write %d bytes ok\n",ret);

    close(fd);
    return 0;

}