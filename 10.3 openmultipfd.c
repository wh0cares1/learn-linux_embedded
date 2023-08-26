#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
int main(void)
{
    int fd1;
    int fd2;
    fd1 = open("./test.txt",O_WRONLY|O_TRUNC|O_APPEND);
    if(-1==fd1)
    {
        perror("open error");
        return 1;
    }

    fd2 = open("./test.txt",O_WRONLY);
    if(-1==fd2)
    {
        perror("open error");
        close(fd1);
        return 1;
    }
    write(fd1,"helloworld",10);
    write(fd2,"fdfdfdfdfd",10);

    close(fd1);
    close(fd2);
    return 0;
}