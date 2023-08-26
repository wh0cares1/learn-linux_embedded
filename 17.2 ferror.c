#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
int main(void)
{
    FILE *f = NULL;
    int ret;
    char buf[128]={0};
    f = fopen("./test.txt","w+");
    if(NULL == f)
    {
        perror("fopen error");
        return 1;
    }
    ret = fwrite("helloworld",1,10,f);
    if(10>ret)
    {
        printf("fwrite error");
        fclose(f);
        return 1;
    }

    ret = fseek(f,0,SEEK_SET);//lseek ?
    if(-1==ret)
    {
        perror("fseek error");
        fclose(f);
        return 1;
    }

    ret = fread(buf,1,10,f);//10bytes=1*10
    if(10>ret)
    {
        if(ferror(f))
        {
            printf("fread error\n");
            fclose(f);
            return 1;
        }
        else
        {
            if(feof(f))
            {
                printf("fread end of the file already\n");
                fclose(f);
                return 1;
            }
        }
        clearerr(f);
    }

    printf("fread %s\n",buf);
    fclose(f);
    return 0;

}