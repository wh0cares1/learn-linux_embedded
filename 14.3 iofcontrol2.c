#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
int main(void)
{
    int ret;
    int fd1;

    fd1 = open("./test.txt",O_WRONLY);//add O_APPEND
    if(-1==fd1)
    {
        perror("open error");
        return 1;
    }
    //get
    ret = fcntl(fd1,F_GETFL);
    if(-1==ret)
    {
        perror("fcntl get error");
        close(fd1);
        return 1;
    }
    printf("flags 0x%x\n",ret);

    //set
    ret = fcntl(fd1,F_SETFL,ret|O_APPEND);
    if(-1==ret)
    {
        perror("fcntl set error");
        close(fd1);
        return 1;
    }

    //get again after you set
    ret = fcntl(fd1,F_GETFL);
    if(-1==ret)
    {
        perror("fcntl get error");
        close(fd1);
        return 1;
    }
    printf("get flags 0x%x\n",ret);

    close(fd1);

    return 0;

}