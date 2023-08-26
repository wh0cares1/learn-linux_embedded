#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(int argc, char *argv[])
{
    clock_t t_start;
    clock_t t_end;
    int i, j;
    //start
    t_start = clock();
    if (-1 == t_start)
        exit(-1);
    //testing code setion{
    for (i = 0; i < 20000; i++)
    for (j = 0; j < 20000; j++)
    ;
    //testing code setion}
    //end
    t_end = clock();
    if (-1 == t_end)
        exit(-1);
    //printf
    printf("total CPU time(user and kernel time): %f second\n", (t_end - t_start) / (double)CLOCKS_PER_SEC);
    exit(0);
}