
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
    //strncmp("ABCD","AAA",2);
    printf("%d\n",strcmp("ABCD","ABCD"));
    printf("%d\n",strcmp("ABCD","a"));
    printf("%d\n",strcmp("a","ABCD"));

    return 0;
}