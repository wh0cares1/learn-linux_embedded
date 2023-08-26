
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

int main(void)
{
    char *ptr = NULL;
    char str[] = "helloworld mjrj";

    //ptr = strrchr(str,'r');//strchr
    ptr = strstr(str,"mjrj");
    if(NULL != ptr)
    {
        printf("string : %s\n",ptr);
        printf("index : %ld\n",ptr-str);
    }

    return 0;
}