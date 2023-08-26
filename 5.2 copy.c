//./copy src_file des_file
//int main(void)
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
int main(int argc, char**argv)
{
    char buffer[1024];
    int fd1,fd2;
    int ret;

    printf("argc %d\n",argc);
    for(int i=0;i<argc;i++)
    {
        printf("argv[%d]=%s\n",i, argv[i]);
    }
    // open src file
    fd1 = open(argv[1],O_RDONLY);
    if(-1==fd1)
    {
        printf("open src file error\n");
        return -1;
    }

        // open des file
    fd2 = open(argv[2],O_WRONLY|O_CREAT|O_EXCL,S_IRWXU|S_IRGRP|S_IROTH);
    if(-1==fd2)
    {
        printf("open des file error\n");
        ret = -1;
        goto error1;
    }
    ret = read(fd1,buffer,sizeof(buffer));//read 1024 bytes only
    if(-1==ret)
    {
        goto error2;
    }

    ret = write(fd2,buffer,sizeof(buffer));//write 1024 bytes only
    if(-1==ret)
    {
        goto error2;
    }

    ret = 0;

error2:
    close(fd2);
error1:
    close(fd1);

    return ret;

}