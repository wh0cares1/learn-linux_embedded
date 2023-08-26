#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/stat.h>

#define FILETOCHECK "./test.txt"

int main(void)
{
    int ret;
    ret = chmod("./test.txt",0777);
    //lchmod -> open();
    if(-1==ret)
    {
        perror("open error");
        return 1;
    }
    return 0;
}
