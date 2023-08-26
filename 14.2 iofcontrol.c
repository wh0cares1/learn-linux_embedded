#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
int main(void)
{
    int ret;
    int fd1;
    int fd2;

    fd1 = open("./test.txt",O_WRONLY);
    if(-1==fd1)
    {
        perror("open error");
        return 1;
    }

    fd2 = fcntl(fd1,F_DUPFD,0);//dup or dup2
    if(-1==fd2)
    {
        perror("fcntl error");
        close(fd1);
        return 1;
    }
    printf("fd1 = %d , fd2 = %d\n",fd1, fd2);
    close(fd1);
    close(fd2);
    return 0;

}