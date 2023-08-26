#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
int main(void)
{
    int ret;
    int fd1;
    fd1 = open("./test.txt",O_WRONLY);
    if(-1==fd1)
    {
        perror("open error");
        return 1;
    }
    //ret = truncate("./test.txt",4);
    ret = ftruncate(fd1,2048);//2k
    if(-1==ret)
    {
        perror("truncate error");
        return 1;
    }
    return 0;
}