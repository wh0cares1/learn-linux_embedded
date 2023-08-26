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
#include <signal.h>


int main(int argc,char **argv)
{
     int pid;
     if(2>argc)
     {
        return 1;
     }

     pid = atoi(argv[1]);
     printf("pid %d \n",pid);


     if(-1==kill(pid,SIGINT))
     {
        perror("kill error\n");
        exit(-1);
     }
     
     return 0;
}