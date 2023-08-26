#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
int main(void)
{
    int fd1;
    int fd2;
    int ret;
    char buf[100];
    fd1 = open("./test.txt",O_RDWR|O_TRUNC);
    if(-1==fd1)
    {
        perror("open error");
        return 1;
    }

    //fd2 = dup(fd1);
    fd2 = dup2(fd1,1000);
    printf("fd2 = %d\n",fd2);
    
    if(-1==fd2)
    {
        perror("dup error");
        close(fd1);
        return 1;
    }

    ret = write(fd1,"helloworld",10);
    if(-1==ret)
    {
        perror("write error");
        close(fd1);
        close(fd2);
        return 1;
    }

    lseek(fd2,0,SEEK_SET);//reset the pointer to beginning of the file

    ret = read(fd2,buf,10);//helloworld , but it will give you nothing
    if(-1==ret)
    {
        perror("read error");
        close(fd1);
        close(fd2);
        return 1;
    }

    printf("read  %s\n",buf);
    close(fd1);
    close(fd2);

}