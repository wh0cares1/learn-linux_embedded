#include <unistd.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <utime.h>
#include <time.h>
#include <dirent.h>
#include <errno.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>
#include <sys/utsname.h>
#include <sys/time.h>
int main(void)
{
    char *base = NULL;
    //base = (char *)malloc(100);
    //posix_memalign((void **)&base,256,1024);
    base = (char *)aligned_alloc(256,256*4);
    if(NULL==base)   
    {
        printf("malloc error\n");
        exit(-1);
    }

    memset(base,1,100);
    *(base+0) =  19;
    *(base+1) =  21;
    free(base);
    base = NULL;
    return 0;
}