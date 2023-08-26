#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
int main(void)
{
    int fd;
    int ret;
    unsigned char buf[1024];
    fd = open("test.txt",O_WRONLY|O_CREAT|O_EXCL,0644);
    if(-1==fd)
    {
        perror("open error");
        return 1;
    }
    
    ret = lseek(fd,1024,SEEK_SET);
    if(-1==ret)
    {
        perror("lseek error");
        close(fd);
        return 1;
    }

    ret = write(fd,buf,1024);
    if(-1==ret)
    {
        perror("write error");
        close(fd);
        return 1;
    }
    //
    printf("write %d data in\n",ret);
    close(fd);
    return 0;


}