#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
int main(void)
{
    int fd;
    fd = open("./test.txt",O_RDONLY|O_TRUNC);
    if(-1==fd)
    {
        perror("open error");
        return 1;
    }
    close(fd);
    return 0;
}