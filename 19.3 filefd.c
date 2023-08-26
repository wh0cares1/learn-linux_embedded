#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
int main(void)
{
    // int fd;
    // int ret;
    // FILE *file=NULL;
    // fd = open("./test.txt",O_WRONLY|O_CREAT|O_TRUNC,0666);
    // if (-1==fd)
    // {
    //     perror("open error");
    //     return 1;
    // }

    // file = fdopen(fd,"w");//convert int fd to FILE* file
    // if(NULL==file)
    // {
    //     perror("fdopen error");
    //     close(fd);
    //     return 1;
    // }

    // ret = fwrite("helloworld",1,10,file);
    // if(10>ret)
    // {
    //     printf("write file error or end the file\n");
    //     fclose(file);
    //     return 1;
    // }

    // fclose(file);

    FILE* file =NULL;
    int fd;
    int ret;
    file = fopen("./test.txt","w");
    if(NULL==file)
    {
        perror("fopen error");
        return 1;
    }

    fd = fileno(file);//convert FILE* file to int fd
    if(-1==fd)
    {
        perror("fileno error");
        fclose(file);
        return 1;
    }

    ret = write(fd,"helloworld",10);
    if(-1==ret)
    {
        perror("write error");
        fclose(file);
        return 1;
    }
    
    fclose(file);
    return 0;



}