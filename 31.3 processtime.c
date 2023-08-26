#include <stdio.h>
#include <stdlib.h>
#include <sys/times.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    struct tms t_buf_start;
    struct tms t_buf_end;
    clock_t t_start;
    clock_t t_end;
    long tck;
    int i, j;
    // get system tick, which means how many ticks in a second
    tck = sysconf(_SC_CLK_TCK);
    //start time
    t_start = times(&t_buf_start);
    if (-1 == t_start) 
    {
        perror("times error");
        exit(-1);
    }
    //testing code section
    for (i = 0; i < 20000; i++)
        for (j = 0; j < 20000; j++)
    ;
    sleep(1); //sleep 
    //end time
    t_end = times(&t_buf_end);
    if (-1 == t_end)    
    {
        perror("times error");
        exit(-1);
    }
    //printf 
    printf("total   CPU time(user time and kernel time): %f second\n", (t_end - t_start) / (double)tck);
    printf("user    CPU  time: %f second\n", (t_buf_end.tms_utime - t_buf_start.tms_utime) / (double)tck);
    printf("kernel  CPU   time: %f second\n", (t_buf_end.tms_stime - t_buf_start.tms_stime) / (double)tck);
    exit(0);
}