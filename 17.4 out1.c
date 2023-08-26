#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
int main(void)
{
    printf("helloworld\n");

    write(1,"helloworld",10);
    
    return 0;
}