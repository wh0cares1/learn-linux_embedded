#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
int main(void)
{
    int fd;
    int ret;
    fd = open("./test.txt",O_WRONLY|O_APPEND);
    if(-1==fd)
    {
        perror("open error");
        return 1;
    }

    ret = write(fd,"HIHI",4);
    if(-1==ret)
    {
        perror("write error");
        close(fd);
        return 1;
    }

    close(fd);
    return 0;
}