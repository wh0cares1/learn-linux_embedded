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

int main(void)
{
    int ret;
    char buf[256]={0};
    getcwd(buf, sizeof(buf));
    printf("working folder -> %s\n",buf);

    chdir("../../");


    getcwd(buf, sizeof(buf));
    printf("now working folder -> %s\n",buf);

    return 0;

}
       