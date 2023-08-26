#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define FILETOCHECK "./test.txt"

int main(void)
{

    int ret;
    ret = access(FILETOCHECK,F_OK);
    printf("checking file %s\n",FILETOCHECK);
    if(-1==ret)
    {   
        perror("file does not exist \n");
        return 1;
    }

    ret = access(FILETOCHECK,R_OK);
    if(!ret)
    {   
        printf("read ok !\n");
    }
    else
    {
        printf("no read permission\n");
    }

    ret = access(FILETOCHECK,W_OK);
    if(!ret)
    {   
        printf("write ok !\n");
    }
    else
    {
        printf("no write permission\n");
    }

    ret = access(FILETOCHECK, X_OK);
    if(!ret)
    {   
        printf("excute ok !\n");
    }
    else
    {
        printf("no excute permission\n");
    }

    return 0;
}