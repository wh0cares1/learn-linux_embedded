
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
#include <sys/sysinfo.h>

 //for lib call sysconf
 //long sysconf(int name);

int main(void)
{

    
    printf("every user max processes : %ld\n",sysconf(_SC_CHILD_MAX));
    printf("system clock tck: %ld\n",sysconf(_SC_CLK_TCK));
    printf("system page size : %ld\n",sysconf(_SC_PAGESIZE));
    
    return 0;
}