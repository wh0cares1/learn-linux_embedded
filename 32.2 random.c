#include <stdio.h>
#include <stdlib.h>
#include <sys/times.h>
#include <unistd.h>
#include <time.h>

int main(int argc, char *argv[])
{
    int ret;

    srand(time(NULL));//set up the seed

    for (int i=0;i<5;i++)
    {
        ret = rand()%100;//(0-100)
        printf("%d ",ret);
    }

    printf("\n");
    
    return 0;

}