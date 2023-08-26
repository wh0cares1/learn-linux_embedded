#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    printf("helloworld");
    write(STDOUT_FILENO,"write here\n",11);
    exit(0);
}