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
    int x=0,y=0,z=0;
    x=1;
    y=10;
    z=(x+1,y+1); // z will = to the most right one. here is y+1;
    printf("%d %d %d \n",x,y,z);
    return 0;

}
       