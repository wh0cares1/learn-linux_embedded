#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
int main(void)
{
    int fd;
    int ret;
    char buf[4096]={0};//4k buff
    fd = open("./test.txt",O_WRONLY|O_CREAT|O_EXCL,0666);
    if(-1 == fd)
    {
        perror("fopen error");
        return 1;
    }
    for(int i=0;i<4096;i++)//write 4096 times of 4k buff
        write(fd,buf,sizeof(buf));
    //at this point , the user data actually only gets copied to kernel buffer cache area,
    //not writen to hard drive yet
    
    //fsync(fd);// this function will force kernel to write the cached data buffer 
    //from the user to hard drive
    //fdatasync(fd);//sync up data, not manage information of the file(meta data)
    //sync();//it will sync up all files in kernel buff cache area

    close(fd);
    return 0;
}